#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct _coral_str { const uint8_t* ptr; size_t len; } _coral_str;

typedef struct SourceMap SourceMap;
typedef struct FileEntry FileEntry;
typedef struct InternEntry InternEntry;
typedef struct SourceLoc SourceLoc;
typedef struct Decl Decl;
typedef struct Lexer Lexer;
typedef struct Label Label;
typedef struct Slice Slice;
typedef struct FlagBranch FlagBranch;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Ast Ast;
typedef struct TypeEntry TypeEntry;
typedef struct Span Span;
typedef struct VariantVariant VariantVariant;
typedef struct EnumVariant EnumVariant;
typedef struct Diagnostic Diagnostic;
typedef struct EscapeResult EscapeResult;
typedef struct TestResult TestResult;
typedef struct NodeId NodeId;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct Expr Expr;
typedef struct Pat Pat;
typedef struct GenericParam GenericParam;
typedef struct TraitBound TraitBound;
typedef struct File File;
typedef struct Node Node;
typedef struct Field Field;
typedef struct Token Token;
typedef struct Param Param;
typedef struct AstContext AstContext;
typedef struct IdentifierTable IdentifierTable;
typedef struct Parser Parser;
typedef struct IdentEntry IdentEntry;
typedef struct SwitchCase SwitchCase;
typedef struct ImportSymbol ImportSymbol;
typedef struct Stmt Stmt;
typedef struct ParserMark ParserMark;
typedef struct Attribute Attribute;
typedef enum ErrorCode ErrorCode;
typedef enum TokenKind TokenKind;


Slice Slice_from(Slice* self, uint8_t* p, size_t len);
_Bool Slice_eq(Slice* self, Slice b);
_Bool Slice_eqSlice(Slice* self, Slice other);
_Bool Slice_eqCstr(Slice* self, uint8_t* cStr, size_t cStrLen);

typedef struct Slice {
    uint8_t* ptr;
    size_t len;
} Slice;

Slice Slice_from(Slice* self, uint8_t* p, size_t len) {
    Slice s;
    (s.ptr = p);
    (s.len = len);
    return s;
}
_Bool Slice_eq(Slice* self, Slice b) {
    if ((self->len != b.len)) {
        return 0;
    }
    for (size_t i = 0; (i < self->len); ) {
        if ((self->ptr[i] != b.ptr[i])) {
            return 0;
        }
    }
    return 1;
}
_Bool Slice_eqSlice(Slice* self, Slice other) {
    if ((self->len != other.len)) {
        return 0;
    }
    for (size_t i = 0; (i < self->len); ) {
        if ((self->ptr[i] != other.ptr[i])) {
            return 0;
        }
    }
    return 1;
}
_Bool Slice_eqCstr(Slice* self, uint8_t* cStr, size_t cStrLen) {
    if ((self->len != cStrLen)) {
        return 0;
    }
    for (size_t i = 0; (i < self->len); ) {
        if ((self->ptr[i] != cStr[i])) {
            return 0;
        }
    }
    return 1;
}



typedef struct SourceMap SourceMap;
typedef struct FileEntry FileEntry;
typedef struct InternEntry InternEntry;
typedef struct SourceLoc SourceLoc;
typedef struct Decl Decl;
typedef struct Lexer Lexer;
typedef struct Label Label;
typedef struct Slice Slice;
typedef struct FlagBranch FlagBranch;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Ast Ast;
typedef struct TypeEntry TypeEntry;
typedef struct Span Span;
typedef struct VariantVariant VariantVariant;
typedef struct EnumVariant EnumVariant;
typedef struct Diagnostic Diagnostic;
typedef struct EscapeResult EscapeResult;
typedef struct TestResult TestResult;
typedef struct NodeId NodeId;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct Expr Expr;
typedef struct Pat Pat;
typedef struct GenericParam GenericParam;
typedef struct TraitBound TraitBound;
typedef struct File File;
typedef struct Node Node;
typedef struct Field Field;
typedef struct Token Token;
typedef struct Param Param;
typedef struct AstContext AstContext;
typedef struct IdentifierTable IdentifierTable;
typedef struct Parser Parser;
typedef struct IdentEntry IdentEntry;
typedef struct SwitchCase SwitchCase;
typedef struct ImportSymbol ImportSymbol;
typedef struct Stmt Stmt;
typedef struct ParserMark ParserMark;
typedef struct Attribute Attribute;
typedef enum ErrorCode ErrorCode;
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
    TokenKind_Typedef,
    TokenKind_Variant,
    TokenKind_In,
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
    TokenKind_Percent,
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
    TokenKind_PercentEqual,
    TokenKind_EqualEqual,
    TokenKind_NotEqual,
    TokenKind_LessEqual,
    TokenKind_GreaterEqual,
    TokenKind_PipeEqual,
    TokenKind_CaretEqual,
    TokenKind_AmpEqual,
    TokenKind_NegEqual,
    TokenKind_ShlEqual,
    TokenKind_ShrEqual,
    TokenKind_FatArrow,
    TokenKind_ColonColon,
    TokenKind_PlusPlus,
    TokenKind_MinusMinus,
    TokenKind_And,
    TokenKind_Or,
    TokenKind_Shl,
    TokenKind_Shr,
    TokenKind_Arrow,
    TokenKind_StarDot,
    TokenKind_Ellipsis,
    TokenKind_LParen,
    TokenKind_RParen,
    TokenKind_LBrace,
    TokenKind_RBrace,
    TokenKind_LBracket,
    TokenKind_RBracket,
    TokenKind_AttrOpen,
    TokenKind_AttrClose,
    TokenKind_BuiltinSizeof,
    TokenKind_BuiltinAssert,
    TokenKind_BuiltinAlignof,
    TokenKind_BuiltinTypeof,
    TokenKind_BuiltinAssertOut,
    TokenKind_At,
    TokenKind_Question,
    TokenKind_Unknown
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




typedef struct SourceMap SourceMap;
typedef struct FileEntry FileEntry;
typedef struct InternEntry InternEntry;
typedef struct SourceLoc SourceLoc;
typedef struct Decl Decl;
typedef struct Lexer Lexer;
typedef struct Label Label;
typedef struct Slice Slice;
typedef struct FlagBranch FlagBranch;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Ast Ast;
typedef struct TypeEntry TypeEntry;
typedef struct Span Span;
typedef struct VariantVariant VariantVariant;
typedef struct EnumVariant EnumVariant;
typedef struct Diagnostic Diagnostic;
typedef struct EscapeResult EscapeResult;
typedef struct TestResult TestResult;
typedef struct NodeId NodeId;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct Expr Expr;
typedef struct Pat Pat;
typedef struct GenericParam GenericParam;
typedef struct TraitBound TraitBound;
typedef struct File File;
typedef struct Node Node;
typedef struct Field Field;
typedef struct Token Token;
typedef struct Param Param;
typedef struct AstContext AstContext;
typedef struct IdentifierTable IdentifierTable;
typedef struct Parser Parser;
typedef struct IdentEntry IdentEntry;
typedef struct SwitchCase SwitchCase;
typedef struct ImportSymbol ImportSymbol;
typedef struct Stmt Stmt;
typedef struct ParserMark ParserMark;
typedef struct Attribute Attribute;
typedef enum ErrorCode ErrorCode;
typedef enum TokenKind TokenKind;



enum ErrorCode {
    ErrorCode_LexUnknownChar = 0,
    ErrorCode_LexUnterminatedString,
    ErrorCode_LexUnterminatedChar,
    ErrorCode_LexUnterminatedComment,
    ErrorCode_LexInvalidEscape,
    ErrorCode_LexInvalidNumber,
    ErrorCode_LexInvalidChar,
    ErrorCode_ParseExpectedToken,
    ErrorCode_ParseExpectedExpr,
    ErrorCode_ParseExpectedType,
    ErrorCode_ParseExpectedDecl,
    ErrorCode_ParseExpectedStmt,
    ErrorCode_ParseUnexpectedEof,
    ErrorCode_ParseInvalidAssignTarget,
    ErrorCode_ParseDuplicateModifier,
    ErrorCode_ParseMissingSemicolon,
    ErrorCode_SemaUndeclaredIdent,
    ErrorCode_SemaTypeMismatch,
    ErrorCode_SemaArityMismatch,
    ErrorCode_SemaDuplicateDecl,
    ErrorCode_SemaInvalidCast,
    ErrorCode_SemaUnknownMember,
    ErrorCode_CodegenUnsupported,
    ErrorCode_CodegenInternal,
    ErrorCode_DriverFileNotFound,
    ErrorCode_DriverInvalidFlag,
    ErrorCode_DriverOutOfMemory
};




typedef struct SourceMap SourceMap;
typedef struct FileEntry FileEntry;
typedef struct InternEntry InternEntry;
typedef struct SourceLoc SourceLoc;
typedef struct Decl Decl;
typedef struct Lexer Lexer;
typedef struct Label Label;
typedef struct Slice Slice;
typedef struct FlagBranch FlagBranch;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Ast Ast;
typedef struct TypeEntry TypeEntry;
typedef struct Span Span;
typedef struct VariantVariant VariantVariant;
typedef struct EnumVariant EnumVariant;
typedef struct Diagnostic Diagnostic;
typedef struct EscapeResult EscapeResult;
typedef struct TestResult TestResult;
typedef struct NodeId NodeId;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct Expr Expr;
typedef struct Pat Pat;
typedef struct GenericParam GenericParam;
typedef struct TraitBound TraitBound;
typedef struct File File;
typedef struct Node Node;
typedef struct Field Field;
typedef struct Token Token;
typedef struct Param Param;
typedef struct AstContext AstContext;
typedef struct IdentifierTable IdentifierTable;
typedef struct Parser Parser;
typedef struct IdentEntry IdentEntry;
typedef struct SwitchCase SwitchCase;
typedef struct ImportSymbol ImportSymbol;
typedef struct Stmt Stmt;
typedef struct ParserMark ParserMark;
typedef struct Attribute Attribute;
typedef enum ErrorCode ErrorCode;
typedef enum TokenKind TokenKind;


typedef uint32_t Str;

typedef struct SourceLoc {
    uint32_t data;
} SourceLoc;

typedef struct NodeId {
    uint32_t index;
} NodeId;




typedef struct SourceMap SourceMap;
typedef struct FileEntry FileEntry;
typedef struct InternEntry InternEntry;
typedef struct SourceLoc SourceLoc;
typedef struct Decl Decl;
typedef struct Lexer Lexer;
typedef struct Label Label;
typedef struct Slice Slice;
typedef struct FlagBranch FlagBranch;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Ast Ast;
typedef struct TypeEntry TypeEntry;
typedef struct Span Span;
typedef struct VariantVariant VariantVariant;
typedef struct EnumVariant EnumVariant;
typedef struct Diagnostic Diagnostic;
typedef struct EscapeResult EscapeResult;
typedef struct TestResult TestResult;
typedef struct NodeId NodeId;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct Expr Expr;
typedef struct Pat Pat;
typedef struct GenericParam GenericParam;
typedef struct TraitBound TraitBound;
typedef struct File File;
typedef struct Node Node;
typedef struct Field Field;
typedef struct Token Token;
typedef struct Param Param;
typedef struct AstContext AstContext;
typedef struct IdentifierTable IdentifierTable;
typedef struct Parser Parser;
typedef struct IdentEntry IdentEntry;
typedef struct SwitchCase SwitchCase;
typedef struct ImportSymbol ImportSymbol;
typedef struct Stmt Stmt;
typedef struct ParserMark ParserMark;
typedef struct Attribute Attribute;
typedef enum ErrorCode ErrorCode;
typedef enum TokenKind TokenKind;


uint32_t SourceMap_addFile(SourceMap* self, Str path, uint8_t* bytes, size_t len);
uint32_t SourceMap_lineColLine(SourceMap* self, uint32_t fileId, uint32_t offset);
uint32_t SourceMap_lineColCol(SourceMap* self, uint32_t fileId, uint32_t offset);

typedef struct Span {
    uint32_t file;
    uint32_t start;
    uint32_t end;
} Span;

typedef struct Label {
    Span span;
    Str text;
    uint8_t kind;
} Label;

typedef struct FileEntry {
    Str path;
    uint8_t* bytes;
    size_t len;
    uint32_t* lineStarts;
    uint32_t lineCount;
} FileEntry;

typedef struct SourceMap {
    FileEntry* files;
    uint32_t filesLen;
} SourceMap;

uint32_t SourceMap_addFile(SourceMap* self, Str path, uint8_t* bytes, size_t len) {
    uint32_t id = self->filesLen;
    return id;
}
uint32_t SourceMap_lineColLine(SourceMap* self, uint32_t fileId, uint32_t offset) {
    return 1;
}
uint32_t SourceMap_lineColCol(SourceMap* self, uint32_t fileId, uint32_t offset) {
    return 1;
}



typedef struct SourceMap SourceMap;
typedef struct FileEntry FileEntry;
typedef struct InternEntry InternEntry;
typedef struct SourceLoc SourceLoc;
typedef struct Decl Decl;
typedef struct Lexer Lexer;
typedef struct Label Label;
typedef struct Slice Slice;
typedef struct FlagBranch FlagBranch;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Ast Ast;
typedef struct TypeEntry TypeEntry;
typedef struct Span Span;
typedef struct VariantVariant VariantVariant;
typedef struct EnumVariant EnumVariant;
typedef struct Diagnostic Diagnostic;
typedef struct EscapeResult EscapeResult;
typedef struct TestResult TestResult;
typedef struct NodeId NodeId;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct Expr Expr;
typedef struct Pat Pat;
typedef struct GenericParam GenericParam;
typedef struct TraitBound TraitBound;
typedef struct File File;
typedef struct Node Node;
typedef struct Field Field;
typedef struct Token Token;
typedef struct Param Param;
typedef struct AstContext AstContext;
typedef struct IdentifierTable IdentifierTable;
typedef struct Parser Parser;
typedef struct IdentEntry IdentEntry;
typedef struct SwitchCase SwitchCase;
typedef struct ImportSymbol ImportSymbol;
typedef struct Stmt Stmt;
typedef struct ParserMark ParserMark;
typedef struct Attribute Attribute;
typedef enum ErrorCode ErrorCode;
typedef enum TokenKind TokenKind;

extern int32_t printf(uint8_t* fmt, ...);
extern int32_t write(int32_t fd, uint8_t* buf, size_t len);

DiagnosticEngine DiagnosticEngine_init(DiagnosticEngine* self, uint8_t* bufStart, uint8_t* bufEnd);
_Bool DiagnosticEngine_hasErrors(DiagnosticEngine* self);
_Bool DiagnosticEngine_tooManyErrors(DiagnosticEngine* self);
void DiagnosticEngine_emitError(DiagnosticEngine* self, ErrorCode code, uint8_t* errPtr, Str msg);
void DiagnosticEngine_emitWarning(DiagnosticEngine* self, ErrorCode code, uint8_t* errPtr, Str msg);
void DiagnosticEngine_emitNote(DiagnosticEngine* self, ErrorCode code, uint8_t* errPtr, Str msg);
void DiagnosticEngine_emitFatal(DiagnosticEngine* self, ErrorCode code, uint8_t* errPtr, Str msg);
void DiagnosticEngine_renderSimple(DiagnosticEngine* self, ErrorCode code, uint8_t* errPtr, Str msg, uint8_t* level);
void DiagnosticEngine_renderDiagnostic(DiagnosticEngine* self, Diagnostic* diag);
void DiagnosticEngine_renderLabel(DiagnosticEngine* self, Label* lbl);

