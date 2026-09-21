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
    def __init__(self, name, fields, is_pub, methods=None):
        self.name = name
        self.fields = fields
        self.is_pub = is_pub
        self.methods = methods or []


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
    def __init__(self, target, value, op="="):
        self.target = target
        self.value = value
        self.op = op


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
    def __init__(self, expr, cases, else_body):
        self.expr = expr
        self.cases = cases
        self.else_body = else_body


class DestructPattern(Node):
    def __init__(self, name, fields):
        self.name = name
        self.fields = fields


class OrPattern(Node):
    def __init__(self, patterns):
        self.patterns = patterns


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


class TupleExpr(Node):
    def __init__(self, exprs):
        self.exprs = exprs


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
    def __init__(self, name, generic_args=None):
        self.name = name
        self.generic_args = generic_args or []


class TernaryExpr(Node):
    def __init__(self, cond, then_expr, else_expr):
        self.cond = cond
        self.then_expr = then_expr
        self.else_expr = else_expr


class VariantDecl(Node):
    def __init__(self, name, variants, is_pub=False, generic_params=None):
        self.name = name
        self.variants = variants
        self.is_pub = is_pub
        self.generic_params = generic_params or []
        self.methods = []


class VariantVariant(Node):
    def __init__(self, name, fields):
        self.name = name
        self.fields = fields


class VariantField(Node):
    def __init__(self, type_node, name):
        self.type_node = type_node
        self.name = name


class UnionDecl(Node):
    def __init__(self, name, fields, is_pub=False):
        self.name = name
        self.fields = fields
        self.is_pub = is_pub


class TraitDecl(Node):
    def __init__(self, name, methods, is_pub=False):
        self.name = name
        self.methods = methods
        self.is_pub = is_pub


class ExtendTraitBlock(Node):
    def __init__(self, type_node, trait_name, methods):
        self.type_node = type_node
        self.trait_name = trait_name
        self.methods = methods


class DistinctDecl(Node):
    def __init__(self, name, base_type, is_pub=False):
        self.name = name
        self.base_type = base_type
        self.is_pub = is_pub


class TypedefDecl(Node):
    def __init__(self, name, target_type, is_pub=False):
        self.name = name
        self.target_type = target_type
        self.is_pub = is_pub


class FlagDecl(Node):
    def __init__(self, flag_name, branches):
        self.flag_name = flag_name
        self.branches = branches


class FlagBranch(Node):
    def __init__(self, label, stmts):
        self.label = label
        self.stmts = stmts


class ComptimeBlock(Node):
    def __init__(self, stmts):
        self.stmts = stmts


class AsmStmt(Node):
    def __init__(self, volatile, template, outputs, inputs, clobbers):
        self.volatile = volatile
        self.template = template
        self.outputs = outputs
        self.inputs = inputs
        self.clobbers = clobbers


class LoopStmt(Node):
    def __init__(self, body):
        self.body = body


class ForInStmt(Node):
    def __init__(self, binding, iter_expr, body):
        self.binding = binding
        self.iter_expr = iter_expr
        self.body = body


