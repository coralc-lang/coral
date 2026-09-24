import os
import re
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


def _module_map_candidates(import_path, module_map):
    if not module_map or "::" not in import_path:
        return []
    try:
        with open(module_map, "r", encoding="utf-8") as f:
            lines = f.readlines()
    except OSError:
        return []
    keys = [import_path]
    if import_path.startswith("file::"):
        keys.append(import_path[6:])
    map_dir = os.path.dirname(_canonical_path(module_map))
    project_dir = os.path.dirname(map_dir)
    roots = [project_dir]
    cwd = _canonical_path(os.getcwd())
    if cwd not in roots:
        roots.append(cwd)
    candidates = []
    for line in lines:
        line = line.strip()
        if not line or line.startswith("#") or "->" not in line:
            continue
        key, value = (part.strip() for part in line.split("->", 1))
        if key.startswith("@"):
            key = key[1:]
        if key not in keys:
            continue
        for root in roots:
            base = value if os.path.isabs(value) else os.path.join(root, value)
            paths = [base]
            if not base.endswith(".crl"):
                paths.insert(0, base + ".crl")
            if base.endswith(".crl") and os.path.isfile(os.path.join(os.path.dirname(base), "lib.crl")):
                paths.insert(0, os.path.join(os.path.dirname(base), "lib.crl"))
            if os.path.isdir(base):
                paths.append(os.path.join(base, "lib.crl"))
            for path in paths:
                candidates.append(_canonical_path(path))
    return candidates


def _import_candidates(source_file, import_path, module_map=None):
    candidates = _module_map_candidates(import_path, module_map)
    if candidates:
        return candidates

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


def resolve_library_import(import_path, manifest, module_map=None):
    candidates = _module_map_candidates(import_path, module_map)
    if candidates:
        for candidate in candidates:
            if os.path.isfile(candidate):
                return candidate
    roots = []
    home = os.path.expanduser("~")
    roots.append(os.path.join(home, ".coral", "lib"))
    roots.append(os.path.join(os.getcwd(), "lib"))
    if not manifest:
        manifest = import_path.split("::", 1)[0]
    paths = []
    if manifest.endswith(".crl") or "/" in manifest:
        for root in roots:
            base = os.path.join(root, manifest)
            paths.extend([base, base + ".crl"])
    else:
        for root in roots:
            base = os.path.join(root, manifest)
            paths.extend([base + ".crl", os.path.join(base, "lib.crl")])
    for path in paths:
        canonical = _canonical_path(path)
        if os.path.isfile(canonical):
            return canonical
    return None


def resolve_import_path(source_file, import_path, module_map=None):
    for candidate in _import_candidates(source_file, import_path, module_map):
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


def parse_file(path, parsed, all_asts, dep_graph, active=None, module_map=None):
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
            if not hasattr(decl, "path"):
                continue
            imp_path = decl.path
            if getattr(decl, "is_lib", False):
                resolved = resolve_library_import(
                    imp_path, getattr(decl, "lib_path", None), module_map
                )
                tried = [imp_path]
            else:
                resolved = resolve_import_path(abspath, imp_path, module_map)
                tried = _import_candidates(abspath, imp_path, module_map)
            if resolved is None:
                raise UnresolvedImportError(abspath, imp_path, tried)
            if resolved not in deps:
                deps.append(resolved)
            parse_file(resolved, parsed, all_asts, dep_graph, active, module_map)
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


def _manifest_exports(lib_path):
    exports = []
    pattern = re.compile(r'^\s*pub\s+mod\s+([A-Za-z_][A-Za-z0-9_-]*)\s*=\s*import\s+"([^"]+)"\s*;\s*$')
    try:
        with open(lib_path, "r", encoding="utf-8") as f:
            lines = f.readlines()
    except OSError as exc:
        raise ValueError(str(exc)) from exc
    base = os.path.dirname(os.path.abspath(lib_path))
    for line in lines:
        match = pattern.match(line)
        if not match:
            continue
        name, target = match.groups()
        candidates = [
            os.path.join(base, target),
            os.path.join(base, target + ".crl"),
            os.path.join(base, target, "lib.crl"),
        ]
        resolved = next((_canonical_path(path) for path in candidates if os.path.isfile(path)), None)
        if resolved is None:
            raise UnresolvedImportError(lib_path, target, candidates)
        exports.append((name, resolved))
    return exports


