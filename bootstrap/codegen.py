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


class CodeGen:
    def __init__(self):
        self.out = []
        self.indent = 0
        self.struct_names = set()
        self.ext_methods = {}
        self.typedefs = {}

    def emit(self, s):
        self.out.append(s)

    def emit_indent(self):
        self.emit("    " * self.indent)

    def gen_type(self, node):
        if node is None:
            return "void"
        if isinstance(node, TypeIdent):
            name = node.name
            if name in BUILTIN_TYPES:
                return BUILTIN_TYPES[name]
            return "_coral_" + name if name in self.struct_names else name
        if isinstance(node, PointerType):
            return self.gen_type(node.base) + "*"
        if isinstance(node, ConstType):
            return "const " + self.gen_type(node.base)
        if isinstance(node, SliceType):
            return "_coral_slice"
        if isinstance(node, ArrayType):
            return self.gen_type(node.base) + f"[{self.gen_expr(node.size)}]"
        if isinstance(node, TupleType):
            return "_coral_tuple"
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
            func = self.gen_expr(node.func)
            args = ", ".join(self.gen_expr(a) for a in node.args)
            return f"{func}({args})"
        if isinstance(node, DotExpr):
            return f"{self.gen_expr(node.obj)}.{self.gen_expr(node.field)}"
        if isinstance(node, ColonColonExpr):
            left = self.gen_expr(node.left)
            right = self.gen_expr(node.right)
            return f"{left}_{right}"
        if isinstance(node, StarDotExpr):
            return f"{self.gen_expr(node.obj)}->{self.gen_expr(node.field)}"
        if isinstance(node, IndexExpr):
            return f"{self.gen_expr(node.obj)}[{self.gen_expr(node.index)}]"
        if isinstance(node, Assign):
            return f"({self.gen_expr(node.target)} = {self.gen_expr(node.value)})"
        if isinstance(node, SizeofExpr):
            return f"sizeof({self.gen_type(node.type_node)})"
        if isinstance(node, CastExpr):
            return f"(({self.gen_type(node.type_node)}){self.gen_expr(node.expr)})"
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
        if isinstance(node, SwitchStmt):
            self.emit(f"switch ({self.gen_expr(node.expr)}) {{\n")
            self.indent += 1
            for val, body in node.cases:
                self.emit_indent()
                self.emit(f"case {self.gen_expr(val)}:\n")
                self.indent += 1
                for s in body.stmts:
                    self.gen_stmt(s)
                self.emit_indent()
                self.emit("break;\n")
                self.indent -= 1
            if node.default:
                self.emit_indent()
                self.emit("default:\n")
                self.indent += 1
                for s in node.default.stmts:
                    self.gen_stmt(s)
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

        if node.self_type:
            st = self.gen_type(node.self_type)
            st_name = st.replace("_coral_", "")
            if st_name not in self.ext_methods:
                self.ext_methods[st_name] = []
            self.ext_methods[st_name].append(node)

        params = []
        for p in node.params:
            tp = self.gen_type(p.type_node)
            params.append(f"{tp} {p.name}")

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

    def gen_struct(self, node):
        self.struct_names.add(node.name)
        name = node.name
        self.emit(f"typedef struct {name} {{\n")
        for f in node.fields:
            self.emit(f"    {self.gen_type(f.type_node)} {f.name};\n")
        self.emit(f"}} {name};\n\n")

    def gen_enum(self, node):
        self.emit(f"enum {node.name} {{\n")
        for i, v in enumerate(node.variants):
            if i == 0:
                self.emit(f"    {node.name}_{v} = 0,\n")
            else:
                self.emit(f"    {node.name}_{v},\n")
        self.emit(f"}};\n\n")

    def generate(self, ast):
        self.emit("#include <stdint.h>\n")
        self.emit("#include <stddef.h>\n")
        self.emit("#include <stdbool.h>\n")
        self.emit("#include <string.h>\n")
        self.emit("#include <stdlib.h>\n")
        self.emit("#include <stdio.h>\n\n")

        self.emit("typedef struct _coral_str { const uint8_t* ptr; size_t len; } _coral_str;\n\n")

        for decl in ast.decls:
            if isinstance(decl, StructDecl):
                self.gen_struct(decl)
            elif isinstance(decl, EnumDecl):
                self.gen_enum(decl)

        forward = []
        for decl in ast.decls:
            if isinstance(decl, FuncDecl) and not decl.is_extern:
                ret = self.gen_type(decl.return_type)
                params = []
                for p in decl.params:
                    tp = self.gen_type(p.type_node)
                    params.append(f"{tp} {p.name}")
                forward.append(f"{ret} {decl.name}({', '.join(params)});")
            elif isinstance(decl, ExtendBlock):
                for m in decl.methods:
                    if not m.is_extern:
                        ret = self.gen_type(m.return_type)
                        st = self.gen_type(decl.type_node).replace("_coral_", "")
                        params = [f"{self.gen_type(decl.type_node)} self"] + [
                            f"{self.gen_type(p.type_node)} {p.name}" for p in m.params if p.name != "self"
                        ]
                        forward.append(f"{ret} {st}_{m.name}({', '.join(params)});")

        if forward:
            self.emit("/* forward declarations */\n")
            for f in forward:
                self.emit(f"{f}\n")
            self.emit("\n")

        for decl in ast.decls:
            if isinstance(decl, ImportDecl):
                continue
            if isinstance(decl, ModReexport):
                continue
            if isinstance(decl, StructDecl):
                continue
            if isinstance(decl, EnumDecl):
                continue
            if isinstance(decl, FuncDecl):
                self.gen_func(decl)
            elif isinstance(decl, ExtendBlock):
                for method in decl.methods:
                    st = self.gen_type(decl.type_node)
                    st_name = st.replace("_coral_", "")
                    method.self_type = decl.type_node
                    ret = self.gen_type(method.return_type)
                    params = [f"{st} self"] + [
                        f"{self.gen_type(p.type_node)} {p.name}" for p in method.params if p.name != "self"
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

        if "__main__" in [d.name for d in ast.decls if isinstance(d, FuncDecl)]:
            pass
        else:
            self.emit("int main(int argc, char** argv) {\n")
            self.emit("    return 0;\n")
            self.emit("}\n")

        return "".join(self.out)
