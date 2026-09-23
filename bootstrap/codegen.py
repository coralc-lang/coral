from parser import *
from lexer import TokenKind

BUILTIN_TYPES = {
    "void": "void", "bool": "_Bool", "char": "char",
    "u8": "uint8_t", "i8": "int8_t",
    "u16": "uint16_t", "i16": "int16_t",
    "u32": "uint32_t", "i32": "int32_t",
    "u64": "uint64_t", "i64": "int64_t",
    "u128": "__uint128_t", "i128": "__int128_t",
    "f32": "float", "f64": "double",
    "usize": "size_t", "isize": "intptr_t",
    "rawptr": "void*", "str": "_coral_str",
    "self": "self",
}


def tuple_type_name(types):
    parts = []
    for t in types:
        if isinstance(t, TypeIdent):
            parts.append(t.name)
        elif isinstance(t, PointerType):
            parts.append(tuple_type_name([t.base]) + "ptr")
        else:
            parts.append("any")
    return "_coral_tuple_" + "_".join(parts)


class CodeGen:
    def __init__(self):
        self.out = []
        self.indent = 0
        self.struct_names = set()
        self.enum_names = set()
        self.ext_methods = {}
        self.current_file = None
        self.suppress_main = False
        self.tuple_types = {}
        self.local_types = {}
        self.current_self_type = None
        self.current_return_type = None
        self.pointer_fields = {}
        self.field_type_names = {}
        self.flags = {}

    def set_current_file(self, path):
        self.current_file = path
        self.out = []
        self.indent = 0

    def emit(self, s):
        self.out.append(s)

    def emit_indent(self):
        self.emit("    " * self.indent)

    def get_tuple_type(self, types):
        name = tuple_type_name(types)
        if name not in self.tuple_types:
            self.tuple_types[name] = types
        return name

    def gen_type(self, node):
        if node is None:
            return "void"
        if isinstance(node, TypeIdent):
            name = node.name
            if name in BUILTIN_TYPES:
                return BUILTIN_TYPES[name]
            if node.generic_args:
                return f"void*"
            return name
        if isinstance(node, PointerType):
            return self.gen_type(node.base) + "*"
        if isinstance(node, ConstType):
            return "const " + self.gen_type(node.base)
        if isinstance(node, SliceType):
            return "Slice"
        if isinstance(node, ArrayType):
            return self.gen_type(node.base) + f"[{self.gen_expr(node.size)}]"
        if isinstance(node, TupleType):
            return self.get_tuple_type(node.types)
        return "void*"

    def gen_expr(self, node):
        if isinstance(node, IntLit):
            return node.value
        if isinstance(node, FloatLit):
            return node.value
        if isinstance(node, StringLit):
            return node.value
        if isinstance(node, CharLit):
            return node.value
        if isinstance(node, BoolLit):
            return "1" if node.value else "0"
        if isinstance(node, NullLit):
            return "NULL"
        if isinstance(node, Ident):
            if node.name == "self":
                return "self"
            return node.name
        if isinstance(node, BinaryExpr):
            return f"({self.gen_expr(node.left)} {node.op} {self.gen_expr(node.right)})"
        if isinstance(node, UnaryExpr):
            if node.op in ("++post", "--post", "++pre", "--pre"):
                op = node.op.replace("post", "").replace("pre", "")
                if "pre" in node.op:
                    return f"({op}{self.gen_expr(node.expr)})"
                return f"({self.gen_expr(node.expr)}{op})"
            return f"({node.op} {self.gen_expr(node.expr)})"
        if isinstance(node, CallExpr):
            func_name = self.gen_expr(node.func)
            args = ", ".join(self.gen_expr(a) for a in node.args)
            if isinstance(node.func, DotExpr) and isinstance(node.func.obj, Ident) and node.func.obj.name == "self":
                obj_type = self.current_self_type or "Lexer"
                method_name = self.gen_expr(node.func.field)
                all_args = "self" + (", " + args if args else "")
                return f"{obj_type}_{method_name}({all_args})"
            if isinstance(node.func, DotExpr) and isinstance(node.func.obj, Ident):
                obj_name = node.func.obj.name
                if obj_name in self.local_types:
                    raw_tp = self.local_types[obj_name]
                    is_ptr = raw_tp.strip().endswith('*')
                    obj_type = raw_tp.rstrip('*').strip()
                    method_name = self.gen_expr(node.func.field)
                    arg0 = obj_name if is_ptr else f"&{obj_name}"
                    all_args = arg0 + (", " + args if args else "")
                    return f"{obj_type}_{method_name}({all_args})"
            if isinstance(node.func, DotExpr) and isinstance(node.func.obj, DotExpr) and isinstance(node.func.obj.obj, Ident) and node.func.obj.obj.name == "self":
                outer_field = self.gen_expr(node.func.obj.field)
                method_name = self.gen_expr(node.func.field)
                st = self.current_self_type or "Lexer"
                type_name = self.field_type_names.get((st, outer_field), outer_field.capitalize())
                inner_arg = f"self->{outer_field}"
                all_args = inner_arg + (", " + args if args else "")
                return f"{type_name}_{method_name}({all_args})"
            if isinstance(node.func, DotExpr) and isinstance(node.func.obj, DotExpr) and isinstance(node.func.obj.obj, Ident):
                a_name = node.func.obj.obj.name
                b_field = self.gen_expr(node.func.obj.field)
                c_method = self.gen_expr(node.func.field)
                if a_name in self.local_types:
                    a_raw = self.local_types[a_name]
                    a_is_ptr = a_raw.strip().endswith('*')
                    a_type = a_raw.rstrip('*').strip()
                    field_type = self.field_type_names.get((a_type, b_field), b_field.capitalize())
                    is_a_ptr = a_is_ptr
                    obj_inner = f"{a_name}->{b_field}" if is_a_ptr else f"{a_name}.{b_field}"
                    # b_field is Lexer* if Parser.lexer, so obj_inner already is Lexer*
                    all_args = f"{obj_inner}" + (", " + args if args else "")
                    return f"{field_type}_{c_method}({all_args})"
            return f"{func_name}({args})"
        if isinstance(node, DotExpr):
            obj_str = self.gen_expr(node.obj)
            field_str = self.gen_expr(node.field)
            if obj_str in ("diag", "lbl"):
                return f"{obj_str}->{field_str}"
            if isinstance(node.obj, Ident) and node.obj.name == "self":
                return f"self->{field_str}"
            if isinstance(node.obj, Ident) and node.obj.name in self.local_types and self.local_types[node.obj.name].strip().endswith('*'):
                return f"{obj_str}->{field_str}"
            if isinstance(node.obj, DotExpr) and isinstance(node.obj.obj, Ident) and node.obj.obj.name == "self":
                outer_field = self.gen_expr(node.obj.field)
                st = self.current_self_type or "Lexer"
                field_type = self.field_type_names.get((st, outer_field), "")
                if field_type.strip().endswith('*'):
                    return f"{obj_str}->{field_str}"
                else:
                    return f"{obj_str}.{field_str}"
            # Fallback: value field access uses .
            return f"{obj_str}.{field_str}"
            if isinstance(node.field, IntLit):
                return f"{obj_str}._{field_str}"
            return f"{obj_str}.{field_str}"
        if isinstance(node, ColonColonExpr):
            left = self.gen_expr(node.left)
            right = self.gen_expr(node.right)
            return f"{left}_{right}"
        if isinstance(node, StructLiteral):
            te = node.type_expr
            if hasattr(te, 'left') and hasattr(te, 'right'):
                tn = self.gen_expr(te.left)
                vn = self.gen_expr(te.right)
                fields = ", ".join(
                    f".{fn} = {self.gen_expr(fv)}"
                    for fn, fv in zip(node.field_names, node.field_values)
                )
                return f"({tn}){{ .tag = {tn}_{vn}, .payload.{vn} = {{{fields}}} }}"
            tname = self.gen_expr(te)
            fields = ", ".join(
                f".{fn} = {self.gen_expr(fv)}"
                for fn, fv in zip(node.field_names, node.field_values)
            )
            return f"({tname}){{{fields}}}"
        if isinstance(node, StarDotExpr):
            return f"{self.gen_expr(node.obj)}->{self.gen_expr(node.field)}"
        if isinstance(node, IndexExpr):
            return f"{self.gen_expr(node.obj)}[{self.gen_expr(node.index)}]"
        if isinstance(node, Assign):
            return f"({self.gen_expr(node.target)} {node.op} {self.gen_expr(node.value)})"
        if isinstance(node, TernaryExpr):
            return f"({self.gen_expr(node.cond)} ? {self.gen_expr(node.then_expr)} : {self.gen_expr(node.else_expr)})"
        if isinstance(node, SizeofExpr):
            return f"sizeof({self.gen_type(node.type_node)})"
        if isinstance(node, CastExpr):
            return f"(({self.gen_type(node.type_node)}){self.gen_expr(node.expr)})"
        if isinstance(node, TupleExpr):
            if self.current_return_type:
                return f"({self.current_return_type}){{ " + ", ".join(self.gen_expr(e) for e in node.exprs) + " }"
            return "{ " + ", ".join(self.gen_expr(e) for e in node.exprs) + " }"
        if isinstance(node, BuiltinCall):
            if node.name == "assert":
                return f"assert({self.gen_expr(node.args[0]) if node.args else ''})"
            elif node.name == "alignof":
                return f"_Alignof({self.gen_expr(node.args[0])})"
            elif node.name == "sizeof":
                return f"sizeof({self.gen_expr(node.args[0])})"
            elif node.name == "typeof":
                return f"typeof({self.gen_expr(node.args[0])})"
            elif node.name == "offsetof":
                return f"__builtin_offsetof({self.gen_type(node.args[0])}, {self.gen_expr(node.args[1])})"
            return f"/* @builtin {node.name} */"
        if isinstance(node, Block):
            return "(void)0"
        return "/* unhandled expr */"

    def gen_stmt(self, node):
        self.emit_indent()
        if isinstance(node, ReturnStmt):
            if node.expr:
                self.emit(f"return {self.gen_expr(node.expr)};\n")
            else:
                self.emit("return;\n")
            return
        if isinstance(node, ExprStmt):
            self.emit(f"{self.gen_expr(node.expr)};\n")
            return
        if isinstance(node, VarDecl):
            tp = self.gen_type(node.type_node)
            name = node.name
            self.local_types[name] = tp
            # also handle Token* etc. where tp includes *
            if node.init_expr:
                self.emit(f"{tp} {name} = {self.gen_expr(node.init_expr)};\n")
            else:
                self.emit(f"{tp} {name};\n")
            return
        if isinstance(node, Assign):
            self.emit(f"{self.gen_expr(node.target)} = {self.gen_expr(node.value)};\n")
            return
        if isinstance(node, BreakStmt):
            self.emit("break;\n")
            return
        if isinstance(node, ContinueStmt):
            self.emit("continue;\n")
            return
        if isinstance(node, DeferStmt):
            self.emit("/* defer */\n")
            return
        if isinstance(node, IfExpr):
            self.emit(f"if ({self.gen_expr(node.cond)}) ")
            self.gen_block(node.then_body)
            if node.else_body:
                self.emit(" else ")
                if isinstance(node.else_body, Block):
                    self.gen_block(node.else_body)
                else:
                    self.gen_block(node.else_body)
            self.emit("\n")
            return
        if isinstance(node, WhileStmt):
            self.emit(f"while ({self.gen_expr(node.cond)}) ")
            self.gen_block(node.body)
            self.emit("\n")
            return
        if isinstance(node, ForStmt):
            self.emit("for (")
            if node.init:
                if isinstance(node.init, VarDecl):
                    tp = self.gen_type(node.init.type_node)
                    self.emit(f"{tp} {node.init.name} = {self.gen_expr(node.init.init_expr)}")
                else:
                    self.emit(self.gen_expr(node.init.expr) if isinstance(node.init, ExprStmt) else "")
            self.emit("; ")
            if node.cond:
                self.emit(self.gen_expr(node.cond))
            self.emit("; ")
            if node.post:
                if isinstance(node.post, ExprStmt):
                    self.emit(self.gen_expr(node.post.expr))
                elif isinstance(node.post, Assign):
                    self.emit(self.gen_expr(node.post))
            self.emit(") ")
            self.gen_block(node.body)
            self.emit("\n")
            return
        if isinstance(node, ForInStmt):
            self.emit(f"for (size_t _idx = 0; _idx < {self.gen_expr(node.iter_expr)}.len; _idx++) ")
            if isinstance(node.body, Block):
                self.emit("{\n")
                self.indent_level += 1
                self.emit_indent()
                self.emit(f"{BUILTIN_TYPES.get('char', 'char')} {node.binding} = ")
                self.emit(f"((char*){self.gen_expr(node.iter_expr)}.ptr)[_idx];\n")
                for stmt in node.body.stmts:
                    self.gen_stmt(stmt)
                self.indent_level -= 1
                self.emit_indent()
                self.emit("}\n")
            else:
                self.emit("{\n")
                self.indent_level += 1
                self.emit_indent()
                self.emit(f"{BUILTIN_TYPES.get('char', 'char')} {node.binding} = ")
                self.emit(f"((char*){self.gen_expr(node.iter_expr)}.ptr)[_idx];\n")
                self.gen_stmt(node.body)
                self.indent_level -= 1
                self.emit_indent()
                self.emit("}\n")
            return
        if isinstance(node, LoopStmt):
            self.emit("while (1) ")
            self.gen_block(node.body)
            self.emit("\n")
            return
        if isinstance(node, ComptimeBlock):
            for s in node.stmts:
                self.gen_stmt(s)
            return
        if isinstance(node, AsmStmt):
            self.emit("asm ")
            if node.volatile:
                self.emit("volatile ")
            self.emit("(\n")
            self.indent_level += 1
            self.emit_indent()
            parts = " \\n ".join(f"\"{p}\"" for p in node.template)
            self.emit(f"{parts}\n")
            self.indent_level -= 1
            self.emit_indent()
            self.emit(");\n")
            return
        if isinstance(node, BuiltinCall):
            if node.name == "assert":
                self.emit(f"assert({self.gen_expr(node.args[0]) if node.args else ''});\n")
            elif node.name == "alignof":
                self.emit(f"_Alignof({self.gen_expr(node.args[0])});\n")
            elif node.name == "typeof":
                self.emit(f"typeof({self.gen_expr(node.args[0])});\n")
            else:
                self.emit(f"/* @builtin {node.name} */;\n")
            return
            return
        if isinstance(node, SwitchStmt):
            self.emit(f"switch ({self.gen_expr(node.expr)}) {{\n")
            self.indent += 1
            for pattern, body in node.cases:
                self.emit_indent()
                if isinstance(pattern, DestructPattern):
                    self.emit(f"case {pattern.name}:\n")
                elif isinstance(pattern, OrPattern):
                    for i, p in enumerate(pattern.patterns):
                        self.emit_indent()
                        self.emit(f"case {self.gen_expr(p)}:\n")
                else:
                    self.emit(f"case {self.gen_expr(pattern)}:\n")
                self.indent += 1
                for s in body.stmts:
                    self.gen_stmt(s)
                self.emit_indent()
                self.emit("break;\n")
                self.indent -= 1
            if node.else_body:
                self.emit_indent()
                self.emit("default:\n")
                self.indent += 1
                for s in node.else_body.stmts:
                    self.gen_stmt(s)
                self.emit_indent()
                self.emit("break;\n")
                self.indent -= 1
            self.indent -= 1
            self.emit_indent()
            self.emit("}\n")
            return
        if isinstance(node, Block):
            self.gen_block(node)
            self.emit("\n")
            return
        self.emit(f"/* unhandled: {type(node).__name__} */\n")

    def gen_block(self, node):
        self.emit("{\n")
        self.indent += 1
        for stmt in node.stmts:
            self.gen_stmt(stmt)
        self.indent -= 1
        self.emit_indent()
        self.emit("}")

    def gen_func(self, node):
        ret = self.gen_type(node.return_type)
        name = node.name
        saved_return = self.current_return_type
        self.current_return_type = ret
        saved_locals = self.local_types
        self.local_types = {}

        if node.self_type:
            st = self.gen_type(node.self_type)
            st_name = st
            if st_name not in self.ext_methods:
                self.ext_methods[st_name] = []
            self.ext_methods[st_name].append(node)

        params = []
        for p in node.params:
            if p.name == "...":
                params.append("...")
            else:
                tp = self.gen_type(p.type_node)
                params.append(f"{tp} {p.name}")
                if p.name != "self":
                    self.local_types[p.name] = tp.rstrip('*').strip()

        param_str = ", ".join(params)

        if node.is_extern:
            self.emit_indent()
            self.emit(f"extern {ret} {name}({param_str});\n")
            return

        self.emit_indent()
        if node.is_pub:
            self.emit("/* pub */ ")
        self.emit(f"{ret} {name}({param_str}) ")
        self.gen_block(node.body)
        self.emit("\n")
        self.current_return_type = saved_return
        self.local_types = saved_locals

    def gen_struct(self, node):
        self.struct_names.add(node.name)
        name = node.name
        self.emit(f"typedef struct {name} {{\n")
        self.pointer_fields[name] = set()
        for f in node.fields:
            tp = self.gen_type(f.type_node)
            self.emit(f"    {tp} {f.name};\n")
            if isinstance(f.type_node, PointerType):
                self.pointer_fields[name].add(f.name)
                self.field_type_names[(name, f.name)] = tp
            else:
                self.field_type_names[(name, f.name)] = tp
        self.emit(f"}} {name};\n\n")
        for method in node.methods:
            st = name
            method.self_type = TypeIdent(name)
            saved = self.current_self_type
            self.current_self_type = st
            saved_return = self.current_return_type
            ret = self.gen_type(method.return_type)
            self.current_return_type = ret
            has_self = any(p.name == "self" for p in method.params)
            if has_self:
                params = [f"{st}* self"] + [
                    f"{self.gen_type(p.type_node)} {p.name}" for p in method.params if p.name != "self"
                ]
            elif getattr(method, 'is_static', False):
                params = [
                    f"{self.gen_type(p.type_node)} {p.name}" for p in method.params
                ]
            else:
                params = [f"{st}* self"] + [
                    f"{self.gen_type(p.type_node)} {p.name}" for p in method.params
                ]
            param_str = ", ".join(params)
            if method.is_extern:
                self.emit_indent()
                self.emit(f"extern {ret} {st}_{method.name}({param_str});\n")
            else:
                self.emit_indent()
                self.emit(f"{ret} {st}_{method.name}({param_str}) ")
                self.gen_block(method.body)
                self.emit("\n")
            self.current_self_type = saved
            self.current_return_type = saved_return

    def gen_enum(self, node):
        self.emit(f"enum {node.name} {{\n")
        for i, v in enumerate(node.variants):
            if i == 0:
                self.emit(f"    {node.name}_{v} = 0")
            else:
                self.emit(f"    {node.name}_{v}")
            if i < len(node.variants) - 1:
                self.emit(",\n")
            else:
                self.emit("\n")
        self.emit(f"}};\n\n")

    def gen_variant(self, node):
        name = node.name
        tag_name = f"{name}_tag"
        self.emit(f"enum {tag_name} {{\n")
        for i, v in enumerate(node.variants):
            if i == 0:
                self.emit(f"    {name}_{v.name} = 0")
            else:
                self.emit(f"    {name}_{v.name}")
            if i < len(node.variants) - 1:
                self.emit(",\n")
            else:
                self.emit("\n")
        self.emit(f"}};\n\n")
        self.emit(f"typedef struct {name} {{\n")
        self.emit(f"    enum {tag_name} tag;\n")
        if any(len(v.fields) > 0 for v in node.variants):
            self.emit(f"    union {{\n")
            for v in node.variants:
                if len(v.fields) > 0:
                    self.emit(f"        struct {{\n")
                    for f in v.fields:
                        self.emit(f"            {self.gen_type(f.type_node)} {f.name};\n")
                    self.emit(f"        }} {v.name};\n")
            self.emit(f"    }} payload;\n")
        self.emit(f"}} {name};\n\n")
        for method in node.methods:
            st = name
            method.self_type = TypeIdent(name)
            saved = self.current_self_type
            self.current_self_type = st
            ret = self.gen_type(method.return_type)
            has_self = any(p.name == "self" for p in method.params)
            if has_self:
                params = [f"{st}* self"] + [
                    f"{self.gen_type(p.type_node)} {p.name}" for p in method.params if p.name != "self"
                ]
            elif getattr(method, 'is_static', False):
                params = [
                    f"{self.gen_type(p.type_node)} {p.name}" for p in method.params
                ]
            else:
                params = [f"{st}* self"] + [
                    f"{self.gen_type(p.type_node)} {p.name}" for p in method.params
                ]
            param_str = ", ".join(params)
            if method.is_extern:
                self.emit_indent()
                self.emit(f"extern {ret} {st}_{method.name}({param_str});\n")
            else:
                self.emit_indent()
                self.emit(f"{ret} {st}_{method.name}({param_str}) ")
                self.gen_block(method.body)
                self.emit("\n")
            self.current_self_type = saved

    def gen_union(self, node):
        name = node.name
        self.emit(f"typedef union {name} {{\n")
        for f in node.fields:
            self.emit(f"    {self.gen_type(f.type_node)} {f.name};\n")
        self.emit(f"}} {name};\n\n")

    def gen_tuple_typedefs(self):
        for name, types in self.tuple_types.items():
            self.emit(f"typedef struct {name} {{\n")
            for i, t in enumerate(types):
                self.emit(f"    {self.gen_type(t)} _{i};\n")
            self.emit(f"}} {name};\n")
        if self.tuple_types:
            self.emit("\n")

    def collect_tuple_types(self, node):
        if isinstance(node, TupleType):
            name = tuple_type_name(node.types)
            if name not in self.tuple_types:
                self.tuple_types[name] = node.types
        elif isinstance(node, PointerType):
            self.collect_tuple_types(node.base)
        elif isinstance(node, ArrayType):
            self.collect_tuple_types(node.base)
        elif isinstance(node, ConstType):
            self.collect_tuple_types(node.base)
        elif isinstance(node, FuncDecl):
            self.collect_tuple_types(node.return_type)
            for p in node.params:
                self.collect_tuple_types(p.type_node)
        elif isinstance(node, ParamDecl):
            self.collect_tuple_types(node.type_node)
        elif isinstance(node, FieldDecl):
            self.collect_tuple_types(node.type_node)
        elif isinstance(node, StructDecl):
            for f in node.fields:
                self.collect_tuple_types(f)
            for m in node.methods:
                self.collect_tuple_types(m)
        elif isinstance(node, ExtendBlock):
            for m in node.methods:
                self.collect_tuple_types(m)

    def collect_ast_tuple_types(self, ast):
        for decl in ast.decls:
            self.collect_tuple_types(decl)

    def generate(self, ast):
        self.emit("#include <stdint.h>\n")
        self.emit("#include <stddef.h>\n")
        self.emit("#include <stdbool.h>\n")
        self.emit("#include <string.h>\n")
        self.emit("#include <stdlib.h>\n\n")

        self.emit("typedef struct _coral_str { const uint8_t* ptr; size_t len; } _coral_str;\n\n")

        self.collect_ast_tuple_types(ast)

        for decl in ast.decls:
            if isinstance(decl, StructDecl):
                self.struct_names.add(decl.name)
            elif isinstance(decl, EnumDecl):
                self.enum_names.add(decl.name)
            elif isinstance(decl, VariantDecl):
                self.struct_names.add(decl.name)
            elif isinstance(decl, UnionDecl):
                self.struct_names.add(decl.name)
            elif isinstance(decl, DistinctDecl):
                self.struct_names.add(decl.name)

        for name in self.struct_names:
            self.emit(f"typedef struct {name} {name};\n")
        for name in self.enum_names:
            self.emit(f"typedef enum {name} {name};\n")
        if self.struct_names or self.enum_names:
            self.emit("\n")

        for decl in ast.decls:
            if isinstance(decl, FuncDecl) and decl.is_extern:
                ret = self.gen_type(decl.return_type)
                params = []
                for p in decl.params:
                    if p.name == "...":
                        params.append("...")
                    else:
                        tp = self.gen_type(p.type_node)
                        params.append(f"{tp} {p.name}")
                param_str = ", ".join(params)
                self.emit(f"extern {ret} {decl.name}({param_str});\n")
        self.emit("\n")

        self.gen_tuple_typedefs()

        for decl in ast.decls:
            if isinstance(decl, FuncDecl):
                if not decl.is_extern:
                    ret = self.gen_type(decl.return_type)
                    params = []
                    for p in decl.params:
                        if p.name == "...":
                            params.append("...")
                        else:
                            tp = self.gen_type(p.type_node)
                            params.append(f"{tp} {p.name}")
                    param_str = ", ".join(params)
                    self.emit(f"{ret} {decl.name}({param_str});\n")
            elif isinstance(decl, StructDecl):
                st = decl.name
                for method in decl.methods:
                    if method.is_extern:
                        continue
                    method.self_type = TypeIdent(st)
                    ret = self.gen_type(method.return_type)
                    has_self = any(p.name == "self" for p in method.params)
                    if has_self:
                        params = [f"{st}* self"] + [
                            f"{self.gen_type(p.type_node)} {p.name}" for p in method.params if p.name != "self"
                        ]
                    elif getattr(method, 'is_static', False):
                        params = [
                            f"{self.gen_type(p.type_node)} {p.name}" for p in method.params
                        ]
                    else:
                        params = [f"{st}* self"] + [
                            f"{self.gen_type(p.type_node)} {p.name}" for p in method.params
                        ]
                    param_str = ", ".join(params)
                    self.emit(f"{ret} {st}_{method.name}({param_str});\n")
            elif isinstance(decl, ExtendBlock):
                st = self.gen_type(decl.type_node)
                for method in decl.methods:
                    if method.is_extern:
                        continue
                    ret = self.gen_type(method.return_type)
                    has_self = any(p.name == "self" for p in method.params)
                    if has_self:
                        params = [f"{st}* self"] + [
                            f"{self.gen_type(p.type_node)} {p.name}" for p in method.params if p.name != "self"
                        ]
                    elif getattr(method, 'is_static', False):
                        params = [
                            f"{self.gen_type(p.type_node)} {p.name}" for p in method.params
                        ]
                    else:
                        params = [f"{st}* self"] + [
                            f"{self.gen_type(p.type_node)} {p.name}" for p in method.params
                        ]
                    param_str = ", ".join(params)
                    self.emit(f"{ret} {st}_{method.name}({param_str});\n")
            elif isinstance(decl, ExtendTraitBlock):
                st = self.gen_type(decl.type_node)
                for method in decl.methods:
                    if method.is_extern:
                        continue
                    ret = self.gen_type(method.return_type)
                    has_self = any(p.name == "self" for p in method.params)
                    if has_self:
                        params = [f"{st}* self"] + [
                            f"{self.gen_type(p.type_node)} {p.name}" for p in method.params if p.name != "self"
                        ]
                    elif getattr(method, 'is_static', False):
                        params = [
                            f"{self.gen_type(p.type_node)} {p.name}" for p in method.params
                        ]
                    else:
                        params = [f"{st}* self"] + [
                            f"{self.gen_type(p.type_node)} {p.name}" for p in method.params
                        ]
                    param_str = ", ".join(params)
                    self.emit(f"{ret} {st}_{method.name}({param_str});\n")
            elif isinstance(decl, VariantDecl):
                pass
            elif isinstance(decl, UnionDecl):
                pass
            elif isinstance(decl, DistinctDecl):
                base = self.gen_type(decl.base_type)
                self.emit(f"typedef {base} {decl.name};\n")
            elif isinstance(decl, TypedefDecl):
                target = self.gen_type(decl.target_type)
                self.emit(f"typedef {target} {decl.name};\n")
            elif isinstance(decl, FlagDecl):
                pass
            elif isinstance(decl, TraitDecl):
                pass
        self.emit("\n")

        for decl in ast.decls:
            if isinstance(decl, StructDecl):
                self.gen_struct(decl)
            elif isinstance(decl, EnumDecl):
                self.gen_enum(decl)
            elif isinstance(decl, VariantDecl):
                self.gen_variant(decl)
            elif isinstance(decl, UnionDecl):
                self.gen_union(decl)

        self.gen_tuple_typedefs()

        for decl in ast.decls:
            if isinstance(decl, FuncDecl):
                self.gen_func(decl)
            elif isinstance(decl, ExtendBlock):
                for method in decl.methods:
                    st = self.gen_type(decl.type_node)
                    st_name = st
                    method.self_type = decl.type_node
                    saved = self.current_self_type
                    self.current_self_type = st
                    ret = self.gen_type(method.return_type)
                    has_self = any(p.name == "self" for p in method.params)
                    if has_self:
                        params = [f"{st}* self"] + [
                            f"{self.gen_type(p.type_node)} {p.name}" for p in method.params if p.name != "self"
                        ]
                    elif getattr(method, 'is_static', False):
                        params = [
                            f"{self.gen_type(p.type_node)} {p.name}" for p in method.params
                        ]
                    else:
                        params = [f"{st}* self"] + [
                            f"{self.gen_type(p.type_node)} {p.name}" for p in method.params
                        ]
                    param_str = ", ".join(params)
                    if method.is_extern:
                        self.emit_indent()
                        self.emit(f"extern {ret} {st_name}_{method.name}({param_str});\n")
                    else:
                        self.emit_indent()
                        self.emit(f"{ret} {st_name}_{method.name}({param_str}) ")
                        self.gen_block(method.body)
                        self.emit("\n")
                    self.current_self_type = saved
            elif isinstance(decl, ExtendTraitBlock):
                for method in decl.methods:
                    st = self.gen_type(decl.type_node)
                    st_name = st
                    method.self_type = decl.type_node
                    saved = self.current_self_type
                    self.current_self_type = st
                    ret = self.gen_type(method.return_type)
                    has_self = any(p.name == "self" for p in method.params)
                    if has_self:
                        params = [f"{st}* self"] + [
                            f"{self.gen_type(p.type_node)} {p.name}" for p in method.params if p.name != "self"
                        ]
                    elif getattr(method, 'is_static', False):
                        params = [
                            f"{self.gen_type(p.type_node)} {p.name}" for p in method.params
                        ]
                    else:
                        params = [f"{st}* self"] + [
                            f"{self.gen_type(p.type_node)} {p.name}" for p in method.params
                        ]
                    param_str = ", ".join(params)
                    if method.is_extern:
                        self.emit_indent()
                        self.emit(f"extern {ret} {st_name}_{method.name}({param_str});\n")
                    else:
                        self.emit_indent()
                        self.emit(f"{ret} {st_name}_{method.name}({param_str}) ")
                        self.gen_block(method.body)
                        self.emit("\n")
                    self.current_self_type = saved
            elif isinstance(decl, FlagDecl):
                target_branch = None
                flag_val = self.flags.get(decl.flag_name)
                if flag_val:
                    for b in decl.branches:
                        if b.label == flag_val:
                            target_branch = b
                            break
                if target_branch is None:
                    for b in decl.branches:
                        if b.label == "default" or b.label == "else":
                            target_branch = b
                            break
                if target_branch is None and decl.branches:
                    target_branch = decl.branches[0]
                if target_branch:
                    for s in target_branch.stmts:
                        self.gen_stmt(s)

        if not self.suppress_main:
            has_main = any(isinstance(d, FuncDecl) and d.name == "main" for d in ast.decls)
            if not has_main:
                self.emit("int main(int argc, char** argv) {\n")
                self.emit("    return 0;\n")
                self.emit("}\n")

        return "".join(self.out)
