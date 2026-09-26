# crlbc — a lexer + parser for the `.crlb` format

A hand-written, no-STL lexer and recursive-descent parser for the full v2
`.crlb` grammar (the "Full .crlb grammar (v2)" write-up, i.e. the original
grammar plus every addition folded in: `schema`, `strict`, `workspace`,
`profile`, `extends`, `target`/`link`/`artifact`, `features`, `env`, `phase`,
`hook`, `test`/`bench`, `log`/`metrics`, `lint`/`format`/`lsp`, `ci`,
`remote`, `deps`).

## Build & run

```sh
g++ -std=c++17 -Wall -Wextra -O2 -o crlbc lexer.cpp parser.cpp main.cpp
./crlbc example.crlb        # parses a file and dumps the AST
./crlbc                     # no args: parses a small embedded demo string
```

`example.crlb` is the full canonical v2 example from the spec, verbatim; it
parses cleanly and every construct in it round-trips into the AST dump.
`v1_example_fixed.crlb` is the original (pre-v2) canonical example.

## "No std", structs not classes

- No STL: no `std::string`, `std::vector`, `std::map`, `iostream`, smart
  pointers, exceptions. Just the C library (`malloc`/`free`, `memcpy`,
  `strlen`, `fopen`/`fread`, `printf`-family) plus hand-rolled types:
  - `Str` — a length-prefixed string slice (`str.h`).
  - `Arena` — a bump allocator; every AST node, string, and dynamic array
    is carved out of it, and the whole thing is freed in one call
    (`arena.h`).
  - `DynArray<T>` — a minimal growable array template backed by the arena
    (`dynarray.h`). A template is used instead of `void*` + element size
    for type safety; templates are a core-language feature, not part of
    the standard *library*.
- Everything is a `struct`, nothing is a `class`. Where behavior is needed
  (lexer, parser), it's free functions taking a pointer to the struct
  (`lexer_next(Lexer*)`, `parse_file(Parser*)`), not member functions —
  this is composition (structs holding other structs/arrays, functions
  operating on them) with no inheritance anywhere.
- `Value` (the STRING/NUMBER/BOOL/LIST value type) is written as a plain
  tagged struct rather than a real C++ `union`, because one of its members
  (`ValueList*`, for the LIST case) would be fine in a union too, but the
  struct form makes the AST-dumping code in `main.cpp` simpler to read
  without changing any of the "struct + arena + composition" constraints.
  If you'd rather it be a real `union`, that's a one-line change to
  `ast.h` since every member is already a POD.

## Design: one generic `Node`, not ~25 bespoke structs

The grammar has ~15 top-level declaration kinds and ~10 block kinds, but
almost every one of them reduces to the same shape: an optional string
label, an optional `extends` target, and a body that's a mix of
`IDENT = value ;` fields and a handful of nested blocks. Rather than
writing a distinct struct per declaration (`BuildDecl`, `TaskDecl`,
`TestDecl`, ...), the parser builds a single generic `Node` (see `ast.h`)
tagged with a `NodeKind`, plus generic `Field` entries for every
`IDENT = value ;`-shaped construct (this covers plain fields, `modules`/
`skip`, `provides`/`requires`/`exclude`/`include`/`features` inside
`override`, `feature_decl` entries, `env` pairs, `doc` fields, and
`dep_field` entries — they're all structurally identical). This mirrors
the spec's own stated philosophy that the *parser* accepts more than is
semantically valid and leaves enforcement to "the builder" — e.g. the
spec notes that `phase` requires `on`/`run` but "the parser doesn't"
enforce it, and that `deps`/`remote` are "parsed but not evaluated". This
parser applies that same leniency uniformly: a block's body will
structurally accept a stray nested block or field that the strict
per-production grammar wouldn't allow there (e.g. an `env {}` typo'd
inside a `bench` block), rather than special-casing which nested blocks
are legal in which parent.

## Two things flagged in the grammar text itself

While implementing this against the exact EBNF, two inconsistencies
between the *grammar* and the *canonical example* showed up. Both are
resolved by following the example (since that's clearly the intended
usage), and are worth knowing about if the grammar doc gets revised:

1. `top_decl` (the top-level alternation) lists `build_decl | workspace_decl
   | alias_decl | task_decl | test_decl | bench_decl | hook_decl |
   profile_decl | include_decl | lsp_decl | format_decl | ci_decl |
   remote_decl | deps_decl` — but the canonical v2 example also uses
   `phase "..." { ... }`, `lint { ... }`, and top-level `override "..." {
   ... }` outside of any `build`. This parser accepts all three at the top
   level, matching the example rather than the (incomplete) alternation.

2. `field = IDENT "=" value ";"` requires a trailing `;`, and the v2
   canonical example is punctuated that way throughout. The *original*
   (pre-v2) example in the first write-up, however, omits the semicolons
   after plain fields (`root = "compiler/"` with no `;`) even though it's
   governed by the same `field` production. This parser follows the EBNF
   (and the v2 example) and requires the `;` — seemingly the original
   example was just typed without it, and there's no textual boundary
   (whitespace isn't otherwise significant) that would let a parser
   recover the field boundary if the semicolon were truly optional.

## The one real ambiguity: `target`

`target` is both a reserved plain field (`target = "native-x86_64";`, the
build architecture) *and* the v2 block keyword (`target "corald" { ... }`,
one of several build outputs) — and the canonical example uses both forms
in the same `build` block. The parser resolves this with one token of
extra lookahead: if the token right after `target` is `=`, it's the plain
field; otherwise (a `STRING` label or `{`) it's the block. The same
lookahead machinery also disambiguates `env` (`env = { ... };` the block,
vs. a hypothetical plain field literally named `env`) by checking that a
`{` follows the `=`.

## Files

| File | Contents |
|---|---|
| `arena.h` | Bump allocator |
| `str.h` | `Str` string-slice type |
| `dynarray.h` | `DynArray<T>` growable array |
| `token.h` | `TokenKind`, `Token` |
| `lexer.h` / `lexer.cpp` | Tokenizer |
| `ast.h` | `Value`, `Field`, `NodeKind`, `Node` |
| `parser.h` / `parser.cpp` | Recursive-descent parser → `Node*` AST |
| `main.cpp` | CLI driver: reads a file, parses it, dumps the AST |
| `example.crlb` | The full canonical v2 example, used as a test file |