typedef struct Diagnostic {
    uint32_t code;
    uint32_t severity;
    Str message;
    Str detail;
    Label* labels;
    uint32_t labelsLen;
    Str why;
    Str fix;
    Str learn;
} Diagnostic;

typedef struct DiagnosticEngine {
    size_t errors;
    size_t warnings;
    size_t errorLimit;
    uint8_t* bufStart;
    uint8_t* bufEnd;
    SourceMap* sourceMap;
} DiagnosticEngine;

extern int32_t printf(uint8_t* fmt, ...);
extern int32_t write(int32_t fd, uint8_t* buf, size_t len);
DiagnosticEngine DiagnosticEngine_init(DiagnosticEngine* self, uint8_t* bufStart, uint8_t* bufEnd) {
    DiagnosticEngine e;
    (e.errors = 0);
    (e.warnings = 0);
    (e.errorLimit = 20);
    (e.bufStart = bufStart);
    (e.bufEnd = bufEnd);
    (e.sourceMap = NULL);
    return e;
}
_Bool DiagnosticEngine_hasErrors(DiagnosticEngine* self) {
    return (self->errors > 0);
}
_Bool DiagnosticEngine_tooManyErrors(DiagnosticEngine* self) {
    return (self->errors >= self->errorLimit);
}
void DiagnosticEngine_emitError(DiagnosticEngine* self, ErrorCode code, uint8_t* errPtr, Str msg) {
    if (DiagnosticEngine_tooManyErrors(self)) {
        return;
    }
    (self->errors = (self->errors + 1));
    DiagnosticEngine_renderSimple(self, code, errPtr, msg, "error");
}
void DiagnosticEngine_emitWarning(DiagnosticEngine* self, ErrorCode code, uint8_t* errPtr, Str msg) {
    (self->warnings = (self->warnings + 1));
    DiagnosticEngine_renderSimple(self, code, errPtr, msg, "warning");
}
void DiagnosticEngine_emitNote(DiagnosticEngine* self, ErrorCode code, uint8_t* errPtr, Str msg) {
    DiagnosticEngine_renderSimple(self, code, errPtr, msg, "note");
}
void DiagnosticEngine_emitFatal(DiagnosticEngine* self, ErrorCode code, uint8_t* errPtr, Str msg) {
    (self->errors = (self->errors + 1));
    DiagnosticEngine_renderSimple(self, code, errPtr, msg, "fatal error");
}
void DiagnosticEngine_renderSimple(DiagnosticEngine* self, ErrorCode code, uint8_t* errPtr, Str msg, uint8_t* level) {
    uint8_t* lineStart = errPtr;
    while ((lineStart > self->bufStart)) {
        uint8_t* prev = (lineStart - 1);
        if ((prev[0] == '\n')) {
            break;
        }
        (lineStart = prev);
    }
    uint8_t* lineEnd = errPtr;
    while ((lineEnd < self->bufEnd)) {
        if ((lineEnd[0] == '\n')) {
            break;
        }
        if ((lineEnd[0] == '\r')) {
            break;
        }
        (lineEnd = (lineEnd + 1));
    }
    size_t lineNum = 1;
    uint8_t* scan = self->bufStart;
    while ((scan < lineStart)) {
        if ((scan[0] == '\n')) {
            (lineNum = (lineNum + 1));
        }
        (scan = (scan + 1));
    }
    size_t colNum = (((size_t)(errPtr - lineStart)) + 1);
    printf("%llu:%llu: %s: %s\n", lineNum, colNum, level, msg);
    size_t lineLen = ((size_t)(lineEnd - lineStart));
    write(1, lineStart, lineLen);
    write(1, "\n", 1);
    int32_t i = 1;
    while ((i < ((int32_t)colNum))) {
        write(1, " ", 1);
        (i = (i + 1));
    }
    write(1, "^\n", 2);
}
void DiagnosticEngine_renderDiagnostic(DiagnosticEngine* self, Diagnostic* diag) {
    uint8_t* sevStr = "error";
    if ((diag->severity == 2)) {
        (sevStr = "warning");
    }
    if ((diag->severity == 1)) {
        (sevStr = "note");
    }
    if ((diag->severity == 4)) {
        (sevStr = "fatal error");
    }
    printf("%s: %s\n", sevStr, diag->message);
    printf("  %s\n", diag->detail);
    uint32_t i = 0;
    while ((i < diag->labelsLen)) {
        Label* lbl = (diag->labels + i);
        DiagnosticEngine_renderLabel(self, lbl);
        (i = (i + 1));
    }
    printf("  why    %s\n", diag->why);
    printf("  fix    %s\n", diag->fix);
    printf("  learn  %s\n", diag->learn);
}
void DiagnosticEngine_renderLabel(DiagnosticEngine* self, Label* lbl) {
    uint8_t* errPtr = (self->bufStart + lbl->span.start);
    uint8_t* lineStart = errPtr;
    while ((lineStart > self->bufStart)) {
        uint8_t* prev = (lineStart - 1);
        if ((prev[0] == '\n')) {
            break;
        }
        (lineStart = prev);
    }
    uint8_t* lineEnd = errPtr;
    while ((lineEnd < self->bufEnd)) {
        if ((lineEnd[0] == '\n')) {
            break;
        }
        if ((lineEnd[0] == '\r')) {
            break;
        }
        (lineEnd = (lineEnd + 1));
    }
    size_t lineNum = 1;
    uint8_t* scan = self->bufStart;
    while ((scan < lineStart)) {
        if ((scan[0] == '\n')) {
            (lineNum = (lineNum + 1));
        }
        (scan = (scan + 1));
    }
    size_t startCol = ((size_t)(errPtr - lineStart));
    uint32_t spanLen = (lbl->span.end - lbl->span.start);
    size_t lineLen = ((size_t)(lineEnd - lineStart));
    printf("  %llu | ", lineNum);
    write(1, lineStart, lineLen);
    write(1, "\n", 1);
    printf("       | ");
    size_t j = 0;
    while ((j < startCol)) {
        write(1, " ", 1);
        (j = (j + 1));
    }
    if ((spanLen <= 1)) {
        write(1, "^", 1);
    } else {
        {
            uint32_t k = 0;
            uint32_t mid = (spanLen / 2);
            while ((k < spanLen)) {
                if ((k == mid)) {
                    write(1, "+", 1);
                } else {
                    {
                        write(1, "-", 1);
                    }
                }
                (k = (k + 1));
            }
        }
    }
    write(1, "\n", 1);
    printf("       | ");
    (j = 0);
    if ((spanLen > 1)) {
        uint32_t mid2 = (spanLen / 2);
        while ((j < (startCol + mid2))) {
            write(1, " ", 1);
            (j = (j + 1));
        }
    } else {
        {
            while ((j < startCol)) {
                write(1, " ", 1);
                (j = (j + 1));
            }
        }
    }
    printf("`- %s\n", lbl->text);
}



typedef struct SourceMap SourceMap;
typedef struct FileEntry FileEntry;
typedef struct InternEntry InternEntry;
typedef struct SourceLoc SourceLoc;
typedef struct Decl Decl;
typedef struct Lexer Lexer;
typedef struct Label Label;
typedef struct Slice Slice;
typedef struct FlagBranch FlagBranch;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Ast Ast;
typedef struct TypeEntry TypeEntry;
typedef struct Span Span;
typedef struct VariantVariant VariantVariant;
typedef struct EnumVariant EnumVariant;
typedef struct Diagnostic Diagnostic;
typedef struct EscapeResult EscapeResult;
typedef struct TestResult TestResult;
typedef struct NodeId NodeId;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct Expr Expr;
typedef struct Pat Pat;
typedef struct GenericParam GenericParam;
typedef struct TraitBound TraitBound;
typedef struct File File;
typedef struct Node Node;
typedef struct Field Field;
typedef struct Token Token;
typedef struct Param Param;
typedef struct AstContext AstContext;
typedef struct IdentifierTable IdentifierTable;
typedef struct Parser Parser;
typedef struct IdentEntry IdentEntry;
typedef struct SwitchCase SwitchCase;
typedef struct ImportSymbol ImportSymbol;
typedef struct Stmt Stmt;
typedef struct ParserMark ParserMark;
typedef struct Attribute Attribute;
typedef enum ErrorCode ErrorCode;
typedef enum TokenKind TokenKind;


void IdentifierTable_init(IdentifierTable* self, IdentEntry* buf, size_t cap);
size_t IdentifierTable_hash(IdentifierTable* self, uint8_t* name, size_t len);
IdentifierInfo* IdentifierTable_get(IdentifierTable* self, uint8_t* name, size_t len);
void IdentifierTable_addKeyword(IdentifierTable* self, uint8_t* name, size_t len, TokenKind kind);
void IdentifierTable_addKeywords(IdentifierTable* self);

typedef struct IdentEntry {
    IdentifierInfo info;
    _Bool occupied;
} IdentEntry;

typedef struct IdentifierTable {
    IdentEntry* entries;
    size_t capacity;
    size_t count;
} IdentifierTable;

void IdentifierTable_init(IdentifierTable* self, IdentEntry* buf, size_t cap) {
    (self->entries = buf);
    (self->capacity = cap);
    (self->count = 0);
    for (size_t i = 0; (i < cap); ) {
        (self->entries[i].occupied = 0);
    }
}
size_t IdentifierTable_hash(IdentifierTable* self, uint8_t* name, size_t len) {
    size_t h = 14695981039346656037;
    for (size_t i = 0; (i < len); ) {
        (h ^= ((size_t)name[i]));
        (h *= 1099511628211);
    }
    return h;
}
IdentifierInfo* IdentifierTable_get(IdentifierTable* self, uint8_t* name, size_t len) {
    size_t idx = (IdentifierTable_hash(self, name, len) & (self->capacity - 1));
    for (size_t probe = 0; (probe < self->capacity); ) {
        size_t pos = ((idx + probe) & (self->capacity - 1));
        IdentEntry e = self->entries[pos];
        if ((! e.occupied)) {
            (e.info.name = name);
            (e.info.nameLen = len);
            (e.info.kind = TokenKind_Ident);
            (e.info.isKeyword = 0);
            (e.occupied = 1);
            (self->entries[pos] = e);
            (self->count++);
            return (& e.info);
        }
        if ((e.info.nameLen == len)) {
            _Bool match = 1;
            for (size_t i = 0; (i < len); ) {
                if ((e.info.name[i] != name[i])) {
                    (match = 0);
                    break;
                }
            }
            if (match) {
                return (& e.info);
            }
        }
    }
    return NULL;
}
void IdentifierTable_addKeyword(IdentifierTable* self, uint8_t* name, size_t len, TokenKind kind) {
    IdentifierInfo* info = IdentifierTable_get(self, name, len);
    if ((info != NULL)) {
        (info->kind = kind);
        (info->isKeyword = 1);
    }
}
void IdentifierTable_addKeywords(IdentifierTable* self) {
    IdentifierTable_addKeyword(self, "if", 2, TokenKind_If);
    IdentifierTable_addKeyword(self, "as", 2, TokenKind_As);
    IdentifierTable_addKeyword(self, "in", 2, TokenKind_In);
    IdentifierTable_addKeyword(self, "mod", 3, TokenKind_Mod);
    IdentifierTable_addKeyword(self, "pub", 3, TokenKind_Pub);
    IdentifierTable_addKeyword(self, "for", 3, TokenKind_For);
    IdentifierTable_addKeyword(self, "asm", 3, TokenKind_Asm);
    IdentifierTable_addKeyword(self, "var", 3, TokenKind_Var);
    IdentifierTable_addKeyword(self, "enum", 4, TokenKind_Enum);
    IdentifierTable_addKeyword(self, "else", 4, TokenKind_Else);
    IdentifierTable_addKeyword(self, "loop", 4, TokenKind_Loop);
    IdentifierTable_addKeyword(self, "flag", 4, TokenKind_Flag);
    IdentifierTable_addKeyword(self, "true", 4, TokenKind_True);
    IdentifierTable_addKeyword(self, "null", 4, TokenKind_Null);
    IdentifierTable_addKeyword(self, "self", 4, TokenKind_Self);
    IdentifierTable_addKeyword(self, "while", 5, TokenKind_While);
    IdentifierTable_addKeyword(self, "trait", 5, TokenKind_Trait);
    IdentifierTable_addKeyword(self, "const", 5, TokenKind_Const);
    IdentifierTable_addKeyword(self, "defer", 5, TokenKind_Defer);
    IdentifierTable_addKeyword(self, "break", 5, TokenKind_Break);
    IdentifierTable_addKeyword(self, "union", 5, TokenKind_Union);
    IdentifierTable_addKeyword(self, "import", 6, TokenKind_Import);
    IdentifierTable_addKeyword(self, "static", 6, TokenKind_Static);
    IdentifierTable_addKeyword(self, "struct", 6, TokenKind_Struct);
    IdentifierTable_addKeyword(self, "extern", 6, TokenKind_Extern);
    IdentifierTable_addKeyword(self, "switch", 6, TokenKind_Switch);
    IdentifierTable_addKeyword(self, "return", 6, TokenKind_Return);
    IdentifierTable_addKeyword(self, "extend", 6, TokenKind_Extend);
    IdentifierTable_addKeyword(self, "typedef", 7, TokenKind_Typedef);
    IdentifierTable_addKeyword(self, "variant", 7, TokenKind_Variant);
    IdentifierTable_addKeyword(self, "distinct", 8, TokenKind_Distinct);
    IdentifierTable_addKeyword(self, "continue", 8, TokenKind_Continue);
    IdentifierTable_addKeyword(self, "comptime", 8, TokenKind_Comptime);
    IdentifierTable_addKeyword(self, "volatile", 8, TokenKind_Volatile);
    IdentifierTable_addKeyword(self, "false", 5, TokenKind_False);
    IdentifierTable_addKeyword(self, "void", 4, TokenKind_Void);
    IdentifierTable_addKeyword(self, "bool", 4, TokenKind_Bool);
    IdentifierTable_addKeyword(self, "char", 4, TokenKind_Char);
    IdentifierTable_addKeyword(self, "u8", 2, TokenKind_U8);
    IdentifierTable_addKeyword(self, "u16", 3, TokenKind_U16);
    IdentifierTable_addKeyword(self, "u32", 3, TokenKind_U32);
    IdentifierTable_addKeyword(self, "u64", 3, TokenKind_U64);
    IdentifierTable_addKeyword(self, "u128", 4, TokenKind_U128);
    IdentifierTable_addKeyword(self, "i8", 2, TokenKind_I8);
    IdentifierTable_addKeyword(self, "i16", 3, TokenKind_I16);
    IdentifierTable_addKeyword(self, "i32", 3, TokenKind_I32);
    IdentifierTable_addKeyword(self, "i64", 3, TokenKind_I64);
    IdentifierTable_addKeyword(self, "i128", 4, TokenKind_I128);
    IdentifierTable_addKeyword(self, "f32", 3, TokenKind_F32);
    IdentifierTable_addKeyword(self, "f64", 3, TokenKind_F64);
    IdentifierTable_addKeyword(self, "usize", 5, TokenKind_Usize);
    IdentifierTable_addKeyword(self, "isize", 5, TokenKind_Isize);
    IdentifierTable_addKeyword(self, "rawptr", 6, TokenKind_Rawptr);
    IdentifierTable_addKeyword(self, "str", 3, TokenKind_Str);
}



