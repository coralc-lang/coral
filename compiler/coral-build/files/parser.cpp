#include "parser.h"
#include <cstring>

// ─────────────────────────── low-level helpers ────────────────────────────

static void advance(Parser* p) {
    if (p->hasLa1) {
        p->cur = p->la1;
        if (p->hasLa2) {
            p->la1 = p->la2;
            p->hasLa2 = false;
            // hasLa1 stays true
        } else {
            p->hasLa1 = false;
        }
    } else {
        p->cur = lexer_next(&p->lex);
    }
}

// One and two tokens of lookahead beyond p->cur, filled lazily. Needed
// because a couple of keywords are genuinely ambiguous with only one token
// of lookahead -- most notably "target", which is both a reserved plain
// field (`target = "native-x86_64";`, the build architecture) *and* a
// nested block keyword (`target "coralc" { ... }`, one of several build
// outputs). The two forms only diverge at the token right after the
// keyword: '=' means a plain field, anything else means a block.
static TokenKind peek1_kind(Parser* p) {
    if (!p->hasLa1) { p->la1 = lexer_next(&p->lex); p->hasLa1 = true; }
    return p->la1.kind;
}
static TokenKind peek2_kind(Parser* p) {
    peek1_kind(p);
    if (!p->hasLa2) { p->la2 = lexer_next(&p->lex); p->hasLa2 = true; }
    return p->la2.kind;
}

static void error_at(Parser* p, const char* msg) {
    if (p->hadError) return; // keep the first error
    p->hadError = true;
    p->errLine = p->cur.line;
    p->errCol = p->cur.col;
    long n = (long)strlen(msg);
    if (n > 500) n = 500;
    memcpy(p->errMsg, msg, (unsigned long)n);
    p->errMsg[n] = 0;
}

static bool check(Parser* p, TokenKind k) {
    return p->cur.kind == k;
}

static bool checkIdent(Parser* p, const char* text) {
    return p->cur.kind == TK_IDENT && str_eq_cstr(p->cur.text, text);
}

static Token expect(Parser* p, TokenKind k, const char* what) {
    Token t = p->cur;
    if (p->cur.kind != k) {
        error_at(p, what);
        return t;
    }
    advance(p);
    return t;
}

static Node* new_node(Parser* p, NodeKind kind) {
    Node* n = (Node*)arena_alloc(p->arena, (long)sizeof(Node), (long)alignof(Node));
    n->kind = kind;
    n->hasLabel = false;
    n->hasExtends = false;
    n->hasPayload = false;
    n->label.ptr = 0; n->label.len = 0;
    n->extendsTarget.ptr = 0; n->extendsTarget.len = 0;
    n->payload.ptr = 0; n->payload.len = 0;
    da_init(&n->fields);
    da_init(&n->children);
    return n;
}

static Value make_value_string(Str s) {
    Value v; v.kind = VK_STRING; v.str = s; v.num = 0; v.boolean = false; v.list = 0;
    return v;
}
static Value make_value_number(long long n) {
    Value v; v.kind = VK_NUMBER; v.str.ptr = 0; v.str.len = 0; v.num = n; v.boolean = false; v.list = 0;
    return v;
}
static Value make_value_bool(bool b) {
    Value v; v.kind = VK_BOOL; v.str.ptr = 0; v.str.len = 0; v.num = 0; v.boolean = b; v.list = 0;
    return v;
}

// ─────────────────────────────── value / list ─────────────────────────────
// value = STRING | NUMBER | BOOL | list ;
// list  = "[" [ value { "," value } [ "," ] ] "]" ;

static Value parse_value(Parser* p);

static Value parse_list(Parser* p) {
    Value v;
    v.kind = VK_LIST;
    v.str.ptr = 0; v.str.len = 0; v.num = 0; v.boolean = false;
    v.list = (ValueList*)arena_alloc(p->arena, (long)sizeof(ValueList), (long)alignof(ValueList));
    da_init(&v.list->items);

    expect(p, TK_LBRACKET, "expected '[' to start a list");
    if (!check(p, TK_RBRACKET)) {
        for (;;) {
            Value item = parse_value(p);
            if (p->hadError) break;
            da_push(p->arena, &v.list->items, item);
            if (check(p, TK_COMMA)) {
                advance(p);
                if (check(p, TK_RBRACKET)) break; // trailing comma allowed
                continue;
            }
            break;
        }
    }
    expect(p, TK_RBRACKET, "expected ']' to close a list");
    return v;
}

