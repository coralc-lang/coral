# Coral porting guide (lib_old → lib, old syntax → new syntax)

This is the complete reference for porting work. Do **not** read
`compiler/`, `bootstrap/`, or any other part of the compiler tree — it is
irrelevant to porting and often an older dialect.

Concrete completed ports you may open as examples (max 2–3 files):

- `lib/std/collections/vec.crl` (old: `lib_old/std/collections/vec.crl`)
- `lib/std/data/option.crl` (old: `lib_old/std/data/option.crl`)
- `lib/std/data/result.crl` (old: `lib_old/std/data/result.crl`)

## 1. Imports

Four forms, nothing else. **Never write a string path** (`import "x"`) —
that syntax is being removed. Never write `.crl` in an import.

```crl
import token { TokenKind, Token };          // sibling: ./token.crl next to this file
import lexer::table { TokenTable };         // module import (builder-resolved)
import(lib) std::mman { alloc, dealloc };   // import from the lib surface
import(lib) core;                           // whole surface, no item list
import(lib) std::allocator { Allocator, mimalloc { MiAlloc }, tlsf { Tlsf } };  // nested items
```

Nested item braces are supported: `mimalloc::{ MiAlloc }` inside an item
list is equivalent to the flat path `mimalloc::MiAlloc`. Use whichever;
both are correct.

**Allocator surface:** there is no `std::tlsf` and no `std::mimalloc`.
Allocators hang under `std::allocator` (the `allocators/` folder whose
`lib.crl` re-exports `allocator`, `tlsf`, and `mimalloc`), so always
`import(lib) std::allocator { mimalloc { MiAlloc }, tlsf { Tlsf } }`.
Inside the `allocators/` folder itself, use sibling imports
(`import allocator { Allocator };`, `import tlsf { Tlsf };`) — never the
`std::allocator` surface from a file that the surface itself re-exports.

**FLAGGED — assumed working, not verified:** (a) nested item lists
(`mimalloc::{ MiAlloc }`) and flat paths (`mimalloc::MiAlloc`) both
resolve; (b) a flat `Allocator` item resolves through the
`std::allocator` surface even though `lib.crl` re-exports it as a
sub-module; (c) the `std` surface picks up the platform surface's
`pub mod allocator` entry. If any of these fail at build time it is a
sema/loader gap to report — not a port bug. Do not work around them,
and do not read the compiler to check.

Re-exports live in a folder's `lib.crl`:

```crl
pub mod option = import option;
pub mod memory = import memory::intrinsics;
```

**Platform rule:** import paths never contain `x86_64`, `linux`,
`windows`, or `arm64`. Platform is selected by the build manifest
(`lib/std/manifest.linux.crlb` etc.), not by the path. Write
`import(lib) std::mman { alloc };` — never
`import x86_64::linux::memory::mman`.

Import only what you use. If old code did `std::mman::alloc<T>(x)`,
replace with `import(lib) std::mman { alloc, dealloc, realloc };` at the
top and call `alloc<T>(x)` unqualified. Watch for name collisions; if two
sources collide, keep one qualified via the module import form.

## 2. Declarations

```crl
pub void push(T val) { ... }          // no `fn` keyword; return type first
static Vec<T> new() { ... }           // associated fn (no receiver) / file-local helper
usize count() { return self.len; }    // method inside struct body
extern("C") rawptr calloc(usize count, usize size);   // FFI
pub typedef cchar = u8;               // type alias
pub Allocator* defaultAllocator;      // global
const u32 FLI_COUNT = 32;             // const
static const u8 Table[16] = { ... };  // static const table
```

Params are `type name` (C-style), never `name: type`. Variadic: `...`.
File-private helpers get `static`.

### struct

Methods live **inside** the struct body; constructors are `static`:

```crl
pub struct Vec<T>
{
    T* data;
    usize len;

    static Vec<T> new() { return Vec<T> { .data = null, .len = 0 }; }
    void push(T val) { ... }
}
```

Plain records, buffers, handles, arenas → struct.

### variant + extend

Sum types become `variant`; their methods move to an `extend` block
below:

