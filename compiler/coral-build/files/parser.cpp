#include "parser.h"
#include <cstring>

// ─────────────────────────── token-stream helpers ──────────────────────────

void Parser::advance() {
    if (self->hasLa1) {
        self->cur = self->la1;
        if (self->hasLa2) {
            self->la1 = self->la2;
            self->hasLa2 = false;
            // hasLa1 stays true
        } else {
            self->hasLa1 = false;
        }
    } else {
        self->cur = self->lex.next();
    }
}

// One and two tokens of lookahead beyond `cur`, filled lazily. Needed
// because a couple of keywords are genuinely ambiguous with only one
// token of lookahead -- most notably "target", which is both a reserved
// plain field (`target = "native-x86_64";`, the build architecture) *and*
// a nested block keyword (`target "coralc" { ... }`, one of several build
// outputs). The two forms only diverge at the token right after the
// keyword: '=' means a plain field, anything else means a block.
TokenKind Parser::peek1Kind() {
    if (!self->hasLa1) { self->la1 = self->lex.next(); self->hasLa1 = true; }
    return self->la1.kind;
}
TokenKind Parser::peek2Kind() {
    self->peek1Kind();
    if (!self->hasLa2) { self->la2 = self->lex.next(); self->hasLa2 = true; }
    return self->la2.kind;
}

bool Parser::check(TokenKind k) const {
    return self->cur.kind == k;
}

bool Parser::checkIdent(const char* text) const {
    return self->cur.kind == TK_IDENT && self->cur.text.equalsCstr(text);
}

Token Parser::expect(TokenKind k, const char* what) {
    Token t = self->cur;
    if (self->cur.kind != k) {
        self->errorAt(what);
        return t;
    }
    self->advance();
    return t;
}

void Parser::errorAt(const char* msg) {
    if (self->hadError) return; // keep the first error
    self->hadError = true;
    self->errLine = self->cur.line;
    self->errCol = self->cur.col;
    i64 n = (i64)strlen(msg);
    if (n > 500) n = 500;
    memcpy(self->errMsg, msg, (u64)n);
    self->errMsg[n] = 0;
}

// True for keywords that introduce a nested block *unless* they're
// immediately followed by '=', in which case they're just an ordinary
// "name = value ;" field (this is how "target" is reused as both the
// reserved `target = "native-x86_64";` field and the
// `target "corald" { ... }` block keyword).
bool Parser::isBlockKeywordHere(const char* text) {
    if (!self->checkIdent(text)) return false;
    return self->peek1Kind() != TK_EQUALS;
}

Node* Parser::newNode(NodeKind kind) {
    Node* n = (Node*)self->arena->alloc((i64)sizeof(Node), (i64)alignof(Node));
    n->init(kind, self->arena);
    return n;
}

// ─────────────────────────────── value / list ──────────────────────────────
// value = STRING | NUMBER | BOOL | list ;
// list  = "[" [ value { "," value } [ "," ] ] "]" ;

Value Parser::parseList() {
    self->expect(TK_LBRACKET, "expected '[' to start a list");

    ValueArray* arr = (ValueArray*)self->arena->alloc((i64)sizeof(ValueArray), (i64)alignof(ValueArray));
    arr->init(self->arena);

    if (!self->check(TK_RBRACKET)) {
        for (;;) {
            Value item = self->parseValue();
            if (self->hadError) break;
            arr->push(item);
            if (self->check(TK_COMMA)) {
                self->advance();
                if (self->check(TK_RBRACKET)) break; // trailing comma allowed
                continue;
            }
            break;
        }
    }
    self->expect(TK_RBRACKET, "expected ']' to close a list");
    return Value::ofList(arr);
}

Value Parser::parseValue() {
    if (self->check(TK_STRING)) { Value v = Value::ofString(self->cur.text);   self->advance(); return v; }
    if (self->check(TK_NUMBER)) { Value v = Value::ofNumber(self->cur.numValue); self->advance(); return v; }
    if (self->check(TK_BOOL))   { Value v = Value::ofBool(self->cur.boolValue);  self->advance(); return v; }
    if (self->check(TK_LBRACKET)) { return self->parseList(); }
    self->errorAt("expected a value (string, number, true/false, or a list)");
    return Value::ofString(Str::make(0, 0));
}

// ────────────────────────────── nested blocks ──────────────────────────────
// The leading keyword identifier ("override", "env", "target", ...) has
// already been consumed by the caller (parseBody) by the time each of
// these methods runs.

