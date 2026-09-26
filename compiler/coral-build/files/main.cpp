#include "parser.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>

static void print_indent(int n) {
    for (int i = 0; i < n; i = i + 1) fputs("  ", stdout);
}

static void print_value(Value v) {
    switch (v.kind) {
        case VK_STRING:
            putchar('"'); str_print(v.str); putchar('"');
            break;
        case VK_NUMBER:
            printf("%lld", v.num);
            break;
        case VK_BOOL:
            fputs(v.boolean ? "true" : "false", stdout);
            break;
        case VK_LIST:
            putchar('[');
            for (long i = 0; i < v.list->items.count; i = i + 1) {
                if (i != 0) fputs(", ", stdout);
                print_value(v.list->items.data[i]);
            }
            putchar(']');
            break;
    }
}

static void dump_node(Node* n, int depth) {
    print_indent(depth);
    fputs(node_kind_name(n->kind), stdout);
    if (n->hasLabel) {
        // alias's label is an IDENT (e.g. `alias lexer = ...`), everything
        // else that has a label (build, override, task, target, ...) got
        // it from a quoted STRING -- print each the way it was written.
        if (n->kind == NK_ALIAS) { putchar(' '); str_print(n->label); }
        else { fputs(" \"", stdout); str_print(n->label); fputs("\"", stdout); }
    }
    if (n->hasExtends) { fputs(" extends \"", stdout); str_print(n->extendsTarget); fputs("\"", stdout); }
    if (n->hasPayload) { fputs(" = \"", stdout); str_print(n->payload); fputs("\"", stdout); }
    putchar('\n');

    for (long i = 0; i < n->fields.count; i = i + 1) {
        print_indent(depth + 1);
        str_print(n->fields.data[i].name);
        fputs(" = ", stdout);
        print_value(n->fields.data[i].value);
        putchar('\n');
    }
    for (long i = 0; i < n->children.count; i = i + 1) {
        dump_node(n->children.data[i], depth + 1);
    }
}

int main(int argc, char** argv) {
    const char* buf;
    long len;
    char* fileBuf = 0;

    if (argc > 1) {
        FILE* f = fopen(argv[1], "rb");
        if (!f) { fprintf(stderr, "cannot open %s\n", argv[1]); return 1; }
        fseek(f, 0, SEEK_END);
        long sz = ftell(f);
        fseek(f, 0, SEEK_SET);
        fileBuf = (char*)malloc((unsigned long)sz + 1);
        long rd = (long)fread(fileBuf, 1, (unsigned long)sz, f);
        fileBuf[rd] = 0;
        fclose(f);
        buf = fileBuf;
        len = rd;
    } else {
        static const char* embedded =
            "schema = 1;\n"
            "build \"demo\" {\n"
            "    root = \"src/\";\n"
            "    modules = [\"a\", \"b\"];\n"
            "}\n";
        buf = embedded;
        len = (long)strlen(embedded);
    }

    Arena arena;
    arena_init(&arena, 1 << 16);

    Parser p;
    parser_init(&p, buf, len, &arena);
    Node* root = parse_file(&p);

    int rc = 0;
    if (p.hadError) {
        fprintf(stderr, "parse error at line %ld, col %ld: %s\n", p.errLine, p.errCol, p.errMsg);
        rc = 1;
    } else {
        printf("parsed ok: %ld top-level declaration(s)\n\n", root->children.count);
        dump_node(root, 0);
    }

    if (fileBuf) free(fileBuf);
    arena_free_all(&arena);
    return rc;
}
