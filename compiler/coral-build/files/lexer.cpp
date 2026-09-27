#include "lexer.h"

static bool isIdentStart(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_';
}
static bool isIdentCont(char c) {
    return isIdentStart(c) || (c >= '0' && c <= '9') || c == '-';
}
static bool isDigit(char c) { return c >= '0' && c <= '9'; }

void Lexer::init(char* src, i64 len) {
    self->src = src;
    self->len = len;
    self->pos = 0;
    self->line = 1;
    self->col = 1;
    self->hadError = false;
}

char Lexer::peek() const {
    if (self->pos >= self->len) return 0;
    return self->src[self->pos];
}

char Lexer::advance() {
    char c = self->src[self->pos];
    self->pos = self->pos + 1;
    if (c == '\n') { self->line = self->line + 1; self->col = 1; }
    else { self->col = self->col + 1; }
    return c;
}

void Lexer::skipWsAndComments() {
    for (;;) {
        char c = self->peek();
        if (c == ' ' || c == '\t' || c == '\r' || c == '\n') { self->advance(); continue; }
        if (c == '#') {
            while (self->peek() != 0 && self->peek() != '\n') self->advance();
            continue;
        }
        break;
    }
}

Token Lexer::next() {
    self->skipWsAndComments();

    Token t;
    t.kind = TK_EOF;
    t.text.ptr = 0; t.text.len = 0;
    t.line = self->line; t.col = self->col;
    t.numValue = 0; t.boolValue = false;

    if (self->pos >= self->len) { t.kind = TK_EOF; return t; }

    char c = self->peek();

    if (c == '{') { self->advance(); t.kind = TK_LBRACE;   return t; }
    if (c == '}') { self->advance(); t.kind = TK_RBRACE;   return t; }
    if (c == '[') { self->advance(); t.kind = TK_LBRACKET; return t; }
    if (c == ']') { self->advance(); t.kind = TK_RBRACKET; return t; }
    if (c == '=') { self->advance(); t.kind = TK_EQUALS;   return t; }
    if (c == ';') { self->advance(); t.kind = TK_SEMI;     return t; }
    if (c == ',') { self->advance(); t.kind = TK_COMMA;    return t; }

    if (c == '"') {
        self->advance(); // opening quote
        i64 start = self->pos;
        i64 writePos = start; // trails `pos` only once an escape is seen

        for (;;) {
            char cc = self->peek();
            if (cc == 0) { self->hadError = true; t.kind = TK_ERROR; return t; }
            if (cc == '"') { self->advance(); break; }

            if (cc == '\\') {
                self->advance(); // the backslash
                char esc = self->peek();
                if (esc == 0) { self->hadError = true; t.kind = TK_ERROR; return t; }
                self->advance(); // the escaped character

                char decoded;
                switch (esc) {
                    case 'n':  decoded = '\n'; break;
                    case 't':  decoded = '\t'; break;
                    case 'r':  decoded = '\r'; break;
                    case '"':  decoded = '"';  break;
                    case '\\': decoded = '\\'; break;
                    default:   decoded = esc;  break;
                }
                self->src[writePos] = decoded;
                writePos = writePos + 1;
                continue;
            }

            // Ordinary character. While writePos == pos (no escape seen
            // yet) this is a self-assignment of one byte -- effectively
            // free, and definitely not a heap allocation.
            self->src[writePos] = cc;
            writePos = writePos + 1;
            self->advance();
        }

        i64 outLen = writePos - start;
        t.kind = TK_STRING;
        t.text = Str::make(self->src + start, outLen);
        return t;
    }

    if (isDigit(c)) {
        i64 start = self->pos;
        while (isDigit(self->peek())) self->advance();
        i64 l = self->pos - start;
        t.kind = TK_NUMBER;
        t.text = Str::make(self->src + start, l);
        i64 v = 0;
        for (i64 i = 0; i < l; i = i + 1) v = v * 10 + (self->src[start + i] - '0');
        t.numValue = v;
        return t;
    }

    if (isIdentStart(c)) {
        i64 start = self->pos;
        while (isIdentCont(self->peek())) self->advance();
        i64 l = self->pos - start;
        Str txt = Str::make(self->src + start, l);
        if (txt.equalsCstr("true"))  { t.kind = TK_BOOL; t.boolValue = true;  t.text = txt; return t; }
        if (txt.equalsCstr("false")) { t.kind = TK_BOOL; t.boolValue = false; t.text = txt; return t; }
        t.kind = TK_IDENT;
        t.text = txt;
        return t;
    }

    // Unknown character.
    self->advance();
    self->hadError = true;
    t.kind = TK_ERROR;
    t.text = Str::make(self->src + (self->pos - 1), 1);
    return t;
}
