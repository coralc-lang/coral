# Wallvm Optimization Landscape — pass inventory, scoring, gaps, roadmap

Status: analysis document. Inventories every pass in `lib/wallvm/passes/` (42
modules, `passes/lib.crl:1-42`) plus the driver-imported ABI pass, scores each
0-5 for implementation quality, scores gcc/clang **-O3** parity for the
optimizer (instruction scheduling and `-mtune`/micro-arch choices are excluded
by scope — machine-level gaps belong to `docs/pipeline-gaps.md`), and
ends with an ordered adoption roadmap. A dedicated section covers
vectorization/SIMD status, which is the single biggest -O3 delta.

Method: every claim below was read from the tree; line numbers are current as
of this reading (`wallvm.crl` has moved since `docs/pipeline-gaps.md` was
written — its §1 line refs are stale, the claims are re-verified in §5.3).
No compiler was run; this is a static audit. Scoring rubric:

- **5** — matches gcc -O3 quality for its domain (nothing lands here yet)
- **4** — correct, effective core implementation; minor coverage gaps
- **3** — real value but conservative/narrow, or known correctness caveats
- **2** — partially dead or misfired logic; small surface with defects
- **1** — wired but ineffective, or dead on valid IR
- **0** — exists but contributes nothing as wired

---

## 1. Summary table

| Pass (file) | Entry | Lane(s) | Score | vs gcc/clang -O3 |
|---|---|---|---|---|
| validate | `validate.crl:290` | head+tail all lanes, structure | 4 | infra (n/a) |
| algebraic/simplify | `algebraic.crl:314` | L0-3 | 4 | partial (vs instcombine) |
| constfold | `constfold.crl:466` | L0-3 | 4 | yes |
| sccp | `sccp.crl:869` | L0-3 | 4 | yes |
| dce (`irPassDce`) | `dce.crl:168` | L0-1 | 4 | yes |
| adce | `dce.crl:316` | L2-3 | 4 | yes |
| cse | `cse.crl:157` | L1 only | 4 | yes (early-cse) |
| gvn | `gvn.crl:244` | L2-3 | 4 | partial (no PRE) |
| peephole | `peephole.crl:470` | L1-3 | 4 | partial |
| comm_canon | `comm_canon.crl:84` | L1-3 | 4 | partial |
| involution | `involution.crl:174` | L1-3 | 4 | partial |
| idiom | `idiom.crl:440` | L1-3 | 4 | partial (no memcpy/memset) |
| divmod | `divmod.crl:94` | L3 | 4 | partial (no magic const div) |
| inline | `inline.crl:546` | L2-3 | 4 | partial (not bottom-up) |
| unroll | `unroll.crl:734` | structure, `--funroll` | 4 | yes (gated, G20) |
| alias_analysis | `alias_analysis.crl:665` | L2-3 (analysis) | 4 | partial (object-based) |
| borrowcheck | `borrowcheck.crl:1388` | structure | 4* | n/a — diagnostic; 0 as optimizer |
| range + range_br_elim | `range.crl:589,599` | L1-3 | 3 | partial (no SCEV) |
| branchprop | `branchprop.crl:166` | L1-3 | 3 | partial |
| licm | `licm.crl:301` | L2-3 | 3 | partial (G18 safety) |
| dse | `dse.crl:150` | L1-3 | 3 | partial |
| macro_fusion | `macro_fusion.crl:142` | L3 | 3 | scheduling-adjacent (excluded) |
| machine_opt | `machine_opt.crl:349` | L3 | 3 | partial (IR-level, name misleading) |
| lower_phis | `lower_phis.crl:10` | L2-3 tail | 3 | n/a (lowering; G2) |
| tail_dup | `tail_dup.crl:167` | L3 | 3 | partial |
| tco (accumulator) | `tco.crl:392` | L3 | 3 | partial (vs tailcallelim) |
| loopcse | `loopcse.crl:288` | L2-3 | 3 | partial |
| loop_interchange | `loop_interchange.crl:406` | L3 | 3 | yes (conservative) |
| loop_distribute | `loop_distribute.crl:543` | L3 | 3 | yes (conservative) |
| loop_detect | `loop_detect.crl:14,110` | utility (unwired) | 3 | partial (no canonical form) |
| memory_ssa | `memory_ssa.crl:358` | L2-3 slot — **no-op by design** | 3† | analysis exists; slot self-disables |
| select_to_branch | `select_to_branch.crl:181` | L3 | 2 | no |
| sroa | `sroa.crl:8` | L2-3 | 2 | no (not SROA — G11) |
| mem2reg | `mem2reg.crl:409` | L2-3 | 2 | partial (strong algorithm, memory bug) |
| jump_thread | `jump_thread.crl:134` | L1-3 | 2 | partial (orphan bug — G14) |
| lex_canon | `lex_canon.crl:182` | L3 | 2 | partial (chain sort discarded) |
| idempotent | `idempotent.crl:185` | L3 | 2 | no (main patterns dead) |
| branch_factoring | `branch_factoring.crl:271` | L3 | 2 | partial (half dead) |
| stack_layout | `stack_layout.crl:17` | L3 | 2 | n/a (heuristic; overflow risk) |
| branch_inversion | `branch_inversion.crl:9` | L1-3 | 1 | no (dead on valid IR) |
| ipa_cp | `ipa_cp.crl:281` | **unwired** | 1 | no (stub) |
| simd_vec | `simd_vec.crl:867` | L3 | 1 | no (see §6) |
| abi_lower | `x86_64/linux/abi_lower.crl:884` | L1-3 head | 3 | n/a (ABI; G3/G4 stand) |