static Value parse_value(Parser* p) {
    if (check(p, TK_STRING)) { Value v = make_value_string(p->cur.text); advance(p); return v; }
    if (check(p, TK_NUMBER)) { Value v = make_value_number(p->cur.numValue); advance(p); return v; }
    if (check(p, TK_BOOL))   { Value v = make_value_bool(p->cur.boolValue); advance(p); return v; }
    if (check(p, TK_LBRACKET)) { return parse_list(p); }
    error_at(p, "expected a value (string, number, true/false, or a list)");
    return make_value_string(str_make(0, 0));
}

// ─────────────────────── forward declarations ─────────────────────────────

static void parse_body(Parser* p, Node* owner);
static Node* parse_override(Parser* p);
static Node* parse_env(Parser* p);
static Node* parse_target(Parser* p);
static Node* parse_link(Parser* p);
static Node* parse_artifact(Parser* p);
static Node* parse_features(Parser* p);
static Node* parse_log(Parser* p);
static Node* parse_metrics(Parser* p);

// ────────────────────────────── nested blocks ──────────────────────────────
// The leading keyword identifier ("override", "env", "target", ...) has
// already been consumed by the caller (parse_body) by the time each of
// these functions runs.

// env_block = "env" "=" "{" { env_pair } "}" ";"
// env_pair  = IDENT "=" STRING ";"
static Node* parse_env(Parser* p) {
    Node* n = new_node(p, NK_ENV);
    expect(p, TK_EQUALS, "expected '=' after 'env'");
    expect(p, TK_LBRACE, "expected '{' to start env block");
    while (!check(p, TK_RBRACE) && !check(p, TK_EOF) && !p->hadError) {
        Token nameTok = expect(p, TK_IDENT, "expected identifier as env key");
        expect(p, TK_EQUALS, "expected '=' after env key");
        Token valTok = expect(p, TK_STRING, "expected string value in env block");
        expect(p, TK_SEMI, "expected ';' after env value");
        Field f; f.name = nameTok.text; f.value = make_value_string(valTok.text);
        da_push(p->arena, &n->fields, f);
    }
    expect(p, TK_RBRACE, "expected '}' to close env block");
    expect(p, TK_SEMI, "expected ';' after env block");
    return n;
}

// link_block = "link" [ STRING ] "{" { link_field } "}" ;
static Node* parse_link(Parser* p) {
    Node* n = new_node(p, NK_LINK);
    if (check(p, TK_STRING)) { n->label = p->cur.text; n->hasLabel = true; advance(p); }
    expect(p, TK_LBRACE, "expected '{' after 'link'");
    parse_body(p, n);
    expect(p, TK_RBRACE, "expected '}' to close link block");
    return n;
}

// artifact_block = "artifact" [ STRING ] "{" { artifact_field } "}" ;
static Node* parse_artifact(Parser* p) {
    Node* n = new_node(p, NK_ARTIFACT);
    if (check(p, TK_STRING)) { n->label = p->cur.text; n->hasLabel = true; advance(p); }
    expect(p, TK_LBRACE, "expected '{' after 'artifact'");
    parse_body(p, n);
    expect(p, TK_RBRACE, "expected '}' to close artifact block");
    return n;
}

// features_block = "features" "{" { feature_decl } "}" ;
// feature_decl   = IDENT "=" list ";"   -- fits the generic field loop.
static Node* parse_features(Parser* p) {
    Node* n = new_node(p, NK_FEATURES);
    expect(p, TK_LBRACE, "expected '{' after 'features'");
    parse_body(p, n);
    expect(p, TK_RBRACE, "expected '}' to close features block");
    return n;
}

// log_block = "log" "{" { log_field } "}" ;
static Node* parse_log(Parser* p) {
    Node* n = new_node(p, NK_LOG);
    expect(p, TK_LBRACE, "expected '{' after 'log'");
    parse_body(p, n);
    expect(p, TK_RBRACE, "expected '}' to close log block");
    return n;
}

// metrics_block = "metrics" "{" { metrics_field } "}" ;
static Node* parse_metrics(Parser* p) {
    Node* n = new_node(p, NK_METRICS);
    expect(p, TK_LBRACE, "expected '{' after 'metrics'");
    parse_body(p, n);
    expect(p, TK_RBRACE, "expected '}' to close metrics block");
    return n;
}