```crl
pub variant Option<T>
{
    None,
    Some { T value; }
}

pub extend<T> Option<T>
{
    bool isSome()
    {
        switch (self)
        {
            Some { value } => { return true; },
            else => { return false; }
        }
    }
}
```

Rule: a struct that is really "tag/bool + payload(s)" (old
`option`-style) → variant + extend. Anything else stays a struct.
Payload cases are `Name { T field; }`.

`extend` is also how you add methods to an existing type in another
file: `pub extend str { ... }`.

## 3. Types

`u8 u16 u32 u64` `i8 i16 i32 i64` `usize isize` `f32 f64` `bool`
`rawptr` `str` `void`. Pointers `T*`, `const T*`. Arrays `T[N]`
(in params and fields). Function-pointer types: `bool(T, T) less`,
`void(rawptr, usize) free`. Generics: declared `<T, N>`, called
`alloc<T>(n)` (no turbofish, no `::<>`).

## 4. Expressions and statements

- Struct/variant literals use **only designated initializers**:
  `Vec<T> { .data = null, .len = 0 }`,
  `Option<T>::Some { .value = x }`. Old build-up locals
  (`T v; v.a = ...; return v;`) collapse into one literal.
- `switch (x) { pat => { ... }, pat if cond => { ... }, else => ... };`
  always parenthesized; `else` is the fallback prong (never `default`).
- `if / else`, `while`, C-style `for (usize i = 0; i < n; i++)`,
  `break;` `continue;` `return x;`.
- Casts are C-style `(T)x`. There is no `as`.
- Member access: `self.field` (always dot on `self`); other pointers use
  `p->next`. Address-of `&x`, deref `*p`, index `a[i]`, ternary `a ? b : c`.
- Assertions are builtin attribute calls:
  `@assert(cond)`, `@assertOut(cond)`, `@assertOut(cond, "msg")`.
  Bare `assert(...)` is old syntax.
- String `"..."` (escapes `\n \t \\ \" \u{...}`), char `'a'`, ints
  `42 0xFF 1_000` with optional suffix `32u`, `5ull`, floats `1.5`,
  `true` / `false`, `null`.
- `defer` statement exists for cleanup: `defer close(f);`.

## 5. Naming

- Types / variants / traits: **PascalCase** (`vec` → `Vec`,
  `hashmap` → `HashMap`, `linkedlist` → `LinkedList`,
  `priorityqueue` → `PriorityQueue`, `ringbuf` → `RingBuf`).
  Rename every reference consistently: signatures, literals, casts,
  nested types.
- Functions and methods: keep the old name (existing std is camelCase:
  `isSome`, `unwrapOr`, `withCap`).
- Fields: keep as-is.
- File names: lowercase snake (`priorityqueue.crl`, `shared_ptr.crl`).

## 6. Imports of old code — mapping

| old (lib_old) | new (lib) |
|---|---|
| `mod std = import(lib, "std");` | delete; add targeted `import(lib) std::x { sym, ... };` |
| `mod d = import(lib, "std/collections/deque.crl");` | `import deque;` (sibling) |
| `import "allocator";` | `import allocator;` |
| `mod std = import(lib, "std");` + `std::mman::alloc<T>(x)` | `import(lib) std::mman { alloc };` + `alloc<T>(x)` |
| `pub mod x = import(lib, "path/file.crl");` (in a lib.crl) | `pub mod x = import path::file;` |
| `std::tlsf::Tlsf`, `std::mimalloc::MiAlloc` | items under `std::allocator { tlsf { Tlsf }, mimalloc { MiAlloc } }`; siblings inside `allocators/` |
| `std::mman::_mmap` / `std::mman::_munmap` | `import(lib) std::intrinsics { mmap, munmap };` (mman no longer wraps them) |
| `std::libc::*` | `import(lib) platform::libc { ... };` (libc surface is `lib/platform/libc.crl`) |
| `std::ios::*` | `std::io::ios::*` (io folder surface, §8) |
| `std::string::*` | `std::text::string::*` (text category ports later — FLAG) |
| `std::fmt::*` | `std::fmt::*` (own folder, ports later — FLAG) |
| `std::{ fios, fs, net, term, ... }` | `std::io::{ fios, fs, net, term, ... }` (§8) |