\* scored as a diagnostic; as an optimizer it is 0 (it transforms nothing).
† scored as a library; as a pipeline slot it builds, destroys, and returns
`false` (`memory_ssa.crl:385-387`).

**Headline findings.** (1) Vectorization is effectively absent: the wired
`simd_vec` pass emits semantically wrong IR and does no loop-level
vectorization (§6). (2) The loop substrate is degraded — mem2reg refuses loop
allocas (G10), nothing canonicalizes/rotates loops (G17), no indvars (G19).
(3) The pipeline cannot fully converge and carries dead-on-arrival passes:
validate reports "changed" when valid (G1), branch_inversion/idempotent/
factorCommonGuards can never fire on validator-clean IR, and mem2reg has a
use-after-free/double-free (`mem2reg.crl:494,506,517`).

---

## 2. How the pipeline is wired (current line numbers)

```
irCompile (wallvm.crl:417)
  per function:  irOptimize → irStructureLane → regalloc
  whole module:  irCodegen

irOptimize (wallvm.crl:284): pick L0-L3, runOnFuncIterate, maxIters 1/2/5/8 (wallvm.crl:296)

L0 (wallvm.crl:169): validate, simplify, constfold, sccp, dce, validate
L1 (wallvm.crl:181): + abi_lower, comm_canon, involution, range, range_br_elim,
                     branchprop, branch_inv_flat, cse, cast_elim, dse,
                     jump_thread, idiom, peephole
L2 (wallvm.crl:206): + mem2reg, sroa, alias, mssa, licm, gvn, loopcse,
                     inline, adce, lowrphis            (no cse — G8)
L3 (wallvm.crl:238): L2 + stack_layout, lex_canon, branch_fact, divmod,
                     loop_interchange, loop_distribute, tail_dup, tco,
                     simd_vec, idempotent, macro_fusion, machine_opt, sel2br
structure lane (wallvm.crl:306): borrowcheck → [unroll if --funroll (318)] → validate
```

Two structural facts shape everything below:

- `runOnFuncIterate` treats any pass return of `true` as "changed, keep
  iterating" (`wallvm.crl:144-155`), and `irPassValidate` returns
  `nerrors == 0` — true when the IR is **valid** (`validate.crl:286,295`).
  Validate sits at both ends of every lane, so L1-L3 always burn all 2/5/8
  iterations (G1). Validation errors are discarded inside the pass.
- The structure lane runs **after** `irOptimize`, while its own comment
  demands borrowcheck "before any pass that could move or remove
  loads/stores" (`wallvm.crl:310-315`) — G6 stands.

---

## 3. Score distribution

| Score | Count | Entries |
|---|---|---|
| 5 | 0 | — |
| 4 | 17 | validate, algebraic, constfold, sccp, dce, adce, cse, gvn, peephole, comm_canon, involution, idiom, divmod, inline, unroll, alias_analysis, borrowcheck* |
| 3 | 15 | range, branchprop, licm, dse, macro_fusion, machine_opt, lower_phis, tail_dup, tco, loopcse, loop_interchange, loop_distribute, loop_detect, memory_ssa†, abi_lower |
| 2 | 8 | select_to_branch, sroa, mem2reg, jump_thread, lex_canon, idempotent, branch_factoring, stack_layout |
| 1 | 3 | branch_inversion, ipa_cp, simd_vec |
| 0 | 0 | — |

43 entries = the 42 modules in `passes/lib.crl` + the driver-imported
`abi_lower`. The distribution is a healthy middle: the scalar-folding core is
solid (the 4s), the loop/CFG layer is where quality decays, and the tail of
1s and 2s is disproportionately expensive because those passes run on every
L1+ compile yet either cannot fire or actively mutate the CFG incorrectly.

---

## 4. Inventory notes (evidence per group)

### 4.1 Scalar simplification and folding — the strong core

- **algebraic** (`irPassSimplify`, `algebraic.crl:314`): identity,
  strength-reduction and extension-chain patterns; workhorse of every lane.
  Score 4; vs instcombine it lacks reassociation (G15).
- **constfold** (`constfold.crl:466`): full integer/float binary, unary,
  convert, select, FMA and rotate folding. Score 4 — on par with clang
  constant folding, short of UB-based information.