// target_block = "target" STRING "{" { target_field } "}" ;
static Node* parse_target(Parser* p) {
    Node* n = new_node(p, NK_TARGET);
    Token lbl = expect(p, TK_STRING, "expected string label after 'target'");
    n->label = lbl.text; n->hasLabel = true;
    expect(p, TK_LBRACE, "expected '{' after target label");
    parse_body(p, n);
    expect(p, TK_RBRACE, "expected '}' to close target block");
    return n;
}

// override_block = "override" STRING "{" { override_field } "}" ;
static Node* parse_override(Parser* p) {
    Node* n = new_node(p, NK_OVERRIDE);
    Token lbl = expect(p, TK_STRING, "expected string label after 'override'");
    n->label = lbl.text; n->hasLabel = true;
    expect(p, TK_LBRACE, "expected '{' after override label");
    parse_body(p, n);
    expect(p, TK_RBRACE, "expected '}' to close override block");
    return n;
}

// Shared body loop used by every brace-delimited block: build_field,
// workspace_field, profile_field, task_field, test_field, bench_field,
// hook_field, phase_field, target_field, link_field, artifact_field,
// override_field, log_field, metrics_field, lint_field, format_field,
// lsp_field, ci_field, remote_field, feature_decl, dep_field all reduce to
// either a nested block (override/env/target/link/artifact/features/log/
// metrics) or a plain "IDENT = value ;" field.
//
// Note: this is intentionally more permissive than the exact per-block
// grammar (e.g. it would accept a stray `env = {...};` inside a `bench`
// block, which the strict grammar disallows). The spec's own design notes
// say structural validity beyond this is the builder's job, not the
// parser's (e.g. "The grammar allows [phase's `on`/`run`] to be omitted,
// but semantically they're required. The builder enforces this; the
// parser doesn't.") -- this parser follows that philosophy uniformly.
// True for keywords that introduce a nested block *unless* they're
// immediately followed by '=', in which case they're just an ordinary
// "name = value ;" field (this is how "target" is reused as both the
// reserved `target = "native-x86_64";` field and the `target "corald" {..}`
// block keyword).
static bool is_block_keyword_here(Parser* p, const char* text) {
    if (!checkIdent(p, text)) return false;
    return peek1_kind(p) != TK_EQUALS;
}

static void parse_body(Parser* p, Node* owner) {
    while (!check(p, TK_RBRACE) && !check(p, TK_EOF) && !p->hadError) {
        // "env" is doubly ambiguous: `env = { ... };` is the nested block,
        // but nothing stops a plain field literally named env, so we also
        // have to check that '{' follows the '='.
        if (checkIdent(p, "env") && peek1_kind(p) == TK_EQUALS && peek2_kind(p) == TK_LBRACE) {
            advance(p); Node* c = parse_env(p); da_push(p->arena, &owner->children, c); continue;
        }
        if (is_block_keyword_here(p, "override")) { advance(p); Node* c = parse_override(p); da_push(p->arena, &owner->children, c); continue; }
        if (is_block_keyword_here(p, "target"))   { advance(p); Node* c = parse_target(p);   da_push(p->arena, &owner->children, c); continue; }
        if (is_block_keyword_here(p, "link"))     { advance(p); Node* c = parse_link(p);     da_push(p->arena, &owner->children, c); continue; }
        if (is_block_keyword_here(p, "artifact")) { advance(p); Node* c = parse_artifact(p); da_push(p->arena, &owner->children, c); continue; }
        if (is_block_keyword_here(p, "features")) { advance(p); Node* c = parse_features(p); da_push(p->arena, &owner->children, c); continue; }
        if (is_block_keyword_here(p, "log"))      { advance(p); Node* c = parse_log(p);      da_push(p->arena, &owner->children, c); continue; }
        if (is_block_keyword_here(p, "metrics"))  { advance(p); Node* c = parse_metrics(p);  da_push(p->arena, &owner->children, c); continue; }

        if (!check(p, TK_IDENT)) { error_at(p, "expected a field name or nested block"); break; }
        Token nameTok = p->cur;
        advance(p);
        expect(p, TK_EQUALS, "expected '=' after field name");
        Value v = parse_value(p);
        expect(p, TK_SEMI, "expected ';' after field value");
        Field f; f.name = nameTok.text; f.value = v;
        da_push(p->arena, &owner->fields, f);
    }
}

