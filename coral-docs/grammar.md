# coral grammar reference (for coralc)

This is the concrete syntactic/production-level language model as reflected by the
self-host compiler parsers in `compiler/coral-parser/*.crl` and the AST in
`compiler/coral-ast/*.crl`. `coral-docs/reason.crl`, `coral-docs/imports.md`,
`coral-docs/build_sys.md`, and `coral-docs/coralc_plan.md` add the semantic intent.
Where the implementation differs from the docs, this file wins for parsing, and the
docs win for *intended* semantics.

## 1. Lexical categories

- Whitespace, `// line`, `/* block */` (block comments are not nested).
- Tokens: keywords, identifiers, numbers, string/char literals, operators/delimiters.
- Identifiers: XID_Start / XID_Continue (ASCII reduced form is optimized; many
  Unicode ranges are hardcoded — a correctness smell, not full UAX31).
- Numbers: decimal, `0x` hex, `0b` binary, `0o` octal; `_` separators; unsigned
  suffix `u`/`U` (`32u`, `5ull`); a single float token with optional exponent;
  `127`, `0xFF`, `1e5`, `3.14f` accepted.
- String literals `"…"` with escapes `\n \t \\ \"` and, at lex level, continues
  over newlines (a gap; doc says strings do terminate on newline). Raw strings
  `R"(…)"` / `R"<n>(…)"`.

## 2. Declarations (top level, in `parseFile`)

A file is a sequence of declarations interleaved with imports and
(static-)`Type name(...)` decls. Each decl goes through `parseDecl`, which first
consumes any `#[[ attr ]]` attributes and then dispatched on modifiers:

- modifiers: `pub` (and one of `extern("C")`, `static`).
- keyword decls: `struct`, `variant`, `union`, `enum`, `trait`, `extend`,
  `comptime`, `const`, `typedef`, `distinct`, `flag`?, `import`, `mod`.
- Sonst: `<Type> <name>` → `parseFuncOrVarDecl`, and `Name<…>` → field types /
  extends handled structurally.

`#[[attr]]` lists may name `inline`, `const`, `threadlocal`, `noalias`,
`condassign`, `calleesees`… — today they are parsed but **not** stored/honored
(the parser already accepts idents/keywords/args, so `#[[myAttr(1, "x")]]`
parses).

## 3. Type syntax

`parseType` (parser/type.crl):

- `Const` prefix: `const T` → `Const(T)`.
- `Comptime` prefix: `comptime T` → `ComptimeT`.
- Base ( `parseBaseType` ): scalar keyword, named type, `(T)`, `struct(…)` tuple,
  `(…)` fn-ptr, type refs, `self(s)`, `str`, etc.
- Fn-ptr over a base: `base(Params)` → `makeFunctionPointer(0, base, params)`:
  `void(u64)`, `u32(rawptr)`, `bool(T, T) less`.
- Pointers/arrays: postfix `T*` → `makePointer`, `T[N]` → array, `[]` → slice.
- Named type with generics: `Option<T>`, `HashMap<K, V>`.
- `any <Trait>` (dyn-trait object type) — decided syntax, not implemented.
- Parameter `self` variants: bare `self` or explicily for const: `type name(const self)`, which will throw error if self is modified

## 4. Types (used as annotations)

`Type` = `Named` (primitive or concrete/generic decl name), `Pointer`, `Const`,
`Comptime`, `Slice` (`T[]`), `Array` (`T[N]`), `Rawptr` (`rawptr`), `FnPtr`,
Tuple, `TypeParam`, `Distinct`, plus `Str` used as a `u8*` interned-id in AST.

## 5. Declarations

- **struct**: `struct [gen] Name<T,…> { fields; methods; }` where fields are
  `Type name;`, methods are `Type name(params) const? {…}` (implicit self),
  and constructors are `static Name new(...){…}` / `static map(...)`.
- **variant**: `variant [gen] Name<T> { VariantName { Type field; }, UnitName, … }`.
  Methods live in a `pub extend<T> Name<T> {…}` below.
- **union**, **enum** (`EnumName { A, B = 1 }`), **trait** (`trait Name {fn(inline list of methods);}`), **extend** (`pub extend<T> Type<T> { methods }`), **extend trait** (`extend S : Trait {…}`).
- **const / constant**: `const Type name = expr;` (sema must constant-fold where required).
- **`typedef` / `pub typedef Name = Type;`**.
- **`pub extern[c] Name<params>;`** → extern variable.
- **`distinct`**: `pub distinct <Name> = <Type>;` (or `flag(Arch){…}` — unsupported).
- **import** (4 legal forms, no string literal, no `.crl`):
  - `import name { syms };`   (sibling `name.crl`)
  - `import mod::sub { syms };`  (builder-resolved module)
  - `import(lib) std::x { syms };`  // typed import from lib
  - `import(lib) std;`  // whole lib surface, no braces
