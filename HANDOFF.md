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