- **sccp** (`sccp.crl:869`): real worklist SCCP with lattice, reachability
  and phase-2 replacement (`replaceAllUses` at `sccp.crl:1086`). Score 4.
- **cse** (`cse.crl:157`): block-local CSE with commutative matching and
  call invalidation. Correct but L1-only — L2/L3 rely on dom-scoped GVN with
  no cheap local cleanup after inline/lowrphis churn (G8).
- **gvn** (`gvn.crl:244`): dominator-scoped expression table + load CSE; no
  PRE (G15). Score 4.
- **peephole** (`peephole.crl:470`): identity folds + branch redirect; some
  added code paths are guarded into deadness by a phi check (safe, odd).
  Score 4.
- **comm_canon** (`comm_canon.crl:84`) const-to-right; **involution**
  (`involution.crl:174`) fabs/neg/xor inverse chains with width guards;
  **cast_elim** (`cast_elim.crl:38`) ten cast-nesting patterns — all score 4.
- **lex_canon** (`lex_canon.crl:182`): **defect** — the chain that
  `flattenSortChain` rebuilds is computed then discarded; only the two operands of the
  current instruction get sorted, and the abandoned instructions leave stale
  use lists (`lex_canon.crl:200-210`). Score 2.
- **idempotent** (`idempotent.crl:185`): **mostly dead** — both the
  redundant-store scan and the store→load bypass scan break at any preceding
  `Store` (`idempotent.crl:64-71,107-114`) before reaching the Store-match
  checks that sit behind the break (`idempotent.crl:80,119`). Only the
  bitcast/GEP/dead-alloca patterns can fire. Score 2.
- **divmod** (`divmod.crl:94`): div+rem fusion with dominance and use-count
  gating — good. But the Granlund–Montgomery constant-divisor sequences
  used by gcc
  do not exist anywhere (pow2 only, see codegen-quality §2), so parity is
  partial.
- **idiom** (`idiom.crl:440`): rotate, bswap or-chains, min/max selects,
  abs, FMA — but no memcpy/memset loop idiom formation (G16). Score 4.
- **select_to_branch** (`select_to_branch.crl:181`): fires only when the
  defining instruction of a value operand is a side-effecting op
  (`select_to_branch.crl:52-53`, `159-178`) — but such operands are eagerly
  evaluated before the branch anyway, so the conversion defers nothing; pure
  selects (where a cmov-vs-branch tradeoff would be discussed) are skipped.
  Net effect: three new blocks per conversion (`:60-99`) and CFG churn.
  Score 2.

### 4.2 Branch/CFG passes — half of them cannot fire

- **branch_inversion** (`branch_inversion.crl:9`): **dead on valid IR.** It
  requires the last **two** instructions of a block to both be `CondBr`
  (`branch_inversion.crl:26-27`), but the validator demands exactly one
  terminator, last (`validate.crl:146-165`). Its ICmp-branch arm is
  unreachable for the same reason. Score 1; wired in L1-L3 (`wallvm.crl:194`).
- **branch_factoring** (`branch_factoring.crl:271`): `collapseInversions`
  (`:35`) works, but `factorCommonGuards` (`:157`)   only proceeds when the last instructions of both target blocks are `ICmp`
  (`:179`) — again a shape the
  validator forbids. Half the pass is dead. Score 2.
- **branchprop** (`branchprop.crl:166`): dominator-scoped constant
  propagation of `icmp eq/ne`. Real, conservative. Score 3.
- **jump_thread** (`jump_thread.crl:134`): threads through side-effect-free
  passthrough blocks; rewires the source terminator and edges for itself,
  then empties the target with `target->ninsts = 0`
  (`jump_thread.crl:75-95`) **without checking other predecessors of the
  target**. Any multi-pred passthrough block leaves those preds
  pointing at a terminator-less block; nothing ever cleans that up at L2/L3
  (see 4.4). Score 2.
- **tail_dup** (`tail_dup.crl:167`): same shape but correctly gated on
  `target->npreds == 1` (`tail_dup.crl:41-43`); still leaves an empty block
  behind. Score 3.
- **macro_fusion** (`macro_fusion.crl:142`): moves a cmp adjacent to its
  dependent branch within a block. Scheduling-adjacent (out of scope for
  parity), and defeated by the lack of loop rotation/block layout (G31).
  Score 3.
- **Simplifycfg does not exist** (G14): no empty-block folding, no
  common-tail merge, no branch-to-empty-block elimination anywhere in
  `passes/`.

### 4.3 Memory, SSA, and aliasing

- **mem2reg** (`mem2reg.crl:409`): full Cytron SSA construction — dominance
  frontiers, renaming, phi placement. Two serious defects:
  1. **Use-after-free + double-free**: `inLoop` is allocated at `:457`,
     freed at `:494`, then read at `:506/:514` and freed again at `:517`
     inside the `if (anyLoopAlloca)` branch — i.e., exactly when a
     loop-touched alloca exists, which is any function with a loop alloca.
  2. The loop-alloca promotion refusal itself (G10): every alloca whose
     def/use blocks are inside a loop stays in memory
     (`mem2reg.crl:455-519`), so LICM/GVN/range/unroll/simd_vec all see
     loads/stores instead of values — while `unroll.crl:3-9` documents that
     it expects "the canonical loop form produced by mem2reg".
     Also returns `true` unconditionally (`mem2reg.crl:599`), so it claims
     change even when it promoted nothing. Score 2 (algorithm 4, safety 0).
