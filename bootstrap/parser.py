from lexer import TokenKind


class Node:
    pass


class SourceFile(Node):
    def __init__(self, decls):
        self.decls = decls


class ImportDecl(Node):
    def __init__(self, path, symbols, is_lib, lib_path):
        self.path = path
        self.symbols = symbols
        self.is_lib = is_lib
        self.lib_path = lib_path


class ModReexport(Node):
    def __init__(self, alias, path, is_lib, lib_path):
        self.alias = alias
        self.path = path
        self.is_lib = is_lib
        self.lib_path = lib_path


class StructDecl(Node):
    def __init__(self, name, fields, is_pub):
        self.name = name
        self.fields = fields
        self.is_pub = is_pub


class FieldDecl(Node):
    def __init__(self, type_node, name):
        self.type_node = type_node
        self.name = name


class EnumDecl(Node):
    def __init__(self, name, variants, is_pub):
        self.name = name
        self.variants = variants
        self.is_pub = is_pub


class FuncDecl(Node):
    def __init__(self, name, params, return_type, body, is_pub, is_extern, is_static, is_method, self_type):
        self.name = name
        self.params = params
        self.return_type = return_type
        self.body = body
        self.is_pub = is_pub
        self.is_extern = is_extern
        self.is_static = is_static
        self.is_method = is_method
        self.self_type = self_type


class ParamDecl(Node):
    def __init__(self, type_node, name):
        self.type_node = type_node
        self.name = name


class ExtendBlock(Node):
    def __init__(self, type_node, methods):
        self.type_node = type_node
        self.methods = methods


class Block(Node):
    def __init__(self, stmts):
        self.stmts = stmts


class ReturnStmt(Node):
    def __init__(self, expr):
        self.expr = expr


class ExprStmt(Node):
    def __init__(self, expr):
        self.expr = expr


class VarDecl(Node):
    def __init__(self, type_node, name, init_expr):
        self.type_node = type_node
        self.name = name
        self.init_expr = init_expr


class Assign(Node):
    def __init__(self, target, value):
        self.target = target
        self.value = value


class IfExpr(Node):
    def __init__(self, cond, then_body, else_body):
        self.cond = cond
        self.then_body = then_body
        self.else_body = else_body


class WhileStmt(Node):
    def __init__(self, cond, body):
        self.cond = cond
        self.body = body


class ForStmt(Node):
    def __init__(self, init, cond, post, body):
        self.init = init
        self.cond = cond
        self.post = post
        self.body = body


class SwitchStmt(Node):
    def __init__(self, expr, cases, default):
        self.expr = expr
        self.cases = cases
        self.default = default


class BreakStmt(Node):
    pass


class ContinueStmt(Node):
    pass


class DeferStmt(Node):
    def __init__(self, stmt):
        self.stmt = stmt


class CallExpr(Node):
    def __init__(self, func, args):
        self.func = func
        self.args = args


class IndexExpr(Node):
    def __init__(self, obj, index):
        self.obj = obj
        self.index = index


class DotExpr(Node):
    def __init__(self, obj, field):
        self.obj = obj
        self.field = field


class ColonColonExpr(Node):
    def __init__(self, left, right):
        self.left = left
        self.right = right


class StarDotExpr(Node):
    def __init__(self, obj, field):
        self.obj = obj
        self.field = field


class UnaryExpr(Node):
    def __init__(self, op, expr):
        self.op = op
        self.expr = expr


class BinaryExpr(Node):
    def __init__(self, op, left, right):
        self.op = op
        self.left = left
        self.right = right


class CastExpr(Node):
    def __init__(self, type_node, expr):
        self.type_node = type_node
        self.expr = expr


class SizeofExpr(Node):
    def __init__(self, type_node):
        self.type_node = type_node


class Ident(Node):
    def __init__(self, name):
        self.name = name


class IntLit(Node):
    def __init__(self, value, kind):
        self.value = value
        self.kind = kind


class FloatLit(Node):
    def __init__(self, value):
        self.value = value


class StringLit(Node):
    def __init__(self, value, prefix):
        self.value = value
        self.prefix = prefix


class CharLit(Node):
    def __init__(self, value):
        self.value = value


class BoolLit(Node):
    def __init__(self, value):
        self.value = value


