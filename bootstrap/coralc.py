import sys
import os
import json

def resolve_import_path(source_file, import_path):
    source_dir = os.path.dirname(os.path.abspath(source_file))
    compiler_dir = os.path.normpath(os.path.join(source_dir, ".."))

    candidate = os.path.join(source_dir, import_path + ".crl")
    if os.path.exists(candidate):
        return candidate
    candidate2 = os.path.join(source_dir, import_path)
    if os.path.exists(candidate2):
        return candidate2

    for sub in os.listdir(compiler_dir):
        sub_dir = os.path.join(compiler_dir, sub)
        if not os.path.isdir(sub_dir):
            continue
        sub_path = os.path.join(sub_dir, import_path + ".crl")
        if os.path.exists(sub_path):
            return sub_path
        sub_path2 = os.path.join(sub_dir, import_path)
        if os.path.exists(sub_path2):
            return sub_path2

    candidate3 = os.path.join(compiler_dir, import_path + ".crl")
    if os.path.exists(candidate3):
        return candidate3
    lib_dir = os.path.join(source_dir, "..", "..", "lib")
    candidate5 = os.path.join(lib_dir, import_path + ".crl")
    if os.path.exists(candidate5):
        return candidate5
    return None

def parse_file(path, parsed, all_asts, dep_graph):
    abspath = os.path.abspath(path)
    if abspath in parsed:
        return
    parsed[abspath] = True
    with open(path, "r") as f:
        source = f.read()

    from lexer import Lexer
    from parser import Parser

    lexer = Lexer(source, path)
    tokens = lexer.lex()
    parser = Parser(tokens, path)
    ast = parser.parse()
    all_asts[abspath] = ast

    deps = []
    for decl in ast.decls:
        if hasattr(decl, 'is_lib') and decl.is_lib:
            continue
        if hasattr(decl, 'path'):
            imp_path = decl.path
            resolved = resolve_import_path(path, imp_path)
            if resolved:
                deps.append(os.path.abspath(resolved))
                parse_file(resolved, parsed, all_asts, dep_graph)
    dep_graph[abspath] = deps

def topological_sort(graph):
    visited = set()
    order = []

    def visit(node):
        if node in visited:
            return
        visited.add(node)
        for dep in graph.get(node, []):
            visit(dep)
        order.append(node)

    for node in graph:
        visit(node)
    return order

def main():
    if len(sys.argv) < 2:
        print("usage: coralc <file.crl> [-o output] [--no-compile]")
        sys.exit(1)

    input_path = sys.argv[1]
    output_path = "a.out"
    no_compile = "--no-compile" in sys.argv
    if "-o" in sys.argv:
        idx = sys.argv.index("-o")
        output_path = sys.argv[idx + 1]

    from parser import StructDecl, EnumDecl, ExtendBlock
    from codegen import CodeGen

    parsed = {}
    all_asts = {}
    dep_graph = {}
    parse_file(input_path, parsed, all_asts, dep_graph)

    ordered = topological_sort(dep_graph)

    gen = CodeGen()
    for path in ordered:
        ast = all_asts[path]
        for d in ast.decls:
            if isinstance(d, StructDecl):
                gen.struct_names.add(d.name)
            elif isinstance(d, EnumDecl):
                gen.enum_names.add(d.name)
            elif isinstance(d, ExtendBlock):
                tn = gen.gen_type(d.type_node)
                gen.struct_names.add(tn)

    all_c = []
    first = True
    for path in ordered:
        ast = all_asts[path]
        gen.set_current_file(path)
        gen.suppress_main = not first
        c_code = gen.generate(ast)
        if first:
            all_c.append(c_code)
            first = False
        else:
            for line in c_code.split("\n"):
                if line.startswith("#include"):
                    continue
                if line.startswith("typedef struct _coral_str"):
                    continue
                all_c.append(line)

    c_path = output_path + ".c"
    with open(c_path, "w") as f:
        f.write("\n".join(all_c))
    print(f"wrote {c_path}")

    if not no_compile:
        cc = os.environ.get("CC", "gcc")
        cmd = f'{cc} -o {output_path} {c_path} -lgcc'
        print(f"{cmd}")
        ret = os.system(cmd)
        if ret != 0:
            print("compilation failed")
            sys.exit(1)
        os.remove(c_path)
        print(f"wrote {output_path}")

if __name__ == "__main__":
    main()
