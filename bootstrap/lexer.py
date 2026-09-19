class TokenKind:
    Eof = "Eof"
    Ident = "Ident"
    Dec = "Dec"
    Hex = "Hex"
    Bin = "Bin"
    Oct = "Oct"
    Float = "Float"
    String = "String"
    RawString = "RawString"
    Char = "Char"
    TrueLit = "True"
    NullLit = "Null"
    FalseLit = "False"
    If = "If"
    As = "As"
    Mod = "Mod"
    Pub = "Pub"
    For = "For"
    Asm = "Asm"
    Var = "Var"
    Enum = "Enum"
    Else = "Else"
    Loop = "Loop"
    Flag = "Flag"
    Self = "Self"
    While = "While"
    Trait = "Trait"
    Const = "Const"
    Defer = "Defer"
    Break = "Break"
    Union = "Union"
    Import = "Import"
    Static = "Static"
    Struct = "Struct"
    Extern = "Extern"
    Switch = "Switch"
    Return = "Return"
    Extend = "Extend"
    Default = "Default"
    Typedef = "Typedef"
    Void = "Void"
    Bool = "Bool"
    CharType = "CharType"
    U8 = "U8"
    I8 = "I8"
    U16 = "U16"
    I16 = "I16"
    U32 = "U32"
    I32 = "I32"
    U64 = "U64"
    I64 = "I64"
    U128 = "U128"
    I128 = "I128"
    F32 = "F32"
    F64 = "F64"
    Usize = "Usize"
    Isize = "Isize"
    Rawptr = "Rawptr"
    Str = "Str"
    Distinct = "Distinct"
    Continue = "Continue"
    Comptime = "Comptime"
    Volatile = "Volatile"
    Plus = "Plus"
    Minus = "Minus"
    Star = "Star"
    Slash = "Slash"
    Less = "Less"
    Greater = "Greater"
    Neg = "Neg"
    Not = "Not"
    Colon = "Colon"
    Semicolon = "Semicolon"
    Comma = "Comma"
    Hash = "Hash"
    Dot = "Dot"
    Ampersand = "Ampersand"
    Caret = "Caret"
    Pipe = "Pipe"
    Equal = "Equal"
    PlusEqual = "PlusEqual"
    MinusEqual = "MinusEqual"
    StarEqual = "StarEqual"
    SlashEqual = "SlashEqual"
    EqualEqual = "EqualEqual"
    NotEqual = "NotEqual"
    LessEqual = "LessEqual"
    GreaterEqual = "GreaterEqual"
    PipeEqual = "PipeEqual"
    CaretEqual = "CaretEqual"
    AmpEqual = "AmpEqual"
    NegEqual = "NegEqual"
    FatArrow = "FatArrow"
    ColonColon = "ColonColon"
    PlusPlus = "PlusPlus"
    MinusMinus = "MinusMinus"
    And = "And"
    Or = "Or"
    StarDot = "StarDot"
    Ellipsis = "Ellipsis"
    LParen = "LParen"
    Rparen = "Rparen"
    LBrace = "LBrace"
    RBrace = "RBrace"
    LBracket = "LBracket"
    RBracket = "RBracket"
    At = "At"
    Question = "Question"
    BuiltinSizeof = "BuiltinSizeof"
    BuiltinAssert = "BuiltinAssert"
    BuiltinAlignof = "BuiltinAlignof"
    BuiltinTypeof = "BuiltinTypeof"


