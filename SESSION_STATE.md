# Session State — 2026-10-17

Repo: coralc @ HEAD `5dc32ad` + uncommitted frontend/build changes (below).

## Update — 2026-10-18: language server milestone (`coralc --serve`)

- `compiler-new/coral-lsp/server.crl` speaks real LSP on the **std API only**
  (`std::io::fs` `readFileToString`, `std::io::ios` `print`/`readChar`) — no
  `platform::libc`, no stdout diversion. Builder and build-file parser gained
  `quiet` flags so the protocol owns stdout.
- PROTOCOL.md conformance: `-32002` before `initialize`, second `initialize`
  `-32600`, malformed JSON `-32700`, non-object `-32600`, exit codes (0 after
  `shutdown`, 1 without, clean EOF), `didClose` clears markers, diagnostics
  and hover positions in UTF-16 code units.
- Hover returns real types via `Expr.resolvedType`; `checkIdent`
  (coral-semantics/expr.crl) now sets it on ident expressions — semantics
  change, selfbuild-verified identical.
- **Whole-project error report**: `didOpen` analyzes the build entry and
  publishes per-file diagnostics for the whole import closure; files that
  stop having records are cleared; relative analyzer paths are anchored at
  `initialize`'s `rootUri`.
- Lineage: fullbuild31 + selfbuild31 rc=0, `cmp` **IDENTICAL** (C 2542959 B;
  self-built stripped binary 794224 B). Installed to `~/.coral/bin/coralc`
  (sha256-verified).
- Tests: `/tmp/opencode/lsp_conform.py` 13/13 (lifecycle, exit codes, UTF-16
  columns, b.crl error while clean a.crl open, didClose clear, `-32601`,
  stderr silent); hover regression PASS; `coral-vscode/tools/test-live-server.js`
  9/9 against the installed binary; single-file compile strace: gcc invoked
  `-x c -` (stdin pipe, no `.c` on disk), rc=0.
- Docs synced across coralc/coral-vscode/coral-zed: `PROTOCOL.md` §12 current
  state, `LANGUAGE-SERVER.md` compiler section.

## Milestone: self-hosting achieved

`compiler-new` builds itself to a stable, byte-identical fixpoint under the
new libc-default allocator:

- bootstrap: `python3 bootstrap/coralc.py compiler/coral-frontend/coralc.crl -o build/coralc` → rc=0
  (logs: `build/bootstrap_libc.log`, `build/bootstrap_memcpy.log`; stage0 `build/coralc` 625464 B)
- fullbuild (stage0 builds compiler-new): rc=0, `build/fullbuild17.log`,
  emits 2278148 B C; saved `/tmp/opencode/fullbuild17_coralc.c`
- selfbuild (compiler-new builds itself): rc=0, `/tmp/opencode/selfbuild12.log`
- `cmp fullbuild17_coralc.c compiler-new/build/coralc.c` → **IDENTICAL**
  (stable fixpoint; G2 self-built binary `compiler-new/build/coralc` 834720 B)
- self-built compiler builds `/tmp/opencode/matest` → **ALL PASS** (t1–t4)

Re-verified after the memcpy UB fix (same-day later lineage, fixes included):

- gen1 (18:12): stage0 → compiler-new, C matches fullbuild17
- fullbuild18: rc=0, emits 2278512 B C (`/tmp/opencode/fullbuild18_coralc.c`)
- selfbuild18 + gen3b: rc=0, `cmp` IDENTICAL each time — three-gen fixpoint
- ASan+UBSan full compiler build: **0 findings**, emitted C identical
- valgrind (glibc-debug installed): **0 errors** on full matest build; matest
  app itself → ALL PASS

Latest lineage (after the global-lib fallback in `analyze.crl`):

- fullbuild19 + selfbuild19: rc=0, `cmp` **IDENTICAL** (emits 2280236 B C,
  binary 834792 B) — this is the compiler installed to `~/.coral/bin`

Later lineage (`coralc init` + `.gitignore` feature):