typedef struct SourceMap SourceMap;
typedef struct FileEntry FileEntry;
typedef struct InternEntry InternEntry;
typedef struct SourceLoc SourceLoc;
typedef struct Decl Decl;
typedef struct Lexer Lexer;
typedef struct Label Label;
typedef struct Slice Slice;
typedef struct FlagBranch FlagBranch;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Ast Ast;
typedef struct TypeEntry TypeEntry;
typedef struct Span Span;
typedef struct VariantVariant VariantVariant;
typedef struct EnumVariant EnumVariant;
typedef struct Diagnostic Diagnostic;
typedef struct EscapeResult EscapeResult;
typedef struct TestResult TestResult;
typedef struct NodeId NodeId;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct Expr Expr;
typedef struct Pat Pat;
typedef struct GenericParam GenericParam;
typedef struct TraitBound TraitBound;
typedef struct File File;
typedef struct Node Node;
typedef struct Field Field;
typedef struct Token Token;
typedef struct Param Param;
typedef struct AstContext AstContext;
typedef struct IdentifierTable IdentifierTable;
typedef struct Parser Parser;
typedef struct IdentEntry IdentEntry;
typedef struct SwitchCase SwitchCase;
typedef struct ImportSymbol ImportSymbol;
typedef struct Stmt Stmt;
typedef struct ParserMark ParserMark;
typedef struct Attribute Attribute;
typedef enum ErrorCode ErrorCode;
typedef enum TokenKind TokenKind;


void Lexer_init(Lexer* self, Slice src, DiagnosticEngine* diag, IdentifierTable* idents);
_Bool Lexer_isAtEnd(Lexer* self);
uint8_t* Lexer_getCur(Lexer* self);
void Lexer_setCur(Lexer* self, uint8_t* c);
uint8_t* Lexer_getLineStart(Lexer* self);
void Lexer_setLineStart(Lexer* self, uint8_t* c);
uint32_t Lexer_getLine(Lexer* self);
void Lexer_setLine(Lexer* self, uint32_t l);
Token Lexer_getToken(Lexer* self);
void Lexer_setToken(Lexer* self, Token t);
Token Lexer_makeToken(Lexer* self, TokenKind kind, uint8_t* start);

typedef struct Lexer {
    DiagnosticEngine* diag;
    IdentifierTable* idents;
    size_t line;
    uint8_t* bufStart;
    uint8_t* bufEnd;
    uint8_t* cur;
    uint8_t* lineStart;
    Token token;
} Lexer;

void Lexer_init(Lexer* self, Slice src, DiagnosticEngine* diag, IdentifierTable* idents) {
    (self->bufStart = src.ptr);
    (self->cur = src.ptr);
    (self->bufEnd = ((uint8_t*)(((size_t)src.ptr) + src.len)));
    (self->line = 1);
    (self->lineStart = src.ptr);
    (self->diag = diag);
    (self->idents = idents);
}
_Bool Lexer_isAtEnd(Lexer* self) {
    return (self->cur >= self->bufEnd);
}
uint8_t* Lexer_getCur(Lexer* self) {
    return self->cur;
}
void Lexer_setCur(Lexer* self, uint8_t* c) {
    (self->cur = c);
}
uint8_t* Lexer_getLineStart(Lexer* self) {
    return self->lineStart;
}
void Lexer_setLineStart(Lexer* self, uint8_t* c) {
    (self->lineStart = c);
}
uint32_t Lexer_getLine(Lexer* self) {
    return self->line;
}
void Lexer_setLine(Lexer* self, uint32_t l) {
    (self->line = l);
}
Token Lexer_getToken(Lexer* self) {
    return self->token;
}
void Lexer_setToken(Lexer* self, Token t) {
    (self->token = t);
}
Token Lexer_makeToken(Lexer* self, TokenKind kind, uint8_t* start) {
    Token t;
    (t.kind = kind);
    (t.data.ptr = start);
    (t.data.len = ((size_t)(self->cur - start)));
    (t.line = self->line);
    (t.col = (((size_t)(start - self->lineStart)) + 1));
    (t.info = NULL);
    return t;
}



typedef struct SourceMap SourceMap;
typedef struct FileEntry FileEntry;
typedef struct InternEntry InternEntry;
typedef struct SourceLoc SourceLoc;
typedef struct Decl Decl;
typedef struct Lexer Lexer;
typedef struct Label Label;
typedef struct Slice Slice;
typedef struct FlagBranch FlagBranch;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Ast Ast;
typedef struct TypeEntry TypeEntry;
typedef struct Span Span;
typedef struct VariantVariant VariantVariant;
typedef struct EnumVariant EnumVariant;
typedef struct Diagnostic Diagnostic;
typedef struct EscapeResult EscapeResult;
typedef struct TestResult TestResult;
typedef struct NodeId NodeId;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct Expr Expr;
typedef struct Pat Pat;
typedef struct GenericParam GenericParam;
typedef struct TraitBound TraitBound;
typedef struct File File;
typedef struct Node Node;
typedef struct Field Field;
typedef struct Token Token;
typedef struct Param Param;
typedef struct AstContext AstContext;
typedef struct IdentifierTable IdentifierTable;
typedef struct Parser Parser;
typedef struct IdentEntry IdentEntry;
typedef struct SwitchCase SwitchCase;
typedef struct ImportSymbol ImportSymbol;
typedef struct Stmt Stmt;
typedef struct ParserMark ParserMark;
typedef struct Attribute Attribute;
typedef enum ErrorCode ErrorCode;
typedef enum TokenKind TokenKind;


uint32_t decodeUtf8(uint8_t* buf, uint8_t* bufEnd, size_t* outLen);
_Bool isXidStart(uint32_t cp);
_Bool isXidContinue(uint32_t cp);
Token Lexer_lexIdentifier(Lexer* self, uint8_t* start);

/* pub */ uint32_t decodeUtf8(uint8_t* buf, uint8_t* bufEnd, size_t* outLen) {
    if ((buf >= bufEnd)) {
        (outLen[0] = 0);
        return 0;
    }
    uint8_t b0 = buf[0];
    if ((b0 < 0x80)) {
        (outLen[0] = 1);
        return ((uint32_t)b0);
    }
    if ((b0 < 0xC0)) {
        (outLen[0] = 0);
        return 0;
    }
    if ((b0 < 0xE0)) {
        if (((buf + 1) >= bufEnd)) {
            (outLen[0] = 0);
            return 0;
        }
        uint8_t b1 = buf[1];
        if (((b1 & 0xC0) != 0x80)) {
            (outLen[0] = 0);
            return 0;
        }
        (outLen[0] = 2);
        return ((((uint32_t)(b0 & 0x1F)) << 6) | ((uint32_t)(b1 & 0x3F)));
    }
    if ((b0 < 0xF0)) {
        if (((buf + 2) >= bufEnd)) {
            (outLen[0] = 0);
            return 0;
        }
        uint8_t b1 = buf[1];
        uint8_t b2 = buf[2];
        if ((((b1 & 0xC0) != 0x80) || ((b2 & 0xC0) != 0x80))) {
            (outLen[0] = 0);
            return 0;
        }
        (outLen[0] = 3);
        return (((((uint32_t)(b0 & 0x0F)) << 12) | (((uint32_t)(b1 & 0x3F)) << 6)) | ((uint32_t)(b2 & 0x3F)));
    }
    if ((b0 < 0xF8)) {
        if (((buf + 3) >= bufEnd)) {
            (outLen[0] = 0);
            return 0;
        }
        uint8_t b1 = buf[1];
        uint8_t b2 = buf[2];
        uint8_t b3 = buf[3];
        if (((((b1 & 0xC0) != 0x80) || ((b2 & 0xC0) != 0x80)) || ((b3 & 0xC0) != 0x80))) {
            (outLen[0] = 0);
            return 0;
        }
        (outLen[0] = 4);
        return ((((((uint32_t)(b0 & 0x07)) << 18) | (((uint32_t)(b1 & 0x3F)) << 12)) | (((uint32_t)(b2 & 0x3F)) << 6)) | ((uint32_t)(b3 & 0x3F)));
    }
    (outLen[0] = 0);
    return 0;
}
/* pub */ _Bool isXidStart(uint32_t cp) {
    if ((cp < 128)) {
        return ((((cp | 0x20) >= 'a') && ((cp | 0x20) <= 'z')) || (cp == '_'));
    }
    if (((cp >= 0x00C0) && (cp <= 0x06FF))) {
        return 1;
    }
    if (((cp >= 0x0700) && (cp <= 0x07BF))) {
        return 1;
    }
    if (((cp >= 0x0900) && (cp <= 0x0D7F))) {
        return 1;
    }
    if (((cp >= 0x0E00) && (cp <= 0x0EFF))) {
        return 1;
    }
    if (((cp >= 0x1000) && (cp <= 0x137F))) {
        return 1;
    }
    if (((cp >= 0x13A0) && (cp <= 0x13FF))) {
        return 1;
    }
    if (((cp >= 0x1400) && (cp <= 0x16FF))) {
        return 1;
    }
    if (((cp >= 0x1700) && (cp <= 0x18AF))) {
        return 1;
    }
    if (((cp >= 0x1900) && (cp <= 0x1A1F))) {
        return 1;
    }
    if (((cp >= 0x1B00) && (cp <= 0x1C7F))) {
        return 1;
    }
    if (((cp >= 0x1D00) && (cp <= 0x1FFF))) {
        return 1;
    }
    if (((cp >= 0x2E80) && (cp <= 0x31BF))) {
        return 1;
    }
    if (((cp >= 0x3200) && (cp <= 0x9FFF))) {
        return 1;
    }
    if (((cp >= 0xA000) && (cp <= 0xA7FF))) {
        return 1;
    }
    if (((cp >= 0xA800) && (cp <= 0xA95F))) {
        return 1;
    }
    if (((cp >= 0xA960) && (cp <= 0xAA7F))) {
        return 1;
    }
    if (((cp >= 0xAA80) && (cp <= 0xABBF))) {
        return 1;
    }
    if (((cp >= 0xABC0) && (cp <= 0xD7FF))) {
        return 1;
    }
    if (((cp >= 0xF900) && (cp <= 0xFDFF))) {
        return 1;
    }
    if (((cp >= 0xFE30) && (cp <= 0xFE6F))) {
        return 1;
    }
    if (((cp >= 0xFF00) && (cp <= 0xFFEF))) {
        return 1;
    }
    if (((cp >= 0x10000) && (cp <= 0x101FF))) {
        return 1;
    }
    if (((cp >= 0x10200) && (cp <= 0x103FF))) {
        return 1;
    }
    if (((cp >= 0x10400) && (cp <= 0x105BF))) {
        return 1;
    }
    if (((cp >= 0x10600) && (cp <= 0x108AF))) {
        return 1;
    }
    if (((cp >= 0x108E0) && (cp <= 0x109FF))) {
        return 1;
    }
    if (((cp >= 0x10A00) && (cp <= 0x10BAF))) {
        return 1;
    }
    if (((cp >= 0x10C00) && (cp <= 0x10D3F))) {
        return 1;
    }
    if (((cp >= 0x10E60) && (cp <= 0x10FAF))) {
        return 1;
    }
    if (((cp >= 0x10FB0) && (cp <= 0x1117F))) {
        return 1;
    }
    if (((cp >= 0x11180) && (cp <= 0x1137F))) {
        return 1;
    }
    if (((cp >= 0x11380) && (cp <= 0x1173F))) {
        return 1;
    }
    if (((cp >= 0x11800) && (cp <= 0x11AAF))) {
        return 1;
    }
    if (((cp >= 0x11AB0) && (cp <= 0x11CBF))) {
        return 1;
    }
    if (((cp >= 0x11D00) && (cp <= 0x11EFF))) {
        return 1;
    }
    if (((cp >= 0x11F00) && (cp <= 0x11FAF))) {
        return 1;
    }
    return 0;
}
/* pub */ _Bool isXidContinue(uint32_t cp) {
    if (isXidStart(cp)) {
        return 1;
    }
    if ((cp < 128)) {
        return ((cp >= '0') && (cp <= '9'));
    }
    if (((cp >= 0x0300) && (cp <= 0x036F))) {
        return 1;
    }
    if (((cp >= 0x1AB0) && (cp <= 0x1AFF))) {
        return 1;
    }
    if (((cp >= 0x1DC0) && (cp <= 0x1DFF))) {
        return 1;
    }
    if (((cp >= 0xFE20) && (cp <= 0xFE2F))) {
        return 1;
    }
    if (((cp >= 0xFE00) && (cp <= 0xFE0F))) {
        return 1;
    }
    if (((cp >= 0xFE10) && (cp <= 0xFE1F))) {
        return 1;
    }
    if (((cp >= 0x20DD) && (cp <= 0x20E0))) {
        return 1;
    }
    return 0;
}
Token Lexer_lexIdentifier(Lexer* self, uint8_t* start) {
    while ((! Lexer_isAtEnd(self))) {
        size_t len;
        uint32_t cp = decodeUtf8(self->cur, self->bufEnd, (& len));
        if (((len == 0) || (! isXidContinue(cp)))) {
            break;
        }
        (self->cur += len);
    }
    size_t len = ((size_t)(self->cur - start));
    if ((self->idents == NULL)) {
        Token t = Lexer_makeToken(self, TokenKind_Ident, start);
        return t;
    }
    IdentifierInfo* ii = IdentifierTable_get(self->idents, start, len);
    Token t = Lexer_makeToken(self, ii->kind, start);
    (t.info = ii);
    return t;
}



