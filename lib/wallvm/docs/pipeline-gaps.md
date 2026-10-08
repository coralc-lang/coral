# Wallvm Pipeline Gap Analysis

Status: analysis document. Compares the wallvm pass pipeline and backends as
they exist today against a production optimizer/codegen pipeline (clang
-O1/-O2, new pass manager, plus the LLVM machine-code layer). Every claim was
verified against the tree; suspected bugs are marked **[verify]** where the
code is ambiguous or the convention split is systemic.

Sources read: `wallvm.crl` (driver), all 41 passes in `passes/`,
`regalloc/{lsra,graph}.crl`, `rules/asm_rules.crl`, `target/{x86,x86_64,wasm}`,
`target/x86_64/linux/abi_lower.crl` (+ windows/x86 variants), `noret/`,
`base/{irtypes,irOps,irBuilder,domtree,irMetadata}.crl`, `ffi/`, `gc/`,
`docs/assembler-plan.md`, `IR.md`.

---

## 1. The actual pipeline, stage by stage

### 1.1 Driver shape (`wallvm.crl`)

`irCompile` (wallvm.crl:406) loops over module functions and runs, per
function:

```
irOptimize(func, ctx, optLevel)      // one of pipelineLevel0..3, iterated
irStructureLane(func, ctx)           // borrowcheck, [unroll], validate
regalloc (lsra, or graph for O3 leaf fns ≤ 8 blocks; skipped for wasm)
```

then `irCodegen` on the whole module. There is **no module-level pass stage**
(call graph, globals, COMDAT); everything is a function pass. `PassPipeline`
is a flat array run by `runOnFuncIterate` until no pass reports change, with
maxIters = 1 / 2 / 5 / 8 for L0 / L1 / L2 / L3 (wallvm.crl:285).

### 1.2 L0 (wallvm.crl:158)

validate → simplify → constfold → sccp → dce → validate.

No mem2reg, no phi lowering. Frontend-emitted phis (legal per IR.md §1)
reach regalloc and codegen directly; the x86_64 emitter has **no Phi case**
(falls into the `else` comment arm, x86_64_base.crl:2074).

### 1.3 L1 (wallvm.crl:170)

validate → **abi_lower** → comm_canon → simplify → constfold → involution →
sccp → range → range_br_elim → branchprop → branch_inv_flat → cse →
cast_elim → dse → jump_thread → idiom → peephole → dce → validate.

Notable: no mem2reg/SROA at all (L1 optimizes raw alloca traffic), no LICM,
no GVN, no lower_phis (same phi-into-codegen problem as L0).

### 1.4 L2 (wallvm.crl:195)

validate → **abi_lower** → mem2reg → sroa → comm_canon → simplify →
constfold → involution → range → range_br_elim → branchprop → sccp → adce →
alias → mssa → licm → gvn → loopcse → jump_thread → **inline** → cast_elim →
idiom → peephole → dse → **lowrphis** → validate. Iterated ≤ 5 times.

### 1.5 L3 (wallvm.crl:227)

L2 plus: stack_layout, lex_canon, branch_inv_flat, branch_fact, divmod,
loop_interchange, loop_distribute, tail_dup, tco (accumulator), simd_vec,
idempotent, macro_fusion, machine_opt (MemorySSA store/load forwarding —
an IR pass despite the name), sel2br. Iterated ≤ 8 times.

### 1.6 Structure lane (wallvm.crl:295)

borrowcheck (diagnostic) → unroll (only with `--funroll`) → validate. Runs
**after** the optimization pipeline and **again** inside `irCompileAsm`
(wallvm.crl:477), so unrolling is applied twice when both entry points are
used.

### 1.7 Regalloc contract (wallvm.crl:344-398)

- `useCalleeSave = false` for SystemV/Win64 (caller-save only; call-spanning
  values are force-spilled), `true` for 32-bit x86.
- `backendHandlesSpills = true` for all x86 targets: lsra **does not** insert
  spill loads/stores (lsra.crl:913-915); it writes `SPILL_BIT|slot` or
  `FLOAT_BIT|reg` into `valData` (lsra.crl:1050-1074) and the backend is
  expected to decode it.
- wasm: no regalloc (stack machine).

### 1.8 Codegen dispatch (wallvm.crl:507-525)

SystemV/SyscallX86_64/SyscallMacOS → x86_64 linux; Win64 → windows;
Cdecl/Stdcall/SyscallX86 → x86; Wasm32 → wasm; **everything else → x86_64
bare** — including Wasm64, Aapcs64, Riscv64 (wrong target silently).

---

## 2. Reference pipeline (clang -O1/-O2, condensed)