// ───────────────────────────── top-level decls ─────────────────────────────

static Node* parse_labeled_block(Parser* p, NodeKind kind, bool allowExtends) {
    Node* n = new_node(p, kind);
    Token lbl = expect(p, TK_STRING, "expected a string label");
    n->label = lbl.text; n->hasLabel = true;
    if (allowExtends && checkIdent(p, "extends")) {
        advance(p);
        Token ext = expect(p, TK_STRING, "expected a string after 'extends'");
        n->extendsTarget = ext.text; n->hasExtends = true;
    }
    expect(p, TK_LBRACE, "expected '{'");
    parse_body(p, n);
    expect(p, TK_RBRACE, "expected '}'");
    return n;
}

static Node* parse_unlabeled_block(Parser* p, NodeKind kind) {
    Node* n = new_node(p, kind);
    expect(p, TK_LBRACE, "expected '{'");
    parse_body(p, n);
    expect(p, TK_RBRACE, "expected '}'");
    return n;
}

// alias_decl = "alias" IDENT "=" STRING ";"
static Node* parse_alias(Parser* p) {
    Node* n = new_node(p, NK_ALIAS);
    Token nameTok = expect(p, TK_IDENT, "expected an identifier after 'alias'");
    n->label = nameTok.text; n->hasLabel = true;
    expect(p, TK_EQUALS, "expected '=' after alias name");
    Token target = expect(p, TK_STRING, "expected a string after '=' in alias");
    n->payload = target.text; n->hasPayload = true;
    expect(p, TK_SEMI, "expected ';' after alias declaration");
    return n;
}

// include_decl = "include" STRING ";"
static Node* parse_include(Parser* p) {
    Node* n = new_node(p, NK_INCLUDE);
    Token path = expect(p, TK_STRING, "expected a string after 'include'");
    n->payload = path.text; n->hasPayload = true;
    expect(p, TK_SEMI, "expected ';' after include declaration");
    return n;
}

// schema_decl = "schema" "=" NUMBER ";"
static Node* parse_schema(Parser* p) {
    Node* n = new_node(p, NK_SCHEMA);
    expect(p, TK_EQUALS, "expected '=' after 'schema'");
    Token num = expect(p, TK_NUMBER, "expected a number after 'schema ='");
    expect(p, TK_SEMI, "expected ';' after schema declaration");
    Field f; f.name = str_from_cstr("value"); f.value = make_value_number(num.numValue);
    da_push(p->arena, &n->fields, f);
    return n;
}

// strict_decl = "strict" "=" BOOL ";"
static Node* parse_strict(Parser* p) {
    Node* n = new_node(p, NK_STRICT);
    expect(p, TK_EQUALS, "expected '=' after 'strict'");
    Token b = expect(p, TK_BOOL, "expected true/false after 'strict ='");
    expect(p, TK_SEMI, "expected ';' after strict declaration");
    Field f; f.name = str_from_cstr("value"); f.value = make_value_bool(b.boolValue);
    da_push(p->arena, &n->fields, f);
    return n;
}

// deps_decl = "deps" "{" { dep_entry } "}" ;
// dep_entry = STRING "=" "{" { dep_field } "}" ";"
static Node* parse_deps(Parser* p) {
    Node* n = new_node(p, NK_DEPS);
    expect(p, TK_LBRACE, "expected '{' after 'deps'");
    while (check(p, TK_STRING) && !p->hadError) {
        Token key = p->cur; advance(p);
        Node* entry = new_node(p, NK_DEP_ENTRY);
        entry->label = key.text; entry->hasLabel = true;
        expect(p, TK_EQUALS, "expected '=' after dependency key");
        expect(p, TK_LBRACE, "expected '{' after dependency key '='");
        parse_body(p, entry); // dep_field entries are plain fields
        expect(p, TK_RBRACE, "expected '}' to close dependency entry");
        expect(p, TK_SEMI, "expected ';' after dependency entry");
        da_push(p->arena, &n->children, entry);
    }
    expect(p, TK_RBRACE, "expected '}' to close deps block");
    return n;
}

