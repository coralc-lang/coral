# Session Todos

Working list for the WallVM assembler + std cleanup session.
Verify with `python3 coral-docs/check_crl.py <files>` (balance only).
Never touch: `compiler/**`, `bootstrap/**`, `.probe/`, `HANDOFF.md`, `lib_old/**`.
Another opencode instance works this tree — re-read files before editing.

## Session policy (standing decisions)

- **std error handling**: Result/Option conversion is SELECTIVE, not blanket.
  Result<T, E> only where failure is real/differentiable and the caller
  needs the reason; Option<T> only where absence is a normal outcome;
  otherwise leave the plain type. "Too simple to justify a wrapper" →
  plain (probes → bool, ignored failures → void, total fns → plain).
  Low-level pointer-style APIs (mman alloc/free/realloc, memory intrinsics,
  Allocator fn pointers) keep rawptr/null — pointer is the right contract.
- **Platform parity is first-class**: every public API in std for each
  platform must have a direct equivalent on the other side — same name,
  params, return type (including E). Internals may differ by syscall;
  representation types (File i32 vs rawptr) may differ but must be named
  identically in signatures. Genuine platform-by-nature gaps get a
  documented one-line justification.
- **No `static` on free functions** anywhere in `lib/` — non-pub is already
  file-local; the modifier is noise. (`static` on *variables* stays: C codegen
  needs it for external-linkage avoidance. `static` methods inside
  `extend`/`variant` blocks stay: they mean no-self.)
- **compiler/ and bootstrap/ are off-limits** — not our business, not the
  business of any spawned agent (read or write).
- **GIT IS USER-ONLY**: agents never run git mutations (add/commit/restore/
  stash/reset/revert). User's commits are ground truth — agents edit forward,
  never revert another agent's committed work.
- **char is utf32** — the coral character type is a 32-bit codepoint; std
  support is currently thin (see item 8).
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
- [x] Static strip: `static` removed from 525 free-fn lines / 77 files in
      lib/; methods+variables untouched; check_crl PASS.
- [x] Result::andThen Ok{error}→Ok{value} binding bug fixed (both platforms).
- [x] WallVM legacy SSE table: new `lib/wallvm/asm/x86/x86_sse.crl`
      (255 rows: moves, packed arith, logic, cvt, comis, shuf, SSSE3,
      SSE4.1; SSE/SSSE3/SSE4 escapes 0F/0F38/0F3A), wired after tryVecTable;
      341/341 gas golden bytes match; check_crl PASS.
- [x] WallVM front-end parser fixes (all 10 findings): `*` indirect marker
      (call *foo FF /2 now correct), leading-dot labels `.L4`, sym+N addend
      (Rel + $imm), parseMask after mem, char literals, octal 0NNN,
      segment overrides %fs:, @PLT zero-alloc slices + stripAt at all
      reloc sites, undefined syms → global binding at ELF/COFF writers,
      lexQuoted free paths. check_crl PASS on common/x86_64/obj.
- [x] std io Result/Option conversion (selective, both platforms):
      IoError{Os|Eof|BadUsage} in fs.crl; fileOpen/read/write/seek,
      readFileToString, dir/file mutators, net, process, bio, fios, temp
      → Result; env get/commandLine/statPath → Option; probes/close/path
      pure fns left plain. ios.crl locked. link.crl already consumes
      Results. check_crl PASS.
- [x] PARITY AUDIT round 1 — all three scopes green:
  - io/parser (42 files): 139/139 pub fns identical; fixed 3 latent windows
    bugs (term.crl GetConsoleMode + temp.crl CreateDirectoryA missing
    imports, ios.crl `typeof` vs `@typeof`); Result-count "gaps" were
    body-internal false alarms; strip table: all KEEP (wrappers justified).
  - collections/concurrent/memory (10 files): windows **async.crl was
    missing entirely → ported** (Win32 fibers, 710 lines, +5 externs in
    lib/platform/win32.crl) + `pub mod async` export; mman
    `Arena.remaining` const-self drift fixed; mimalloc page-aliasing bugfix
    ported to windows; STRIPPED async.poolRun/AsyncChannel.recv
    Option→Future*, SmartPtr/SharedPtr.init Result<bool>→bool;
    mman rawptr contract verified intact; Result counts now symmetric.
  - rest of std (56 files): 91/91 file pairs, 28/28 signature pairs SAME;
    no one-sided Result/Option anywhere; only justified exceptions (Win32
    consts, BCryptGenRandom entropy, representation types); linux lib.crl
    comment synced → byte-identical.
  - Re-verified by orchestrator: all 14 changed files check_crl PASS.
- [x] char (utf32) std support:
  - `core/char_util.crl`: charIsValid/IsAscii/IsDigit/IsAlpha/IsAlnum/
    IsUpper/IsLower/IsSpace/IsControl/IsPrint, charToUpper/ToLower (ASCII
    bounds honest), charToU32/FromU32/TryFromU32 (rejects surrogates,
    >U+10FFFF), charEncodeUtf8 (strict, 0=invalid), charDecodeUtf8
    (bounded, U+FFFD policy).
  - `core/str.crl`: str::nextCodepoint(usize* idx, char* out),
    str::codepointCount().
  - `std::text::string`: String::pushCodepoint/nextCodepoint/
    codepointCount (both platforms, byte-identical).
  - `std::text::utf8`: nextChar → Option<char> (None = input exhausted
    only), encodeChar → String.
  - `std::fmt`: formatChar.
  - ios.crl internals: `char` prong in _fprintOne + {:d}/{:x}/{:b} for
    char — `println("{}", c)` now works; NO pub signature changes (ios
    pub sigs verified identical both platforms, attribute-stripped).
  - Policies: decode = U+FFFD replacement + 1-byte advance; encode =
    strict at core, U+FFFD substitution at convenience layers.
  - No full Unicode tables (ASCII-only, documented in code) — deliberate.
  - check_crl PASS; runtime-verified 40+ assertions (compile+run probes).

## Known pre-existing bugs (found during char work, NOT ours, NOT fixed)

- **`vaprint` silence bug** — va-args print variant emits nothing; reproduces
  at HEAD (owned by io/** historically).
- **io/fs C-codegen typedef ordering** — breaks linking programs that pull
  `std::io` lib reexports; reproduces at HEAD. `import(lib) std::io::ios`
  alone links fine.
- `.probe/io*.crl` stale vs Result-based fs API (.probe off-limits).

## In progress / next up

### 1. Static strip — DONE (see Completed)

### 2. std error-handling refactor — DONE + AUDITED (see Completed)
Conversion landed, then audited against the selective rubric; io/parser
kept all wrappers (justified), collections/memory had 3 strips. Parity
proved. Remaining follow-ups are below, not in this item.

### 3. WallVM front-end parser fixes — DONE (see Completed)

### 4. WallVM legacy SSE table — DONE (see Completed)

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

### 8. char (utf32) std support — DONE (see Completed)

### 9. Wrap-up — LATER
- Audit WallVM codegen mnemonic list vs assembler coverage.
- Gas golden fixture suite under a fixtures dir.
- Re-deploy verification agents until clean.
- Update `lib/wallvm/docs/assembler-plan.md`.
- Reconcile PORTING_RULES "keep static helpers" line with new no-static-fn
  policy (ask owner before editing PORTING_RULES).
- Verify stale `.probe/io*.crl` against Result-based fs API (read-only note;
  .probe is off-limits).
