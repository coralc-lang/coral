# Codegen Quality Reference (gcc study → wallvm audit)

Goal: measure our x86 backend (`lib/wallvm/target/x86_64/x86_64_base.crl`,
`lib/wallvm/target/x86/x86_base.crl`) against what GCC actually emits, per
construct, and turn the gap into a prioritized fix list.

Corpus: `/tmp/wallvm_corpus/corpus.c` (~60 tiny functions covering integer
add/sub/mul/div/rem (signed+unsigned), shifts, compares, selects, i8/i16/i32/i64
loads/stores, arrays + struct field access, float add/mul/div/compare, calls
(leaf/non-leaf), loops (sum, memset-like), abs/min/max, constant materialization,
pointer arithmetic, div by constant). Built with
`gcc -O0/-O1/-O2/-O3 -S -masm=att` (GCC 16.1.1). Representative -O2 output is in
`/tmp/wallvm_corpus/o2.s`.

## Section 1 — What GCC emits and why it is good

### 1.1 Width-correct mnemonics everywhere
GCC picks the mnemonic to match the C type: `addl/subl/imull/idivl/shrl/sarl/cmpl/movl`
for 32-bit ops; `movq/imulq` only when the type is 64-bit. It never materializes a
64-bit op for 32-bit data. Writing a 32-bit result zero-extends into the 64-bit
register for free, so the upper half needs no separate cleanup.

### 1.2 `xorl %eax,%eax` for zero
`zero()`, `uzero()` compile to `xorl %eax, %eax; ret`. `xor reg,reg` is handled
as a zero-idiom (no dependency on the old value, breaks the dependency chain,
1 cycle). Same trick sets `%edx` before unsigned `divl` (`xorl %edx,%edx`).

### 1.3 `leal` for adds and scaled adds
`a+b` → `leal (%rdi,%rsi), %eax`. `a*3-b` → `leal (%rdi,%rdi,2), %eax`. `x*7` →
`leal 0(,%rdi,8), %eax; subl %edi, %eax`. `i*stride+j` → a single `imull` +
`movlslq` + one SIB load. LEA costs one cycle, no flags, and folds scale-by-1/2/4/8
plus displacement for free — the canonical replacement for mul-by-small-constant and
for an explicit add.

### 1.4 Memory operands folded into ALU ops
`a[i] += v` on the same address compiles to `addl (%rdi), %eax` / `add w/l/q, (%r)` —
one instruction instead of load+op+store. `sum += a[i]` → `addl (%rdi), %eax`.
`p->y = v` → `movl %esi, 4(%rdi)`. `p->x` → `movl (%rdi), %eax`. Struct field offsets
fold into the displacement (`4(%rdi)`, `8(%rdi)`, `10(%rdi)`).

### 1.5 `test` vs `cmp $0`
Guarding a loop with a zero/non-zero check: `testl %esi, %esi; jle`/`je` rather than
`cmp $0`. A compare against zero is just a subtract — `test` sets the same ZF and
documents intent; more importantly the incoming flag may already hold the answer.

### 1.6 `cmov` / `setcc` for small selects
`max(a,b)` → `cmpl %edi, %esi; movl %edi, %eax; cmovle %esi, %eax`. Compare →
zeroed rax → `setle %al`. `abs` → `negl; cmovs %edi, %eax`. Branchless, no
misprediction, both inputs already evaluated.

### 1.7 Sign/zero-extension folding into loads
`char`, `short` loads emit `movzbl/movzwl` (zero-extend) or `movsbl/movswl` (sign-extend)
*directly from memory* — no separate `movzbl reg, reg` after a plain load, no
dest-suffix trickery. Small struct fields likewise (`sz` → `movswl 8(%rdi), %eax`,
`sw` → `movsbl 10(%rdi), %eax`).

### 1.8 `idiv` only when necessary; magic-multiply for constant divisors
Runtime divisor → real `cdq`/`idiv` (or `xorl %edx,%edx`/`divl` unsigned). Constant
divisor 7 → `imulq $-1840700269` + shifts (the Granlund–Montgomery magic-number
division sequence), which turns a ~20–40-cycle `idiv` into a 3-cycle multiply + shift.
GCC also special-cases powers of two (`sar/shrl` by k, with bias correction for
signed division) — fixed shifts instead of a divide.

### 1.9 Branch layout: hot path falls through
The loop body (`addl (%rdi), %eax; addq $4, %rdi; cmpq %rdx, %rdi; jne`) keeps the
back-edge taken/not-taken so the fall-through path is the loop body; the cold path
(`.L36:`, `.L39:`) is placed after the hot path. PDE/idiom loops become `jmp memset@PLT`
— one tail call instead of a byte loop.

