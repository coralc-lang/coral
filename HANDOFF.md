# HANDOFF — coralc self-host compiler (2026-10-03)

## Owner directives
- **2026-10-17 — parser static free functions get stripped.** The owner will remove the use of static free functions from the parser; they should not be allowed again. Do not add new ones.
- **2026-10-17 — errors.txt (project root) must be matched to what we support**, with a priority object; many of the listed errors need to be implemented in the compiler. Includes: enforce module privacy (items not marked `pub` must not be callable/usable), OOB index of fixed arrays must be impossible, switch exhaustiveness rules (all variants no else, or else, fallthrough warned), slice type proposal (`slice T name;` or `T name[..]`), error codes E0103/E0104/E0105/E0201-E0205/E0304.
- **2026-10-17 — after compiler-new compiles and runs:** add a build and cache system (much is still incomplete); implement `coralc init`, `exec` in the build fields, and the other unimplemented parts; add `coralc --serve` + JSON serialization so the compiler acts as a language server (type info, multi-file tracking, lib referencing).

## Repo / build commands
- Workspace: `/home/cerie/Documents/coralc`
- Build compiler: `timeout 200 python3 bootstrap/coralc.py compiler/coral-frontend/coralc.crl -o /tmp/opencode/coralc > /tmp/opencode/build.log 2>&1; echo BUILD=$?`
- Compile a file: `timeout 20 /tmp/opencode/coralc <file>.crl -o /tmp/out`
- Parser test: `python3 bootstrap/coralc.py compiler/coral-frontend/test.crl -o /tmp/opencode/pt && timeout 30 /tmp/opencode/pt`
- Builder test: `python3 bootstrap/coralc.py compiler/coral-build/test_builder.crl -o /tmp/opencode/tb && timeout 30 /tmp/opencode/tb`
- `/tmp/opencode` may be wiped on restart → rebuild.

## Completed this session

## Session tick summary 2026-10-15c (ph1 placeholder matrix GREEN: cchar type-switch, str→ptr casts, arena move-safety)
Uncommitted compiler files: mono.crl, collect.crl, instantiate.crl, comptime.crl, codegen.crl, context.crl, pattern.crl, bootstrap/codegen.py, HANDOFF.md. Build BUILD=0.

**ph1.crl** (the 26-line placeholder/println matrix) now compiles and runs rc=0 with correct output end-to-end (i32/neg/u64/i64/f64/f32/bool/str/char/cstr/usize/isize/toStr/specs `{:d} {:x} {:b}`/spec neg/spec big/esc/brace-escape/mix/spaces/hex/bin/Repeat/ptr `{:p}`/runtime fmt/print/flush/eprintln). pg0–pg3 bisect groups green; ph2_0/1/2 green; full ct battery (ct1–ct11, tostr, tostr2, polymin, usz, bx, iter1, iter2, x1–x4, m1, m2) re-verified.