## 7. Porting rules

1. Port the **whole file** — no TODOs, no stubbed functions, no dropped
   logic. Preserve every function, even private ones.
2. Comments are **allowed and welcome**: keep meaningful `//` and
   `/* ... */` comments; fix ones that become wrong; don't invent
   filler.
3. Drop only what the completed ports dropped: free wrapper functions
   that just delegate to a static/constructor (see old vec's
   `pub vec<T> new<T>()`), and duplicate struct declarations you can
   import instead (e.g. `Allocator` already exists in
   `lib/std/x86_64/linux/memory/allocators/allocator.crl`).
4. Where old code is C-isms the new dialect replaced, follow the
   examples: `self->x` → `self.x`, `assert(...)` → `@assert(...)`,
   positional literal → designated, `x as T` → `(T)x`.
5. Layout: portable code → `lib/std/<category>/`; platform-dependent
   code → `lib/std/x86_64/linux/<category>/`. `fmt` gets its own folder
   `lib/std/fmt/` (not under `text/`). Windows ports are made later by
   copying the linux tree — never write windows code now.
6. If a construct has no clean equivalent, port it as faithfully as
   possible and flag the judgment call in your report.
7. Do not modify files outside your assigned destinations.

## 8. The io port — 12 files, print family redesign

Source `lib_old/std/io/`: bio, cmd, env, fios, fs, ios, log, net, path,
process, temp, term. Destination `lib/std/x86_64/linux/io/` — every file
talks to libc, so the whole category is platform-dependent.

### 8.1 Surface and imports

- Create `lib/std/x86_64/linux/io/lib.crl` with one
  `pub mod ios = import ios;` line per file (all 12).
- Add exactly one line to `lib/std/x86_64/linux/lib.crl`:
  `pub mod io = import io;`. That file is user-owned — change nothing
  else in it; if its shape has moved, report the line you would add
  instead of forcing it.
- Import form for io files:
  - `import(lib) std { libc, ... }` → `import(lib) platform::libc { write, strlen, ... };`
  - `import(lib) std { string }` → `import(lib) std::text::string { String };` (ported later — FLAG)
  - `import(lib) std { fmt }` → see 8.3: the print path should NOT need fmt
  - `import(lib) std { fios }` → sibling `import fios { ... };`
  - `cchar` comes bare (cf. `lib/platform/libc.crl` which uses it with no
    import); if a file needs it explicitly, `import core { cchar };`
