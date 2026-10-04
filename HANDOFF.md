# HANDOFF — coralc self-host compiler (2026-10-03)

## Repo / build commands
- Workspace: `/home/cerie/Documents/coralc`
- Build compiler: `timeout 200 python3 bootstrap/coralc.py compiler/coral-frontend/coralc.crl -o /tmp/opencode/coralc > /tmp/opencode/build.log 2>&1; echo BUILD=$?`
- Compile a file: `timeout 20 /tmp/opencode/coralc <file>.crl -o /tmp/out`
- Parser test: `python3 bootstrap/coralc.py compiler/coral-frontend/test.crl -o /tmp/opencode/pt && timeout 30 /tmp/opencode/pt`
- Builder test: `python3 bootstrap/coralc.py compiler/coral-build/test_builder.crl -o /tmp/opencode/tb && timeout 30 /tmp/opencode/tb`
- `/tmp/opencode` may be wiped on restart → rebuild.

## Completed this session

## Session tick summary 2026-10-03
All verified cumulative; code committed in sequence 27dcaa1..7acd59f.
- Parser: local array decls `u8 tmp[72]` (stmt+const+struct-field); `= {a,b}` array-literal inits via ArrayLiteral; ternary binds like C; `~=` means `x=~y` in both bootstrap + coral-parser; switch `pat | pat => body` accepted (multiple patterns one SwitchCase; PatKind::Or codegen path ALSO repaired); nested `module::{ a, b }` imports parse; `static`/`extern` struct methods are now routed through parseFuncOrVarDecl with correct flags (complex self (fn-ptr) params like `usize(K) hf` compile); comptime T parses.
- Sema: two-pass declareAll+checkBodies (same-file fwd refs); If/While/For/Ternary/IfExpr conditions must be bool; ForIn validates iterable+bind; Deref non-pointer errors; `++`/`--` type propagating; assigning via `self=` unwraps implicit-self pointer; sameType TypeParam<->Named placeholder bridge; AssignCompatible accepts literal narrowing initializers (C-like constant conversion); `compatible()` hardened (no int/float interconvert; Str->pointer removed; Pointer match requires same base payload; const-add allowed Target: T* -> const T*; `T*`->rawptr allowed one-way; integer widening rule = same signedness widen or u->s-wider). selfNamedType feeds selfType params for struct/union/trait/variant method checks. BlockExpr setter propagates trailing expr type; switch-expr-body trailing expr through switch-expr result. StaticCall+S::method via Path now type-checked by findMethod; StaticCall type set to method return. TC-0007 SemaInternal in neutral sites. comptime T -> its fn must carry a comptime {} block.
- Lexer: f/F suffix -> f32 FloatLit (flags), l/L/ll/ul/ull suffixes numeric flags; exponent underscores rejected; overlong/invalid UTF-8 sequences and \u/\U surrogate bounds rejected.
- Codegen: 33 silent `cg.errors++` sites -> `cgError(msg)` -> `error[CG-0002]` (with all `if (cap)` conditions restored); Codegen's heap-allocated `DiagnosticEngine*` via `CompileUnit::engineObj` so CG messages render after analyze; cgFindDecl inline 32-entry name cache; Call/Path Static emit uses `S_new` + correct temp type; no C-`static` on method body definitions (extern protos consistent); struct-array fields in generated C were broken and were sidestepped via `Str*` + arena alloc (python-emitted C never got struct-array working).
- Builder command dispatch: `include "x.crlb"` expanded (8-deep cap, relative to including dir) and `build "X" extends "base.crlb"` merges base fields under child's (child wins).
- 2026-10-03: `@compileError(msg)` aborts sema with its message as TC-0002; `@isFormatLiteral(expr)` types as bool and emits 1/0 at compile time (true only for string literal args). `comptime T` parses (flags bit0) and fns with such params require a comptime{} block in their body.
- 2026-10-03: in-memory HIR groundwork (compiler/coral-hir): `HirModule` struct holds the resolved items + mono instances as interned rows; `build(ctx,file,mono,name)` constructs it; text is rendered (only on the `--emit-hir` flag) by `printHir`.
- 2026-10-03: distinct decls now emit typedef in C; `flag (ARCH) {...}` evaluated at parse time to the arm matching `ctx->targetArch` (default x86_64) else `else` arm; cchar.crl compiles through CG.