**Root causes fixed:**
1. **Arena move-safety** (context.crl, new `growStable` used by `growNodes`/`growTypes`): the nodes/types arenas were `realloc`-grown; the mono evaluator caches raw `Node*`/`TypeEntry*` in locals, so the moment a nested instantiation grew the arena mid-evaluation, cached pointers dangled → pg2/ph1 segfault (`evalArmBody`'s cached `Node*` after the arm's own arg-rewrite allocated a node). `growStable` allocates a fresh block and keeps the old one allocated — stale reads stay valid and content-identical (geometric waste < 2x, never freed; revisit with a chunked arena when convenient).
2. **Type-switch exact-match pass** (comptime.crl `evalSwitch`): pass 1 matches arms naming the scrutinee type *exactly as spelled* (new `patToTy`), pass 2 keeps the loose alias/underlying/usize≡u64/trait matching. Fixes `cchar =>` losing to the `u8` arm.
3. **`resolvePatBase` distinct handling** (comptime.crl): a symbol whose `typeNode` is not a Named-with-the-same-name (a `distinct`'s representation) now resolves to the Named entry when one exists — the pattern `cchar` denotes `Named cchar`, not the flag's else-arm representation (`flag(arch)` gets no value from the plain CLI, so it picked `u8`). `println("{}", cchar)` now prints the glyph (`char: A`).
4. **Comptime literal types** (comptime.crl): `makeBool`/`makeStrCopy` set `.ty` (boolType/strType) so `tyOfVal` infers the right `T` for `_fprintOne` — bool literals were matching the `str` arm (`val` undeclared in the "bool: {} {}" instance) and a str literal tail hit the i32 arm.
5. **str→pointer cast** (codegen.crl Cast arm): `(const cchar*)"cstr"` now emits the C string token directly (`((char* const)("cstr"))`) — a `_coral_str` slice struct cannot cast to a pointer (was gcc `cannot convert to a pointer type`).

**Verification:** ASan (`gcc -g -O1 -fsanitize=address`, `detect_leaks=0`) clean on the whole ct battery incl. ph1. Valgrind cannot run on this box (Arch ships a stripped `ld-linux-x86-64.so.2`; memcmp redirect setup fails) — ASan is the substitute. 32-probe sweep vs baseline `coralc_prev` (worktree `/tmp/opencode/base`): **0 diffs** (rc and program output).

**Cleanup:** removed the `[cg] CG-0002` debug printf + its unused printf extern from codegen.crl. The `[mono]` error-path prints (instantiate :315/:550/:559, collect :155) are deliberately retained — they are the only report for internal mono invariant/compile failures; strip once those route through the diagnostics engine.

**Open:** no CLI path feeds `flag(arch)` a value yet (bootstrap CLI has `--flag name=value`; the built coralc frontend does not) — cchar's representation resolves via the flag's else arm, harmless now that switches match the Named type; io_basic.crl still blocked on pre-existing sema TC-0002 at `lib/std/x86_64/linux/io/fs.crl:254`; turbofish value-variant first-match gap (codegen.crl) still open.

## Session tick summary 2026-10-15 (M2 follow-ups: toStr prong, usize/isize, `{..}` iterables, runtime-body rewriting)
Uncommitted compiler files: mono.crl, collect.crl, instantiate.crl, comptime.crl, codegen.crl, pattern.crl, bootstrap/codegen.py (+ HANDOFF.md). Build: `timeout 300 python3 bootstrap/coralc.py compiler/coral-frontend/coralc.crl -o /tmp/opencode/coralc` → BUILD=0.

**Landed:**
1. **CG-0002 root cause (struct args to generic calls)**: `callValueKeyTyped` hashed `substituteType` results, but substitution interns a fresh copy per call → collect-time vs codegen-time keys differed. New `typeDigest` (mono.crl) — structural, allocation-free hash of the type tree; both phases use it now. `tostr.crl`/`polymin.crl`/`bx.crl` compile (was `error[CG-0002] no unique mono instance for call`).
2. **`(any toStr)` prong**: `v.toStr()` parses as `ExprKind::MethodCall` — comptime.crl had NO MethodCall handling. New `evalMethodCall` re-roots receiver/args and returns a fresh kind5 node (or `makeRt(id, rt)` when unchanged); wired into `evalExpr` + `evalExprStmt`. Old `evalCall` Field-callee re-rooting kept for `x.field(...)`.
3. **usize/isize print**: `samePatTy`/type-switch alias fix (Usize≡U64, Isize≡I64) — `usz.crl` prints `5 7`.
4. **`{..}` over comptime `str`** (iter1): `evalForIn` unrolls str bytes at comptime, binding each as a `u8`-typed runtime literal so `@typeof(elem)` folds on u8 (uses a local `Sema*` — chained receiver method calls emit broken C). iter1 prints `104, 105`.
5. **Runtime `{..}` over collections** (iter2 `i32 xs[] = {1,2,3}`): runtime loop refs now rewritten end-to-end. New in comptime.crl:
   - `emitSink` stack (`sinkBufs/sinkLens/sinkCaps`, `emit()` appends to the innermost sink; `sinkPop` hands the buffer to the AST context tracked); `emitCount`/`emitRewind` are sink-aware.
   - `rwStmt`/`rwExprRef`: recursive rewrite of runtime statements at depth>0 — For/While/Loop/ForIn/If/Block/VarDecl/Assign/ExprStmt/Return get reconstructed with bound caller-side refs (`out`→`&out`, `val`→`_varg0`) so inlined stdlib bodies compile; runtime ForIn also binds the loop elem as a runtime ident typed with the collection's element type (so `@typeof(elem)` in `_fprintOne` infers right).
   - `promoteLoopAssigns`/`collectLoopAssigns`: comptime locals assigned inside a runtime loop body (`bool first = true` in `_fprintIter`) are rebound as runtime idents and their `if`/assign statements stay runtime (a comptime fold would eat the `", "` separators). iter2 prints `1, 2, 3`.
6. **Return value drop fixed** (x3): `StmtKind::Return` at depth>0 never evaluated its value expr → `return _fprintPtr(out, …)` vanished (implicit-decl `_fprintPtrVal`). New `evalExprValue` (extracted from `evalExprStmt`) evaluates it; `rwStmt` rewrites it too.
7. **Repeat/spaces arms fixed** (x1): `rep:[xxxx]` — the `'_'`/`'l'` arms' unrolled `_pbyte(out, ' ')` now re-roots `out` (same runtime-body machinery).
8. **Bootstrap struct array fields** (bootstrap/codegen.py `field_decl`): Python bootstrap emitted `T[N] name;` for array struct fields (invalid C) — CtEval's `NodeId* sinkBufs[8]` hit it. Now emits `T name[N];` (Coral codegen already did).
9. **codegen tail-param Array emission** (M2 leftover): tail params of Array type emit `base name[]` instead of `base[N] name`.

**Design decision recorded (user, 2026-10-15) — iteration model:** keep the **structural fast path** for `Array`/`Slice`/`pack`/`str` (no protocol, no allocation, element type + length known) and add an **`iter` trait** as the fallback for anything else: loop desugars to `container.iterator()` + `it.next()`, stdlib implements it once for arrays/slices/str/Vec, user types opt in by extending the trait. Trait-only is the most uniform but routes plain arrays through iterator state (and is heavier in mono: generic instance resolution + real loop-state emission); structural-only is easiest now but rots into a compiler special case per container. **Not implemented yet — future work** (applies to `println("{..}")` too, since `_fprintIter` is just range-for).

**Open / next:** ph1.crl placeholder matrix segfaults the compiler (rc=139, bisect incomplete; x1/x2/x3/x4 isolated OK); `[cg] CG-0002` diagnostic printf in codegen.crl + `[mono]` prints in collect.crl/instantiate.crl still to strip before commit; turbofish value-variant first-match (codegen.crl :1217/:1247) still open; io_basic.crl still blocked on pre-existing sema TC-0002 at `lib/std/x86_64/linux/io/fs.crl:254` (`str::fromParts(path.ptr, …)` const `u8*` mismatch).

## Session tick summary 2026-10-15 (MILESTONE 2 LANDED: `println("{}", …)` + heterogeneous runtime tail args)
Uncommitted compiler files this session: mono.crl, collect.crl, instantiate.crl, comptime.crl, codegen.crl (+ HANDOFF.md). Build: `timeout 300 python3 bootstrap/coralc.py compiler/coral-frontend/coralc.crl -o /tmp/opencode/coralc > /tmp/opencode/build.log 2>&1; echo BUILD=$?` → BUILD=0. Verified (`/tmp/opencode/ct`, single-file, `lib` symlink): ct1 `hello`; ct2 hello/bye/hello (2 keyed instances, `...` sig — M1 shape preserved); ct3 `println("{}", 42)` → `42`; ct4 `i32 x=5; print(x)` → `5` (was gcc "val undeclared"); ct5 runtime int → `5`; ct6 runtime str → `hi`; ct7 float literal → `3.14`; ct8 `"{} {}"`,1,2 → `1 2`; ct9 `print(str)` → `hi`; ct10 mixed i32/f64/str → `1 2.5 z`; ct11 same fmt with i32 vs f64 → **2 distinct typed-key instances**. Generated C: ct5 `println__…_v618cd05f…(_coral_str fmt, int32_t _varg0)` body `_fprintI32((&(out)), _varg0);`; ct10 `(…, int32_t _varg0, double _varg1, _coral_str _varg2)`; ct3 folds the literal to `42`; ct6 `_fprintBytes((&(out)), _varg0.ptr, _varg0.len);`; **zero `switch(`** in all emitted files. Probe sweep (32 `.probe` files, baseline worktree `df86f4c` → coralc_prev): **only io_basic.crl differs** — same rc=2, failure advanced from 8× `placeholder/argument count mismatch` to 1× `type implements neither a builtin printer nor toStr` (newly exposes that `usize`/`isize` have no `_fprintOne` switch arm — pre-existing lib/sema gap, still rc=2; everything else bit-identical). `coralc build` on the compiler tree fails pre-M2 too (comment-only `compiler/coral-frontend/lib.crl` parses `#…` as an error) — bootstrap remains the supported path.

**What landed (M2):**
1. **Tail-arg recording** (collect.crl): `collectCall` records every non-Spread arg past the fixed params (`tailTypes[k]` = exprType+activeSubs, `tailNodes[k]` = arg id), `arity = tailLen` (a bare `...` never counts → forwarded `_printEmit(&out, fmt, ...)` stays arity 0, M1 semantics). New `callValueKeyTyped` (mono.crl): valueKey ⊕ each arg's substituted resolvedType → `println("{}", x_i32)` vs `y_f64` get distinct instances. `MonoWorkItem`/`MonoInstance` carry `tailTypes/tailNodes/tailLen` (`tailArgNames` on the instance; all freed in clear()); `enqueueVal` dedupe requires equal tailLen + per-tail sameType.
2. **Comptime pack construction** (instantiate.crl `evalComptimeBody`): `packArity > 0` builds the pack — literal tails fold (StringLit→`strLitVal`, IntLit/CharLit→new `makeIntTy(value, tt)` carrying the arg's type, BoolLit→`makeBool`); runtime tails become fresh `Ident` nodes named `_varg0…_vargN-1` (resolvedType = tailTypes[k], nodes stored in `instance.tailArgNames` so codegen declares the same names); the pack binds to the variadic param so `for (var arg : args)` unrolls, and `_fprintOne`'s `switch (@typeof(T))` sees the element's own type.
3. **Per-call generic inference** (comptime.crl `evalCall`): after binding param `pp`, when pp's type strips (Comptime/Const) to `TypeParam` or a Named matching a `genericParams` name, infer from the arg's CtVal type (new `tyOfVal`: kind4→`.ty`, else `.ty`, else arg node resolvedType) through new `resolveTypeParamTy` (TypeParam→lookup(name)→kind4) and bind the gp name — this **shadows the accidental outer-T name-collision** that made M1's str arms work; now `_fprintOne<comptime T>` truly binds T from its own argument.
4. **Runtime arg emission** (comptime.crl `evalExprStmt`): every call arg is probed via `evalExpr` (not just Ident/IntLit/CharLit/BoolLit) — kind1/2 → `valToNode` (arg's resolvedType copied onto the fresh node), kind3 → new `mkStrLitTy(bytes, argTy)` (pointer-typed literal, not a slice), kind5 → emit the bound caller-side node. `Cast` of kind5 re-roots to the inner node (`(i32)val` → `_varg0`, C implicit conversion at the arg slot); `Field`/`Index`/`DerefField` of kind5 re-root fresh nodes (`val.ptr` → `_varg0.ptr`, `f.ptr[i]` with literal i → `valToNode(i)`). This fixes ct4's emitted-undeclared `val`.
5. **Signature + match** (codegen.crl): `cgEmitParams`/`cgEmitProto`/`cgEmitFuncCommon` take a `MonoInstance* inst` (all 9 call sites updated); when `inst.tailLen > 0 && inst.tailArgNames != null` the variadic param emits named trailing params `, <ty> _varg<k>` instead of `...` (call sites pass args positionally either way); `cgEmitFuncCommon` `cgAddLocal`s the tail names. `cgCallFromDecl` keys via `callValueKeyTyped(args, argsLen, cg.subs, cg.subsLen)` and type-matches via new `mono.inferCallArgs` (mirrors collectCall slot inference; replaces the `inst.argumentsLen == argsLen` prefix check that mis-picked for variadic calls). ct2 keys changed from M1 (`_v3ed333…`/`_v12a691…`) because the typed key mixes resolvedType — expected.

**Known limitations (post-M2):** `usize`/`isize` have no `_fprintOne` arm (needs a lib arm or an alias-matching policy decision — io_basic rc=2 either way); `(any toStr)` user types + `{..}` iterators still untested end-to-end; turbofish value-variant first-match (codegen.crl :1217/:1247) still open; flat-emission sibling-scope name collapse unchanged.

## Session tick summary 2026-10-15 (MILESTONE 1 LANDED: `println("hello")` compiles + prints)
Uncommitted compiler files this session: mono.crl, collect.crl, instantiate.crl, comptime.crl, codegen.crl (+ HANDOFF.md). User chose **Option A — Zig-style monomorphization** (value-keyed instances) via question tool.
Build: `timeout 300 python3 bootstrap/coralc.py compiler/coral-frontend/coralc.crl -o /tmp/opencode/coralc > /tmp/opencode/build.log 2>&1; echo BUILD=$?` → BUILD=0. Verify: `cd /tmp/opencode/iotest && rm -rf build && timeout 150 /tmp/opencode/coralc build -ferror-limit=0` → **`hello`** (note: delete `build/` before rebuild — the stale-check does not notice lib/mono edits). ct suite: ct1 `HiO` (grep -c switch ct1.c = 0), new ct2 (`println("hello"); println("bye"); println("hello");`) prints hello/bye/hello with **2 value-keyed instances** (`_v3cd73622badd2233` hello, dedupe of the repeated literal; `_v111d9fef51fd4fcb` bye), a/b/c unchanged. Probe sweep `.probe/*.crl` (32 files, copied to /tmp/opencode/probes with `lib` symlink): **bit-identical results to a pre-session baseline compiler** (chain/hashshape/p_cg10/p_cg2/p_flag/p_fopen/p_nested/p_opt2/p_opt/p_pf2/p_pf/p_trim/p_trim2/p_trim3 pass, same run codes; the 18 other failures — io2, p_cg*, genargs etc. — pre-exist; baseline built via `git worktree add /tmp/opencode/base HEAD` + prior-session uncommitted files copied in, then `coralc_prev`).

**What landed (Option A, all verified by the runs above):**
1. **Value-keyed instance identity** (soundness fix from the 2026-10-14 agent verdict): `MonoInstance`/`MonoWorkItem` += `valueKey, packArity, literalNames, literalNodes, literalsLen` (mono.crl structs ~:75-95, clear() frees). New `MonoCaller.callValueKey(args, argsLen)` (mono.crl ~:383): FNV-1a (1469598103934665603 / 1099511628211) over per-arg tokens 'S'+string bytes / 'I'/'C'/'B'+value / 'P' bare spread / 'R' runtime, argsLen mixed in — computed identically at collect time and codegen time from the same nodes. `collectCall` records fixed-param literal args (`litNames` = param name, `litNodes` = arg node), computes `arity = argsLen - namedCount` clamped, passes key/arity/literals to new `enqueueVal` (dedupe now requires equal types AND equal valueKey). `hasInstance`/`addInstance` take the key; `addInstance` now returns the instance index via `outIndex` (fixes the old `instances + instancesLen - 1` after dedupe-hit wart in `run()`).
2. **Codegen keys the symbol + body**: `cgInstanceNameV` appends `_v<hex>` when key != 0 (cgWriteHex); `cgCallFromDecl` computes the call's key and prefers the keyed match (falls back only to a lone valueKey==0 instance — multiple same-typed instances with no key match = hard error); `cgInstanceBody`/`cgEmitFuncCommon` take valueKey; proto/body loops use `cgInstanceNameV(..., inst.valueKey)`; turbofish paths (:1217/:1247) now use the instance's keyed name too (variant SELECTION there is still first-match — known gap).
3. **evalComptimeBody binds call-site values** (instantiate.crl): after type substitutions, each recorded literal arg binds the param name (StringLit → new `CtEval.strLitVal` — strips the intern's surrounding quotes, handles `C"…"`; IntLit/CharLit → makeInt; BoolLit → makeBool). Variadic instances with arity 0 bind the pack param to `makePack(null, 0)` so `for (var x : args)` unrolls to ZERO iterations.
4. **Evaluator fixes needed by the literal scanner** (comptime.crl):
   - `@isFormatLiteral` evaluates the ARG (`evalExpr` kind3 ⇒ true; runtime fmt stays unbound → false). 
   - evalCall inlining: param loop restructured (`while (p < paramsLen)`, per-param `pi < argc` guard) so a trailing variadic param is reached when `pi == argc` and binds an EMPTY pack (`else if (pp->name != 0)`); previously the loop exited at `pi == argc` (dead code) — this was the CG-0002 root.
   - `evalArmBody`: switch arms evaluate their Block WITHOUT the scope-restore so `f = fmt;` inside `str => { … }` survives the arm (Block eval restores bindings; the arm assignment was being dropped → remainder loop saw `f` unbound → emitted the while with `@compileError` inside → CG-0002). Used by type-switch and int-switch arms.
   - `tryFoldAssign` plain `=`: a declared-but-unbound local (`str f;`) binds the comptime value AND emits a rewritten runtime assign whose RHS is a fresh literal (`valToNode`; new `mkStrLit` interns a quoted+escaped form since codegen reads StringLit text with quotes) — the original RHS (`fmt`) is comptime-only and must not leak into the C body.
   - `evalVarDecl`: emits a decl only once per name (`declNames` set; `declEmitted` rewind signal only when `loopDepth == 0`) — unrolled loops re-evaluating the same VarDecl no longer duplicate C decls or force loop re-emit.
   - `evalExprStmt` call-arg rewrite: kind5 args (`av.rid`) are now rewritten too, so `_pbyte(cgIdent, byte)` emits the caller-side node (`_pbyte(&out, 104)`); plus StringLit now uses `strLitVal` (value bytes, no quotes).
5. **Debug prints stripped** (except error-path `[mono] enqueue mismatch` / `validateInstance FAILED` / `evalComptimeBody FAILED` / type-switch miss, which are kept as diagnostics).

**Expected iotest C shape (now generated, for reference):** `println__<str>_v<hex>(_coral_str fmt, ...)` with body `outBuf; out; str f; (f = "hello"); size_t i = 0; _pbyte(&out, h/e/l/l/o); _fprintNewline(&out); _pflush(&out);` — `f`/`i`/`c` are dead but keep the flat body C-valid.

**Known limitations / next (Milestone 2):** — *RESOLVED 2026-10-15, see the M2 tick above.*
- `println("{}", 42)` (literal fmt + heterogeneous runtime args) still hits the for-in fallback at the instance level: the literal branch's `for (var arg : args)` needs the pack elements bound to the instance's own trailing param idents + named trailing params in the prototype (collect already records arg types per position when arity > 0 — the design from the 2026-10-14 addendum (A) covers it, not yet implemented).
- Turbofish value-variant selection picks the first type-match (codegen.crl :1217/:1247) — correct symbol now (keyed name), wrong variant possible when the same type has ≥2 keyed instances.
- Flat emission means declarations/assignments from a comptime-unrolled frame are visible for the WHOLE instance body (name collisions across sibling scopes collapse — accepted for now; see declNames once-per-name).

## Session tick summary 2026-10-14 (comptime print pipeline wired; ios variadic-pack for-in is the last blocker)
Uncommitted compiler files: codegen.crl, compile.crl, coralc.crl, comptime.crl, instantiate.crl, analyze.crl, expr.crl (+ explicit user commits this day: 7aa2d93 ios, 483b712 lib, 330a449 str). Build: `timeout 300 python3 bootstrap/coralc.py compiler/coral-frontend/coralc.crl -o /tmp/opencode/coralc > /tmp/opencode/build.log 2>&1; echo BUILD=$?` → BUILD=0. Verify ct1: `cd /tmp/opencode/ct && timeout 30 /tmp/opencode/coralc ct1.crl --no-prelude -o ct1 && ./ct1` → prints `HiO`, `grep -c switch ct1.c` = 0. iotest: `cd /tmp/opencode/iotest && timeout 150 /tmp/opencode/coralc build -ferror-limit=0` → sema clean, **codegen fails CG-0002 "for-in over non-slice/array"**.

**DONE this session (all verified):**
1. **codegen reads instance bodies now** — new `cgInstanceBody` (codegen.crl ~:4282, before `cgEmitFuncCommon`): matches a FunctionInstance by declaration.index + substitutions (parameter+typeNode per index), returns `inst.body`; `cgEmitFuncCommon` does `bodyId = dd…Func.body; instBody = cgInstanceBody(...); if (instBody.index != 0) bodyId = instBody;` (~:4345). Root cause: codegen ALWAYS emitted the *declaration's* body, so comptime-rewritten instance bodies were never used (functions emitted empty). Applies to generic + non-generic + method paths (all call cgEmitFuncCommon).
2. **Body replacement condition** (instantiate.crl ~:363): was `emittedLen > 0 && emittedLen != stmtsLen` → equal-length rewrites (`[comptime{N}]` → `[stmt]`) were skipped (i32 arm emitted nothing). Now `emittedLen > 0` only. `emittedLen == 0` keeps the original body (comptime-only body → codegen emits nothing → empty fn, correct for fully-folded).
3. **const-int genericity extended** (expr.crl, fixes user's ios.crl:611 `u64 limit = neg ? 9223372036854775808u : INT64_MAX;` after the user removed the manual `(u64)` cast in 483b712):
   - `isConstIntExpr` → wrapper over `isConstIntExprD(id, depth)` (depth cap 24) which now also accepts **Ident → const decl value** (via `lookupAt` + `DeclKind::Constant`) and **Ternary of const-int branches** (cond excluded); fixed a pre-existing `Shl.left && Shr.right` payload typo into `Shl.right`.
   - NEW `hasUnsignedSuffix(id)` / `hasUnsignedSuffixD` — true when a `u`-suffixed literal appears anywhere in a const-int expr, or an unsigned-typed int const ident is referenced.
   - `assignCompatible` const-int fast path (~:385): `if (self.hasUnsignedSuffix(value)) return !self.intSigned(targetTy);` before `setExprType(value, targetTy)` — the fast path used to launder `5u`/`9223372036854775808u` into signed targets during ternary branch unification.
   - Behavior (verified t1/t2/t3 probes in /tmp/opencode/ct): `u64 a = c ? 9223372036854775808u : <i64 const or lit>;` OK; `u64 e = c ? 5u : 1;` OK; `i64 d = c ? 9223372036854775808u : 1;` still rejected (u = unsigned-only); `u64 c = i64Var;` still rejected (no implicit). **These rules extend the existing documented const-int/u-suffix rules — flag to user for veto if the ternary unification semantics should differ.**
4. **Prelude** (analyze.crl ~:1399, inside `if (!noPrelude)`): loads `core::str`, `std::io::ios`, `std::text::string`, `std::option`, `std::vec`. Deliberately NOT loaded:
   - `std::result` — result.crl:24 `isErr` resolve fail + :94 `Ok { error }` unknown field (field is `value`); never loaded by default builds.
   - `std::collections::arr` — `Arr<T, N>` uses a generic param as array size; parser rejects (`type.crl:140` "array size must be an integer literal or a const int declared in this file"; sizes resolve to `u32` at parse time). Needs type-representation work (symbolic array size) — do not preload until then.
   - Path note: `std::arr`/`std::vec`/`std::option`/`std::result` aliases exist in the GENERIC `lib/std/lib.crl` but NOT in the platform `lib/std/x86_64/linux/lib.crl` (that one has vec/option/result but no arr/text) — `std::io::ios` and `std::text::string` resolve via directories + platform segs; `std::collections::arr` resolves by directory too.
5. **`--no-prelude`** (args.crl — committed by user in 330a449): flag classify is **length 12** (`--no-prelude`), `Options.noPrelude`, plumbed through compile.crl/coralc.crl/analyzeForCompile. Single-file usage: `coralc <file.crl> --no-prelude -o out`.
6. **lib/std string.crl fixes (linux + windows, user-requested)**: `const u8* src = …; src = …` → `u8* src = self.ptr + off; src = self.ptr + off + sv.len;` (statement-level `const T x` makes the VARIABLE const in coral → reassign = TC-0008); `r.pushStr(&self)` ×2 → `r.pushStr(self)` (self is already `String*` in methods, `&self` = `String**` ≠ `const String*`).

**Debug instrumentation STILL IN TREE (strip before final; rebuild after strip):** — *STRIPPED 2026-10-15 (see top tick); error-path prints kept.*
- comptime.crl evalSwitch: prints at :1291 (sc.kind/cases), :1306 (arm i/hit), :1311 (arm emitted count).
- instantiate.crl: :344 (evalComptimeBody decl/subs), :346 (emitted/failed/miss), :366 (bodytag/stmtsLen/emitted); pre-existing :230 validateInstance FAILED, :349 FAILED msg, :358 type-switch miss.
- collect.crl: :148 enqueue mismatch, :350 collectCall decl/gcount/ok/arg0.

**CURRENT BLOCKER — CG-0002 for-in (precise trace, all from /tmp/opencode/iotest.log):**
- iotest app: `i32 main() { println("hello"); return 0; }` (prelude provides println; no imports needed).
- log: `[mono] collectCall decl=3430 gcount=1 ok=1 arg0=3` → `[ct] evalComptimeBody decl=3430 subs=1` → `evalSwitch sc.kind=4 cases=23`, `arm 14 hit=1`, `arm eval emitted=1`; `evalComptimeBody decl=3430 emitted=6`; `bodytag=6 stmtsLen=5`.
- `decl=3430` = **`println<comptime T>`** (ios.crl:496) body = 5 top-level stmts: `outBuf`, `out`, `comptime { _printEmit(&out, fmt, ...); }`, `_fprintNewline(&out)`, `_pflush(&out)` — stmtsLen=5 ✓.
- The 23-arm switch is **`_fprintOne`'s `switch (@typeof(T))`** (ios.crl ~:223) evaluated INLINE under println's `evalComptimeBody` (evalCall inlining; no separate evalComptimeBody) — arm14 = `str` → emitted=1.
- `@isFormatLiteral(fmt)` in `_printEmit`'s comptime evaluates **FALSE**: `fmt` is a value param, not bound (evalComptimeBody binds only type substitutions; `evalBuiltin` isFormatLiteral tests `litStringBytes` on the RAW node → Ident → false). So `_printEmit` takes the **else branch** (ios.crl:466-468): `_fprintOne(out, fmt); for (var arg : args) _fprintOne(out, arg);`
- `for (var arg : args)`: `args` = variadic pack ident, unbound in ct scopes → evalExpr → `makeRt` (kind5) → `evalForIn` can't unroll (needs kind6 pack) → **fallback re-emits the whole for-in as a runtime stmt**.
- codegen `cgStmt` ForIn (~:3932-3938) requires the iterable's `resolvedType` to be Slice/Array; a variadic pack isn't → **CG-0002** (loc-less, reported under app file).
- Arithmetic check: emitted = [outBuf, out, 1 stmt from `_fprintOne<str>` arm, for-in, `_fprintNewline`, `_pflush`] = 6 ✓.

**Fix options (DESIGN CALL — ask user before implementing):**
- **(A) record call-site literal values in mono** so evalComptimeBody binds value params (`fmt` → kind3 str) → `@isFormatLiteral` true → literal branch. But `MonoInstance.arguments` is `Ty*` only and `collectCall` takes types; needs value recording (at least literals) + binding in evalComptimeBody. Note the literal branch ALSO has `for (var arg : args)` (:394) — with the instance's pack ARITY known (collectCall has `argumentsLen`) an EMPTY pack unrolls to nothing (covers `println("hello")`); non-empty needs values (C) or runtime (B).
- **(B) variadic packs become runtime-materializable** — sema types a `...args` param as slice/array, codegen materializes call-site args into a temp array at variadic call sites (C-varargs reality); then a runtime for-in over a pack is legal and the else branch (values-only print, `vaprint` :533) works untouched.
- **(C) evaluator unrolls pack for-in using recorded call-site values** (subset of A; runtime non-literal args force fallback → still needs B for those).
- Both A and B touch core data structures (mono `MonoInstance`/`collectCall`; sema pack typing + codegen call lowering) — don't pick unilaterally.

**Agent diagnosis addendum (two explore agents, 2026-10-14):**
- Pack params: parser sets `flags=16`, `typeNode=0` (parser/decl.crl:391-404); sema declares the name with Type 0 and stays silent (stmt.crl:348-352) → `args` has `resolvedType == 0` → codegen `te == null` → CG-0002. Sema for-in accepts only Slice/Array but has a comptime-depth exemption (stmt.crl:121-151, guard at :128-133); codegen re-checks strictly (codegen.crl:3924-3941).
- Call lowering: no variadic-specific handling; trailing args emitted individually into the C call (codegen.crl:2399-2434); prototypes emit C `...` for ANY `flags & 16` param incl. externs (cgEmitParams codegen.crl:4209-4217); **no `va_start`/`va_arg` exists anywhere**; a runtime pack Ident has no C declaration (param erased as unnamed `...`, codegen.crl:4214). Spread `...` is comptime-only (lowering at codegen.crl:2958-2961 emits literal 0 for bare `...`).
- **SOUNDNESS VERDICT (critical)**: instances are keyed ONLY by (kind, decl/name, type args) — enqueue collect.crl:144-178, hasInstance instantiate.crl:122-134; body rewritten in place (instantiate.crl:381); every type-matching call dispatches to the same symbol (cgCallFromDecl codegen.crl:988-1028, cgInstanceName :326-338, cgInstanceBody :4282-4311). So binding call-site values into a shared instance body is **silently unsound** (`println("hello")` and `println("x {}", v)` both map to `println<str>`) unless the value fingerprint becomes part of the instance key/mangling everywhere.
- `@isFormatLiteral` checks the RAW node — `litStringBytes` on the arg node (comptime.crl:592-604, :634-645); binding `fmt` alone does NOT flip it (must eval the arg / consult the binding; but a bound RUNTIME str must stay false → record literal-ness).
- Empty pack: `evalCall` inline SKIPS binding when `pi == argc` (comptime.crl:777 `if (pi < argc)`); if bound, `makePack(elems, 0)` unrolls the loop to ZERO iterations via the good path (evalForIn comptime.crl:1416-1458; fallback `self.emit(id)` at :1420-1424 is the runtime re-emit that hits CG-0002). Other warts: inline never restores caller's `variadicPackName` (:788 vs :823); `hasInstance` compares name not declaration.index (instantiate.crl:127); `run()` uses `instances + instancesLen - 1` even after dedupe-hit (instantiate.crl:226-227).
- **Refined design options** (see verdict): **(A) Zig-style monomorphization (recommended)** — key instances by (types + literal-value fingerprint + arity/arg types); for instances of variadic fns, emit NAMED trailing params (one per call-site arg, typed from the recorded arg types — call sites already pass them individually, so C call convention is compatible); evalComptimeBody binds `fmt` (literal→kind3 + isLiteral flag) and packs (elements bound to the instance's own trailing param idents, not caller nodes — emission stays sound); `@isFormatLiteral` consults the binding's literal flag. Handles literal formats AND heterogeneous runtime args (per-element types are in the key). Bigger change but keeps the instance boundary. **(B) call-site inlining** — splice comptime-bodied calls into the caller (sound; biggest architectural change; no such machinery exists — evalCall inline only runs inside comptime). **(C) runtime slice packs (agent A's option B)** — type packs as slices + materialize temp arrays at call sites: legalizes runtime for-in but CANNOT handle heterogeneous elements (`_fprintOne<comptime T>` dispatch can't exist at runtime) → only zero/homogeneous tails; subsumed by A.

**Suggested next moves:** decide A/B/C with user → implement → re-run iotest (`println("hello")` must build + print `hello`) → strip debug prints → rebuild → re-run `/tmp/opencode/run_tests.sh` (recreate if wiped; PASS=34 baseline) + probe suite + `/tmp/opencode/proj` → update this file.

## Session tick summary 2026-10-09 (std sweep: char-lit decode, generic/method arg checking, suite PASS=34/34)
Commits: 62ce09a (parser), 403ed89 (sema), c09dc80 (mono+codegen), 5ce5c01 (windows lib). Verify = BUILD=0 (bootstrap/coralc.py), `run_tests.sh` PASS=34 FAIL=0 (incl. option gold test), nested_import NI_RC=0/run0, gp4/gp5 run0, io2+p_fopen+p_opt2+hashshape+v2/v3/x7 probes RC=0 (v3/x7 deliberately null-deref `zero(0,…)` → run-time segfault = expected), p_trim/p_trim2/p_trim3 0/11/11.
- **CharLit decoded (root cause of every char literal == `'`)**: parser `TokenKind::CharLit` took `tok.data.ptr[0]` = the OPENING QUOTE (token span includes both quotes) → value 39 for ALL literals → `str.trim`/`char_util` comparisons never matched (io2 exit 3). Now decodes content: `EscapeResult::decodeEscapeSequence` for `\…` (reused lexer helper; must call as `EscapeResult::` or codegen emits the unmangled name), `decodeUtf8` otherwise. Effect: `'
'`=10, `'a'`=97.
- **checkCall C++/clang rule (user directive)**: explicit typeargs (`zero<E<i32,i32>>(…)`, `Vec<i32>::new`) bind once — `sflag` hoisted above arg loop, each param `substituteFieldTy(param, calleeTy)` then `assignCompatible`; retTy reuses sflag. Refactored core into `checkCallResolved(callId, Symbol*, …)` so qualified calls can pre-resolve.
- **Qualified call resolution**: new `modulePathPrefix(segs, segCount)` (all-but-last joined `::`); module-root branch does `scopes.lookupAll(fname, cands, 16)` preferring `importPathInFile(modPath, cand->fileId)`, fallback `lookupAt` — `fios::fileOpen` no longer binds fs.crl's own `fileOpen`.
- **MethodCall generic binding**: `Ty recvTy = exprType(receiver)`; args checked via `assignCompatible(arg, argTy, substituteFieldTy(param, recvTy))` (was strict `compatible` — rejected IntLit→f64), return `substituteFieldTy(returnType, recvTy)` — `out.push(K)`/hashmap chains green.
- **assignCompatible Neg literal arm**: `-1` parses `Neg{IntLit}` — unwrap sign with `negated` flag; unsigned targets reject negated (u8 `= -1` fails), signed range limits off-by-one for magnitude (`i32 ≤ 2147483648`), floats get literal leniency (`f64 d = -1`, `unwrapOr(-1)` in option gold test).
- **Char-family pointer compat (typecheck.crl)**: `unqualTy` (strip Const/Comptime + resolve 0-generic Named via lookupType; 8-iter guard), `charFamily` (inline tag compares — **no local `TypeKind` var, breaks bootstrap C codegen**), `charSignMix`; wired into Pointer/Pointer + Array/Pointer (`const cchar*` ↔ `i8*`/`u8*`); plus Str→Pointer(charFamily) decay (`write(1, "…", n)`).
- **Qualified type paths keep final segment** (parser/type.crl ColonColon loop): `fios::FileHandle` binds `FileHandle`.
- **mono `substituteType` FnPtr case** (copyTypes params + recurse ret) + **codegen FnPtr typedef naming** from substituted spelling (`FnP_<ret>_<args…>`, cgMangleTy sanitize) — was shared `FnP_<index>` typedef for all instances (C arg-type errors on Vec<i32> fns).
- **std::option/result reexports** in BOTH platform `lib/lib.crl` (`pub mod option = import data::option;` — base `lib/std/data/` doesn't exist); windows `data/option.crl` `unwrap()` else-branch `return false` → `@assert(false)` (linux was already fixed).
- **Remaining next (todo)**: 3) multi-declarator struct fields `i32 goo, moo;` (chain.crl PAR-0001 + HANDOFF example typo `}` → `};`); 4) `.goo` on method-call result / `.add().sub()` chaining; 6) ~~println `...` spread (4× PAR-0002 in ios.crl) + comptime print pipeline~~ **parse OK + evaluator/codegen pipeline landed 2026-10-14; blocked only on variadic-pack `for`-in (CG-0002) — see top tick**; 7) bulk new error codes with distinct IDs across parser/sema/loader/codegen + `--explain`; 8) windows std sweep / compiler-ASan suite run.

## Session tick summary 2026-10-09 (stage-2 mangling Phase A+B+D landed; suite PASS=34/34)
Commits: a0235b9 (Phase A), bdc629f (Phase B+D + lib fixes). Verify = `timeout 300 python3 bootstrap/coralc.py compiler/coral-frontend/coralc.crl -o /tmp/opencode/coralc` BUILD=0, nested_import compiles+runs, `/tmp/opencode/run_tests.sh` PASS=34 FAIL=0, gp4 generic mimalloc probe runs clean under ASan (`gcc -std=gnu11 -fsanitize=address -g -O0`; the frontend hardcodes `gcc -std=gnu11 ` at compile.crl:210 — no CC env; it keeps the generated `.c` on success too, so manual ASan rebuilds just re-gcc the file).
- **Phase A (mangle_asm.md)**: scope-chain mangling `crl__<scope>__<seg…>[__<alias>]__<name>` for decls/types/enums committed a0235b9.
- **Phase B (mono)**: collect/instantiate/sema-expr generic-preamble + diagnostics probes removed after green (bdc629f).
- **Phase D (codegen — "remove the temp val and goto")**: statements emit native C — if/while/for/forin/break/continue; expressions return inline ebuf text (`stTail`); TupleExpr double-emit fixed. **Documented exceptions still on temp machinery**: IfExpr (temp+goto), SwitchExpr (result temp + if/else-if chain lowering via cgEmitSwitchChain — no fallthrough, default last, plain C break), AddressOf/MethodCall-receiver materialization via new `cgAddrOfValue` (extern-decl-before-cgExpr pattern for mutual recursion). `cgEmitLabel`/`cgEmitGoto`/`cgNewTemp`/temp decl loop kept for those. assertOut: 1-arg → `assert(cond);`, 2-arg Str → `assert(cond && _coral_strtruth(msg));`, 2-arg non-str → `assert(cond && msg);`; struct eq/ne → memcmp+sizeof; str eq/ne → preamble `_coral_streq`.
- **Method dispatch (all 8 nested_import gcc error classes fixed → NI_RC=0)**: `cgOwnerSpelling` normalizes owner spelling (`str` → `_coral_str` — extend's cgDeclOwner is the C name, call sites use the coral name); call-arm branch (a) tries `cgFindMethodDeclOwner(rootT)` + composes def-side suffix (`owner_method`) before cgResolveCall; StaticCall arm composes the same; MethodCall synthetic `&` receiver now goes through `cgAddrOfValue` (fixes 7 lvalue `&`-operand errors); all stmt handlers evaluate cgExpr before writing prefixes, so temp statements from cgExpr land safely (Asm operands are the one racy exception, ignored).
- **All debug probes stripped** from codegen/expr/instantiate/collect (script: `/tmp/opencode/strip_probes.py`); zero `write(2` / `extern("C") i64 write` left in compiler/. Clean rebuild from stripped tree is green.
- **Lib fixes (source bugs, not compiler)**: `string.crl:91/:145` ptr subtraction cast `(const u8*)self.ptr` (invalid C `const uint8_t* - char*`); `mimalloc.crl` `_miPageAlloc` no longer aliases `MiPage` over the `MiSegment` header — `seg->base == seg` by design, so `page->sizeClass = sc` used to clobber `seg->base` before `page->base = seg->base + metaSize` read it → wild block pointers (runtime SIGSEGV in `_miFreeBlockEncode`, caught by gdb + ASan on `/tmp/opencode/gp4.crl`); page now lives at `seg->base + sizeof(MiSegment)`, metaSize aligns past segment+page headers with `~255u` (was `~256u` — off-by-one that undersized the header region).
- **Phase C**: landed 49067f7 (TypeEntry.loc + file-aware lookupType + owner/suffix mangle split). **Next**: windows std sweep, compiler-ASan suite run, cchar/const-shape sweep items below.

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
- **Build system (NEW TODO 2026-10-03, user directive; RE-PRIORITIZED 2026-10-15: build system FIRST)** — order:
  0. User directive 2026-10-15: fix the build system **before** finishing the remaining compiler diagnostics work (it may also need compiler features the build depends on — the u32→usize widening below is likely one).
  1. Finish the compiler (parse/sema diagnostics push) enough that the build system can drive it; the rest lands once the compiler is in a shippable state.
  2. `coral init`: must check whether the project has a `.gitignore`; if missing/absent entry, create it and add a `.coral/` entry (project-local state folder).
  3. Generated C must NEVER be littered into the source tree: emit to `~/.coral/artifacts` (or `/tmp` for scratch builds). Project build state lives in the project's `.coral/` folder. Rule enforced by past cleanups: 47 stray generated `.c` sweep artifacts were deleted from `lib/`; keep the repo free of `.c` output.
  4. Distribution/install: once both pieces are done, copy the `lib/` folder + the finished compiler + the complete build system into `~/.coral/` as the installed toolchain.
- **Cross-module `extend` + declaration-only methods — forward test (reviewed 2026-10-15, user asked to note what the compiler needs)**: fixture at `compiler/coral-test/test-extend-module/` (`main.crl` + `calc/{calc,add,sub,mul,div,lib}.crl`). Purpose per in-file comment: "this is a test that will make future issues fixed before they come — how would an extended item have the extended methods be brought into scope?". Shape: `calc/calc.crl` defines `pub struct calculator` whose methods are **prototypes without bodies** (`f64 add(self);` …); each sibling module (`add.crl`/`sub.crl`/`mul.crl`/`div.crl`) does `import calc { calculator }; pub extend calculator { f64 add() { return self.a + self.b; } }` (implicit-self extension methods, no trait); `calc/lib.crl` re-exports the modules (`pub mod add = import add;` …); `main.crl` does `import calc { calc::calculator, add, sub, mul, div // imported to bring the extend blocks into scope }` then `calculator::from(...)` and `c.run()` where `run()` dispatches `self.add()` etc. Compiler requirements this fixture pins down:
  1. **Multi-file/module builds** — the fixture can only build through the build system (`coralc build` + manifest/module-map); single-file `coralc file.crl` cannot express it. This is the immediate reason it ties into the build-system work.
  2. **Cross-module `extend` registration**: an `extend` block in module B attaching non-trait methods to a type defined in module A (B imports the type; method resolution at call sites must find B's extend).
  3. **Prototype-then-extend linking**: struct-body method declarations without bodies must resolve to the extend-provided definition at call/typecheck/mono time (and a diagnostic when nothing extends them).
  4. **Extend scoping rule (the test's actual question)**: importing a module must bring that module's `extend` blocks into scope — resolution consults extends only from the type's module + imported modules (define-and-answer the visibility rule; currently `extend` collection is same-unit only).
  5. **Name coexistence**: main imports module names `add/sub/mul/div` while the same names are methods on `calculator` — `c.add()` (method) vs `calc::add` (module path) must not collide.
  6. **Implicit-self extension methods**: `f64 add() { ... self ... }` with no explicit `self` param, callable as `c.add()` and via `self.add()` inside the type's own methods.
  - Language errors to correct when this fixture is promoted to an active test (in-file comment says it was written by a model not familiar with coral — "correct any language errors here, but understand the purpose"): `calculator::from(1024, 2048 "div")` missing a comma after 2048; `if (operation.equals("add") return self.add();` — malformed parens and `str` has no `.equals` (use `==`); `run()` falls off the end without a return on the no-match path (definite-return will reject); `printf("%f", c.run())` may need `C"%f"` under the string-literal convention todo.
  - Current status: NOT buildable — multi-file build + cross-module extend both missing. Do not "fix" the fixture to compile under today's limits; it is the spec for these features.
- **Implicit integer widening `u32`→`usize` missing (io_basic TC-0002 real root cause, corrected 2026-10-15)**: repro `/tmp/opencode/ct/ptr2.crl` — `u32 lastSlash` passed to `str::fromParts(const u8* ptr, usize len)` (lib/core/str.crl:22) fails `assignCompatible` with "static arg type mismatch" (expr.crl:1002). Literals/const-int-exprs adopt the target (expr.crl:385-394) and `usize`↔`u64` are mutually assignable (typecheck.crl:909-912), but a plain u32 **variable** → `usize` param is rejected: `compatible()` (typecheck.crl:845-927) has NO integer-widening rule (the "same signedness widen or u->s-wider" rule noted in the 2026-10-09 tick is not in the current code). This is the io_basic blocker at `lib/std/x86_64/linux/io/fs.crl:254` (`createDirRecursive(str::fromParts(path.ptr, lastSlash), mode)`) — the earlier `const u8*`/`Pointer{Const U8}` diagnosis was WRONG. Decide the rule (re-add same-signedness widening incl. Usize≡U64/Isize≡I64 equivalence classes, or require `(usize)` casts in lib) — likely also needed by build-system code. Side note (separate latent issue, lower priority): `strPtrType()` (typecheck.crl:114-129) returns whatever `Pointer{U8}` it finds first (mutable) while its comment says `str.ptr` is `const u8*` — inconsistent by instantiation order; only fix if a new probe shows it breaking const-correctness.
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
- **`comptime {}` blocks** — **PARTLY WORKING as of 2026-10-14**: the mono evaluator (`compiler/coral-mono/comptime.crl`, driver `instantiate.crl`) evaluates comptime bodies per instance (type switch unrolling, `_fprintOne`-style dispatch), codegen now emits the rewritten instance body (`cgInstanceBody`, codegen.crl ~:4282). Standalone proof: `/tmp/opencode/ct/ct1.crl` → prints `HiO`, zero `switch` in generated C. Remaining: value params not bound (only types) → `@isFormatLiteral(fmt)` false → ios `_printEmit` else-branch leaves `for (var arg : args)` runtime → CG-0002. See top tick for fix options A/B/C.
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

    static this new(i32 a, i32 b) { return this { .goo = a, .moo = b }; }
    i32 add() { return self.goo + self.moo; }
    i32 sub() { return self.goo - self.moo; }
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