- fullbuild20 + selfbuild20: rc=0, **IDENTICAL** (emits 2285935 B C) —
  `coralc init` wired into the dispatch
- fullbuild21: rc=0 (emits 2286138 B C) — `init [dir]` positional accepted
- fullbuild22: FAILED (ternary `needsNl ? 1 : 0` mixed i32 with usize);
  superseded, log kept
- fullbuild23 + selfbuild23: rc=0, **IDENTICAL** (emits 2290087 B C, binary
  839344 B) — `.gitignore` handling + `**/.coral/` pattern; matest rebuilt
  with this binary → ALL PASS
- fullbuild24 + selfbuild24: rc=0, **IDENTICAL** (emits 2300923 B C) — `opt`
  + `--opt`, task evaluation, `coralc run`/`coralc <task>`; self-built binary
  now 1389352 B because opt=debug finally applies `-g` (C text unchanged)
- `~/.coral` install (fullbuild19 lineage) **predates** `init`; per standing
  instruction it is only refreshed when a milestone completes

## Last-commit contents (efc7996, source files)

- `compiler-new/coral-backend/codegen.crl`, `compiler/coral-backend/codegen.crl`:
  switch-case `break` fix — break now targets the switch via `goto __Lsw<n>`
  label (break-target stack: `breakKinds`/`breakLabels`/`breakDepth`/`switchSeq`,
  `cgPushLoop`/`cgPopLoop`/`cgPushSwitch`/`cgPopSwitch`), matching the python
  reference's real C `switch` semantics (`bootstrap/codegen.py:550`).
  This was the root cause of the broken self-build (plain C `break` in an
  if-chain escaped the enclosing loop).
- `compiler/coral-frontend/compile.crl`, `compiler-new/coral-frontend/compile.crl`:
  `codeHasMain` now accepts `void main(` in addition to `int32_t main(`
  (helper `codeHasSlice`).
- `compiler-new/coral-semantics/analyze.crl`: `libMerge` `j++` fix; preloads for
  `std::Result` / `std::arr` commented out as stubs (see Pending).
- `compiler-new/coral-build/builder.crl`: stale/fresh build prints commented out.
- `lib/std/x86_64/linux/memory/allocators/mimalloc.crl`: 5 allocator fixes
  (see below).

## Uncommitted changes (as of this update)

- `compiler-new/coral-frontend/init.crl` (new, staged) — `coralc init`
- `compiler-new/coral-frontend/tasks.crl` (new) — task runner
- `compiler-new/coral-frontend/args.crl` — `init [dir]` positional, `--opt`,
  `Command::Task`, usage lines
- `compiler-new/coral-frontend/coralc.crl` — wire `runInit`/`runTask`; run
  executes task "run" (fallback: output binary); `coralc <task>` runs any task
- `compiler-new/coral-frontend/compile.crl` — `opt` → gcc `-O0 -g` / `-O2` /
  `-Os`
- `compiler-new/coral-build/builder.crl` — `opt` field (validated: debug/
  release/size, else E1000) + task table (name/exec/output/after) +
  `bTaskIndex`
- `compiler-new/build/{coralc,coralc.c}` — fullbuild24 artifacts
- `print.crl` (repo root) — user's own edit, untouched by this session
- `compiler-new/.coral/cache/` — untracked build cache (not ignored)

Previously uncommitted allocator/runtime-shim + shim work is now in commits
`a10a6fa` and `5dc32ad`; that set was:

1. `lib/std/x86_64/windows/memory/allocators/mimalloc.crl` — mirrored the same
   5 fixes from the linux file:
   - `MI_SIZE_CLASS_SMALL[129]`: leading `0,` entry (off-by-one shift;
     size 128 previously mapped to class 0 → 8-byte block → realloc data loss)
   - `_miSizeClass`: drop the `129–1024` division fast path; scan
     `for (u32 i = 12; i < MI_SIZE_CLASS_COUNT; i++)`
   - alloc: huge path condition `size > MI_BLOCK_SIZES[last]`
   - free: huge-page detection `page->segment == null`
   - realloc: same-class no-op guarded by `newSize <= page->blockSize`