### 1.10 Tail calls
`memset_like` lowers to `tail jmp memset` with no stack frame — the frame is torn
down before the jump, reusing the caller's frame.

### 1.11 Leaf-function stack-frame avoidance
Every tiny function has no prologue at all: no `push %rbp; mov %rsp, %rbp`, no
`subq $N, %rsp`. GCC proves nothing needs memory, keeps everything in registers,
and emits just the body + `ret`.

### 1.12 No redundant moves
`square(x)+square(x+1)` is inlined and scheduled in-place; `leaf(a,b)*2` →
`leal(%rdi,%rdi,2); subl; addl %eax,%eax` (add self, no mov-then-add). A return in
`%eax` that is already in `%eax` emits no move (`f2i` → bare `ret` when the input
and output registers already match).

### 1.13 Constant materialization
Small constants are immediates in the ALU op or a single `movl $imm, %eax`.
Float constants come from a constant pool (`.rodata.cst4` + RIP-relative
`addss .LC0(%rip), %xmm0`) — never a `movq $0x3F800000` + `movq2xmm` dance.

### 1.14 Pointer arithmetic folding
`a[i*stride+j]` → `imull %ecx,%esi; addl %edx,%esi; movslq %esi,%rsi; movl (%rdi,%rsi,4),%eax`
— the index is sign-extended once and the SIB form does base+index*4 in the load
itself. GEP with constant offset → displacement, no `lea` at all when nothing needs
the address itself.

## Section 2 — Audit of our backend

Verdict legend: **good** (we match GCC), **partial** (exists but narrow/incorrectly
gated), **naive** (missing / always-64-bit / wrong-width).