class BuiltinCall(Node):
    def __init__(self, name, args):
        self.name = name
        self.args = args


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
            TokenKind.Struct,
        ) or k == TokenKind.Ident

    def parse_generic_args(self):
        self.expect(TokenKind.Less)
        args = []
        if self.peek().kind != TokenKind.Greater:
            args.append(self.parse_type())
            while self.match(TokenKind.Comma):
                if self.peek().kind == TokenKind.Greater:
                    break
                args.append(self.parse_type())
        self.expect(TokenKind.Greater)
        return args

    def parse_generic_params(self):
        if self.peek().kind != TokenKind.Less:
            return []
        self.expect(TokenKind.Less)
        params = []
        while self.peek().kind != TokenKind.Greater:
            name = self.expect(TokenKind.Ident).value
            bounds = []
            if self.peek().kind == TokenKind.Colon:
                self.advance()
                bounds.append(self.parse_type())
                while self.match(TokenKind.Comma):
                    bounds.append(self.parse_type())
            params.append((name, bounds))
            self.match(TokenKind.Comma)
        self.expect(TokenKind.Greater)
        return params

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
            if self.peek().kind == TokenKind.Less:
                generic_args = self.parse_generic_args()
                base.generic_args = generic_args
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
        return self.parse_assign()

    def parse_assign(self):
        left = self.parse_ternary()
        if self.peek().kind in (TokenKind.Equal, TokenKind.PlusEqual, TokenKind.MinusEqual,
                                 TokenKind.StarEqual, TokenKind.SlashEqual,
                                 TokenKind.PipeEqual, TokenKind.CaretEqual,
                                 TokenKind.AmpEqual, TokenKind.NegEqual):
            op = self.advance()
            right = self.parse_or()
            op_map = {
                TokenKind.Equal: "=", TokenKind.PlusEqual: "+=",
                TokenKind.MinusEqual: "-=", TokenKind.StarEqual: "*=",
                TokenKind.SlashEqual: "/=", TokenKind.PipeEqual: "|=",
                TokenKind.CaretEqual: "^=", TokenKind.AmpEqual: "&=",
                TokenKind.NegEqual: "~=",
            }
            return Assign(left, right, op_map.get(op.kind, "="))
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
        if t.kind == TokenKind.BuiltinSizeof:
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
                if self.peek().kind == TokenKind.Dec:
                    field_tok = self.advance()
                    left = DotExpr(left, IntLit(field_tok.value, "dec"))
                elif self.peek().kind == TokenKind.Ident:
                    field = self.advance()
                    left = DotExpr(left, Ident(field.value))
                else:
                    raise SyntaxError(f"expected field name or index after '.', got {self.peek().kind}")
            elif self.peek().kind == TokenKind.StarDot:
                self.advance()
                if self.peek().kind == TokenKind.Dec:
                    field_tok = self.advance()
                    left = StarDotExpr(left, IntLit(field_tok.value, "dec"))
                else:
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
            if self.peek().kind in (TokenKind.Void, TokenKind.Bool, TokenKind.CharType,
                                    TokenKind.U8, TokenKind.I8, TokenKind.U16, TokenKind.I16,
                                    TokenKind.U32, TokenKind.I32, TokenKind.U64, TokenKind.I64,
                                    TokenKind.U128, TokenKind.I128, TokenKind.F32, TokenKind.F64,
                                    TokenKind.Usize, TokenKind.Isize, TokenKind.Rawptr, TokenKind.Str,
                                    TokenKind.Struct):
                tp = self.parse_type()
                self.expect(TokenKind.Rparen)
                inner = self.parse_unary()
                return CastExpr(tp, inner)
            expr = self.parse_expr()
            if self.peek().kind == TokenKind.Comma:
                exprs = [expr]
                while self.match(TokenKind.Comma):
                    exprs.append(self.parse_expr())
                self.expect(TokenKind.Rparen)
                return TupleExpr(exprs)
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
            self.match(TokenKind.LParen)
            cond = self.parse_expr()
            self.expect(TokenKind.Rparen)
            if self.peek().kind == TokenKind.LBrace:
                body = self.parse_block()
            else:
                body = Block([self.parse_stmt()])
            return WhileStmt(cond, body)

        if t.kind == TokenKind.For:
            self.advance()
            self.match(TokenKind.LParen)
            saved_pos = self.pos
            has_var = self.match(TokenKind.Var)
            if has_var or (self.peek().kind == TokenKind.Ident and self.peek2().kind in (TokenKind.Colon, TokenKind.Comma)):
                if has_var:
                    binding_name = self.expect(TokenKind.Ident).value
                else:
                    binding_name = self.expect(TokenKind.Ident).value
                if self.peek().kind == TokenKind.Colon:
                    self.advance()
                    iter_expr = self.parse_expr()
                    self.expect(TokenKind.Rparen)
                    if self.peek().kind == TokenKind.LBrace:
                        body = self.parse_block()
                    else:
                        body = Block([self.parse_stmt()])
                    return ForInStmt(binding_name, iter_expr, body)
                else:
                    self.pos = saved_pos
                    if has_var:
                        self.pos -= 1
            else:
                self.pos = saved_pos
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
            if self.peek().kind not in (TokenKind.Rparen, TokenKind.RBrace):
                post = self.parse_expr()
            self.expect(TokenKind.Rparen)
            if self.peek().kind == TokenKind.LBrace:
                body = self.parse_block()
            else:
                body = Block([self.parse_stmt()])
            return ForStmt(init, cond, post, body)

        if t.kind == TokenKind.Switch:
            return self.parse_switch()

        if t.kind == TokenKind.Loop:
            self.advance()
            if self.peek().kind == TokenKind.LBrace:
                body = self.parse_block()
            else:
                body = Block([self.parse_stmt()])
            return LoopStmt(body)

        if t.kind == TokenKind.Comptime:
            self.advance()
            if self.peek().kind == TokenKind.LBrace:
                body = self.parse_block()
            else:
                body = Block([self.parse_stmt()])
            return ComptimeBlock(body.stmts)

        if t.kind == TokenKind.Asm:
            return self.parse_asm()

        if t.kind == TokenKind.At:
            return self.parse_builtin_call()

        if t.kind == TokenKind.Struct or t.kind in (
                TokenKind.Void, TokenKind.Bool, TokenKind.CharType,
                TokenKind.U8, TokenKind.I8, TokenKind.U16, TokenKind.I16,
                TokenKind.U32, TokenKind.I32, TokenKind.U64, TokenKind.I64,
                TokenKind.U128, TokenKind.I128, TokenKind.F32, TokenKind.F64,
                TokenKind.Usize, TokenKind.Isize, TokenKind.Rawptr, TokenKind.Str):
            tp = self.parse_type()
            name = self.expect(TokenKind.Ident).value
            init_expr = None
            if self.match(TokenKind.Equal):
                init_expr = self.parse_expr()
            self.match(TokenKind.Semicolon)
            return VarDecl(tp, name, init_expr)

        if t.kind == TokenKind.Ident:
            peek2 = self.peek2()
            if peek2.kind in (TokenKind.Ident, TokenKind.Star):
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
        if self.peek().kind == TokenKind.LBrace:
            then_body = self.parse_block()
        else:
            then_body = Block([self.parse_stmt()])
        else_body = None
        if self.match(TokenKind.Else):
            if self.peek().kind == TokenKind.If:
                else_body = Block([self.parse_if()])
            elif self.peek().kind == TokenKind.LBrace:
                else_body = self.parse_block()
            else:
                else_body = Block([self.parse_stmt()])
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
        self.match(TokenKind.LParen)
        expr = self.parse_expr()
        self.expect(TokenKind.Rparen)
        self.expect(TokenKind.LBrace)
        cases = []
        else_body = None
        while self.peek().kind != TokenKind.RBrace:
            if self.peek().kind == TokenKind.Else:
                self.advance()
                self.expect(TokenKind.FatArrow)
                if self.peek().kind == TokenKind.LBrace:
                    else_body = self.parse_block()
                else:
                    else_body = Block([self.parse_stmt()])
                self.match(TokenKind.Comma)
                continue
            pattern = self.parse_switch_pattern()
            self.expect(TokenKind.FatArrow)
            if self.peek().kind == TokenKind.LBrace:
                body = self.parse_block()
            else:
                body = Block([self.parse_stmt()])
            self.match(TokenKind.Comma)
            cases.append((pattern, body))
        self.expect(TokenKind.RBrace)
        return SwitchStmt(expr, cases, else_body)

    def parse_switch_pattern(self):
        parts = []
        part = self.parse_postfix()
        if self.peek().kind == TokenKind.LBrace and isinstance(part, Ident):
            self.advance()
            fields = []
            while self.peek().kind != TokenKind.RBrace:
                fname = self.expect(TokenKind.Ident).value
                fields.append(fname)
                self.match(TokenKind.Comma)
            self.expect(TokenKind.RBrace)
            return DestructPattern(part.name, fields)
        parts.append(part)
        while self.match(TokenKind.Pipe):
            parts.append(self.parse_postfix())
        if len(parts) == 1:
            return parts[0]
        return OrPattern(parts)

    def parse_asm(self):
        self.expect(TokenKind.Asm)
        volatile = self.match(TokenKind.Volatile) is not None
        self.expect(TokenKind.LBrace)
        template = []
        while self.peek().kind != TokenKind.RBrace:
            if self.peek().kind == TokenKind.String:
                template.append(self.advance().value)
            else:
                self.advance()
        self.expect(TokenKind.RBrace)
        self.match(TokenKind.Semicolon)
        return AsmStmt(volatile, template, [], [], [])

    def parse_builtin_call(self):
        self.expect(TokenKind.At)
        name = self.expect(TokenKind.Ident).value
        args = []
        if self.match(TokenKind.LParen):
            if self.peek().kind != TokenKind.Rparen:
                args.append(self.parse_expr())
                while self.match(TokenKind.Comma):
                    args.append(self.parse_expr())
            self.expect(TokenKind.Rparen)
        return BuiltinCall(name, args)

    def parse_variant_decl(self, is_pub=False):
        self.expect(TokenKind.Variant)
        name = self.expect(TokenKind.Ident).value
        generic_params = []
        if self.match(TokenKind.Less):
            while self.peek().kind != TokenKind.Greater:
                gp = self.expect(TokenKind.Ident).value
                generic_params.append(gp)
                self.match(TokenKind.Comma)
            self.expect(TokenKind.Greater)
        self.expect(TokenKind.LBrace)
        variants = []
        while self.peek().kind != TokenKind.RBrace:
            vtok = self.peek()
            if vtok.kind == TokenKind.Ident:
                self.advance()
                vname = vtok.value
            else:
                vname = vtok.value if vtok.value else vtok.kind
                self.advance()
            vfields = []
            if self.peek().kind == TokenKind.LBrace:
                self.advance()
                while self.peek().kind != TokenKind.RBrace:
                    ftp = self.parse_type()
                    ftok = self.peek()
                    if ftok.kind == TokenKind.Ident:
                        self.advance()
                        fname = ftok.value
                    else:
                        fname = ftok.value if ftok.value else ftok.kind
                        self.advance()
                    vfields.append(VariantField(ftp, fname))
                    if not self.match(TokenKind.Comma):
                        self.match(TokenKind.Semicolon)
                self.expect(TokenKind.RBrace)
            variants.append(VariantVariant(vname, vfields))
            self.match(TokenKind.Comma)
        self.expect(TokenKind.RBrace)
        methods = []
        if self.peek().kind == TokenKind.LBrace:
            self.expect(TokenKind.LBrace)
            while self.peek().kind != TokenKind.RBrace:
                is_mpub = self.match(TokenKind.Pub) is not None
                is_mextern = self.match(TokenKind.Extern) is not None
                is_mstatic = self.match(TokenKind.Static) is not None
                methods.append(self.parse_func(is_mpub, is_mextern, is_mstatic))
            self.expect(TokenKind.RBrace)
        v = VariantDecl(name, variants, is_pub, generic_params)
        v.methods = methods
        return v

    def parse_struct_fields_and_methods(self):
        self.expect(TokenKind.LBrace)
        fields = []
        methods = []
        while self.peek().kind != TokenKind.RBrace:
            if self.peek().kind in (TokenKind.Pub, TokenKind.Extern):
                self.advance()
            if self.peek().kind == TokenKind.Static:
                self.advance()
            if self.peek().kind == TokenKind.Extend:
                break
            if self.peek().kind == TokenKind.RBrace:
                break

            tp = self.parse_type()
            name_tok = self.peek()
            if name_tok.kind == TokenKind.Ident:
                self.advance()
                name = name_tok.value
            elif name_tok.kind in (TokenKind.LParen, TokenKind.Rparen):
                break
            else:
                break

            if self.peek().kind == TokenKind.LParen:
                self.expect(TokenKind.LParen)
                params = []
                if self.peek().kind != TokenKind.Rparen:
                    if self.peek().kind == TokenKind.Self:
                        self.advance()
                        params.append(ParamDecl(TypeIdent("self"), "self"))
                        while self.match(TokenKind.Comma):
                            ptp = self.parse_type()
                            pname = self.expect(TokenKind.Ident).value
                            params.append(ParamDecl(ptp, pname))
                    else:
                        ptp = self.parse_type()
                        pname = self.expect(TokenKind.Ident).value
                        params.append(ParamDecl(ptp, pname))
                        while self.match(TokenKind.Comma):
                            ptp = self.parse_type()
                            pname = self.expect(TokenKind.Ident).value
                            params.append(ParamDecl(ptp, pname))
                self.expect(TokenKind.Rparen)
                body = self.parse_block()
                methods.append(FuncDecl(name, params, tp, body, False, False, False, False, None))
                continue

            fields.append(FieldDecl(tp, name))
            self.match(TokenKind.Semicolon)
        self.expect(TokenKind.RBrace)
        return fields, methods

    def parse_struct_fields(self):
        fields, _ = self.parse_struct_fields_and_methods()
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
                    if self.peek().kind == TokenKind.Ellipsis:
                        self.advance()
                        params.append(ParamDecl(TypeIdent("..."), "..."))
                        break
                    tp = self.parse_type()
                    pname = self.expect(TokenKind.Ident).value
                    params.append(ParamDecl(tp, pname))
            elif self.peek().kind == TokenKind.Ellipsis:
                self.advance()
                params.append(ParamDecl(TypeIdent("..."), "..."))
            else:
                tp = self.parse_type()
                pname = self.expect(TokenKind.Ident).value
                params.append(ParamDecl(tp, pname))
                while self.match(TokenKind.Comma):
                    if self.peek().kind == TokenKind.Ellipsis:
                        self.advance()
                        params.append(ParamDecl(TypeIdent("..."), "..."))
                        break
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

                if self.peek().kind == TokenKind.String:
                    path_token = self.advance()
                    path = path_token.value.strip('"')
                elif self.peek().kind == TokenKind.Ident:
                    path_parts = [self.advance().value]
                    while self.match(TokenKind.ColonColon):
                        path_parts.append(self.expect(TokenKind.Ident).value)
                    path = "::".join(path_parts)
                else:
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
                    self.match(TokenKind.Import)
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
                    fields, methods = self.parse_struct_fields_and_methods()
                    decls.append(StructDecl(name, fields, True, methods))
                    continue
                if self.peek().kind == TokenKind.Variant:
                    variant = self.parse_variant_decl(True)
                    decls.append(variant)
                    continue
                if self.peek().kind == TokenKind.Union:
                    self.advance()
                    name = self.expect(TokenKind.Ident).value
                    fields, methods = self.parse_struct_fields_and_methods()
                    decls.append(UnionDecl(name, fields, True))
                    for m in methods:
                        decls.append(m)
                    continue
                if self.peek().kind == TokenKind.Trait:
                    self.advance()
                    name = self.expect(TokenKind.Ident).value
                    self.expect(TokenKind.LBrace)
                    methods = []
                    while self.peek().kind != TokenKind.RBrace:
                        is_mpub = self.match(TokenKind.Pub) is not None
                        is_mextern = self.match(TokenKind.Extern) is not None
                        is_mstatic = self.match(TokenKind.Static) is not None
                        methods.append(self.parse_func(is_mpub, is_mextern, is_mstatic))
                    self.expect(TokenKind.RBrace)
                    decls.append(TraitDecl(name, methods, True))
                    continue
                if self.peek().kind == TokenKind.Distinct:
                    self.advance()
                    name = self.expect(TokenKind.Ident).value
                    self.expect(TokenKind.Equal)
                    base = self.parse_type()
                    self.match(TokenKind.Semicolon)
                    decls.append(DistinctDecl(name, base, True))
                    continue
                if self.peek().kind == TokenKind.Typedef:
                    self.advance()
                    name = self.expect(TokenKind.Ident).value
                    self.expect(TokenKind.Equal)
                    target = self.parse_type()
                    self.match(TokenKind.Semicolon)
                    decls.append(TypedefDecl(name, target, True))
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
                trait_name = None
                if self.match(TokenKind.Colon):
                    trait_name = self.expect(TokenKind.Ident).value
                self.expect(TokenKind.LBrace)
                methods = []
                while self.peek().kind != TokenKind.RBrace:
                    is_pub = self.match(TokenKind.Pub) is not None
                    is_extern = self.match(TokenKind.Extern) is not None
                    is_static = self.match(TokenKind.Static) is not None
                    methods.append(self.parse_func(is_pub, is_extern, is_static, tp))
                self.expect(TokenKind.RBrace)
                if trait_name:
                    decls.append(ExtendTraitBlock(tp, trait_name, methods))
                else:
                    decls.append(ExtendBlock(tp, methods))
                continue

            if t.kind == TokenKind.Mod:
                self.advance()
                alias = self.expect(TokenKind.Ident).value
                self.expect(TokenKind.Equal)
                self.match(TokenKind.Import)
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
                fields, methods = self.parse_struct_fields_and_methods()
                decls.append(StructDecl(name, fields, False, methods))
                continue

            if t.kind == TokenKind.Variant:
                variant = self.parse_variant_decl(False)
                decls.append(variant)
                continue

            if t.kind == TokenKind.Union:
                self.advance()
                name = self.expect(TokenKind.Ident).value
                fields, methods = self.parse_struct_fields_and_methods()
                decls.append(UnionDecl(name, fields, False))
                for m in methods:
                    decls.append(m)
                continue

            if t.kind == TokenKind.Trait:
                self.advance()
                name = self.expect(TokenKind.Ident).value
                self.expect(TokenKind.LBrace)
                methods = []
                while self.peek().kind != TokenKind.RBrace:
                    is_mpub = self.match(TokenKind.Pub) is not None
                    is_mextern = self.match(TokenKind.Extern) is not None
                    is_mstatic = self.match(TokenKind.Static) is not None
                    methods.append(self.parse_func(is_mpub, is_mextern, is_mstatic))
                self.expect(TokenKind.RBrace)
                decls.append(TraitDecl(name, methods, False))
                continue

            if t.kind == TokenKind.Distinct:
                self.advance()
                name = self.expect(TokenKind.Ident).value
                self.expect(TokenKind.Equal)
                base = self.parse_type()
                self.match(TokenKind.Semicolon)
                decls.append(DistinctDecl(name, base, False))
                continue

            if t.kind == TokenKind.Flag:
                self.advance()
                flag_name = self.expect(TokenKind.Ident).value
                self.expect(TokenKind.LBrace)
                branches = []
                while self.peek().kind != TokenKind.RBrace:
                    label = self.expect(TokenKind.Ident).value
                    self.expect(TokenKind.Colon)
                    stmts = []
                    while self.peek().kind not in (TokenKind.Ident, TokenKind.RBrace):
                        stmts.append(self.parse_stmt())
                    branches.append(FlagBranch(label, stmts))
                self.expect(TokenKind.RBrace)
                self.match(TokenKind.Semicolon)
                decls.append(FlagDecl(flag_name, branches))
                continue

            if t.kind in (TokenKind.Extern, TokenKind.Static):
                is_extern = t.kind == TokenKind.Extern
                is_static = t.kind == TokenKind.Static
                self.advance()
                if is_extern and self.peek().kind == TokenKind.LParen:
                    self.advance()
                    while self.peek().kind != TokenKind.Rparen:
                        self.advance()
                    self.expect(TokenKind.Rparen)
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
