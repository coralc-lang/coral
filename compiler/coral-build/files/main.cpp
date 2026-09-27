#include "parser.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>

struct AstDumper {
    void indent(i32 depth);
    void dumpValue(Value v);
    void dumpNode(Node* n, i32 depth);
};

void AstDumper::indent(i32 depth) {
    for (i32 i = 0; i < depth; i = i + 1) fputs("  ", stdout);
}

void AstDumper::dumpValue(Value v) {
    switch (v.kind) {
        case VK_STRING:
            putchar('"'); v.str.print(); putchar('"');
            break;
        case VK_NUMBER:
            printf("%lld", (long long)v.num);
            break;
        case VK_BOOL:
            fputs(v.boolean ? "true" : "false", stdout);
            break;
        case VK_LIST:
            putchar('[');
            for (i64 i = 0; i < v.list->count; i = i + 1) {
                if (i != 0) fputs(", ", stdout);
                self->dumpValue(v.list->at(i));
            }
            putchar(']');
            break;
    }
}

void AstDumper::dumpNode(Node* n, i32 depth) {
    self->indent(depth);
    fputs(nodeKindName(n->kind), stdout);
    if (n->hasLabel) {
        // alias's label is an IDENT (e.g. `alias lexer = ...`); everything
        // else that has a label (build, override, task, target, ...) got
        // it from a quoted STRING. Print each the way it was written.
        if (n->kind == NK_ALIAS) { putchar(' '); n->label.print(); }
        else { fputs(" \"", stdout); n->label.print(); fputs("\"", stdout); }
    }
    if (n->hasExtends) { fputs(" extends \"", stdout); n->extendsTarget.print(); fputs("\"", stdout); }
    if (n->hasPayload)  { fputs(" = \"", stdout); n->payload.print(); fputs("\"", stdout); }
    putchar('\n');

    for (i64 i = 0; i < n->fields.count; i = i + 1) {
        self->indent(depth + 1);
        n->fields.at(i).name.print();
        fputs(" = ", stdout);
        self->dumpValue(n->fields.at(i).value);
        putchar('\n');
    }
    for (i64 i = 0; i < n->children.count; i = i + 1) {
        self->dumpNode(n->children.at(i), depth + 1);
    }
}

int main(int argc, char** argv) {
    char* fileBuf = 0;
    char* buf;
    i64 len;

    if (argc > 1) {
        FILE* f = fopen(argv[1], "rb");
        if (!f) { fprintf(stderr, "cannot open %s\n", argv[1]); return 1; }
        fseek(f, 0, SEEK_END);
        i64 sz = ftell(f);
        fseek(f, 0, SEEK_SET);
        fileBuf = (char*)malloc((u64)sz + 1);
        i64 rd = (i64)fread(fileBuf, 1, (u64)sz, f);
        fileBuf[rd] = 0;
        fclose(f);
        buf = fileBuf;
        len = rd;
    } else {
        static char embedded[] =
            "schema = 1;\n"
            "build \"demo\" {\n"
            "    root = \"src/\";\n"
            "    modules = [\"a\", \"b\"];\n"
            "}\n";
        buf = embedded;
        len = (i64)strlen(embedded);
    }

    Arena arena;
    arena.init(1 << 16);

    Parser p;
    p.init(buf, len, &arena);
    Node* root = p.parseFile();

    int rc = 0;
    if (p.hadError) {
        fprintf(stderr, "parse error at line %lld, col %lld: %s\n",
                (long long)p.errLine, (long long)p.errCol, p.errMsg);
        rc = 1;
    } else {
        printf("parsed ok: %lld top-level declaration(s)\n\n", (long long)root->children.count);
        AstDumper dumper;
        dumper.dumpNode(root, 0);
    }

    if (fileBuf) free(fileBuf);
    arena.freeAll();
    return rc;
}