- **sroa** (`sroa.crl:8`): not SROA — single-store scalar forwarding; no
  aggregate splitting, GEP/atomic uses bail (G11). The use-list maintenance
  gap from pipeline-gaps is **fixed**: operands are rewritten through
  `removeUser`/`addUser` (`sroa.crl:133-144`). Still score 2: struct/array
  allocas are never scalarized, so they can never be promoted.
- **lower_phis** (`lower_phis.crl:10`): alloca round-trip per phi. Correct
  even on critical edges, but pure memory traffic, inserted last so regalloc
  never coalesces it, and ping-pongs with mem2reg at L2/L3 whenever a
  non-loop phi exists (G2). Score 3.
- **alias_analysis** (`alias_analysis.crl:665`): object-based points-to over
  allocas/globals with GEP/bitcast/phi propagation, escape tracking, and a
  256-object cap (`alias_analysis.crl:31`). No field sensitivity. Score 4 —
  adequate for the passes that consume it.
- **memory_ssa** (`memory_ssa.crl:358`): builds MemorySSA, then `deinit()`s
  it and returns `false` (`memory_ssa.crl:385-387`) — the L2/L3 pipeline slot
  exists purely to burn time, with an honest comment explaining why it cannot
  be cached (dangling AA pointer). Consumers (machine_opt, loopcse) recompute
  their own views per run. Score 3 as a library, and see edge candidate E1.
- **machine_opt** (`machine_opt.crl:349`): despite the name, an IR pass:
  MemorySSA store-to-load forwarding + DSE. The cross-block forwarding
  advertises "via dominance" (`machine_opt.crl:80`) but scans blocks by
  **array index** `pi < bi` for killing stores (`machine_opt.crl:240`) —
  neither sound (a later-indexed block can lie on the path) nor complete
  (an earlier-indexed block can too). Score 3.
- **dse** (`dse.crl:150`): single-block must-alias DSE with barrier flush. 3.
- **licm** (`licm.crl:301`): builds/reuses preheaders (`licm.crl:16`,
  `createPreheader`), hoists loop-invariant code. The load hoist check is
  only alias-vs-stores plus call/asm presence (`licm.crl:379-400`) — no
  dereferenceability proof, no "dominates all exits" test, so a conditional
  load can be speculated into the preheader and fault (G18 stands). Score 3.
- **loopcse** (`loopcse.crl:288`): hoists loads from loops that provably
  cannot write (`loopcse.crl:44-56`), dedupes preheaders; leaks the `IrLoop`
  objects it allocates (comment admits it, `loopcse.crl:39`). Score 3.
- **borrowcheck** (`borrowcheck.crl:1388`, collect variant `:1421`):
  diagnostic-only — three rules, CFG liveness, union-find regions, a
  fixed-point write-capability analysis; the pipeline calls it and discards
  the result (`wallvm.crl:312-315`). Score 4 as what it is (diagnostics), 0
  as an optimizer.

### 4.4 Loops

- **loop_detect** (`loop_detect.crl:14,110`): natural-loop detection over the
  domtree; utility, wired into no pipeline (passes that need loops — licm,
  unroll, interchange, distribute, simd_vec — each re-derives induction
  patterns by hand). Score 3.
- **unroll** (`unroll.crl:734`): full unroll with trip count, budgets, and
  phi/block teardown. Well implemented, but opt-in via `--funroll` and placed
  in the structure lane after the entire optimizer (`wallvm.crl:318`), so its
  output is never re-simplified in the same compile (G20). Score 4.
- **loop_interchange** (`loop_interchange.crl:406`) and **loop_distribute**
  (`loop_distribute.crl:543`): both carry real safety checks (nesting, IV
  shape, no calls/atomics, single latch) and refuse conservatively. Score 3
  each — correct, rarely fire without canonical loop form.
- **What loops lack** (§5.2): rotation, LCSSA, loop-simplify, unswitching,
  loop deletion, indvars/SCEV, strength reduction, and real vectorization.

### 4.5 Interprocedural and driver-adjacent

- **inline** (`inline.crl:546`): function-local cost model with thresholds
  keyed to caller size (200/80 cut-offs, `inline.crl:552-557`), single-site
  discount (`:209-214`). The recursion guard is direct-only — "callee calls
  back to caller" (`inline.crl:150`) — not an SCC check, and callers are
  optimized in module order rather than bottom-up (G7). Score 4.
- **tco** (`tco.crl:392`): accumulator-recursion → loop. Much narrower than
  the tailcallelim pass; the emitter has its own adjacent `call;ret → jmp`
  peephole (pipeline-gaps G34). Score 3.
