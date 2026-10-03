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