class NullLit(Node):
    pass


class PointerType(Node):
    def __init__(self, base):
        self.base = base


class SliceType(Node):
    def __init__(self, base):
        self.base = base


class ConstType(Node):
    def __init__(self, base):
        self.base = base


class ArrayType(Node):
    def __init__(self, base, size):
        self.base = base
        self.size = size


class TupleType(Node):
    def __init__(self, types):
        self.types = types


class TypeIdent(Node):
    def __init__(self, name):
        self.name = name


class TernaryExpr(Node):
    def __init__(self, cond, then_expr, else_expr):
        self.cond = cond
        self.then_expr = then_expr
        self.else_expr = else_expr


class Parser:
    def __init__(self, tokens, filename):
        self.tokens = tokens
        self.pos = 0
        self.filename = filename

    def peek(self):
        return self.tokens[self.pos]

    def advance(self):
        t = self.tokens[self.pos]
        self.pos += 1
        return t

    def expect(self, kind):
        t = self.peek()
        if t.kind != kind:
            raise SyntaxError(f"{self.filename}:{t.line}:{t.col}: expected {kind}, got {t.kind} ({t.value!r})")
        return self.advance()

    def match(self, kind):
        if self.peek().kind == kind:
            return self.advance()
        return None

    def is_type_start(self):
        k = self.peek().kind
        return k in (
            TokenKind.Void, TokenKind.Bool, TokenKind.CharType,
            TokenKind.U8, TokenKind.I8, TokenKind.U16, TokenKind.I16,
            TokenKind.U32, TokenKind.I32, TokenKind.U64, TokenKind.I64,
            TokenKind.U128, TokenKind.I128, TokenKind.F32, TokenKind.F64,
            TokenKind.Usize, TokenKind.Isize, TokenKind.Rawptr, TokenKind.Str,
        ) or k == TokenKind.Ident

    def parse_type(self):
        t = self.peek()
        if t.kind == TokenKind.Const:
            self.advance()
            base = self.parse_type()
            return ConstType(base)
        if t.kind == TokenKind.Star:
            self.advance()
            base = self.parse_type()
            return PointerType(base)
        if t.kind == TokenKind.Struct:
            self.advance()
            self.expect(TokenKind.LParen)
            types = []
            types.append(self.parse_type())
            while self.match(TokenKind.Comma):
                types.append(self.parse_type())
            self.expect(TokenKind.Rparen)
            return TupleType(types)
        if t.kind == TokenKind.Ident:
            self.advance()
            base = TypeIdent(t.value)
            if self.match(TokenKind.LBracket):
                size = self.parse_expr()
                self.expect(TokenKind.RBracket)
                return ArrayType(base, size)
            if self.peek().kind == TokenKind.Star:
                self.advance()
                return PointerType(base)
            return base
        if t.kind in (TokenKind.Void, TokenKind.Bool, TokenKind.CharType,
                       TokenKind.U8, TokenKind.I8, TokenKind.U16, TokenKind.I16,
                       TokenKind.U32, TokenKind.I32, TokenKind.U64, TokenKind.I64,
                       TokenKind.U128, TokenKind.I128, TokenKind.F32, TokenKind.F64,
                       TokenKind.Usize, TokenKind.Isize, TokenKind.Rawptr, TokenKind.Str):
            self.advance()
            base = TypeIdent(t.value)
            if self.peek().kind == TokenKind.Star:
                self.advance()
                return PointerType(base)
            if self.peek().kind == TokenKind.LBracket:
                size = self.parse_expr()
                self.expect(TokenKind.RBracket)
                return ArrayType(base, size)
            return base
        raise SyntaxError(f"{self.filename}:{t.line}:{t.col}: unexpected token in type: {t.kind} ({t.value!r})")

    def parse_expr(self):
        return self.parse_ternary()

    def parse_assign(self):
        left = self.parse_or()
        if self.peek().kind in (TokenKind.Equal, TokenKind.PlusEqual, TokenKind.MinusEqual,
                                 TokenKind.StarEqual, TokenKind.SlashEqual):
            op = self.advance()
            right = self.parse_or()
            return Assign(left, right)
        return left

    def parse_ternary(self):
        cond = self.parse_or()
        if self.peek().kind == TokenKind.Question:
            self.advance()
            then_expr = self.parse_expr()
            self.expect(TokenKind.Colon)
            else_expr = self.parse_assign()
            return TernaryExpr(cond, then_expr, else_expr)
        return cond

    def parse_or(self):
        left = self.parse_and()
        while self.peek().kind == TokenKind.Or:
            self.advance()
            right = self.parse_and()
            left = BinaryExpr("||", left, right)
        return left

    def parse_and(self):
        left = self.parse_comparison()
        while self.peek().kind == TokenKind.And:
            self.advance()
            right = self.parse_comparison()
            left = BinaryExpr("&&", left, right)
        return left

    def parse_comparison(self):
        left = self.parse_bitwise_or()
        while self.peek().kind in (TokenKind.EqualEqual, TokenKind.NotEqual,
                                    TokenKind.Less, TokenKind.LessEqual,
                                    TokenKind.Greater, TokenKind.GreaterEqual):
            op = self.advance()
            right = self.parse_bitwise_or()
            left = BinaryExpr(op.value, left, right)
        return left

    def parse_bitwise_or(self):
        left = self.parse_bitwise_xor()
        while self.peek().kind == TokenKind.Pipe and self.peek2().kind != TokenKind.Pipe:
            self.advance()
            right = self.parse_bitwise_xor()
            left = BinaryExpr("|", left, right)
        return left

    def peek2(self):
        if self.pos + 1 < len(self.tokens):
            return self.tokens[self.pos + 1]
        return self.tokens[-1]

    def parse_bitwise_xor(self):
        left = self.parse_bitwise_and()
        while self.peek().kind == TokenKind.Caret:
            self.advance()
            right = self.parse_bitwise_and()
            left = BinaryExpr("^", left, right)
        return left

    def parse_bitwise_and(self):
        left = self.parse_shift()
        while self.peek().kind == TokenKind.Ampersand:
            self.advance()
            right = self.parse_shift()
            left = BinaryExpr("&", left, right)
        return left

    def parse_shift(self):
        left = self.parse_add()
        while self.peek().kind in (TokenKind.Less, TokenKind.Greater):
            if self.peek().kind == TokenKind.Less and self.peek2().kind == TokenKind.Less:
                self.advance()
                self.advance()
                right = self.parse_add()
                left = BinaryExpr("<<", left, right)
            elif self.peek().kind == TokenKind.Greater and self.peek2().kind == TokenKind.Greater:
                self.advance()
                self.advance()
                right = self.parse_add()
                left = BinaryExpr(">>", left, right)
            else:
                break
        return left

    def parse_add(self):
        left = self.parse_mul()
        while self.peek().kind in (TokenKind.Plus, TokenKind.Minus):
            op = self.advance()
            right = self.parse_mul()
            left = BinaryExpr(op.value, left, right)
        return left

    def parse_mul(self):
        left = self.parse_unary()
        while self.peek().kind in (TokenKind.Star, TokenKind.Slash):
            op = self.advance()
            right = self.parse_unary()
            left = BinaryExpr(op.value, left, right)
        return left

    def parse_unary(self):
        t = self.peek()
        if t.kind == TokenKind.Minus:
            self.advance()
            return UnaryExpr("-", self.parse_unary())
        if t.kind == TokenKind.Not:
            self.advance()
            return UnaryExpr("!", self.parse_unary())
        if t.kind == TokenKind.Neg:
            self.advance()
            return UnaryExpr("~", self.parse_unary())
        if t.kind == TokenKind.Star:
            self.advance()
            return UnaryExpr("*", self.parse_unary())
        if t.kind == TokenKind.Ampersand:
            self.advance()
            return UnaryExpr("&", self.parse_unary())
        if t.kind == TokenKind.PlusPlus:
            self.advance()
            return UnaryExpr("++pre", self.parse_unary())
        if t.kind == TokenKind.MinusMinus:
            self.advance()
            return UnaryExpr("--pre", self.parse_unary())
        if t.kind == TokenKind.Sizeof or t.kind == TokenKind.BuiltinSizeof:
            self.advance()
            if self.match(TokenKind.LParen):
                tp = self.parse_type()
                self.expect(TokenKind.Rparen)
                return SizeofExpr(tp)
        if t.kind == TokenKind.Ident and t.value == "sizeof":
            self.advance()
            if self.match(TokenKind.LParen):
                tp = self.parse_type()
                self.expect(TokenKind.Rparen)
                return SizeofExpr(tp)
        return self.parse_postfix()

    def parse_postfix(self):
        left = self.parse_primary()
        while True:
            if self.peek().kind == TokenKind.LParen:
                self.advance()
                args = []
                if self.peek().kind != TokenKind.Rparen:
                    args.append(self.parse_expr())
                    while self.match(TokenKind.Comma):
                        args.append(self.parse_expr())
                self.expect(TokenKind.Rparen)
                left = CallExpr(left, args)
            elif self.peek().kind == TokenKind.Dot:
                self.advance()
                field = self.expect(TokenKind.Ident)
                left = DotExpr(left, Ident(field.value))
            elif self.peek().kind == TokenKind.StarDot:
                self.advance()
                field = self.expect(TokenKind.Ident)
                left = StarDotExpr(left, Ident(field.value))
            elif self.peek().kind == TokenKind.ColonColon:
                self.advance()
                right_name = self.expect(TokenKind.Ident)
                left = ColonColonExpr(left, Ident(right_name.value))
            elif self.peek().kind == TokenKind.LBracket:
                self.advance()
                idx = self.parse_expr()
                self.expect(TokenKind.RBracket)
                left = IndexExpr(left, idx)
            elif self.peek().kind == TokenKind.PlusPlus:
                self.advance()
                left = UnaryExpr("++post", left)
            elif self.peek().kind == TokenKind.MinusMinus:
                self.advance()
                left = UnaryExpr("--post", left)
            else:
                break
        return left

    def parse_primary(self):
        t = self.peek()
        if t.kind == TokenKind.Dec or t.kind == TokenKind.Hex or t.kind == TokenKind.Bin or t.kind == TokenKind.Oct:
            self.advance()
            return IntLit(t.value, t.kind)
        if t.kind == TokenKind.Float:
            self.advance()
            return FloatLit(t.value)
        if t.kind == TokenKind.String:
            self.advance()
            prefix = ""
            return StringLit(t.value, prefix)
        if t.kind == TokenKind.Char:
            self.advance()
            return CharLit(t.value)
        if t.kind == TokenKind.TrueLit:
            self.advance()
            return BoolLit(True)
        if t.kind == TokenKind.FalseLit:
            self.advance()
            return BoolLit(False)
        if t.kind == TokenKind.NullLit:
            self.advance()
            return NullLit()
        if t.kind == TokenKind.Ident:
            self.advance()
            return Ident(t.value)
        if t.kind == TokenKind.LParen:
            self.advance()
            expr = self.parse_expr()
            self.expect(TokenKind.Rparen)
            return expr
        if t.kind == TokenKind.Self:
            self.advance()
            return Ident("self")
        if t.kind == TokenKind.LBrace:
            return self.parse_block_expr()
        raise SyntaxError(f"{self.filename}:{t.line}:{t.col}: unexpected token: {t.kind} ({t.value!r})")

    def parse_block_expr(self):
        self.expect(TokenKind.LBrace)
        stmts = []
        while self.peek().kind != TokenKind.RBrace:
            stmts.append(self.parse_stmt())
        self.expect(TokenKind.RBrace)
        return Block(stmts)

    def parse_stmt(self):
        t = self.peek()

        if t.kind == TokenKind.Return:
            self.advance()
            expr = None
            if self.peek().kind not in (TokenKind.Semicolon, TokenKind.RBrace):
                expr = self.parse_expr()
            self.match(TokenKind.Semicolon)
            return ReturnStmt(expr)

        if t.kind == TokenKind.Break:
            self.advance()
            self.match(TokenKind.Semicolon)
            return BreakStmt()

        if t.kind == TokenKind.Continue:
            self.advance()
            self.match(TokenKind.Semicolon)
            return ContinueStmt()

        if t.kind == TokenKind.Var:
            self.advance()
            name = self.expect(TokenKind.Ident).value
            init_expr = None
            if self.match(TokenKind.Equal):
                init_expr = self.parse_expr()
            self.match(TokenKind.Semicolon)
            return VarDecl(None, name, init_expr)

        if t.kind == TokenKind.If:
            return self.parse_if()

        if t.kind == TokenKind.While:
            self.advance()
            cond = self.parse_expr()
            body = self.parse_block()
            return WhileStmt(cond, body)

        if t.kind == TokenKind.For:
            self.advance()
            init = None
            if self.peek().kind != TokenKind.Semicolon:
                init = self.parse_stmt()
            else:
                self.advance()
            cond = None
            if self.peek().kind != TokenKind.Semicolon:
                cond = self.parse_expr()
            self.expect(TokenKind.Semicolon)
            post = None
            if self.peek().kind != TokenKind.RParen:
                post = self.parse_expr()
            self.expect(TokenKind.Rparen)
            body = self.parse_block()
            return ForStmt(init, cond, post, body)

        if t.kind == TokenKind.Switch:
            return self.parse_switch()

        if t.kind == TokenKind.Defer:
            self.advance()
            stmt = self.parse_stmt()
            return DeferStmt(stmt)

        if t.kind == TokenKind.LBrace:
            return self.parse_block()

        if t.kind in (TokenKind.Struct, TokenKind.Enum, TokenKind.Extern, TokenKind.Static):
            return self.parse_block()

        if self.is_type_start():
            peek2 = self.peek2()
            if peek2.kind == TokenKind.Ident:
                tp = self.parse_type()
                name = self.expect(TokenKind.Ident).value
                init_expr = None
                if self.match(TokenKind.Equal):
                    init_expr = self.parse_expr()
                self.match(TokenKind.Semicolon)
                return VarDecl(tp, name, init_expr)

        expr = self.parse_expr()
        self.match(TokenKind.Semicolon)
        return ExprStmt(expr)

    def parse_if(self):
        self.expect(TokenKind.If)
        cond = self.parse_expr()
        then_body = self.parse_block()
        else_body = None
        if self.match(TokenKind.Else):
            if self.peek().kind == TokenKind.If:
                else_body = Block([self.parse_if()])
            else:
                else_body = self.parse_block()
        return IfExpr(cond, then_body, else_body)

    def parse_block(self):
        self.expect(TokenKind.LBrace)
        stmts = []
        while self.peek().kind != TokenKind.RBrace:
            stmts.append(self.parse_stmt())
        self.expect(TokenKind.RBrace)
        return Block(stmts)

    def parse_switch(self):
        self.expect(TokenKind.Switch)
        expr = self.parse_expr()
        self.expect(TokenKind.LBrace)
        cases = []
        default = None
        while self.peek().kind != TokenKind.RBrace:
            t = self.peek()
            if t.kind == TokenKind.Default:
                self.advance()
                self.expect(TokenKind.Colon)
                stmts = []
                while self.peek().kind not in (TokenKind.RBrace, TokenKind.Default):
                    stmts.append(self.parse_stmt())
                default = Block(stmts)
            else:
                val = self.parse_expr()
                self.expect(TokenKind.Colon)
                stmts = []
                while self.peek().kind not in (TokenKind.RBrace, TokenKind.Default):
                    stmts.append(self.parse_stmt())
                cases.append((val, Block(stmts)))
        self.expect(TokenKind.RBrace)
        return SwitchStmt(expr, cases, default)

    def parse_struct_fields(self):
        self.expect(TokenKind.LBrace)
        fields = []
        while self.peek().kind != TokenKind.RBrace:
            if self.peek().kind in (TokenKind.Pub, TokenKind.Extern):
                self.advance()
            if self.peek().kind == TokenKind.Static:
                self.advance()
            if self.peek().kind == TokenKind.Extend:
                break
            tp = self.parse_type()
            name_tok = self.advance()
            name = name_tok.value
            if self.peek().kind == TokenKind.LParen:
                depth = 1
                self.advance()
                while depth > 0 and not self.is_at_end():
                    if self.peek().kind == TokenKind.LParen:
                        depth += 1
                    elif self.peek().kind == TokenKind.Rparen:
                        depth -= 1
                    self.advance()
                if self.peek().kind == TokenKind.LBrace:
                    depth = 1
                    self.advance()
                    while depth > 0 and not self.is_at_end():
                        if self.peek().kind == TokenKind.LBrace:
                            depth += 1
                        elif self.peek().kind == TokenKind.RBrace:
                            depth -= 1
                        self.advance()
                continue
            fields.append(FieldDecl(tp, name))
            self.match(TokenKind.Semicolon)
        self.expect(TokenKind.RBrace)
        return fields

    def is_at_end(self):
        return self.peek().kind == TokenKind.Eof

    def parse_enum_variants(self):
        self.expect(TokenKind.LBrace)
        variants = []
        while self.peek().kind != TokenKind.RBrace:
            name = self.expect(TokenKind.Ident).value
            variants.append(name)
            self.match(TokenKind.Comma)
        self.expect(TokenKind.RBrace)
        return variants

    def parse_func(self, is_pub, is_extern, is_static, self_type=None):
        ret_type = None
        name_token = self.peek()
        if self.is_type_start():
            if self.peek().kind == TokenKind.Struct and self.peek2().kind == TokenKind.LParen:
                ret_type = self.parse_type()
                name_token = self.advance()
            elif self.peek2().kind == TokenKind.Ident:
                ret_type = self.parse_type()
                name_token = self.advance()
            elif name_token.kind == TokenKind.Ident:
                name_token = self.advance()
                ret_type = None
            else:
                ret_type = self.parse_type()
                name_token = self.advance()
        else:
            name_token = self.advance()

        name = name_token.value
        self.expect(TokenKind.LParen)
        params = []
        if self.peek().kind != TokenKind.Rparen:
            if self.peek().kind == TokenKind.Self:
                self.advance()
                params.append(ParamDecl(TypeIdent("self"), "self"))
                while self.match(TokenKind.Comma):
                    tp = self.parse_type()
                    pname = self.expect(TokenKind.Ident).value
                    params.append(ParamDecl(tp, pname))
            else:
                tp = self.parse_type()
                pname = self.expect(TokenKind.Ident).value
                params.append(ParamDecl(tp, pname))
                while self.match(TokenKind.Comma):
                    tp = self.parse_type()
                    pname = self.expect(TokenKind.Ident).value
                    params.append(ParamDecl(tp, pname))
        self.expect(TokenKind.Rparen)

        if is_extern:
            self.match(TokenKind.Semicolon)
            return FuncDecl(name, params, ret_type, None, is_pub, True, is_static, self_type is not None, self_type)

        body = self.parse_block()
        is_method = len(params) > 0 and params[0].name == "self"
        return FuncDecl(name, params, ret_type, body, is_pub, False, is_static, is_method, self_type)

    def parse_top_level(self):
        decls = []
        while self.peek().kind != TokenKind.Eof:
            t = self.peek()

            if t.kind == TokenKind.Import:
                self.advance()
                is_lib = False
                lib_path = None
                if self.match(TokenKind.LParen):
                    lib_token = self.advance()
                    lib_path = lib_token.value
                    self.expect(TokenKind.Rparen)
                    is_lib = True

                if is_lib:
                    while self.peek().kind not in (TokenKind.Semicolon, TokenKind.Eof):
                        self.advance()
                    self.match(TokenKind.Semicolon)
                    decls.append(ImportDecl("", [], True, lib_path))
                    continue

                path_token = self.expect(TokenKind.String)
                path = path_token.value.strip('"')

                symbols = []
                if self.match(TokenKind.LBrace):
                    if self.peek().kind != TokenKind.RBrace:
                        sym = self.expect(TokenKind.Ident).value
                        as_name = None
                        if self.match(TokenKind.As):
                            as_name = self.expect(TokenKind.Ident).value
                        symbols.append((sym, as_name))
                        while self.match(TokenKind.Comma):
                            if self.peek().kind == TokenKind.RBrace:
                                break
                            sym = self.expect(TokenKind.Ident).value
                            as_name = None
                            if self.match(TokenKind.As):
                                as_name = self.expect(TokenKind.Ident).value
                            symbols.append((sym, as_name))
                    self.expect(TokenKind.RBrace)
                self.match(TokenKind.Semicolon)
                decls.append(ImportDecl(path, symbols, is_lib, lib_path))
                continue

            if t.kind == TokenKind.Pub:
                self.advance()
                if self.peek().kind == TokenKind.Mod:
                    self.advance()
                    alias = self.expect(TokenKind.Ident).value
                    self.expect(TokenKind.Equal)
                    is_lib = False
                    lib_path = None
                    if self.match(TokenKind.LParen):
                        lib_token = self.expect(TokenKind.Ident)
                        lib_path = lib_token.value
                        self.expect(TokenKind.Rparen)
                        is_lib = True
                    path_token = self.expect(TokenKind.String)
                    path = path_token.value.strip('"')
                    self.match(TokenKind.Semicolon)
                    decls.append(ModReexport(alias, path, is_lib, lib_path))
                    continue
                if self.peek().kind == TokenKind.Enum:
                    self.advance()
                    name = self.expect(TokenKind.Ident).value
                    variants = self.parse_enum_variants()
                    decls.append(EnumDecl(name, variants, True))
                    continue
                if self.peek().kind == TokenKind.Struct:
                    if self.tokens[self.pos + 1].kind == TokenKind.LParen:
                        func = self.parse_func(True, False, False)
                        decls.append(func)
                        continue
                    self.advance()
                    name = self.expect(TokenKind.Ident).value
                    fields = self.parse_struct_fields()
                    decls.append(StructDecl(name, fields, True))
                    continue
                if self.peek().kind in (TokenKind.Extern, TokenKind.Static):
                    is_extern = self.peek().kind == TokenKind.Extern
                    is_static = self.peek().kind == TokenKind.Static
                    self.advance()
                    func = self.parse_func(True, is_extern, is_static)
                    decls.append(func)
                    continue
                func = self.parse_func(True, False, False)
                decls.append(func)
                continue

            if t.kind == TokenKind.Extend:
                self.advance()
                tp = self.parse_type()
                self.expect(TokenKind.LBrace)
                methods = []
                while self.peek().kind != TokenKind.RBrace:
                    is_pub = self.match(TokenKind.Pub) is not None
                    is_extern = self.match(TokenKind.Extern) is not None
                    is_static = self.match(TokenKind.Static) is not None
                    methods.append(self.parse_func(is_pub, is_extern, is_static, tp))
                self.expect(TokenKind.RBrace)
                decls.append(ExtendBlock(tp, methods))
                continue

            if t.kind == TokenKind.Mod:
                self.advance()
                alias = self.expect(TokenKind.Ident).value
                self.expect(TokenKind.Equal)
                is_lib = False
                lib_path = None
                if self.match(TokenKind.LParen):
                    lib_token = self.expect(TokenKind.Ident)
                    lib_path = lib_token.value
                    self.expect(TokenKind.Rparen)
                    is_lib = True
                path_token = self.expect(TokenKind.String)
                path = path_token.value.strip('"')
                self.match(TokenKind.Semicolon)
                decls.append(ModReexport(alias, path, is_lib, lib_path))
                continue

            if t.kind == TokenKind.Enum:
                self.advance()
                name = self.expect(TokenKind.Ident).value
                variants = self.parse_enum_variants()
                decls.append(EnumDecl(name, variants, False))
                continue

            if t.kind == TokenKind.Struct:
                self.advance()
                name = self.expect(TokenKind.Ident).value
                fields = self.parse_struct_fields()
                decls.append(StructDecl(name, fields, False))
                continue

            if t.kind in (TokenKind.Extern, TokenKind.Static):
                is_extern = t.kind == TokenKind.Extern
                is_static = t.kind == TokenKind.Static
                self.advance()
                func = self.parse_func(False, is_extern, is_static)
                decls.append(func)
                continue

            if t.kind == TokenKind.Const:
                self.advance()
                tp = self.parse_type()
                name = self.expect(TokenKind.Ident).value
                self.expect(TokenKind.Equal)
                val = self.parse_expr()
                self.match(TokenKind.Semicolon)
                decls.append(VarDecl(tp, name, val))
                continue

            if t.kind == TokenKind.Pub:
                self.advance()
                func = self.parse_func(True, False, False)
                decls.append(func)
                continue

            func = self.parse_func(False, False, False)
            decls.append(func)

        return SourceFile(decls)

    def parse(self):
        return self.parse_top_level()