// env_block = "env" "=" "{" { env_pair } "}" ";"
// env_pair  = IDENT "=" STRING ";"
Node* Parser::parseEnv() {
    Node* n = self->newNode(NK_ENV);
    self->expect(TK_EQUALS, "expected '=' after 'env'");
    self->expect(TK_LBRACE, "expected '{' to start env block");
    while (!self->check(TK_RBRACE) && !self->check(TK_EOF) && !self->hadError) {
        Token nameTok = self->expect(TK_IDENT, "expected identifier as env key");
        self->expect(TK_EQUALS, "expected '=' after env key");
        Token valTok = self->expect(TK_STRING, "expected string value in env block");
        self->expect(TK_SEMI, "expected ';' after env value");
        n->addField(nameTok.text, Value::ofString(valTok.text));
    }
    self->expect(TK_RBRACE, "expected '}' to close env block");
    self->expect(TK_SEMI, "expected ';' after env block");
    return n;
}

// link_block = "link" [ STRING ] "{" { link_field } "}" ;
Node* Parser::parseLink() {
    Node* n = self->newNode(NK_LINK);
    if (self->check(TK_STRING)) { n->label = self->cur.text; n->hasLabel = true; self->advance(); }
    self->expect(TK_LBRACE, "expected '{' after 'link'");
    self->parseBody(n);
    self->expect(TK_RBRACE, "expected '}' to close link block");
    return n;
}

// artifact_block = "artifact" [ STRING ] "{" { artifact_field } "}" ;
Node* Parser::parseArtifact() {
    Node* n = self->newNode(NK_ARTIFACT);
    if (self->check(TK_STRING)) { n->label = self->cur.text; n->hasLabel = true; self->advance(); }
    self->expect(TK_LBRACE, "expected '{' after 'artifact'");
    self->parseBody(n);
    self->expect(TK_RBRACE, "expected '}' to close artifact block");
    return n;
}

// features_block = "features" "{" { feature_decl } "}" ;
// feature_decl   = IDENT "=" list ";"   -- fits the generic field loop.
Node* Parser::parseFeatures() {
    Node* n = self->newNode(NK_FEATURES);
    self->expect(TK_LBRACE, "expected '{' after 'features'");
    self->parseBody(n);
    self->expect(TK_RBRACE, "expected '}' to close features block");
    return n;
}

// log_block = "log" "{" { log_field } "}" ;
Node* Parser::parseLog() {
    Node* n = self->newNode(NK_LOG);
    self->expect(TK_LBRACE, "expected '{' after 'log'");
    self->parseBody(n);
    self->expect(TK_RBRACE, "expected '}' to close log block");
    return n;
}

// metrics_block = "metrics" "{" { metrics_field } "}" ;
Node* Parser::parseMetrics() {
    Node* n = self->newNode(NK_METRICS);
    self->expect(TK_LBRACE, "expected '{' after 'metrics'");
    self->parseBody(n);
    self->expect(TK_RBRACE, "expected '}' to close metrics block");
    return n;
}

// target_block = "target" STRING "{" { target_field } "}" ;
Node* Parser::parseTarget() {
    Node* n = self->newNode(NK_TARGET);
    Token lbl = self->expect(TK_STRING, "expected string label after 'target'");
    n->label = lbl.text; n->hasLabel = true;
    self->expect(TK_LBRACE, "expected '{' after target label");
    self->parseBody(n);
    self->expect(TK_RBRACE, "expected '}' to close target block");
    return n;
}

// override_block = "override" STRING "{" { override_field } "}" ;
Node* Parser::parseOverride() {
    Node* n = self->newNode(NK_OVERRIDE);
    Token lbl = self->expect(TK_STRING, "expected string label after 'override'");
    n->label = lbl.text; n->hasLabel = true;
    self->expect(TK_LBRACE, "expected '{' after override label");
    self->parseBody(n);
    self->expect(TK_RBRACE, "expected '}' to close override block");
    return n;
}