- **ipa_cp** (`ipa_cp.crl:281`): **stub** — the entry exists, `TODO,
  implement module-level entry point` at `ipa_cp.crl:288`, wired into no
  pipeline. The module-level pass layer (ipscp, globalopt, globaldce,
  argpromotion, attribute inference) simply does not exist (G7). Score 1.
- **abi_lower** (`x86_64/linux/abi_lower.crl:884`): SysV eightbyte
  classification, wired at the head of L1-L3. G3 (contract wants an
  `IrModule*`, driver passes `IrContext*`) still stands as written — the
  null-fallback added at `abi_lower.crl:886-888` never triggers when a
  non-null context pointer is type-punned through it **[verify]** — and G4
  stands: only the SysV variant is imported (`wallvm.crl:52`); Win64/i386
  variants are referenced nowhere. Score 3.
- **stack_layout** (`stack_layout.crl:17`): sorts hot/cold allocas into the
  entry block, but `newCap = entry->ninsts` (`stack_layout.crl:157`) while it
  then pushes **every** collected alloca including ones gathered from other
  blocks (comment at `:176-178`) — `newCount` can exceed `newCap` (heap
  overflow) and moved allocas keep their old parents (double-parenting).
  The G30 risk stands. Score 2.

---

## 5. Gap analysis vs gcc/clang -O3

Scope: optimizer only. Instruction scheduling, block placement heuristics,
`-mtune`-driven instruction selection and the machine layer are excluded
(see `docs/pipeline-gaps.md` G31/G35/G36) — except where they cap what an
optimizer pass can achieve, which is noted.

### 5.1 At parity (partial→yes)

Constant folding/SCCP, local+dom-scoped CSE/GVN, DCE/ADCE, integer identity
simplification, loop unrolling (behind a flag), loop interchange/distribution
(at a conservative subset), div+rem fusion, rotate/abs/minmax idioms, inline
(cost-modelled but not CGSCC), object-based alias analysis, LICM hoisting
(with the G18 caveat), range-based branch elimination (a
correlated-range-elimination cousin).

### 5.2 Missing or broken vs -O3

**Scalar/CFG layer**

- No **simplifycfg** (G14): empty/merged block folding, common-tail
  merge/hoist, branch-to-empty-block elimination. Two of the three CFG
  passes that exist cannot fire on valid IR (branch_inversion,
  factorCommonGuards — §4.2).
- No **reassociation** beyond two-operand lexical sort, and the chain
  rebuild from that sort is discarded (`lex_canon.crl:200-210`; G15).
- No **PRE** in GVN (G15); no loop-invariant code motion of stores; no
  EarlyCSE-style cheap pass at L2/L3 (G8).
- The fixpoint itself is fake: validate-as-changed (G1) guarantees all
  iterations run, while mem2reg↔lower_phis ping-pong (G2) means some
  functions can never converge.

**Memory layer**

- No real **SROA** (G11): aggregates never scalarized → never promoted.
- mem2reg **loop-alloca refusal** (G10) — the highest-leverage single defect
  for loop code quality: every loop-carried scalar stays in memory, degrading
  LICM, GVN, range, unroll, and any future vectorizer at once.
- No **loop idiom formation** for memcpy/memset (G16) — gcc turns byte
  loops into `memset@PLT` tail calls; we emit the byte loop.

**Loop layer**

- No **loop canonicalization**: no loop-simplify form, no LCSSA, no **loop
  rotation** (G17). Without rotation the backedge is not a fall-through, which
  also defeats macro_fusion at the loop bottom (G31) and leaves every loop
  pass re-deriving induction patterns by hand.
- No **indvars/SCEV** (G19): trip counts computed ad hoc per pass; no loop
  strength reduction (the `i*stride+j` addressing stays as mul+add).
- No **unswitching**, no **loop deletion** (store-only loops are not
  DCE-able today).
- **Vectorization**: see §6 — worse than missing; the wired pass is harmful.

**Interprocedural layer**

- No CGSCC/module stage (G7): ipa_cp is a stub, no ipscp, globalopt,
  globaldce, deadarg/argpromotion, no attribute inference; inliner is not
  bottom-up.

**Pipeline hygiene**

- G1 (validate burns iterations, discards diagnostics), G5 (abi_lower at
  pipeline head), G6 (borrowcheck after the passes that move memory),
  G20 (unroll after everything, and twice via `irCompileAsm`) all stand.

### 5.3 `pipeline-gaps.md` claims re-verified this pass

Revalidated again 2026-10-09 against the current tree. Most of the
re-verification below was already done here; this pass closed the one item
it had left open and added two new findings.