2. `lib/std/x86_64/linux/memory/mman.crl` — default allocator swapped to libc:
   `initDefaultAllocator()` now sets `defaultAllocator = &libcAllocator`
   (removed `_miAllocInstance.init(64 MB)`).
3. `lib/std/x86_64/windows/memory/mman.crl` — same swap (parity).
4. `lib/std/x86_64/{linux,windows}/memory/intrinsics/memory.crl` — alignment-safe
   `memcpy` (UBSan found misaligned `size_t` load/store in the 8-byte chunk
   loop; now aligns dest, then uses `usize` chunks when src is 8-aligned,
   `u32` when 4-aligned, bytes otherwise). Found via ASan/UBSan run of the
   compiler; fix verified by re-running the sanitizer build (0 findings).
5. `compiler-new/coral-semantics/analyze.crl` — global lib fallback:
   `libGlobalRoot()` = `$CORAL_HOME/lib`, else `$HOME/.coral/lib`; probed
   after project/CWD `lib` in both the normal and platform-root resolution
   paths. `compiler/` (stage0) intentionally unchanged.

All edited files pass `python3 coral-docs/check_crl.py` (PASS ×7).

## `coralc init` (new)

`coralc init [dir]` (no dir = `.`) scaffolds and refuses to overwrite an
existing `coral.crlb`:

```
<dir>/
├── coral.crlb            build "…" { root="."; entry="src"; modules=["src"];
│                         target="native-x86_64"; opt="debug"; output="build/<name>" }
├── .gitignore            ensures `**/.coral/` (any depth)
├── .coral/
└── src/
    └── lib.crl           hello main, so `coralc run` works immediately
```

`.gitignore` behavior: creates the file if absent; otherwise appends
`**/.coral/` only when no `.coral` / `.coral/` / `**/.coral/` line exists
(handles missing trailing newline).

Deviations from `coral-docs/build_sys.md` §11 (doc example is internally
inconsistent: `root="src/"` + `modules=["src"]` would look in `src/src/`):
consistent form is `root="."` + `modules=["src"]`; `src/lib.crl` gets a minimal
main (doc says empty — but that yields a non-runnable link target); the
`.gitignore` step is not in the doc.

Verified (fullbuild23 binary): fresh init → run rc=0; append to existing
`.gitignore` (with and without trailing newline); no-op when `**/.coral/`
already present; re-init refusal rc=1; `git init` + `git check-ignore -v`
confirms root `.coral/` and nested `src/deep/.coral/` are ignored via
`**/.coral/`.

## Mu projects build-system findings (2026-10-17)

Local fixes applied in `~/Documents/Mu` (uncommitted there):
- `Mu_coral/src/mu-parser/base.crl`: missing closing `}` for the top-level
  `pub extend Parser {` (line 44) — appended at EOF (brother files end `}\n}\n`)
- `Mu_coral/src/mu-json/lsp.crl`: local `Lsp self;` renamed (…self is a
  reserved keyword; only occurrence of a `self`-named local)
- `Mu_coral/coral.crlb`: added aliases `buf`, `lsp` (→ mu-json) and
  `frontend` (→ mu-frontend)

Mu_coral now reaches typecheck (was parse/import errors). Current sample:
`io.crl:8 str cmd = commandLine()` type mismatch, `fmtStr2` arg `u8*` vs `str`
(decl.crl:767), `strEq` undeclared in mu-sema, `str.endsWith` method missing.

Mu_engine (schema 2): parses fine, 18 modules mapped, 0 aliases; 3 sema
errors (`sqrt` undeclared in math; `usize * u32` operand mismatches in scene).

Build-system status in `compiler-new` (per field/feature):
- **evaluated**: include, extends (field merge, child wins), root/entry/output/
  module_map/cache_dir/target, `opt` (debug/release/size → gcc `-O0 -g` /
  `-O2` / `-Os`; CLI `--opt <level>` for single-file mode), flags/modules/skip,
  aliases, task decls (`exec`/`after`/`output`: `after` recurses into other
  tasks with "build" as an already-satisfied pseudo-dep; `output` redirects
  `exec` stdout unless it names a directory), fingerprint cache/staleness,
  `coralc map`, `coralc build` (`--force/--map-only/--dry-run`), `coralc init`,
  `coralc run` (task "run" if defined, else the output binary), `coralc <task>`