typedef struct SourceMap SourceMap;
typedef struct FileEntry FileEntry;
typedef struct InternEntry InternEntry;
typedef struct SourceLoc SourceLoc;
typedef struct Decl Decl;
typedef struct Lexer Lexer;
typedef struct Label Label;
typedef struct Slice Slice;
typedef struct FlagBranch FlagBranch;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Ast Ast;
typedef struct TypeEntry TypeEntry;
typedef struct Span Span;
typedef struct VariantVariant VariantVariant;
typedef struct EnumVariant EnumVariant;
typedef struct Diagnostic Diagnostic;
typedef struct EscapeResult EscapeResult;
typedef struct TestResult TestResult;
typedef struct NodeId NodeId;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct Expr Expr;
typedef struct Pat Pat;
typedef struct GenericParam GenericParam;
typedef struct TraitBound TraitBound;
typedef struct File File;
typedef struct Node Node;
typedef struct Field Field;
typedef struct Token Token;
typedef struct Param Param;
typedef struct AstContext AstContext;
typedef struct IdentifierTable IdentifierTable;
typedef struct Parser Parser;
typedef struct IdentEntry IdentEntry;
typedef struct SwitchCase SwitchCase;
typedef struct ImportSymbol ImportSymbol;
typedef struct Stmt Stmt;
typedef struct ParserMark ParserMark;
typedef struct Attribute Attribute;
typedef enum ErrorCode ErrorCode;
typedef enum TokenKind TokenKind;


EscapeResult EscapeResult_decodeEscapeSequence(uint8_t* ptr, uint8_t* end);

typedef struct EscapeResult {
    uint32_t codepoint;
    size_t bytesConsumed;
    _Bool isValid;
} EscapeResult;

EscapeResult EscapeResult_decodeEscapeSequence(uint8_t* ptr, uint8_t* end) {
    EscapeResult esc;
    (esc.isValid = 1);
    (esc.bytesConsumed = 2);
    (esc.codepoint = 0);
    if (((ptr >= end) || (ptr[0] != '\\'))) {
        (esc.isValid = 0);
        return esc;
    }
    if (((ptr + 1) >= end)) {
        (esc.isValid = 0);
        return esc;
    }
    uint8_t next = ptr[1];
    switch (next) {
        case 'n':
            (esc.codepoint = '\n');
            break;
        case 'r':
            (esc.codepoint = '\r');
            break;
        case 't':
            (esc.codepoint = '\t');
            break;
        case '\\':
            (esc.codepoint = '\\');
            break;
        case '\'':
            (esc.codepoint = '\'');
            break;
        case '"':
            (esc.codepoint = '"');
            break;
        case '0':
            (esc.codepoint = '\0');
            break;
        case 'x':
            if (((ptr + 4) > end)) {
                (esc.isValid = 0);
            } else {
                {
                    uint8_t h1 = ptr[2];
                    uint8_t h2 = ptr[3];
                    if (((! (((h1 >= '0') && (h1 <= '9')) || (((h1 | 0x20) >= 'a') && ((h1 | 0x20) <= 'f')))) || (! (((h2 >= '0') && (h2 <= '9')) || (((h2 | 0x20) >= 'a') && ((h2 | 0x20) <= 'f')))))) {
                        (esc.isValid = 0);
                    } else {
                        {
                            uint8_t hi = ((h1 >= 'a') ? ((h1 - 'a') + 10) : ((h1 >= 'A') ? ((h1 - 'A') + 10) : (h1 - '0')));
                            uint8_t lo = ((h2 >= 'a') ? ((h2 - 'a') + 10) : ((h2 >= 'A') ? ((h2 - 'A') + 10) : (h2 - '0')));
                            (esc.codepoint = ((uint32_t)((hi << 4) | lo)));
                            (esc.bytesConsumed = 4);
                        }
                    }
                }
            }
            break;
        case 'u':
            if (((ptr + 6) > end)) {
                (esc.isValid = 0);
            } else {
                {
                    uint32_t cp = 0;
                    _Bool valid = 1;
                    for (size_t i = 0; (i < 4); ) {
                        uint8_t h = ptr[(2 + i)];
                        uint8_t val;
                        if (((h >= '0') && (h <= '9'))) {
                            (val = (h - '0'));
                        } else {
                            if ((((h | 0x20) >= 'a') && ((h | 0x20) <= 'f'))) {
                                (val = (((h | 0x20) - 'a') + 10));
                            } else {
                                {
                                    (valid = 0);
                                    break;
                                }
                            }
                        }
                        (cp = ((cp << 4) | val));
                    }
                    if ((! valid)) {
                        (esc.isValid = 0);
                    } else {
                        {
                            (esc.codepoint = cp);
                            (esc.bytesConsumed = 6);
                        }
                    }
                }
            }
            break;
        case 'U':
            if (((ptr + 10) > end)) {
                (esc.isValid = 0);
            } else {
                {
                    uint32_t cp = 0;
                    _Bool valid = 1;
                    for (size_t i = 0; (i < 8); ) {
                        uint8_t h = ptr[(2 + i)];
                        uint8_t val;
                        if (((h >= '0') && (h <= '9'))) {
                            (val = (h - '0'));
                        } else {
                            if ((((h | 0x20) >= 'a') && ((h | 0x20) <= 'f'))) {
                                (val = (((h | 0x20) - 'a') + 10));
                            } else {
                                {
                                    (valid = 0);
                                    break;
                                }
                            }
                        }
                        (cp = ((cp << 4) | val));
                    }
                    if ((! valid)) {
                        (esc.isValid = 0);
                    } else {
                        {
                            (esc.codepoint = cp);
                            (esc.bytesConsumed = 10);
                        }
                    }
                }
            }
            break;
        default:
            (esc.isValid = 0);
            (esc.codepoint = next);
            break;
    }
    return esc;
}



typedef struct SourceMap SourceMap;
typedef struct FileEntry FileEntry;
typedef struct InternEntry InternEntry;
typedef struct SourceLoc SourceLoc;
typedef struct Decl Decl;
typedef struct Lexer Lexer;
typedef struct Label Label;
typedef struct Slice Slice;
typedef struct FlagBranch FlagBranch;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Ast Ast;
typedef struct TypeEntry TypeEntry;
typedef struct Span Span;
typedef struct VariantVariant VariantVariant;
typedef struct EnumVariant EnumVariant;
typedef struct Diagnostic Diagnostic;
typedef struct EscapeResult EscapeResult;
typedef struct TestResult TestResult;
typedef struct NodeId NodeId;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct Expr Expr;
typedef struct Pat Pat;
typedef struct GenericParam GenericParam;
typedef struct TraitBound TraitBound;
typedef struct File File;
typedef struct Node Node;
typedef struct Field Field;
typedef struct Token Token;
typedef struct Param Param;
typedef struct AstContext AstContext;
typedef struct IdentifierTable IdentifierTable;
typedef struct Parser Parser;
typedef struct IdentEntry IdentEntry;
typedef struct SwitchCase SwitchCase;
typedef struct ImportSymbol ImportSymbol;
typedef struct Stmt Stmt;
typedef struct ParserMark ParserMark;
typedef struct Attribute Attribute;
typedef enum ErrorCode ErrorCode;
typedef enum TokenKind TokenKind;


void Lexer_skipWsCmts(Lexer* self);

void Lexer_skipWsCmts(Lexer* self) {
    while ((! Lexer_isAtEnd(self))) {
        uint8_t c = self->cur[0];
        switch (c) {
                        case ' ':
            case '\r':
            case '\t':
                (self->cur++);
                break;
            case '\n':
                (self->line++);
                (self->cur++);
                (self->lineStart = self->cur);
                break;
            case '/':
                if ((((self->cur + 1) < self->bufEnd) && (self->cur[1] == '/'))) {
                    (self->cur += 2);
                    while (((! Lexer_isAtEnd(self)) && (self->cur[0] != '\n'))) {
                        (self->cur++);
                    }
                } else {
                    if ((((self->cur + 1) < self->bufEnd) && (self->cur[1] == '*'))) {
                        (self->cur += 2);
                        while ((! Lexer_isAtEnd(self))) {
                            if ((self->cur[0] == '\n')) {
                                (self->line++);
                                (self->cur++);
                                (self->lineStart = self->cur);
                            } else {
                                if ((((self->cur[0] == '*') && ((self->cur + 1) < self->bufEnd)) && (self->cur[1] == '/'))) {
                                    (self->cur += 2);
                                    break;
                                } else {
                                    {
                                        (self->cur++);
                                    }
                                }
                            }
                        }
                    } else {
                        {
                            return;
                        }
                    }
                }
                break;
            default:
                return;
                break;
        }
    }
}



typedef struct SourceMap SourceMap;
typedef struct FileEntry FileEntry;
typedef struct InternEntry InternEntry;
typedef struct SourceLoc SourceLoc;
typedef struct Decl Decl;
typedef struct Lexer Lexer;
typedef struct Label Label;
typedef struct Slice Slice;
typedef struct FlagBranch FlagBranch;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Ast Ast;
typedef struct TypeEntry TypeEntry;
typedef struct Span Span;
typedef struct VariantVariant VariantVariant;
typedef struct EnumVariant EnumVariant;
typedef struct Diagnostic Diagnostic;
typedef struct EscapeResult EscapeResult;
typedef struct TestResult TestResult;
typedef struct NodeId NodeId;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct Expr Expr;
typedef struct Pat Pat;
typedef struct GenericParam GenericParam;
typedef struct TraitBound TraitBound;
typedef struct File File;
typedef struct Node Node;
typedef struct Field Field;
typedef struct Token Token;
typedef struct Param Param;
typedef struct AstContext AstContext;
typedef struct IdentifierTable IdentifierTable;
typedef struct Parser Parser;
typedef struct IdentEntry IdentEntry;
typedef struct SwitchCase SwitchCase;
typedef struct ImportSymbol ImportSymbol;
typedef struct Stmt Stmt;
typedef struct ParserMark ParserMark;
typedef struct Attribute Attribute;
typedef enum ErrorCode ErrorCode;
typedef enum TokenKind TokenKind;


Token Lexer_lexNumber(Lexer* self, uint8_t* start);
Token Lexer_lexHex(Lexer* self, uint8_t* start);
Token Lexer_lexBinary(Lexer* self, uint8_t* start);
Token Lexer_lexOctal(Lexer* self, uint8_t* start);
Token Lexer_lexDecimal(Lexer* self, uint8_t* start);

Token Lexer_lexNumber(Lexer* self, uint8_t* start) {
    if (((((! Lexer_isAtEnd(self)) && (self->cur[0] == 'x')) && (((size_t)(self->cur - start)) == 1)) && (start[0] == '0'))) {
        (self->cur++);
        return Lexer_lexHex(self, start);
    }
    if (((((! Lexer_isAtEnd(self)) && (self->cur[0] == 'b')) && (((size_t)(self->cur - start)) == 1)) && (start[0] == '0'))) {
        (self->cur++);
        return Lexer_lexBinary(self, start);
    }
    if (((((! Lexer_isAtEnd(self)) && (self->cur[0] == 'o')) && (((size_t)(self->cur - start)) == 1)) && (start[0] == '0'))) {
        (self->cur++);
        return Lexer_lexOctal(self, start);
    }
    return Lexer_lexDecimal(self, start);
}
Token Lexer_lexHex(Lexer* self, uint8_t* start) {
    if ((Lexer_isAtEnd(self) || (! ((((self->cur[0] >= '0') && (self->cur[0] <= '9')) || ((self->cur[0] >= 'a') && (self->cur[0] <= 'f'))) || ((self->cur[0] >= 'A') && (self->cur[0] <= 'F')))))) {
        DiagnosticEngine_reportError(self->diag, self->bufStart, self->bufEnd, start, "hex literal has no digits");
        return Lexer_makeToken(self, TokenKind_Hex, start);
    }
    while ((! Lexer_isAtEnd(self))) {
        uint8_t c = self->cur[0];
        if ((((((c >= '0') && (c <= '9')) || ((c >= 'a') && (c <= 'f'))) || ((c >= 'A') && (c <= 'F'))) || (c == '_'))) {
            (self->cur++);
        } else {
            {
                break;
            }
        }
    }
    return Lexer_makeToken(self, TokenKind_Hex, start);
}
Token Lexer_lexBinary(Lexer* self, uint8_t* start) {
    if ((Lexer_isAtEnd(self) || ((self->cur[0] != '0') && (self->cur[0] != '1')))) {
        DiagnosticEngine_reportError(self->diag, self->bufStart, self->bufEnd, start, "binary literal has no digits");
        return Lexer_makeToken(self, TokenKind_Bin, start);
    }
    while ((! Lexer_isAtEnd(self))) {
        uint8_t c = self->cur[0];
        if ((((c == '0') || (c == '1')) || (c == '_'))) {
            (self->cur++);
        } else {
            {
                break;
            }
        }
    }
    return Lexer_makeToken(self, TokenKind_Bin, start);
}
Token Lexer_lexOctal(Lexer* self, uint8_t* start) {
    if (((Lexer_isAtEnd(self) || (self->cur[0] < '0')) || (self->cur[0] > '7'))) {
        DiagnosticEngine_reportError(self->diag, self->bufStart, self->bufEnd, start, "octal literal has no digits");
        return Lexer_makeToken(self, TokenKind_Oct, start);
    }
    while ((! Lexer_isAtEnd(self))) {
        uint8_t c = self->cur[0];
        if ((((c >= '0') && (c <= '7')) || (c == '_'))) {
            (self->cur++);
        } else {
            {
                break;
            }
        }
    }
    return Lexer_makeToken(self, TokenKind_Oct, start);
}
Token Lexer_lexDecimal(Lexer* self, uint8_t* start) {
    _Bool isFloat = 0;
    while ((! Lexer_isAtEnd(self))) {
        uint8_t c = self->cur[0];
        if (((c >= '0') && (c <= '9'))) {
            (self->cur++);
        } else {
            if (((c == '.') && (! isFloat))) {
                if ((((self->cur + 1) < self->bufEnd) && (self->cur[1] == '.'))) {
                    break;
                }
                (isFloat = 1);
                (self->cur++);
            } else {
                if ((((c == 'e') || (c == 'E')) && (! isFloat))) {
                    (isFloat = 1);
                    (self->cur++);
                    if (((! Lexer_isAtEnd(self)) && ((self->cur[0] == '+') || (self->cur[0] == '-')))) {
                        (self->cur++);
                    }
                } else {
                    if ((c == '_')) {
                        (self->cur++);
                    } else {
                        {
                            break;
                        }
                    }
                }
            }
        }
    }
    if (isFloat) {
        return Lexer_makeToken(self, TokenKind_Float, start);
    }
    return Lexer_makeToken(self, TokenKind_Dec, start);
}



typedef struct SourceMap SourceMap;
typedef struct FileEntry FileEntry;
typedef struct InternEntry InternEntry;
typedef struct SourceLoc SourceLoc;
typedef struct Decl Decl;
typedef struct Lexer Lexer;
typedef struct Label Label;
typedef struct Slice Slice;
typedef struct FlagBranch FlagBranch;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Ast Ast;
typedef struct TypeEntry TypeEntry;
typedef struct Span Span;
typedef struct VariantVariant VariantVariant;
typedef struct EnumVariant EnumVariant;
typedef struct Diagnostic Diagnostic;
typedef struct EscapeResult EscapeResult;
typedef struct TestResult TestResult;
typedef struct NodeId NodeId;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct Expr Expr;
typedef struct Pat Pat;
typedef struct GenericParam GenericParam;
typedef struct TraitBound TraitBound;
typedef struct File File;
typedef struct Node Node;
typedef struct Field Field;
typedef struct Token Token;
typedef struct Param Param;
typedef struct AstContext AstContext;
typedef struct IdentifierTable IdentifierTable;
typedef struct Parser Parser;
typedef struct IdentEntry IdentEntry;
typedef struct SwitchCase SwitchCase;
typedef struct ImportSymbol ImportSymbol;
typedef struct Stmt Stmt;
typedef struct ParserMark ParserMark;
typedef struct Attribute Attribute;
typedef enum ErrorCode ErrorCode;
typedef enum TokenKind TokenKind;


