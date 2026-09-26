#pragma once
#include "str.h"

enum TokenKind {
    TK_EOF,
    TK_IDENT,
    TK_STRING,
    TK_NUMBER,
    TK_BOOL,
    TK_LBRACE,
    TK_RBRACE,
    TK_LBRACKET,
    TK_RBRACKET,
    TK_EQUALS,
    TK_SEMI,
    TK_COMMA,
    TK_ERROR
};

struct Token {
    TokenKind kind;
    Str text;
    long line;
    long col;
    long long numValue;
    bool boolValue;
};