1. **Platform-aware resolver** (`analyze.crl`): neutral lib paths try `<platform_root>/` first, then the base tree. Default host platform = `x86_64/linux` (from `L->platformRootSegs`).
2. **Error format** (`compiler/coral-diagnostics/error.crl`): every diagnostic funnels through `diag.emitError(code, SourceLoc loc, msg, help)` → stable codes (`LEX-`, `PAR-`, `TC-`, `CG-`, `DRV-`) + exact gutter/caret/help rendering.
3. **Use-after-free fix** (`analyze.crl` + `freeUnit`): lib file buffers were freed before codegen used interned strings → garbage prototypes. Now `unit.bufs/bufsLen` carried on `CompileUnit`, freed in `freeUnit` (after codegen).
4. **Parser-test crash fix**: uninitialized `fileId` in bare `Parser`/`Lexer` + `renderAt` missing `file >= fileCount` bounds-check → segfault in `runSema` errors. Fixed both.
5. **self* in C**: implicit self is now emitted as a pointer param (`cgEmitParams`), member access emits `self->field` (`cgTyIsPtr` in `cgExpr` Field / `cgLvalue` / `cgPatTest` / field binding), assignment derefs (`*self = ...` in `cgLvalue` Ident).
6. **`const` on functions**: parser handles `#[[const]]` attribute (in `parseDecl` and `parseFuncDecl`) and `const` after the param list (`parseFuncOrVarDecl`) → Func flags bit 4 (16). Flags doc updated.
7. **ParseType refactor** (`compiler/coral-parser/type.crl`): extracted `parseTypeSuffix`; `const T*` now builds `Pointer(Const(T))` (was `Const(Pointer(T))` = const pointer).

## Syntax DECIDED (user) — implement before lib port can proceed
- Switch same-body cases: **`pat1 | pat2 => body`** (replaces `,`-separated cases).
- Trait objects: **`any TraitName`** (no Rust `dyn`, no `impl`).

## Current blocking issues to verify first
- **`"Undefined symbol: cgIntern"`-style name mangling / rebuild drift**: always rebuild after git/lib edits before testing.
- **option.crl currently has 6 parse errors** after I reverted the parseType const fix (see below). The parseType const fix ( `Pointer(Const(T))` ) is backed up at `/tmp/opencode/type.crl.const_fix` — re-applying it should restore correct `const T*` codegen; verify whether the 6 parse errors come from that revert or from the lib's new `#[[const]]`/`constPtr` code.
- **cchar/char mismatch**: libc declares `strtod(const cchar*…)`, `vsnprintf(cchar*…)`; generated C uses `uint8_t` for cchar but the system headers use `char` → `conflicting types` errors. Changing cchar u8↔i8 does not fix it (`signed char` still ≠ `char`). Proper fix needs one of: a coral `char` type that maps to C `char`, making the toolchain sign proto compatible, or the user's planned `cchar = flag(Arch) { x86 => i8, else => u8 }` *distinct* type (does not solve the `uint8_t`/`int8_t` vs `char` mismatch on its own — a dedicated emitted `char` is still required).
- `const T*` in tyStr emitted as `T* const` (const pointer) — addressed by the parseType refactor; re-verify after re-applying.

## Unimplemented todos
### High
- **text.txt three-pass sema**: pass 1 declare-all symbols; pass 2 evaluate with dependency tracking (`x` depends on `y`, resume when `y` evaluated); leftover waiters → cyclic-import error (`let a = b; let b = a;`). Include a cyclic lib-import test.
### Switch / trait features (user-blocking for lib)
- ~~Switch `|` same-body cases~~ DONE 2026-10-03: parser accepts `pat | pat => body` in switch stmt+expr (multiple patterns on one `SwitchCase`; `PatKind::Or` codegen path is also repaired — nested alternatives render correctly).
- **`any TraitName` dyn trait objects** — decide done; implement `TypeKind::Dyn`/`TraitObject` (parser, sema type check, codegen vtable/fat-pointer).
### Error messages must be complete — NEW TODO (2026-10-03)
- Every diagnostic in the compiler — sema, parser, lexer, mono, codegen, driver — must emit the full error record: stable code/level + location (file:line:col gutter/caret) + the human-readable message + the actionable fix/help text. Sites still lacking full messages:
  - Parser: `addError()` bare counters without text at ~40+ sites (`recovery.crl`, `nodeListAppend` failures, etc.) — no `code`/`msg`/`loc` wiring yet. `parseFlagDecl`/`parseComptimeDecl` silently return Invalid nodes; their discarded bodies need an explicit 'not implemented' diagnostic.
  - Sema: tupleField/ArrayLiteral fallback messages missing type (`expr.crl` else/fallbacks); assignment failures from `assignExpr`/`DerefType` incompatible operands→ now properly via Non-Pointer-Deref error added 2026-10-03; redeclaration of fields/imports not diagnosed; `While`/`If` conditions ✓; `ForIn` iterable ✓; Deref non-pointer ✓; index-int-operand ✓.
  - Codegen: ~33 `cgError` sites now have distinct messages ✓ (2026-10-03); labels without help text still common (e.g. forward decls + location-less when node.index == 0).
  - Diagnostics' `why`/`fix`/`learn` fields on `Diagnostic`/`renderDiagnostic` are still unpopulated. Engine path passes `help=null` everywhere; only some sites include help (`#[[condassign]]` help exists — PAR-0010).