Token Lexer_lexString(Lexer* self, uint8_t* start);
Token Lexer_lexRawString(Lexer* self, uint8_t* start);

Token Lexer_lexString(Lexer* self, uint8_t* start) {
    while ((! Lexer_isAtEnd(self))) {
        uint8_t c = self->cur[0];
        if ((c == '\"')) {
            (self->cur++);
            return Lexer_makeToken(self, TokenKind_String, start);
        }
        if ((c == '\\')) {
            EscapeResult esc = EscapeResult_decodeEscapeSequence(self->cur, self->bufEnd);
            if ((! esc.isValid)) {
                DiagnosticEngine_reportError(self->diag, self->bufStart, self->bufEnd, self->cur, "unknown escape sequence");
            }
            (self->cur += esc.bytesConsumed);
            continue;
        }
        if ((c == '\n')) {
            (self->line++);
            (self->lineStart = (self->cur + 1));
        }
        (self->cur++);
    }
    DiagnosticEngine_reportError(self->diag, self->bufStart, self->bufEnd, start, "unterminated string literal");
    return Lexer_makeToken(self, TokenKind_Eof, start);
}
Token Lexer_lexRawString(Lexer* self, uint8_t* start) {
    if ((Lexer_isAtEnd(self) || (self->cur[0] != '"'))) {
        DiagnosticEngine_reportError(self->diag, self->bufStart, self->bufEnd, start, "expected '\"' after R for raw string");
        return Lexer_makeToken(self, TokenKind_Eof, start);
    }
    (self->cur++);
    uint8_t* delimStart = self->cur;
    while (((! Lexer_isAtEnd(self)) && (self->cur[0] != '('))) {
        (self->cur++);
    }
    size_t delimLen = ((size_t)(self->cur - delimStart));
    if ((Lexer_isAtEnd(self) || (self->cur[0] != '('))) {
        DiagnosticEngine_reportError(self->diag, self->bufStart, self->bufEnd, start, "expected '(' in raw string delimiter");
        return Lexer_makeToken(self, TokenKind_Eof, start);
    }
    (self->cur++);
    while ((! Lexer_isAtEnd(self))) {
        uint8_t c = self->cur[0];
        if ((c == '\n')) {
            (self->line++);
            (self->lineStart = (self->cur + 1));
        }
        if ((c == ')')) {
            _Bool match = 1;
            for (size_t i = 0; (i < delimLen); ) {
                size_t idx = ((size_t)(((self->cur + 1) + i) - self->bufStart));
                if ((idx >= ((size_t)(self->bufEnd - self->bufStart)))) {
                    (match = 0);
                    break;
                }
                if ((self->bufStart[idx] != delimStart[i])) {
                    (match = 0);
                    break;
                }
            }
            if (match) {
                size_t quoteIdx = ((size_t)(((self->cur + 1) + delimLen) - self->bufStart));
                if (((quoteIdx < ((size_t)(self->bufEnd - self->bufStart))) && (self->bufStart[quoteIdx] == '"'))) {
                    (self->cur = ((uint8_t*)((self->bufStart + quoteIdx) + 1)));
                    return Lexer_makeToken(self, TokenKind_RawString, start);
                }
            }
        }
        (self->cur++);
    }
    DiagnosticEngine_reportError(self->diag, self->bufStart, self->bufEnd, start, "unterminated raw string literal");
    return Lexer_makeToken(self, TokenKind_Eof, start);
}



typedef struct SourceMap SourceMap;
typedef struct FileEntry FileEntry;
typedef struct InternEntry InternEntry;
typedef struct SourceLoc SourceLoc;
typedef struct Decl Decl;
typedef struct Lexer Lexer;
typedef struct Label Label;
typedef struct Slice Slice;
typedef struct FlagBranch FlagBranch;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Ast Ast;
typedef struct TypeEntry TypeEntry;
typedef struct Span Span;
typedef struct VariantVariant VariantVariant;
typedef struct EnumVariant EnumVariant;
typedef struct Diagnostic Diagnostic;
typedef struct EscapeResult EscapeResult;
typedef struct TestResult TestResult;
typedef struct NodeId NodeId;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct Expr Expr;
typedef struct Pat Pat;
typedef struct GenericParam GenericParam;
typedef struct TraitBound TraitBound;
typedef struct File File;
typedef struct Node Node;
typedef struct Field Field;
typedef struct Token Token;
typedef struct Param Param;
typedef struct AstContext AstContext;
typedef struct IdentifierTable IdentifierTable;
typedef struct Parser Parser;
typedef struct IdentEntry IdentEntry;
typedef struct SwitchCase SwitchCase;
typedef struct ImportSymbol ImportSymbol;
typedef struct Stmt Stmt;
typedef struct ParserMark ParserMark;
typedef struct Attribute Attribute;
typedef enum ErrorCode ErrorCode;
typedef enum TokenKind TokenKind;


Token Lexer_lexOperator(Lexer* self, uint8_t c, uint8_t* start);
Token Lexer_lexPunctuation(Lexer* self, uint8_t c, uint8_t* start);

Token Lexer_lexOperator(Lexer* self, uint8_t c, uint8_t* start) {
    if ((! Lexer_isAtEnd(self))) {
        uint8_t next = self->cur[0];
        if (((c == '+') && (next == '+'))) {
            (self->cur++);
            return Lexer_makeToken(self, TokenKind_PlusPlus, start);
        }
        if (((c == '-') && (next == '-'))) {
            (self->cur++);
            return Lexer_makeToken(self, TokenKind_MinusMinus, start);
        }
        if (((c == '=') && (next == '='))) {
            (self->cur++);
            return Lexer_makeToken(self, TokenKind_EqualEqual, start);
        }
        if (((c == '!') && (next == '='))) {
            (self->cur++);
            return Lexer_makeToken(self, TokenKind_NotEqual, start);
        }
        if (((c == '<') && (next == '='))) {
            (self->cur++);
            return Lexer_makeToken(self, TokenKind_LessEqual, start);
        }
        if (((c == '>') && (next == '='))) {
            (self->cur++);
            return Lexer_makeToken(self, TokenKind_GreaterEqual, start);
        }
        if (((c == '&') && (next == '&'))) {
            (self->cur++);
            return Lexer_makeToken(self, TokenKind_And, start);
        }
        if (((c == '|') && (next == '|'))) {
            (self->cur++);
            return Lexer_makeToken(self, TokenKind_Or, start);
        }
        if (((c == '+') && (next == '='))) {
            (self->cur++);
            return Lexer_makeToken(self, TokenKind_PlusEqual, start);
        }
        if (((c == '-') && (next == '='))) {
            (self->cur++);
            return Lexer_makeToken(self, TokenKind_MinusEqual, start);
        }
        if (((c == '*') && (next == '='))) {
            (self->cur++);
            return Lexer_makeToken(self, TokenKind_StarEqual, start);
        }
        if (((c == '/') && (next == '='))) {
            (self->cur++);
            return Lexer_makeToken(self, TokenKind_SlashEqual, start);
        }
        if (((c == '|') && (next == '='))) {
            (self->cur++);
            return Lexer_makeToken(self, TokenKind_PipeEqual, start);
        }
        if (((c == '^') && (next == '='))) {
            (self->cur++);
            return Lexer_makeToken(self, TokenKind_CaretEqual, start);
        }
        if (((c == '&') && (next == '='))) {
            (self->cur++);
            return Lexer_makeToken(self, TokenKind_AmpEqual, start);
        }
        if (((c == '~') && (next == '='))) {
            (self->cur++);
            return Lexer_makeToken(self, TokenKind_NegEqual, start);
        }
        if (((c == '%') && (next == '='))) {
            (self->cur++);
            return Lexer_makeToken(self, TokenKind_PercentEqual, start);
        }
        if (((c == '<') && (next == '<'))) {
            (self->cur++);
            if (((! Lexer_isAtEnd(self)) && (self->cur[0] == '='))) {
                (self->cur++);
                return Lexer_makeToken(self, TokenKind_ShlEqual, start);
            }
            return Lexer_makeToken(self, TokenKind_Shl, start);
        }
        if (((c == '>') && (next == '>'))) {
            (self->cur++);
            if (((! Lexer_isAtEnd(self)) && (self->cur[0] == '='))) {
                (self->cur++);
                return Lexer_makeToken(self, TokenKind_ShrEqual, start);
            }
            return Lexer_makeToken(self, TokenKind_Shr, start);
        }
        if (((c == '-') && (next == '>'))) {
            (self->cur++);
            return Lexer_makeToken(self, TokenKind_Arrow, start);
        }
        if (((c == '[') && (next == '['))) {
            (self->cur++);
            return Lexer_makeToken(self, TokenKind_AttrOpen, start);
        }
        if (((c == ']') && (next == ']'))) {
            (self->cur++);
            return Lexer_makeToken(self, TokenKind_AttrClose, start);
        }
        if (((c == '=') && (next == '>'))) {
            (self->cur++);
            return Lexer_makeToken(self, TokenKind_FatArrow, start);
        }
        if (((c == ':') && (next == ':'))) {
            (self->cur++);
            return Lexer_makeToken(self, TokenKind_ColonColon, start);
        }
        if (((c == '*') && (next == '.'))) {
            (self->cur++);
            return Lexer_makeToken(self, TokenKind_StarDot, start);
        }
        if (((((c == '.') && (next == '.')) && ((self->cur + 1) < self->bufEnd)) && (self->cur[1] == '.'))) {
            (self->cur += 2);
            return Lexer_makeToken(self, TokenKind_Ellipsis, start);
        }
    }
    return Lexer_lexPunctuation(self, c, start);
}
Token Lexer_lexPunctuation(Lexer* self, uint8_t c, uint8_t* start) {
    switch (c) {
        case '+':
            return Lexer_makeToken(self, TokenKind_Plus, start);
            break;
        case '-':
            return Lexer_makeToken(self, TokenKind_Minus, start);
            break;
        case '*':
            return Lexer_makeToken(self, TokenKind_Star, start);
            break;
        case '/':
            return Lexer_makeToken(self, TokenKind_Slash, start);
            break;
        case '%':
            return Lexer_makeToken(self, TokenKind_Percent, start);
            break;
        case '<':
            return Lexer_makeToken(self, TokenKind_Less, start);
            break;
        case '>':
            return Lexer_makeToken(self, TokenKind_Greater, start);
            break;
        case '~':
            return Lexer_makeToken(self, TokenKind_Neg, start);
            break;
        case '!':
            return Lexer_makeToken(self, TokenKind_Not, start);
            break;
        case ':':
            return Lexer_makeToken(self, TokenKind_Colon, start);
            break;
        case ';':
            return Lexer_makeToken(self, TokenKind_Semicolon, start);
            break;
        case ',':
            return Lexer_makeToken(self, TokenKind_Comma, start);
            break;
        case '#':
            return Lexer_makeToken(self, TokenKind_Hash, start);
            break;
        case '.':
            return Lexer_makeToken(self, TokenKind_Dot, start);
            break;
        case '&':
            return Lexer_makeToken(self, TokenKind_Ampersand, start);
            break;
        case '^':
            return Lexer_makeToken(self, TokenKind_Caret, start);
            break;
        case '|':
            return Lexer_makeToken(self, TokenKind_Pipe, start);
            break;
        case '=':
            return Lexer_makeToken(self, TokenKind_Equal, start);
            break;
        case '(':
            return Lexer_makeToken(self, TokenKind_LParen, start);
            break;
        case ')':
            return Lexer_makeToken(self, TokenKind_RParen, start);
            break;
        case '{':
            return Lexer_makeToken(self, TokenKind_LBrace, start);
            break;
        case '}':
            return Lexer_makeToken(self, TokenKind_RBrace, start);
            break;
        case '[':
            return Lexer_makeToken(self, TokenKind_LBracket, start);
            break;
        case ']':
            return Lexer_makeToken(self, TokenKind_RBracket, start);
            break;
        case '@':
            return Lexer_makeToken(self, TokenKind_At, start);
            break;
        default:
            return Lexer_makeToken(self, TokenKind_Unknown, start);
            break;
    }
}



typedef struct SourceMap SourceMap;
typedef struct FileEntry FileEntry;
typedef struct InternEntry InternEntry;
typedef struct SourceLoc SourceLoc;
typedef struct Decl Decl;
typedef struct Lexer Lexer;
typedef struct Label Label;
typedef struct Slice Slice;
typedef struct FlagBranch FlagBranch;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Ast Ast;
typedef struct TypeEntry TypeEntry;
typedef struct Span Span;
typedef struct VariantVariant VariantVariant;
typedef struct EnumVariant EnumVariant;
typedef struct Diagnostic Diagnostic;
typedef struct EscapeResult EscapeResult;
typedef struct TestResult TestResult;
typedef struct NodeId NodeId;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct Expr Expr;
typedef struct Pat Pat;
typedef struct GenericParam GenericParam;
typedef struct TraitBound TraitBound;
typedef struct File File;
typedef struct Node Node;
typedef struct Field Field;
typedef struct Token Token;
typedef struct Param Param;
typedef struct AstContext AstContext;
typedef struct IdentifierTable IdentifierTable;
typedef struct Parser Parser;
typedef struct IdentEntry IdentEntry;
typedef struct SwitchCase SwitchCase;
typedef struct ImportSymbol ImportSymbol;
typedef struct Stmt Stmt;
typedef struct ParserMark ParserMark;
typedef struct Attribute Attribute;
typedef enum ErrorCode ErrorCode;
typedef enum TokenKind TokenKind;


Token Lexer_nextToken(Lexer* self);

