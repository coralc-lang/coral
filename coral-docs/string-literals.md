# String literal convention — handoff

Status: requirement agreed, NOT yet implemented anywhere. The lexer does not
support `C"..."` yet and the compiler does not enforce any of this yet. The
library sweep below may run ahead of the lexer (converted files will not parse
until lexer support lands — sequence the lexer first or together).

## Requirements (from the user)

1. Every string literal must be specified with its type.
2. C-style strings (nul-terminated, no length) use a new `C"..."` literal form.
   The lexer must gain the necessary tokens and support for it.
3. Any other string literal must have a length attached to it.
4. The compiler will be made to enforce all of this — code is being brought
   into convention ahead of enforcement.

## Work items

### Compiler (deferred — out of scope for library agents, `compiler/` stays untouched)

- Lexer: token for `C"..."` alongside the existing string token; support for
  explicitly typed literals; support for a length attached to non-C literals.
- Parser/typechecker: `C"..."` has C-string type (nul-terminated, no len, bare
  pointer / char semantics); every other literal must carry its type and len;
  reject untyped or len-less non-C literals.
- Enforcement across the toolchain once the above lands.

### Library sweep (can start now — this is what the string agent does)

- Areas: `lib/std/`, `lib/core/`, `lib/platform/`, `lib/wallvm/` (excluding
  directories owned by concurrent agents: `wallvm/passes/`, `wallvm/regalloc/`,
  `wallvm/rules/`, `wallvm/target/wasm/`).
- Find every place a C-style string is used without a length — extern library
  and symbol clauses, arguments handed to libc/C functions, printf-style format
  strings, environment/symbol names, anything that must be nul-terminated — and
  rewrite those literals to `C"..."`.
- Every other literal stays a len-carrying literal (its explicit type + attached
  length comes with the future syntax rule); do not invent any other new forms.
- Ambiguity policy: convert only clearly C-style sites; list everything
  ambiguous in the report instead of guessing. User stylistic content (e.g.
  `pub str* NAME[] = { ... }` arrays) is never fought — report it.
- Out of scope: the IR text grammar (IR.md) and the meaning of strings inside
  IR files are governed by the IR spec, not by this convention; `compiler/`
  untouched; manifest/config tables untouched.

### Verification

- `python3 /tmp/opencode/check_crl.py <edited files>` must PASS after edits.
- Report: converted sites (file:line, before → after, why C-style), ambiguous
  sites left alone, counts per area, assumptions.

## Open questions

- Exact spelling/shape of the type annotation and the attached length on
  non-C literals (TBD by the lexer work).
- Whether pointer-array initializers (`pub str* NAME[] = { ... }`) count as
  C-style or len-style (they look C-ish; likely C, confirm with the user).