- The libc surface has no `getchar`, `vsnprintf`, `strtod`, etc. — declare
  missing symbols as local `extern("C")` in the file that needs them
  (precedent: mimalloc's local `sched_yield`). Never edit
  `lib/platform/libc.crl`.

### 8.2 Print family redesign (ios.crl)

Old `print!` / `nprint!` / `eprint!` / `neprint!` compile-time variadics
are replaced by two mechanisms:

**Rust-style print** — format string first, parsed at compile time:

```coral
pub void print<comptime T>(T fmt, ...)    // stdout
pub void println<comptime T>(T fmt, ...)  // stdout + '\n'   (replaces nprint)
pub void eprint<comptime T>(T fmt, ...)   // stderr          (replaces eprint!)
pub void eprintln<comptime T>(T fmt, ...) // stderr + '\n'   (replaces neprint)
```

- `comptime T` marks the format type as compile-time evaluated — the
  compiler parses the format string, never the runtime.
- Placeholders: `{}` (one per following argument), `{{` / `}}` escapes.
  Specifiers (our chosen set — port exactly these): `{}` default,
  `{:d}` decimal, `{:x}` hex, `{:b}` binary, `{:p}` pointer.
- Wrong placeholder/argument count, unknown specifier, or a format
  string containing `{}` passed with no arguments → **compile error**.
- Dispatch is the old `_fprintOne` shape: a `comptime` switch over `T`,
  zero runtime type dispatch.
- Manipulators (`spaces`, `repeat`, `hex`, `bin`, `fixed` and their
  `Spaces`/`Repeat`/`Hex`/`Bin`/`Fixed` structs) stay and work as `{}`
  arguments.

**Type-not-specified rule (toStr)** — any argument that is not part of a
comptime format-string call:

- `print(x)` / `print(a, b)` (no string-literal format first): every
  argument's type must provide `toStr`. The compiler auto-wires the
  `toStr` call and prints the returned `str`.
- Types handled by the built-in comptime switch (ints, floats, bool,
  char, str, cstr, rawptr, String, manipulators) count as having it.
- A type with no `toStr` → **compile error** ("type does not implement
  toStr; implement it or pass a format string").
- A runtime `str` variable as first argument is a value, not a format
  (formats must be comptime literals) — it prints via its own `toStr`.

**vaprint — the printf-like equivalent** (replaces printf-style output):

```coral
pub void vaprint(const cchar* fmt, ...)   // stdout, C printf semantics
```

- Runtime C-style variadic: `%d %i %u %x %X %s %c %f %p %%` plus width,
  precision, `-`/`0` flags (whatever `vsnprintf` supports).
- Anything, indefinitely: unbounded argument count and output length —
  format into a 1024-byte stack buffer with a local
  `extern("C") i32 vsnprintf(...)`, write, advance, loop until done;
  long `%s` runs and literal runs can be written directly.
- No heap allocation, no argument-count limit.

**Optimizations (all print paths):**

1. Comptime format parsing — literal chunks are written directly, no
   runtime scanning of `{}`.
2. Accumulate into one stack buffer (`u8 outBuf[1024]`) and issue ONE
   `write` per call (old code wrote once per argument); flush when full,
   finish with the remainder. stdout and stderr never share a buffer.
3. Integers/hex/bin: hand-rolled itoa into a stack buffer (i64 needs 21
   bytes) — no `String` alloc/free per number (old `_fprintI32`
   heap-allocated). This removes the `std::fmt` dependency from the
   print path entirely.
4. Floats: `snprintf` (`%.6g` / `%.15g` / precision for `Fixed`) into a
   stack buffer.
5. Helpers `[[inline]]`.

**Carry over unchanged:** `_sysReadByte`, `_sysReadLine`, `readChar`,
`readLine`, `read<T>`, `readVal<T>` (same comptime switch), `parseI64`,
`parseU64`, `parseF64`, `flush`, the manipulator structs/factories.
Known source bug: `_readBool` uses undefined `v.equals` → `sv.equals`
(fix it and note it in your report). The old musings comment above
`print!` (ios.crl ~249–257) describes this design being debated —
replace it with a short comment stating the final rules.

### 8.3 The other 11 files

Faithful ports under §7 rules — every function survives. Notes:

- `term.crl`: `std::libc::snprintf` → `platform::libc` import; CSI
  writes unchanged; `u8 buf[24]` stack-array syntax is already valid in
  new coral (cf. `mman.crl` `stackBuf`).
- `fios` is a sibling of the other io files — import it as
  `import fios { ... };`, never through the std surface.
- `net.crl` may need socket externs absent from the libc surface →
  local `extern("C")` declarations (8.1 rule).
- Name mapping for the rest of the lib when it ports later (no
  already-ported file references the old names — verified):
  `nprint` → `println`, `eprint!` → `eprint`, `neprint` → `eprintln`,
  `print!` → `print`, `std::ios::x` → `std::io::ios::x`.

### 8.4 FLAGGED (rely on these; do not investigate)

1. `comptime T` parameter spelling and comptime format-string parsing
   emitting direct writes.
2. Compile errors: placeholder/argument mismatch, unknown specifier,
   missing `toStr`.
3. Trait mechanism in new syntax — spec `toStr` as a trait shaped like
   old `pub trait drop` (`lib_old/std/traits/destructor.crl`); the
   compiler model adapts the spelling. "Compiler auto-adds toStr"
   means: the compiler resolves and inserts the `toStr` call itself —
   users implement `toStr`, they never write dispatch code.
4. Import paths `std::text::string` and `std::fmt` (categories port
   after io); nested surface `std::io::ios::print` resolving through
   `io/lib.crl` + the platform root (same assumption as the allocator
   surface).
5. Local `extern("C")` symbols (`vsnprintf`, `getchar`, sockets) link
   against libc without being in the surface.