Token Lexer_nextToken(Lexer* self) {
    Lexer_skipWsCmts(self);
    uint8_t* start = self->cur;
    if (Lexer_isAtEnd(self)) {
        return Lexer_makeToken(self, TokenKind_Eof, start);
    }
    uint8_t c = self->cur[0];
    (self->cur++);
    if ((((c == 'R') && (! Lexer_isAtEnd(self))) && (self->cur[0] == '"'))) {
        (self->cur++);
        return Lexer_lexRawString(self, start);
    }
    if ((((((c == 'u') || (c == 'U')) || (c == 'c')) && (! Lexer_isAtEnd(self))) && (self->cur[0] == '"'))) {
        (self->cur++);
        return Lexer_lexString(self, start);
    }
    if ((((((c == 'u') && (! Lexer_isAtEnd(self))) && (self->cur[0] == '8')) && ((self->cur + 1) < self->bufEnd)) && (self->cur[1] == '"'))) {
        (self->cur += 2);
        return Lexer_lexString(self, start);
    }
    if (((((c | 0x20) >= 'a') && ((c | 0x20) <= 'z')) || (c == '_'))) {
        return Lexer_lexIdentifier(self, start);
    }
    if (((c >= 0xC0) && (c <= 0xFD))) {
        size_t len;
        uint32_t cp = decodeUtf8(start, self->bufEnd, (& len));
        if (((len > 0) && isXidStart(cp))) {
            (self->cur = (start + len));
            return Lexer_lexIdentifier(self, start);
        }
    }
    if (((c >= '0') && (c <= '9'))) {
        return Lexer_lexNumber(self, start);
    }
    if ((c == '"')) {
        return Lexer_lexString(self, start);
    }
    if ((c == '\'')) {
        while (((! Lexer_isAtEnd(self)) && (self->cur[0] != '\''))) {
            if ((self->cur[0] == '\\')) {
                EscapeResult esc = EscapeResult_decodeEscapeSequence(self->cur, self->bufEnd);
                if ((! esc.isValid)) {
                    DiagnosticEngine_reportError(self->diag, self->bufStart, self->bufEnd, self->cur, "unknown escape sequence");
                }
                (self->cur += esc.bytesConsumed);
            } else {
                {
                    size_t len;
                    uint32_t cp = decodeUtf8(self->cur, self->bufEnd, (& len));
                    if ((len > 0)) {
                        (self->cur += len);
                    } else {
                        {
                            (self->cur++);
                        }
                    }
                }
            }
        }
        if ((! Lexer_isAtEnd(self))) {
            (self->cur++);
        }
        return Lexer_makeToken(self, TokenKind_Char, start);
    }
    Token op = Lexer_lexOperator(self, c, start);
    if ((op.kind != TokenKind_Eof)) {
        return op;
    }
    return Lexer_makeToken(self, TokenKind_Eof, start);
}



typedef struct SourceMap SourceMap;
typedef struct FileEntry FileEntry;
typedef struct InternEntry InternEntry;
typedef struct SourceLoc SourceLoc;
typedef struct Decl Decl;
typedef struct Lexer Lexer;
typedef struct Label Label;
typedef struct Slice Slice;
typedef struct FlagBranch FlagBranch;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Ast Ast;
typedef struct TypeEntry TypeEntry;
typedef struct Span Span;
typedef struct VariantVariant VariantVariant;
typedef struct EnumVariant EnumVariant;
typedef struct Diagnostic Diagnostic;
typedef struct EscapeResult EscapeResult;
typedef struct TestResult TestResult;
typedef struct NodeId NodeId;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct Expr Expr;
typedef struct Pat Pat;
typedef struct GenericParam GenericParam;
typedef struct TraitBound TraitBound;
typedef struct File File;
typedef struct Node Node;
typedef struct TypeKind TypeKind;
typedef struct Field Field;
typedef struct Token Token;
typedef struct Param Param;
typedef struct AstContext AstContext;
typedef struct IdentifierTable IdentifierTable;
typedef struct Parser Parser;
typedef struct IdentEntry IdentEntry;
typedef struct SwitchCase SwitchCase;
typedef struct ImportSymbol ImportSymbol;
typedef struct Stmt Stmt;
typedef struct ParserMark ParserMark;
typedef struct Attribute Attribute;
typedef enum ErrorCode ErrorCode;
typedef enum TokenKind TokenKind;


typedef uint32_t Ty;

enum TypeKind_tag {
    TypeKind_Error = 0,
    TypeKind_Void,
    TypeKind_Bool,
    TypeKind_Char,
    TypeKind_I8,
    TypeKind_U8,
    TypeKind_I16,
    TypeKind_U16,
    TypeKind_I32,
    TypeKind_U32,
    TypeKind_I64,
    TypeKind_U64,
    TypeKind_I128,
    TypeKind_U128,
    TypeKind_F32,
    TypeKind_F64,
    TypeKind_Isize,
    TypeKind_Usize,
    TypeKind_Rawptr,
    TypeKind_Str,
    TypeKind_Named,
    TypeKind_Pointer,
    TypeKind_Const,
    TypeKind_Slice,
    TypeKind_Array,
    TypeKind_FnPtr,
    TypeKind_Tuple,
    TypeKind_TypeParam
};

typedef struct TypeKind {
    enum TypeKind_tag tag;
    union {
        struct {
            Str name;
            Ty* genericArgs;
            uint32_t genericArgsLen;
        } Named;
        struct {
            Ty base;
        } Pointer;
        struct {
            Ty base;
        } Const;
        struct {
            Ty base;
        } Slice;
        struct {
            Ty base;
            uint32_t len;
        } Array;
        struct {
            Ty returnType;
            Ty* params;
            uint32_t paramsLen;
            Str name;
        } FnPtr;
        struct {
            Ty* elems;
            uint32_t elemsLen;
        } Tuple;
        struct {
            Str name;
            uint32_t index;
        } TypeParam;
    } payload;
} TypeKind;

typedef struct TypeEntry {
    TypeKind kind;
    SourceLoc loc;
} TypeEntry;




typedef struct SourceMap SourceMap;
typedef struct FileEntry FileEntry;
typedef struct InternEntry InternEntry;
typedef struct SourceLoc SourceLoc;
typedef struct Decl Decl;
typedef struct Lexer Lexer;
typedef struct Label Label;
typedef struct Slice Slice;
typedef struct FlagBranch FlagBranch;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Ast Ast;
typedef struct TypeEntry TypeEntry;
typedef struct Span Span;
typedef struct VariantVariant VariantVariant;
typedef struct EnumVariant EnumVariant;
typedef struct Diagnostic Diagnostic;
typedef struct EscapeResult EscapeResult;
typedef struct TestResult TestResult;
typedef struct NodeId NodeId;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct Expr Expr;
typedef struct Pat Pat;
typedef struct GenericParam GenericParam;
typedef struct TraitBound TraitBound;
typedef struct File File;
typedef struct Node Node;
typedef struct TypeKind TypeKind;
typedef struct Field Field;
typedef struct Token Token;
typedef struct Param Param;
typedef struct AstContext AstContext;
typedef struct PatKind PatKind;
typedef struct IdentifierTable IdentifierTable;
typedef struct Parser Parser;
typedef struct IdentEntry IdentEntry;
typedef struct SwitchCase SwitchCase;
typedef struct ImportSymbol ImportSymbol;
typedef struct Stmt Stmt;
typedef struct ParserMark ParserMark;
typedef struct Attribute Attribute;
typedef enum ErrorCode ErrorCode;
typedef enum TokenKind TokenKind;



enum PatKind_tag {
    PatKind_Wildcard = 0,
    PatKind_Lit,
    PatKind_Ident,
    PatKind_Type,
    PatKind_Variant,
    PatKind_Tuple,
    PatKind_Struct,
    PatKind_Or,
    PatKind_Guard,
    PatKind_Range
};

typedef struct PatKind {
    enum PatKind_tag tag;
    union {
        struct {
            NodeId expr;
        } Lit;
        struct {
            Str name;
        } Ident;
        struct {
            Ty typeNode;
        } Type;
        struct {
            Str typeName;
            Str variant;
            Str* fieldNames;
            uint32_t fieldNamesLen;
        } Variant;
        struct {
            NodeId* elems;
            uint32_t elemsLen;
        } Tuple;
        struct {
            Str name;
            NodeId* fieldNames;
            uint32_t fieldNamesLen;
        } Struct;
        struct {
            NodeId* alternatives;
            uint32_t alternativesLen;
        } Or;
        struct {
            NodeId pattern;
            NodeId cond;
        } Guard;
        struct {
            NodeId start;
            NodeId end;
            uint8_t flags;
        } Range;
    } payload;
} PatKind;

typedef struct Pat {
    PatKind kind;
    SourceLoc loc;
} Pat;




typedef struct SourceMap SourceMap;
typedef struct FileEntry FileEntry;
typedef struct InternEntry InternEntry;
typedef struct SourceLoc SourceLoc;
typedef struct Decl Decl;
typedef struct Lexer Lexer;
typedef struct Label Label;
typedef struct DeclKind DeclKind;
typedef struct Slice Slice;
typedef struct FlagBranch FlagBranch;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Ast Ast;
typedef struct TypeEntry TypeEntry;
typedef struct Span Span;
typedef struct VariantVariant VariantVariant;
typedef struct EnumVariant EnumVariant;
typedef struct Diagnostic Diagnostic;
typedef struct EscapeResult EscapeResult;
typedef struct TestResult TestResult;
typedef struct NodeId NodeId;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct Expr Expr;
typedef struct Pat Pat;
typedef struct GenericParam GenericParam;
typedef struct TraitBound TraitBound;
typedef struct File File;
typedef struct Node Node;
typedef struct TypeKind TypeKind;
typedef struct Field Field;
typedef struct Token Token;
typedef struct Param Param;
typedef struct AstContext AstContext;
typedef struct PatKind PatKind;
typedef struct IdentifierTable IdentifierTable;
typedef struct Parser Parser;
typedef struct IdentEntry IdentEntry;
typedef struct SwitchCase SwitchCase;
typedef struct ImportSymbol ImportSymbol;
typedef struct Stmt Stmt;
typedef struct ParserMark ParserMark;
typedef struct Attribute Attribute;
typedef enum ErrorCode ErrorCode;
typedef enum TokenKind TokenKind;



typedef struct GenericParam {
    Str name;
    NodeId* bounds;
    uint32_t boundsLen;
} GenericParam;

typedef struct TraitBound {
    Str traitName;
} TraitBound;

typedef struct Param {
    Str name;
    Ty typeNode;
    SourceLoc loc;
    uint8_t flags;
} Param;

typedef struct Field {
    Str name;
    Ty typeNode;
    NodeId defaultValue;
    SourceLoc loc;
    uint8_t flags;
} Field;

typedef struct EnumVariant {
    Str name;
    NodeId value;
    SourceLoc loc;
    uint8_t flags;
} EnumVariant;

typedef struct VariantVariant {
    Str name;
    Str* fieldNames;
    Ty* fieldTypes;
    uint32_t fieldsLen;
    SourceLoc loc;
} VariantVariant;

typedef struct FlagBranch {
    Str label;
    NodeId* stmts;
    uint32_t stmtsLen;
} FlagBranch;

typedef struct ImportSymbol {
    Str name;
    Str alias;
    uint8_t flags;
} ImportSymbol;

typedef struct Attribute {
    Str name;
    Str* args;
    uint32_t argsLen;
    SourceLoc loc;
} Attribute;

enum DeclKind_tag {
    DeclKind_Import = 0,
    DeclKind_ModReexport,
    DeclKind_Struct,
    DeclKind_Enum,
    DeclKind_Variant,
    DeclKind_Union,
    DeclKind_Trait,
    DeclKind_Extend,
    DeclKind_ExtendTrait,
    DeclKind_Func,
    DeclKind_Constant,
    DeclKind_TypeAlias,
    DeclKind_Distinct,
    DeclKind_Flag,
    DeclKind_Comptime
};

typedef struct DeclKind {
    enum DeclKind_tag tag;
    union {
        struct {
            Str path;
            ImportSymbol* symbols;
            uint32_t symbolsLen;
            uint8_t flags;
        } Import;
        struct {
            Str alias;
            Str path;
            uint8_t flags;
        } ModReexport;
        struct {
            Str name;
            NodeId* genericParams;
            uint32_t genericParamsLen;
            NodeId* fields;
            uint32_t fieldsLen;
            NodeId* methods;
            uint32_t methodsLen;
            uint8_t flags;
        } Struct;
        struct {
            Str name;
            Ty backingType;
            NodeId* variants;
            uint32_t variantsLen;
            uint8_t flags;
        } Enum;
        struct {
            Str name;
            NodeId* genericParams;
            uint32_t genericParamsLen;
            VariantVariant* variants;
            uint32_t variantsLen;
            NodeId* methods;
            uint32_t methodsLen;
            uint8_t flags;
        } Variant;
        struct {
            Str name;
            NodeId* genericParams;
            uint32_t genericParamsLen;
            NodeId* fields;
            uint32_t fieldsLen;
            NodeId* methods;
            uint32_t methodsLen;
            uint8_t flags;
        } Union;
        struct {
            Str name;
            NodeId* genericParams;
            uint32_t genericParamsLen;
            NodeId* methods;
            uint32_t methodsLen;
            uint8_t flags;
        } Trait;
        struct {
            Ty selfType;
            NodeId* methods;
            uint32_t methodsLen;
        } Extend;
        struct {
            Ty selfType;
            Str traitName;
            NodeId* methods;
            uint32_t methodsLen;
        } ExtendTrait;
        struct {
            Str name;
            NodeId* genericParams;
            uint32_t genericParamsLen;
            NodeId* params;
            uint32_t paramsLen;
            Ty returnType;
            NodeId body;
            uint8_t flags;
        } Func;
        struct {
            Str name;
            Ty typeNode;
            NodeId value;
            uint8_t flags;
        } Constant;
        struct {
            Str name;
            Ty target;
            uint8_t flags;
        } TypeAlias;
        struct {
            Str name;
            Ty baseType;
            uint8_t flags;
        } Distinct;
        struct {
            Str flagName;
            NodeId* branches;
            uint32_t branchesLen;
        } Flag;
        struct {
            NodeId* decls;
            uint32_t declsLen;
        } Comptime;
    } payload;
} DeclKind;

typedef struct Decl {
    DeclKind kind;
    SourceLoc loc;
    Attribute* attrs;
    uint32_t attrsLen;
} Decl;

typedef struct File {
    Str path;
    NodeId* decls;
    uint32_t declsLen;
} File;




typedef struct SourceMap SourceMap;
typedef struct FileEntry FileEntry;
typedef struct InternEntry InternEntry;
typedef struct SourceLoc SourceLoc;
typedef struct Decl Decl;
typedef struct Lexer Lexer;
typedef struct StmtKind StmtKind;
typedef struct Label Label;
typedef struct DeclKind DeclKind;
typedef struct Slice Slice;
typedef struct FlagBranch FlagBranch;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Ast Ast;
typedef struct TypeEntry TypeEntry;
typedef struct Span Span;
typedef struct VariantVariant VariantVariant;
typedef struct EnumVariant EnumVariant;
typedef struct Diagnostic Diagnostic;
typedef struct EscapeResult EscapeResult;
typedef struct TestResult TestResult;
typedef struct NodeId NodeId;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct Expr Expr;
typedef struct Pat Pat;
typedef struct GenericParam GenericParam;
typedef struct TraitBound TraitBound;
typedef struct File File;
typedef struct Node Node;
typedef struct TypeKind TypeKind;
typedef struct Field Field;
typedef struct Token Token;
typedef struct Param Param;
typedef struct AstContext AstContext;
typedef struct PatKind PatKind;
typedef struct IdentifierTable IdentifierTable;
typedef struct Parser Parser;
typedef struct IdentEntry IdentEntry;
typedef struct SwitchCase SwitchCase;
typedef struct ImportSymbol ImportSymbol;
typedef struct Stmt Stmt;
typedef struct ParserMark ParserMark;
typedef struct Attribute Attribute;
typedef enum ErrorCode ErrorCode;
typedef enum TokenKind TokenKind;