// Shared body loop used by every brace-delimited block. Every *_field
// production in the grammar (build_field, workspace_field, profile_field,
// task_field, test_field, bench_field, hook_field, phase_field,
// target_field, link_field, artifact_field, override_field, log_field,
// metrics_field, lint_field, format_field, lsp_field, ci_field,
// remote_field, feature_decl, dep_field) reduces to either a nested block
// (override/env/target/link/artifact/features/log/metrics) or a plain
// "IDENT = value ;" field.
//
// This is intentionally more permissive than the exact per-production
// grammar (it would accept a stray `env = {...};` inside a `bench` block,
// which the strict grammar disallows there). The spec's own design notes
// say structural validity beyond this is the builder's job, not the
// parser's -- this parser follows that philosophy uniformly.
void Parser::parseBody(Node* owner) {
    while (!self->check(TK_RBRACE) && !self->check(TK_EOF) && !self->hadError) {
        // "env" is doubly ambiguous: `env = { ... };` is the nested block,
        // but nothing stops a plain field literally named env, so we also
        // check that '{' follows the '='.
        if (self->checkIdent("env") && self->peek1Kind() == TK_EQUALS && self->peek2Kind() == TK_LBRACE) {
            self->advance(); owner->addChild(self->parseEnv()); continue;
        }
        if (self->isBlockKeywordHere("override")) { self->advance(); owner->addChild(self->parseOverride()); continue; }
        if (self->isBlockKeywordHere("target"))   { self->advance(); owner->addChild(self->parseTarget());   continue; }
        if (self->isBlockKeywordHere("link"))     { self->advance(); owner->addChild(self->parseLink());     continue; }
        if (self->isBlockKeywordHere("artifact")) { self->advance(); owner->addChild(self->parseArtifact()); continue; }
        if (self->isBlockKeywordHere("features")) { self->advance(); owner->addChild(self->parseFeatures()); continue; }
        if (self->isBlockKeywordHere("log"))      { self->advance(); owner->addChild(self->parseLog());      continue; }
        if (self->isBlockKeywordHere("metrics"))  { self->advance(); owner->addChild(self->parseMetrics());  continue; }

        if (!self->check(TK_IDENT)) { self->errorAt("expected a field name or nested block"); break; }
        Token nameTok = self->cur;
        self->advance();
        self->expect(TK_EQUALS, "expected '=' after field name");
        Value v = self->parseValue();
        self->expect(TK_SEMI, "expected ';' after field value");
        owner->addField(nameTok.text, v);
    }
}

// ───────────────────────────── top-level decls ─────────────────────────────

Node* Parser::parseLabeledBlock(NodeKind kind, bool allowExtends) {
    Node* n = self->newNode(kind);
    Token lbl = self->expect(TK_STRING, "expected a string label");
    n->label = lbl.text; n->hasLabel = true;
    if (allowExtends && self->checkIdent("extends")) {
        self->advance();
        Token ext = self->expect(TK_STRING, "expected a string after 'extends'");
        n->extendsTarget = ext.text; n->hasExtends = true;
    }
    self->expect(TK_LBRACE, "expected '{'");
    self->parseBody(n);
    self->expect(TK_RBRACE, "expected '}'");
    return n;
}

Node* Parser::parseUnlabeledBlock(NodeKind kind) {
    Node* n = self->newNode(kind);
    self->expect(TK_LBRACE, "expected '{'");
    self->parseBody(n);
    self->expect(TK_RBRACE, "expected '}'");
    return n;
}

// alias_decl = "alias" IDENT "=" STRING ";"
Node* Parser::parseAlias() {
    Node* n = self->newNode(NK_ALIAS);
    Token nameTok = self->expect(TK_IDENT, "expected an identifier after 'alias'");
    n->label = nameTok.text; n->hasLabel = true;
    self->expect(TK_EQUALS, "expected '=' after alias name");
    Token target = self->expect(TK_STRING, "expected a string after '=' in alias");
    n->payload = target.text; n->hasPayload = true;
    self->expect(TK_SEMI, "expected ';' after alias declaration");
    return n;
}

// include_decl = "include" STRING ";"
Node* Parser::parseInclude() {
    Node* n = self->newNode(NK_INCLUDE);
    Token path = self->expect(TK_STRING, "expected a string after 'include'");
    n->payload = path.text; n->hasPayload = true;
    self->expect(TK_SEMI, "expected ';' after include declaration");
    return n;
}

// schema_decl = "schema" "=" NUMBER ";"
Node* Parser::parseSchema() {
    Node* n = self->newNode(NK_SCHEMA);
    self->expect(TK_EQUALS, "expected '=' after 'schema'");
    Token num = self->expect(TK_NUMBER, "expected a number after 'schema ='");
    self->expect(TK_SEMI, "expected ';' after schema declaration");
    n->addField(Str::fromCstr("value"), Value::ofNumber(num.numValue));
    return n;
}

// strict_decl = "strict" "=" BOOL ";"
Node* Parser::parseStrict() {
    Node* n = self->newNode(NK_STRICT);
    self->expect(TK_EQUALS, "expected '=' after 'strict'");
    Token b = self->expect(TK_BOOL, "expected true/false after 'strict ='");
    self->expect(TK_SEMI, "expected ';' after strict declaration");
    n->addField(Str::fromCstr("value"), Value::ofBool(b.boolValue));
    return n;
}

