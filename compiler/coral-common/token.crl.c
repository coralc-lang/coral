#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct _coral_str { const uint8_t* ptr; size_t len; } _coral_str;

typedef struct IdentifierInfo IdentifierInfo;
typedef struct Slice Slice;
typedef struct Token Token;
typedef enum TokenKind TokenKind;

enum TokenKind {
    TokenKind_Eof = 0,
    TokenKind_Ident,
    TokenKind_Dec,
    TokenKind_Hex,
    TokenKind_Bin,
    TokenKind_Oct,
    TokenKind_Float,
    TokenKind_String,
    TokenKind_RawString,
    TokenKind_Char,
    TokenKind_True,
    TokenKind_Null,
    TokenKind_False,
    TokenKind_If,
    TokenKind_As,
    TokenKind_Mod,
    TokenKind_Pub,
    TokenKind_For,
    TokenKind_Asm,
    TokenKind_Var,
    TokenKind_Enum,
    TokenKind_Else,
    TokenKind_Loop,
    TokenKind_Flag,
    TokenKind_Self,
    TokenKind_While,
    TokenKind_Trait,
    TokenKind_Const,
    TokenKind_Defer,
    TokenKind_Break,
    TokenKind_Union,
    TokenKind_Import,
    TokenKind_Static,
    TokenKind_Struct,
    TokenKind_Extern,
    TokenKind_Switch,
    TokenKind_Return,
    TokenKind_Extend,
    TokenKind_Default,
    TokenKind_Typedef,
    TokenKind_Void,
    TokenKind_Bool,
    TokenKind_U8,
    TokenKind_I8,
    TokenKind_U16,
    TokenKind_I16,
    TokenKind_U32,
    TokenKind_I32,
    TokenKind_U64,
    TokenKind_I64,
    TokenKind_U128,
    TokenKind_I128,
    TokenKind_F32,
    TokenKind_F64,
    TokenKind_Usize,
    TokenKind_Isize,
    TokenKind_Rawptr,
    TokenKind_Str,
    TokenKind_Distinct,
    TokenKind_Continue,
    TokenKind_Comptime,
    TokenKind_Volatile,
    TokenKind_Plus,
    TokenKind_Minus,
    TokenKind_Star,
    TokenKind_Slash,
    TokenKind_Less,
    TokenKind_Greater,
    TokenKind_Neg,
    TokenKind_Not,
    TokenKind_Colon,
    TokenKind_Semicolon,
    TokenKind_Comma,
    TokenKind_Hash,
    TokenKind_Dot,
    TokenKind_Ampersand,
    TokenKind_Caret,
    TokenKind_Pipe,
    TokenKind_Equal,
    TokenKind_PlusEqual,
    TokenKind_MinusEqual,
    TokenKind_StarEqual,
    TokenKind_SlashEqual,
    TokenKind_EqualEqual,
    TokenKind_NotEqual,
    TokenKind_LessEqual,
    TokenKind_GreaterEqual,
    TokenKind_PipeEqual,
    TokenKind_CaretEqual,
    TokenKind_AmpEqual,
    TokenKind_NegEqual,
    TokenKind_FatArrow,
    TokenKind_ColonColon,
    TokenKind_PlusPlus,
    TokenKind_MinusMinus,
    TokenKind_And,
    TokenKind_Or,
    TokenKind_StarDot,
    TokenKind_Ellipsis,
    TokenKind_LParen,
    TokenKind_Rparen,
    TokenKind_LBrace,
    TokenKind_RBrace,
    TokenKind_LBracket,
    TokenKind_RBracket,
    TokenKind_BuiltinSizeof,
    TokenKind_BuiltinAssert,
    TokenKind_BuiltinAlignof,
    TokenKind_BuiltinTypeof,
    TokenKind_At,
};

typedef struct Token {
    size_t col;
    size_t line;
    Slice data;
    TokenKind kind;
    IdentifierInfo* info;
} Token;

typedef struct IdentifierInfo {
    uint8_t* name;
    size_t nameLen;
    TokenKind kind;
    _Bool isKeyword;
} IdentifierInfo;

int main(int argc, char** argv) {
    return 0;
}
