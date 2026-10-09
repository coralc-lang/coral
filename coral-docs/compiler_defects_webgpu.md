# Compiler defects found while porting the WebGPU API

Status: **D1 and D2 are known limitations, tracked and being resolved.
D3 is the one open question.** Re-tested against the compiler rebuilt
2026-10-08 22:36. Found while hand-porting the wgpu-native headers
(`webgpu.h` + `wgpu.h`) into a Coral extern module at
`Mu_engine/src/webgpu/`. Reported against the `coralc` binary installed at
`/home/cerie/.coral/coralc`.

Two of the three are already-known gaps that this report only
characterises from the outside — see [builder_incomplete.md](builder_incomplete.md)
for the build-system one and the max-file limit for the driver one. The
report exists to record what a porter hits, not to propose root-cause
analysis of known work.

| ID | Area | Symptom | Status |
|----|------|---------|--------|
| D1 | driver | Max source-file limit truncates input | **known** |
| D2 | build driver | `coralc build` compiles nothing, exits 0 | **known** |
| D3 | parser | `import(lib) a::b { c::d }` rejected | **open** |

## Context

**Where this was found.** While hand-porting the wgpu-native C headers into
a Coral extern API module — the same kind of work as the existing `stb`,
`sdl`, `gl`, `physics`, and `cgltf` ports in `Mu_engine/src/`. The
workstream is exploratory, so these defects surfaced before any code
depended on them.

**Working directory:** `/home/cerie/Documents/Mu`

**Compiler under test:** `/home/cerie/.coral/coralc`, installed from
`/home/cerie/Documents/coralc`. No version flag is available
(`coralc --version` is rejected with `DRV-0002`), so the build cannot be
identified from the binary itself; findings are pinned by timestamp and
size instead:

| | first report | after rebuild |
|---|---|---|
| mtime | 2026-10-08 22:12 | 2026-10-08 22:36 |
| size | 482,400 B | 482,472 B |

**Test subject:** the WebGPU module, two files:

| File | Lines | Bytes |
|------|-------|-------|
| `Mu_engine/src/webgpu/webgpu.crl` | 2,130 | 91,788 |
| `Mu_engine/src/webgpu/lib.crl` | 1 | 32 |

`lib.crl` is the one-line module re-export
(`pub mod webgpu = import webgpu;`) required by the repo convention of one
`<name>.crl` plus a one-line `lib.crl` per module. The test file is
`webgpu.crl`: 655 constants, 228 `extern` function declarations (202 from
`webgpu.h`, 26 native from `wgpu.h`), 114 structs, 70 enum typedefs, 8
flag-set typedefs, 23 opaque handle typedefs, and 12 function-pointer
typedefs. The 91,788-byte size is what makes it a useful test subject: it
exceeds the current max-file limit by a wide margin.

**Project build file:** `Mu_engine/coral.crlb` (schema 2, `strict = true`,
18 modules), used as the test project for D2.

**Scope note.** The compiler is not otherwise usable from this project at
the time of writing: the `jolt` build phase that produces
`libmualibs.a` / `libJoltC.a` / `libJolt.a` does not run, and none of
those archives exist, so D2 cannot be exercised through a full link until
that is addressed. Single-file compiles (`coralc <file.crl> --dry-run`)
work and are what the reproductions below use.

### Re-test log — compiler rebuilt 2026-10-08 22:36

Re-ran every reproduction against the rebuilt binary (482,400 B → 482,472 B).
All three reproduce unchanged.

| Check | Expected | Result |
|-------|----------|--------|
| D1 `type.crl` (5 lines) duplicate typedef | `TC-0004` | `TC-0004` — correct, no limit involved |
| D1 distinct typedef at offset 65,636 | compiles | dropped, exit 0, 1 of 2 in generated C |
| D1 control, both decls under the limit | compiles | both present |
| D2 `coralc build` in `Mu_engine` | compile + artifacts | 18 modules `stale`, exit 0, no `build/muengine` |
| D2 `--force` | differ from default | identical output |
| D2 `.coral/graph` | dependency edges | header comment only, no edges |
| D2 `.coral/cache` | created per `cache_dir` | absent |
| D3 `import(lib) std::io { ios::println }` | parses | `PAR-0001 expected '}', found '::'` |
| Port file `webgpu.crl` (91,788 B) | compiles | `PAR-0006` at **1636:53**, identical to previous run |

The D1 failure position is unchanged to the exact column, confirming the
limit is still in force and was not moved by the rebuild.

### Why only parse errors were reported (not undeclared names)