// deps_decl = "deps" "{" { dep_entry } "}" ;
// dep_entry = STRING "=" "{" { dep_field } "}" ";"
Node* Parser::parseDeps() {
    Node* n = self->newNode(NK_DEPS);
    self->expect(TK_LBRACE, "expected '{' after 'deps'");
    while (self->check(TK_STRING) && !self->hadError) {
        Token key = self->cur; self->advance();
        Node* entry = self->newNode(NK_DEP_ENTRY);
        entry->label = key.text; entry->hasLabel = true;
        self->expect(TK_EQUALS, "expected '=' after dependency key");
        self->expect(TK_LBRACE, "expected '{' after dependency key '='");
        self->parseBody(entry); // dep_field entries are plain fields
        self->expect(TK_RBRACE, "expected '}' to close dependency entry");
        self->expect(TK_SEMI, "expected ';' after dependency entry");
        n->addChild(entry);
    }
    self->expect(TK_RBRACE, "expected '}' to close deps block");
    return n;
}

// top_decl per the v2 grammar text: build | workspace | alias | task | test
// | bench | hook | profile | include | lsp | format | ci | remote | deps.
//
// Two things worth flagging about the grammar as given: `phase_decl` and
// `lint_decl` are defined as productions and used at the top level in the
// canonical v2 example, but are missing from the `top_decl` alternation
// itself, and a bare top-level `override "..." { ... }` (outside any
// `build`) is also used in the canonical example despite `override_block`
// only being listed as a `build_field` alternative. Those look like
// oversights in the grammar text rather than an intent to forbid them --
// this parser follows the canonical example and accepts all three at the
// top level.
Node* Parser::parseTopDecl() {
    if (self->checkIdent("schema"))    { self->advance(); return self->parseSchema(); }
    if (self->checkIdent("strict"))    { self->advance(); return self->parseStrict(); }
    if (self->checkIdent("build"))     { self->advance(); return self->parseLabeledBlock(NK_BUILD, true); }
    if (self->checkIdent("workspace")) { self->advance(); return self->parseLabeledBlock(NK_WORKSPACE, false); }
    if (self->checkIdent("profile"))   { self->advance(); return self->parseLabeledBlock(NK_PROFILE, true); }
    if (self->checkIdent("alias"))     { self->advance(); return self->parseAlias(); }
    if (self->checkIdent("task"))      { self->advance(); return self->parseLabeledBlock(NK_TASK, false); }
    if (self->checkIdent("test"))      { self->advance(); return self->parseLabeledBlock(NK_TEST, false); }
    if (self->checkIdent("bench"))     { self->advance(); return self->parseLabeledBlock(NK_BENCH, false); }
    if (self->checkIdent("hook"))      { self->advance(); return self->parseLabeledBlock(NK_HOOK, false); }
    if (self->checkIdent("phase"))     { self->advance(); return self->parseLabeledBlock(NK_PHASE, false); }
    if (self->checkIdent("override"))  { self->advance(); return self->parseOverride(); }
    if (self->checkIdent("include"))   { self->advance(); return self->parseInclude(); }
    if (self->checkIdent("lsp"))       { self->advance(); return self->parseUnlabeledBlock(NK_LSP); }
    if (self->checkIdent("format"))    { self->advance(); return self->parseUnlabeledBlock(NK_FORMAT); }
    if (self->checkIdent("ci"))        { self->advance(); return self->parseUnlabeledBlock(NK_CI); }
    if (self->checkIdent("remote"))    { self->advance(); return self->parseUnlabeledBlock(NK_REMOTE); }
    if (self->checkIdent("lint"))      { self->advance(); return self->parseUnlabeledBlock(NK_LINT); }
    if (self->checkIdent("deps"))      { self->advance(); return self->parseDeps(); }
    self->errorAt("unrecognized top-level declaration");
    return 0;
}

// ────────────────────────────────── driver ─────────────────────────────────

void Parser::init(char* src, i64 len, Arena* arena) {
    self->lex.init(src, len);
    self->arena = arena;
    self->hasLa1 = false;
    self->hasLa2 = false;
    self->hadError = false;
    self->errMsg[0] = 0;
    self->errLine = 0;
    self->errCol = 0;
    self->advance(); // prime the one-token lookahead
}

Node* Parser::parseFile() {
    Node* root = self->newNode(NK_ROOT);
    while (!self->check(TK_EOF) && !self->hadError) {
        Node* d = self->parseTopDecl();
        if (d == 0 || self->hadError) break;
        root->addChild(d);
    }
    return root;
}