- **parsed only, not evaluated**: phase (`on`/`run`/`output`/`after`), link
  (`libs`/`flags`/`script`/`strip`), deps, profile, workspace, target/artifact
  blocks, features, env, log/metrics, hooks, test, bench, lint/format/lsp/ci/
  remote, override, task `env`/doc fields
- **not implemented**: `coralc clean`, `coralc graph`, `coralc doctor`

Mu usage that needs the parsed-only features: `link.libs` + `phase "jolt"`
(Mu_engine) — task "run" and extends are now covered.

## Global install (~/.coral)

- Layout: `~/.coral/bin/coralc` (self-built, 794224 B, selfbuild31 lineage) +
  `~/.coral/lib/**` (copy of repo `lib/`).
- Import resolution order: project `<input>/../lib` → CWD `lib` →
  `$CORAL_HOME/lib` / `$HOME/.coral/lib` → platform-root variants of each.
- Verified from `/tmp/opencode/gtest` (copy of matest, **no** `lib` symlink):
  `CORAL_TRACE_LOAD=1 ~/.coral/bin/coralc build --force` → rc=0, 25 module
  loads from `/home/cerie/.coral/lib/`, app ALL PASS.
- Refresh after source changes (from repo root):
  `cp compiler-new/build/coralc ~/.coral/bin/coralc`
  `rm -rf ~/.coral/lib && cp -r lib ~/.coral/lib`
- Pre-existing stale `~/.coral/coralc` (616968 B, top level) left untouched;
  remove it if nothing references it.

### Why libc default now

Temporary, while the system upgrade (yay -Syu) runs: keeps builds independent
of mimalloc while it soaks, and both mimalloc copies now carry all known fixes.
The mimalloc allocator itself is intact and tested — only the default changed.

### Restore mimalloc default (when ready)

In both `mman.crl` files, `initDefaultAllocator()`:

```coral
pub void initDefaultAllocator()
{
    if (defaultAllocator != null) return;
    _miAllocInstance.init(64 * 1024 * 1024); // 64 MB initial reservation
    defaultAllocator = &miAllocator;
}
```

## mimalloc fixes already in place (both platforms)

- `_miSizeClass` scan from class 12 (class 0 = 8 bytes only via table)
- huge path: only sizes above the largest class (32768) go to mmap
- free: huge pages identified by `page->segment == null`
- realloc: same-class guard `newSize <= blockSize`
- `MI_SIZE_CLASS_SMALL` shift fix (leading `0,`)

Stress coverage: `/tmp/opencode/matest` (class-boundary realloc ladder to
300000, 768-class page churn, xorshift churn, shrink/grow) → ALL PASS.

## Diagnostics status

- ASan (+UBSan): working. Full compiler build under it is clean after the
  memcpy fix (`/tmp/opencode/coralc_asan{,2}`).
- valgrind: **working** now — fixed by installing `glibc-debug` (matches
  glibc 2.44+r50) plus `export DEBUGINFOD_URLS="https://debuginfod.archlinux.org"`.
  Smoke rc=0; full matest compile → 0 errors (`/tmp/opencode/valgrind_matest*.log`).
- Leaks (valgrind, matest build): 12,426 allocs / 11,344 frees; retained
  ~19 MB per compile — `AstContext` arena 4.7 MB, `DiagnosticEngine.addFile`
  source buffers 7.2 MB, ~838 small per-decl/lookup blocks 3.4 MB. No invalid
  access; mostly process-lifetime by design, but must be addressed before
  `--serve`/LSP (long-running) work.
- rr: needs one-time `sudo sysctl kernel.perf_event_paranoid=1`; then
  `rr record ./build/coralc build --force` in `compiler-new/`.
