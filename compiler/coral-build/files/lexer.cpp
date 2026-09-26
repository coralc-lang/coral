#include "lexer.h"

static char peekc(Lexer* lx) {
    if (lx->pos >= lx->len) return 0;
    return lx->src[lx->pos];
}

static char advc(Lexer* lx) {
    char c = lx->src[lx->pos];
    lx->pos = lx->pos + 1;
    if (c == '\n') { lx->line = lx->line + 1; lx->col = 1; }
    else { lx->col = lx->col + 1; }
    return c;
}

static void skip_ws_and_comments(Lexer* lx) {
    for (;;) {
        char c = peekc(lx);
        if (c == ' ' || c == '\t' || c == '\r' || c == '\n') { advc(lx); continue; }
        if (c == '#') {
            while (peekc(lx) != 0 && peekc(lx) != '\n') advc(lx);
            continue;
        }
        break;
    }
}

static bool is_ident_start(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_';
}
static bool is_ident_cont(char c) {
    return is_ident_start(c) || (c >= '0' && c <= '9') || c == '-';
}
static bool is_digit(char c) { return c >= '0' && c <= '9'; }

void lexer_init(Lexer* lx, const char* src, long len, Arena* arena) {
    lx->src = src;
    lx->len = len;
    lx->pos = 0;
    lx->line = 1;
    lx->col = 1;
    lx->arena = arena;
    lx->hadError = false;
}

Token lexer_next(Lexer* lx) {
    skip_ws_and_comments(lx);

    Token t;
    t.kind = TK_EOF;
    t.text.ptr = 0; t.text.len = 0;
    t.line = lx->line; t.col = lx->col;
    t.numValue = 0; t.boolValue = false;

    if (lx->pos >= lx->len) { t.kind = TK_EOF; return t; }

    char c = peekc(lx);

    if (c == '{') { advc(lx); t.kind = TK_LBRACE; return t; }
    if (c == '}') { advc(lx); t.kind = TK_RBRACE; return t; }
    if (c == '[') { advc(lx); t.kind = TK_LBRACKET; return t; }
    if (c == ']') { advc(lx); t.kind = TK_RBRACKET; return t; }
    if (c == '=') { advc(lx); t.kind = TK_EQUALS; return t; }
    if (c == ';') { advc(lx); t.kind = TK_SEMI; return t; }
    if (c == ',') { advc(lx); t.kind = TK_COMMA; return t; }

    if (c == '"') {
        advc(lx); // consume opening quote
        long remaining = lx->len - lx->pos;
        char* buf = (char*)arena_alloc(lx->arena, remaining + 1, 1);
        long outLen = 0;
        for (;;) {
            char cc = peekc(lx);
            if (cc == 0) { lx->hadError = true; t.kind = TK_ERROR; return t; }
            if (cc == '"') { advc(lx); break; }
            if (cc == '\\') {
                advc(lx);
                char esc = peekc(lx);
                if (esc == 0) { lx->hadError = true; t.kind = TK_ERROR; return t; }
                advc(lx);
                switch (esc) {
                    case 'n': buf[outLen] = '\n'; break;
                    case 't': buf[outLen] = '\t'; break;
                    case 'r': buf[outLen] = '\r'; break;
                    case '"': buf[outLen] = '"'; break;
                    case '\\': buf[outLen] = '\\'; break;
                    default: buf[outLen] = esc; break;
                }
                outLen = outLen + 1;
                continue;
            }
            buf[outLen] = cc;
            outLen = outLen + 1;
            advc(lx);
        }
        buf[outLen] = 0;
        t.kind = TK_STRING;
        t.text = str_make(buf, outLen);
        return t;
    }

    if (is_digit(c)) {
        long start = lx->pos;
        while (is_digit(peekc(lx))) advc(lx);
        long l = lx->pos - start;
        t.kind = TK_NUMBER;
        t.text = str_make(lx->src + start, l);
        long long v = 0;
        for (long i = 0; i < l; i = i + 1) v = v * 10 + (lx->src[start + i] - '0');
        t.numValue = v;
        return t;
    }

    if (is_ident_start(c)) {
        long start = lx->pos;
        while (is_ident_cont(peekc(lx))) advc(lx);
        long l = lx->pos - start;
        Str txt = str_make(lx->src + start, l);
        if (str_eq_cstr(txt, "true"))  { t.kind = TK_BOOL; t.boolValue = true;  t.text = txt; return t; }
        if (str_eq_cstr(txt, "false")) { t.kind = TK_BOOL; t.boolValue = false; t.text = txt; return t; }
        t.kind = TK_IDENT;
        t.text = txt;
        return t;
    }

    // Unknown character.
    advc(lx);
    lx->hadError = true;
    t.kind = TK_ERROR;
    t.text = str_make(lx->src + (lx->pos - 1), 1);
    return t;
}