// top_decl per the v2 grammar text: build | workspace | alias | task | test
// | bench | hook | profile | include | lsp | format | ci | remote | deps.
//
// Two things worth flagging about the spec as given: `phase_decl` and
// `lint_decl` are defined as productions and used at the top level in the
// canonical v2 example, but are missing from the `top_decl` alternation
// itself. That looks like an oversight in the grammar text rather than an
// intent to forbid them -- this parser follows the canonical example and
// accepts both at the top level.
static Node* parse_top_decl(Parser* p) {
    if (checkIdent(p, "schema"))    { advance(p); return parse_schema(p); }
    if (checkIdent(p, "strict"))    { advance(p); return parse_strict(p); }
    if (checkIdent(p, "build"))     { advance(p); return parse_labeled_block(p, NK_BUILD, true); }
    if (checkIdent(p, "workspace")) { advance(p); return parse_labeled_block(p, NK_WORKSPACE, false); }
    if (checkIdent(p, "profile"))   { advance(p); return parse_labeled_block(p, NK_PROFILE, true); }
    if (checkIdent(p, "alias"))     { advance(p); return parse_alias(p); }
    if (checkIdent(p, "task"))      { advance(p); return parse_labeled_block(p, NK_TASK, false); }
    if (checkIdent(p, "test"))      { advance(p); return parse_labeled_block(p, NK_TEST, false); }
    if (checkIdent(p, "bench"))     { advance(p); return parse_labeled_block(p, NK_BENCH, false); }
    if (checkIdent(p, "hook"))      { advance(p); return parse_labeled_block(p, NK_HOOK, false); }
    if (checkIdent(p, "phase"))     { advance(p); return parse_labeled_block(p, NK_PHASE, false); }
    if (checkIdent(p, "override"))  { advance(p); return parse_override(p); }
    if (checkIdent(p, "include"))   { advance(p); return parse_include(p); }
    if (checkIdent(p, "lsp"))       { advance(p); return parse_unlabeled_block(p, NK_LSP); }
    if (checkIdent(p, "format"))    { advance(p); return parse_unlabeled_block(p, NK_FORMAT); }
    if (checkIdent(p, "ci"))        { advance(p); return parse_unlabeled_block(p, NK_CI); }
    if (checkIdent(p, "remote"))    { advance(p); return parse_unlabeled_block(p, NK_REMOTE); }
    if (checkIdent(p, "lint"))      { advance(p); return parse_unlabeled_block(p, NK_LINT); }
    if (checkIdent(p, "deps"))      { advance(p); return parse_deps(p); }
    error_at(p, "unrecognized top-level declaration");
    return 0;
}

// ────────────────────────────────── driver ─────────────────────────────────

void parser_init(Parser* p, const char* src, long len, Arena* arena) {
    lexer_init(&p->lex, src, len, arena);
    p->arena = arena;
    p->hasLa1 = false;
    p->hasLa2 = false;
    p->hadError = false;
    p->errMsg[0] = 0;
    p->errLine = 0;
    p->errCol = 0;
    advance(p); // prime the one-token lookahead
}

Node* parse_file(Parser* p) {
    Node* root = new_node(p, NK_ROOT);
    while (!check(p, TK_EOF) && !p->hadError) {
        Node* d = parse_top_decl(p);
        if (d == 0 || p->hadError) break;
        da_push(p->arena, &root->children, d);
    }
    return root;
}

const char* node_kind_name(NodeKind k) {
    switch (k) {
        case NK_ROOT:      return "root";
        case NK_SCHEMA:    return "schema";
        case NK_STRICT:    return "strict";
        case NK_BUILD:     return "build";
        case NK_WORKSPACE: return "workspace";
        case NK_PROFILE:   return "profile";
        case NK_ALIAS:     return "alias";
        case NK_TASK:      return "task";
        case NK_TEST:      return "test";
        case NK_BENCH:     return "bench";
        case NK_HOOK:      return "hook";
        case NK_PHASE:     return "phase";
        case NK_TARGET:    return "target";
        case NK_LINK:      return "link";
        case NK_ARTIFACT:  return "artifact";
        case NK_FEATURES:  return "features";
        case NK_ENV:       return "env";
        case NK_LOG:       return "log";
        case NK_METRICS:   return "metrics";
        case NK_LINT:      return "lint";
        case NK_FORMAT:    return "format";
        case NK_LSP:       return "lsp";
        case NK_CI:        return "ci";
        case NK_REMOTE:    return "remote";
        case NK_DEPS:      return "deps";
        case NK_DEP_ENTRY: return "dep_entry";
        case NK_OVERRIDE:  return "override";
        case NK_INCLUDE:   return "include";
    }
    return "?";
}