`coralc` uses **queue-based passes**: a work queue feeds each stage, so
circular imports resolve without infinite loops and dependency ordering is
settled by the queue rather than by file order. A consequence here is that
when input is cut short by the file limit, the compile never reaches the
stage that fills semantic entities. Reporting therefore stops at whatever
the parse stage had already queued:

- parse errors (`PAR-0006` on the truncated construct) are reported,
- undeclared-name / undeclared-symbol errors (`TC-0001` and friends) are
  **not**, because sema never ran to populate entities.

So a file rejected purely for exceeding the limit shows a parse symptom
and suppresses the sema diagnostics that would otherwise explain it. Do
not read the absence of `TC-` errors as "the remainder of the file is
clean".

The separate error limit compounds this: `-ferror-limit=0` was tried on
`webgpu.crl` and did not change the outcome (still `errors=5
(parse=4 sema=1 mono=0)`), because the limit is not what stopped it.

### Note on the D3 control

The flat-form control (`std::text::string { String }`) parses its import
correctly but then fails with 52 × `TC-0003 wrong number of generic
arguments` and 1 × `TC-0001`. That is an artefact of the minimal test file
having no entry point, not a new defect — recorded here so it is not
mistaken for one later.

---

## D1 — max source-file limit truncates input (known)

**Status:** known limitation, tracked, will be resolved
**Component:** driver — max-file limit, interacting with the error limit

**Not a source-reader defect.** The compiler stops reading a source file
at the current max-file limit (observed at exactly **byte 65,536**) and
discards the remainder without a dedicated diagnostic. The root cause is
the max-file limit in the driver, which is already known and being
resolved; this entry records only the observable consequence for porting
large API surfaces, not a new finding.

The limit does not corrupt declarations below the cutoff. `type.crl` at the
repo root (90 bytes, two typedefs, `foo` deliberately declared twice)
reports `TC-0004 duplicate declaration of this name` exactly as expected —
semantic checking is unaffected when the file fits.

### Reproduction

A *distinct, valid* declaration placed past the limit, with no duplicates
and no syntax errors anywhere, so nothing about the input is itself wrong:

```coral
pub typedef Before = u32;   // ...padded so the next decl starts past the limit...
pub typedef After  = u32;   // valid, distinct — dropped
```

Actual:

```
coral: wrote distinct2.c (370 bytes)
coral: dry run, would link distinct2
```

Exit code 0, no error. Generated C contains only the first declaration:

```c
typedef uint32_t Before;
```