## Key differentiators / design rules (from docs + user)
- No `impl`/`dyn` in coral; dyn trait spelled `any Trait`.
- `#[[const]]` attr + `type name(params) const {…}` = const method (cannot mutate self/params); Func flags bit 4 = 16.
- `cchar = u8` today; `cchar` should become platform-dependent (`flag(Arch){x86=>i8,else=>u8}`) once `distinct`/flag types exist.
- Errors: `error[C0024]: msg / ┌► file:line:col / │ lineno │ source / ▲ / ╰─ help`.
- Modularization: imports never contain `x86_64/linux`; platform selected by manifest + target flags; neutral paths resolve under platform_root first.
- `Parser p;` bare creates uninitialized fields (incl. `fileId`) — callers must set them.

## Std library (lib/) — constructs that do NOT parse / are not implemented
Verified by running `/tmp/opencode/coralc <file>` on samples:

- ~~Local array declarations in fn bodies~~ DONE 2026-10-03: `u8 tmp[72];` parses in stmt+const+struct-field positions; `= { a, b }` array-literal initializers parse as `ExprKind::ArrayLiteral`. Verified: `/tmp/opencode/arr` compiles+runs; sha256.crl now parse-clean (next failure there is sema Deref/Index of slices, not parse). Array sizes must be integer literals; named const sizes (e.g. `MI_SEGMENT_MAP_SIZE`) still rejected.
- ~~Fn-pointer params with names~~ PARSE-DONE 2026-10-03: struct-body `static`/`extern` methods were mis-routed through `parseFuncDecl` (dropped flags, never consumed `static`); now routed through `parseFuncOrVarDecl` with correct flags. RESOLVED 2026-10-03 via the sameType TypeParam~Named bridge + stricter compatible(): fp4.crl (HashMap static new with fn-ptr params) now compiles and runs.
- **Struct/array fields or local arrays with const-size** (`MiSegmentMapEntry* buckets[MI_SEGMENT_MAP_SIZE]`) → parse/`identifier` errors at `mimalloc.crl:47`.
- **`#[[inline]]`, `#[[noinline]]`, `#[[threadlocal]]`, etc.** — now *parsed* (robust attr consumer over idents/keywords/args) but **not honored** (no codegen inline hint, no threadlocal, etc.).
- **`comptime {}` blocks** (`io/ios.crl`) — `parseComptimeDecl` returns an Invalid node → parsed then discarded; no comptime evaluation.
- **`asm {}` blocks** (wallvm, thread, mimalloc, intrinsics) — parse, but sema fails (`undeclared identifier` on template); codegen only partially supports (`StmtKind::Asm` emits raw `__asm__` with literal template pieces, no operand/constraint handling).
- **`defer`** — codegen emits `/* unsupported: defer */` only.
- **`pub trait …` + `extend S : Trait`** — parses as `DeclKind::Trait`/`DeclKind::ExtendTrait`, but codegen skips traits; sema has no real trait-method resolution (`findMethod` doesn't consult the trait), so `trait`-typed dispatch does not work.
- **`distinct` / `flag(Arch){…}`** (e.g. `pub distinct cchar = flag(Arch){x86=>{i8}else=>{u8}}`) — parse errors; not a real feature yet.
- **`any TraitName` trait-object types** — syntax decided (`any Widget`), not implemented.
- ~~Switch `|` multi-pattern cases~~ DONE 2026-10-03 (see line 34 note).
- Lib files importing (`import(..)`) mostly fail to resolve because of the above plus the neutral-path/library manifest gaps (`E1004` for `std::x::y` when the folder/manifest chain `memory`, `data`, `collections`, etc. doesn't chain cleanly).

## Sema — pointer.crl is unused
- `compiler/coral-semantics/pointer.crl` is a 407-line comment-only file (no code). It is not imported/used. Decisions about in-built drop, pointer safety etc. captured there are NOT enforced. Either delete it or implement its analysis.

## Type inference — largely unimplemented
- `var x = expr;` can only infer when the initializer already has a concrete/known type; there is **no constraint solving / type-unification** (no "unknown" type vars solved across usages). `var x = expr;` with an un-inferable initializer → "cannot infer type: add an explicit type annotation".
- Generic calls are **not** type-inferred from arguments: `obj.map(fn)` does not bind `T` from the receiver or from `fn`; there is no substitution/`satisfy` check for generic params on generic fn/method calls (`genericArgParam` skips checks). Mono collects specializations from concrete receiver types but has no argument-driven inference.
- `Alloc/constructors`/`Option::Some{...}` do not infer the generic from designated fields; enum/variant case expressions type by position only.
- `distinct`/`comptime`/`FnPtr`/`Tuple` types are not propagated by inference.
Give this a roadmap slot before relying on inference for lib code.

## Language rules NOT yet enforced by sema
(Language rules exist in docs/`coral-docs/reason.crl`, `imports.md`, but the sema doesn't enforce them)
- `compatible()` is not sound: any pointer ↔ any pointer, int/float interconvert, `from==0/to==0` pass-through, generic params match everything (`dependentType→true`). 
- Remaining unenforced sema rules (2026-10-03 view; ticked DONE items removed): no return-type check on assignments failures silently; no redeclaration diagnostic; `Switch` patterns not type-checked; `Cast` accepts any→any; casts/inc/dec not int-checked; `Not`/`BitNot` operand unchecked; variadic args unchecked; generic args skipped in checks; `checkPath` only validates first two segments; many Expr kinds untyped (`TupleField`, `ArrayLiteral`, `Sizeof`/`Alignof`/`Typeof`, `BuiltinCall`); single-pass order-dependent for import resolution (mutual recursion across files / cyclic imports undetected — declared-all now covers same-file fwd-refs); extends collected as part of method-resolution passes.
- Many diagnostics missing the error *message* payload (`addError()` counts but prints nothing) — several codegen silent-`errors++` too.

## Grammar reference
- See `coral-docs/grammar.md` for the full concrete grammar (tokens, decls, types, exprs, precedence, self/const semantics, attributes).

## Constraint for new work: production-level, C++-similar grammar
Coral's grammar intentionally mirrors C/C++ and is built/followed against Clang for those aspects specifically to avoid naivety. New parsing/precedence/lexical/diagnostic decisions should match Clang's equivalents where Coral adopts the same surface syntax, so the grammar stays principled and the front-end does not bake in one-off heuristics. References: `coral-docs/reason.crl`, `coral-docs/imports.md`, `coral-docs/compiler-pipeline.md`, `coral-docs/build_sys.md`.

## Known grammar / semantic rules of the language (accumulated; user to extend)

### Files & modules
- Source file is a list of top-level declarations; no preprocessor (beyond `#[[...]]` attribute syntax) and no `#include`.
- Import forms (only these; never a string path, never `.crl` in the path):
  - `import name { sym, … };` — from a sibling file `./name.crl`.
  - `import mod::path { sym, … };` — builder-resolved module.
  - `import(lib) std::x { sym, … };` — import from the std lib surface.
  - `import(lib) std;` — whole surface, no item list.
- Re-exports live in `lib.crl`: `pub mod option = import data::option;`.
- Build manifests (`.crlb`): `build "std" { root, modules, platform_root, select, … }`, `extends`/`include`, profiles/target/link/artifact/features (parsed, mostly not acted upon yet).
- Neutral import paths must NOT contain platform segments (`x86_64`, `linux`, …); platform path is selected by the build manifest for the target.

### Declarations & visibility
- `pub`, `static`, `extern("C")` modifiers; public-visibility defaults private.
- Function declaration form: `Type name<[T,…]>(param,…)[const] { body }` — return type first, no `fn` keyword.
- `ret name(…)` fn with no fn keyword; `static` fn = no receiver; methods defined inside a struct/variant/union/trait body or in `extend` blocks.
- Struct constructors are `static Struct<T> new(){…}`; field init via designated `.field = expr`.
- Decls: `struct`, `variant`, `union`, `enum`, `trait`, `distinct`, `extend`, `ExtendTrait`, `typedef`, `Constant` (`const`/`const u8 Table[N]`), `import`, `mod` (reexport), `flag`?, `comptime`.
- fn flags bits: 1=isPub, 2=isExtern, 4=isStatic, 8=hasBody, 16=isConst. Param flags: 1=isSelf, 16=variadic (`...`), 8=unnamed.

### Types
- Scalars: `u8 u16 u32 u64`, `i8 i16 i32 i64`, `usize isize`, `f32 f64`, `bool`, `rawptr`, `str`, `void`, `cchar` (= u8 now; should be platform `i8`/`u8` eventually).
- Pointers: `T*`, `const T*`, `const self*` (receiver). `str` is an interned index into a table (`u32`), distinct from slices.
- Arrays: `T[N]` (in params/fields); slices `T[]` (Slice); tuples.
- Fn-pointer type: `T(params)` (e.g. `void(rawptr, usize) free`); used for `Option<T>::map(T(T) fn)`.
- Generics: declared `<T, N>`, concrete via `Name<args>` (no turbofish).
- Dependent/`const`/`comptime`/`distinct` wrapper kinds exist in `TypeKind`.
- Decided trait-object syntax: `any TraitName` (not implemented).
- Numeric literal suffixes: formats `decimal/0x/0b/0o`, `_` separators, `u/U` suffix (e.g. `32u`, `5ull`), floats `1.5`, `true/false`, `null`.

### Expressions / statements
- Postfix: `()` call, `.field`, `p->field` (deref-field), `a[i]`, `a?b:c`ternary, `++ --` post.
- Prefix/unary: `!x` (Not), `~x` (BitNot), `-x` (Neg), `&x`, `*x`, `+x`?, `++ --` pre, `not` is alias for `!`? (we treat `!`=Not, `~`=BitNot; `-9223372036854775808` handled via Neg+IntLit range narrowing).
- Binary precedence levels incl. `| && ||`. `|` inside switch patterns / or-patterns; not yet the token separator for same-body cases (decided, unimplemented).
- `~=` is currently parsed as `!=` (known bug — should be a compound `AssignNeg`).
- Casts are C-style `(T)x`; no `as`. Address-of `&x`, deref `*x`.
- `switch (x) { pat1 | pat2 => {…}, else => … };` parenthesized; prongs end with `,` inside `{}`, guards via `=>`; there is no `default` keyword (use `else`).
- Value blocks can end with an expression → switch-as-expression.
- `defer` statement not supported in codegen; `comptime { }` not evaluated; `asm` not type-checked; deferrals reported as unsupported.

### Methods & self semantics
- Methods may omit `self` → sema declares an implicit `self`; in C the receiver is a **pointer** (`Option_doubledouble* self`), member access emits `self->field`, assignment writes through (`*self = …`).
- `#[[const]]` attribute OR `const` after `(params)` → const method (cannot mutate self/params) — flag bit 16.
- Method resolution: linear first-match over methods + `extend` blocks; no trait impl dispatch yet.

### Diagnostics
- Stable codes: `LEX-0001..`, `PAR-…`, `TC-…`, `CG-…`, `DRV-…`; then `error[CODE]: msg` / `┌─► file:line:col` / gutter source / `▲` under the error column / `╰─` optional help.

### Known bugs (partial)
- `~=` mapped to `!=`. neg and not are different.
- Ternary `?:` has no expression precedence (parsed as full-expression); `parsePrimary` cast detection is speculation-heavy and re-parses types.
- Single-pass sema: mutual recursion / forward references / extends collected in same pass; `import(lib)` plain-symbol validation order-dependent.
- `compatible()` unsound; silent assignment/redecl errors; no condition-bool checks; variadic args unchecked; `StaticCall` untyped.
- Codegen silent `cg.errors++` at ~33 sites; `cgResolveCall`/`cgMethodRecvKind` do per-call linear scans; 16-arg cap; dead `tempArrs`/`tempSeq`.
- Lexer: fixed 256-slot ident table; no `f`/`F`/`l`/`L` suffixes; `u` suffix exists; `decodeUtf8`/`\u` accept invalid; `parseInteger` returns partial on overflow; no hex float.

## Semantic rules (C/C++-style + coral-specific, enforced or to-be-enforced)

### Declarations & scopes
- No duplicate declaration of the same name in one scope.
- `use-before-declaration` / forward refs: file-scope fn names are resolvable out of order only after a declare-all pass; `var` is not usable before its declaration.
- Visibility: `pub` carries; imports resolve the same names only if public; alias/symbol ambiguity is an error.
- Const symbols cannot be reassigned; `pub const` is usable across modules.

### Initialization / inference
- A local `var x = expr;` may omit an annotation only when the initializer has a concrete type; otherwise error. `var x: T = expr;` checks `expr` against `T`.
- `const X = …;` requires the initializer to be a constant expression (literal fold) when untyped.
- Constants: enum values and literal-sized fields may not use non-constexpr exprs.

### Expressions & lvalues
- An assignment target must be an lvalue (`ident`, `field`, `deref *p`, `slice index` usable as lvalue); assigning to a literal/`const`/`comptime` is not allowed.
- `++`/`--` operands must be an lvalue of an integer/arithmetic-ish type.
- Member access `a.b`: `a` must have non-null `b` member; `a->b` requires `a` to be a pointer.
- Indexing `a[i]`: first operand integer/slice/pointer/array, second integer; the index operand's type must be checked as integer (sema gap — today unchecked). **Out-of-bounds indexing is PROHIBITED**: for fixed-size arrays (`T[N]`) with a statically known index (literal/comptime), sema must reject `i < 0`-style unsigned wraparound and `i >= N` at compile time; for dynamic indices, a conforming implementation guarantees a defined trap/panic rather than silent UB (runtime bounds check retained; not yet implemented).
- Call on a value of fn-pointer/FnPtr type only; calling an `i32`/`rawptr` is a type error.
- Return statements must match the function's declared return type; missing return on a non-void path is invalid (Wasm/void ok).
- The block must definitely produce the return value on all paths (unlike C).

### Conversions (C/C++-strict)
- No implicit integer↔float, float→int, or different-width integer assignment; explicit conversion via `(T)x`.
- No pointer↔int conversions; `rawptr` may receive object pointers (and be cast); typed `T*` requires matching element type.
- No `T**` from `T*` without explicit cast. Struct/`enum`/`fn` types are not assignable to unrelated struct/enum/fn types.
- Identical shape is not enough for `distinct` types: explicit conversion required; distinct new/coercion rules must be checked.
- Generic named types match exactly (after instantiation) with no covariance; `str` ≠ slice.

### Operators
- Arithmetic `+ - * / %` require integer-or-float operands of the same type after int promotion; result type preserved.
- `%`/`~`/shift only on `usize`/`i*`/`u*`.
- Logical `&& || !` require `bool` operands and produce `bool`.
- Bitwise `& | ^ ~` require integer/`bool`(? — decide) operands.
- Comparisons `== != < <= > >=`: operands must share an integer/float/bool/pointer/str (== only for pointer) relation and produce `bool`; no enum↔int implicit compare.
- Shifts require right operand to be within-width unsigned integer (decide rule); oversized shift is an error/undefined-behavior choice — decide and note.

### Types / aggregates
- A struct/variant/union value must have every non-defaulted member initialized exactly once.
- Struct literal: field names valid, types compatible, no duplicate member, all required members present.
- Variant: match subject must be the right type; every case arm produces the type; fields bound have the declared type; literals/flags consistent.
- Enum: used value must be a declared member / valid discriminant; exhaustive match over member set.
- Array literal: element count == declared size; homogeneous conversion only.
- Pointer arithmetic: byte math only via provided helpers; addition/subtraction on `T*` yields `T*` and index must be integer-compatible.
- `comptime` wrapper forces constant-evaluable inner type.

### Control flow
- `if`/`while`/`for`/`match` conditions must be `bool` (C requires nonzero-truthy; decide — coral currently requires tests).
- `for (T x in it)`: `it` must be iterable for `T`.
- `break`/`continue` only inside loops; `return` only inside a function; no label jumps into blocks.
- Switch: patterns exhaustive (or `else`), duplicate patterns rejected, scrutinee type must match arms, different payload widths must be handled; implicit subgroup via `|` treated as one case shared-body.
- No case fall-through like C (each arm scoped with empty or explicit); decide define.

### Functions / methods
- A function call must supply the exact number of arguments or be a valid variadic call; variadic args are untyped extras.
- Method call receiver type has a visible member by that name (`findMethod` over impl blocks); arity match.
- `const` methods may not mutate `self`/params; `comptime` fn calls in const context must be comptime-evaluable.
- Static methods (flags bit 2) take no `self`; calling a static method requires `Type::name()` path, not instance.
- A method cannot be defined on a built-in/alien type from another module unless `pub` re-exported rules allow.
- Extern fns share C linkage: params/return must be C-ABI-expressible; calls validate against the system prototype page (cchar vs char issue lives here).

### Imports / modules
- Importing an unknown symbol/module/slot is an error (`E1004`/`E1005`).
- No direct circular import reliance: declarations collected first, evaluation waits on dependencies, leftover waits → `E1006`.
- `pub` items in `lib.crl`/lib surface resolve neutral paths under the platform root first then base tree; both must produce the same *semantic type shape* (today only the file must be found).

### Lexer / literal rules
- Numeric: grammar-allowed literals only; overflow must be a diagnostic (`parseInteger out of range`); float literal invalid tokens diagnosed; `_` separators; valid integer suffixes (`u`,`ul`,`ull`) map to distinct types; invalid suffix is an error.
- String/char literal must terminate before EOF/newline (unless triple quote design say otherwise); unknown escape is an error.
- Identifiers follow XID-Start/XID-Continue; C++-similar keywords/literals reserved; emitted C is keyworded-escaped (cgIdent).

### Conditional assignment
- An assignment expression (`x = v`, `x += v`, …) appearing directly as the controlling condition of `if` / `while` / `for` is a **compile-time error** (`ParseCondAssign`), because it is usually a mistaken `==`.
- It is permitted only when explicitly allowed via the attribute `#[[condassign]]` on that `if`/`while`/`for` statement (parser carries `condAssignAttr` for the immediately-enclosed condition).

## HIR text format (proposed; in-memory, single-parseable, backend-neutral)
Goal: a single, self-contained textual form produced *after* sema + import resolution + comptime folding + monomorphization + drop-trait/scope resolution — everything the backend needs already resolved/named. Only lives in memory; its text form is for debugging/tests and is re-parseable by a single pass.

### 1) Module header & items
```crl
module @std::x86_64::linux    // fully qualified path

  imports   // resolved, no longer imported at compile time
    @core::limits as _limits (INT64_MAX)
    @core::cchar  as _cchar  (cchar)

  // items, each fully typed + named
  pub variant Option<...>;  // each generic instantiated below with a concrete name
  // monomorph instances get fresh concrete names
  struct Option_doubledouble { tag: i64, u: union { _0: {}, u1: { value: f64 } } }
  extend Option_doubledouble {
    pub isSome  :: (self: Option_doubledouble*) -> bool
    pub unwrap  :: (self: Option_doubledouble*) -> f64
  }
  extern printf :: (fmt: cchar*, ...) -> i32
  const INT64_MAX :: i64 = 0x7fffffffffffffff
  fn checkedPow :: (base: f64, exp: f64) -> Option<f64>;
  // ^ signatures declare everything; body lowered below
```

### 2) Type spellings (no inference, all resolved)
- Scalars: `u8 u16 u32 u64 i8 i16 i32 i64 usize isize f32 f64 bool cchar str rawptr void`
- `T*`, `const T*`, `T[N]`, `T[]` (slice), `struct#Name`, `union#Name`, `variant#Name`, `enum#Name`, `distinct#Name(T)`, `fn (T,…)->U` (fnptr), `any Trait` (object), `Option_doubledouble`-style mono names.
- Generic params of a *definition* are declared inline: `fn @foo< T: TypeBound? >(arg: T) -> T`.
- Instantiation: `Option<f64>` or its canonical name `Option_f64` (either acceptable, same meaning).

### 3) Item body — A-normal-ish typed local form
```crl
  // fn @checkedPow :: (base: f64, exponent: f64) -> Option<f64> {
  // locals:
  //   tmp0 : Option<f64>;
  //   tmp1 : f64;
  // entry:
  //   tmp0 = copy _limits$checkedPow(base, exponent);  // cross-module fully-qualified call
  //   br label %then_%return;
  // then:
  //   tmp1 = load %x;  // every use is typed
  //   store %tmp1 into %r;
  //   ret { kind: Some, payload: tmp1 } into $slot;
  // } // rejected, it should be more high level than this, or at least, temp not 
  // needed, the temp val c was a shitty decision. and this was mirroring it
```
- Every local/temp has a name and a type. Every expression yields a typed slot; no unparsed sugar.
- Control flow is explicit blocks ending in `ret`/`br`/`switch`/`unreachable`.
- Drop markers: `drop %name` explicit points (resolved from drop-trait impls during sema).
- Comptime args/fold results are literal already (`const`/`comptime` resolved).

### 4) Monomorphization table
```crl
  mono:
    #0 = Option<f64>      :: struct { ... }           // concrete struct
    #1 = Option<f64>::isSome  :: (self: Option<f64>*) -> bool  // instance method
    #2 = Option<f64>::unwrap :: (self: Option<f64>*) -> f64
       monos #1 requires #0; #2 requires #0
```
- Each generic decl's specialization listed with argument types; bodies reference mono ids.

### 5) Parsing the HIR back
- The text is a single grammar from `module`/`imports`/`struct`/`extend`/`fn`/`mono`/`locals`/`entry` down to `load/store/call/ret/br/switch/drop`; one pass, every symbol and type already resolved — no imports, comptime, or type inference needed when reading it.

(We will finalize the exact punctuation/keywords when we stabilize the IR; above is the minimal shape that satisfies "everything resolved + single-parseable + backend-neutral".)

## Built-in traits the language should have (not yet implemented)
- `drop` — `void drop()` glue; called when the value goes out of scope (like Rust `Drop`). Mentioned in `threadpool.crl` comments; NOT enforced/resolved anywhere.
- `toStr` — string representation; sema doesn't resolve which impl applies to a concrete type.
- `iterable` — `for (T x : it)` means `it` must satisfy `iterable` (supplied by `Iterator`/`Stream` extensions); currently `ForIn` has NO sema check and codegen just assumes slice/array.
- `eq` / `ne` / `ord` — equality & ordering used by switch/enum compare and `==`.
- `clone` / `default` / `debug` (fmt/debug printing).
- `copy` / `send` / `sync` marker analogues.
These must be declared in the definition of the `trait` keyword's language and have sema impl-resolution + a const/drop elaboration pass before they can be used; today their constructs don't parse or don't resolve (see gaps section).

## Error rendering gaps
- Most diagnostics emit only the bare line `error[PAR-0001]: <msg>` with no location, or a one-line `expected ';'` with no source line/caret/help.
- `why`, `fix`, and `learn` fields exist on `Diagnostic`/`renderDiagnostic` but are not populated/rendered on the common path; `call sites report stable CODE + location + help` is still aspirational on many sites.
- Several sema/parser reports go through `addError()`/`semaErrorNode(…, code, msg)` but the `why`/`fix` are always `null`; no label spans, no secondary notes.
- Consequently many real errors produce empty/positionless output (`expected ';'` with no line, `expected identifier` at offset) making diagnosis hard — treat improving the renderer as part of closing the diagnostics todo.

## Where compilation checks stand
- Running `/tmp/opencode/coralc <file>` on lib/test files is how we flag what coralc cannot do; each failure is being written into this file (unsupported syntax, unenforced rules, missing sema/codegen). Yes — this is a deliberate gap sweep, not compilation steps toward shipping.
- Blocking right now: option.crl (test) reports 6 parse errors with no established position; investigating whether the offending construct is in a lib-only path with mismatched file id, or a lib file using syntax the parser rejects (e.g. `@assertOut(...)` in `result.crl`, local arrays, fn-ptr-params).

### comptime semantics (to encode in sema; parser doesn't yet emit `comptime T` gen-params)
- `comptime { … }` is a general compile-time block (switches, if/else, for, arbitrary logic) that selects/emits code; not just switches/ifs.
- A generic param may be `comptime T` (`print<comptime T>(T fmt, …)`): the caller does NOT supply T — it is auto-deduced by the function's `comptime { … }` block.
- Semantic rule: every function with a `comptime T` generic param MUST contain a `comptime { … }` block. Add to sema (and produce a proper compile error when absent).
- Not yet implemented: parser acceptance of `comptime T` in the generic-param list, comptime evaluation, `@compileError` / `@isFormatLiteral` handling.

### Nested path-listed import (decided, IMPLEMENTED 2026-10-03: `module::{ a, b }` parses; `nested_import.crl` parse-clean, sema TC for unresolved lib symbols still applies)
```crl
import(lib) std::text {
    string::{ String },
    strutil::{ splitVec, trim, indexOfChar }
};
```
- Brings `std::text::string::String` and `std::text::strutil::{…}` into scope.
- The parser supports brace nesting *without* `::` (`string { String }`) by
  recursing with a `::`-joined prefix, but the `module::{ … }` form is a parse
  error today. Needs implementation before the lib port can use it.
- Demo: `compiler/coral-test/nested_import.crl` (expected to fail to parse until implemented).

- struct enum and variant definition in functions
- there should also be a prelude flg, for prelude imports, like core::str, to provide str methods. 
- this should be on by default but can be turnned off in the build file and via flags.
- also, make sure agents review this whole system extensively for naivety, hacks, ans redndant operation, improper logic, bad actions, and expencsive behaviour(perf)
- `self.semaErrorNode(ErrorCode::SemaInternal, self.ctx.noneNode(), "allocTypeSlot failed (type table full)");` type table being ull is a result of bad management and naivety. dooes it ever happpen in cpp or c?
- the addition of an @default() function, to set the default vals for a type.
- implementation od #[[generator(debug, cmp, ..)]] 