KEYWORDS = {
    "if": TokenKind.If,
    "as": TokenKind.As,
    "mod": TokenKind.Mod,
    "pub": TokenKind.Pub,
    "for": TokenKind.For,
    "asm": TokenKind.Asm,
    "var": TokenKind.Var,
    "enum": TokenKind.Enum,
    "else": TokenKind.Else,
    "loop": TokenKind.Loop,
    "flag": TokenKind.Flag,
    "true": TokenKind.TrueLit,
    "null": TokenKind.NullLit,
    "self": TokenKind.Self,
    "while": TokenKind.While,
    "trait": TokenKind.Trait,
    "const": TokenKind.Const,
    "defer": TokenKind.Defer,
    "break": TokenKind.Break,
    "union": TokenKind.Union,
    "import": TokenKind.Import,
    "static": TokenKind.Static,
    "struct": TokenKind.Struct,
    "extern": TokenKind.Extern,
    "switch": TokenKind.Switch,
    "return": TokenKind.Return,
    "extend": TokenKind.Extend,
    "default": TokenKind.Default,
    "typedef": TokenKind.Typedef,
    "distinct": TokenKind.Distinct,
    "continue": TokenKind.Continue,
    "comptime": TokenKind.Comptime,
    "volatile": TokenKind.Volatile,
    "false": TokenKind.FalseLit,
    "void": TokenKind.Void,
    "bool": TokenKind.Bool,
    "char": TokenKind.CharType,
    "u8": TokenKind.U8,
    "u16": TokenKind.U16,
    "u32": TokenKind.U32,
    "u64": TokenKind.U64,
    "u128": TokenKind.U128,
    "i8": TokenKind.I8,
    "i16": TokenKind.I16,
    "i32": TokenKind.I32,
    "i64": TokenKind.I64,
    "i128": TokenKind.I128,
    "f32": TokenKind.F32,
    "f64": TokenKind.F64,
    "usize": TokenKind.Usize,
    "isize": TokenKind.Isize,
    "rawptr": TokenKind.Rawptr,
    "str": TokenKind.Str,
    "sizeof": TokenKind.BuiltinSizeof,
    "assert": TokenKind.BuiltinAssert,
    "alignof": TokenKind.BuiltinAlignof,
    "typeof": TokenKind.BuiltinTypeof,
}


class Token:
    def __init__(self, kind, line, col, value):
        self.kind = kind
        self.line = line
        self.col = col
        self.value = value

    def __repr__(self):
        return f"Token({self.kind}, {self.line}:{self.col}, {self.value!r})"


