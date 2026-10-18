# 🆕 NEW — Expand `coralc --serve`

**Status: action required. Nothing in this document is implemented yet.**

Both editor extensions are now fully wired for the features below. The
limiting factor is entirely on the compiler side.

- Editors: `/home/cerie/Documents/coral-vscode`, `/home/cerie/Documents/coral-zed`
- Full specification: [`PROTOCOL.md`](./PROTOCOL.md) — normative, with exact JSON
- Method audit: [`PROTOCOL.md` §11b](./PROTOCOL.md) — all 51 standard methods, current status

---

## Where the server actually stands

Verified by probing all 51 standard LSP requests plus 12 notifications against
`coralc 0.1.0` (`python3 tools/probe-lsp-surface.py`):

| | |
| --- | --- |
| Methods implemented | **1** — `textDocument/hover`, which returns `null` |
| Methods returning `-32601` | **50** |
| Crashes / hangs / corrupt stream | **none** |

Rejecting unknown methods correctly is half the contract and it is already
satisfied. What is missing is feature coverage.

The server also survives being sent `workspace/didChangeConfiguration`,
`notebookDocument/documentSymbol`, and `languageStatus` without complaint.

---

## Phase 1 — without these the editor feels dead

### 1. `publishDiagnostics`: send an empty array

**The single highest-value fix, and it is a few lines.**

The server only publishes when it has something to report. A document fixed
back to clean keeps its stale errors forever, because silence is not
"no errors".

```jsonc
// every didChange, unconditionally
{"method":"textDocument/publishDiagnostics",
 "params":{"uri":"file:///…","version":7,"diagnostics":[]}}
```

Also include `version` — both clients advertise `versionSupport`.

### 2. `textDocument/hover`

Already advertised; always returns `null`. Return the resolved type. For a
method this is the ideal answer:

```jsonc
{"contents":[{"language":"coral","value":"fn at(usize i) -> T"},
             "\nArray element access."],
 "range":{"start":{"line":4,"character":5},"end":{"line":4,"character":7}}}
```

`lspAnalyze` already exists in `coral_lsp::server` — the work is rendering its
result rather than discarding it. **Do not return `null` for a symbol you
recognise**; return `null` only where there genuinely is nothing.

### 3. `textDocument/documentSymbol`

`detail` is the declaration minus its body. Coral is type-first, so this is
what makes the outline readable:

```
T at(usize i)          not  at
pub struct Arr<T, N>
trait Rng<N>
```

| Coral | `SymbolKind` |
| --- | --- |
| `struct`, `union`, `extend`, `variant`, `enum` | 5 Class |
| `trait` | 11 Interface |
| functions, methods, constructors | 12 Function |
| fields, variant members | 8 Field |
| constants, locals | 13 Variable |

### 4. `textDocument/definition` + `textDocument/documentHighlight` + `textDocument/typeDefinition`

These share one name-resolution pass, so build them together.

Return `LocationLink[]` — both editors advertise `definition.linkSupport`, and
it carries `originSelectionRange` so the editor highlights the declaration
without a second round trip. `typeDefinition` is often the more useful jump in
a language with type parameters: from `T` to the `struct` that defines it.

### 5. `textDocument/completion` + `completionItem/resolve`

The largest daily-use win, and the most work — it needs a real scope table.

| Trigger | Completes |
| --- | --- |
| `.` | fields and methods, narrowed to the receiver's type |
| `::` | module paths, types, associated constants |
| `#[[` | attributes |
| identifier | declarations in scope |

Send a small list and fill `documentation` in `completionItem/resolve`.

---

## Phase 2 — what makes it feel like a real language

| Method | Why it matters here |
| --- | --- |
| `textDocument/semanticTokens/full` | **Only the compiler knows `T` is a type parameter.** Tree-sitter sees an identifier. This is how types get visually distinguished. |
| `textDocument/inlayHint` | Inferred types on bindings that do not state them. |
| `textDocument/signatureHelp` | Type-first declarations put the return type mid-signature: `at(usize i) -> T`. |
| `textDocument/codeAction` + `workspace/applyEdit` | Most Coral diagnostics are mechanical, so quick fixes are cheap and high value. |
| `textDocument/foldingRange` | Struct and function bodies. |
| `textDocument/references` | Shares the resolution pass with definition. |
| `window/showMessage` | **Report fatal setup problems instead of exiting silently.** A missing `build.crlb` currently produces no output at all. |
| `window/workDoneProgress/create` + `$/progress` | Whole-project indexing takes real time. |
| `languageStatus` | Compiler state in the editor status bar. |

