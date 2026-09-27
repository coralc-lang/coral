#pragma once
#include "types.h"
#include "token.h"

// A build tool's lexer is on the hot path (it re-runs on every invocation,
// on every file in the project), so it does no allocation at all:
//
//   - identifiers, numbers, and punctuation are always zero-copy slices
//     directly into the source buffer.
//   - a quoted string with no escapes is also a zero-copy slice.
//   - a quoted string WITH escapes is decoded in place: since resolving an
//     escape (\n, \", \\, ...) only ever shortens the text, we can write
//     the decoded bytes backwards over the same span we're reading from,
//     with a read cursor always at or ahead of the write cursor. No heap
//     buffer, no arena, nothing -- this is why `src` below is a mutable
//     char*, not `const char*`.
//
// (The earlier version of this lexer allocated a fresh arena buffer sized
// to the entire *remaining length of the file* for every single string
// token, even ones with no escapes. That's not just wasted allocation,
// it's O(remaining-file-size) work per string literal. This version does
// none of that.)
struct Lexer {
    char* src;
    i64 len;
    i64 pos;
    i64 line;
    i64 col;
    bool hadError;

    void init(char* src, i64 len);
    Token next();

    char peek() const;
    char advance();
    void skipWsAndComments();
};
