Got it — locking in your decisions:

- **Q4:** **B** — explicit `modules = [...]` list. Plus **aliases** so files write `import lexer::table` instead of `import coral_lexer::table`.
- **Q5:** **Option 1** — builder writes `.coral/modules.map`, compiler reads it.
- **Entry:** `coral-frontend` (not `coral-lexer`).
- **Compiler does NOT walk the tree.** Only the builder walks. (I'll explain why this is correct below, since you asked for the reason against A.)

Let me answer the "A vs B" question properly first, then write the full spec.

---

## Why B is correct here (and why A is wrong for your pipeline)

You asked: *"making the compiler walk everything is stressful of the pipeline, as the overhead from compiling all these files comes — or is that not what happens?"*

You're half-right. Let me separate the two concerns:

**Concern 1: Who walks the tree?**
- **A (auto-walk):** builder walks, discovers modules. Compiler doesn't walk — compiler reads the map. So A doesn't make the *compiler* slow.
- **B (explicit list):** builder walks only the listed folders. Compiler reads the map. Same compiler behavior.

So **A vs B is not about compiler speed** — both keep the compiler dumb. A vs B is about **who owns the source of truth for "what modules exist."**

**Concern 2: Why B wins for you**

1. **Determinism.** With A, a stray `lib.crl` you accidentally leave in `compiler/` (backup folder, scratch dir, vendor dump) silently becomes a module. With B, you list what's real. The build graph can't be changed by accident.
2. **Skip lists fall out naturally.** You said folders can be skipped. With A you need `skip = [...]` on top of the walk. With B, skipping = not listing it. One concept, not two.
3. **Aliases need a home.** `import lexer::table` needs a mapping `lexer → coral-lexer`. Where does that mapping live? Naturally in the build file next to the module list. With A, aliases have no obvious anchor.
4. **You can still `coralc map` for discovery.** You said `coralc map` re-scans and adds new `lib.crl` files. So the "don't want to hand-maintain the list" problem is solved by a *tool*, not by making the walk implicit. Explicit list + auto-update tool = best of both.
5. **Incremental + cache-friendly.** Cache fingerprint = list of modules + their file hashes. Explicit list = stable fingerprint. A walk = fingerprint changes when unrelated folders change.

**The one thing A does better:** zero-config for new projects. But you already planned `coralc init` and `coralc map`, which covers that.

So: **B is correct.** Compiler stays dumb, builder stays explicit, `coralc map` keeps the list fresh.

Now the full spec.

---

# `crl` Build System — Full Specification

## 0. Naming

| Thing | Name | Extension |
|---|---|---|
| Source language | Coral | `.crl` |
| Build file | Coral Build | `.crlb` |
| Compiler | `coralc` | — |
| Builder | `coralc` | — |
| Module map | `modules.map` | — |
| Cache dir | `.coral/` | — |

---

## 1. Directory layout (example)

```
myproject/
├── coral.crlb                     # the build file (root)
├── .coral/                        # cache + generated
│   ├── modules.map
│   ├── cache/
│   └── graph.dot
├── compiler/
│   ├── coral-ast/
│   │   └── lib.crl
│   ├── coral-backend/
│   ├── coral-common/
│   │   ├── lib.crl
│   │   ├── slice.crl
│   │   └── token.crl
│   ├── coral-context/
│   ├── coral-diagnostics/
│   │   ├── lib.crl
│   │   └── lexer_diag.crl
│   ├── coral-entities/
│   ├── coral-frontend/            # entry
│   ├── coral-ir/
│   ├── coral-lexer/
│   │   ├── lib.crl
│   │   ├── base.crl
│   │   ├── escape.crl
│   │   ├── ident.crl
│   │   ├── lexer.crl
│   │   ├── number.crl
│   │   ├── operator.crl
│   │   ├── skip_ws.crl
│   │   ├── string.crl
│   │   └── table.crl
│   ├── coral-module/
│   ├── coral-parser/
│   │   ├── lib.crl
│   │   └── expr.crl
│   ├── coral-semantics/
│   └── coral-source/
└── build/
    └── coralc                    # output
```

---

## 2. Build file grammar (`.crlb`)

```ebnf
build_file    = { decl } ;
decl          = build_decl | alias_decl | task_decl | include_decl ;

build_decl    = "build" STRING "{" { build_field } "}" ;
build_field   = field | modules_field | skip_field | override_block ;

field         = IDENT "=" value ";" ;
modules_field = "modules" "=" "[" [ STRING { "," STRING } [ "," ] ] "]" ";" ;
skip_field    = "skip"    "=" "[" [ STRING { "," STRING } [ "," ] ] "]" ";" ;

override_block = "override" STRING "{" { field } "}" ;

alias_decl    = "alias" IDENT "=" STRING ";" ;
task_decl     = "task" STRING "{" { task_field } "}" ;
task_field    = field | "after" "=" list ";" | "exec" "=" STRING ";" ;

include_decl  = "include" STRING ";" ;

value         = STRING | NUMBER | BOOL | list ;
list          = "[" [ value { "," value } [ "," ] ] "]" ;

IDENT         = /[A-Za-z_][A-Za-z0-9_-]*/ ;
STRING        = '"' { /[^"\\]/ | "\\" . } '"' ;
NUMBER        = /[0-9]+/ ;
BOOL          = "true" | "false" ;

(* comments *)
comment       = "#" { /[^\n]/ } ;
```

### Reserved build fields

| Field | Type | Meaning |
|---|---|---|
| `root` | string | Root dir of the source tree (for paths) |
| `entry` | string | Module name that is the executable |
| `target` | string | `native-x86_64`, `native-arm64`, `wasm32`, `bytecode` |
| `opt` | string | `debug`, `release`, `size` |
| `output` | string | Output binary path |
| `module_map` | string | Where to write `modules.map` (default `.coral/modules.map`) |
| `cache_dir` | string | Default `.coral/cache` |
| `flags` | list | Extra flags passed to `coralc` |
| `modules` | list | **Required.** Which folders are build modules |
| `skip` | list | Subfolders to exclude during any scan |
| `alias` | decl | `name → folder` mapping for imports |
| `override` | block | Per-module field overrides |
| `task` | decl | Named task (run/test/clean/etc.) |

---

## 3. Builder's view of `lib.crl`

The builder parses `lib.crl` **only** to extract re-export lines. Everything else in the file is ignored (it's the compiler's problem).

```ebnf
lib_file      = { lib_item } ;
lib_item      = pub_mod | other ;      (* other = anything, skipped by builder *)
pub_mod       = "pub" "mod" IDENT "=" "import" STRING ";" ;
```

Extraction rule:

- Scan for `pub mod NAME = import "PATH";` at any nesting depth that the builder can safely detect (line-oriented is fine).
- Each match registers: **`<this_folder>::<NAME>` → resolved(PATH)** in the global module table.
- `PATH` is resolved **relative to the `lib.crl` file's folder**.

Resolution of `PATH`:

1. If `<folder>/<PATH>.crl` exists → that file.
2. Else if `<folder>/<PATH>/lib.crl` exists → that folder's surface.
3. Else → error `E1004 unresolved re-export path`.

---

## 4. The global module table

Built by the builder in one pass. Stored in `.coral/modules.map`.

### Format

Plain text, line-oriented, stable, diff-friendly:

```
# coral modules.map v1
# <folder>::<export>  →  <resolved-path>
common::token       →  compiler/coral-common/token.crl
common::slice       →  compiler/coral-common/slice.crl
diagnostics::lexer_diag  →  compiler/coral-diagnostics/lexer_diag.crl
lexer::base         →  compiler/coral-lexer/base.crl
lexer::escape       →  compiler/coral-lexer/escape.crl
lexer::ident        →  compiler/coral-lexer/ident.crl
lexer::lexer        →  compiler/coral-lexer/lexer.crl
lexer::number       →  compiler/coral-lexer/number.crl
lexer::operator     →  compiler/coral-lexer/operator.crl
lexer::skip_ws      →  compiler/coral-lexer/skip_ws.crl
lexer::string       →  compiler/coral-lexer/string.crl
lexer::table        →  compiler/coral-lexer/table.crl
parser::expr        →  compiler/coral-parser/expr.crl

# aliases (from build file)
@lexer::table             →  compiler/coral-lexer/table.crl
@lexer::lexer             →  compiler/coral-lexer/lexer.crl
@parser::expr             →  compiler/coral-parser/expr.crl
```

- Lines starting with `#` are comments.
- Unaliased entries use the raw folder name.
- Aliased entries start with `@` and are what source files actually write.

### Why text and not JSON

- Diffs cleanly in git.
- Trivially greppable.
- No parser dependency.
- Fast to load (one line scan).

---

## 5. Aliases

Source files write:

```crl
import lexer::table { TokenTable };
import parser::expr  { Expr };
```

Not:

```crl
import coral-lexer::table { TokenTable };
import coral-parser::expr { Expr };
```

Aliases are declared in the build file:

```crlb
alias lexer  = "coral-lexer/lib.crl";
alias parser = "coral-parser/lib.crl";
alias common = "coral-common/lib.crl";
alias diag   = "coral-diagnostics/lib.crl";
```

The builder applies aliases when writing `modules.map`, so the compiler never sees `coral-lexer::` — it sees `lexer::` directly.

**Rules:**

- An alias must point to a folder in `modules`.
- An alias name must not collide with another alias or a bare folder name.
- Aliases are only for **module imports**. Path imports (`import "token"`) are unaffected.

---

## 6. Import forms (compiler + builder)

| Form | Kind | Resolver |
|---|---|---|
| `import "token" { ... }` | Path | Compiler, relative to current file |
| `import ".." { ... }` | Path | Compiler |
| `import "../foo" { ... }` | Path | Compiler |
| `import lexer::table { ... }` | Module | **Builder** via `modules.map` |
| `import common::token { ... }` | Module | Builder |
| `import common { ... }` | Module (surface) | Builder — pulls everything `coral-common/lib.crl` re-exports |

The compiler sees `import lexer::table` and asks the module map: "give me the path for `lexer::table`." The map answers. The compiler never walks.

---

## 7. Build algorithm

```
coralc build
  1. read coral.crlb
  2. resolve `root`, `modules`, `skip`, `alias`
  3. for each module in `modules`:
       - locate <root>/<module>/lib.crl
       - error E1001 if missing
       - parse for `pub mod NAME = import "PATH";`
       - for each, resolve PATH to a file or folder
       - register in module table under <module>::NAME
  4. error E1002 on duplicate <module>::NAME
  5. error E1003 on alias pointing to missing module
  6. write .coral/modules.map   (unaliased + aliased entries)
  7. for each module, for each .crlin it:
       - scan for `import x::y` module-imports
       - resolve via map
       - add edge  <this-module> → <target-module>
  8. error E1005 on unresolved module import
  9. error E1006 on cycle (with trace)
 10. topo-sort modules
 11. for each module in order:
       - fingerprint = hash(lib.crl+ all .crlin folder + dep fingerprints)
       - if fingerprint in cache, skip
       - else:  coralc --emit-obj --module-map=.coral/modules.map <folder>/*.crl
 12. link entry module → output
 13. write cache
```

---

## 8. Error formats

Consistent, single-line first, details after:

```
E1001  missing lib.crl
  module: coral-frontend
  path:   compiler/coral-frontend/lib.crl
  hint:   run `coralc init coral-frontend` or add a lib.crl

E1002  duplicate module export
  name:   coral-lexer::table
  first:  compiler/coral-lexer/lib.crl:4
  second: compiler/coral-lexer/alt/lib.crl:2

E1003  alias points to unknown module
  alias:  lexer
  target: coral-lexer
  list:   modules = [...]

E1004  unresolved re-export path
  file:   compiler/coral-common/lib.crl:3
  path:   "token"
  tried:  compiler/coral-common/token.crl
          compiler/coral-common/token/lib.crl

E1005  unresolved module import
  file:   compiler/coral-lexer/lexer.crl:1
  import: common::token
  map:    .coral/modules.map
  hint:   is coral-common in `modules`?

E1006  dependency cycle
  cycle:  coral-lexer → coral-parser → coral-lexer
  paths:
    compiler/coral-lexer/lib.crl
    compiler/coral-parser/lib.crl
```

---

## 9. CLI spec

```
coralc init [dir]              scaffold empty project:
                              dir/
                                coral.crlb
                                .coral/
                                <module>/
                                  lib.crl

coralc build                   run full build (uses cache)
coralc build --force           ignore cache
coralc build --module NAME     build one module + deps
coralc build --emit-map        write modules.map only, no compile

coralc map                     rescan tree; add any new lib.crlto `modules`
coralc map --dry               show what would be added, don't write

coralc run                     build entry, then exec output
coralc clean                   wipe .coral/cache and build/
coralc graph                   dump .coral/graph.dot
coralc doctor                  validate build file, aliases, cycles
```

---

## 10. Worked example — your tree

### `coral.crlb`

```crlb
build "coralc" {
    root       = "compiler/"
    entry      = "coral-frontend/coral.crl"
    target     = "native-x86_64"
    opt        = "release"
    output     = "build/coralc"
    module_map = ".coral/modules.map"
    cache_dir  = ".coral/cache"

    flags = ["--strict", "--warn-unused"]

    modules = [
        "coral-ast",
        "coral-backend",
        "coral-common",
        "coral-context",
        "coral-diagnostics",
        "coral-entities",
        "coral-frontend",
        "coral-ir",
        "coral-lexer",
        "coral-module",
        "coral-parser",
        "coral-semantics",
        "coral-source",
    ]

    skip = ["target", "vendor"]
}

# short names for imports
alias lexer   = "coral-lexer/lib.crl";
alias parser  = "coral-parser/lib.crl";
alias common  = "coral-common/lib.crl";
alias diag    = "coral-diagnostics/lib.crl";
alias ast     = "coral-ast/lib.crl";
alias ir      = "coral-ir/lib.crl";
alias sem     = "coral-semantics/lib.crl";
alias src     = "coral-source/lib.crl";

# per-module overrides
override "coral-lexer" {
    flags = ["--no-inline"];
}

override "coral-parser" {
    opt = "debug";           # parser is hot, keep symbols
}

# tasks
task "run" {
    after = ["build"];
    exec  = "build/coralc";
}

task "test" {
    after = ["build"];
    exec  = "build/coralc --self-test";
}
```

### `compiler/coral-common/lib.crl`

```crl
pub mod token = import "token";
pub mod slice = import "slice";

# regular code is allowed too
pub str version() {
    return "0.1.0";
}
```

### `compiler/coral-lexer/lib.crl`

```crl
pub mod base     = import "base";
pub mod escape   = import "escape";
pub mod ident    = import "ident";
pub mod lexer    = import "lexer";
pub mod number   = import "number";
pub mod operator = import "operator";
pub mod skip_ws  = import "skip_ws";
pub mod string   = import "string";
pub mod table    = import "table";
```

### `compiler/coral-lexer/lexer.crl` (uses module import)

```crl
import common::token { TokenKind, Token };
import common::slice { Slice };

import "ident"  { scan_ident };
import "number" { scan_number };

pub Token lex(Slice src) {
    # ...
}
```

Note:
- `common::token` → module import → resolved by builder via `modules.map`.
- `"ident"` → path import → sibling file, resolved by compiler locally.

### `.coral/modules.map` (generated)

```
# coral modules.map v1 — generated by `coralc build`, do not edit
common::token        →  compiler/coral-common/token.crl
common::slice        →  compiler/coral-common/slice.crl
diag::lexer_diag     →  compiler/coral-diagnostics/lexer_diag.crl
lexer::base          →  compiler/coral-lexer/base.crl
lexer::escape        →  compiler/coral-lexer/escape.crl
lexer::ident         →  compiler/coral-lexer/ident.crl
lexer::lexer         →  compiler/coral-lexer/lexer.crl
lexer::number        →  compiler/coral-lexer/number.crl
lexer::operator      →  compiler/coral-lexer/operator.crl
lexer::skip_ws       →  compiler/coral-lexer/skip_ws.crl
lexer::string        →  compiler/coral-lexer/string.crl
lexer::table         →  compiler/coral-lexer/table.crl
parser::expr         →  compiler/coral-parser/expr.crl
...
```

### Build graph (edges derived from imports)

```
coral-common
    ↑
coral-lexer ──→ coral-parser ──→ coral-ast
    ↑                                ↑
coral-frontend ─────────────────────┘
    ↓
coral-ir ──→ coral-semantics
```

(Exact edges depend on what your `.crl` files import. The builder derives them, you don't write them.)

---

## 11. `coralc init` and `coralc map`

### `coralc init myproject`

```
myproject/
├── coral.crlb
├── .coral/
└── src/
    └── lib.crl         # empty
```

`coral.crlb`:

```crlb
build "myproject" {
    root   = "src/"
    entry  = "src"
    target = "native-x86_64"
    opt    = "debug"
    output = "build/myproject"
    modules = ["src"]
}
```

`src/lib.crl`:

```crl
# public surface of src
```

### `coralc map`

Walks `root/`, finds every folder containing `lib.crl`, and:

- adds any missing folder to `modules = [...]`
- removes any listed folder with no `lib.crl`
- refreshes `modules.map`
- reports the diff

```
$ coralc map
+ added   coral-module
+ added   coral-context
~ updated modules.map  (14 entries, 3 aliases)
```

With `--dry`, prints but doesn't write.

---

## 12. Caching

Each module gets a fingerprint:

```
fingerprint(module) = hash(
    hash(every .crlin module folder, sorted),
    hash(lib.crl),
    for each dep in module: fingerprint(dep),
    build_flags_for(module),
    compiler_version,
)
```

Stored in `.coral/cache/<module>.fp`. On build:

- fingerprint match → skip compilation
- mismatch → recompile, cascade to dependents

`coralc clean` wipes `.coral/cache/`.

---

## 13. Reference builder pseudocode

```pseudo
function build(build_file):
    cfg = parse_crlb(build_file)
    root = cfg.root
    modules = cfg.modules
    skip = cfg.skip or []
    aliases = cfg.aliases or {}

    # 1. scan lib.crlfiles
    table = {}                       # "folder::name" → path
    for m in modules:
        libpath = join(root, m, "lib.crl")
        if not exists(libpath):
            error E1001(m, libpath)
        src = read(libpath)
        for (name, path) in scan_pub_mod(src):
            resolved = resolve_path(join(root, m), path)
            if resolved == null:
                error E1004(libpath, path)
            key = m + "::" + name
            if key in table:
                error E1002(key, table[key], resolved)
            table[key] = resolved

    # 2. validate aliases
    for (alias_name, target_folder) in aliases:
        if target_folder not in modules:
            error E1003(alias_name, target_folder)

    # 3. write modules.map (aliased + unaliased)
    emit_map(table, aliases)

    # 4. build import graph
    edges = {}                       # module → set(module)
    for m in modules:
        for file in walk_crl(join(root, m), skip):
            for imp in scan_module_imports(file):
                # imp looks like "lexer::table" or "common"
                folder = resolve_module(imp, table, aliases)
                if folder == null:
                    error E1005(file, imp)
                if folder != m:
                    edges[m].add(folder)

    # 5. cycle check
    if cycle = find_cycle(edges):
        error E1006(cycle)

    # 6. topo-sort
    order = topo_sort(edges)

    # 7. compile
    for m in order:
        fp = fingerprint(m, edges[m])
        if cached(m, fp) and not force:
            continue
        sources = walk_crl(join(root, m), skip)
        run("coralc",
            "--module-map", ".coral/modules.map",
            "--emit-obj",
            "--target", cfg.target,
            "--opt", cfg.opt,
            *module_flags(m, cfg),
            *sources)
        store_cache(m, fp)

    # 8. link
    link(cfg.entry, cfg.output)

    # 9. tasks
    run_pending_tasks(cfg, triggered_by="build")
```

---

## 14. Summary of design decisions

| Decision | Choice | Why |
|---|---|---|
| Build file extension | `.crlb` | Distinct from source |
| Build file syntax | Block + `key = value` | Familiar, readable, diff-friendly |
| Module list | Explicit (`modules = [...]`) | Deterministic, alias anchor, skip = not listed |
| Aliases | In build file | Short imports, no folder names in source |
| Compiler walks tree? | No | Only builder walks; compiler reads `modules.map` |
| Module map location | `.coral/modules.map` | Well-known, overridable |
| Module map format | Line-oriented text | Diffable, greppable, fast |
| `lib.crl` role | Source + re-export surface | Builder reads only `pub mod` lines |
| Path imports | `import "x"` | Compiler-local, sibling files |
| Module imports | `import x::y` | Builder-resolved via map |
| Caching | Fingerprint per module | Cascades through deps |
| Scaffolding | `coralc init`, `coralc map` | Zero to working project, auto-refresh |

---

If you want, next I can:

- write the **lexer/parser for `.crlb`** in your `.crl` language,
- or write the **`modules.map` reader** that `coralc` uses,
- or add a **`workspace`** concept (multiple `.crlb` files, one root).


// priority
another thing, importing wia string paths, woulld require a binding to a module alias, because the item is nameless