#pragma once
#include "lexer.h"
#include "ast.h"

struct Parser {
    Lexer lex;
    Token cur;          // current token, always valid after parser_init
    Token la1;          // one token beyond cur (lazily filled)
    bool hasLa1;
    Token la2;          // two tokens beyond cur (lazily filled)
    bool hasLa2;
    Arena* arena;
    bool hadError;
    char errMsg[512];
    long errLine;
    long errCol;
};

void parser_init(Parser* p, const char* src, long len, Arena* arena);

// Parses an entire .crlb file and returns the root node (kind == NK_ROOT).
// On error, p->hadError is set and p->errMsg/errLine/errCol describe it;
// the returned root may be partially populated.
Node* parse_file(Parser* p);