| Claim | Status now |
|---|---|
| G1 validate returns true when valid | **stands** (`validate.crl:252,295` vs `wallvm.crl:158-163`) |
| G2 mem2reg ↔ lower_phis ping-pong | **stands** (`lower_phis.crl:50-89` allocas pass mem2reg's screen at `mem2reg.crl:528-541`; lane order unchanged, `wallvm.crl:252,298`) |
| G7 no module layer, ipa_cp unwired | **stands** (`passes/lib.crl:19` exports it; no pipeline references it) |
| G10 mem2reg refuses loop allocas | **stands** (`mem2reg.crl:449-519`) |
| G11 sroa use-list staleness | **fixed** — rewrites go through removeUser/addUser (`sroa.crl:135-137`, :143-144, :150-157); "not SROA" part stands |
| G14 threaders orphan preds | **stands for jump_thread** (`jump_thread.crl:80`, no npreds check); **fixed for tail_dup** (`tail_dup.crl:43,98,131`). sel2br's unnamed blocks also still real (`select_to_branch.crl:24-28`) |
| G18 LICM speculation | **stands** (`licm.crl:196-198`, :348-358, :379-399) |
| G20 unroll placement | **stands** (`wallvm.crl:338-341`) |
| G21 spill contract | **fixed — question closed.** The item this row left open is now settled: the prologue *does* reserve the frame area. `spillSlotCount = countSpillSlots(func)` and `spillFrameBytes = spillSlotCount * 16` (`x86_64_base.crl:575-576`, :2199-2231) and the region is reserved in the prologue (:775-796) and released in the epilogue (:1030-1037), with frame/red-zone/shrink-wrap all gated on `spillSlotCount == 0` (:593, :719-729). `valueIsSpill` has ~40 call sites. See A1 struck in `pipeline-gaps.md` |
| G27 store operand order inverted | **fixed, and the original claim was wrong** — every emitter path reads `ops[0]`=value, `ops[1]`=address with width from the value type (`x86_64_base.crl:1557-1562`, :1687-1701, :1818-1824, :2742-2745; `x86_base.crl:783-786`), matching `irBuilder.store(val, ptr)` and the prologue seeding in the same file (:830, :852) |
| G22 reserved-reg off-by-one | **fixed** — `X86_64_RESERVED_INT` has 4 entries with `numReservedIntRegs = 4`, float 3/3 (`x86_64_base.crl:13-19`, `wallvm.crl:413-416`). The **clobber** half of G22 stands |
| G3 abi_lower userdata confusion | **fixed** — pass reads `func->parent` (`target/x86_64/linux/abi_lower.crl:906-916`); `addFunc` sets it (`irtypes.crl:547`) |
| G30 alloca frame model | **fixed** — type-sized, 16-rounded, prologue-reserved, rbp-relative (`x86_64_base.crl:460-514`, :776-796, :2764-2772) |
| G32 call-site ABI details | **fixed** — alignment, `%al` for varargs, single stack-arg pass, params past 6th/4th seeded (`x86_64_base.crl:3543-3550`, :3781-3790, :3552-3663, :808-1022) |
| G34 tail calls | **regressed** — `isTailCall` is now an unconditional `return false` naming G34 as open (`x86_64_base.crl:3841-3849`); `emitRet`'s tail branch is dead. 64-bit tail calls gone |
| **G42 unsigned div `cqo`** | **fixed 2026-10-09** — was **new — wrong answers**: `emitDiv`/`emitRem` emitted `cqo` then `divq` for the unsigned case; they now branch on `isSigned` (`cqo` vs `xorl %edx, %edx`), the sequence the 32-bit port already had (`x86_base.crl:672,710`) |
| **G43 `stack_layout` overflow** | **fixed 2026-10-09** — was **new — heap corruption**: the gather now takes only allocas whose `parent` is the entry block, the rebuilt array is null-checked, and the append refuses to run past `newCap`; the dangling-`parent` double-parenting is gone with the gather restriction |

---

## 6. Vectorization and SIMD status

This is the largest -O3 gap, so it gets a full section. Three layers exist:
the IR pass (`passes/simd_vec.crl`), the IR opcode surface
(`base/irOps.crl:68-79`), and the backends (`target/x86_64/x86_64_base.crl`,
`target/x86_64/avx.crl`, `target/wasm/wasm.crl`). They do not agree with
each other.

### 6.1 What the pass does

`irPassAutoVectorize` (`simd_vec.crl:867`) is wired into L3 only
(`wallvm.crl:270`). Per function it finds loops by a layout-order back-edge
heuristic (`simd_vec.crl:180-193`), analyzes header+latch for an induction
phi, and matches six patterns — elementwise load-op-store, load-store copy,
broadcast-mul, sum reduction, min/max reduction (`simd_vec.crl:21-29`). On a
match it inserts `VecBroadcast` + `Vec*` ops next to the scalar chain,
neuters the scalar store into `Noret` (`simd_vec.crl:777-784`), and relies on
its own peephole sweep to delete the dead scalar chain
(`simd_vec.crl:817-864`).

### 6.2 Findings

- **F1 — it is not loop vectorization.** The loop is never widened: the
  IV step stays 1 element, there is no body replication by the vector width,
  no trip-count/width interaction (`chooseVectorWidth` picks lanes purely
  from element size, `simd_vec.crl:558-568`), no scalar remainder
  handling, no runtime alias check, and no cost model at all —
  `applyVectorization` transforms each candidate unconditionally
  (`simd_vec.crl:599-629`). Even if every emitted instruction were
  correct, the loop would still do one element per iteration; throughput
  cannot improve. There is no SLP either (G16).
- **F2 — candidates are only searched in the header block.**
  `findCandidates` iterates `header->ninsts` exclusively
  (`simd_vec.crl:288-291`); real loop bodies are separate blocks in
  canonical form, so only degenerate single-block loops ever match.
- **F3 — the "vector load" is a splat of the pointer.** The pass emits
  `VecBroadcast` with the base address of the GEP as its operand
  (`simd_vec.crl:636-640,681-687,726-730`), commented "Create vector load".
  But `VecBroadcast` means *splat a value*: the x86 emitter does
  `vbroadcastss src` from a register (`x86_64_base.crl:3374-3398`) and wasm
  emits `<ty>.splat` (`wasm.crl:1673-1680`). There is **no vector load
  opcode at all** in `base/irOps.crl:68-79` — so the emitted IR splats the
  address bits instead of loading elements. On AVX2 the source is a GPR
  (`getRegForValue` of a pointer), which `vbroadcastss %rax` cannot even
  encode.
- **F4 — reductions mix scalar and vector types.** The reduction transform
  feeds the scalar accumulator phi and a vector load into a `Vec*` op and
  then `replaceAllUses` the result of the scalar op with the vector-typed value
  (`simd_vec.crl:800-815`), so the phi and its users change type
  mid-function. The comment defers the horizontal-reduction lowering to "the
  backend", which has no such lowering.
- **F5 — the side-effect safety scan skips header and latch.**
  `analyzeLoop` excludes `header` and `latch` when checking for
  calls/atomics/fences (`simd_vec.crl:261-278`) — the two blocks that always
  exist — so a call in the latch does not disqualify the loop.
- **F6 — backend vector emission ignores width.** `emitVecBinOp` /
  `emitVecFloatBinOp` promote xmm→ymm and emit 256-bit ops whenever AVX2/AVX
  is enabled (`x86_64_base.crl:3311-3324,3345-3357`) with no check that the
  vector type is 256 bits wide; `xmmToYmm` just renames the register string
  (`x86_64_base.crl:3289-3304`). A `<4 x i32>` op writes garbage into the
  upper 128 bits. `tyVector` stores width 0 (`irtypes.crl:726`), and
  `emitStoreWidth` switches on `type->width` with `case 16 → movw` and
  `default → movq` (`x86_64_base.crl:1316-1345`) — a vector store therefore
  emits an 8-byte `movq` regardless of the real size of the vector
  (`irTypeSizeOf` knows better: `irtypes.crl:795`).
- **F7 — `avx.crl` is a dead file.** All 272 lines of
  `target/x86_64/avx.crl` (256/512-bit emitters, gather, FMA helpers) are
  imported by nothing — zero references outside the file; only
  `generic.crl:23-24,72-73` sets `features.avx`. The inline xmm→ymm
  promotion in `x86_64_base.crl` duplicates a subset of it. Either wire it
  deliberately or delete it.
- **F8 — opcode coverage is one-way.** The IR has `ShuffleVector` and the
  emitter handles it (`x86_64_base.crl:2315`), but `ExtractElement` /
  `InsertElement` exist in the IR and are handled only by wasm — on x86-64
  they fall into the silent comment arm (pipeline-gaps G28), so any
  extract/insert a future vectorizer emits is dropped from the binary.

### 6.3 Verdict

`simd_vec` scores 1: wired, active at -O3, and its output is semantically
wrong (F3/F4) while being performance-neutral at best (F1/F2). The backend
has a usable 128-bit SSE floor and partial AVX promotion, but no vector
memory ops, no width discipline, and no reduction lowering. A real
implementation needs, in order: vector load/store opcodes (or GEP-based
loads feeding extract/shuffle) + width-aware emission (F6), a canonical
loop form (§5.2, G17), then a proper loop vectorizer: trip-count/width
analysis, runtime alias versioning, scalar epilogue, and a profitability
model — plus SLP for straight-line code (G16).

---

## 7. Edge candidates

- **E1 — stop throwing MemorySSA away.** `memory_ssa.crl:385-387` builds
  MSSA, destroys it, and returns false every iteration of every L2/L3
  pipeline; `machine_opt` and `loopcse` then re-derive overlapping views from
  scratch (G26 waste). Fixing the objection in the ownership comment (an MSSA
  holding a pointer to a dying AA) is small — store both in the
  `FunctionAnalysisCache` together (`wallvm.crl` analysis cache, bumped per
  mutation at `wallvm.crl:133,152`) — and turns the ad-hoc memory reasoning
  of three passes into one shared, correct analysis. Low effort, medium win.
- **E2 — rotation-aware resurrection of the dead branch passes.**
  branch_inversion and factorCommonGuards are wired but unreachable
  (§4.2). Rewriting them against the *rotated* loop form (fall-through
  backedge, header test at bottom) is the natural pairing: rotation (G17)
  gives them a legal shape, they give the rotated loops macro-fusion and
  branch-chain friendliness (G31). One infrastructure change unlocks three
  currently-dead passes.
- **E3 — vector memory ops as the thin end of the wedge.** Adding
  `VecLoad`/`VecStore` (or vector-typed GEP loads) with width-aware
  `emitStoreWidth`/`emitLoadWidth` and fixing `xmmToYmm` gating (F6) is a
  contained backend change that (a) makes even the current broken `simd_vec`
  output honest or loudly rejected, (b) unblocks future loop vectorization
  and memset/memcpy idiom lowering (G16), and (c) resolves the fate of the
  dead `avx.crl` (F7) — wire or delete, consciously.
- **E4 — resurrect `ipa_cp` as the module-layer beachhead.** The pass
  structure exists (`ipa_cp.crl:44-281`), the driver has no module stage
  (G7) — a minimal module pass that propagates constants into/through
  calls, plus bottom-up caller ordering for the existing inliner, buys most
  of the benefit of ipscp without a full CGSCC framework.

---

## 8. Adoption roadmap

Ordered by dependency: nothing in row 2+ is trustworthy or observable until
row 1 lands, and row 3 needs the loop form of row 2.

| # | Item | Why | Hook point | Effort | Win |
|---|---|---|---|---|---|
| R1 | Optimizer correctness sweep | Pipeline cannot converge; several passes are dead or unsafe, so optimization results are unverifiable | `mem2reg.crl:494-517` (UAF/double-free), `validate.crl:286` vs `wallvm.crl:144-155` (ran-vs-changed contract), `branch_inversion.crl:26-27`, `idempotent.crl:64-80,107-120`, `branch_factoring.crl:179`, `lex_canon.crl:200-210`, `select_to_branch.crl:52-53`, `memory_ssa.crl:385-387` (E1) | days | converging fixpoint, 5 passes that can actually fire, honest pipeline slots |
| R2 | Loop substrate: canonical form + indvars-lite + placement | Every loop pass (and the future vectorizer) re-derives structure today; G10 keeps loop scalars in memory | new `passes/loop_canon.crl` (rotate + LCSSA + dedicated exits) inserted in L2/L3 before licm (`wallvm.crl:224,261`); mem2reg loop promotion behind an lsra fix (G10/G13); move `irPassUnroll` from the structure lane into the lane (`wallvm.crl:318`); LICM safety `licm.crl:379-400` | medium | unroll/interchange/distribute/macro-fusion all start firing; trip counts become computable |
| R3 | Real vectorization (with E3) | The defining -O3 feature; the current pass is worse than nothing | backend first: `base/irOps.crl:68-79` (VecLoad/VecStore), `x86_64_base.crl:1316-1345,3306-3398` (width discipline); then replace `passes/simd_vec.crl` on top of R2's loop form: cost model, runtime alias check, scalar epilogue, then SLP | large | vector-width throughput on dense loops; retire or wire `avx.crl` |
| R4 | CFG hygiene: simplifycfg + PRE + reassociate | CFG passes that exist cannot fire; two more do not exist (G14/G15) | new `passes/simplifycfg.crl` (empty-block fold, common-tail, branch-to-empty) run early in each lane; PRE inside `gvn.crl:244`; real chain sort in `lex_canon.crl:200` | medium | instruction count and branch quality across all code, plus fixes orphaned by jump_thread |
| R5 | Module layer: ipscp + bottom-up inline + globaldce | G7 — the entire interprocedural tier is absent | new module stage in `irCompile` (`wallvm.crl:417`), resurrect `ipa_cp.crl:281-289` | medium-large | cross-function constants, dead-code elimination at module scope |

---

## 9. Relation to the other documents

- `docs/pipeline-gaps.md` — complementary and deeper on driver/regalloc/
  backend gaps (G1-G41). §5.3 above re-verifies its optimizer claims against
  the current tree; its §1 line numbers are stale. This document adds the
  per-pass scoring, the dead-pass findings (branch_inversion,
  factorCommonGuards, idempotent, lex_canon), the mem2reg memory bug, and
  the full vectorization section, none of which appear there.
- `docs/codegen-quality.md` — the emitter-side counterpart (width-correct
  mnemonics, isel folds); its §2/§3 findings stand independently. The
  constant-divisor magic-multiply item there closes the `divmod` parity gap
  noted in §4.1.
- `docs/assembler-plan.md` — relevant only through E3: its P5 phase
  (wider SSE/AVX tables, inline-asm validation) is where the mnemonic-side
  of vector emission would land.

Caveats: this is a static reading; no pass was executed (repo rules forbid
running the compiler), so scoring reflects code as written. Items marked
**[verify]** have a plausible alternate reading and should be checked before
being acted on.