- ptrace_scope=1 blocks attach; use gdb-from-start or rr.

## Post-upgrade checklist (after yay -Syu + reboot if glibc/core updated)

1. `timeout 900 python3 bootstrap/coralc.py compiler/coral-frontend/coralc.crl -o build/coralc`
2. `cd compiler-new && rm -rf .coral && timeout 900 ../build/coralc build --force`
   → save `build/coralc.c` (comparing against `/tmp/opencode/fullbuild17_coralc.c`
   is only meaningful if sources are unchanged)
3. `rm -rf .coral && timeout -s KILL 300 ./build/coralc build --force`
   → `cmp` the two C files → expect IDENTICAL
4. Rebuild + run `/tmp/opencode/matest` → expect ALL PASS
5. valgrind smoke (`valgrind --quiet /bin/true`) → expect rc=0 (glibc-debug
   is already installed; this only breaks again if glibc is upgraded past it,
   in which case reinstall the matching `glibc-debug`)

Note: `/tmp/opencode` artifacts may be cleared by reboot — the fullbuild C
can be regenerated by step 1–2; logs live in `build/*.log`.

## Pending work (HANDOFF post-compile todos)

- **Codegen defects (found during LSP work)**:
  - **Short-circuit hoisting**: method calls on the right of `&&`/`||` are
    evaluated *before* the left operand's guard. Observed crash:
    `docs[fi] != null && docs[fi]->uri.asView().equals(uri)` — generated C
    hoists `String_asView(...)` above the null check (ASan: SEGV in
    `String_asView`, rax=0). Plain field loads are not hoisted, only method
    calls. Fix in `coral-backend/codegen.crl`; until then bind the receiver
    first or nest the `if`s (server.crl does the latter).
  - `io/fs` C-codegen typedef ordering — breaks linking programs that pull
    `std::io` reexports (reproduces at HEAD; tracked in `SESSION_TODOS.md`
    "Known pre-existing bugs", owned there).
  - **File-scope initializers are emitted verbatim**: any global initializer
    that is not a literal/aggregate literal becomes an invalid C static
    initializer (`gcc: initializer element is not constant`). Repro:
    `print.crl` at repo root (`var b = _a.isAsciiAlpha();`), plus minimal
    cases: `var h = g + 1;` and even `const B = A + 1;` (reference to an
    earlier global const) — /tmp/opencode/gv{2,3}. `const Type name = expr`
    is documented as "sema must constant-fold" (grammar.md) but no folding
    happens for file-scope decls; `var` globals with runtime initializers
    need pre-main dynamic init (constructor) or a sema error. Plan:
    (1) fold const init exprs over earlier constants, (2) dynamic-init
    function for runtime `var` initializers.

- Leak cleanup for long-running modes: `AstContext` arena, DiagnosticEngine
  source-buffer Vec, small per-decl allocations (see Diagnostics status)

- Next up (user queue): LSP follow-ons — `documentSymbol`, `definition`,
  `references`, `completion`, ranged hover (see PROTOCOL.md §12 gaps); then
  more error codes/messages from `errors.txt`
- Remaining build system (per `coral-docs/build_sys.md`): `link { libs }`
  wiring into the gcc driver, `phase` (on/run/output/after), `deps`;
  then `coralc clean/graph/doctor`, `profile`/`workspace`/hooks
- `errors.txt` triage + priority object
- build/cache system; `--serve` + JSON language server
- Mu source/typecheck follow-ups: `commandLine()`/io wrapper, `strEq` import
  surface, `str.endsWith`, `fmtStr2` u8*→str args, `sqrt`, mixed usize/u32
  arithmetic — collect the real language/compiler gaps from both projects
- Fix `std::result` for real (`result.crl:94` `Ok { error }` field bug;
  isErr/isOk resolve) and `Arr<T, N>` generic-size rejection
  (`coral-parser/type.crl:140`), then re-enable the preloads in `analyze.crl`
  (leave the user's comments in place)
- Windows platform code beyond the mimalloc mirror is untested here