- **`mod` reexport**: `pub mod name = import path[:symbols];`
- Generic params declared via `<T, …>`; monomorphised per use-site.

## 6. Function / method syntax

`Type name<[T,…]>[(params)][const] { body } | extern("C") | static ...`
- Params: `type name, …`; unnamed `type, …`; variadic last `...` (Param.flags&16).
- Methods omit `self` (sema injects an implicit `*self` receiver); explicit
  /`const self` are also allowed (`Param.flags & 1`).
- Static fn: `flags & 4` → no receiver; instance methods and `const` methods
  (flags bit 16 — decided, currently: `#[[const]]` or post-parens `const`).

## 7. Statements (parser/stmt.crl)

- `var name [: Ty] = expr;` / `let name = expr;` / `Name name = expr;`
  (`parseExprOrDecl`); `var` + `= expr` in for/while/if is decided with the
  `condassign` attribute (assign-in-condition allowed only with it).
- `if (cond) {…}[else if (…){…}][else {…}]`, `while (cond) {…}`,
  `for (init; cond; inc) {…}`, `for (name in expr) {… }`?, `switch (expr) {…}`,
  `comptime {…}` (stub), `defer expr;` (unsupported in codegen), `asm "…" {outputs}` (partially supported), `return expr;`, `break;`,
  `continue;`, `<block as expr>`, expression-statements, `defer expr;`.
- Switch cases: `pattern => { body },`; patterns via `PatternKind`:
  `Wildcard` (`_`), `Lit(expr)`, `Variant{variantName, fieldNames, fieldNodes?}`
  (`Some { value } => …`), `Enum`, `Path`, `Ident`, `Or` (multiple alternatives),
  `Else` guard (`else`) — a `,` separator between cases today; the
  **decided** form is `pat1 | pat2 => body` (not implemented).

## 8. Expressions (parser/expr.crl)

- Precedence (low→high) via binary levels: `=, +=, -=, *=, /=, %=` are separate
  Assign stmts with LPArench considerations; conditional `a ? b : c` handled in
  parsePrimaryExpr via a bracket speculation (no natural precedence today).
- Binary levels from `prec()`: `1 => lowest`, `&|^`, `==/!=`, `< <= > >=`, `<< >>`?, `+ -`, `* / %`, `**` (absent), unary small.
- Unary: `!`(Not), `~`(BitNot), `-`(Neg), `&`(AddressOf), `*`(Deref), `++`/`--` pre/post.
- Postfix: call `(args)`, `.field`, `p->field`(DerefField), `a[i]`(Index), struct-literal field init in brackets `Name { .field = x }`.
- Interpolation?: none. String ops via libc. `str` is an interned pointer.

## 9. Expression grammar goto (relevant cases)

- `ExprKind`: Lit, Ident, TypeRef, Path, Call, MethodCall, Index, Field,
  DerefField, Block, IfExpr, MatchExpr/SwitchExpr, TupleExpr, ArrayLiteral,
  StructLiteral, Cast, AddressOf, Deref, UnaryOp(Neg/Not/BitNot/PreInc/PreDec/PostInc/PostDec),
  Binary(...) exprs.
- Match arms `Variant{…} => { .. }` inside struct bodies and `switch` calls;
  `VariantLiteral` via `Type::Some { .field = x }`.

## 10. Types-as-expressions

- `TypeRef(Ty)`, `Ident`(name), `Path`, `Field`, `TypeParam`; `Name<args>` parsers a
  generic-variant literal. Tuple-typed composite of one or more exprs between `(…)`.

## 11. Notes mapping to the front-end (for agents)

- Every parser fn is a method on `Parser` in `compiler/coral-parser/*.crl` with
  `pub extend Parser` blocks in `decl.crl`, `expr.crl`, `type.crl`, `stmt.crl`,
  `pattern.crl`, `recovery.crl`, `file.crl`, `parser.crl`, `base.crl`.
- AST enums: `compiler/coral-ast/expr.crl` `ExprKind`, `decl.crl` `DeclKind`,
  `pat.crl` `PatKind`.
- Cross refs: `@compiler/coralc_plan.md` (staged plan), `imports.md`, `build_sys.md`
  (build manifests), `reason.crl` (design intent & event registry),
  `compiler-pipeline.md` (per-module responsibilities).

### Known parse gaps (std lib that does not parse today)
- Local array decls in a fn body (`u8 tmp[72];`) → parse error.
- Fn-pointer params with names (`usize(K) hf`).
- Struct field array decls with const-size exprs.
- `comptime {}` blocks and `asm {}` blocks are parsed then dumped.
- `#[[inline]]` etc.: parsed but not semantic.
- `pub distinct X = flag(…)`, `any TraitName`, switch `|` syntax — decided but
  unimplemented.