```
module:  cgscc(inline bottom-up ↔ function simplification), globalopt,
         ipsccp, deadargelim, globaldce, function-attr inference
function: sroa → mem2reg(promote) → early-cse → jump-threading →
         correlated-prop → simplifycfg → instcombine ⇄ (repeat) →
         sccp/bdce/adce → reassociate → constraint-elim →
         loop-simplify + LCSSA → licm → loop-rotate → licm → unswitch →
         indvars(SCEV) → loop-idiom → loop-deletion → unroll →
         loop-distribute(O3) → loop-vectorize → slp → memcpyopt →
         sccp/bdce/dse → tailcallelim → simplifycfg
codegen:  isel (SelectionDAG/GISel) → machine-{cse,licm,copyprop} →
         pre-RA scheduling → regalloc (greedy: live-range splitting,
         rematerialization, coalescing, shrink-wrapping in PEI) →
         stack-slot-coloring (spill-slot packing) → post-RA scheduling →
         machine block placement (branch chaining/fall-through) →
         machine peephole → branch relaxation → emit (CFI/.eh_frame,
         DWARF, section flags, relocations)
```

Section 3 maps each divergence. Categories: **[C]** correctness/ABI,
**[Q]** code quality, **[N]** nice-to-have.

---

## 3. Gap inventory

### 3.1 Driver / pipeline structure

**G1 [C] — `irPassValidate`'s return value defeats fixpoint iteration.**
`validateFunc` returns `nerrors == 0` (validate.crl:247), i.e. **true when
the IR is valid**. `runOnFuncIterate` treats true as "changed, keep
iterating" (wallvm.crl:140-155). Validate sits at the head and tail of every
pipeline, so every function at L1-L3 always burns all 2/5/8 iterations.
Compile-time blowup and a masking effect over real non-convergence (see G2).
Belongs to: driver (`wallvm.crl`) + `passes/validate.crl` (needs a separate
"ran" vs "changed" contract, or validate must return false).

**G2 [C] — mem2reg ↔ lower_phis ping-pong.** L2/L3 end with `irLowerPhis`,
which turns each phi into a fresh alloca + per-pred stores + a load
(lower_phis.crl). On the next global iteration mem2reg re-promotes every
non-loop phi-alloca (they pass its promotability screen) and lower_phis
re-lowers them — the pipeline cannot converge whenever a non-loop phi
exists. Belongs to: driver ordering + `passes/lower_phis.crl` design.

