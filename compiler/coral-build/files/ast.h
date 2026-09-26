#pragma once
#include "str.h"
#include "dynarray.h"

// value = STRING | NUMBER | BOOL | list ;  list = "[" [value {"," value} [","]] "]" ;
enum ValueKind { VK_STRING, VK_NUMBER, VK_BOOL, VK_LIST };

struct Value;

struct ValueList {
    DynArray<Value> items;
};

// A tagged union of the four value shapes the grammar allows. We keep this
// as plain fields (a "poor man's union") rather than a real C++ union
// because Value contains a DynArray<Value>* which is fine in a union too,
// but keeping everything as plain fields makes the AST dump code simpler
// and costs only a few bytes.
struct Value {
    ValueKind kind;
    Str str;          // VK_STRING
    long long num;     // VK_NUMBER
    bool boolean;      // VK_BOOL
    ValueList* list;   // VK_LIST
};

// field = IDENT "=" value ";"
// Every "IDENT = value ;" construct in the grammar (plain fields, modules/
// skip lists, provides/requires/exclude/include/features lists, feature_decl
// entries, env pairs, doc fields, dep_field entries, ...) is represented
// uniformly as a Field. This is deliberate: the spec itself says the parser
// accepts more than is semantically valid and leaves validation to "the
// builder" (see e.g. the notes on `phase` requiring `on`/`run`, and on
// `deps`/`remote` being "parsed but not evaluated"). A generic Field covers
// all of these without needing ~60 distinct struct types.
struct Field {
    Str name;
    Value value;
};

// One kind per distinct decl/block shape in the v2 grammar.
enum NodeKind {
    NK_ROOT,       // the whole file
    NK_SCHEMA,     // schema = NUMBER ;
    NK_STRICT,     // strict = BOOL ;
    NK_BUILD,      // build STRING [extends STRING] { ... }
    NK_WORKSPACE,  // workspace STRING { ... }
    NK_PROFILE,    // profile STRING [extends STRING] { ... }
    NK_ALIAS,      // alias IDENT = STRING ;
    NK_TASK,       // task STRING { ... }
    NK_TEST,       // test STRING { ... }
    NK_BENCH,      // bench STRING { ... }
    NK_HOOK,       // hook STRING { ... }
    NK_PHASE,      // phase STRING { ... }
    NK_TARGET,     // target STRING { ... }           (nested in build)
    NK_LINK,       // link [STRING] { ... }            (nested)
    NK_ARTIFACT,   // artifact [STRING] { ... }        (nested)
    NK_FEATURES,   // features { IDENT = list ; ... }  (nested)
    NK_ENV,        // env = { IDENT = STRING ; ... } ; (nested)
    NK_LOG,        // log { ... }                      (nested)
    NK_METRICS,    // metrics { ... }                  (nested)
    NK_LINT,       // lint { ... }
    NK_FORMAT,     // format { ... }
    NK_LSP,        // lsp { ... }
    NK_CI,         // ci { ... }
    NK_REMOTE,     // remote { ... }
    NK_DEPS,       // deps { dep_entry* }
    NK_DEP_ENTRY,  // STRING = { dep_field* } ;        (child of deps)
    NK_OVERRIDE,   // override STRING { ... }          (nested in build)
    NK_INCLUDE     // include STRING ;
};

struct Node {
    NodeKind kind;

    Str label;          // build/override/task/target/... string label, or
                         // alias's IDENT name
    bool hasLabel;

    Str extendsTarget;   // build/profile "extends" target
    bool hasExtends;

    Str payload;         // alias's STRING target, include's path
    bool hasPayload;

    DynArray<Field> fields;    // plain "name = value ;" entries
    DynArray<Node*> children;  // nested blocks (override, env, target,
                               // link, artifact, features, log, metrics,
                               // dep_entry)
};

const char* node_kind_name(NodeKind k);
