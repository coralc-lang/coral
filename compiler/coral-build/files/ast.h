#pragma once
#include "types.h"
#include "str.h"
#include "dynarray.h"

enum ValueKind { VK_STRING, VK_NUMBER, VK_BOOL, VK_LIST };

struct ValueArray; // defined below, after Value -- forward-declared here so
                    // Value's union can hold a pointer to one.

// value = STRING | NUMBER | BOOL | list ;
// A real union this time: Str, i64 and bool are all trivial, and
// ValueArray* is just a pointer, so the union is itself trivially
// copyable -- no special-member-function gymnastics needed.
struct Value {
    ValueKind kind;
    union {
        Str str;
        i64 num;
        bool boolean;
        ValueArray* list;
    };

    static Value ofString(Str s);
    static Value ofNumber(i64 n);
    static Value ofBool(bool b);
    static Value ofList(ValueArray* l);
};

DEFINE_ARRAY(ValueArray, Value);

// field = IDENT "=" value ";"
// Every "IDENT = value ;" shape in the grammar (plain fields, modules/skip
// lists, provides/requires/exclude/include/features lists, feature_decl
// entries, env pairs, doc fields, dep_field entries, ...) is represented
// uniformly as a Field -- they're all structurally identical, and the
// spec's own notes say the parser is meant to accept more than is
// semantically valid and leave validation to "the builder".
struct Field {
    Str name;
    Value value;
};

DEFINE_ARRAY(FieldArray, Field);

enum NodeKind {
    NK_ROOT,
    NK_SCHEMA,
    NK_STRICT,
    NK_BUILD,
    NK_WORKSPACE,
    NK_PROFILE,
    NK_ALIAS,
    NK_TASK,
    NK_TEST,
    NK_BENCH,
    NK_HOOK,
    NK_PHASE,
    NK_TARGET,
    NK_LINK,
    NK_ARTIFACT,
    NK_FEATURES,
    NK_ENV,
    NK_LOG,
    NK_METRICS,
    NK_LINT,
    NK_FORMAT,
    NK_LSP,
    NK_CI,
    NK_REMOTE,
    NK_DEPS,
    NK_DEP_ENTRY,
    NK_OVERRIDE,
    NK_INCLUDE
};

const char* nodeKindName(NodeKind k);

struct Node; // forward-declared so ChildArray can hold Node*
DEFINE_ARRAY(ChildArray, Node*);

struct Node {
    NodeKind kind;

    Str label;          // build/override/task/target/... label, or
                        // alias's IDENT name
    bool hasLabel;

    Str extendsTarget;   // build/profile "extends" target
    bool hasExtends;

    Str payload;         // alias's STRING target, or include's path
    bool hasPayload;

    FieldArray fields;    // plain "name = value ;" entries
    ChildArray children;  // nested blocks (override, env, target, link,
                          // artifact, features, log, metrics, dep_entry)

    void init(NodeKind kind, Arena* arena);
    void addField(Str name, Value v);
    void addChild(Node* child);
};
