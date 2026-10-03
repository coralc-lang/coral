# HANDOFF — coralc self-host compiler (2026-10-03)

## Repo / build commands
- Workspace: `/home/cerie/Documents/coralc`
- Build compiler: `timeout 200 python3 bootstrap/coralc.py compiler/coral-frontend/coralc.crl -o /tmp/opencode/coralc > /tmp/opencode/build.log 2>&1; echo BUILD=$?`
- Compile a file: `timeout 20 /tmp/opencode/coralc <file>.crl -o /tmp/out`
- Parser test: `python3 bootstrap/coralc.py compiler/coral-frontend/test.crl -o /tmp/opencode/pt && timeout 30 /tmp/opencode/pt`
- Builder test: `python3 bootstrap/coralc.py compiler/coral-build/test_builder.crl -o /tmp/opencode/tb && timeout 30 /tmp/opencode/tb`
- `/tmp/opencode` may be wiped on restart → rebuild.

## Completed this session
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
- **Switch `|` same-body cases** — decide done; implement parser (`PatKind::Or` exists — route `|` into it) + codegen (already renders `||` for Or, so mostly parser wiring).
- **`any TraitName` dyn trait objects** — decide done; implement `TypeKind::Dyn`/`TraitObject` (parser, sema type check, codegen vtable/fat-pointer).
### Sema soundness / diagnostics
- `compatible()` is unsound (any pointer ↔ any pointer; int/float freely interconvert; `from==0` always true).
- Silent errors: assignment failures, redeclaration errors, `Deref` of non-pointer, calling a non-function value.
- `StaticCall` not type-checked in sema; `checkCallee`/`cgResolveCall`/cgMethodRecvKind do linear single-file searches — attach resolved decls to AST nodes (clang-style).
### Codegen
- 33 silent `cg.errors++` sites — route through the diag engine.
- `cgFindDecl` linear scan per call; `cgResolveCall` linear mono-instance scan; 16-element caps; dead `tempArrs`/`tempSeq`; `cgEmitStructFields` unused `indent`; asm template O(n²) string rebuild; dead conditionals.
- Parser: `~=` mapped to `!=`; ternary precedence; double-parsing in speculation (`parseExprOrDecl`, struct/union fields, const untyped detection, param name extraction from type); `pendingGreater` `>>` split; stub `parseFlagDecl`/`parseComptimeDecl` returning Invalid node.
### Lexer
- No `f`/`F` float suffix; no `l`/`L` int suffix; single-bit `numFlags`; fixed 256-entry ident table (never resizes); `decodeUtf8` accepts invalid UTF-8/overlong/surrogates; `\u`/`\U` accept surrogates; `parseInteger` returns partial on overflow; no hex floats; exponent allows `_`.
### Builder (`compiler/coral-build/`)
- `include "…"` never expanded.
- `extends "…"` never merged.
- `target` consulted for nothing — no neutral→platform tree routing (needs `platform_root`).
- Manifest selection from target flags (linux/windows); profiles/workspace/override/tasks/tests/hooks/phases/link/artifact/features/env/log/metrics/lint/format/lsp/ci/remote/deps parsed but unused.
### Language / features
- Lexer/parser/sema for `any TraitName`; comptime type-pattern matching; mono `ceval` (also enables file-scope Ident→const folding in `cgConstAtom`); pub-mod reexport; mangling (`mangle_asm.md`); embed modules; Defer unsupported; `Trait` decls skipped in codegen.
### Lib porting (lib_old → lib per `coral-docs/porting_guide.md`)
- Full port of remaining crates; requires switch `|` and `any TraitName` to be implemented first.
### Repo hygiene
- `PH:` markers cleanup (analyze.crl, compile.crl) and consistent commits.

## Key differentiators / design rules (from docs + user)
- No `impl`/`dyn` in coral; dyn trait spelled `any Trait`.
- `#[[const]]` attr + `type name(params) const {…}` = const method (cannot mutate self/params); Func flags bit 4 = 16.
- `cchar = u8` today; `cchar` should become platform-dependent (`flag(Arch){x86=>i8,else=>u8}`) once `distinct`/flag types exist.
- Errors: `error[C0024]: msg / ┌► file:line:col / │ lineno │ source / ▲ / ╰─ help`.
- Modularization: imports never contain `x86_64/linux`; platform selected by manifest + target flags; neutral paths resolve under platform_root first.
- `Parser p;` bare creates uninitialized fields (incl. `fileId`) — callers must set them.

