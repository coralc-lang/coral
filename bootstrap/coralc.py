import os
import shlex
import subprocess
import sys


class UnresolvedImportError(FileNotFoundError):
    def __init__(self, source_file, import_path, candidates):
        self.source_file = source_file
        self.import_path = import_path
        self.candidates = tuple(candidates)
        tried = ", ".join(self.candidates) if self.candidates else "no candidate paths"
        super().__init__(
            f'unresolved import "{import_path}" in {source_file}; tried: {tried}'
        )


class ImportCycleError(ValueError):
    pass


def _canonical_path(path):
    return os.path.normcase(os.path.realpath(os.path.abspath(path)))


def _import_name(import_path):
    if not isinstance(import_path, str) or not import_path or "\0" in import_path:
        return None
    if "::" not in import_path:
        return import_path
    parts = import_path.split("::")
    if any(not part for part in parts):
        return None
    if parts[0] == "file":
        parts = parts[1:]
    if not parts:
        return None
    return os.path.join(*parts)


def _search_roots(source_dir):
    compiler_dir = os.path.normpath(os.path.join(source_dir, os.pardir))
    roots = [source_dir]
    try:
        with os.scandir(compiler_dir) as entries:
            module_dirs = sorted(
                (entry.path for entry in entries if entry.is_dir()),
                key=os.path.basename,
            )
    except OSError:
        module_dirs = []
    roots.extend(module_dirs)
    roots.append(compiler_dir)
    roots.append(os.path.normpath(os.path.join(source_dir, os.pardir, os.pardir, "lib")))

    unique_roots = []
    seen = set()
    for root in roots:
        canonical = _canonical_path(root)
        if canonical not in seen:
            seen.add(canonical)
            unique_roots.append(canonical)
    return unique_roots


def _import_candidates(source_file, import_path):
    import_name = _import_name(import_path)
    if import_name is None:
        return []

    source_dir = os.path.dirname(_canonical_path(source_file))
    candidates = []
    seen = set()
    for root in _search_roots(source_dir):
        base = os.path.join(root, import_name)
        paths = []
        if not import_name.endswith(".crl"):
            paths.append(base + ".crl")
        paths.append(base)
        if os.path.isdir(base):
            paths.append(os.path.join(base, "lib.crl"))
        for path in paths:
            canonical = _canonical_path(path)
            if canonical not in seen:
                seen.add(canonical)
                candidates.append(canonical)
    return candidates


def resolve_import_path(source_file, import_path):
    for candidate in _import_candidates(source_file, import_path):
        try:
            if os.path.isfile(candidate):
                return candidate
        except OSError:
            continue
    return None


def _cycle_error(active, node):
    start = active.index(node)
    cycle = active[start:] + [node]
    return ImportCycleError("import cycle detected: " + " -> ".join(cycle))


def parse_file(path, parsed, all_asts, dep_graph, active=None):
    abspath = _canonical_path(path)
    if abspath in parsed:
        return
    if active is None:
        active = []
    if abspath in active:
        raise _cycle_error(active, abspath)

    with open(abspath, "r", encoding="utf-8") as f:
        source = f.read()

    from lexer import Lexer
    from parser import Parser

    lexer = Lexer(source, abspath)
    tokens = lexer.lex()
    parser = Parser(tokens, abspath)
    ast = parser.parse()
    all_asts[abspath] = ast

    deps = []
    active.append(abspath)
    try:
        for decl in ast.decls:
            if getattr(decl, "is_lib", False):
                continue
            if not hasattr(decl, "path"):
                continue
            imp_path = decl.path
            resolved = resolve_import_path(abspath, imp_path)
            if resolved is None:
                raise UnresolvedImportError(
                    abspath, imp_path, _import_candidates(abspath, imp_path)
                )
            if resolved not in deps:
                deps.append(resolved)
            parse_file(resolved, parsed, all_asts, dep_graph, active)
    finally:
        active.pop()

    dep_graph[abspath] = deps
    parsed[abspath] = True


def topological_sort(graph):
    visited = set()
    active = []
    order = []

    def visit(node):
        if node in visited:
            return
        if node in active:
            raise _cycle_error(active, node)
        active.append(node)
        for dep in graph.get(node, ()):
            visit(dep)
        active.pop()
        visited.add(node)
        order.append(node)

    for node in graph:
        visit(node)
    return order


_USAGE = "usage: coralc <file.crl> [-o output] [--no-compile] [--flag NAME=VALUE]"


def _abort(message, show_usage=False):
    print(f"coralc: error: {message}", file=sys.stderr)
    if show_usage:
        print(_USAGE, file=sys.stderr)
    raise SystemExit(1)