| GCC behavior | Our emitter | Evidence |
|---|---|---|
| Width-correct mnemonics | **naive**: every arithmetic path copies with `movq` and uses the 64-bit op; the width-argument `lOp` is accepted but never emitted. | `emitBinOp` — x86_64_base.crl:2078 (always `movq`, always `qOp`; callers pass `"addl"` etc. but it is dropped). `emitDiv`/`emitRem` — x86_64_base.crl:2098/2125 (always `%rax`/`cqo`/`idivq`). `emitShift` — x86_64_base.crl:2152 (always `movq`, `%cl` op, 64-bit). `emitUnOp`, `Neg`, `Not`, `emitICmp` — x86_64_base.crl:2173, 1747-1768, 2244 (always `movq`/`notq`/`negq`/`cmpq`). |
| `xor reg,reg` for zero | **partial**: only `x*0` gets `xorq dst,dst` (64-bit, wrong for 32-bit) and only when `src1`/`dst` aliases are handled; general `x^x`, zero-return, and `%edx`-zeroing before unsigned div are absent. | x86_64_base.crl:876-889 (`iselEmitMulConst` `c==0` → `xorq`), x86_64_base.crl:3109 (xor is only used to zero the vararg xmm count, i.e. by hand). |
| `lea` for add/scale | **partial**: standalone `emitGep` uses `leaq` with base,index,scale — but emits scale 8 for anything it cannot classify and never uses `leaq` for plain `add`; no `lea` for `imul` by 1/2/3/5/9 by the ALU paths. | `emitGep` — x86_64_base.crl:2219-2243. |
| Add folding into load/store address (op-with-memory-source) | **partial**: `iselTryFoldLoadOpStore` covers `load→op→store` same-address for add/sub/and/or/xor with widths 8/16/32/64 (x86_64_base.crl:1378-1446) — but there is no fold for "use memory operand as ALU source" (`addl (%rdi), %eax` where the value is used once), so arithmetic loads a register copy first. | `iselTryFoldLoadOpStore` gate `loadInst->ops[0] != addrVal` — x86_64_base.crl:1422; no equivalent for a bare Load+Op use. |
| Store constant to memory | **naive**: `store i32 %c, p` copies the constant into a register first, then `movl` to memory. No `mov $c,(%r)` and no `add $c,(%r)` folding. | `emitStore` / `emitStoreWidth` — x86_64_base.crl:2200-2210, 1253-1296. |
| GEP+load/store folding (disp + SIB) | **partial**: `iselTryFoldGepLoad`/`GepStore` exist (x86_64_base.crl:1447-1568) but only when the GEP has a *register* index with scale 1/2/4/8 and no constant displacement — a struct field `p->y` (constant offset) never folds to `movl 4(%rdi), %eax`; it still materializes a separate `leaq` + load. | x86_64_base.crl:1447-1506 (fold requires `addrInst->nops >= 3` and uses idx register + hard-coded scale 4 in `(base, idx, 4)` — no disp/literal index path). |
| `test` vs `cmp $0` | **good** for the literal-0 rhs case only: `iselTryFoldCmpZero` covers `icmp x, 0` (x86_64_base.crl:1570-1589) — but `emitCondBr` unconditionally emits a fresh `testq cond,cond` even when `cond` is already an `icmp` result (so compare+branch
work), and a general "reuse incoming flags" is absent. | x86_64_base.crl:1570, 2327-2345. |
| xor-zeroing result registers before `setcc` | **naive**: `emitICmp` uses `%al` without zeroing it first and moves with `movzbq %al, dst` — fine, but compared to gcc's `xorl %eax,%eax; setl %al` it leaves `%rax` upper garbage semantics unhandled and has no path to reuse. Minor. | x86_64_base.crl:2244-2265. |
| `cmov` for small selects | **partial**: `emitSelect` emits `testq cond,cond; cmovne src1; cmovz src2` (x86_64_base.crl:2955-2984) — correct skeleton but 64-bit unconditional (`dst` never truncated to 32-bit), and it forgets that both operands must be materialized; GCC's `cmp; mov; cmov` form avoids one partial-flag idiom. | `emitSelect` — x86_64_base.crl:2955; compare-driven cmov from an `icmp` predicate is not used (gcc maps max/min select to `cmp`+`cmov` directly). |
| Sign/zero-extension folding into loads | **good**: `iselTryFoldExtLoad` emits `movzbl/movzwl/movsbl/movswl/movslq` directly from memory (x86_64_base.crl:1298-1377). | — |
| Constant-divisor magic multiply | **partial**: pow-2 only (`iselEmitSDivPow2`/`iselEmitUDivPow2`, x86_64_base.crl:1085-1140) and divmod.crl fuses div+rem into mul/sub; general constant-divisor magic-multiply (GCC's `imul`+shift sequence for 7, etc.) is absent — non-pow2 constants fall to `idivq`. | divmod.crl:1-15 (fuse only); x86_64_base.crl:1085, 1118; generic `emitDiv` at 2098. |
| Branch layout / inversion | **naive**: `emitCondBr` always jumps to the true target and falls through to an unconditional `jmp` of the false target (x86_64_base.crl:2327-2345); no hot/cold ordering, no flag reuse. Passes `branch_inversion.crl`, `branch_factoring.crl`, `branchprop.crl`, `tail_dup.crl` exist in `passes/` but there is no evidence of wiring into the x86 emitter's block ordering. | x86_64_base.crl:2327-2345; passes/branch_inversion.crl. |
| Tail calls | **partial**: `isTailCall` exists and is *wired into* `emitRet` (x86_64_base.crl:788-840, 2927-2953), requiring no frame, no callee-saves, non-Windows, direct ret value; a `tco.crl` pass also exists. But it misses calls through values not kept in `lastCallTarget`/`lastCallResult` (e.g. any call in an earlier block of a function with multiple rets), so coverage is thin. | x86_64_base.crl:2927, 786; passes/tco.crl. |
| Leaf-function frame avoidance | **unknown/partial**: prologue emission at x86_64_base.crl:403-730 sets `currentFuncHasFrame` — need to verify every function without allocas skips it; `emitAlloca` unconditionally does `subq $8, %rsp` *per alloca* with no dedicated slot (x86_64_base.crl:2211-2218), so any alloca forces a frame-ish stack walk. | x86_64_base.crl:2211-2218. |
| Redundant move elimination | **naive**: `emitBinOp`, `emitShift`, `emitDiv`, `emitCast`, `emitRet` all `movq` whenever `src != dst` string-compare says so — which is true after register allocation *for the copy of the operand into the op*, not a real coalescing pass; no peephole removes `movq %rax, %rax` sequences across isel folds (`movq rax; movq r10, rax; addq...` is common in generated code because every op copies its first operand). | x86_64_base.crl:2078-2096, 2152-2171, 2244-2265. |
| Constant materialization | **partial**: immediates for ALU ops exist (`iselIsConstInt` gate at x86_64_base.crl:859); float constants via data section (good). But `ret 0`/generic zero paths have no `xor-zeroing` and constants loaded via `movq $` without a `movl $, %eax` 32-bit fast path anywhere in the generic emitter. | x86_64_base.crl:859, 1167-1170. |
| memset-loop → memset call | **partial**: `idiom.crl` exists; `memset_like` would want a single `tail jmp memset` — no direct evidence the isel path emits it; the IR-level idiom pass may, but the emitter has no loop-idiom lowering of its own. | passes/idiom.crl (not reviewed line-by-line here); emitter has no equivalent. |
| 32-bit shift/div clobber correctness | **naive (correctness-relevant)**: `emitShift` and `emitDiv` sign-extend through `%rax`/`cqo` unconditionally — for an i32 that still holds the old upper 32 bits cleared only if a 32-bit write zeroed them, but the emitter's own other paths don't guarantee that after `movq`-only copies; the type-safe thing is `cltd/idivl` with 32-bit registers. | x86_64_base.crl:2098-2150, 2152-2171. |
| `imulq` clobbering for 64-bit mul | **partial**: `Mul` always assumes three-operand `imulq src2, dst` — good; but no `lea` form for `*2/*4/*8` (gcc does `leal` for powers of two — minor). | x86_64_base.crl:1754-1762. |

## Section 3 — Prioritized fix list

Ordered by expected value (correctness first, then speed on typical code, then size).

1. **Width-aware mnemonic selection (i32/i16/i8) in all ALU paths.**
   Naive: every op copies with `movq`, always uses the 64-bit op (`addl` passed but ignored).
   Target: pick by `inst->base.type->width` like `emitLoadWidth`/`emitStoreWidth` already do —
   `movl`/`movl`+`addl`/`subl`/`imull` for 32-bit, `movw`/`movb` for 16/8, `movq` only for 64-bit.
   Change: `emitBinOp`, `emitDiv`/`emitRem` (use `cdq`+`idivl` for i32, `cltd/divl` unsigned),
   `emitShift` (emit `%cl` with `shll/sarl/shrl` for i32), `emitUnOp`, `Neg`/`Not`, `emitICmp`
   (`cmpl`/`cmpw`/`cmpb`), `emitSelect`/`emitCondBr` (`testl`).
   Win: correctness (64-bit ops on 32-bit data can silently change semantics after
   partial-register clobbers) and ~2× smaller on i32-heavy code; this is the single
   biggest audit finding.

2. **Compare-flags reuse + one instruction from compare to branch.**
   Naive: `emitICmp` materializes via `setcc` into a register, then `emitCondBr`
   re-tests it (`testq cond,cond`), an extra block of instructions; no inversion.
   Target: directly from `icmp`+`condbr` on the same value, emit `cmpl %es, %edi` +
   `jl/jge/...` — one fused compare+branch, true-target laid out as the hot fall-through
   or after an inversion pass.
   Change: isel fold `ICmp` feeding `CondBr` (cond consumed only by branch) +
   block-layout pass that orders hot successor as fall-through; plumb
   `branch_inversion.crl`.
   Win: 2–4 fewer instructions per branch, better PDE prediction; small/medium.

3. **GEP displacement folding into memory operands for constant offsets.**
   Naive: `iselTryFoldGepLoad/GepStore` only handle register index * scale; every
   struct field (`p->y`, `p->z`) materializes `leaq` + separate load even though the
   offset is a constant that fits the disp field.
   Target: fold `Gep(base, constOffset)` → `movl N(%base), %eax` / `movb N(%base), %r8b`;
   fold `Gep(base, idx)` with element size → SIB `(base, idx, scale)` plus disp for the
   constant part; reserve `leaq` for when the address is itself the result.
   Win: 1–2 instructions per field access, less register pressure; medium.

4. **Op-with-memory-source fold (load-op as single ALU op with memory operand).**
   Naive: a load used once by an arithmetic op goes through a register, then the op.
   Target: `sull = load p; x = sull + k` → `movl (%r), %eax` folded to
   `addl (%r), %eax` — same shape as GCC's `addl (%rdi), %eax` in reduction loops.
   Change: isel hook on ALU op whose operand is a single-use Load; reuse the same
   same-address discipline as `iselTryFoldLoadOpStore`.
   Win: 1 instruction per folded op, smaller loops; medium.

5. **Magic-multiply for constant divisors (any constant, not just pow2).**
   Naive: only pow2 divisors (`iselEmitSDivPow2`/`iselEmitUDivPow2`) and divmod.crl
   div+rem fusion; all other constant divisors emit full `cqo`+`idivq` (and 64-bit!).
   Target: GCC's Granlund–Montgomery sequence — for nonzero constant `d`, precompute
   `M = ceil(2^(32+L)/d)` etc., emit `movslq $M`+`imulq`+`shrq`+adjust; reuse for u32.
   Change: new isel helper `iselEmitDivConstMul` used from the `trySelect` dispatch in
   `Add..Lshr` (x86_64_base.crl:1171-1216), plus width-correct 32-bit variant.
   Win: replaces ~20–40-cycle `idiv` with ~3-cycle multiply+shift in divisor-heavy
   code; medium-high on such loops.

6. **xor-zeroing for 0-valued definitions and div/rem's `%edx`.**
   Naive: `x*0` → `xorq` (64-bit; wrong width for i32); `emitDiv/emitRem` unsigned
   paths never zero `%rdx` (they sign-extend blindly via `cqo`, which is only right
   for signed).
   Target: `ReturnInst(0)`/zero constants → `xorl %eax,%eax`; unsigned div/rem →
   `xorl %edx,%edx`; width the xor with the op width.
   Change: emitter const-materialization path + width-aware `emitDiv`/`emitRem`.
   Win: correctness for unsigned div/rem on 32-bit; also a cycle or two less dep chain.

7. **`cmov` directly from icmp; width-aware `emitSelect`.**
   Naive: `emitSelect` always `testq cond,cond; cmovne; cmovz` with 64-bit moves.
   Target: when select condition is an icmp, fuse to `cmpl; movl %esi,%eax; cmovle`;
   use `cmovl` (etc.) keyed off the real predicate, width-correct.
   Change: isel fold on Select whose cond is a single-use ICmp; pass the predicate's
   width through.
   Win: removes the test idiom and a register copy; small.

8. **Constant-to-memory stores/loads (`mov $c,(%r)` / `mov $c,%reg` with no movq dance).**
   Naive: constants are loaded to a register, then stored; no `movl $42, (%rdi)`.
   Target: `store i32 %c, p` → `movl $c, (%r)`.
   Change: `emitStoreWidth` checks if `inst->ops[1]` is a `ConstInt` and emits the
   immediate form.
   Win: one fewer mov per store; small.

9. **Tail-call coverage.**
   Naive: `isTailCall` only catches `ret v` where `v` is the very last call's result
   and the frame is empty (x86_64_base.crl:2927-2953). Any earlier-block calls or
   a single stray alloca disable it.
   Target: reuse the IR TCO pass to rewrite `ret call` → tail form before emission,
   and make `isTailCall` walk through simple cleanup blocks.
   Win: O(1) stack for recursive wrappers and memset-style thunks; small but free.

10. **Frame avoidance for alloca-less functions; one slot per alloca, not `subq $8` each.**
    Naive: `emitAlloca` emits `subq $8, %rsp; movq %rsp, dst` per alloca (leaky — no
    restore), forcing ad-hoc frame handling.
    Target: compute frame size once in prologue from the stack_layout pass, give each
    alloca a fixed `[-N](%rbp)` slot, leaf functions emit no frame.
    Win: correctness of frames and 1–2 instrs per function; medium.

11. **`lea` for constant-indexed adds instead of `imul`+add, and `negq`/`notq`/`movq` width fixes.**
    Covered by fix 1 (width) and fix 3 (lea for gep). Additionally make `imul`-by-2/4/8
    use `leaq`.

12. **Loop-idiom lowering for memset/memcpy in the emitter or a guaranteed idiom pass.**
    Naive: byte-store loops compile as literal load/cmp/store blocks.
    Target: GCC's single `tail jmp memset`.
    Change: verify `idiom.crl` runs before isel for hot loops; otherwise lower
    recognizable write-loops in the emitter pass through a helper.
    Win: large for such loops (vectorized memset vs byte loop).

## Notes

- All audit citations refer to `lib/wallvm/target/x86_64/x86_64_base.crl` unless
  named; the 32-bit port `lib/wallvm/target/x86/x86_base.crl` already uses
  32-bit mnemonics for binary ops (`Add => emitBinOp(inst, "addl")`, x86_base.crl:448-460)
  but still routes through a 64-bit-style `movq`-free skeleton — its div/shift/icmp
  paths mirror the 64-bit emitter's blind spots (x86_base.crl:508, 587, 630).
- `divmod.crl` fuses div+rem into mul/sub and `tco.crl`, `branch_inversion.crl`,
  `select_to_branch.crl` etc. exist at IR level; several are not currently fed into
  the x86 emitter path, so the wins they represent (fix list items 5, 2, 7, 9) appear
  to be unused in practice.
