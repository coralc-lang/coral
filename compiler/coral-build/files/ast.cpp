#include "ast.h"

Value Value::ofString(Str s) { Value v; v.kind = VK_STRING; v.str = s; return v; }
Value Value::ofNumber(i64 n) { Value v; v.kind = VK_NUMBER; v.num = n; return v; }
Value Value::ofBool(bool b)  { Value v; v.kind = VK_BOOL;   v.boolean = b; return v; }
Value Value::ofList(ValueArray* l) { Value v; v.kind = VK_LIST; v.list = l; return v; }

void Node::init(NodeKind k, Arena* arena) {
    self->kind = k;
    self->hasLabel = false;
    self->hasExtends = false;
    self->hasPayload = false;
    self->label = Str::make(0, 0);
    self->extendsTarget = Str::make(0, 0);
    self->payload = Str::make(0, 0);
    self->fields.init(arena);
    self->children.init(arena);
}

void Node::addField(Str name, Value v) {
    Field f; f.name = name; f.value = v;
    self->fields.push(f);
}

void Node::addChild(Node* child) {
    self->children.push(child);
}

const char* nodeKindName(NodeKind k) {
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