class Lexer:
    def __init__(self, source, filename):
        self.source = source
        self.filename = filename
        self.pos = 0
        self.line = 1
        self.line_start = 0
        self.tokens = []

    def is_at_end(self):
        return self.pos >= len(self.source)

    def peek(self):
        if self.pos >= len(self.source):
            return "\0"
        return self.source[self.pos]

    def peek2(self):
        if self.pos + 1 >= len(self.source):
            return "\0"
        return self.source[self.pos + 1]

    def advance(self):
        c = self.source[self.pos]
        self.pos += 1
        return c

    def skip_ws(self):
        while not self.is_at_end():
            c = self.peek()
            if c in " \t\r":
                self.advance()
            elif c == "\n":
                self.line += 1
                self.advance()
                self.line_start = self.pos
            elif c == "/":
                if self.peek2() == "/":
                    self.advance()
                    self.advance()
                    while not self.is_at_end() and self.peek() != "\n":
                        self.advance()
                elif self.peek2() == "*":
                    self.advance()
                    self.advance()
                    while not self.is_at_end():
                        if self.peek() == "\n":
                            self.line += 1
                            self.advance()
                            self.line_start = self.pos
                        elif self.peek() == "*" and self.peek2() == "/":
                            self.advance()
                            self.advance()
                            break
                        else:
                            self.advance()
                else:
                    break
            else:
                break

    def make_token(self, kind, start):
        return Token(kind, self.line, start - self.line_start + 1, self.source[start:self.pos])

    def lex_string(self, start):
        while not self.is_at_end():
            c = self.peek()
            if c == '"':
                self.advance()
                return self.make_token(TokenKind.String, start)
            if c == "\\":
                self.advance()
                if not self.is_at_end():
                    self.advance()
                continue
            if c == "\n":
                self.line += 1
                self.advance()
                self.line_start = self.pos
                continue
            self.advance()
        return self.make_token(TokenKind.String, start)

    def lex_raw_string(self, start):
        if self.is_at_end() or self.peek() != '"':
            return self.make_token(TokenKind.RawString, start)
        self.advance()

        delim_start = self.pos
        while not self.is_at_end() and self.peek() != "(":
            self.advance()
        delim = self.source[delim_start:self.pos]

        if self.is_at_end() or self.peek() != "(":
            return self.make_token(TokenKind.RawString, start)
        self.advance()

        while not self.is_at_end():
            c = self.peek()
            if c == "\n":
                self.line += 1
                self.advance()
                self.line_start = self.pos
                continue
            if c == ")":
                if self.source[self.pos + 1: self.pos + 1 + len(delim)] == delim:
                    after = self.pos + 1 + len(delim)
                    if after < len(self.source) and self.source[after] == '"':
                        self.pos = after + 1
                        return self.make_token(TokenKind.RawString, start)
            self.advance()
        return self.make_token(TokenKind.RawString, start)

    def lex_number(self, start):
        if self.peek() == "x" and (self.pos - start) == 1 and self.source[start] == "0":
            self.advance()
            return self.lex_hex(start)
        if self.peek() == "b" and (self.pos - start) == 1 and self.source[start] == "0":
            self.advance()
            return self.lex_binary(start)
        if self.peek() == "o" and (self.pos - start) == 1 and self.source[start] == "0":
            self.advance()
            return self.lex_octal(start)
        return self.lex_decimal(start)

    def lex_hex(self, start):
        while not self.is_at_end():
            c = self.peek()
            if c.isdigit() or ("a" <= c <= "f") or ("A" <= c <= "F") or c == "_":
                self.advance()
            else:
                break
        return self.make_token(TokenKind.Hex, start)

    def lex_binary(self, start):
        while not self.is_at_end():
            c = self.peek()
            if c in "01_":
                self.advance()
            else:
                break
        return self.make_token(TokenKind.Bin, start)

    def lex_octal(self, start):
        while not self.is_at_end():
            c = self.peek()
            if ("0" <= c <= "7") or c == "_":
                self.advance()
            else:
                break
        return self.make_token(TokenKind.Oct, start)

    def lex_decimal(self, start):
        is_float = False
        while not self.is_at_end():
            c = self.peek()
            if c.isdigit():
                self.advance()
            elif c == "." and not is_float:
                if self.peek2() == ".":
                    break
                is_float = True
                self.advance()
            elif (c == "e" or c == "E") and not is_float:
                is_float = True
                self.advance()
                if not self.is_at_end() and self.peek() in "+-":
                    self.advance()
            elif c == "_":
                self.advance()
            else:
                break
        kind = TokenKind.Float if is_float else TokenKind.Dec
        return self.make_token(kind, start)

    def lex_ident(self, start):
        while not self.is_at_end():
            c = self.peek()
            if c.isalnum() or c == "_":
                self.advance()
            else:
                break
        word = self.source[start:self.pos]
        kind = KEYWORDS.get(word, TokenKind.Ident)
        return self.make_token(kind, start)

    def lex_char(self, start):
        while not self.is_at_end() and self.peek() != "'":
            if self.peek() == "\\":
                self.advance()
                if not self.is_at_end():
                    self.advance()
            else:
                self.advance()
        if not self.is_at_end():
            self.advance()
        return self.make_token(TokenKind.Char, start)

    def lex_operator(self, c, start):
        if not self.is_at_end():
            nxt = self.peek()
            if c == "+" and nxt == "+":
                self.advance()
                return self.make_token(TokenKind.PlusPlus, start)
            if c == "-" and nxt == "-":
                self.advance()
                return self.make_token(TokenKind.MinusMinus, start)
            if c == "=" and nxt == "=":
                self.advance()
                return self.make_token(TokenKind.EqualEqual, start)
            if c == "!" and nxt == "=":
                self.advance()
                return self.make_token(TokenKind.NotEqual, start)
            if c == "<" and nxt == "=":
                self.advance()
                return self.make_token(TokenKind.LessEqual, start)
            if c == ">" and nxt == "=":
                self.advance()
                return self.make_token(TokenKind.GreaterEqual, start)
            if c == "&" and nxt == "&":
                self.advance()
                return self.make_token(TokenKind.And, start)
            if c == "|" and nxt == "|":
                self.advance()
                return self.make_token(TokenKind.Or, start)
            if c == "+" and nxt == "=":
                self.advance()
                return self.make_token(TokenKind.PlusEqual, start)
            if c == "-" and nxt == "=":
                self.advance()
                return self.make_token(TokenKind.MinusEqual, start)
            if c == "*" and nxt == "=":
                self.advance()
                return self.make_token(TokenKind.StarEqual, start)
            if c == "/" and nxt == "=":
                self.advance()
                return self.make_token(TokenKind.SlashEqual, start)
            if c == "|" and nxt == "=":
                self.advance()
                return self.make_token(TokenKind.PipeEqual, start)
            if c == "^" and nxt == "=":
                self.advance()
                return self.make_token(TokenKind.CaretEqual, start)
            if c == "&" and nxt == "=":
                self.advance()
                return self.make_token(TokenKind.AmpEqual, start)
            if c == "~" and nxt == "=":
                self.advance()
                return self.make_token(TokenKind.NegEqual, start)
            if c == "=" and nxt == ">":
                self.advance()
                return self.make_token(TokenKind.FatArrow, start)
            if c == ":" and nxt == ":":
                self.advance()
                return self.make_token(TokenKind.ColonColon, start)
            if c == "*" and nxt == ".":
                self.advance()
                return self.make_token(TokenKind.StarDot, start)
            if c == "." and nxt == ".":
                if self.pos + 2 < len(self.source) and self.source[self.pos + 2] == ".":
                    self.advance()
                    self.advance()
                    return self.make_token(TokenKind.Ellipsis, start)

        ops = {
            "+": TokenKind.Plus, "-": TokenKind.Minus, "*": TokenKind.Star,
            "/": TokenKind.Slash, "<": TokenKind.Less, ">": TokenKind.Greater,
            "~": TokenKind.Neg, "!": TokenKind.Not, ":": TokenKind.Colon,
            ";": TokenKind.Semicolon, ",": TokenKind.Comma, "#": TokenKind.Hash,
            ".": TokenKind.Dot, "&": TokenKind.Ampersand, "^": TokenKind.Caret,
            "|": TokenKind.Pipe, "=": TokenKind.Equal, "(": TokenKind.LParen,
            ")": TokenKind.Rparen, "{": TokenKind.LBrace, "}": TokenKind.RBrace,
            "[": TokenKind.LBracket, "]": TokenKind.RBracket,             "@": TokenKind.At, "?": TokenKind.Question,
        }
        kind = ops.get(c)
        if kind:
            return self.make_token(kind, start)
        return self.make_token(TokenKind.Eof, start)

    def next_token(self):
        self.skip_ws()
        start = self.pos
        if self.is_at_end():
            return self.make_token(TokenKind.Eof, start)

        c = self.advance()

        if c == "R" and not self.is_at_end() and self.peek() == '"':
            self.advance()
            return self.lex_raw_string(start)
        if c in ("u", "U", "c") and not self.is_at_end() and self.peek() == '"':
            self.advance()
            return self.lex_string(start)
        if c == "u" and not self.is_at_end() and self.peek() == "8":
            if self.pos + 1 < len(self.source) and self.source[self.pos + 1] == '"':
                self.advance()
                self.advance()
                return self.lex_string(start)

        if c.isalpha() or c == "_":
            return self.lex_ident(start)
        if c.isdigit():
            return self.lex_number(start)
        if c == '"':
            return self.lex_string(start)
        if c == "'":
            return self.lex_char(start)

        return self.lex_operator(c, start)

    def lex(self):
        while True:
            tok = self.next_token()
            self.tokens.append(tok)
            if tok.kind == TokenKind.Eof:
                break
        return self.tokens