def _parse_args(argv):
    input_path = None
    output_path = "a.out"
    no_compile = False
    flags = {}
    output_seen = False
    options_done = False
    index = 0

    while index < len(argv):
        arg = argv[index]
        if not options_done and arg == "--":
            options_done = True
        elif not options_done and arg == "-o":
            if output_seen:
                raise ValueError("-o may only be specified once")
            if index + 1 >= len(argv) or argv[index + 1] in (
                "-o", "--no-compile", "--flag", "--"
            ):
                raise ValueError("-o requires an output path")
            output_path = argv[index + 1]
            if not output_path:
                raise ValueError("-o requires a non-empty output path")
            output_seen = True
            index += 1
        elif not options_done and arg == "--no-compile":
            no_compile = True
        elif not options_done and arg == "--flag":
            if index + 1 >= len(argv):
                raise ValueError("--flag requires NAME=VALUE")
            value = argv[index + 1]
            if "=" not in value:
                raise ValueError("--flag requires NAME=VALUE")
            name, flag_value = value.split("=", 1)
            if not name:
                raise ValueError("--flag name must not be empty")
            flags[name] = flag_value
            index += 1
        elif not options_done and arg.startswith("-") and arg != "-":
            raise ValueError(f"unknown option: {arg}")
        elif input_path is None:
            if not arg:
                raise ValueError("input path must not be empty")
            input_path = arg
        else:
            raise ValueError(f"unexpected positional argument: {arg}")
        index += 1

    if input_path is None:
        raise ValueError("missing input file")

    if not os.path.isfile(input_path):
        if os.path.exists(input_path):
            raise ValueError(f"input path is not a file: {input_path}")
        raise FileNotFoundError(f"input file does not exist: {input_path}")
    if os.path.isdir(output_path):
        raise ValueError(f"output path is a directory: {output_path}")

    c_path = output_path + ".c"
    if os.path.isdir(c_path):
        raise ValueError(f"generated C path is a directory: {c_path}")
    output_parent = os.path.dirname(os.path.abspath(output_path))
    if not os.path.isdir(output_parent):
        raise ValueError(f"output directory does not exist: {output_parent}")

    input_abs = _canonical_path(input_path)
    if _canonical_path(output_path) == input_abs or _canonical_path(c_path) == input_abs:
        raise ValueError("output path must not overwrite the input file")

    return input_path, output_path, no_compile, flags


def _compiler_command(output_path, c_path):
    try:
        compiler = shlex.split(os.environ.get("CC", "gcc"))
    except ValueError as exc:
        _abort(f"invalid CC: {exc}")
    if not compiler:
        _abort("CC must name a compiler")
    return compiler + ["-o", output_path, c_path, "-lgcc"]


def main(argv=None):
    if argv is None:
        argv = sys.argv[1:]
    try:
        input_path, output_path, no_compile, flags = _parse_args(argv)
    except (OSError, ValueError) as exc:
        _abort(str(exc), show_usage=True)

    from parser import StructDecl, EnumDecl, ExtendBlock, VariantDecl, UnionDecl
    from codegen import CodeGen

    parsed = {}
    all_asts = {}
    dep_graph = {}
    try:
        parse_file(input_path, parsed, all_asts, dep_graph)
        ordered = topological_sort(dep_graph)
    except UnresolvedImportError as exc:
        _abort(str(exc))
    except ImportCycleError as exc:
        _abort(str(exc))
    except OSError as exc:
        _abort(str(exc))

    gen = CodeGen()
    gen.flags = flags
    gen.collect_global_methods(all_asts.values())
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
            elif isinstance(d, VariantDecl):
                gen.struct_names.add(d.name)
            elif isinstance(d, UnionDecl):
                gen.struct_names.add(d.name)

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
    try:
        with open(c_path, "w", encoding="utf-8", newline="\n") as f:
            f.write("\n".join(all_c))
    except OSError as exc:
        _abort(str(exc))
    print(f"wrote {c_path}")

    if not no_compile:
        cmd = _compiler_command(output_path, c_path)
        print(shlex.join(cmd))
        try:
            result = subprocess.run(cmd, check=False, shell=False)
        except OSError as exc:
            _abort(f"failed to run C compiler: {exc}")
        if result.returncode != 0:
            _abort(f"C compiler exited with status {result.returncode}")
        try:
            os.remove(c_path)
        except OSError as exc:
            _abort(str(exc))
        print(f"wrote {output_path}")


if __name__ == "__main__":
    main()