typedef struct SwitchCase {
    NodeId* patterns;
    uint32_t patternsLen;
    NodeId guard;
    NodeId body;
    uint8_t flags;
} SwitchCase;

enum StmtKind_tag {
    StmtKind_ExprStmt = 0,
    StmtKind_VarDecl,
    StmtKind_Assign,
    StmtKind_Return,
    StmtKind_Break,
    StmtKind_Continue,
    StmtKind_Block,
    StmtKind_If,
    StmtKind_While,
    StmtKind_Loop,
    StmtKind_For,
    StmtKind_ForIn,
    StmtKind_Switch,
    StmtKind_Defer,
    StmtKind_Comptime,
    StmtKind_Asm
};

typedef struct StmtKind {
    enum StmtKind_tag tag;
    union {
        struct {
            NodeId expr;
        } ExprStmt;
        struct {
            Str name;
            Ty typeNode;
            NodeId init;
            uint8_t flags;
        } VarDecl;
        struct {
            NodeId target;
            NodeId value;
            Str op;
        } Assign;
        struct {
            NodeId value;
        } Return;
        struct {
            NodeId* stmts;
            uint32_t stmtsLen;
        } Block;
        struct {
            NodeId cond;
            NodeId thenBody;
            NodeId elseBody;
        } If;
        struct {
            NodeId cond;
            NodeId body;
        } While;
        struct {
            NodeId body;
        } Loop;
        struct {
            NodeId init;
            NodeId cond;
            NodeId post;
            NodeId body;
            uint8_t flags;
        } For;
        struct {
            Str bindName;
            Ty bindType;
            NodeId iterExpr;
            NodeId body;
            uint8_t flags;
        } ForIn;
        struct {
            NodeId expr;
            SwitchCase* cases;
            uint32_t casesLen;
        } Switch;
        struct {
            NodeId stmt;
        } Defer;
        struct {
            NodeId* stmts;
            uint32_t stmtsLen;
        } Comptime;
        struct {
            NodeId* template;
            uint32_t templateLen;
            uint8_t flags;
        } Asm;
    } payload;
} StmtKind;

typedef struct Stmt {
    StmtKind kind;
    SourceLoc loc;
    Attribute* attrs;
    uint32_t attrsLen;
} Stmt;




typedef struct SourceMap SourceMap;
typedef struct FileEntry FileEntry;
typedef struct InternEntry InternEntry;
typedef struct SourceLoc SourceLoc;
typedef struct Decl Decl;
typedef struct Lexer Lexer;
typedef struct StmtKind StmtKind;
typedef struct Label Label;
typedef struct DeclKind DeclKind;
typedef struct Slice Slice;
typedef struct FlagBranch FlagBranch;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Ast Ast;
typedef struct TypeEntry TypeEntry;
typedef struct Span Span;
typedef struct ExprKind ExprKind;
typedef struct VariantVariant VariantVariant;
typedef struct EnumVariant EnumVariant;
typedef struct Diagnostic Diagnostic;
typedef struct EscapeResult EscapeResult;
typedef struct TestResult TestResult;
typedef struct NodeId NodeId;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct Expr Expr;
typedef struct Pat Pat;
typedef struct GenericParam GenericParam;
typedef struct TraitBound TraitBound;
typedef struct File File;
typedef struct Node Node;
typedef struct TypeKind TypeKind;
typedef struct Field Field;
typedef struct Token Token;
typedef struct Param Param;
typedef struct AstContext AstContext;
typedef struct PatKind PatKind;
typedef struct IdentifierTable IdentifierTable;
typedef struct Parser Parser;
typedef struct IdentEntry IdentEntry;
typedef struct SwitchCase SwitchCase;
typedef struct ImportSymbol ImportSymbol;
typedef struct Stmt Stmt;
typedef struct ParserMark ParserMark;
typedef struct Attribute Attribute;
typedef enum ErrorCode ErrorCode;
typedef enum TokenKind TokenKind;



enum ExprKind_tag {
    ExprKind_IntLit = 0,
    ExprKind_FloatLit,
    ExprKind_StringLit,
    ExprKind_CharLit,
    ExprKind_BoolLit,
    ExprKind_NullLit,
    ExprKind_Ident,
    ExprKind_Path,
    ExprKind_Call,
    ExprKind_MethodCall,
    ExprKind_Field,
    ExprKind_DerefField,
    ExprKind_Index,
    ExprKind_StaticCall,
    ExprKind_Cast,
    ExprKind_Sizeof,
    ExprKind_Alignof,
    ExprKind_Typeof,
    ExprKind_AddressOf,
    ExprKind_Deref,
    ExprKind_Neg,
    ExprKind_Not,
    ExprKind_Add,
    ExprKind_Sub,
    ExprKind_Mul,
    ExprKind_Div,
    ExprKind_Mod,
    ExprKind_Eq,
    ExprKind_Ne,
    ExprKind_Lt,
    ExprKind_Le,
    ExprKind_Gt,
    ExprKind_Ge,
    ExprKind_And,
    ExprKind_Or,
    ExprKind_BitAnd,
    ExprKind_BitOr,
    ExprKind_BitXor,
    ExprKind_Shl,
    ExprKind_Shr,
    ExprKind_Assign,
    ExprKind_AssignAdd,
    ExprKind_AssignSub,
    ExprKind_AssignMul,
    ExprKind_AssignDiv,
    ExprKind_AssignMod,
    ExprKind_AssignBitAnd,
    ExprKind_AssignBitOr,
    ExprKind_AssignBitXor,
    ExprKind_AssignShl,
    ExprKind_AssignShr,
    ExprKind_TupleField,
    ExprKind_StructLiteral,
    ExprKind_ArrayLiteral,
    ExprKind_BuiltinCall,
    ExprKind_BlockExpr,
    ExprKind_IfExpr,
    ExprKind_SwitchExpr
};

typedef struct ExprKind {
    enum ExprKind_tag tag;
    union {
        struct {
            uint64_t value;
            uint8_t flags;
        } IntLit;
        struct {
            Str value;
        } FloatLit;
        struct {
            Str value;
        } StringLit;
        struct {
            uint32_t value;
        } CharLit;
        struct {
            uint8_t flags;
        } BoolLit;
        struct {
            Str name;
        } Ident;
        struct {
            NodeId* segments;
            uint32_t segmentsLen;
        } Path;
        struct {
            NodeId callee;
            NodeId* args;
            uint32_t argsLen;
        } Call;
        struct {
            NodeId receiver;
            Str method;
            NodeId* args;
            uint32_t argsLen;
        } MethodCall;
        struct {
            NodeId obj;
            Str field;
        } Field;
        struct {
            NodeId obj;
            Str field;
        } DerefField;
        struct {
            NodeId obj;
            NodeId index;
        } Index;
        struct {
            Str typeName;
            Str method;
            NodeId* args;
            uint32_t argsLen;
        } StaticCall;
        struct {
            NodeId expr;
            Ty targetType;
        } Cast;
        struct {
            Ty targetType;
        } Sizeof;
        struct {
            Ty targetType;
        } Alignof;
        struct {
            NodeId expr;
        } Typeof;
        struct {
            NodeId expr;
        } AddressOf;
        struct {
            NodeId expr;
        } Deref;
        struct {
            NodeId expr;
        } Neg;
        struct {
            NodeId expr;
        } Not;
        struct {
            NodeId left;
            NodeId right;
        } Add;
        struct {
            NodeId left;
            NodeId right;
        } Sub;
        struct {
            NodeId left;
            NodeId right;
        } Mul;
        struct {
            NodeId left;
            NodeId right;
        } Div;
        struct {
            NodeId left;
            NodeId right;
        } Mod;
        struct {
            NodeId left;
            NodeId right;
        } Eq;
        struct {
            NodeId left;
            NodeId right;
        } Ne;
        struct {
            NodeId left;
            NodeId right;
        } Lt;
        struct {
            NodeId left;
            NodeId right;
        } Le;
        struct {
            NodeId left;
            NodeId right;
        } Gt;
        struct {
            NodeId left;
            NodeId right;
        } Ge;
        struct {
            NodeId left;
            NodeId right;
        } And;
        struct {
            NodeId left;
            NodeId right;
        } Or;
        struct {
            NodeId left;
            NodeId right;
        } BitAnd;
        struct {
            NodeId left;
            NodeId right;
        } BitOr;
        struct {
            NodeId left;
            NodeId right;
        } BitXor;
        struct {
            NodeId left;
            NodeId right;
        } Shl;
        struct {
            NodeId left;
            NodeId right;
        } Shr;
        struct {
            NodeId target;
            NodeId value;
        } Assign;
        struct {
            NodeId target;
            NodeId value;
        } AssignAdd;
        struct {
            NodeId target;
            NodeId value;
        } AssignSub;
        struct {
            NodeId target;
            NodeId value;
        } AssignMul;
        struct {
            NodeId target;
            NodeId value;
        } AssignDiv;
        struct {
            NodeId target;
            NodeId value;
        } AssignMod;
        struct {
            NodeId target;
            NodeId value;
        } AssignBitAnd;
        struct {
            NodeId target;
            NodeId value;
        } AssignBitOr;
        struct {
            NodeId target;
            NodeId value;
        } AssignBitXor;
        struct {
            NodeId target;
            NodeId value;
        } AssignShl;
        struct {
            NodeId target;
            NodeId value;
        } AssignShr;
        struct {
            NodeId obj;
            uint32_t index;
        } TupleField;
        struct {
            Ty typeNode;
            Str* fieldNames;
            NodeId* fieldValues;
            uint32_t fieldValuesLen;
        } StructLiteral;
        struct {
            NodeId* elems;
            uint32_t elemsLen;
        } ArrayLiteral;
        struct {
            Str name;
            NodeId* args;
            uint32_t argsLen;
        } BuiltinCall;
        struct {
            NodeId* stmts;
            uint32_t stmtsLen;
            NodeId result;
        } BlockExpr;
        struct {
            NodeId cond;
            NodeId thenBody;
            NodeId elseBody;
        } IfExpr;
        struct {
            NodeId expr;
            SwitchCase* cases;
            uint32_t casesLen;
        } SwitchExpr;
    } payload;
} ExprKind;

typedef struct Expr {
    ExprKind kind;
    SourceLoc loc;
    Ty resolvedType;
} Expr;




typedef struct SourceMap SourceMap;
typedef struct FileEntry FileEntry;
typedef struct InternEntry InternEntry;
typedef struct NodeKind NodeKind;
typedef struct SourceLoc SourceLoc;
typedef struct Decl Decl;
typedef struct Lexer Lexer;
typedef struct StmtKind StmtKind;
typedef struct Label Label;
typedef struct DeclKind DeclKind;
typedef struct Slice Slice;
typedef struct FlagBranch FlagBranch;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Ast Ast;
typedef struct TypeEntry TypeEntry;
typedef struct Span Span;
typedef struct ExprKind ExprKind;
typedef struct VariantVariant VariantVariant;
typedef struct EnumVariant EnumVariant;
typedef struct Diagnostic Diagnostic;
typedef struct EscapeResult EscapeResult;
typedef struct TestResult TestResult;
typedef struct NodeId NodeId;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct Expr Expr;
typedef struct Pat Pat;
typedef struct GenericParam GenericParam;
typedef struct TraitBound TraitBound;
typedef struct File File;
typedef struct Node Node;
typedef struct TypeKind TypeKind;
typedef struct Field Field;
typedef struct Token Token;
typedef struct Param Param;
typedef struct AstContext AstContext;
typedef struct PatKind PatKind;
typedef struct IdentifierTable IdentifierTable;
typedef struct Parser Parser;
typedef struct IdentEntry IdentEntry;
typedef struct SwitchCase SwitchCase;
typedef struct ImportSymbol ImportSymbol;
typedef struct Stmt Stmt;
typedef struct ParserMark ParserMark;
typedef struct Attribute Attribute;
typedef enum ErrorCode ErrorCode;
typedef enum TokenKind TokenKind;



enum NodeKind_tag {
    NodeKind_Expr = 0,
    NodeKind_Stmt,
    NodeKind_;,
    NodeKind_Decl,
    NodeKind_Pat,
    NodeKind_Type
};

typedef struct NodeKind {
    enum NodeKind_tag tag;
    union {
        struct {
            Expr value;
        } Expr;
        struct {
            Stmt value;
        } Stmt;
        struct {
            Decl value;
        } Decl;
        struct {
            Pat value;
        } Pat;
        struct {
            Ty value;
        } Type;
    } payload;
} NodeKind;

typedef struct Node {
    NodeKind kind;
    SourceLoc loc;
} Node;

typedef struct Ast {
    File* files;
    uint32_t filesLen;
    Node* nodes;
    uint32_t nodesLen;
    TypeEntry* types;
    uint32_t typesLen;
} Ast;




typedef struct SourceMap SourceMap;
typedef struct FileEntry FileEntry;
typedef struct InternEntry InternEntry;
typedef struct NodeKind NodeKind;
typedef struct SourceLoc SourceLoc;
typedef struct Decl Decl;
typedef struct Lexer Lexer;
typedef struct StmtKind StmtKind;
typedef struct Label Label;
typedef struct DeclKind DeclKind;
typedef struct Slice Slice;
typedef struct FlagBranch FlagBranch;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Ast Ast;
typedef struct TypeEntry TypeEntry;
typedef struct Span Span;
typedef struct ExprKind ExprKind;
typedef struct VariantVariant VariantVariant;
typedef struct EnumVariant EnumVariant;
typedef struct Diagnostic Diagnostic;
typedef struct EscapeResult EscapeResult;
typedef struct TestResult TestResult;
typedef struct NodeId NodeId;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct Expr Expr;
typedef struct Pat Pat;
typedef struct GenericParam GenericParam;
typedef struct TraitBound TraitBound;
typedef struct File File;
typedef struct Node Node;
typedef struct TypeKind TypeKind;
typedef struct Field Field;
typedef struct Token Token;
typedef struct Param Param;
typedef struct AstContext AstContext;
typedef struct PatKind PatKind;
typedef struct IdentifierTable IdentifierTable;
typedef struct Parser Parser;
typedef struct IdentEntry IdentEntry;
typedef struct SwitchCase SwitchCase;
typedef struct ImportSymbol ImportSymbol;
typedef struct Stmt Stmt;
typedef struct ParserMark ParserMark;
typedef struct Attribute Attribute;
typedef enum ErrorCode ErrorCode;
typedef enum TokenKind TokenKind;

extern void* malloc(size_t size);
extern void free(void* ptr);

void AstContext_init(AstContext* self, uint32_t internCap, uint32_t typeCap, uint32_t nodeCap);
void AstContext_deinit(AstContext* self);
_Bool AstContext_streq(AstContext* self, uint8_t* a, size_t aLen, uint8_t* b, size_t bLen);
uint32_t AstContext_intern(AstContext* self, uint8_t* ptr, size_t len);
Ty AstContext_allocTypeSlot(AstContext* self);
NodeId AstContext_allocNodeSlot(AstContext* self);
NodeId AstContext_noneNode(AstContext* self);
uint32_t AstContext_nodeCount(AstContext* self);

