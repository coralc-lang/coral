#pragma once
#include "lexer.h"
#include "ast.h"

// Recursive-descent parser for the full .crlb v2 grammar. Every grammar
// production is a method on Parser, called as `self->parseThing()` --
// there is no `parse_thing(Parser* p)` free-function style anywhere, and
// no argument is ever "the object itself" (compare the old lexer_next(&lx)
// style, which this deliberately replaces).
struct Parser {
    Lexer lex;
    Arena* arena;

    Token cur;         // current token
    Token la1;         // one token beyond cur, filled lazily
    bool hasLa1;
    Token la2;         // two tokens beyond cur, filled lazily
    bool hasLa2;

    bool hadError;
    char errMsg[512];
    i64 errLine;
    i64 errCol;

    void init(char* src, i64 len, Arena* arena);
    Node* parseFile();

    // --- token-stream helpers ---
    void advance();
    TokenKind peek1Kind();
    TokenKind peek2Kind();
    bool check(TokenKind k) const;
    bool checkIdent(const char* text) const;
    Token expect(TokenKind k, const char* what);
    void errorAt(const char* msg);
    bool isBlockKeywordHere(const char* text);

    Node* newNode(NodeKind kind);

    // --- values ---
    Value parseValue();
    Value parseList();

    // --- bodies / nested blocks ---
    void parseBody(Node* owner);
    Node* parseOverride();
    Node* parseEnv();
    Node* parseTarget();
    Node* parseLink();
    Node* parseArtifact();
    Node* parseFeatures();
    Node* parseLog();
    Node* parseMetrics();

    // --- top-level decls ---
    Node* parseLabeledBlock(NodeKind kind, bool allowExtends);
    Node* parseUnlabeledBlock(NodeKind kind);
    Node* parseAlias();
    Node* parseInclude();
    Node* parseSchema();
    Node* parseStrict();
    Node* parseDeps();
    Node* parseTopDecl();
};