---

## Phase 3 — Coral-specific opportunities

These are worth more here than in most languages:

- **`prepareTypeHierarchy` + `typeHierarchy/supertypes|subtypes`** — Coral has
  `trait` and `extend`. That is a genuine type hierarchy, and it is nearly free
  once name resolution exists.
- **`workspace/willRenameFiles`** — rename a `.crl` and rewrite the `import`
  statements that point at it.
- **`prepareCallHierarchy`** — callers and callees, valuable in a systems
  language.
- **`textDocument/declaration`** — distinct from `definition`. Coral has both
  declarations and definitions, so they are genuinely different answers.
- **`workspace/symbol`** — project-wide symbol search.

---

## Protocol requirements that are easy to get wrong

**Position encoding.** LSP 3.17 negotiates this. Both clients advertise UTF-16
code units; Coral sources are UTF-8, so any non-ASCII identifier or string
literal will be off by N. Echo the encoding you chose in `initialize`:

```jsonc
"positionEncoding": "utf-16"
```

**Empty diagnostics are the clearing mechanism.** See Phase 1.

**`-32601` for anything unimplemented.** Never ignore a request. An editor
waiting on a reply that never arrives is worse than one that knows the feature
is absent.

**`window/showMessage` is legal during `initialize`** — before the
`InitializeResult` is sent, it is one of five notifications a server may send.

**Diagnostics should not cascade.** Recover from a parse error and keep
analysing the rest of the file. One syntax error should not produce fifty.

---

## Known false positives to fix alongside

Both reproduce on unmodified, valid Coral in
`lib/std/x86_64/linux/collections/arr.crl`:

| Code | Message | Occurrences |
| --- | --- | --- |
| `T0002` | `cannot dereference this type` | 5 — on valid `self.data[i]` indexing |
| `P0002` | `array size must be an integer literal or a const int` | 1 — on `T data[N]`, valid when `N` is a generic parameter |

These are the only diagnostics the server emits across the sampled corpus, and
they are all wrong. **The tree-sitter grammar in `coral-zed` parses all 406
files at 94%** — the semantic pass is behind the real language, and it is the
critical path for every feature above.

---

## Do not implement

Permanent `-32601`, with reasons recorded so nobody re-litigates it:

`formatting`, `rangeFormatting`, `onTypeFormatting` (no formatter) ·
`codeLens` · `documentColor`, `colorPresentation` (no colour literals) ·
`documentLink` (no URLs in source) · `inlineValue` (debugger) ·
`linkedEditingRange` · `notebookDocument/*` (unless Coral notebooks exist).

---

## Editors are ready

The client work is done and gated by tests, so the above will light up without
further editor changes:

| Feature | VS Code | Zed |
| --- | --- | --- |
| Diagnostics | Problems panel + squiggles | gutter + problems panel |
| Hover | registered | via `hoverProvider` |
| Completion | registered, triggers `.` `::` `#[[` | via `completionProvider` |
| Definition / typeDefinition / references | registered | via capabilities |
| DocumentSymbol | registered, hierarchical | outline panel |
| SignatureHelp | registered | via `signatureHelpProvider` |
| SemanticTokens | registered | **needs `"semantic_tokens": "combined"`** — Zed defaults to `"off"` |
| InlayHint | registered | via `inlayHintProvider` |
| Rename, FoldingRange | registered | via capabilities |

Both extensions log which capabilities the server advertises on startup, so the
gap is visible in the editor log rather than having to be guessed at.

Zed's language server is declared by the extension itself
(`extension.toml` → `[language_servers.coral]`, resolved in `src/lib.rs`), so
there is nothing to configure. VS Code spawns `coralc --serve` itself.