## Std library (lib/) — constructs that do NOT parse / are not implemented
Verified by running `/tmp/opencode/coralc <file>` on samples:

- **Local array declarations in fn bodies** (`u8 tmp[72];`) → parse error `expected ';'`. Blocks most `io/*.crl`, `hashmap.crl`, etc.
- **Fn-pointer params with names** (`usize(K) hf, bool(K, K) ef`) → parse error `expected ')'`. Blocks `hashmap.crl:20`.
- **Struct/array fields or local arrays with const-size** (`MiSegmentMapEntry* buckets[MI_SEGMENT_MAP_SIZE]`) → parse/`identifier` errors at `mimalloc.crl:47`.
- **`#[[inline]]`, `#[[noinline]]`, `#[[threadlocal]]`, etc.** — now *parsed* (robust attr consumer over idents/keywords/args) but **not honored** (no codegen inline hint, no threadlocal, etc.).
- **`comptime {}` blocks** (`io/ios.crl`) — `parseComptimeDecl` returns an Invalid node → parsed then discarded; no comptime evaluation.
- **`asm {}` blocks** (wallvm, thread, mimalloc, intrinsics) — parse, but sema fails (`undeclared identifier` on template); codegen only partially supports (`StmtKind::Asm` emits raw `__asm__` with literal template pieces, no operand/constraint handling).
- **`defer`** — codegen emits `/* unsupported: defer */` only.
- **`pub trait …` + `extend S : Trait`** — parses as `DeclKind::Trait`/`DeclKind::ExtendTrait`, but codegen skips traits; sema has no real trait-method resolution (`findMethod` doesn't consult the trait), so `trait`-typed dispatch does not work.
- **`distinct` / `flag(Arch){…}`** (e.g. `pub distinct cchar = flag(Arch){x86=>{i8}else=>{u8}}`) — parse errors; not a real feature yet.
- **`any TraitName` trait-object types** — syntax decided (`any Widget`), not implemented.
- **Switch `|` multi-pattern cases** — syntax decided (`pat1 | pat2 => body`), not implemented (Or-patterns already exist inside patterns/codegen renders `||`).
- Lib files importing (`import(..)`) mostly fail to resolve because of the above plus the neutral-path/library manifest gaps (`E1004` for `std::x::y` when the folder/manifest chain `memory`, `data`, `collections`, etc. doesn't chain cleanly).

## Sema — pointer.crl is unused
- `compiler/coral-semantics/pointer.crl` is a 407-line comment-only file (no code). It is not imported/used. Decisions about in-built drop, pointer safety etc. captured there are NOT enforced. Either delete it or implement its analysis.

## Language rules NOT yet enforced by sema
(Language rules exist in docs/`coral-docs/reason.crl`, `imports.md`, but the sema doesn't enforce them)
- `compatible()` is not sound: any pointer ↔ any pointer, int/float interconvert, `from==0/to==0` pass-through, generic params match everything (`dependentType→true`). 
- No return-type check on assignments failures silently; no redeclaration diagnostic; `While`/`If` conditions not required to be `bool`; `ForIn` not validated as iterable; `Switch` patterns not type-checked; `Cast` accepts any→any; `Index` index not checked as int; casts/inc/dec not int-checked; `Not`/`BitNot` operand unchecked; variadic args unchecked; generic args skipped in checks; `checkPath` only validates first two segments; many Expr kinds untyped (`TupleField`, `ArrayLiteral`, `Ternary`, `IfExpr`, `BlockExpr`, `Sizeof`/`Alignof`/`Typeof`, `BuiltinCall`); `StaticCall` not sema'd (always `addError`); single-pass order-dependent (mutual recursion / forward refs broken); extends collected during same pass as method resolution.
- Many diagnostics missing the error *message* payload (`addError()` counts but prints nothing) — several codegen silent-`errors++` too.

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
- Explicit `self` param supported (`self`, `self*`, `const self*`) → detected via param flags bit 0.
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