def generate_modules_map(module_dirs, output_path, aliases=None):
    aliases = aliases or {}
    module_names = {}
    for directory in module_dirs:
        canonical = _canonical_path(directory)
        name = os.path.basename(canonical)
        if name in module_names:
            raise ValueError(f"duplicate module: {name}")
        module_names[name] = canonical
    lines = ["# coral modules.map v1"]
    for name, directory in sorted(module_names.items()):
        lib_path = os.path.join(directory, "lib.crl")
        if not os.path.isfile(lib_path):
            raise ValueError(f"missing lib.crl: {lib_path}")
        for export, target in _manifest_exports(lib_path):
            relative = os.path.relpath(target, os.getcwd())
            lines.append(f"{name}::{export} -> {relative}")
            for alias, module in sorted(aliases.items()):
                if module == name:
                    lines.append(f"@{alias}::{export} -> {relative}")
    output = os.path.abspath(output_path)
    parent = os.path.dirname(output)
    if not os.path.isdir(parent):
        raise ValueError(f"map output directory does not exist: {parent}")
    with open(output, "w", encoding="utf-8", newline="\n") as f:
        f.write("\n".join(lines) + "\n")
    return output


def _map_main(argv):
    module_dirs = []
    aliases = {}
    output = None
    index = 0
    while index < len(argv):
        arg = argv[index]
        if arg == "--output":
            if index + 1 >= len(argv):
                raise ValueError("--output requires a path")
            output = argv[index + 1]
            index += 1
        elif arg == "--module-dir":
            if index + 1 >= len(argv):
                raise ValueError("--module-dir requires a path")
            module_dirs.append(argv[index + 1])
            index += 1
        elif arg == "--alias":
            if index + 1 >= len(argv) or "=" not in argv[index + 1]:
                raise ValueError("--alias requires NAME=MODULE")
            alias, module = argv[index + 1].split("=", 1)
            if not alias or not module:
                raise ValueError("--alias requires NAME=MODULE")
            aliases[alias] = module
            index += 1
        elif arg.startswith("-"):
            raise ValueError(f"unknown map option: {arg}")
        else:
            module_dirs.append(arg)
        index += 1
    if not module_dirs:
        raise ValueError("map requires at least one module directory")
    if output is None:
        output = ".coral/modules.map"
    result = generate_modules_map(module_dirs, output, aliases)
    print(f"wrote {result}")
    return 0


_USAGE = "usage: coralc <file.crl> [-o output] [--no-compile] [--module-map PATH] [--flag NAME=VALUE]"


def _abort(message, show_usage=False):
    print(f"coralc: error: {message}", file=sys.stderr)
    if show_usage:
        print(_USAGE, file=sys.stderr)
    raise SystemExit(1)


def _parse_args(argv):
    input_path = None
    output_path = "a.out"
    no_compile = False
    module_map = None
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
        elif not options_done and arg == "--module-map":
            if index + 1 >= len(argv) or not argv[index + 1]:
                raise ValueError("--module-map requires a path")
            module_map = argv[index + 1]
            index += 1
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
    if module_map is not None and not os.path.isfile(module_map):
        raise ValueError(f"module map does not exist: {module_map}")

    input_abs = _canonical_path(input_path)
    if _canonical_path(output_path) == input_abs or _canonical_path(c_path) == input_abs:
        raise ValueError("output path must not overwrite the input file")

    return input_path, output_path, no_compile, module_map, flags


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
    if argv and argv[0] == "map":
        try:
            return _map_main(argv[1:])
        except (OSError, ValueError) as exc:
            _abort(str(exc))
    try:
        input_path, output_path, no_compile, module_map, flags = _parse_args(argv)
    except (OSError, ValueError) as exc:
        _abort(str(exc), show_usage=True)

    from parser import StructDecl, EnumDecl, ExtendBlock, VariantDecl, UnionDecl
    from codegen import CodeGen

    parsed = {}
    all_asts = {}
    dep_graph = {}
    try:
        parse_file(input_path, parsed, all_asts, dep_graph, module_map=module_map)
        ordered = topological_sort(dep_graph)
    except UnresolvedImportError as exc:
        _abort(str(exc))
    except ImportCycleError as exc:
        _abort(str(exc))
    except SyntaxError as exc:
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