The same file with both declarations under the limit emits both typedefs.
```

### Confirmed properties

- The cutoff is exact. Byte 65,536 of `webgpu.crl` falls at line 1636,
  column 53, mid-identifier.
- The failure position is content-dependent in the *file* but fixed in the
  *byte*: the diagnostic always lands at whichever construct straddles
  offset 65,536.
- Comment-only files beyond 64 KiB do not always trip this, so the cap
  interacts with lexing rather than being a plain read-buffer limit.

### Misleading diagnostic

When the cutoff lands mid-construct, the parser emits a fabricated error
naming the end of file instead of the real cause:

```
error[PAR-0006]: unexpected end of file
  ┌─► src/webgpu/webgpu.crl:1636:53
  │
  │ 1636 │ pub extern void wgpuRenderBundleEncoderDraw(WGPURend
    |                                                            ▲
    |                                                            ╰─ the file ended before this construct was closed
```

The message blames EOF and never mentions the file limit. Anyone chasing
this will look for a missing brace in a file that is actually fine.
Worth emitting an explicit "file exceeds max size" diagnostic when the
limit is hit, so the symptom is not misattributed.

### Impact on the WebGPU port

`webgpu.crl` is 91,788 bytes. Everything past the limit — roughly the last
475 lines, including the whole `wgpu.h` native-extension section and its
26 function declarations — is invisible to the parser. Until the limit is
resolved, that file cannot be compiled as a single unit, so the port cannot
be verified against the compiler at all.

This is a size problem, not a correctness problem: the declarations below
the cutoff are fine, and the static header conformance check passes
independently of the compiler.

---

## D2 — `coralc build` compiles nothing and exits 0

**Status:** known limitation — the build system is not complete yet
**Component:** build driver (`coralc build`)

The build system is a known incomplete area (see also
[builder_incomplete.md](builder_incomplete.md), which records that `.crlb`
fields are parsed but not acted upon). This entry records only the
end-to-end symptom from the command line; it is not a new finding, and the
fix is part of completing the build system rather than the compiler.

`coralc build` writes `modules.map`, reports every module as `stale`, and
exits 0. No compilation, no codegen, no link output.

```
$ cd Mu_engine && coralc build
modules.map written (18 modules, 0 aliases)
engine  stale
math  stale
...
webgpu  stale
...
$ echo $?
0
```

### Reproduction

Any project with a `coral.crlb`. `Mu_engine` is a ready-made case.

### Observations

- `--dry-run` behaves identically, i.e. nothing is compiled even when
  compilation is explicitly requested.
- `--force` also behaves identically, which is self-contradictory:
  `--force` is supposed to bypass staleness checks, yet the same "stale"
  verdict appears with and without it.
- `.coral/graph` and `.coral/graph.dot` are written but contain no edges.
- `.coral/cache` is never created, despite `cache_dir = ".coral/cache"`
  being set in the build file.

The driver therefore completes module discovery and then stops before the
compile phase. Because no diagnostic is emitted, a total no-op is
indistinguishable from a successful build.

### Related: build phases do not run

The `jolt` phase in `coral.crlb` is supposed to drive cmake and produce
`build/native/libmualibs.a`, `build/native/joltc/libJoltC.a` and
`libJolt.a`. It does not run, and none of those archives exist. Linking
could not succeed even once D2 is fixed.

This is adjacent to the known builder gap in
[builder_incomplete.md](builder_incomplete.md), which records that `.crlb`
fields (`phases`, `deps`, `link`, `target`, …) are parsed but never acted
upon. D2 appears to be the same gap seen end-to-end from the command line:
field-level findings there, whole-driver no-op here. They should be fixed
together or at minimum tracked as one issue.

### Suggested first steps

- Exit non-zero, or at minimum print a clear "nothing to do / driver did
  not reach compile phase" line, when the build produces no artifacts. A
  no-op must not be reportable as success.
- Make `--force` observably differ from the default path, or drop it until
  it does something.

---

## D3 — import form `import(lib) a::b { c::d }` is rejected

**Status:** open
**Component:** parser

The symbol-list import form with a nested path is not accepted:

```coral
import(lib) std::io { ios::println };
```

Actual:

```
error[PAR-0001]: expected '}', found '::'
error[PAR-0004]: unexpected closing token
coral: cannot resolve import(lib) std::io
```

The parser wants `}` immediately after the path and cannot accept
`ios::println` as a symbol inside the braces.

### Reproduction

This is not synthetic — it is the exact line used by the existing engine
entry point, `Mu_engine/src/engine/main.crl:4`, which currently fails to
parse. `grammar.md` documents `A { syms }` as valid, so either the parser
has a gap or the installed binary is out of step with the sources.

### Notes

- The std tree itself uses the flat form and works:
  `import(lib) std::text::string { String };` and
  `import ios { println, eprintln };`
  (see `lib/std/x86_64/linux/io/log.crl:2`).
- Passing a manifest explicitly (`-f lib/std/manifest.linux.crlb`) does
  not change the outcome, so this is a parser gap and not a
  manifest-resolution failure.

### Version-skew note

`coralc --version` is not a recognised flag, so there is no way to ask the
binary what it is. Given that the repo's own engine entry point does not
parse, verifying the installed build against these sources is worth doing
explicitly.

---

## Verification status of the WebGPU port

Independently of the three defects above, the port was verified
**statically against the headers only**:

```
structs checked: 114, fns checked: 228 — RESULT: ALL-MATCH
```

That is conformance of declarations to the C ABI (field-for-field and
parameter-for-parameter after type mapping). It is **not** a compile: the
compiler has never accepted this code, due to D1. Treat the port as
unverified by the toolchain until D1 and D2 are resolved.

---

## Reproducing all three

From this directory's parent (`coralc/`):

```sh
# D1 — duplicate decl placed past byte 65536 should be TC-0004
python3 - <<'EOF'
head = 'pub typedef MyThing = u32;\n'
pad  = '//' + 'z' * 78 + '\n'
body = head
while len(body.encode()) < 65536 + 40 - len(head):
    body += pad
body += 'pub typedef MyThing = u64;\n'
open('/tmp/cap6.crl', 'w').write(body)
EOF
coralc /tmp/cap6.crl --dry-run   # expect: error; actual: success

# D2 — build driver
cd ../Mu/Mu_engine && coralc build; echo "exit=$?"   # exit=0, no artifacts

# D3 — nested symbol import
printf 'import(lib) std::io { ios::println };\nfn t() { }\n' > /tmp/imp.crl
coralc /tmp/imp.crl --dry-run   # expect: ok; actual: PAR-0001
```