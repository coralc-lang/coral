# HANDOFF — coralc self-host compiler (2026-10-03)

## Repo / build commands
- Workspace: `/home/cerie/Documents/coralc`
- Build compiler: `timeout 200 python3 bootstrap/coralc.py compiler/coral-frontend/coralc.crl -o /tmp/opencode/coralc > /tmp/opencode/build.log 2>&1; echo BUILD=$?`
- Compile a file: `timeout 20 /tmp/opencode/coralc <file>.crl -o /tmp/out`
- Parser test: `python3 bootstrap/coralc.py compiler/coral-frontend/test.crl -o /tmp/opencode/pt && timeout 30 /tmp/opencode/pt`
- Builder test: `python3 bootstrap/coralc.py compiler/coral-build/test_builder.crl -o /tmp/opencode/tb && timeout 30 /tmp/opencode/tb`
- `/tmp/opencode` may be wiped on restart → rebuild.

## Completed this session

## Session tick summary 2026-10-09 (stage-2 mangling Phase A+B+D landed; suite PASS=34/34)
Commits: a0235b9 (Phase A), bdc629f (Phase B+D + lib fixes). Verify = `timeout 300 python3 bootstrap/coralc.py compiler/coral-frontend/coralc.crl -o /tmp/opencode/coralc` BUILD=0, nested_import compiles+runs, `/tmp/opencode/run_tests.sh` PASS=34 FAIL=0, gp4 generic mimalloc probe runs clean under ASan (`gcc -std=gnu11 -fsanitize=address -g -O0`; the frontend hardcodes `gcc -std=gnu11 ` at compile.crl:210 — no CC env; it keeps the generated `.c` on success too, so manual ASan rebuilds just re-gcc the file).
- **Phase A (mangle_asm.md)**: scope-chain mangling `crl__<scope>__<seg…>[__<alias>]__<name>` for decls/types/enums committed a0235b9.
- **Phase B (mono)**: collect/instantiate/sema-expr generic-preamble + diagnostics probes removed after green (bdc629f).
- **Phase D (codegen — "remove the temp val and goto")**: statements emit native C — if/while/for/forin/break/continue; expressions return inline ebuf text (`stTail`); TupleExpr double-emit fixed. **Documented exceptions still on temp machinery**: IfExpr (temp+goto), SwitchExpr (result temp + if/else-if chain lowering via cgEmitSwitchChain — no fallthrough, default last, plain C break), AddressOf/MethodCall-receiver materialization via new `cgAddrOfValue` (extern-decl-before-cgExpr pattern for mutual recursion). `cgEmitLabel`/`cgEmitGoto`/`cgNewTemp`/temp decl loop kept for those. assertOut: 1-arg → `assert(cond);`, 2-arg Str → `assert(cond && _coral_strtruth(msg));`, 2-arg non-str → `assert(cond && msg);`; struct eq/ne → memcmp+sizeof; str eq/ne → preamble `_coral_streq`.
- **Method dispatch (all 8 nested_import gcc error classes fixed → NI_RC=0)**: `cgOwnerSpelling` normalizes owner spelling (`str` → `_coral_str` — extend's cgDeclOwner is the C name, call sites use the coral name); call-arm branch (a) tries `cgFindMethodDeclOwner(rootT)` + composes def-side suffix (`owner_method`) before cgResolveCall; StaticCall arm composes the same; MethodCall synthetic `&` receiver now goes through `cgAddrOfValue` (fixes 7 lvalue `&`-operand errors); all stmt handlers evaluate cgExpr before writing prefixes, so temp statements from cgExpr land safely (Asm operands are the one racy exception, ignored).
- **All debug probes stripped** from codegen/expr/instantiate/collect (script: `/tmp/opencode/strip_probes.py`); zero `write(2` / `extern("C") i64 write` left in compiler/. Clean rebuild from stripped tree is green.
- **Lib fixes (source bugs, not compiler)**: `string.crl:91/:145` ptr subtraction cast `(const u8*)self.ptr` (invalid C `const uint8_t* - char*`); `mimalloc.crl` `_miPageAlloc` no longer aliases `MiPage` over the `MiSegment` header — `seg->base == seg` by design, so `page->sizeClass = sc` used to clobber `seg->base` before `page->base = seg->base + metaSize` read it → wild block pointers (runtime SIGSEGV in `_miFreeBlockEncode`, caught by gdb + ASan on `/tmp/opencode/gp4.crl`); page now lives at `seg->base + sizeof(MiSegment)`, metaSize aligns past segment+page headers with `~255u` (was `~256u` — off-by-one that undersized the header region).
- **Next**: Phase C (TypeEntry fileId + type/enum mangling), windows std sweep, compiler-ASan suite run, cchar/const-shape sweep items below.

## Session tick summary 2026-10-09 (wallvm SIMD: backend vector wave + simd_vec widening rework)
Backend wave + windows.crl landed in 616cda2 (user committed); the simd_vec rework + doc updates below are UNCOMMITTED at handoff. Verify = check_crl.py PASS + gas-form assembly via system gcc + greps; no compiler runs (PORTING_RULES §0.5).
- **x86_64_base.crl vector emitters** (4914 lines): width-aware `emitLoadWidth`/`emitStoreWidth` (vec/float → movdqu/movd/movq, fixes wrapped-paren slot bug + mem→mem via xmm0/xmm1, spilled int via r10, spilled float via xmm15); `rspSlotText`/`sibText`/`addrFor(r11 reload)`; dispatch arms VecAdd/Sub/Mul/Div/Min/Max/Broadcast + NEW ExtractElement/InsertElement/ShuffleVector; helpers sinkF, emitVecTwoOp (SSE copy+fold, VEX 3-op only when w>128 && avxReady), emitVecBinOp/FloatBinOp (pd/ps by elem width), emitBcastDword, emitBroadcast (vpbroadcastd/q + SSE shufps/shufpd/punpck paths), emitVecLaneOp (signed idiv lane loop with rax/rdx push/pop), emitVecMinMax (unsigned contract), emitShuffle, emitExtractElem/emitInsertElem (SIB dynamic idx, window roundtrips); `_ymmbuf[4][16]` scratch. Operand convention: bare dynamic regs, `%` only in hand-written literals.
- **windows.crl**: sse/sse2/sse3/ssse3/sse41/sse42 flags added (was missing → SSE emitters dead on Windows target).
- **simd_vec.crl rework (821 lines, uncommitted)** — F1-F5 from landscape §6.2 fixed: real widening vectorizer. Loops via `irLoopDetectNatural`; IV = header phi (0 outside, Add(phi,1) from latch, phi actually used by the step); exit compare = single-use `phi < const` as header/latch terminator (latch must re-enter on true); side-effect scan over ALL loop blocks incl. atomics; candidates anywhere in loop: single-consumer phi-indexed Gep chain ending in phi-indexed store, other operand const/invariant or a second phi-indexed same-type load; store-once claims; uniform elemBits per loop; read-only `verifyWidening` gate audits every in-loop IV user + every claimed-GEP user (kills leftovers/side-ifs/early exits); then vector Load at GEP result (NOT the old pointer-splat broadcast), vec ops anchored at the op (multi-block dominance), store at scalar store's position, neuter→Noret (transient; peephole fixpoint erases before final validate), widen via interned constInt operand REPLACE (never mutates shared consts). Reductions dropped (F4 type mixing — horizontal reduction = follow-up); signed int min/max stay scalar. Known scope: constant bounds only, no remainder loop, no cost model, no runtime alias check, wasm has no vector Load lowering.
- **optimization-landscape.md §6/E3/R3 updated** to the reworked state (F1-F6,F8 resolved; F7 avx.crl wire-or-delete still open).

## Session tick summary 2026-10-08 (char=utf32, headers→link libc, local static, const prescan)
All verified below; committed with this file.
- **`char` is UTF-32 (user directive — char literal ≠ `char` type)**: sema `intWidth(Char)` = 32 (was 8); codegen tyStr `Char` → `uint32_t` (never C `char`; the slice literal must be NUL-free — len 8 not 9); CharLit fallback cast `(char)N` → `(uint32_t)N`; `str` stays a byte view → `strPtrType()` = `Pointer(Const(U8))` (was `Pointer(Const(Char))`). Probes green: `sizeof(char)==4`, codepoint roundtrip `(char)128512`.
- **cchar → C's plain `char`**: tyStr special-cases `Named{cchar}` → `char` (platform plain-char signedness matches cchar's flag(i8/u8) arms; libc protos take `char`). No typedef needed — coral's emissions match system/ABI once const shape is right.
- **`C"..."` types as `const cchar*`** (new `ccharPtrType()` in typecheck.crl): shape `Const{Pointer{Named cchar}}` = what type-position `const cchar*` params parse to today; also assignable to statement-const locals via compatible()'s source-const strip. `printf(C"...")` probe green via `import(lib) platform::libc { printf }` + `import(lib) core::cchar { cchar }` — cchar must be imported too (imported-decl types check against the caller's scope; pre-existing wart, 49× TC-0001 without it).
- **Generated C links libc directly (user directive) — NO system function headers**: preamble keeps only `stdint/stddef/stdbool` + `assert.h` (macro-only, declares no libc function coral also declares); removed `string/stdlib/stdio/unistd` → the conflicting-prototypes class is gone. Coral now emits ALL extern prototypes itself (`cgIsCrtFn` skip removed at 3 sites: cgEmitProtos + 2 method paths; the function itself is now dead code). `libc.crl` memcpy/memmove/memset return `rawptr` (was `void`; real C returns dst → kills -Wbuiltin-declaration-mismatch). Remaining gcc noise: builtin-mismatch **warnings** for `vsnprintf`/`strtod` const placement (`char* const` vs `const char*`) — the const-shape item below; ABI-identical, links fine.
- **local `static T name [= expr];`**: stmt.crl Var/Const/Static branch; flags bit2 = isStatic (4), bit1 hasInit now only when an init is present; omitted init = zero (C static semantics); codegen emits `static ` in both VarDecl branches (array + scalar). Probe (LCG `static u64 state`, call counter) green, generated C has `static uint64_t state`. Value persists across calls and is never dropped → ties into `#[[no_drop]]`/`#[[no_drop_all]]` (grammar.md:38/40) and future HIR drop-trait work; grammar.md statement-syntax note still TODO.
- **Array sizes order-independent (prescan declare-all)**: `prescanConstInts()` token-level pre-pass at `parseFile` start (mute `lexer.diag`, state machine `const` → head tokens → `=` → Dec/Hex/Bin/Oct → `;` into `Parser.constNames/constValues` table; freed by `freeConstTable()`); `parseDeclaratorArray` resolves Ident sizes via `lookupConstInt`. Error text: "array size must be an integer literal or a const int declared in this file". Cross-file consts need text.txt sema declare-all (open). Probe const-after-use green; sweep deltas ipa_cp −56, hmac −32, mimalloc −8, windows temp −109 parse.
- **Parser test PTEST=1 is the BASELINE**: git-clone HEAD → identical exit code + byte-identical output (pre-existing, not a regression). Builder test = 0.
- **Sweep 2026-10-08 (per-file clone-vs-working diff)**: parse 703→438 (−265); sema 50,709→55,954 — the rise is mostly *exposed* sema (parse-unblocked wallvm passes each gain +500–660 checks: unroll/simd_vec/licm/gvn/dse/loopcse/memory_ssa/machine_opt/loop_distribute) plus ~50 lines of char=utf32 churn (corpus `const char*` spellings vs cchar: ios+10, trie+9, process+6, hmac+12, xml/fs+3, ascii+2 …). Clean (parse=0 && sema=0) stable 46=46, zero clean→dirty flips. `branch_inversion` +2 / `branch_factoring` +3 parse = **user WIP** using `f64 a, b;` (committed version has single declarators) — not a regression.
- **Multi-declarator `T a, b;` NOT implemented (NEW gap — user WIP already needs it)**: parseExprOrDecl returns a single Stmt node, so comma lists need caller-side expansion or a DeclList stmt kind (+ sema/codegen); today `f64 a, b;` → PAR-0002/PAR-0001 then undeclared-identifier noise.
- Remaining parse hotspots: x86_64_base 45, x86_base 34 + linux 34 (user WIP), wasm 26 (WIP), sha256 18, lsra 17, mimalloc 14 (all `asm volatile` — parseAsmStmt doesn't consume `Volatile`; operand lists `: "=r"(v) : "m"(x) : "memory"` unparsed → NEXT), irParser 9.
- **const T\* shape fragmentation (open)**: type-position const parses `Const{Pointer}` (tyStr renders `T* const`), statement `const T x` = bare type + flags bit0, semantic types (str.ptr) = `Pointer{Const}`; `compatible()` strips const on one side only → cross-shape mismatches (~50 sema lines + the builtin warnings above). A prior session's element-binding fix was REVERTED (backup `/tmp/opencode/type.crl.const_fix` wiped; the "ParseType refactor" tick below records the intended end state: `const T*` → `Pointer(Const(T))`). Re-apply plan: bind `const` to base before suffixes in parseType; stop the stmt path from pre-consuming `const` (peek so parseType binds); unwrap Const in parseConstDecl's untyped-name detection; `integerType`/`floatType` strip Const/Comptime (else indexing on const locals breaks); `ccharPtrType` → `Pointer{Const{Named}}`; then str.ptr → `const u8*` params start matching.

## Session tick summary 2026-10-03
All verified cumulative; code committed in sequence 27dcaa1..7acd59f, then 1852667, 361a5c8.
- **1852667** (parser): brace-init at top level/var via `parseInitExpr` (`parseFuncOrVarDecl` value); fn-type-ahead guard in `type.crl` (stops `T x` being eaten as a cast in speculating contexts); `parseConstDecl` fn-shape speculation in `parseDecl` (`const T* f(...)`); nested `{...}` array-init elements.
- **361a5c8** (typed positional struct literals, 16 files): `parseLiteralFields` positional mode (`fieldNames=0` discriminator, maps by declaration order — str: 0=ptr, 1=len); sema `findMemberByIndex` (member.crl) + `coerceArrayLit` (recurses nested braces, sets `resolvedType`); codegen positional emission (skips `.name =`) + `cgEmitInitValue` for file-scope inits (fixes emitted-outside-function `__t0`); `inferArrayFromInit` — `T name[] = {…}` sizes the array (5 decl sites); "too many positional fields" TC-0006; corpus: `str.crl` `sv.ptr=`→`.ptr=`, asm_rules.crl:1088 stray `,`, keyword renames (compiler `any`→`hadOne`, `range.crl` `var`→`val`, branchprop/borrowcheck `any`→`anyHit`, `lib/std/misc/any.crl`→`erased.crl` with struct `Erased`/`asPtr`). Final struct-literal taxonomy: named `T { f=v, .f=v }`, variant `T::V{…}`, `str{…}`, **typed positional `T{v1,v2}`**, untyped brace-init `T x={…}`, array `{a,b}`, switch pattern `Some{value}`.
- **CWD-dependence bug (open)**: import resolution gives different error counts for the same absolute path depending on the working directory (repo root vs `/tmp/opencode/probe`) — latent loader/relative-path bug, diagnose before trusting single-file probes run from odd directories.
- Sweep trajectory (265 files, 47 clean): parse errors 21,090 → **660 (−97%)**; sema 22,830 → 49,653 (doubles as files start parsing). wallvm noret/wallvm.crl parse 2061→1; asm_rules 2373→651; mem2reg/irtypes parse 0. Remaining parse hotspots: temp.crl 109 (const-ident array sizes `T buf[_TMP_PATH_MAX]`), hmac 32×2, mimalloc 22×2, sha256 18×2, lsra 17; x86_base/linux 34 + wasm 26 are user WIP. Sweep probes run with `--dry-run -ferror-limit=0` from repo root; gcc-verified probes via `-o t.bin` (real gcc). 47 generated `.c` artifacts deleted from `lib/` (rule: never litter `.c`).
- Parser: local array decls `u8 tmp[72]` (stmt+const+struct-field); `= {a,b}` array-literal inits via ArrayLiteral; ternary binds like C; `~=` means `x=~y` in both bootstrap + coral-parser; switch `pat | pat => body` accepted (multiple patterns one SwitchCase; PatKind::Or codegen path ALSO repaired); nested `module::{ a, b }` imports parse; `static`/`extern` struct methods are now routed through parseFuncOrVarDecl with correct flags (complex self (fn-ptr) params like `usize(K) hf` compile); comptime T parses.
- Sema: two-pass declareAll+checkBodies (same-file fwd refs); If/While/For/Ternary/IfExpr conditions must be bool; ForIn validates iterable+bind; Deref non-pointer errors; `++`/`--` type propagating; assigning via `self=` unwraps implicit-self pointer; sameType TypeParam<->Named placeholder bridge; AssignCompatible accepts literal narrowing initializers (C-like constant conversion); `compatible()` hardened (no int/float interconvert; Str->pointer removed; Pointer match requires same base payload; const-add allowed Target: T* -> const T*; `T*`->rawptr allowed one-way; integer widening rule = same signedness widen or u->s-wider). selfNamedType feeds selfType params for struct/union/trait/variant method checks. BlockExpr setter propagates trailing expr type; switch-expr-body trailing expr through switch-expr result. StaticCall+S::method via Path now type-checked by findMethod; StaticCall type set to method return. TC-0007 SemaInternal in neutral sites. comptime T -> its fn must carry a comptime {} block.
- Lexer: f/F suffix -> f32 FloatLit (flags), l/L/ll/ul/ull suffixes numeric flags; exponent underscores rejected; overlong/invalid UTF-8 sequences and \u/\U surrogate bounds rejected.
- Codegen: 33 silent `cg.errors++` sites -> `cgError(msg)` -> `error[CG-0002]` (with all `if (cap)` conditions restored); Codegen's heap-allocated `DiagnosticEngine*` via `CompileUnit::engineObj` so CG messages render after analyze; cgFindDecl inline 32-entry name cache; Call/Path Static emit uses `S_new` + correct temp type; no C-`static` on method body definitions (extern protos consistent); struct-array fields in generated C were broken and were sidestepped via `Str*` + arena alloc (python-emitted C never got struct-array working).
- Builder command dispatch: `include "x.crlb"` expanded (8-deep cap, relative to including dir) and `build "X" extends "base.crlb"` merges base fields under child's (child wins).
- 2026-10-03: `@compileError(msg)` aborts sema with its message as TC-0002; `@isFormatLiteral(expr)` types as bool and emits 1/0 at compile time (true only for string literal args). `comptime T` parses (flags bit0) and fns with such params require a comptime{} block in their body.
- 2026-10-03: in-memory HIR groundwork (compiler/coral-hir): `HirModule` struct holds the resolved items + mono instances as interned rows; `build(ctx,file,mono,name)` constructs it; text is rendered (only on the `--emit-hir` flag) by `printHir`.
- 2026-10-03: distinct decls now emit typedef in C; `flag (ARCH) {...}` evaluated at parse time to the arm matching `ctx->targetArch` (default x86_64) else `else` arm; cchar.crl compiles through CG.
- 2026-10-03: three positions of `flag (NAME) { key => {...}, ..., else => {...} }` — type position (RHS of distinct/typedef), statement position (replaced by the selected arm's block) and expression position — all select the arm whose key equals the build-time flag value from a flag table fed by *both* `--flag NAME=VALUE` CLI args and a manifest `flags = ["NAME=VALUE",...]` list (compile.crl merges both before analyzeForCompile). If no args match and no else exists, compile errors.

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
- **Build system (NEW TODO 2026-10-03, user directive) — complete AFTER the compiler, in this order:**
  1. Finish the compiler (parse/sema diagnostics push) first; the build system is completed once the compiler is in a shippable state.
  2. `coral init`: must check whether the project has a `.gitignore`; if missing/absent entry, create it and add a `.coral/` entry (project-local state folder).
  3. Generated C must NEVER be littered into the source tree: emit to `~/.coral/artifacts` (or `/tmp` for scratch builds). Project build state lives in the project's `.coral/` folder. Rule enforced by past cleanups: 47 stray generated `.c` sweep artifacts were deleted from `lib/`; keep the repo free of `.c` output.
  4. Distribution/install: once both pieces are done, copy the `lib/` folder + the finished compiler + the complete build system into `~/.coral/` as the installed toolchain.
- **String literal convention (parser enforcement) + library convention**: `C"..."` is the C-style literal (nul-terminated, no len — the lexer already lexes it); every other string literal must be specified with its type and have a len attached to it; the parser must enforce this and the compiler will be made to enforce it everywhere. Library sweep already done as a first pass: 125 clearly C-style sites in lib/std, lib/core, lib/wallvm converted to `C"..."` (compiler/ untouched; IR text grammar untouched); still open: `asm volatile` template strings, println format literals, `@compileError`/`@assertOut` args, `pub str* NAME[]` initializer arrays. Details and open questions: `coral-docs/string-literals.md`. Corollary rule: `str::fromCstr` is for runtime C-string variables only — never wrap a literal in it (literals are str by default); `C"..."` stays only where the callee genuinely consumes a raw C string (printf formats, libc `const cchar*` params).
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
- **Too few diagnostic codes (user directive 2026-10-03)**: many distinct situations collapse into the generic `PAR-0001`/`PAR-0002`/`TC-0001` buckets. Each *kind* of mistake needs its own stable code so `coralc --explain <CODE>` can return a targeted long-form explanation. Allocation point stays single: `codeStr()` in `compiler/coral-diagnostics/code.crl` (scheme decision open: keep `PAR-0001` vs user's proposed `SYN-1002` — user cited rustc-style `XXX-nnnn` codes).
- **Missing semantic checks to add (verified absent / partial, 2026-10-03):**
  - **Mismatched return type**: partially checked (`compiler/coral-semantics/stmt.crl:84` compares expr type vs fn return) — gap: bare `return;` inside a non-void function is NOT caught; no help text showing the declared vs actual type spans.
  - **Missing return value / not-all-paths-return**: NO control-flow analysis exists — a non-void function whose body can fall off the end or take a branch without `return` compiles silently. Need a definite-return walk over If/While/Switch/Block/BlockExpr tails (rule already written at "Control flow" below: "The block must definitely produce the return value on all paths (unlike C)").
  - **Out-of-bounds array index**: NO check at all — only comment stubs `SEM-4001` in `compiler/coral-semantics/pointer.crl` (file is comment-only, unused). For `T[N]` with a static/literal index, sema must reject `i >= N` (and negative for signed) at compile time; runtime trap check is a later item.
  - Plus the many other absent checks listed under "Language rules NOT yet enforced by sema".
- **Diagnostics quality standard (researched from rustc, 2026-10-03):**
  - rustc-dev-guide: every error gets a **unique code** in `diagnostics.rs`; every code has a **long-form markdown explanation** served by `--explain`; codes formatted `E0001`-style (RFC 1567). Coralc analog: `PAR-xxxx` + a `--explain` long-form doc per code.
  - rustc-dev-guide (diagnostics): the window is **Message + primary span (file/line/col with source, caret) + optional secondary spans with labels + sub-diagnostics (help/note)**. The primary span must stand alone (understandable without the rest); labels explain *why*, `help:` says *what to do*, `note:` adds context. Coralc's `why`/`fix`/`learn` fields map exactly to help/note/learn — populate them on the common render path.
  - Search the internet for more error-message catalogs as this work proceeds (user directive): rustc/clippy/gcc/clang error-code lists are the reference sets to mine for situations coral must diagnose.
- Still open from earlier: **text.txt three-pass sema** (declare-all → dependency-tracked eval → cyclic-import error) — see Unimplemented todos; it changes when these sema checks can even run.


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

### Accessing a member of a struct from a function returning it's type
```crl
  struct this { // `this` is not a coral keyword, no need to worry
    i32 goo, moo;

    this new(i32 a, i32 b) { return this { .goo = a, .moo = b }; }
    i32 add() { return self.goo + self.moo; }
    i32 sub() { return self.goo - self.moo };
  }

  pub i32 main()
  {
      // c is an i32 here from type inference
      var c = this::new(2, 3).goo; // where we access the item from the static method or something
      var d = this::new(c, 3).add().sub(); // the login in this chained mthod call might be incorrect,
                                           //fix it, but it should be a chained call
  }
```
- This allows for what it should allow.