typedef struct InternEntry {
    uint8_t* ptr;
    size_t len;
    uint32_t id;
} InternEntry;

typedef struct AstContext {
    InternEntry* interns;
    uint32_t internsLen;
    uint32_t internsCap;
    TypeEntry* types;
    uint32_t typesLen;
    uint32_t typesCap;
    Node* nodes;
    uint32_t nodesLen;
    uint32_t nodesCap;
} AstContext;

void AstContext_init(AstContext* self, uint32_t internCap, uint32_t typeCap, uint32_t nodeCap) {
    (self->interns = malloc((internCap * 24)));
    (self->internsLen = 1);
    (self->internsCap = internCap);
    (self->types = malloc((typeCap * 64)));
    (self->typesLen = 1);
    (self->typesCap = typeCap);
    (self->nodes = malloc((nodeCap * 192)));
    (self->nodesLen = 1);
    (self->nodesCap = nodeCap);
}
void AstContext_deinit(AstContext* self) {
    free(self->interns);
    free(self->types);
    free(self->nodes);
}
_Bool AstContext_streq(AstContext* self, uint8_t* a, size_t aLen, uint8_t* b, size_t bLen) {
    if ((aLen != bLen)) {
        return 0;
    }
    size_t i = 0;
    while ((i < aLen)) {
        uint8_t* ap = (a + i);
        uint8_t* bp = (b + i);
        if ((ap[0] != bp[0])) {
            return 0;
        }
        (i = (i + 1));
    }
    return 1;
}
uint32_t AstContext_intern(AstContext* self, uint8_t* ptr, size_t len) {
    uint32_t i = 0;
    while ((i < self->internsLen)) {
        InternEntry* e = (self->interns + i);
        if (AstContext_streq(self, e->ptr, e->len, ptr, len)) {
            return e->id;
        }
        (i = (i + 1));
    }
    if ((self->internsLen >= self->internsCap)) {
        return 0;
    }
    InternEntry* e = (self->interns + self->internsLen);
    (e->ptr = ptr);
    (e->len = len);
    (e->id = self->internsLen);
    (self->internsLen = (self->internsLen + 1));
    return e->id;
}
Ty AstContext_allocTypeSlot(AstContext* self) {
    if ((self->typesLen >= self->typesCap)) {
        return 0;
    }
    Ty id = self->typesLen;
    (self->typesLen = (self->typesLen + 1));
    return id;
}
NodeId AstContext_allocNodeSlot(AstContext* self) {
    if ((self->nodesLen >= self->nodesCap)) {
        NodeId n;
        (n.index = 0);
        return n;
    }
    NodeId n;
    (n.index = self->nodesLen);
    (self->nodesLen = (self->nodesLen + 1));
    return n;
}
NodeId AstContext_noneNode(AstContext* self) {
    NodeId n;
    (n.index = 0);
    return n;
}
uint32_t AstContext_nodeCount(AstContext* self) {
    return self->nodesLen;
}
extern void* malloc(size_t size);
extern void free(void* ptr);



typedef struct SourceMap SourceMap;
typedef struct FileEntry FileEntry;
typedef struct InternEntry InternEntry;
typedef struct NodeKind NodeKind;
typedef struct SourceLoc SourceLoc;
typedef struct Decl Decl;
typedef struct Lexer Lexer;
typedef struct StmtKind StmtKind;
typedef struct Label Label;
typedef struct DeclKind DeclKind;
typedef struct Slice Slice;
typedef struct FlagBranch FlagBranch;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Ast Ast;
typedef struct TypeEntry TypeEntry;
typedef struct Span Span;
typedef struct ExprKind ExprKind;
typedef struct VariantVariant VariantVariant;
typedef struct EnumVariant EnumVariant;
typedef struct Diagnostic Diagnostic;
typedef struct EscapeResult EscapeResult;
typedef struct TestResult TestResult;
typedef struct NodeId NodeId;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct Expr Expr;
typedef struct Pat Pat;
typedef struct GenericParam GenericParam;
typedef struct TraitBound TraitBound;
typedef struct File File;
typedef struct Node Node;
typedef struct TypeKind TypeKind;
typedef struct Field Field;
typedef struct Token Token;
typedef struct Param Param;
typedef struct AstContext AstContext;
typedef struct PatKind PatKind;
typedef struct IdentifierTable IdentifierTable;
typedef struct Parser Parser;
typedef struct IdentEntry IdentEntry;
typedef struct SwitchCase SwitchCase;
typedef struct ImportSymbol ImportSymbol;
typedef struct Stmt Stmt;
typedef struct ParserMark ParserMark;
typedef struct Attribute Attribute;
typedef enum ErrorCode ErrorCode;
typedef enum TokenKind TokenKind;


Parser Parser_init(Parser* self, Lexer* lexer, AstContext* ctx);
Token Parser_advance(Parser* self);
_Bool Parser_check(Parser* self, TokenKind kind);
_Bool Parser_match(Parser* self, TokenKind kind);
Token Parser_expect(Parser* self, TokenKind kind);
_Bool Parser_atEnd(Parser* self);
NodeId Parser_noneNode(Parser* self);
NodeId Parser_allocNode(Parser* self);
ParserMark Parser_save(Parser* self);
void Parser_restore(Parser* self, ParserMark m);
_Bool Parser_consumeGreater(Parser* self);

typedef struct ParserMark {
    uint8_t* cur;
    uint8_t* lineStart;
    uint32_t line;
    Token current;
    Token previous;
    uint32_t panicMode;
    _Bool pendingGreater;
} ParserMark;

typedef struct Parser {
    Lexer* lexer;
    AstContext* ctx;
    Token current;
    Token previous;
    uint32_t panicMode;
    _Bool pendingGreater;
} Parser;

Parser Parser_init(Parser* self, Lexer* lexer, AstContext* ctx) {
    Parser p;
    (p.lexer = lexer);
    (p.ctx = ctx);
    (p.panicMode = 0);
    (p.pendingGreater = 0);
    Lexer_nextToken(lexer);
    (p.current = lexer->token);
    (p.previous = lexer->token);
    return p;
}
Token Parser_advance(Parser* self) {
    (self->previous = self->current);
    Lexer_nextToken(self->lexer);
    (self->current = self->lexer->token);
    return self->previous;
}
_Bool Parser_check(Parser* self, TokenKind kind) {
    return (self->current.kind == kind);
}
_Bool Parser_match(Parser* self, TokenKind kind) {
    if ((self->current.kind == kind)) {
        Parser_advance(self);
        return 1;
    }
    return 0;
}
Token Parser_expect(Parser* self, TokenKind kind) {
    if ((self->current.kind == kind)) {
        return Parser_advance(self);
    }
    (self->panicMode = 1);
    return self->current;
}
_Bool Parser_atEnd(Parser* self) {
    return (self->current.kind == TokenKind_Eof);
}
NodeId Parser_noneNode(Parser* self) {
    return AstContext_noneNode(self->ctx);
}
NodeId Parser_allocNode(Parser* self) {
    return AstContext_allocNodeSlot(self->ctx);
}
ParserMark Parser_save(Parser* self) {
    ParserMark m;
    (m.cur = Lexer_getCur(self->lexer));
    (m.lineStart = Lexer_getLineStart(self->lexer));
    (m.line = Lexer_getLine(self->lexer));
    (m.current = self->current);
    (m.previous = self->previous);
    (m.panicMode = self->panicMode);
    (m.pendingGreater = self->pendingGreater);
    return m;
}
void Parser_restore(Parser* self, ParserMark m) {
    Lexer_setCur(self->lexer, m.cur);
    Lexer_setLineStart(self->lexer, m.lineStart);
    Lexer_setLine(self->lexer, m.line);
    (self->current = m.current);
    (self->previous = m.previous);
    (self->panicMode = m.panicMode);
    (self->pendingGreater = m.pendingGreater);
    Lexer_setToken(self->lexer, m.current);
}
_Bool Parser_consumeGreater(Parser* self) {
    if (self->pendingGreater) {
        (self->pendingGreater = 0);
        return 1;
    }
    if (Parser_check(self, TokenKind_Greater)) {
        Parser_advance(self);
        return 1;
    }
    if (Parser_check(self, TokenKind_Shr)) {
        Parser_advance(self);
        (self->pendingGreater = 1);
        return 1;
    }
    return 0;
}



typedef struct SourceMap SourceMap;
typedef struct FileEntry FileEntry;
typedef struct InternEntry InternEntry;
typedef struct NodeKind NodeKind;
typedef struct SourceLoc SourceLoc;
typedef struct Decl Decl;
typedef struct Lexer Lexer;
typedef struct StmtKind StmtKind;
typedef struct Label Label;
typedef struct DeclKind DeclKind;
typedef struct Slice Slice;
typedef struct FlagBranch FlagBranch;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Ast Ast;
typedef struct TypeEntry TypeEntry;
typedef struct Span Span;
typedef struct ExprKind ExprKind;
typedef struct VariantVariant VariantVariant;
typedef struct EnumVariant EnumVariant;
typedef struct Diagnostic Diagnostic;
typedef struct EscapeResult EscapeResult;
typedef struct TestResult TestResult;
typedef struct NodeId NodeId;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct Expr Expr;
typedef struct Pat Pat;
typedef struct GenericParam GenericParam;
typedef struct TraitBound TraitBound;
typedef struct File File;
typedef struct Node Node;
typedef struct TypeKind TypeKind;
typedef struct Field Field;
typedef struct Token Token;
typedef struct Param Param;
typedef struct AstContext AstContext;
typedef struct PatKind PatKind;
typedef struct IdentifierTable IdentifierTable;
typedef struct Parser Parser;
typedef struct IdentEntry IdentEntry;
typedef struct SwitchCase SwitchCase;
typedef struct ImportSymbol ImportSymbol;
typedef struct Stmt Stmt;
typedef struct ParserMark ParserMark;
typedef struct Attribute Attribute;
typedef enum ErrorCode ErrorCode;
typedef enum TokenKind TokenKind;

extern int32_t printf(uint8_t* fmt, ...);

void TestResult_print(TestResult* self);
TestResult runParser(uint8_t* src, size_t len);
void testExpr();
void testFunc();
void testVariant();
void testSwitch();
void testFlag();
void testImport();
void testImportRoot();
void testImportLib();
void testModReexport();
void testAttr();
int32_t main();

typedef struct TestResult {
    uint32_t tokens;
    uint32_t nodes;
    uint32_t errors;
} TestResult;

extern int32_t printf(uint8_t* fmt, ...);
void TestResult_print(TestResult* self) {
    printf("tokens=%u nodes=%u errors=%u\n", self->tokens, self->nodes, self->errors);
}
TestResult runParser(uint8_t* src, size_t len) {
    AstContext ctx;
    AstContext_init(&ctx, 4096, 4096, 4096);
    Lexer lexer;
    (lexer.bufStart = src);
    (lexer.cur = src);
    (lexer.bufEnd = (src + len));
    (lexer.line = 1);
    (lexer.lineStart = src);
    (lexer.diag = NULL);
    (lexer.idents = NULL);
    Parser p;
    (p.lexer = (& lexer));
    (p.ctx = (& ctx));
    (p.panicMode = 0);
    (p.pendingGreater = 0);
    Lexer_nextToken((& lexer));
    (p.current = lexer.token);
    (p.previous = lexer.token);
    uint32_t decls = 0;
    while ((! Parser_atEnd(&p))) {
        if ((p.current.kind == TokenKind_Eof)) {
            break;
        }
        if ((p.current.kind == TokenKind_Unknown)) {
            Parser_advance(&p);
            continue;
        }
        Parser_parseDecl(&p);
        (decls = (decls + 1));
        if ((decls > 100)) {
            break;
        }
        if ((p.panicMode == 1)) {
            break;
        }
    }
    TestResult r;
    (r.tokens = decls);
    (r.nodes = AstContext_nodeCount(&ctx));
    (r.errors = p.panicMode);
    AstContext_deinit(&ctx);
    return r;
}
void testExpr() {
    uint8_t* src = "a + b * (c - d);";
    printf("expr test: ");
    AstContext ctx;
    AstContext_init(&ctx, 256, 256, 256);
    Lexer lexer;
    (lexer.bufStart = src);
    (lexer.cur = src);
    (lexer.bufEnd = (src + 18));
    (lexer.line = 1);
    (lexer.lineStart = src);
    (lexer.diag = NULL);
    (lexer.idents = NULL);
    Parser p;
    (p.lexer = (& lexer));
    (p.ctx = (& ctx));
    (p.panicMode = 0);
    (p.pendingGreater = 0);
    Lexer_nextToken((& lexer));
    (p.current = lexer.token);
    (p.previous = lexer.token);
    Parser_parseExpr(&p);
    printf("nodes=%u panic=%u\n", AstContext_nodeCount(&ctx), p.panicMode);
    AstContext_deinit(&ctx);
}
void testFunc() {
    uint8_t* src = "pub i32 add(u32 a, u32 b) { return a + b; }";
    printf("func test: ");
    TestResult r = runParser(src, 46);
    TestResult_print(&r);
}
void testVariant() {
    uint8_t* src = "pub variant Option { Some { u32 value }, None }";
    printf("variant test: ");
    TestResult r = runParser(src, 47);
    TestResult_print(&r);
}
void testSwitch() {
    uint8_t* src = "switch (x) { A => { 1 }, else => { 0 } }";
    printf("switch test: ");
    TestResult r = runParser(src, 41);
    TestResult_print(&r);
}
void testFlag() {
    uint8_t* src = "flag(PLATFORM) { linux => { a; }, else => { b; } }";
    printf("flag test: ");
    TestResult r = runParser(src, 49);
    TestResult_print(&r);
}
void testImport() {
    uint8_t* src = "import \"path\" { foo, bar as baz };";
    printf("import path test: ");
    TestResult r = runParser(src, 36);
    TestResult_print(&r);
}
void testImportRoot() {
    uint8_t* src = "import file::math::core { square };";
    printf("import root test: ");
    TestResult r = runParser(src, 39);
    TestResult_print(&r);
}
void testImportLib() {
    uint8_t* src = "import(lib) std::math { pow };";
    printf("import lib test: ");
    TestResult r = runParser(src, 32);
    TestResult_print(&r);
}
void testModReexport() {
    uint8_t* src = "pub mod m = import \"path\";";
    printf("mod reexport test: ");
    TestResult r = runParser(src, 27);
    TestResult_print(&r);
}
void testAttr() {
    uint8_t* src = "[[packed]] pub struct Foo { u32 x; }";
    printf("attr test: ");
    TestResult r = runParser(src, 36);
    TestResult_print(&r);
}
/* pub */ int32_t main() {
    printf("****coral parser self-test****\n");
    testExpr();
    testFunc();
    testVariant();
    testSwitch();
    testFlag();
    testImport();
    testImportRoot();
    testImportLib();
    testModReexport();
    testAttr();
    printf("****done****\n");
    return 0;
}
