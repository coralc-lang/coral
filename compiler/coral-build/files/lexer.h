#pragma once
#include "token.h"
#include "arena.h"

// IDENT      = /[A-Za-z_][A-Za-z0-9_-]*/
// STRING     = '"' { [^"\\] | "\\" . } '"'
// NUMBER     = /[0-9]+/
// BOOL       = "true" | "false"     (lexed as identifiers, reclassified)
// comment    = "#" { [^\n] }
//
// Keywords (build, workspace, task, extends, ...) are NOT special-cased by
// the lexer -- they come back as plain TK_IDENT tokens, exactly like the
// EBNF's quoted-terminal convention implies (they match the IDENT pattern).
// The parser is what knows which identifier text means what.
struct Lexer {
    const char* src;
    long len;
    long pos;
    long line;
    long col;
    Arena* arena;
    bool hadError;
};

void lexer_init(Lexer* lx, const char* src, long len, Arena* arena);
Token lexer_next(Lexer* lx);