**G3 [C] — `irABILower` is registered as a function pass but its contract
requires the IrModule as userdata** (abi_lower.crl:884-890: "`userdata` as
the owning `IrModule*`"). The driver passes `IrContext*` to every pass
(wallvm.crl:286). `IrModule` and `IrContext` share no layout prefix
(irtypes.crl:516 vs 626), so unless the function was pre-marked
`abi.lower` by an external module-level run, the pass walks garbage.
**[verify]** against how `buildModule` pre-marks functions; as wired inside
`irOptimize` this is type confusion. Belongs to: driver contract; the pass
needs a module-pass slot, not a `PassFn` slot.

**G4 [C] — SysV `irABILower` runs for every calling convention.**
wallvm.crl:52 imports only `x86_64::linux::abi_lower`; the Win64
(`target/x86_64/windows/abi_lower.crl`) and i386
(`target/x86/linux/abi_lower.crl`) variants exist but are referenced
nowhere. Win64/x86 compilations get SysV eightbyte classification or, if
never marked, nothing. Belongs to: driver — abi_lower must be selected per
`cc` like `regallocConfigFor` already does for regalloc.

**G5 [Q] — abi_lower placement is pipeline-head, not codegen-adjacent.**
LLVM lowers the ABI at isel. Here it runs first, before mem2reg and before
inline; the scratch-alloca byte round-trips it emits (abi_lower.crl:439-451)
must be seen through by every downstream pass, and inlining after ABI
lowering mixes lowered and unlowered conventions. It happens to work because
both sides of each call are rewritten (abi_lower.crl:840-881) — but only
for direct calls; indirect calls are explicitly "an IR gap"
(abi_lower.crl:20-21). Belongs to: driver ordering; document the invariant
or move to codegen.

**G6 [Q] — structure lane runs after `irOptimize`, but borrowcheck's own
comment demands it run before any pass that moves loads/stores**
(wallvm.crl:299-304 vs call order at 429-433). After LICM/GVN/DSE/machine_opt
the reported load/store relationships no longer reflect the source. Also,
`irCompileAsm` re-runs the lane (wallvm.crl:477) → double borrowcheck and
**double unroll**. Belongs to: driver.

**G7 [Q] — no CGSCC/module layer.** Inlining is a function pass with a local
cost model (inline.crl:546-642); callers are optimized in module order,
possibly before their callees are optimized; there is no globalopt,
constant merging, dead global/function elimination, or attribute inference
(`noreturn`/`readonly` metadata parsed but unused). `ipa_cp` exists but is
wired into **no** pipeline. Belongs to: new module-pass stage in the driver.

**G8 [Q] — `cse` is L1-only; L2/L3 use only dom-scoped `gvn`.** After the
late inline + sel2br + lower_phis churn there is no cheap local CSE/DCE
cleanup in the same iteration. Belongs to: pipeline tables.

**G9 [N] — no pass-timing, opt-bisect, or `-print-after` debugging hooks**;
validation errors are silently discarded (`lastError` never leaves
`irPassValidate`). Belongs to: driver + validate.

### 3.2 SSA construction and CFG

**G10 [C] — mem2reg refuses to promote any alloca touched inside a loop**
(mem2reg.crl:449-519), justified by a comment claiming lsra mis-assigns
registers across back-edges. This is the tail wagging the dog: loop-carried
scalars stay in memory, so LICM/GVN/range/unroll/simd_vec all see loads and
stores instead of values, and unroll's own comment expects "the canonical
loop form produced by mem2reg" (unroll.crl:3-6) — a form mem2reg never
produces. The correct fix is in lsra/phi lowering (see G13, G24), not in
mem2reg. Belongs to: `passes/mem2reg.crl` + `regalloc/lsra.crl`.

**G11 [Q] — mem2reg runs before `sroa`, and "sroa" is not SROA.**
sroa.crl is single-store forwarding that **bails on any GEP/atomic use**
(sroa.crl:50-56); there is no aggregate splitting, so struct/array allocas
are never scalarized and can never be promoted. Clang order is sroa →
mem2reg. Belongs to: pipeline order + a real SROA in `passes/sroa.crl`.
**[verify]** sroa.crl:73-80 rewrites operands by direct assignment without
`addUser`/`removeUser` — use lists go stale, violating IR.md §5 invariant 4
and poisoning every `nusers`-driven pass downstream (DCE included).

**G12 [C] — no critical-edge splitting pass anywhere.** lower_phis dodges
the classic miscompile by round-tripping through a private alloca per phi
(correct but pure memory traffic; verified the per-pred-store scheme is
sound on critical edges). But jump_thread/tail_dup/sel2br create critical
edges and nothing materializes them; any future move-based phi lowering or
edge placement needs real splitting. Belongs to: new `passes/split_edges.crl`
(or fold into lower_phis).

**G13 [Q] — phi lowering is alloca-based; there is no parallel-copy
lowering.** Every phi becomes store-per-edge + load-at-top (lower_phis.crl),
inserted after the last optimization pass, so the copies are never
coalesced (lsra's `tryCoalesce` is a no-op, lsra.crl:769-827) and never
seen by DSE. LLVM lowers phis to parallel copies that regalloc coalesces.
Belongs to: `passes/lower_phis.crl` + `regalloc/lsra.crl`.

**G14 [Q] — no simplifycfg.** No empty/merged block folding, no common-tail
sinking/hoisting, no unconditional-branch-to-empty-block elimination.
jump_thread (jump_thread.crl) and tail_dup (tail_dup.crl) cover only
passthrough chains and **[verify]** both empty `target->ninsts = 0` without
checking the target's other predecessors (jump_thread.crl:64,
tail_dup.crl:57) — orphaned preds then reach a block with no terminator,
and DCE must clean up. DCE's unreachable-block removal (dce.crl:50-132)
leaves stale entries in successors' `preds` and nulls phi value operands
(dce.crl:113-124), which later passes must tolerate. Belongs to: new
`passes/simplifycfg.crl`; harden the two threaders.

**G15 [Q] — no reassociation pass.** lex_canon sorts operands within a
commutative chain (lex_canon.crl) but there is no global reassociation for
CSE/loop strength reduction; GVN (gvn.crl) is dominator-scoped redundancy
elimination with no PRE. Belongs to: new `passes/reassociate.crl`, PRE in
`passes/gvn.crl`.

**G16 [N] — no memcpy/memset/memmove idiom formation** (idiom.crl covers
rotate/bswap/minmax/abs/fma only); no SLP vectorizer (simd_vec is
loop-only); no switch→jump-table lowering (IR.md §9 defers it; there is no
switch opcode at all).

### 3.3 Loop optimization

**G17 [Q] — no loop canonicalization: no loop-simplify form, no LCSSA, no
loop rotation.** loop_detect reports one "loop" per (header, latch) pair
(loop_detect.crl:28-101); LICM builds its own preheader (licm.crl:16-185);
unroll/interchange/distribute/simd_vec each re-derive the induction pattern
by hand. Without rotation, loops keep a header test + backedge jump instead
of a fall-through backedge, which also defeats branch chaining (G31) and
macro-fusion at the loop bottom. Belongs to: new `passes/loop_canon.crl`
(rotation + dedicated exits + LCSSA).

**G18 [C] — LICM speculation safety.** `isLoopInvariant` admits loads
(licm.crl:194-199) and hoisting only checks alias-vs-stores
(licm.crl:379-399); there is no dereferenceability proof and no
"instruction dominates all exits" check. A load conditional in the loop is
executed unconditionally in the preheader — it can fault. LLVM only hoists
such loads when the address is known dereferenceable. Belongs to:
`passes/licm.crl`.

**G19 [Q] — no SCEV/indvars.** range.crl is a value-range analysis with
branch elimination, not an induction-variable analysis; unroll computes
trip counts ad hoc; simd_vec matches counted loops by hand; loop strength
reduction does not exist. Belongs to: new `passes/indvars.crl`.

**G20 [Q] — unroll placement.** It lives in the structure lane, after the
entire optimizer (wallvm.crl:307), so the unrolled body is never
re-simplified in the same compile (only validate follows) — and it can run
twice via `irCompileAsm` (G6). Clang unrolls inside the loop pipeline with
cleanup after. Belongs to: driver.

### 3.4 Register allocation (`regalloc/`)

**G21 [C] — the spill contract is broken end-to-end.** For every x86 target
the driver sets `backendHandlesSpills = true` (wallvm.crl:344-360,
362-398), so lsra skips IR-level spill rewriting (lsra.crl:911-916) and
emits `SPILL_BIT|slot` in `valData` (lsra.crl:1061). The x86_64 backend's
only decode is `getRegForValue`, which returns **"rax"** for any spilled
value (x86_64_base.crl:1694-1709); `valueIsSpill` is defined but never
called (1717-1721); no spill-slot frame exists (allocas are `subq $8`,
see G30). Net effect: **any function whose live values exceed the
allocatable set silently aliases every spilled value to rax.** This is the
single largest correctness hole in the tree. Belongs to:
`target/x86_64/x86_64_base.crl` (spill slot frame + operand
materialization) or flip `backendHandlesSpills` to false until it exists.

**G22 [C] — no fixed-register / clobber modeling between isel and
regalloc.** The emitter clobbers concrete registers that lsra happily
allocates to unrelated live values: `emitDiv`/`emitRem` destroy rax+rdx
(x86_64_base.crl:2098-2150), `emitShift` destroys rcx (2152-2171),
`emitICmp`/`emitFCmp` write %al/%cl (2244-2313), `VecDiv` walks lanes
through r10/r11/rax/rdx (1898-1926), `emitFcvt` UiToFp uses r10
(2655-2671). Only rsp/rbp are reserved — and `numReservedIntRegs = 3` is
set over a **2-element** array (wallvm.crl:381-385 vs
x86_64_base.crl:7-9; same off-by-one for floats, 384/11-13) → OOB read in
`isReservedName`. LLVM models these as tied operands/fixed-reg
constraints/clobbers in the instruction descriptors. Belongs to:
`regalloc/lsra.crl` (constraint modeling) + the reserved-register tables.

**G23 [C] — Win64 register tables disagree between lsra and the emitter.**
lsra names registers from `abi.callerSaveRegs` — Win64: rax, rcx, rdx, r8,
r9, r10, r11 (asm_rules.crl:137). The emitter decodes the same indices via
`X86_64_INT_REGS` = rax, rcx, rdx, **rsi, rdi**, r8, r9, ...
(x86_64_base.crl:15-17). Indices ≥ 3 name different registers on Win64 →
systematically wrong code. Related: lsra's `isWin` is hardcoded `false`
(lsra.crl:409), so the Win64 param mapping arrays are dead; and the
param-interval pre-assignment it guards is itself overwritten by the scan
(dead code), while `uses`/`defs`/`spillWeight` of param intervals are left
**uninitialized** (lsra.crl:417-441) — including possible NaN weights
feeding `sortIntervals`. Belongs to: `regalloc/lsra.crl` +
`target/x86_64/x86_64_base.crl` (single source of truth for the register
order).

**G24 [Q] — allocator feature set vs "gcc/clang quality":** no
rematerialization (constants get spilled like any value), no live-range
splitting, no real coalescing (`tryCoalesce` only lengthens intervals —
the opposite of coalescing), **one spill slot per vreg, never packed**
(lsra.crl:742,760), caller-save-only policy with `useCalleeSave=false`
force-spills every value that spans a call (lsra.crl:663-665), float
allocation is limited to the 8 ABI **argument** registers (lsra.crl:144,
152-156 — xmm8-xmm15 never used). Also `irGraphRegAlloc` runs lsra first
and then recolors intervals whose results are **never written back to
valData** — a pure no-op refinement that ignores pre-colored params and
would corrupt them if applied (graph.crl:317-355). No shrink-wrapping in
RA (the emitter's deferred-push approximation is fragile, G33). Belongs to:
`regalloc/lsra.crl` (remat, splitting, packing, callee-save support);
retire or repair `regalloc/graph.crl`.

**G25 [C] — lsra depends on block layout it doesn't control.** Intervals
are computed over the raw `func->blocks` order with ends only extended
forward (lsra.crl:466-532). Any layout where a def sits after a dominated
use (nothing enforces RPO) breaks the interval. There is no block-ordering
pass; see G31. Belongs to: `regalloc/lsra.crl` (compute over RPO) + driver
(layout pass).

**G26 [Q] — quadratic scans everywhere:** interval lookup per operand is
O(n²) (lsra.crl:500-531), GVN/CSE tables are linear scans
(gvn.crl:153-159), mem2reg's DF walk is cubic. Belongs to: hashtable-based
value maps in the respective passes.

### 3.5 Frame, ABI, calls

**G27 [C] — `store` operand order appears inverted in both native
backends.** IR convention (irBuilder.crl:190-195, irPrinter.crl:512-521,
irParser.crl:1500-1513, and every pass) is `store v, ptr` → ops[0]=value,
ops[1]=address. `emitStoreWidth`/`emitStore`/`iselTryFoldLoadOpStore`/
`iselTryFoldGepStore` all treat ops[0] as the address and ops[1] as the
value (x86_64_base.crl:1253-1289, 1378-1438, 1507-1520, 2200-2209;
x86_base.crl:619-628). The width is taken from ops[1] too, so it is always
the pointer width (64). **[verify]** — the split is systemic (both
backends, all paths), so this may be a legacy convention deliberately kept
in the emitter; but the prologue param-seeding code in the *same file*
uses the builder convention (x86_64_base.crl:624-727), so at least one
side is wrong. Belongs to: `target/x86_64/x86_64_base.crl`,
`target/x86/x86_base.crl`.

**G28 [C] — unhandled opcodes are emitted as comments.** `emitInst`'s
`else` arm emits `# unhandled opcode` (x86_64_base.crl:2074): Phi,
Noret, Unreachable, all four atomics, Fence, InlineAsm, ExtractValue,
InsertValue, ExtractElement, InsertElement, GcRoot, GcWriteBarrier,
GcSafepoint, LandingPad. Silent code omission; an `unreachable` terminator
falls through into the next block's bytes. `noret/` and
`noretTemplate` (asm_rules.crl:881-961) exist but are not called from the
emitter. The wasm backend's loud `failOp` (wasm.crl:1714) is the correct
behavior. Belongs to: `target/x86_64/x86_64_base.crl` (+ x86) — must trap
or emit, never comment; wire `noret`.

**G29 [C] — no module data emission on native targets.** x86_64 emits only
`.section .text` (x86_64_base.crl:403-406); x86 emits empty `.data` then
`.text` (x86/linux/linux.crl:7-8); no backend except wasm emits globals,
string constants, `.rodata`, `.bss`, `.align`, or `.size`. The emitter's
`dataSection` buffer is **never flushed into the output**
(x86_64_base.crl:78, 146), and `emitFabs` writes a fixed label
`.Lfabs_mask` into it per use (2601-2607) — duplicate labels if `fabs`
appears twice, absolute (non-RIP-relative) addressing, and the definition
never reaches the assembler anyway. Belongs to: backends — a module-level
data/constant-pool emitter (per-section, with alignment and relocations).

**G30 [C] — alloca lowering has no frame model.** `emitAlloca` emits
`subq $8, %rsp` **at the alloca's execution point**, always 8 bytes
(x86_64_base.crl:2211-2217): allocas inside loops grow the stack every
iteration; aggregates/arrays get 8 bytes regardless of type; nothing is
aligned; there is no frame size computation or fixed rbp/rsp-relative
slot assignment. Production: static allocas are sized and placed in the
prologue frame (and stack_layout.crl is only a reordering heuristic —
which also **[verify]** moves non-entry allocas into the entry block while
their original blocks still list them, double-parenting instructions and
overflowing `newInsts` when nvars > entry->ninsts, stack_layout.crl:153-194).
Belongs to: `target/x86_64/x86_64_base.crl` (frame layout) with alloca
sizing from the IR type.

**G31 [Q] — no block placement / branch chaining.** Blocks are emitted in
IR order; every `cond_br` becomes `test+jne+jmp` with both edges as jumps
(x86_64_base.crl:2327-2345); no fall-through placement, no loop-aware
layout, no branch relaxation. Interacts with G17 (rotation) and with
lsra's layout sensitivity (G25). Belongs to: new `passes/block_layout.crl`
(or a backend-side placement) consumed by the emitters.

**G32 [C] — call-site ABI details missing (SysV).** No 16-byte stack
alignment tracking around `call` (allocas and arg pushes shift rsp by 8 at
a time; `movaps` in the callee's vararg prologue can fault); **`%al` is
never set to the vector-register count for vararg calls** while vararg
callee prologues branch on it (x86_64_base.crl:490 vs 2881-2925);
stack-arg cleanup counts each overflow arg as 8 bytes but struct args are
pushed **twice** (2789-2837 vs 2915-2923) → rsp imbalance for >6-arg
calls with aggregates; parameters beyond the 6th (SysV) / 4th (Win64) are
never seeded from the caller's stack frame in the prologue (607-727);
spilled params get no seeding at all (647). Belongs to:
`target/x86_64/x86_64_base.crl`.

**G33 [Q] — prologue/epilogue strategy.** `emitDeferredCalleeSaves` pushes
callee saves at the first block that uses them (x86_64_base.crl:359-401) —
if that block is in a loop the pushes repeat with no matching pops (stack
blowup; reachable on 32-bit targets where `useCalleeSave=true`). Every
`ret` duplicates the full epilogue and each function gets a trailing
epilogue appended after its last block (linux.crl:50) — no epilogue
merging. This is where shrink-wrapping belongs but isn't. Belongs to:
`target/x86_64/x86_64_base.crl` (+ PEI-style pass in `regalloc/`).

**G34 [Q] — tail calls.** Two partial mechanisms: the accumulator-pattern
`tco` pass (tco.crl) and an emitter peephole turning adjacent `call;ret`
into `jmp target` guarded by frame state (x86_64_base.crl:786-852,
2927-2938). There is no general sibling-call optimization (tail calls with
moved argument registers, stack-arg cases, or through abi_lowered calls),
and no guaranteed-TCO marker. Belongs to: `passes/tco.crl` + backends.

### 3.6 Machine level

**G35 [Q] — no instruction scheduling, pre- or post-RA.** AsmRule rows
carry `latency` "for scheduling" (asm_rules.crl:41) and nothing reads
them. `macro_fusion` is an IR-level cmp-adjacency nudge whose effect the
emitter's fixed order may not preserve. Belongs to: new
`target/*/scheduler` (list scheduler over a machine representation that
doesn't exist yet — see G36).

**G36 [Q] — no machine IR; the emitter *is* the machine layer.** All
"machine" optimizations are ad-hoc `iselTry*` pattern folds dispatched
inside `emitInst` (x86_64_base.crl:1723-2076) — single pass, no iteration,
no cross-pattern exposure, no post-RA peephole, no redundant-move
elimination beyond same-instruction src==dst checks. `machine_opt`
(passes/machine_opt.crl) is IR-level MemorySSA forwarding, misnamed.
Belongs to: longer-term — a machine-instruction layer between regalloc and
emission; short-term — a dedicated post-RA peephole pass over emitted
sequences.

**G37 [C] — no PIC/relocations.** Absolute symbol references for data
(G29), no `%rip`-relative addressing, no GOT; `@PLT` is appended only for
extern calls on SysV (x86_64_base.crl:2897-2902); no `.long/.quad`
relocation records, no section flags beyond `.text`. Anything but a
non-PIE static executable is unbuildable. Belongs to: backends + a
relocation/section model (see assembler-plan.md).

**G38 [C] — no unwind/EH metadata.** No `.eh_frame`, no `.cfi` directives;
`landingpad` is reserved in the IR (IR.md §10) and dropped by G28. Any
C++-interop or profiler/unwinder scenario is impossible; frame changes
(subq per alloca) would need CFI anyway. Belongs to: backends (emit CFI
from the frame model of G30).

**G39 [Q] — debug info is parsed, preserved, and then dropped.** The IR
carries `debug.file/line/col` and `var` metadata (IR.md §7.4); inline and
tco copy it (inline.crl:265-272, tco.crl cloneInst); no backend emits
`.file`, `.loc`, or any `.debug_*` section. Belongs to: backends — a
DWARF (or at least line-table) emitter keyed off `debugLoc`.

**G40 [C] — inline asm is dropped silently on every native backend.**
Confirmed by docs/assembler-plan.md ("No target handles
`IrOpcode::InlineAsm` at all … silently dropped"); the IR/parser side is
complete and the constraint/clobber data exists. Wasm fails loudly. The
planned two-layer assembler in assembler-plan.md is the fix. Belongs to:
`lib/wallvm/asm/` (new) per that plan.

**G41 [N] — CPU feature detection.** The linux driver hard-enables
AVX2/FMA/BMI/LZCNT (linux.crl:11-24) — emitted binaries won't run on
pre-2013 hardware; there is no `-mcpu`/host detection. Also no
`.note.GNU-stack` (linker will mark the stack executable) and no `.size`
directives on functions. Belongs to: target drivers + emission.

### 3.7 Whole subsystems missing

- **Atomics lowering** (G28): no `lock` prefix, no `cmpxchg` loops, no fence
  emission — the IR opcodes exist end-to-end and die at the emitter.
- **GC opcodes**: `gc_root`/`gc_writebarrier`/`gc_safepoint` have runtime
  support in `gc/gc.crl` but no codegen hookup (G28).
- **EH**: landingpad reserved, nothing else (G38).
- **Assembler**: text-out only; assembler-plan.md phases the real one (G40).
- **ARM32/ARM64/RISC-V/other backends**: rule tables exist
  (asm_rules.crl:1000-1355) but `irCodegen` silently routes those CCs to the
  x86-64 bare emitter (§1.8); Wasm64 likewise.
- **PGO**: `weight.true/false` metadata parsed and unused.

---

## 4. Severity ranking

### (a) Correctness / ABI blockers

| # | Gap | Ref |
|---|-----|-----|
| A1 | Spilled values decode as `rax`; no spill slots exist (contract broken end-to-end) | G21 |
| A2 | No fixed-reg/clobber modeling: div/shift/icmp/fcmp/vecdiv/uitofp destroy allocatable regs; reserved-array off-by-one OOB | G22 |
| A3 | Unhandled opcodes (noret, unreachable, atomics, fence, extract/insert*, gc_*, inlineasm) emitted as comments; `unreachable` falls through | G28 |
| A4 | alloca → `subq $8` at execution point; loop allocas grow stack; aggregates get 8 bytes; no frame | G30 |
| A5 | Store operand order inverted vs IR convention (both native backends) **[verify]** | G27 |
| A6 | abi_lower: IrModule*/IrContext* type confusion as wired; SysV pass applied to all CCs; Win64/x86 variants unwired | G3, G4 |
| A7 | Win64 lsra↔emitter register-name mismatch; `isWin` hardcoded false; param intervals uninitialized | G23 |
| A8 | No call-site stack alignment; no `%al` for varargs; stack-arg cleanup miscount; params >6 never seeded | G32 |
| A9 | No globals/rodata/bss emission; `dataSection` never flushed; duplicate `.Lfabs_mask` labels; no relocations/PIC | G29, G37 |
| A10 | LICM hoists possibly-trapping loads without dereferenceability/exit-domination checks | G18 |
| A11 | lsra interval correctness depends on unenforced block layout | G25 |
| A12 | sroa rewrites operands without use-list maintenance **[verify]** | G11 |
| A13 | jump_thread/tail_dup orphan predecessors into emptied blocks; sel2br creates nameless blocks **[verify]** | G14 |
| A14 | Frontend phis at L0/L1 reach codegen unlowered (no Phi case in emitter) | §1.2 |
| A15 | Wasm64 and all non-x86 CCs silently dispatch to the x86-64 bare backend | §1.8 |
| A16 | Deferred callee-save pushes can land in loops (32-bit targets) | G33 |
| A17 | validate-as-changed forces maxIters; hides non-convergence and double work | G1, G2 |
| A18 | stack_layout double-parents allocas and can overflow its scratch array **[verify]** | G30 |

### (b) Code-quality blockers (gcc/clang-quality goal)

| # | Gap | Ref |
|---|-----|-----|
| B1 | mem2reg refuses loop allocas → all loop-carried scalars stay in memory; every loop pass degraded | G10 |
| B2 | Phi lowering = alloca round-trip; no parallel copies, no coalescing | G13, G24 |
| B3 | Caller-save-only RA; call-spanning values always spill; float pool = 8 arg regs; no remat/splitting/slot packing; graph-RA is a no-op | G24 |
| B4 | No block placement/branch chaining/loop rotation → both edges of every branch are jumps; macro-fusion defeated | G31, G17 |
| B5 | No instruction scheduling; latency tables unread; no machine IR or post-RA peephole | G35, G36 |
| B6 | No simplifycfg / reassociate / PRE / indvars(SCEV) / real SROA | G14, G15, G19, G11 |
| B7 | No CGSCC/module stage; ipa_cp unwired; no globalopt/globaldce/attr-inference | G7 |
| B8 | Pipeline ordering: abi_lower at head; unroll post-optimizer (and twice); no cleanup after inline in-iteration | G5, G20, G6 |
| B9 | L1 has no mem2reg/SROA; L2/L3 lack a late local CSE; borrowcheck after opts | §1.3, G8, G6 |
| B10 | Epilogue duplication per ret; no shrink-wrapping; red-zone only for leaves | G33 |
| B11 | No general tail-call optimization | G34 |
| B12 | Quadratic data structures in hot passes | G26 |

### (c) Nice-to-have

| # | Gap | Ref |
|---|-----|-----|
| C1 | Debug-info emission (metadata exists end-to-end) | G39 |
| C2 | Inline-asm assembler layer (already planned) | G40 |
| C3 | EH/unwind tables | G38 |
| C4 | PIC/GOT + full relocation model | G37 |
| C5 | CPU feature detection; `.note.GNU-stack`; `.size` directives | G41 |
| C6 | Atomics/fence lowering, GC opcode hookup | §3.7 |
| C7 | ARM/ARM64/RISC-V/Wasm64 backends (rules tables exist) | §3.7 |
| C8 | memcpy/memset idiom formation; SLP; jump tables | G16 |
| C9 | PGO wiring for `weight.*` metadata | §3.7 |
| C10 | Pass timing, opt-bisect, IR dumps, validator diagnostics channel | G9 |

---

## 5. The three most urgent items

### 1. A1 — the spill contract (G21)

Every x86 target runs with `backendHandlesSpills = true`, which tells lsra
*not* to rewrite spills into IR loads/stores because "the backend decodes
SPILL_BIT/FLOAT_BIT itself" (wallvm.crl:341-343). No backend does.
`getRegForValue` maps any spilled value to `"rax"` and moves on; there is no
spill-slot frame for the slot index to even mean anything (allocas are
`subq $8` at the execution point). The moment a function has more
simultaneously-live values than the ~9 allocatable integer registers —
i.e. any non-trivial function, and *guaranteed* for every call-spanning
value under the caller-save-only policy — the output silently computes on
rax instead of the spilled value. Until this is fixed (either teach the
emitters a real spill frame, or flip `backendHandlesSpills` to false so
lsra rewrites loads/stores), **all other optimization work is unverifiable
by execution**, because any test large enough to exercise it can
miscompile.

### 2. A5+A4+A3 — emitter conformance to the IR (G27, G30, G28)

The emitter layer does not implement the IR it consumes. Stores appear
operand-inverted against `irBuilder.store(val, ptr)` and every IR pass
(ops[0] treated as address, ops[1] as value, width taken from the pointer
side); allocas are a per-execution `subq $8` with no frame, so any alloca
in a loop is an unbounded stack leak and any aggregate is truncated to 8
bytes; and an entire tail of the opcode space — noret, unreachable, the
atomics, fences, extract/insertvalue/element, gc ops, inline asm — falls
into a comment arm that emits *nothing*, with `unreachable` falling through
into the next block's bytes. Individually each is a miscompile; together
they mean the pipeline's correctness floor is "programs the emitter
happens to cover". Before pass ordering, before regalloc quality, before
vectorization: the emitter needs a conformance sweep against IR.md §6 —
every opcode either correctly emitted or loudly rejected (the wasm
backend's `failOp` behavior), stores reconciled with the builder
convention, and a prologue-computed frame for allocas and spill slots.

### 3. A2+A6+A7+A8 — the call/ABI boundary (G22, G3, G4, G23, G32)

Nothing about the function-call boundary is sound beyond trivial SysV leaf
functions. The register allocator has no model of fixed-register
constraints, so emitted sequences for div, shifts, compares, and
conversions clobber rax/rcx/rdx/r10/r11 while lsra keeps live values there
(and the reserved-register count overruns its own array by one). ABI
lowering is wired as a function pass that contractually requires the
module pointer it never receives, is the SysV implementation applied to
every calling convention while the Win64 and i386 implementations sit
unwired, and its own comment marks indirect calls as an IR gap. On Win64
the allocator and the emitter disagree about which physical register
indices 3-4 even *are*. Calls themselves don't maintain 16-byte stack
alignment, never set `%al` for varargs (while vararg prologues read it),
misaccount struct stack pushes in the cleanup, and never seed parameters
past the sixth. This cluster is the difference between "compiles
benchmarks" and "links against the world": any call with >6 arguments, any
vararg, any float-heavy call, any Windows target, or any div/shift under
register pressure is currently broken.
