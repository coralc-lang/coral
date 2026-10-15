# Session Todos

Working list for the WallVM assembler + std cleanup session.
Verify with `python3 coral-docs/check_crl.py <files>` (balance only).
Never touch: `compiler/**`, `bootstrap/**`, `.probe/`, `HANDOFF.md`, `lib_old/**`.
Another opencode instance works this tree — re-read files before editing.

## Session policy (standing decisions)

- **std error handling**: public fallible APIs return `Result<T, E>` / `Option<T>`
  (from `std::result` / `std::option`); error types carry errno/detail.
  Low-level pointer-style APIs (mman alloc/free/realloc, memory intrinsics)
  keep rawptr/null — pointer is the right contract there.
- **No `static` on free functions** anywhere in `lib/` — non-pub is already
  file-local; the modifier is noise. (`static` on *variables* stays: C codegen
  needs it for external-linkage avoidance. `static` methods inside
  `extend`/`variant` blocks stay: they mean no-self.)
- **compiler/ and bootstrap/ are off-limits** — not our business, not the
  business of any spawned agent (read or write).
- Goldens: system `as`/`objdump`/`gcc`/`readelf`/`nm`/`ld` allowed; repo
  compilers are not (PORTING_RULES §0.5).

## Completed (this session)

- [x] RIP reloc addend: `emitRm` takes `immTail`; wdisp/reloc use
      `disp - 4 - immTail` (x86_64.crl:576/601-614; vector sites
      x86_avx.crl:535-545, 642-644). setcc temp path verified correct as-is.
- [x] AVX shift-imm group opcodes: `ext` field on VecRow (255=none), all ~182
      rows updated; 8 shift-imm rows now VFS_XRM_V on 0F 71/72/73 /2 /4 /6,
      gas-verified (`c5 e9 71 f1 02` etc).
- [x] vpermq/vpermpd → VFS_XRM_I (0F3A 00/01, ymm-only, gas-verified).
- [x] vextractf128 vsize from widest source register (ymm rm + xmm dst).
- [x] vmovq W1 3-byte VEX confirmed covered by X86Vex two-byte shortcut
      (`two = mmmmm==1 && !w && !x && !b`, common.crl:369).
- [x] AVX/AVX2/FMA3 vector table (~182 rows) + VEncLegacy + vecSigOk
      dstCls/rmCls; FMA3 goldens match gas.
- [x] MMX/string/fence/loop arms, DirEnt 14-17, emitStringLits, weak/vis
      ELF+COFF, lexQuoted, prefix flags, imul/control rows, RcMmx+mm0-7,
      module wiring.
- [x] Legacy encoder CRITs all fixed (size inference, 64-bit ALU, byte-opcode
      adjust, movq imm desync, shiftTab, shift-by-CL D2, imul 2-op, xchg,
      cmpxchg8b, FS_AI rows + early-return, size-guard, pause F3,
      splitMnemonic isFullMnem guard, VFS_NONE dispatch, lea reg-rm reject,
      vmovd/vmovq rmCls/dstCls, vpxor sizes, jecxz/jcxz 0x67).
- [x] asm/common.crl sibBase index-only SIB; COFF reloc offsets;
      emitRaw Abs32.
- [x] check_crl PASS on x86_64.crl, x86_avx.crl after every batch.

## In progress / next up

### 1. Static strip (lib/ free functions) — IN PROGRESS
Strip `static` from top-level free-function declarations in
`lib/std`, `lib/wallvm`, `lib/core`, `lib/platform` (both platform trees).
Keep: `static` variables/tables, `static` methods inside type blocks.
Then check_crl every changed file.

### 2. std error-handling refactor — AGENT
Convert public fallible APIs to Result/Option across `lib/std` (linux +
windows mirrors). Policy above. Scope highlights:
- io/fs: `fileOpen` → `Result<File, IoError>` (errno), `readFileToString` →
  `Result<String, IoError>` (no more silent-empty), stat/rename/mkdir etc.
- io/net, io/process, io/cmd, io/temp, io/path, io/env, io/term, io/log,
  io/bio, io/fios, io/ios: audit every null/-1/empty-string failure path.
- parser/*: malformed input → `Result<T, ParseError>` (line/col/msg);
  keep Option only for genuine "absent".
- collections: null gets → Option (map/hashmap/tree/cache partly done).
- concurrent/async: null Future* paths → Option.
- memory: allocators stay pointer-based; pool/arena init failures may use
  Result where user-facing.
- Update all in-repo call sites, including
  `lib/wallvm/linker/x86/link.crl` (imports fileOpen/fileRead/...).
- Do NOT change: `std::text::string` String API, ios::println/eprintln,
  anything imported by `lib/std/testing` unless signature-compatible.

### 3. WallVM front-end parser fixes — AGENT
All OPEN findings in `lib/wallvm/asm/common.crl` (+minimal elsewhere):
- CRIT: `*` indirect marker dropped (`call *foo` encodes direct;
  asm/common.crl:353,473).
- `.` not allowed in operand identifiers (`.L4` labels).
- `sym+N` addend dropped on Rel path; `$sym+N` rejected.
- parseMask not called after mem operands (AVX-512 mask suffixes).
- Char literals `'a'`; leading-zero octal; segment overrides `%fs:`.
- @PLT buffer leak; lexQuoted free-on-error.
- Undefined syms should become global (weak/global policy).

### 4. WallVM legacy SSE table — AGENT
~150 rows: movaps/movups/movapd/movdqa/movdqu/movss/movsd/movd/movq,
packed arith (padd*/psub*/pmul*/pand/por/pxor/andn), cvt family,
comiss/comisd/ucomi, shufps/shufpd/pshufd/pshuflw/pshufhw, punpck*/pack*,
pextrw/pinsrw/movmskps/pmovmskb, SSSE3/SSE4 via 0F38/0F3A.
New file `lib/wallvm/asm/x86/x86_sse.crl` + wiring in matchAndEncode;
verify against gas goldens; check_crl after.

### 5. WallVM remaining encoder nits — LATER
- imm-form sigOk width check (reject imm not fitting row.immW) — parked.
- Legacy SSE branch opcode+tail emission verification.

### 6. Sections refactor + new directives — LATER
AsmObject dynamic ELF/COFF shdrs; `.section` arbitrary, `.comm/.lcomm/
.set/.equ/.local`, DWARF `.byte` passthrough; COFF/Win32 `.def/.endef/
.scl`, `.seh_*` ignored.

### 7. Linker CRITICALs — LATER (after std fs API lands)
- link.crl driver API-stale (arg counts :294/:300/:314, no OutFmt/Imports;
  lib.crl missing coff/pe/archive/imports exports).
- pe.crl optional-header 4-byte field drift (:349-361) + stale 8-section
  table vs layout's 10.
- COFF reloc constants wrong vs winnt.h.
- object.crl string-table OOB.
- GOTPCREL not relaxed/rejected.

### 8. Wrap-up — LATER
- Audit WallVM codegen mnemonic list vs assembler coverage.
- Gas golden fixture suite under a fixtures dir.
- Re-deploy verification agents until clean.
- Update `lib/wallvm/docs/assembler-plan.md`.
- Reconcile PORTING_RULES "keep static helpers" line with new no-static-fn
  policy (ask owner before editing PORTING_RULES).
