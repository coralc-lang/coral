#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct _coral_str { const uint8_t* ptr; size_t len; } _coral_str;

typedef struct GenericParam GenericParam;
typedef struct ExprKind ExprKind;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct SourceMap SourceMap;
typedef struct InternEntry InternEntry;
typedef struct Parser Parser;
typedef struct StmtKind StmtKind;
typedef struct File File;
typedef struct TypeEntry TypeEntry;
typedef struct Param Param;
typedef struct SwitchCase SwitchCase;
typedef struct Token Token;
typedef struct Lexer Lexer;
typedef struct FlagBranch FlagBranch;
typedef struct EscapeResult EscapeResult;
typedef struct FileEntry FileEntry;
typedef struct ParserMark ParserMark;
typedef struct PatKind PatKind;
typedef struct TypeKind TypeKind;
typedef struct Stmt Stmt;
typedef struct TraitBound TraitBound;
typedef struct VariantVariant VariantVariant;
typedef struct Decl Decl;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Node Node;
typedef struct NodeKind NodeKind;
typedef struct DeclKind DeclKind;
typedef struct Field Field;
typedef struct AstContext AstContext;
typedef struct TestResult TestResult;
typedef struct Pat Pat;
typedef struct IdentifierTable IdentifierTable;
typedef struct Expr Expr;
typedef struct NodeId NodeId;
typedef struct Diagnostic Diagnostic;
typedef struct DiagInfo DiagInfo;
typedef struct Span Span;
typedef struct Label Label;
typedef struct Attribute Attribute;
typedef struct ImportSymbol ImportSymbol;
typedef struct SourceLoc SourceLoc;
typedef struct IdentEntry IdentEntry;
typedef struct Slice Slice;
typedef struct EnumVariant EnumVariant;
typedef struct Ast Ast;
typedef enum ErrorCode ErrorCode;
typedef enum Severity Severity;
typedef enum TokenKind TokenKind;

typedef uint32_t Str;
typedef uint32_t Ty;
void TestResult_print(TestResult* self);
Slice Slice_from(Slice* self, uint8_t* p, size_t len);
_Bool Slice_eq(Slice* self, Slice b);
_Bool Slice_eqSlice(Slice* self, Slice other);
_Bool Slice_eqCstr(Slice* self, uint8_t* cStr, size_t cStrLen);
Token Lexer_nextToken(Lexer* self);
Token Lexer_lexIdentifier(Lexer* self, uint8_t* start);
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
DiagnosticEngine DiagnosticEngine_init(DiagnosticEngine* self, uint8_t* bufStart, uint8_t* bufEnd);
_Bool DiagnosticEngine_hasErrors(DiagnosticEngine* self);
_Bool DiagnosticEngine_tooManyErrors(DiagnosticEngine* self);
void DiagnosticEngine_reportError(DiagnosticEngine* self, uint8_t* bufStart, uint8_t* bufEnd, uint8_t* errPtr, uint8_t* msg);
void DiagnosticEngine_emitError(DiagnosticEngine* self, ErrorCode code, uint8_t* errPtr, uint8_t* msg);
void DiagnosticEngine_emitWarning(DiagnosticEngine* self, ErrorCode code, uint8_t* errPtr, uint8_t* msg);
void DiagnosticEngine_emitNote(DiagnosticEngine* self, ErrorCode code, uint8_t* errPtr, uint8_t* msg);
void DiagnosticEngine_emitFatal(DiagnosticEngine* self, ErrorCode code, uint8_t* errPtr, uint8_t* msg);
void DiagnosticEngine_renderSimple(DiagnosticEngine* self, ErrorCode code, uint8_t* errPtr, uint8_t* msg, uint8_t* level);
void DiagnosticEngine_renderDiagnostic(DiagnosticEngine* self, Diagnostic* diag);
void DiagnosticEngine_renderLabel(DiagnosticEngine* self, Label* lbl);
Severity DiagInfo_getSeverity(DiagInfo* self, ErrorCode code);
uint8_t* DiagInfo_getFormat(DiagInfo* self, ErrorCode code);
uint32_t SourceMap_addFile(SourceMap* self, Str path, uint8_t* bytes, size_t len);
uint32_t SourceMap_lineColLine(SourceMap* self, uint32_t fileId, uint32_t offset);
uint32_t SourceMap_lineColCol(SourceMap* self, uint32_t fileId, uint32_t offset);
void IdentifierTable_init(IdentifierTable* self, IdentEntry* buf, size_t cap);
size_t IdentifierTable_hash(IdentifierTable* self, uint8_t* name, size_t len);
IdentifierInfo* IdentifierTable_get(IdentifierTable* self, uint8_t* name, size_t len);
void IdentifierTable_addKeyword(IdentifierTable* self, uint8_t* name, size_t len, TokenKind kind);
void IdentifierTable_addKeywords(IdentifierTable* self);
EscapeResult EscapeResult_decodeEscapeSequence(uint8_t* ptr, uint8_t* end);
void Lexer_skipWsCmts(Lexer* self);
Token Lexer_lexNumber(Lexer* self, uint8_t* start);
Token Lexer_lexHex(Lexer* self, uint8_t* start);
Token Lexer_lexBinary(Lexer* self, uint8_t* start);
Token Lexer_lexOctal(Lexer* self, uint8_t* start);
Token Lexer_lexDecimal(Lexer* self, uint8_t* start);
Token Lexer_lexString(Lexer* self, uint8_t* start);
Token Lexer_lexRawString(Lexer* self, uint8_t* start);
Token Lexer_lexOperator(Lexer* self, uint8_t c, uint8_t* start);
Token Lexer_lexPunctuation(Lexer* self, uint8_t c, uint8_t* start);
void AstContext_init(AstContext* self, uint32_t internCap, uint32_t typeCap, uint32_t nodeCap);
void AstContext_deinit(AstContext* self);
_Bool AstContext_streq(AstContext* self, uint8_t* a, size_t aLen, uint8_t* b, size_t bLen);
uint32_t AstContext_intern(AstContext* self, uint8_t* ptr, size_t len);
Ty AstContext_allocTypeSlot(AstContext* self);
NodeId AstContext_allocNodeSlot(AstContext* self);
NodeId AstContext_noneNode(AstContext* self);
uint32_t AstContext_nodeCount(AstContext* self);
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
Ty Parser_parseType(Parser* self);
Ty Parser_makeVoid(Parser* self);
Ty Parser_makeNamed(Parser* self, Str name);
Ty Parser_makePointer(Parser* self, Ty base);
Ty Parser_makeConst(Parser* self, Ty base);
Ty Parser_makeSlice(Parser* self, Ty base);
Ty Parser_makeArray(Parser* self, Ty base, uint32_t len);
Ty Parser_allocTypeKind(Parser* self, TypeKind kind);
Ty Parser_parseBaseType(Parser* self);
Ty Parser_allocType(Parser* self);
int32_t Parser_prec(Parser* self, TokenKind kind);
_Bool Parser_isAssignOp(Parser* self, TokenKind kind);
NodeId Parser_storeExpr(Parser* self, ExprKind kind);
NodeId Parser_parseExpr(Parser* self);
NodeId Parser_parseBinaryExpr(Parser* self, int32_t minPrec);
NodeId Parser_makeBinOp(Parser* self, TokenKind op, NodeId left, NodeId right);
NodeId Parser_parseUnaryExpr(Parser* self);
NodeId Parser_parsePostfixExpr(Parser* self);
NodeId Parser_parsePrimaryExpr(Parser* self);
NodeId Parser_parseSwitchExprCase(Parser* self);
NodeId Parser_parseSwitchExprPattern(Parser* self);
NodeId Parser_storeStmt(Parser* self, StmtKind kind);
NodeId Parser_parseStmt(Parser* self);
NodeId Parser_parseReturnStmt(Parser* self);
NodeId Parser_parseIfStmt(Parser* self);
NodeId Parser_parseWhileStmt(Parser* self);
NodeId Parser_parseForStmt(Parser* self);
NodeId Parser_parseLoopStmt(Parser* self);
NodeId Parser_parseSwitchStmt(Parser* self);
NodeId Parser_parseSwitchStmtCase(Parser* self);
NodeId Parser_parseSwitchStmtPattern(Parser* self);
NodeId Parser_parseDeferStmt(Parser* self);
NodeId Parser_parseBlock(Parser* self);
NodeId Parser_parseComptimeStmt(Parser* self);
NodeId Parser_parseAsmStmt(Parser* self);
NodeId Parser_parseExprOrDecl(Parser* self);
NodeId Parser_storeDecl(Parser* self, DeclKind kind);
NodeId Parser_parseDecl(Parser* self);
_Bool Parser_isTypeStart(Parser* self);
NodeId Parser_parseFuncOrVarDecl(Parser* self, _Bool isPub, _Bool isExtern, _Bool isStatic);
NodeId Parser_parseGenericParams(Parser* self);
NodeId Parser_parseFuncDecl(Parser* self);
NodeId Parser_parseParam(Parser* self);
NodeId Parser_parseStructDecl(Parser* self);
NodeId Parser_parseEnumDecl(Parser* self);
NodeId Parser_parseVariantDecl(Parser* self);
NodeId Parser_parseUnionDecl(Parser* self);
NodeId Parser_parseTraitDecl(Parser* self);
NodeId Parser_parseExtendDecl(Parser* self);
NodeId Parser_parseTypedefDecl(Parser* self);
NodeId Parser_parseDistinctDecl(Parser* self);
NodeId Parser_parseFlagDecl(Parser* self);
NodeId Parser_parseImportDecl(Parser* self);
NodeId Parser_parseModReexport(Parser* self);
NodeId Parser_parseComptimeDecl(Parser* self);


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
    for (size_t i = 0; (i < self->len); (i++)) {
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
    for (size_t i = 0; (i < self->len); (i++)) {
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
    for (size_t i = 0; (i < self->len); (i++)) {
        if ((self->ptr[i] != cStr[i])) {
            return 0;
        }
    }
    return 1;
}



typedef struct GenericParam GenericParam;
typedef struct ExprKind ExprKind;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct SourceMap SourceMap;
typedef struct InternEntry InternEntry;
typedef struct Parser Parser;
typedef struct StmtKind StmtKind;
typedef struct File File;
typedef struct TypeEntry TypeEntry;
typedef struct Param Param;
typedef struct SwitchCase SwitchCase;
typedef struct Token Token;
typedef struct Lexer Lexer;
typedef struct FlagBranch FlagBranch;
typedef struct EscapeResult EscapeResult;
typedef struct FileEntry FileEntry;
typedef struct ParserMark ParserMark;
typedef struct PatKind PatKind;
typedef struct TypeKind TypeKind;
typedef struct Stmt Stmt;
typedef struct TraitBound TraitBound;
typedef struct VariantVariant VariantVariant;
typedef struct Decl Decl;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Node Node;
typedef struct NodeKind NodeKind;
typedef struct DeclKind DeclKind;
typedef struct Field Field;
typedef struct AstContext AstContext;
typedef struct TestResult TestResult;
typedef struct Pat Pat;
typedef struct IdentifierTable IdentifierTable;
typedef struct Expr Expr;
typedef struct NodeId NodeId;
typedef struct Diagnostic Diagnostic;
typedef struct DiagInfo DiagInfo;
typedef struct Span Span;
typedef struct Label Label;
typedef struct Attribute Attribute;
typedef struct ImportSymbol ImportSymbol;
typedef struct SourceLoc SourceLoc;
typedef struct IdentEntry IdentEntry;
typedef struct Slice Slice;
typedef struct EnumVariant EnumVariant;
typedef struct Ast Ast;
typedef enum ErrorCode ErrorCode;
typedef enum Severity Severity;
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




typedef struct GenericParam GenericParam;
typedef struct ExprKind ExprKind;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct SourceMap SourceMap;
typedef struct InternEntry InternEntry;
typedef struct Parser Parser;
typedef struct StmtKind StmtKind;
typedef struct File File;
typedef struct TypeEntry TypeEntry;
typedef struct Param Param;
typedef struct SwitchCase SwitchCase;
typedef struct Token Token;
typedef struct Lexer Lexer;
typedef struct FlagBranch FlagBranch;
typedef struct EscapeResult EscapeResult;
typedef struct FileEntry FileEntry;
typedef struct ParserMark ParserMark;
typedef struct PatKind PatKind;
typedef struct TypeKind TypeKind;
typedef struct Stmt Stmt;
typedef struct TraitBound TraitBound;
typedef struct VariantVariant VariantVariant;
typedef struct Decl Decl;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Node Node;
typedef struct NodeKind NodeKind;
typedef struct DeclKind DeclKind;
typedef struct Field Field;
typedef struct AstContext AstContext;
typedef struct TestResult TestResult;
typedef struct Pat Pat;
typedef struct IdentifierTable IdentifierTable;
typedef struct Expr Expr;
typedef struct NodeId NodeId;
typedef struct Diagnostic Diagnostic;
typedef struct DiagInfo DiagInfo;
typedef struct Span Span;
typedef struct Label Label;
typedef struct Attribute Attribute;
typedef struct ImportSymbol ImportSymbol;
typedef struct SourceLoc SourceLoc;
typedef struct IdentEntry IdentEntry;
typedef struct Slice Slice;
typedef struct EnumVariant EnumVariant;
typedef struct Ast Ast;
typedef enum ErrorCode ErrorCode;
typedef enum Severity Severity;
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




typedef struct GenericParam GenericParam;
typedef struct ExprKind ExprKind;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct SourceMap SourceMap;
typedef struct InternEntry InternEntry;
typedef struct Parser Parser;
typedef struct StmtKind StmtKind;
typedef struct File File;
typedef struct TypeEntry TypeEntry;
typedef struct Param Param;
typedef struct SwitchCase SwitchCase;
typedef struct Token Token;
typedef struct Lexer Lexer;
typedef struct FlagBranch FlagBranch;
typedef struct EscapeResult EscapeResult;
typedef struct FileEntry FileEntry;
typedef struct ParserMark ParserMark;
typedef struct PatKind PatKind;
typedef struct TypeKind TypeKind;
typedef struct Stmt Stmt;
typedef struct TraitBound TraitBound;
typedef struct VariantVariant VariantVariant;
typedef struct Decl Decl;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Node Node;
typedef struct NodeKind NodeKind;
typedef struct DeclKind DeclKind;
typedef struct Field Field;
typedef struct AstContext AstContext;
typedef struct TestResult TestResult;
typedef struct Pat Pat;
typedef struct IdentifierTable IdentifierTable;
typedef struct Expr Expr;
typedef struct NodeId NodeId;
typedef struct Diagnostic Diagnostic;
typedef struct DiagInfo DiagInfo;
typedef struct Span Span;
typedef struct Label Label;
typedef struct Attribute Attribute;
typedef struct ImportSymbol ImportSymbol;
typedef struct SourceLoc SourceLoc;
typedef struct IdentEntry IdentEntry;
typedef struct Slice Slice;
typedef struct EnumVariant EnumVariant;
typedef struct Ast Ast;
typedef enum ErrorCode ErrorCode;
typedef enum Severity Severity;
typedef enum TokenKind TokenKind;


typedef uint32_t Str;

typedef struct SourceLoc {
    uint32_t data;
} SourceLoc;

typedef struct NodeId {
    uint32_t index;
} NodeId;




typedef struct GenericParam GenericParam;
typedef struct ExprKind ExprKind;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct SourceMap SourceMap;
typedef struct InternEntry InternEntry;
typedef struct Parser Parser;
typedef struct StmtKind StmtKind;
typedef struct File File;
typedef struct TypeEntry TypeEntry;
typedef struct Param Param;
typedef struct SwitchCase SwitchCase;
typedef struct Token Token;
typedef struct Lexer Lexer;
typedef struct FlagBranch FlagBranch;
typedef struct EscapeResult EscapeResult;
typedef struct FileEntry FileEntry;
typedef struct ParserMark ParserMark;
typedef struct PatKind PatKind;
typedef struct TypeKind TypeKind;
typedef struct Stmt Stmt;
typedef struct TraitBound TraitBound;
typedef struct VariantVariant VariantVariant;
typedef struct Decl Decl;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Node Node;
typedef struct NodeKind NodeKind;
typedef struct DeclKind DeclKind;
typedef struct Field Field;
typedef struct AstContext AstContext;
typedef struct TestResult TestResult;
typedef struct Pat Pat;
typedef struct IdentifierTable IdentifierTable;
typedef struct Expr Expr;
typedef struct NodeId NodeId;
typedef struct Diagnostic Diagnostic;
typedef struct DiagInfo DiagInfo;
typedef struct Span Span;
typedef struct Label Label;
typedef struct Attribute Attribute;
typedef struct ImportSymbol ImportSymbol;
typedef struct SourceLoc SourceLoc;
typedef struct IdentEntry IdentEntry;
typedef struct Slice Slice;
typedef struct EnumVariant EnumVariant;
typedef struct Ast Ast;
typedef enum ErrorCode ErrorCode;
typedef enum Severity Severity;
typedef enum TokenKind TokenKind;


Severity DiagInfo_getSeverity(DiagInfo* self, ErrorCode code);
uint8_t* DiagInfo_getFormat(DiagInfo* self, ErrorCode code);

enum Severity {
    Severity_Ignored = 0,
    Severity_Note,
    Severity_Warning,
    Severity_Error,
    Severity_Fatal
};

typedef struct DiagInfo {
    ErrorCode code;
    Severity severity;
    uint8_t* format;
} DiagInfo;

Severity DiagInfo_getSeverity(DiagInfo* self, ErrorCode code) {
    switch (code) {
        case ErrorCode_LexUnknownChar:
            return Severity_Error;
            break;
        case ErrorCode_LexUnterminatedString:
            return Severity_Error;
            break;
        case ErrorCode_LexUnterminatedChar:
            return Severity_Error;
            break;
        case ErrorCode_LexUnterminatedComment:
            return Severity_Error;
            break;
        case ErrorCode_LexInvalidEscape:
            return Severity_Error;
            break;
        case ErrorCode_LexInvalidNumber:
            return Severity_Error;
            break;
        case ErrorCode_LexInvalidChar:
            return Severity_Error;
            break;
        case ErrorCode_ParseExpectedToken:
            return Severity_Error;
            break;
        case ErrorCode_ParseExpectedExpr:
            return Severity_Error;
            break;
        case ErrorCode_ParseExpectedType:
            return Severity_Error;
            break;
        case ErrorCode_ParseExpectedDecl:
            return Severity_Error;
            break;
        case ErrorCode_ParseExpectedStmt:
            return Severity_Error;
            break;
        case ErrorCode_ParseUnexpectedEof:
            return Severity_Error;
            break;
        case ErrorCode_ParseInvalidAssignTarget:
            return Severity_Error;
            break;
        case ErrorCode_ParseDuplicateModifier:
            return Severity_Warning;
            break;
        case ErrorCode_ParseMissingSemicolon:
            return Severity_Error;
            break;
        case ErrorCode_SemaUndeclaredIdent:
            return Severity_Error;
            break;
        case ErrorCode_SemaTypeMismatch:
            return Severity_Error;
            break;
        case ErrorCode_SemaArityMismatch:
            return Severity_Error;
            break;
        case ErrorCode_SemaDuplicateDecl:
            return Severity_Error;
            break;
        case ErrorCode_SemaInvalidCast:
            return Severity_Error;
            break;
        case ErrorCode_SemaUnknownMember:
            return Severity_Error;
            break;
        case ErrorCode_CodegenUnsupported:
            return Severity_Error;
            break;
        case ErrorCode_CodegenInternal:
            return Severity_Fatal;
            break;
        case ErrorCode_DriverFileNotFound:
            return Severity_Fatal;
            break;
        case ErrorCode_DriverInvalidFlag:
            return Severity_Error;
            break;
        case ErrorCode_DriverOutOfMemory:
            return Severity_Fatal;
            break;
        default:
            return Severity_Error;
            break;
    }
}
uint8_t* DiagInfo_getFormat(DiagInfo* self, ErrorCode code) {
    switch (code) {
        case ErrorCode_LexUnknownChar:
            return "unknown character";
            break;
        case ErrorCode_LexUnterminatedString:
            return "unterminated string literal";
            break;
        case ErrorCode_LexUnterminatedChar:
            return "unterminated character literal";
            break;
        case ErrorCode_LexUnterminatedComment:
            return "unterminated block comment";
            break;
        case ErrorCode_LexInvalidEscape:
            return "invalid escape sequence";
            break;
        case ErrorCode_LexInvalidNumber:
            return "invalid numeric literal";
            break;
        case ErrorCode_LexInvalidChar:
            return "invalid character literal";
            break;
        case ErrorCode_ParseExpectedToken:
            return "expected token";
            break;
        case ErrorCode_ParseExpectedExpr:
            return "expected expression";
            break;
        case ErrorCode_ParseExpectedType:
            return "expected type";
            break;
        case ErrorCode_ParseExpectedDecl:
            return "expected declaration";
            break;
        case ErrorCode_ParseExpectedStmt:
            return "expected statement";
            break;
        case ErrorCode_ParseUnexpectedEof:
            return "unexpected end of file";
            break;
        case ErrorCode_ParseInvalidAssignTarget:
            return "invalid assignment target";
            break;
        case ErrorCode_ParseDuplicateModifier:
            return "duplicate modifier";
            break;
        case ErrorCode_ParseMissingSemicolon:
            return "expected ';'";
            break;
        case ErrorCode_SemaUndeclaredIdent:
            return "use of undeclared identifier";
            break;
        case ErrorCode_SemaTypeMismatch:
            return "type mismatch";
            break;
        case ErrorCode_SemaArityMismatch:
            return "wrong number of arguments";
            break;
        case ErrorCode_SemaDuplicateDecl:
            return "redefinition";
            break;
        case ErrorCode_SemaInvalidCast:
            return "invalid cast";
            break;
        case ErrorCode_SemaUnknownMember:
            return "no member named";
            break;
        case ErrorCode_CodegenUnsupported:
            return "unsupported construct in codegen";
            break;
        case ErrorCode_CodegenInternal:
            return "internal codegen error";
            break;
        case ErrorCode_DriverFileNotFound:
            return "file not found";
            break;
        case ErrorCode_DriverInvalidFlag:
            return "invalid flag";
            break;
        case ErrorCode_DriverOutOfMemory:
            return "out of memory";
            break;
        default:
            return "unknown error";
            break;
    }
}



typedef struct GenericParam GenericParam;
typedef struct ExprKind ExprKind;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct SourceMap SourceMap;
typedef struct InternEntry InternEntry;
typedef struct Parser Parser;
typedef struct StmtKind StmtKind;
typedef struct File File;
typedef struct TypeEntry TypeEntry;
typedef struct Param Param;
typedef struct SwitchCase SwitchCase;
typedef struct Token Token;
typedef struct Lexer Lexer;
typedef struct FlagBranch FlagBranch;
typedef struct EscapeResult EscapeResult;
typedef struct FileEntry FileEntry;
typedef struct ParserMark ParserMark;
typedef struct PatKind PatKind;
typedef struct TypeKind TypeKind;
typedef struct Stmt Stmt;
typedef struct TraitBound TraitBound;
typedef struct VariantVariant VariantVariant;
typedef struct Decl Decl;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Node Node;
typedef struct NodeKind NodeKind;
typedef struct DeclKind DeclKind;
typedef struct Field Field;
typedef struct AstContext AstContext;
typedef struct TestResult TestResult;
typedef struct Pat Pat;
typedef struct IdentifierTable IdentifierTable;
typedef struct Expr Expr;
typedef struct NodeId NodeId;
typedef struct Diagnostic Diagnostic;
typedef struct DiagInfo DiagInfo;
typedef struct Span Span;
typedef struct Label Label;
typedef struct Attribute Attribute;
typedef struct ImportSymbol ImportSymbol;
typedef struct SourceLoc SourceLoc;
typedef struct IdentEntry IdentEntry;
typedef struct Slice Slice;
typedef struct EnumVariant EnumVariant;
typedef struct Ast Ast;
typedef enum ErrorCode ErrorCode;
typedef enum Severity Severity;
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
    uint8_t* text;
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



typedef struct GenericParam GenericParam;
typedef struct ExprKind ExprKind;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct SourceMap SourceMap;
typedef struct InternEntry InternEntry;
typedef struct Parser Parser;
typedef struct StmtKind StmtKind;
typedef struct File File;
typedef struct TypeEntry TypeEntry;
typedef struct Param Param;
typedef struct SwitchCase SwitchCase;
typedef struct Token Token;
typedef struct Lexer Lexer;
typedef struct FlagBranch FlagBranch;
typedef struct EscapeResult EscapeResult;
typedef struct FileEntry FileEntry;
typedef struct ParserMark ParserMark;
typedef struct PatKind PatKind;
typedef struct TypeKind TypeKind;
typedef struct Stmt Stmt;
typedef struct TraitBound TraitBound;
typedef struct VariantVariant VariantVariant;
typedef struct Decl Decl;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Node Node;
typedef struct NodeKind NodeKind;
typedef struct DeclKind DeclKind;
typedef struct Field Field;
typedef struct AstContext AstContext;
typedef struct TestResult TestResult;
typedef struct Pat Pat;
typedef struct IdentifierTable IdentifierTable;
typedef struct Expr Expr;
typedef struct NodeId NodeId;
typedef struct Diagnostic Diagnostic;
typedef struct DiagInfo DiagInfo;
typedef struct Span Span;
typedef struct Label Label;
typedef struct Attribute Attribute;
typedef struct ImportSymbol ImportSymbol;
typedef struct SourceLoc SourceLoc;
typedef struct IdentEntry IdentEntry;
typedef struct Slice Slice;
typedef struct EnumVariant EnumVariant;
typedef struct Ast Ast;
typedef enum ErrorCode ErrorCode;
typedef enum Severity Severity;
typedef enum TokenKind TokenKind;

extern int32_t printf(uint8_t* fmt, ...);
extern int32_t write(int32_t fd, uint8_t* buf, size_t len);

DiagnosticEngine DiagnosticEngine_init(DiagnosticEngine* self, uint8_t* bufStart, uint8_t* bufEnd);
_Bool DiagnosticEngine_hasErrors(DiagnosticEngine* self);
_Bool DiagnosticEngine_tooManyErrors(DiagnosticEngine* self);
void DiagnosticEngine_reportError(DiagnosticEngine* self, uint8_t* bufStart, uint8_t* bufEnd, uint8_t* errPtr, uint8_t* msg);
void DiagnosticEngine_emitError(DiagnosticEngine* self, ErrorCode code, uint8_t* errPtr, uint8_t* msg);
void DiagnosticEngine_emitWarning(DiagnosticEngine* self, ErrorCode code, uint8_t* errPtr, uint8_t* msg);
void DiagnosticEngine_emitNote(DiagnosticEngine* self, ErrorCode code, uint8_t* errPtr, uint8_t* msg);
void DiagnosticEngine_emitFatal(DiagnosticEngine* self, ErrorCode code, uint8_t* errPtr, uint8_t* msg);
void DiagnosticEngine_renderSimple(DiagnosticEngine* self, ErrorCode code, uint8_t* errPtr, uint8_t* msg, uint8_t* level);
void DiagnosticEngine_renderDiagnostic(DiagnosticEngine* self, Diagnostic* diag);
void DiagnosticEngine_renderLabel(DiagnosticEngine* self, Label* lbl);

typedef struct Diagnostic {
    uint32_t code;
    uint32_t severity;
    uint8_t* message;
    uint8_t* detail;
    Label* labels;
    uint32_t labelsLen;
    uint8_t* why;
    uint8_t* fix;
    uint8_t* learn;
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
void DiagnosticEngine_reportError(DiagnosticEngine* self, uint8_t* bufStart, uint8_t* bufEnd, uint8_t* errPtr, uint8_t* msg) {
    if (DiagnosticEngine_tooManyErrors(self)) {
        return;
    }
    (self->errors = (self->errors + 1));
    (self->bufStart = bufStart);
    (self->bufEnd = bufEnd);
    DiagnosticEngine_renderSimple(self, ErrorCode_LexInvalidChar, errPtr, msg, "error");
}
void DiagnosticEngine_emitError(DiagnosticEngine* self, ErrorCode code, uint8_t* errPtr, uint8_t* msg) {
    if (DiagnosticEngine_tooManyErrors(self)) {
        return;
    }
    (self->errors = (self->errors + 1));
    DiagnosticEngine_renderSimple(self, code, errPtr, msg, "error");
}
void DiagnosticEngine_emitWarning(DiagnosticEngine* self, ErrorCode code, uint8_t* errPtr, uint8_t* msg) {
    (self->warnings = (self->warnings + 1));
    DiagnosticEngine_renderSimple(self, code, errPtr, msg, "warning");
}
void DiagnosticEngine_emitNote(DiagnosticEngine* self, ErrorCode code, uint8_t* errPtr, uint8_t* msg) {
    DiagnosticEngine_renderSimple(self, code, errPtr, msg, "note");
}
void DiagnosticEngine_emitFatal(DiagnosticEngine* self, ErrorCode code, uint8_t* errPtr, uint8_t* msg) {
    (self->errors = (self->errors + 1));
    DiagnosticEngine_renderSimple(self, code, errPtr, msg, "fatal error");
}
void DiagnosticEngine_renderSimple(DiagnosticEngine* self, ErrorCode code, uint8_t* errPtr, uint8_t* msg, uint8_t* level) {
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



typedef struct GenericParam GenericParam;
typedef struct ExprKind ExprKind;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct SourceMap SourceMap;
typedef struct InternEntry InternEntry;
typedef struct Parser Parser;
typedef struct StmtKind StmtKind;
typedef struct File File;
typedef struct TypeEntry TypeEntry;
typedef struct Param Param;
typedef struct SwitchCase SwitchCase;
typedef struct Token Token;
typedef struct Lexer Lexer;
typedef struct FlagBranch FlagBranch;
typedef struct EscapeResult EscapeResult;
typedef struct FileEntry FileEntry;
typedef struct ParserMark ParserMark;
typedef struct PatKind PatKind;
typedef struct TypeKind TypeKind;
typedef struct Stmt Stmt;
typedef struct TraitBound TraitBound;
typedef struct VariantVariant VariantVariant;
typedef struct Decl Decl;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Node Node;
typedef struct NodeKind NodeKind;
typedef struct DeclKind DeclKind;
typedef struct Field Field;
typedef struct AstContext AstContext;
typedef struct TestResult TestResult;
typedef struct Pat Pat;
typedef struct IdentifierTable IdentifierTable;
typedef struct Expr Expr;
typedef struct NodeId NodeId;
typedef struct Diagnostic Diagnostic;
typedef struct DiagInfo DiagInfo;
typedef struct Span Span;
typedef struct Label Label;
typedef struct Attribute Attribute;
typedef struct ImportSymbol ImportSymbol;
typedef struct SourceLoc SourceLoc;
typedef struct IdentEntry IdentEntry;
typedef struct Slice Slice;
typedef struct EnumVariant EnumVariant;
typedef struct Ast Ast;
typedef enum ErrorCode ErrorCode;
typedef enum Severity Severity;
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
    for (size_t i = 0; (i < cap); (i++)) {
        (self->entries[i].occupied = 0);
    }
}
size_t IdentifierTable_hash(IdentifierTable* self, uint8_t* name, size_t len) {
    size_t h = 14695981039346656037;
    for (size_t i = 0; (i < len); (i++)) {
        (h ^= ((size_t)name[i]));
        (h *= 1099511628211);
    }
    return h;
}
IdentifierInfo* IdentifierTable_get(IdentifierTable* self, uint8_t* name, size_t len) {
    size_t idx = (IdentifierTable_hash(self, name, len) & (self->capacity - 1));
    for (size_t probe = 0; (probe < self->capacity); (probe++)) {
        size_t pos = ((idx + probe) & (self->capacity - 1));
        IdentEntry* e = (& self->entries[pos]);
        if ((! e->occupied)) {
            (e->info.name = name);
            (e->info.nameLen = len);
            (e->info.kind = TokenKind_Ident);
            (e->info.isKeyword = 0);
            (e->occupied = 1);
            (self->count++);
            return (& e->info);
        }
        if ((e->info.nameLen == len)) {
            _Bool match = 1;
            for (size_t i = 0; (i < len); (i++)) {
                if ((e->info.name[i] != name[i])) {
                    (match = 0);
                    break;
                }
            }
            if (match) {
                return (& e->info);
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



typedef struct GenericParam GenericParam;
typedef struct ExprKind ExprKind;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct SourceMap SourceMap;
typedef struct InternEntry InternEntry;
typedef struct Parser Parser;
typedef struct StmtKind StmtKind;
typedef struct File File;
typedef struct TypeEntry TypeEntry;
typedef struct Param Param;
typedef struct SwitchCase SwitchCase;
typedef struct Token Token;
typedef struct Lexer Lexer;
typedef struct FlagBranch FlagBranch;
typedef struct EscapeResult EscapeResult;
typedef struct FileEntry FileEntry;
typedef struct ParserMark ParserMark;
typedef struct PatKind PatKind;
typedef struct TypeKind TypeKind;
typedef struct Stmt Stmt;
typedef struct TraitBound TraitBound;
typedef struct VariantVariant VariantVariant;
typedef struct Decl Decl;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Node Node;
typedef struct NodeKind NodeKind;
typedef struct DeclKind DeclKind;
typedef struct Field Field;
typedef struct AstContext AstContext;
typedef struct TestResult TestResult;
typedef struct Pat Pat;
typedef struct IdentifierTable IdentifierTable;
typedef struct Expr Expr;
typedef struct NodeId NodeId;
typedef struct Diagnostic Diagnostic;
typedef struct DiagInfo DiagInfo;
typedef struct Span Span;
typedef struct Label Label;
typedef struct Attribute Attribute;
typedef struct ImportSymbol ImportSymbol;
typedef struct SourceLoc SourceLoc;
typedef struct IdentEntry IdentEntry;
typedef struct Slice Slice;
typedef struct EnumVariant EnumVariant;
typedef struct Ast Ast;
typedef enum ErrorCode ErrorCode;
typedef enum Severity Severity;
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



typedef struct GenericParam GenericParam;
typedef struct ExprKind ExprKind;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct SourceMap SourceMap;
typedef struct InternEntry InternEntry;
typedef struct Parser Parser;
typedef struct StmtKind StmtKind;
typedef struct File File;
typedef struct TypeEntry TypeEntry;
typedef struct Param Param;
typedef struct SwitchCase SwitchCase;
typedef struct Token Token;
typedef struct Lexer Lexer;
typedef struct FlagBranch FlagBranch;
typedef struct EscapeResult EscapeResult;
typedef struct FileEntry FileEntry;
typedef struct ParserMark ParserMark;
typedef struct PatKind PatKind;
typedef struct TypeKind TypeKind;
typedef struct Stmt Stmt;
typedef struct TraitBound TraitBound;
typedef struct VariantVariant VariantVariant;
typedef struct Decl Decl;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Node Node;
typedef struct NodeKind NodeKind;
typedef struct DeclKind DeclKind;
typedef struct Field Field;
typedef struct AstContext AstContext;
typedef struct TestResult TestResult;
typedef struct Pat Pat;
typedef struct IdentifierTable IdentifierTable;
typedef struct Expr Expr;
typedef struct NodeId NodeId;
typedef struct Diagnostic Diagnostic;
typedef struct DiagInfo DiagInfo;
typedef struct Span Span;
typedef struct Label Label;
typedef struct Attribute Attribute;
typedef struct ImportSymbol ImportSymbol;
typedef struct SourceLoc SourceLoc;
typedef struct IdentEntry IdentEntry;
typedef struct Slice Slice;
typedef struct EnumVariant EnumVariant;
typedef struct Ast Ast;
typedef enum ErrorCode ErrorCode;
typedef enum Severity Severity;
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



typedef struct GenericParam GenericParam;
typedef struct ExprKind ExprKind;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct SourceMap SourceMap;
typedef struct InternEntry InternEntry;
typedef struct Parser Parser;
typedef struct StmtKind StmtKind;
typedef struct File File;
typedef struct TypeEntry TypeEntry;
typedef struct Param Param;
typedef struct SwitchCase SwitchCase;
typedef struct Token Token;
typedef struct Lexer Lexer;
typedef struct FlagBranch FlagBranch;
typedef struct EscapeResult EscapeResult;
typedef struct FileEntry FileEntry;
typedef struct ParserMark ParserMark;
typedef struct PatKind PatKind;
typedef struct TypeKind TypeKind;
typedef struct Stmt Stmt;
typedef struct TraitBound TraitBound;
typedef struct VariantVariant VariantVariant;
typedef struct Decl Decl;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Node Node;
typedef struct NodeKind NodeKind;
typedef struct DeclKind DeclKind;
typedef struct Field Field;
typedef struct AstContext AstContext;
typedef struct TestResult TestResult;
typedef struct Pat Pat;
typedef struct IdentifierTable IdentifierTable;
typedef struct Expr Expr;
typedef struct NodeId NodeId;
typedef struct Diagnostic Diagnostic;
typedef struct DiagInfo DiagInfo;
typedef struct Span Span;
typedef struct Label Label;
typedef struct Attribute Attribute;
typedef struct ImportSymbol ImportSymbol;
typedef struct SourceLoc SourceLoc;
typedef struct IdentEntry IdentEntry;
typedef struct Slice Slice;
typedef struct EnumVariant EnumVariant;
typedef struct Ast Ast;
typedef enum ErrorCode ErrorCode;
typedef enum Severity Severity;
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
                    for (size_t i = 0; (i < 4); (i++)) {
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
                    for (size_t i = 0; (i < 8); (i++)) {
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



typedef struct GenericParam GenericParam;
typedef struct ExprKind ExprKind;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct SourceMap SourceMap;
typedef struct InternEntry InternEntry;
typedef struct Parser Parser;
typedef struct StmtKind StmtKind;
typedef struct File File;
typedef struct TypeEntry TypeEntry;
typedef struct Param Param;
typedef struct SwitchCase SwitchCase;
typedef struct Token Token;
typedef struct Lexer Lexer;
typedef struct FlagBranch FlagBranch;
typedef struct EscapeResult EscapeResult;
typedef struct FileEntry FileEntry;
typedef struct ParserMark ParserMark;
typedef struct PatKind PatKind;
typedef struct TypeKind TypeKind;
typedef struct Stmt Stmt;
typedef struct TraitBound TraitBound;
typedef struct VariantVariant VariantVariant;
typedef struct Decl Decl;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Node Node;
typedef struct NodeKind NodeKind;
typedef struct DeclKind DeclKind;
typedef struct Field Field;
typedef struct AstContext AstContext;
typedef struct TestResult TestResult;
typedef struct Pat Pat;
typedef struct IdentifierTable IdentifierTable;
typedef struct Expr Expr;
typedef struct NodeId NodeId;
typedef struct Diagnostic Diagnostic;
typedef struct DiagInfo DiagInfo;
typedef struct Span Span;
typedef struct Label Label;
typedef struct Attribute Attribute;
typedef struct ImportSymbol ImportSymbol;
typedef struct SourceLoc SourceLoc;
typedef struct IdentEntry IdentEntry;
typedef struct Slice Slice;
typedef struct EnumVariant EnumVariant;
typedef struct Ast Ast;
typedef enum ErrorCode ErrorCode;
typedef enum Severity Severity;
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



typedef struct GenericParam GenericParam;
typedef struct ExprKind ExprKind;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct SourceMap SourceMap;
typedef struct InternEntry InternEntry;
typedef struct Parser Parser;
typedef struct StmtKind StmtKind;
typedef struct File File;
typedef struct TypeEntry TypeEntry;
typedef struct Param Param;
typedef struct SwitchCase SwitchCase;
typedef struct Token Token;
typedef struct Lexer Lexer;
typedef struct FlagBranch FlagBranch;
typedef struct EscapeResult EscapeResult;
typedef struct FileEntry FileEntry;
typedef struct ParserMark ParserMark;
typedef struct PatKind PatKind;
typedef struct TypeKind TypeKind;
typedef struct Stmt Stmt;
typedef struct TraitBound TraitBound;
typedef struct VariantVariant VariantVariant;
typedef struct Decl Decl;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Node Node;
typedef struct NodeKind NodeKind;
typedef struct DeclKind DeclKind;
typedef struct Field Field;
typedef struct AstContext AstContext;
typedef struct TestResult TestResult;
typedef struct Pat Pat;
typedef struct IdentifierTable IdentifierTable;
typedef struct Expr Expr;
typedef struct NodeId NodeId;
typedef struct Diagnostic Diagnostic;
typedef struct DiagInfo DiagInfo;
typedef struct Span Span;
typedef struct Label Label;
typedef struct Attribute Attribute;
typedef struct ImportSymbol ImportSymbol;
typedef struct SourceLoc SourceLoc;
typedef struct IdentEntry IdentEntry;
typedef struct Slice Slice;
typedef struct EnumVariant EnumVariant;
typedef struct Ast Ast;
typedef enum ErrorCode ErrorCode;
typedef enum Severity Severity;
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



typedef struct GenericParam GenericParam;
typedef struct ExprKind ExprKind;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct SourceMap SourceMap;
typedef struct InternEntry InternEntry;
typedef struct Parser Parser;
typedef struct StmtKind StmtKind;
typedef struct File File;
typedef struct TypeEntry TypeEntry;
typedef struct Param Param;
typedef struct SwitchCase SwitchCase;
typedef struct Token Token;
typedef struct Lexer Lexer;
typedef struct FlagBranch FlagBranch;
typedef struct EscapeResult EscapeResult;
typedef struct FileEntry FileEntry;
typedef struct ParserMark ParserMark;
typedef struct PatKind PatKind;
typedef struct TypeKind TypeKind;
typedef struct Stmt Stmt;
typedef struct TraitBound TraitBound;
typedef struct VariantVariant VariantVariant;
typedef struct Decl Decl;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Node Node;
typedef struct NodeKind NodeKind;
typedef struct DeclKind DeclKind;
typedef struct Field Field;
typedef struct AstContext AstContext;
typedef struct TestResult TestResult;
typedef struct Pat Pat;
typedef struct IdentifierTable IdentifierTable;
typedef struct Expr Expr;
typedef struct NodeId NodeId;
typedef struct Diagnostic Diagnostic;
typedef struct DiagInfo DiagInfo;
typedef struct Span Span;
typedef struct Label Label;
typedef struct Attribute Attribute;
typedef struct ImportSymbol ImportSymbol;
typedef struct SourceLoc SourceLoc;
typedef struct IdentEntry IdentEntry;
typedef struct Slice Slice;
typedef struct EnumVariant EnumVariant;
typedef struct Ast Ast;
typedef enum ErrorCode ErrorCode;
typedef enum Severity Severity;
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
            for (size_t i = 0; (i < delimLen); (i++)) {
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



typedef struct GenericParam GenericParam;
typedef struct ExprKind ExprKind;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct SourceMap SourceMap;
typedef struct InternEntry InternEntry;
typedef struct Parser Parser;
typedef struct StmtKind StmtKind;
typedef struct File File;
typedef struct TypeEntry TypeEntry;
typedef struct Param Param;
typedef struct SwitchCase SwitchCase;
typedef struct Token Token;
typedef struct Lexer Lexer;
typedef struct FlagBranch FlagBranch;
typedef struct EscapeResult EscapeResult;
typedef struct FileEntry FileEntry;
typedef struct ParserMark ParserMark;
typedef struct PatKind PatKind;
typedef struct TypeKind TypeKind;
typedef struct Stmt Stmt;
typedef struct TraitBound TraitBound;
typedef struct VariantVariant VariantVariant;
typedef struct Decl Decl;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Node Node;
typedef struct NodeKind NodeKind;
typedef struct DeclKind DeclKind;
typedef struct Field Field;
typedef struct AstContext AstContext;
typedef struct TestResult TestResult;
typedef struct Pat Pat;
typedef struct IdentifierTable IdentifierTable;
typedef struct Expr Expr;
typedef struct NodeId NodeId;
typedef struct Diagnostic Diagnostic;
typedef struct DiagInfo DiagInfo;
typedef struct Span Span;
typedef struct Label Label;
typedef struct Attribute Attribute;
typedef struct ImportSymbol ImportSymbol;
typedef struct SourceLoc SourceLoc;
typedef struct IdentEntry IdentEntry;
typedef struct Slice Slice;
typedef struct EnumVariant EnumVariant;
typedef struct Ast Ast;
typedef enum ErrorCode ErrorCode;
typedef enum Severity Severity;
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



typedef struct GenericParam GenericParam;
typedef struct ExprKind ExprKind;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct SourceMap SourceMap;
typedef struct InternEntry InternEntry;
typedef struct Parser Parser;
typedef struct StmtKind StmtKind;
typedef struct File File;
typedef struct TypeEntry TypeEntry;
typedef struct Param Param;
typedef struct SwitchCase SwitchCase;
typedef struct Token Token;
typedef struct Lexer Lexer;
typedef struct FlagBranch FlagBranch;
typedef struct EscapeResult EscapeResult;
typedef struct FileEntry FileEntry;
typedef struct ParserMark ParserMark;
typedef struct PatKind PatKind;
typedef struct TypeKind TypeKind;
typedef struct Stmt Stmt;
typedef struct TraitBound TraitBound;
typedef struct VariantVariant VariantVariant;
typedef struct Decl Decl;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Node Node;
typedef struct NodeKind NodeKind;
typedef struct DeclKind DeclKind;
typedef struct Field Field;
typedef struct AstContext AstContext;
typedef struct TestResult TestResult;
typedef struct Pat Pat;
typedef struct IdentifierTable IdentifierTable;
typedef struct Expr Expr;
typedef struct NodeId NodeId;
typedef struct Diagnostic Diagnostic;
typedef struct DiagInfo DiagInfo;
typedef struct Span Span;
typedef struct Label Label;
typedef struct Attribute Attribute;
typedef struct ImportSymbol ImportSymbol;
typedef struct SourceLoc SourceLoc;
typedef struct IdentEntry IdentEntry;
typedef struct Slice Slice;
typedef struct EnumVariant EnumVariant;
typedef struct Ast Ast;
typedef enum ErrorCode ErrorCode;
typedef enum Severity Severity;
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



typedef struct GenericParam GenericParam;
typedef struct ExprKind ExprKind;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct SourceMap SourceMap;
typedef struct InternEntry InternEntry;
typedef struct Parser Parser;
typedef struct StmtKind StmtKind;
typedef struct File File;
typedef struct TypeEntry TypeEntry;
typedef struct Param Param;
typedef struct SwitchCase SwitchCase;
typedef struct Token Token;
typedef struct Lexer Lexer;
typedef struct FlagBranch FlagBranch;
typedef struct EscapeResult EscapeResult;
typedef struct FileEntry FileEntry;
typedef struct ParserMark ParserMark;
typedef struct PatKind PatKind;
typedef struct TypeKind TypeKind;
typedef struct Stmt Stmt;
typedef struct TraitBound TraitBound;
typedef struct VariantVariant VariantVariant;
typedef struct Decl Decl;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Node Node;
typedef struct NodeKind NodeKind;
typedef struct DeclKind DeclKind;
typedef struct Field Field;
typedef struct AstContext AstContext;
typedef struct TestResult TestResult;
typedef struct Pat Pat;
typedef struct IdentifierTable IdentifierTable;
typedef struct Expr Expr;
typedef struct NodeId NodeId;
typedef struct Diagnostic Diagnostic;
typedef struct DiagInfo DiagInfo;
typedef struct Span Span;
typedef struct Label Label;
typedef struct Attribute Attribute;
typedef struct ImportSymbol ImportSymbol;
typedef struct SourceLoc SourceLoc;
typedef struct IdentEntry IdentEntry;
typedef struct Slice Slice;
typedef struct EnumVariant EnumVariant;
typedef struct Ast Ast;
typedef enum ErrorCode ErrorCode;
typedef enum Severity Severity;
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




typedef struct GenericParam GenericParam;
typedef struct ExprKind ExprKind;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct SourceMap SourceMap;
typedef struct InternEntry InternEntry;
typedef struct Parser Parser;
typedef struct StmtKind StmtKind;
typedef struct File File;
typedef struct TypeEntry TypeEntry;
typedef struct Param Param;
typedef struct SwitchCase SwitchCase;
typedef struct Token Token;
typedef struct Lexer Lexer;
typedef struct FlagBranch FlagBranch;
typedef struct EscapeResult EscapeResult;
typedef struct FileEntry FileEntry;
typedef struct ParserMark ParserMark;
typedef struct PatKind PatKind;
typedef struct TypeKind TypeKind;
typedef struct Stmt Stmt;
typedef struct TraitBound TraitBound;
typedef struct VariantVariant VariantVariant;
typedef struct Decl Decl;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Node Node;
typedef struct NodeKind NodeKind;
typedef struct DeclKind DeclKind;
typedef struct Field Field;
typedef struct AstContext AstContext;
typedef struct TestResult TestResult;
typedef struct Pat Pat;
typedef struct IdentifierTable IdentifierTable;
typedef struct Expr Expr;
typedef struct NodeId NodeId;
typedef struct Diagnostic Diagnostic;
typedef struct DiagInfo DiagInfo;
typedef struct Span Span;
typedef struct Label Label;
typedef struct Attribute Attribute;
typedef struct ImportSymbol ImportSymbol;
typedef struct SourceLoc SourceLoc;
typedef struct IdentEntry IdentEntry;
typedef struct Slice Slice;
typedef struct EnumVariant EnumVariant;
typedef struct Ast Ast;
typedef enum ErrorCode ErrorCode;
typedef enum Severity Severity;
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




typedef struct GenericParam GenericParam;
typedef struct ExprKind ExprKind;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct SourceMap SourceMap;
typedef struct InternEntry InternEntry;
typedef struct Parser Parser;
typedef struct StmtKind StmtKind;
typedef struct File File;
typedef struct TypeEntry TypeEntry;
typedef struct Param Param;
typedef struct SwitchCase SwitchCase;
typedef struct Token Token;
typedef struct Lexer Lexer;
typedef struct FlagBranch FlagBranch;
typedef struct EscapeResult EscapeResult;
typedef struct FileEntry FileEntry;
typedef struct ParserMark ParserMark;
typedef struct PatKind PatKind;
typedef struct TypeKind TypeKind;
typedef struct Stmt Stmt;
typedef struct TraitBound TraitBound;
typedef struct VariantVariant VariantVariant;
typedef struct Decl Decl;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Node Node;
typedef struct NodeKind NodeKind;
typedef struct DeclKind DeclKind;
typedef struct Field Field;
typedef struct AstContext AstContext;
typedef struct TestResult TestResult;
typedef struct Pat Pat;
typedef struct IdentifierTable IdentifierTable;
typedef struct Expr Expr;
typedef struct NodeId NodeId;
typedef struct Diagnostic Diagnostic;
typedef struct DiagInfo DiagInfo;
typedef struct Span Span;
typedef struct Label Label;
typedef struct Attribute Attribute;
typedef struct ImportSymbol ImportSymbol;
typedef struct SourceLoc SourceLoc;
typedef struct IdentEntry IdentEntry;
typedef struct Slice Slice;
typedef struct EnumVariant EnumVariant;
typedef struct Ast Ast;
typedef enum ErrorCode ErrorCode;
typedef enum Severity Severity;
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




typedef struct GenericParam GenericParam;
typedef struct ExprKind ExprKind;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct SourceMap SourceMap;
typedef struct InternEntry InternEntry;
typedef struct Parser Parser;
typedef struct StmtKind StmtKind;
typedef struct File File;
typedef struct TypeEntry TypeEntry;
typedef struct Param Param;
typedef struct SwitchCase SwitchCase;
typedef struct Token Token;
typedef struct Lexer Lexer;
typedef struct FlagBranch FlagBranch;
typedef struct EscapeResult EscapeResult;
typedef struct FileEntry FileEntry;
typedef struct ParserMark ParserMark;
typedef struct PatKind PatKind;
typedef struct TypeKind TypeKind;
typedef struct Stmt Stmt;
typedef struct TraitBound TraitBound;
typedef struct VariantVariant VariantVariant;
typedef struct Decl Decl;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Node Node;
typedef struct NodeKind NodeKind;
typedef struct DeclKind DeclKind;
typedef struct Field Field;
typedef struct AstContext AstContext;
typedef struct TestResult TestResult;
typedef struct Pat Pat;
typedef struct IdentifierTable IdentifierTable;
typedef struct Expr Expr;
typedef struct NodeId NodeId;
typedef struct Diagnostic Diagnostic;
typedef struct DiagInfo DiagInfo;
typedef struct Span Span;
typedef struct Label Label;
typedef struct Attribute Attribute;
typedef struct ImportSymbol ImportSymbol;
typedef struct SourceLoc SourceLoc;
typedef struct IdentEntry IdentEntry;
typedef struct Slice Slice;
typedef struct EnumVariant EnumVariant;
typedef struct Ast Ast;
typedef enum ErrorCode ErrorCode;
typedef enum Severity Severity;
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




typedef struct GenericParam GenericParam;
typedef struct ExprKind ExprKind;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct SourceMap SourceMap;
typedef struct InternEntry InternEntry;
typedef struct Parser Parser;
typedef struct StmtKind StmtKind;
typedef struct File File;
typedef struct TypeEntry TypeEntry;
typedef struct Param Param;
typedef struct SwitchCase SwitchCase;
typedef struct Token Token;
typedef struct Lexer Lexer;
typedef struct FlagBranch FlagBranch;
typedef struct EscapeResult EscapeResult;
typedef struct FileEntry FileEntry;
typedef struct ParserMark ParserMark;
typedef struct PatKind PatKind;
typedef struct TypeKind TypeKind;
typedef struct Stmt Stmt;
typedef struct TraitBound TraitBound;
typedef struct VariantVariant VariantVariant;
typedef struct Decl Decl;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Node Node;
typedef struct NodeKind NodeKind;
typedef struct DeclKind DeclKind;
typedef struct Field Field;
typedef struct AstContext AstContext;
typedef struct TestResult TestResult;
typedef struct Pat Pat;
typedef struct IdentifierTable IdentifierTable;
typedef struct Expr Expr;
typedef struct NodeId NodeId;
typedef struct Diagnostic Diagnostic;
typedef struct DiagInfo DiagInfo;
typedef struct Span Span;
typedef struct Label Label;
typedef struct Attribute Attribute;
typedef struct ImportSymbol ImportSymbol;
typedef struct SourceLoc SourceLoc;
typedef struct IdentEntry IdentEntry;
typedef struct Slice Slice;
typedef struct EnumVariant EnumVariant;
typedef struct Ast Ast;
typedef enum ErrorCode ErrorCode;
typedef enum Severity Severity;
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




typedef struct GenericParam GenericParam;
typedef struct ExprKind ExprKind;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct SourceMap SourceMap;
typedef struct InternEntry InternEntry;
typedef struct Parser Parser;
typedef struct StmtKind StmtKind;
typedef struct File File;
typedef struct TypeEntry TypeEntry;
typedef struct Param Param;
typedef struct SwitchCase SwitchCase;
typedef struct Token Token;
typedef struct Lexer Lexer;
typedef struct FlagBranch FlagBranch;
typedef struct EscapeResult EscapeResult;
typedef struct FileEntry FileEntry;
typedef struct ParserMark ParserMark;
typedef struct PatKind PatKind;
typedef struct TypeKind TypeKind;
typedef struct Stmt Stmt;
typedef struct TraitBound TraitBound;
typedef struct VariantVariant VariantVariant;
typedef struct Decl Decl;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Node Node;
typedef struct NodeKind NodeKind;
typedef struct DeclKind DeclKind;
typedef struct Field Field;
typedef struct AstContext AstContext;
typedef struct TestResult TestResult;
typedef struct Pat Pat;
typedef struct IdentifierTable IdentifierTable;
typedef struct Expr Expr;
typedef struct NodeId NodeId;
typedef struct Diagnostic Diagnostic;
typedef struct DiagInfo DiagInfo;
typedef struct Span Span;
typedef struct Label Label;
typedef struct Attribute Attribute;
typedef struct ImportSymbol ImportSymbol;
typedef struct SourceLoc SourceLoc;
typedef struct IdentEntry IdentEntry;
typedef struct Slice Slice;
typedef struct EnumVariant EnumVariant;
typedef struct Ast Ast;
typedef enum ErrorCode ErrorCode;
typedef enum Severity Severity;
typedef enum TokenKind TokenKind;



enum NodeKind_tag {
    NodeKind_Expr = 0,
    NodeKind_Stmt,
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




typedef struct GenericParam GenericParam;
typedef struct ExprKind ExprKind;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct SourceMap SourceMap;
typedef struct InternEntry InternEntry;
typedef struct Parser Parser;
typedef struct StmtKind StmtKind;
typedef struct File File;
typedef struct TypeEntry TypeEntry;
typedef struct Param Param;
typedef struct SwitchCase SwitchCase;
typedef struct Token Token;
typedef struct Lexer Lexer;
typedef struct FlagBranch FlagBranch;
typedef struct EscapeResult EscapeResult;
typedef struct FileEntry FileEntry;
typedef struct ParserMark ParserMark;
typedef struct PatKind PatKind;
typedef struct TypeKind TypeKind;
typedef struct Stmt Stmt;
typedef struct TraitBound TraitBound;
typedef struct VariantVariant VariantVariant;
typedef struct Decl Decl;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Node Node;
typedef struct NodeKind NodeKind;
typedef struct DeclKind DeclKind;
typedef struct Field Field;
typedef struct AstContext AstContext;
typedef struct TestResult TestResult;
typedef struct Pat Pat;
typedef struct IdentifierTable IdentifierTable;
typedef struct Expr Expr;
typedef struct NodeId NodeId;
typedef struct Diagnostic Diagnostic;
typedef struct DiagInfo DiagInfo;
typedef struct Span Span;
typedef struct Label Label;
typedef struct Attribute Attribute;
typedef struct ImportSymbol ImportSymbol;
typedef struct SourceLoc SourceLoc;
typedef struct IdentEntry IdentEntry;
typedef struct Slice Slice;
typedef struct EnumVariant EnumVariant;
typedef struct Ast Ast;
typedef enum ErrorCode ErrorCode;
typedef enum Severity Severity;
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
    (self->interns = NULL);
    (self->internsLen = 0);
    (self->internsCap = 0);
    (self->types = NULL);
    (self->typesLen = 0);
    (self->typesCap = 0);
    (self->nodes = NULL);
    (self->nodesLen = 0);
    (self->nodesCap = 0);
    if ((internCap > 0)) {
        (self->interns = malloc((((size_t)internCap) * 24)));
        if ((self->interns != NULL)) {
            (self->internsCap = internCap);
            (self->internsLen = 1);
            (self->interns[0].ptr = NULL);
            (self->interns[0].len = 0);
            (self->interns[0].id = 0);
        }
    }
    if ((typeCap > 0)) {
        (self->types = malloc((((size_t)typeCap) * 64)));
        if ((self->types != NULL)) {
            (self->typesCap = typeCap);
            (self->typesLen = 1);
        }
    }
    if ((nodeCap > 0)) {
        (self->nodes = malloc((((size_t)nodeCap) * 192)));
        if ((self->nodes != NULL)) {
            (self->nodesCap = nodeCap);
            (self->nodesLen = 1);
        }
    }
}
void AstContext_deinit(AstContext* self) {
    if ((self->interns != NULL)) {
        free(self->interns);
    }
    if ((self->types != NULL)) {
        free(self->types);
    }
    if ((self->nodes != NULL)) {
        free(self->nodes);
    }
    (self->interns = NULL);
    (self->internsLen = 0);
    (self->internsCap = 0);
    (self->types = NULL);
    (self->typesLen = 0);
    (self->typesCap = 0);
    (self->nodes = NULL);
    (self->nodesLen = 0);
    (self->nodesCap = 0);
}
_Bool AstContext_streq(AstContext* self, uint8_t* a, size_t aLen, uint8_t* b, size_t bLen) {
    if ((aLen != bLen)) {
        return 0;
    }
    if ((aLen == 0)) {
        return 1;
    }
    if (((a == NULL) || (b == NULL))) {
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
    if (((self->interns == NULL) || (self->internsLen == 0))) {
        return 0;
    }
    if (((len == 0) || (ptr == NULL))) {
        return 0;
    }
    uint32_t i = 1;
    while (((i < self->internsLen) && (i < self->internsCap))) {
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
    if ((((self->types == NULL) || (self->typesLen == 0)) || (self->typesLen >= self->typesCap))) {
        return 0;
    }
    Ty id = self->typesLen;
    (self->typesLen = (self->typesLen + 1));
    return id;
}
NodeId AstContext_allocNodeSlot(AstContext* self) {
    if ((((self->nodes == NULL) || (self->nodesLen == 0)) || (self->nodesLen >= self->nodesCap))) {
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



typedef struct GenericParam GenericParam;
typedef struct ExprKind ExprKind;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct SourceMap SourceMap;
typedef struct InternEntry InternEntry;
typedef struct Parser Parser;
typedef struct StmtKind StmtKind;
typedef struct File File;
typedef struct TypeEntry TypeEntry;
typedef struct Param Param;
typedef struct SwitchCase SwitchCase;
typedef struct Token Token;
typedef struct Lexer Lexer;
typedef struct FlagBranch FlagBranch;
typedef struct EscapeResult EscapeResult;
typedef struct FileEntry FileEntry;
typedef struct ParserMark ParserMark;
typedef struct PatKind PatKind;
typedef struct TypeKind TypeKind;
typedef struct Stmt Stmt;
typedef struct TraitBound TraitBound;
typedef struct VariantVariant VariantVariant;
typedef struct Decl Decl;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Node Node;
typedef struct NodeKind NodeKind;
typedef struct DeclKind DeclKind;
typedef struct Field Field;
typedef struct AstContext AstContext;
typedef struct TestResult TestResult;
typedef struct Pat Pat;
typedef struct IdentifierTable IdentifierTable;
typedef struct Expr Expr;
typedef struct NodeId NodeId;
typedef struct Diagnostic Diagnostic;
typedef struct DiagInfo DiagInfo;
typedef struct Span Span;
typedef struct Label Label;
typedef struct Attribute Attribute;
typedef struct ImportSymbol ImportSymbol;
typedef struct SourceLoc SourceLoc;
typedef struct IdentEntry IdentEntry;
typedef struct Slice Slice;
typedef struct EnumVariant EnumVariant;
typedef struct Ast Ast;
typedef enum ErrorCode ErrorCode;
typedef enum Severity Severity;
typedef enum TokenKind TokenKind;



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




typedef struct GenericParam GenericParam;
typedef struct ExprKind ExprKind;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct SourceMap SourceMap;
typedef struct InternEntry InternEntry;
typedef struct Parser Parser;
typedef struct StmtKind StmtKind;
typedef struct File File;
typedef struct TypeEntry TypeEntry;
typedef struct Param Param;
typedef struct SwitchCase SwitchCase;
typedef struct Token Token;
typedef struct Lexer Lexer;
typedef struct FlagBranch FlagBranch;
typedef struct EscapeResult EscapeResult;
typedef struct FileEntry FileEntry;
typedef struct ParserMark ParserMark;
typedef struct PatKind PatKind;
typedef struct TypeKind TypeKind;
typedef struct Stmt Stmt;
typedef struct TraitBound TraitBound;
typedef struct VariantVariant VariantVariant;
typedef struct Decl Decl;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Node Node;
typedef struct NodeKind NodeKind;
typedef struct DeclKind DeclKind;
typedef struct Field Field;
typedef struct AstContext AstContext;
typedef struct TestResult TestResult;
typedef struct Pat Pat;
typedef struct IdentifierTable IdentifierTable;
typedef struct Expr Expr;
typedef struct NodeId NodeId;
typedef struct Diagnostic Diagnostic;
typedef struct DiagInfo DiagInfo;
typedef struct Span Span;
typedef struct Label Label;
typedef struct Attribute Attribute;
typedef struct ImportSymbol ImportSymbol;
typedef struct SourceLoc SourceLoc;
typedef struct IdentEntry IdentEntry;
typedef struct Slice Slice;
typedef struct EnumVariant EnumVariant;
typedef struct Ast Ast;
typedef enum ErrorCode ErrorCode;
typedef enum Severity Severity;
typedef enum TokenKind TokenKind;


Ty Parser_parseType(Parser* self);
Ty Parser_makeVoid(Parser* self);
Ty Parser_makeNamed(Parser* self, Str name);
Ty Parser_makePointer(Parser* self, Ty base);
Ty Parser_makeConst(Parser* self, Ty base);
Ty Parser_makeSlice(Parser* self, Ty base);
Ty Parser_makeArray(Parser* self, Ty base, uint32_t len);
Ty Parser_allocTypeKind(Parser* self, TypeKind kind);
Ty Parser_parseBaseType(Parser* self);
Ty Parser_allocType(Parser* self);

Ty Parser_parseType(Parser* self) {
    if (Parser_match(self, TokenKind_Const)) {
        Ty inner = Parser_parseType(self);
        return Parser_makeConst(self, inner);
    }
    Ty base = Parser_parseBaseType(self);
    while (Parser_match(self, TokenKind_Star)) {
        (base = Parser_makePointer(self, base));
    }
    while (Parser_check(self, TokenKind_LBracket)) {
        Parser_advance(self);
        if (Parser_match(self, TokenKind_RBracket)) {
            (base = Parser_makeSlice(self, base));
        } else {
            {
                Parser_parseExpr(self);
                Parser_expect(self, TokenKind_RBracket);
                (base = Parser_makeArray(self, base, 0));
            }
        }
    }
    return base;
}
Ty Parser_makeVoid(Parser* self) {
    TypeKind k;
    (k.tag = TypeKind_Void);
    return Parser_allocTypeKind(self, k);
}
Ty Parser_makeNamed(Parser* self, Str name) {
    TypeKind k;
    (k = (TypeKind){ .tag = TypeKind_Named, .payload.Named = {.name = name, .genericArgs = NULL, .genericArgsLen = 0} });
    return Parser_allocTypeKind(self, k);
}
Ty Parser_makePointer(Parser* self, Ty base) {
    TypeKind k;
    (k = (TypeKind){ .tag = TypeKind_Pointer, .payload.Pointer = {.base = base} });
    return Parser_allocTypeKind(self, k);
}
Ty Parser_makeConst(Parser* self, Ty base) {
    TypeKind k;
    (k = (TypeKind){ .tag = TypeKind_Const, .payload.Const = {.base = base} });
    return Parser_allocTypeKind(self, k);
}
Ty Parser_makeSlice(Parser* self, Ty base) {
    TypeKind k;
    (k = (TypeKind){ .tag = TypeKind_Slice, .payload.Slice = {.base = base} });
    return Parser_allocTypeKind(self, k);
}
Ty Parser_makeArray(Parser* self, Ty base, uint32_t len) {
    TypeKind k;
    (k = (TypeKind){ .tag = TypeKind_Array, .payload.Array = {.base = base, .len = len} });
    return Parser_allocTypeKind(self, k);
}
Ty Parser_allocTypeKind(Parser* self, TypeKind kind) {
    Ty id = AstContext_allocTypeSlot(self->ctx);
    TypeEntry* e = (self->ctx->types + id);
    (e->kind = kind);
    return id;
}
Ty Parser_parseBaseType(Parser* self) {
    if (Parser_match(self, TokenKind_Void)) {
        return Parser_makeVoid(self);
    }
    if (Parser_match(self, TokenKind_Bool)) {
        TypeKind k;
        (k.tag = TypeKind_Bool);
        return Parser_allocTypeKind(self, k);
    }
    if (Parser_match(self, TokenKind_Char)) {
        TypeKind k;
        (k.tag = TypeKind_Char);
        return Parser_allocTypeKind(self, k);
    }
    if (Parser_match(self, TokenKind_U8)) {
        TypeKind k;
        (k.tag = TypeKind_U8);
        return Parser_allocTypeKind(self, k);
    }
    if (Parser_match(self, TokenKind_I8)) {
        TypeKind k;
        (k.tag = TypeKind_I8);
        return Parser_allocTypeKind(self, k);
    }
    if (Parser_match(self, TokenKind_U16)) {
        TypeKind k;
        (k.tag = TypeKind_U16);
        return Parser_allocTypeKind(self, k);
    }
    if (Parser_match(self, TokenKind_I16)) {
        TypeKind k;
        (k.tag = TypeKind_I16);
        return Parser_allocTypeKind(self, k);
    }
    if (Parser_match(self, TokenKind_U32)) {
        TypeKind k;
        (k.tag = TypeKind_U32);
        return Parser_allocTypeKind(self, k);
    }
    if (Parser_match(self, TokenKind_I32)) {
        TypeKind k;
        (k.tag = TypeKind_I32);
        return Parser_allocTypeKind(self, k);
    }
    if (Parser_match(self, TokenKind_U64)) {
        TypeKind k;
        (k.tag = TypeKind_U64);
        return Parser_allocTypeKind(self, k);
    }
    if (Parser_match(self, TokenKind_I64)) {
        TypeKind k;
        (k.tag = TypeKind_I64);
        return Parser_allocTypeKind(self, k);
    }
    if (Parser_match(self, TokenKind_U128)) {
        TypeKind k;
        (k.tag = TypeKind_U128);
        return Parser_allocTypeKind(self, k);
    }
    if (Parser_match(self, TokenKind_I128)) {
        TypeKind k;
        (k.tag = TypeKind_I128);
        return Parser_allocTypeKind(self, k);
    }
    if (Parser_match(self, TokenKind_F32)) {
        TypeKind k;
        (k.tag = TypeKind_F32);
        return Parser_allocTypeKind(self, k);
    }
    if (Parser_match(self, TokenKind_F64)) {
        TypeKind k;
        (k.tag = TypeKind_F64);
        return Parser_allocTypeKind(self, k);
    }
    if (Parser_match(self, TokenKind_Usize)) {
        TypeKind k;
        (k.tag = TypeKind_Usize);
        return Parser_allocTypeKind(self, k);
    }
    if (Parser_match(self, TokenKind_Isize)) {
        TypeKind k;
        (k.tag = TypeKind_Isize);
        return Parser_allocTypeKind(self, k);
    }
    if (Parser_match(self, TokenKind_Rawptr)) {
        TypeKind k;
        (k.tag = TypeKind_Rawptr);
        return Parser_allocTypeKind(self, k);
    }
    if (Parser_match(self, TokenKind_Str)) {
        TypeKind k;
        (k.tag = TypeKind_Str);
        return Parser_allocTypeKind(self, k);
    }
    if (Parser_check(self, TokenKind_Ident)) {
        Parser_advance(self);
        while (Parser_match(self, TokenKind_ColonColon)) {
            Parser_expect(self, TokenKind_Ident);
        }
        if (Parser_check(self, TokenKind_Less)) {
            ParserMark m = Parser_save(self);
            Parser_advance(self);
            _Bool ok = 1;
            if ((Parser_check(self, TokenKind_Greater) || Parser_check(self, TokenKind_Shr))) {
                (ok = Parser_consumeGreater(self));
            } else {
                {
                    Parser_parseType(self);
                    if (self->panicMode) {
                        (ok = 0);
                    } else {
                        {
                            while (Parser_match(self, TokenKind_Comma)) {
                                Parser_parseType(self);
                                if (self->panicMode) {
                                    (ok = 0);
                                    break;
                                }
                            }
                            if (ok) {
                                (ok = Parser_consumeGreater(self));
                            }
                        }
                    }
                }
            }
            if ((! ok)) {
                Parser_restore(self, m);
            }
        }
        if (Parser_check(self, TokenKind_LParen)) {
            Parser_advance(self);
            if ((! Parser_check(self, TokenKind_RParen))) {
                Parser_parseType(self);
                while (Parser_match(self, TokenKind_Comma)) {
                    Parser_parseType(self);
                }
            }
            Parser_expect(self, TokenKind_RParen);
        }
        return Parser_allocType(self);
    }
    if (Parser_check(self, TokenKind_LParen)) {
        Parser_advance(self);
        Parser_parseType(self);
        while (Parser_match(self, TokenKind_Comma)) {
            Parser_parseType(self);
        }
        Parser_expect(self, TokenKind_RParen);
        return Parser_allocType(self);
    }
    if (Parser_check(self, TokenKind_Struct)) {
        Parser_advance(self);
        Parser_expect(self, TokenKind_LParen);
        Parser_parseType(self);
        while (Parser_match(self, TokenKind_Comma)) {
            Parser_parseType(self);
        }
        Parser_expect(self, TokenKind_RParen);
        return Parser_allocType(self);
    }
    (self->panicMode = 1);
    return 0;
}
Ty Parser_allocType(Parser* self) {
    return AstContext_allocTypeSlot(self->ctx);
}



typedef struct GenericParam GenericParam;
typedef struct ExprKind ExprKind;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct SourceMap SourceMap;
typedef struct InternEntry InternEntry;
typedef struct Parser Parser;
typedef struct StmtKind StmtKind;
typedef struct File File;
typedef struct TypeEntry TypeEntry;
typedef struct Param Param;
typedef struct SwitchCase SwitchCase;
typedef struct Token Token;
typedef struct Lexer Lexer;
typedef struct FlagBranch FlagBranch;
typedef struct EscapeResult EscapeResult;
typedef struct FileEntry FileEntry;
typedef struct ParserMark ParserMark;
typedef struct PatKind PatKind;
typedef struct TypeKind TypeKind;
typedef struct Stmt Stmt;
typedef struct TraitBound TraitBound;
typedef struct VariantVariant VariantVariant;
typedef struct Decl Decl;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Node Node;
typedef struct NodeKind NodeKind;
typedef struct DeclKind DeclKind;
typedef struct Field Field;
typedef struct AstContext AstContext;
typedef struct TestResult TestResult;
typedef struct Pat Pat;
typedef struct IdentifierTable IdentifierTable;
typedef struct Expr Expr;
typedef struct NodeId NodeId;
typedef struct Diagnostic Diagnostic;
typedef struct DiagInfo DiagInfo;
typedef struct Span Span;
typedef struct Label Label;
typedef struct Attribute Attribute;
typedef struct ImportSymbol ImportSymbol;
typedef struct SourceLoc SourceLoc;
typedef struct IdentEntry IdentEntry;
typedef struct Slice Slice;
typedef struct EnumVariant EnumVariant;
typedef struct Ast Ast;
typedef enum ErrorCode ErrorCode;
typedef enum Severity Severity;
typedef enum TokenKind TokenKind;


int32_t Parser_prec(Parser* self, TokenKind kind);
_Bool Parser_isAssignOp(Parser* self, TokenKind kind);
NodeId Parser_storeExpr(Parser* self, ExprKind kind);
NodeId Parser_parseExpr(Parser* self);
NodeId Parser_parseBinaryExpr(Parser* self, int32_t minPrec);
NodeId Parser_makeBinOp(Parser* self, TokenKind op, NodeId left, NodeId right);
NodeId Parser_parseUnaryExpr(Parser* self);
NodeId Parser_parsePostfixExpr(Parser* self);
NodeId Parser_parsePrimaryExpr(Parser* self);
NodeId Parser_parseSwitchExprCase(Parser* self);
NodeId Parser_parseSwitchExprPattern(Parser* self);

int32_t Parser_prec(Parser* self, TokenKind kind) {
    switch (kind) {
        case TokenKind_Equal:
            return 1;
            break;
        case TokenKind_PlusEqual:
            return 1;
            break;
        case TokenKind_MinusEqual:
            return 1;
            break;
        case TokenKind_StarEqual:
            return 1;
            break;
        case TokenKind_SlashEqual:
            return 1;
            break;
        case TokenKind_PercentEqual:
            return 1;
            break;
        case TokenKind_AmpEqual:
            return 1;
            break;
        case TokenKind_PipeEqual:
            return 1;
            break;
        case TokenKind_CaretEqual:
            return 1;
            break;
        case TokenKind_ShlEqual:
            return 1;
            break;
        case TokenKind_ShrEqual:
            return 1;
            break;
        case TokenKind_Or:
            return 2;
            break;
        case TokenKind_And:
            return 3;
            break;
        case TokenKind_Pipe:
            return 4;
            break;
        case TokenKind_Caret:
            return 5;
            break;
        case TokenKind_Ampersand:
            return 6;
            break;
        case TokenKind_EqualEqual:
            return 7;
            break;
        case TokenKind_NotEqual:
            return 7;
            break;
        case TokenKind_Less:
            return 8;
            break;
        case TokenKind_LessEqual:
            return 8;
            break;
        case TokenKind_Greater:
            return 8;
            break;
        case TokenKind_GreaterEqual:
            return 8;
            break;
        case TokenKind_Shl:
            return 9;
            break;
        case TokenKind_Shr:
            return 9;
            break;
        case TokenKind_Plus:
            return 10;
            break;
        case TokenKind_Minus:
            return 10;
            break;
        case TokenKind_Star:
            return 11;
            break;
        case TokenKind_Slash:
            return 11;
            break;
        case TokenKind_Percent:
            return 11;
            break;
        default:
            return 0;
            break;
    }
}
_Bool Parser_isAssignOp(Parser* self, TokenKind kind) {
    return (((((((((((kind == TokenKind_Equal) || (kind == TokenKind_PlusEqual)) || (kind == TokenKind_MinusEqual)) || (kind == TokenKind_StarEqual)) || (kind == TokenKind_SlashEqual)) || (kind == TokenKind_PercentEqual)) || (kind == TokenKind_AmpEqual)) || (kind == TokenKind_PipeEqual)) || (kind == TokenKind_CaretEqual)) || (kind == TokenKind_ShlEqual)) || (kind == TokenKind_ShrEqual));
}
NodeId Parser_storeExpr(Parser* self, ExprKind kind) {
    NodeId id = AstContext_allocNodeSlot(self->ctx);
    if ((id.index == 0)) {
        return id;
    }
    Expr e;
    (e.kind = kind);
    Node n;
    (n.kind = (NodeKind){ .tag = NodeKind_Expr, .payload.Expr = {.value = e} });
    return id;
}
NodeId Parser_parseExpr(Parser* self) {
    NodeId cond = Parser_parseBinaryExpr(self, 1);
    if (Parser_match(self, TokenKind_Question)) {
        Parser_parseExpr(self);
        Parser_expect(self, TokenKind_Colon);
        Parser_parseExpr(self);
        return Parser_allocNode(self);
    }
    return cond;
}
NodeId Parser_parseBinaryExpr(Parser* self, int32_t minPrec) {
    NodeId left = Parser_parseUnaryExpr(self);
    while (1) {
        int32_t p = Parser_prec(self, self->current.kind);
        if ((p <= minPrec)) {
            break;
        }
        Token op = Parser_advance(self);
        _Bool rightAssoc = Parser_isAssignOp(self, op.kind);
        NodeId right;
        if (rightAssoc) {
            (right = Parser_parseBinaryExpr(self, p));
        } else {
            {
                (right = Parser_parseBinaryExpr(self, (p + 1)));
            }
        }
        (left = Parser_makeBinOp(self, op.kind, left, right));
    }
    return left;
}
NodeId Parser_makeBinOp(Parser* self, TokenKind op, NodeId left, NodeId right) {
    switch (op) {
        case TokenKind_Plus:
            return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_Add, .payload.Add = {.left = left, .right = right} });
            break;
        case TokenKind_Minus:
            return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_Sub, .payload.Sub = {.left = left, .right = right} });
            break;
        case TokenKind_Star:
            return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_Mul, .payload.Mul = {.left = left, .right = right} });
            break;
        case TokenKind_Slash:
            return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_Div, .payload.Div = {.left = left, .right = right} });
            break;
        case TokenKind_Percent:
            return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_Mod, .payload.Mod = {.left = left, .right = right} });
            break;
        case TokenKind_EqualEqual:
            return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_Eq, .payload.Eq = {.left = left, .right = right} });
            break;
        case TokenKind_NotEqual:
            return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_Ne, .payload.Ne = {.left = left, .right = right} });
            break;
        case TokenKind_Less:
            return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_Lt, .payload.Lt = {.left = left, .right = right} });
            break;
        case TokenKind_LessEqual:
            return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_Le, .payload.Le = {.left = left, .right = right} });
            break;
        case TokenKind_Greater:
            return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_Gt, .payload.Gt = {.left = left, .right = right} });
            break;
        case TokenKind_GreaterEqual:
            return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_Ge, .payload.Ge = {.left = left, .right = right} });
            break;
        case TokenKind_And:
            return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_And, .payload.And = {.left = left, .right = right} });
            break;
        case TokenKind_Or:
            return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_Or, .payload.Or = {.left = left, .right = right} });
            break;
        case TokenKind_Ampersand:
            return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_BitAnd, .payload.BitAnd = {.left = left, .right = right} });
            break;
        case TokenKind_Pipe:
            return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_BitOr, .payload.BitOr = {.left = left, .right = right} });
            break;
        case TokenKind_Caret:
            return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_BitXor, .payload.BitXor = {.left = left, .right = right} });
            break;
        case TokenKind_Shl:
            return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_Shl, .payload.Shl = {.left = left, .right = right} });
            break;
        case TokenKind_Shr:
            return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_Shr, .payload.Shr = {.left = left, .right = right} });
            break;
        case TokenKind_Equal:
            return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_Assign, .payload.Assign = {.target = left, .value = right} });
            break;
        case TokenKind_PlusEqual:
            return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_AssignAdd, .payload.AssignAdd = {.target = left, .value = right} });
            break;
        case TokenKind_MinusEqual:
            return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_AssignSub, .payload.AssignSub = {.target = left, .value = right} });
            break;
        case TokenKind_StarEqual:
            return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_AssignMul, .payload.AssignMul = {.target = left, .value = right} });
            break;
        case TokenKind_SlashEqual:
            return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_AssignDiv, .payload.AssignDiv = {.target = left, .value = right} });
            break;
        case TokenKind_PercentEqual:
            return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_AssignMod, .payload.AssignMod = {.target = left, .value = right} });
            break;
        case TokenKind_AmpEqual:
            return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_AssignBitAnd, .payload.AssignBitAnd = {.target = left, .value = right} });
            break;
        case TokenKind_PipeEqual:
            return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_AssignBitOr, .payload.AssignBitOr = {.target = left, .value = right} });
            break;
        case TokenKind_CaretEqual:
            return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_AssignBitXor, .payload.AssignBitXor = {.target = left, .value = right} });
            break;
        case TokenKind_ShlEqual:
            return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_AssignShl, .payload.AssignShl = {.target = left, .value = right} });
            break;
        case TokenKind_ShrEqual:
            return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_AssignShr, .payload.AssignShr = {.target = left, .value = right} });
            break;
        default:
            return Parser_allocNode(self);
            break;
    }
}
NodeId Parser_parseUnaryExpr(Parser* self) {
    if (Parser_check(self, TokenKind_Not)) {
        Parser_advance(self);
        NodeId expr = Parser_parseUnaryExpr(self);
        return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_Not, .payload.Not = {.expr = expr} });
    }
    if (Parser_check(self, TokenKind_Minus)) {
        Parser_advance(self);
        NodeId expr = Parser_parseUnaryExpr(self);
        return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_Neg, .payload.Neg = {.expr = expr} });
    }
    if (Parser_check(self, TokenKind_Star)) {
        Parser_advance(self);
        NodeId expr = Parser_parseUnaryExpr(self);
        return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_Deref, .payload.Deref = {.expr = expr} });
    }
    if (Parser_check(self, TokenKind_Ampersand)) {
        Parser_advance(self);
        NodeId expr = Parser_parseUnaryExpr(self);
        return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_AddressOf, .payload.AddressOf = {.expr = expr} });
    }
    if (Parser_check(self, TokenKind_Neg)) {
        Parser_advance(self);
        NodeId expr = Parser_parseUnaryExpr(self);
        return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_Neg, .payload.Neg = {.expr = expr} });
    }
    return Parser_parsePostfixExpr(self);
}
NodeId Parser_parsePostfixExpr(Parser* self) {
    NodeId expr = Parser_parsePrimaryExpr(self);
    while (1) {
        if (Parser_check(self, TokenKind_LParen)) {
            Parser_advance(self);
            if ((! Parser_check(self, TokenKind_RParen))) {
                Parser_parseExpr(self);
                while (Parser_match(self, TokenKind_Comma)) {
                    Parser_parseExpr(self);
                }
            }
            Parser_expect(self, TokenKind_RParen);
            (expr = Parser_allocNode(self));
        } else {
            if (Parser_check(self, TokenKind_Dot)) {
                Parser_advance(self);
                if (Parser_check(self, TokenKind_Dec)) {
                    Parser_advance(self);
                } else {
                    {
                        Parser_expect(self, TokenKind_Ident);
                        if (Parser_check(self, TokenKind_LParen)) {
                            Parser_advance(self);
                            if ((! Parser_check(self, TokenKind_RParen))) {
                                Parser_parseExpr(self);
                                while (Parser_match(self, TokenKind_Comma)) {
                                    Parser_parseExpr(self);
                                }
                            }
                            Parser_expect(self, TokenKind_RParen);
                        }
                    }
                }
                (expr = Parser_allocNode(self));
            } else {
                if (Parser_check(self, TokenKind_ColonColon)) {
                    Parser_advance(self);
                    Parser_expect(self, TokenKind_Ident);
                    (expr = Parser_allocNode(self));
                } else {
                    if (Parser_check(self, TokenKind_Arrow)) {
                        Parser_advance(self);
                        Parser_expect(self, TokenKind_Ident);
                        (expr = Parser_allocNode(self));
                    } else {
                        if (Parser_check(self, TokenKind_LBracket)) {
                            Parser_advance(self);
                            Parser_parseExpr(self);
                            Parser_expect(self, TokenKind_RBracket);
                            (expr = Parser_allocNode(self));
                        } else {
                            if ((Parser_check(self, TokenKind_PlusPlus) || Parser_check(self, TokenKind_MinusMinus))) {
                                Parser_advance(self);
                                (expr = Parser_allocNode(self));
                            } else {
                                {
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return expr;
}
NodeId Parser_parsePrimaryExpr(Parser* self) {
    TokenKind k = self->current.kind;
    switch (k) {
        case TokenKind_Dec:
            Parser_advance(self);
            return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_IntLit, .payload.IntLit = {.value = 0, .flags = 0} });
            break;
        case TokenKind_Hex:
            Parser_advance(self);
            return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_IntLit, .payload.IntLit = {.value = 0, .flags = 0} });
            break;
        case TokenKind_Bin:
            Parser_advance(self);
            return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_IntLit, .payload.IntLit = {.value = 0, .flags = 0} });
            break;
        case TokenKind_Oct:
            Parser_advance(self);
            return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_IntLit, .payload.IntLit = {.value = 0, .flags = 0} });
            break;
        case TokenKind_Float:
            Parser_advance(self);
            return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_FloatLit, .payload.FloatLit = {.value = 0} });
            break;
        case TokenKind_String:
            Parser_advance(self);
            return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_StringLit, .payload.StringLit = {.value = 0} });
            break;
        case TokenKind_RawString:
            Parser_advance(self);
            return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_StringLit, .payload.StringLit = {.value = 0} });
            break;
        case TokenKind_Char:
            Parser_advance(self);
            return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_CharLit, .payload.CharLit = {.value = 0} });
            break;
        case TokenKind_True:
            Parser_advance(self);
            return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_BoolLit, .payload.BoolLit = {.flags = 1} });
            break;
        case TokenKind_False:
            Parser_advance(self);
            return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_BoolLit, .payload.BoolLit = {.flags = 0} });
            break;
        case TokenKind_Null:
            Parser_advance(self);
            return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_NullLit });
            break;
        case TokenKind_Ident:
            Token nameTok = Parser_advance(self);
            Str name = AstContext_intern(self->ctx, nameTok.data.ptr, nameTok.data.len);
            if (Parser_check(self, TokenKind_ColonColon)) {
                while (Parser_match(self, TokenKind_ColonColon)) {
                    Parser_expect(self, TokenKind_Ident);
                }
                return Parser_allocNode(self);
            }
            if (Parser_check(self, TokenKind_LBrace)) {
                Parser_advance(self);
                while (((! Parser_check(self, TokenKind_RBrace)) && (! Parser_atEnd(self)))) {
                    Parser_expect(self, TokenKind_Dot);
                    Parser_expect(self, TokenKind_Ident);
                    Parser_expect(self, TokenKind_Equal);
                    Parser_parseExpr(self);
                    if ((! Parser_match(self, TokenKind_Comma))) {
                        break;
                    }
                }
                Parser_expect(self, TokenKind_RBrace);
                return Parser_allocNode(self);
            }
            return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_Ident, .payload.Ident = {.name = name} });
            break;
        case TokenKind_LParen:
            Parser_advance(self);
            NodeId expr = Parser_parseExpr(self);
            Parser_expect(self, TokenKind_RParen);
            return expr;
            break;
        case TokenKind_LBrace:
            Parser_advance(self);
            while (((! Parser_check(self, TokenKind_RBrace)) && (! Parser_atEnd(self)))) {
                Parser_parseExpr(self);
                Parser_match(self, TokenKind_Semicolon);
            }
            Parser_expect(self, TokenKind_RBrace);
            return Parser_allocNode(self);
            break;
        case TokenKind_If:
            Parser_advance(self);
            Parser_expect(self, TokenKind_LParen);
            NodeId cond = Parser_parseExpr(self);
            Parser_expect(self, TokenKind_RParen);
            NodeId thenB = Parser_parseExpr(self);
            NodeId elseB = Parser_noneNode(self);
            if (Parser_match(self, TokenKind_Else)) {
                (elseB = Parser_parseExpr(self));
            }
            return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_IfExpr, .payload.IfExpr = {.cond = cond, .thenBody = thenB, .elseBody = elseB} });
            break;
        case TokenKind_Switch:
            Parser_advance(self);
            Parser_expect(self, TokenKind_LParen);
            NodeId sexpr = Parser_parseExpr(self);
            Parser_expect(self, TokenKind_RParen);
            Parser_expect(self, TokenKind_LBrace);
            while (((! Parser_check(self, TokenKind_RBrace)) && (! Parser_atEnd(self)))) {
                Parser_parseSwitchExprCase(self);
            }
            Parser_expect(self, TokenKind_RBrace);
            return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_SwitchExpr, .payload.SwitchExpr = {.expr = sexpr, .cases = NULL, .casesLen = 0} });
            break;
        case TokenKind_BuiltinSizeof:
            Parser_advance(self);
            Parser_expect(self, TokenKind_LParen);
            Ty sizeofType = Parser_parseType(self);
            Parser_expect(self, TokenKind_RParen);
            return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_Sizeof, .payload.Sizeof = {.targetType = sizeofType} });
            break;
        case TokenKind_BuiltinAlignof:
            Parser_advance(self);
            Parser_expect(self, TokenKind_LParen);
            Ty alignofType = Parser_parseType(self);
            Parser_expect(self, TokenKind_RParen);
            return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_Alignof, .payload.Alignof = {.targetType = alignofType} });
            break;
        case TokenKind_BuiltinTypeof:
            Parser_advance(self);
            Parser_expect(self, TokenKind_LParen);
            NodeId typeofExpr = Parser_parseExpr(self);
            Parser_expect(self, TokenKind_RParen);
            return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_Typeof, .payload.Typeof = {.expr = typeofExpr} });
            break;
        case TokenKind_BuiltinAssert:
            Parser_advance(self);
            Parser_expect(self, TokenKind_LParen);
            Parser_parseExpr(self);
            while (Parser_match(self, TokenKind_Comma)) {
                Parser_parseExpr(self);
            }
            Parser_expect(self, TokenKind_RParen);
            return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_BuiltinCall, .payload.BuiltinCall = {.name = AstContext_intern(self->ctx, "assert", 6), .args = NULL, .argsLen = 0} });
            break;
        case TokenKind_At:
            Parser_advance(self);
            Token bt = Parser_expect(self, TokenKind_Ident);
            Str bname = AstContext_intern(self->ctx, bt.data.ptr, bt.data.len);
            Parser_expect(self, TokenKind_LParen);
            if ((! Parser_check(self, TokenKind_RParen))) {
                Parser_parseExpr(self);
                while (Parser_match(self, TokenKind_Comma)) {
                    Parser_parseExpr(self);
                }
            }
            Parser_expect(self, TokenKind_RParen);
            return Parser_storeExpr(self, (ExprKind){ .tag = ExprKind_BuiltinCall, .payload.BuiltinCall = {.name = bname, .args = NULL, .argsLen = 0} });
            break;
        default:
            (self->panicMode = 1);
            return Parser_noneNode(self);
            break;
    }
}
NodeId Parser_parseSwitchExprCase(Parser* self) {
    if (Parser_match(self, TokenKind_Else)) {
        Parser_expect(self, TokenKind_FatArrow);
        Parser_parseExpr(self);
        Parser_match(self, TokenKind_Comma);
        return Parser_allocNode(self);
    }
    Parser_parseSwitchExprPattern(self);
    while (Parser_match(self, TokenKind_Comma)) {
        Parser_parseSwitchExprPattern(self);
    }
    if (Parser_match(self, TokenKind_If)) {
        Parser_parseExpr(self);
    }
    Parser_expect(self, TokenKind_FatArrow);
    Parser_parseExpr(self);
    Parser_match(self, TokenKind_Comma);
    return Parser_allocNode(self);
}
NodeId Parser_parseSwitchExprPattern(Parser* self) {
    TokenKind k = self->current.kind;
    if ((k == TokenKind_Ident)) {
        Parser_advance(self);
        if (Parser_check(self, TokenKind_ColonColon)) {
            Parser_advance(self);
            Parser_expect(self, TokenKind_Ident);
        }
        if (Parser_check(self, TokenKind_LBrace)) {
            Parser_advance(self);
            while (((! Parser_check(self, TokenKind_RBrace)) && (! Parser_atEnd(self)))) {
                Parser_expect(self, TokenKind_Ident);
                if ((! Parser_match(self, TokenKind_Comma))) {
                    break;
                }
            }
            Parser_expect(self, TokenKind_RBrace);
        }
        return Parser_allocNode(self);
    }
    if ((k == TokenKind_LParen)) {
        Parser_advance(self);
        while (((! Parser_check(self, TokenKind_RParen)) && (! Parser_atEnd(self)))) {
            Parser_parseSwitchExprPattern(self);
            if ((! Parser_match(self, TokenKind_Comma))) {
                break;
            }
        }
        Parser_expect(self, TokenKind_RParen);
        return Parser_allocNode(self);
    }
    Parser_parseExpr(self);
    if ((Parser_check(self, TokenKind_Dot) || Parser_check(self, TokenKind_Colon))) {
        Parser_advance(self);
        Parser_advance(self);
        Parser_parseExpr(self);
    }
    return Parser_allocNode(self);
}



typedef struct GenericParam GenericParam;
typedef struct ExprKind ExprKind;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct SourceMap SourceMap;
typedef struct InternEntry InternEntry;
typedef struct Parser Parser;
typedef struct StmtKind StmtKind;
typedef struct File File;
typedef struct TypeEntry TypeEntry;
typedef struct Param Param;
typedef struct SwitchCase SwitchCase;
typedef struct Token Token;
typedef struct Lexer Lexer;
typedef struct FlagBranch FlagBranch;
typedef struct EscapeResult EscapeResult;
typedef struct FileEntry FileEntry;
typedef struct ParserMark ParserMark;
typedef struct PatKind PatKind;
typedef struct TypeKind TypeKind;
typedef struct Stmt Stmt;
typedef struct TraitBound TraitBound;
typedef struct VariantVariant VariantVariant;
typedef struct Decl Decl;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Node Node;
typedef struct NodeKind NodeKind;
typedef struct DeclKind DeclKind;
typedef struct Field Field;
typedef struct AstContext AstContext;
typedef struct TestResult TestResult;
typedef struct Pat Pat;
typedef struct IdentifierTable IdentifierTable;
typedef struct Expr Expr;
typedef struct NodeId NodeId;
typedef struct Diagnostic Diagnostic;
typedef struct DiagInfo DiagInfo;
typedef struct Span Span;
typedef struct Label Label;
typedef struct Attribute Attribute;
typedef struct ImportSymbol ImportSymbol;
typedef struct SourceLoc SourceLoc;
typedef struct IdentEntry IdentEntry;
typedef struct Slice Slice;
typedef struct EnumVariant EnumVariant;
typedef struct Ast Ast;
typedef enum ErrorCode ErrorCode;
typedef enum Severity Severity;
typedef enum TokenKind TokenKind;


NodeId Parser_storeStmt(Parser* self, StmtKind kind);
NodeId Parser_parseStmt(Parser* self);
NodeId Parser_parseReturnStmt(Parser* self);
NodeId Parser_parseIfStmt(Parser* self);
NodeId Parser_parseWhileStmt(Parser* self);
NodeId Parser_parseForStmt(Parser* self);
NodeId Parser_parseLoopStmt(Parser* self);
NodeId Parser_parseSwitchStmt(Parser* self);
NodeId Parser_parseSwitchStmtCase(Parser* self);
NodeId Parser_parseSwitchStmtPattern(Parser* self);
NodeId Parser_parseDeferStmt(Parser* self);
NodeId Parser_parseBlock(Parser* self);
NodeId Parser_parseComptimeStmt(Parser* self);
NodeId Parser_parseAsmStmt(Parser* self);
NodeId Parser_parseExprOrDecl(Parser* self);

NodeId Parser_storeStmt(Parser* self, StmtKind kind) {
    NodeId id = AstContext_allocNodeSlot(self->ctx);
    if ((id.index == 0)) {
        return id;
    }
    Stmt s;
    (s.kind = kind);
    Node n;
    (n.kind = (NodeKind){ .tag = NodeKind_Stmt, .payload.Stmt = {.value = s} });
    return id;
}
NodeId Parser_parseStmt(Parser* self) {
    while (Parser_match(self, TokenKind_AttrOpen)) {
        Parser_expect(self, TokenKind_Ident);
        if (Parser_check(self, TokenKind_LParen)) {
            Parser_advance(self);
            while (((! Parser_check(self, TokenKind_RParen)) && (! Parser_atEnd(self)))) {
                Parser_advance(self);
                if ((! Parser_match(self, TokenKind_Comma))) {
                    break;
                }
            }
            Parser_expect(self, TokenKind_RParen);
        }
        while (Parser_match(self, TokenKind_Comma)) {
            Parser_expect(self, TokenKind_Ident);
            if (Parser_check(self, TokenKind_LParen)) {
                Parser_advance(self);
                while (((! Parser_check(self, TokenKind_RParen)) && (! Parser_atEnd(self)))) {
                    Parser_advance(self);
                    if ((! Parser_match(self, TokenKind_Comma))) {
                        break;
                    }
                }
                Parser_expect(self, TokenKind_RParen);
            }
        }
        Parser_expect(self, TokenKind_AttrClose);
    }
    if (Parser_check(self, TokenKind_Return)) {
        return Parser_parseReturnStmt(self);
    }
    if (Parser_check(self, TokenKind_If)) {
        return Parser_parseIfStmt(self);
    }
    if (Parser_check(self, TokenKind_While)) {
        return Parser_parseWhileStmt(self);
    }
    if (Parser_check(self, TokenKind_For)) {
        return Parser_parseForStmt(self);
    }
    if (Parser_check(self, TokenKind_Loop)) {
        return Parser_parseLoopStmt(self);
    }
    if (Parser_check(self, TokenKind_Switch)) {
        return Parser_parseSwitchStmt(self);
    }
    if (Parser_check(self, TokenKind_Defer)) {
        return Parser_parseDeferStmt(self);
    }
    if (Parser_check(self, TokenKind_Break)) {
        Parser_advance(self);
        Parser_expect(self, TokenKind_Semicolon);
        return Parser_storeStmt(self, (StmtKind){ .tag = StmtKind_Break });
    }
    if (Parser_check(self, TokenKind_Continue)) {
        Parser_advance(self);
        Parser_expect(self, TokenKind_Semicolon);
        return Parser_storeStmt(self, (StmtKind){ .tag = StmtKind_Continue });
    }
    if (Parser_check(self, TokenKind_LBrace)) {
        return Parser_parseBlock(self);
    }
    if (Parser_check(self, TokenKind_Comptime)) {
        return Parser_parseComptimeStmt(self);
    }
    if ((Parser_check(self, TokenKind_Asm) || Parser_check(self, TokenKind_Volatile))) {
        return Parser_parseAsmStmt(self);
    }
    return Parser_parseExprOrDecl(self);
}
NodeId Parser_parseReturnStmt(Parser* self) {
    Parser_advance(self);
    NodeId val = Parser_noneNode(self);
    if ((! Parser_check(self, TokenKind_Semicolon))) {
        (val = Parser_parseExpr(self));
    }
    Parser_expect(self, TokenKind_Semicolon);
    return Parser_storeStmt(self, (StmtKind){ .tag = StmtKind_Return, .payload.Return = {.value = val} });
}
NodeId Parser_parseIfStmt(Parser* self) {
    Parser_advance(self);
    Parser_expect(self, TokenKind_LParen);
    NodeId cond = Parser_parseExpr(self);
    Parser_expect(self, TokenKind_RParen);
    NodeId thenBody = Parser_parseStmt(self);
    NodeId elseBody = Parser_noneNode(self);
    if (Parser_match(self, TokenKind_Else)) {
        (elseBody = Parser_parseStmt(self));
    }
    return Parser_storeStmt(self, (StmtKind){ .tag = StmtKind_If, .payload.If = {.cond = cond, .thenBody = thenBody, .elseBody = elseBody} });
}
NodeId Parser_parseWhileStmt(Parser* self) {
    Parser_advance(self);
    Parser_expect(self, TokenKind_LParen);
    NodeId cond = Parser_parseExpr(self);
    Parser_expect(self, TokenKind_RParen);
    NodeId body = Parser_parseStmt(self);
    return Parser_storeStmt(self, (StmtKind){ .tag = StmtKind_While, .payload.While = {.cond = cond, .body = body} });
}
NodeId Parser_parseForStmt(Parser* self) {
    Parser_advance(self);
    Parser_expect(self, TokenKind_LParen);
    if (Parser_check(self, TokenKind_RParen)) {
        Parser_advance(self);
        Parser_parseStmt(self);
        return Parser_allocNode(self);
    }
    if ((Parser_check(self, TokenKind_Var) || Parser_check(self, TokenKind_Const))) {
        Parser_advance(self);
        Parser_expect(self, TokenKind_Ident);
        if (Parser_match(self, TokenKind_Colon)) {
            Parser_parseExpr(self);
            Parser_expect(self, TokenKind_RParen);
            Parser_parseStmt(self);
            return Parser_allocNode(self);
        }
        if (Parser_match(self, TokenKind_Equal)) {
            Parser_parseExpr(self);
        }
        Parser_expect(self, TokenKind_Semicolon);
        if ((! Parser_check(self, TokenKind_Semicolon))) {
            Parser_parseExpr(self);
        }
        Parser_expect(self, TokenKind_Semicolon);
        if ((! Parser_check(self, TokenKind_RParen))) {
            Parser_parseExpr(self);
            while (Parser_match(self, TokenKind_Comma)) {
                Parser_parseExpr(self);
            }
        }
        Parser_expect(self, TokenKind_RParen);
        Parser_parseStmt(self);
        return Parser_allocNode(self);
    }
    if (Parser_check(self, TokenKind_Semicolon)) {
        Parser_advance(self);
        if ((! Parser_check(self, TokenKind_Semicolon))) {
            Parser_parseExpr(self);
        }
        Parser_expect(self, TokenKind_Semicolon);
        if ((! Parser_check(self, TokenKind_RParen))) {
            Parser_parseExpr(self);
        }
        Parser_expect(self, TokenKind_RParen);
        Parser_parseStmt(self);
        return Parser_allocNode(self);
    }
    Parser_parseExpr(self);
    if (Parser_match(self, TokenKind_Colon)) {
        Parser_parseExpr(self);
        Parser_expect(self, TokenKind_RParen);
        Parser_parseStmt(self);
        return Parser_allocNode(self);
    }
    Parser_expect(self, TokenKind_Semicolon);
    if ((! Parser_check(self, TokenKind_Semicolon))) {
        Parser_parseExpr(self);
    }
    Parser_expect(self, TokenKind_Semicolon);
    if ((! Parser_check(self, TokenKind_RParen))) {
        Parser_parseExpr(self);
    }
    Parser_expect(self, TokenKind_RParen);
    Parser_parseStmt(self);
    return Parser_allocNode(self);
}
NodeId Parser_parseLoopStmt(Parser* self) {
    Parser_advance(self);
    Parser_parseStmt(self);
    return Parser_allocNode(self);
}
NodeId Parser_parseSwitchStmt(Parser* self) {
    Parser_advance(self);
    Parser_expect(self, TokenKind_LParen);
    Parser_parseExpr(self);
    Parser_expect(self, TokenKind_RParen);
    Parser_expect(self, TokenKind_LBrace);
    while (((! Parser_check(self, TokenKind_RBrace)) && (! Parser_atEnd(self)))) {
        Parser_parseSwitchStmtCase(self);
    }
    Parser_expect(self, TokenKind_RBrace);
    return Parser_allocNode(self);
}
NodeId Parser_parseSwitchStmtCase(Parser* self) {
    if (Parser_match(self, TokenKind_Else)) {
        Parser_expect(self, TokenKind_FatArrow);
        if (Parser_check(self, TokenKind_LBrace)) {
            Parser_parseBlock(self);
        } else {
            Parser_parseStmt(self);
        }
        Parser_match(self, TokenKind_Comma);
        return Parser_allocNode(self);
    }
    Parser_parseSwitchStmtPattern(self);
    while (Parser_match(self, TokenKind_Comma)) {
        Parser_parseSwitchStmtPattern(self);
    }
    if (Parser_match(self, TokenKind_If)) {
        Parser_parseExpr(self);
    }
    Parser_expect(self, TokenKind_FatArrow);
    if (Parser_check(self, TokenKind_LBrace)) {
        Parser_parseBlock(self);
    } else {
        Parser_parseStmt(self);
    }
    Parser_match(self, TokenKind_Comma);
    return Parser_allocNode(self);
}
NodeId Parser_parseSwitchStmtPattern(Parser* self) {
    TokenKind k = self->current.kind;
    if ((k == TokenKind_Ident)) {
        Parser_advance(self);
        if (Parser_match(self, TokenKind_ColonColon)) {
            Parser_expect(self, TokenKind_Ident);
        }
        if (Parser_check(self, TokenKind_LBrace)) {
            Parser_advance(self);
            while (((! Parser_check(self, TokenKind_RBrace)) && (! Parser_atEnd(self)))) {
                Parser_match(self, TokenKind_Dot);
                Parser_expect(self, TokenKind_Ident);
                if ((! Parser_match(self, TokenKind_Comma))) {
                    break;
                }
            }
            Parser_expect(self, TokenKind_RBrace);
        }
        return Parser_allocNode(self);
    }
    if ((k == TokenKind_LParen)) {
        Parser_advance(self);
        while (((! Parser_check(self, TokenKind_RParen)) && (! Parser_atEnd(self)))) {
            Parser_parseSwitchStmtPattern(self);
            if ((! Parser_match(self, TokenKind_Comma))) {
                break;
            }
        }
        Parser_expect(self, TokenKind_RParen);
        return Parser_allocNode(self);
    }
    Parser_parseExpr(self);
    return Parser_allocNode(self);
}
NodeId Parser_parseDeferStmt(Parser* self) {
    Parser_advance(self);
    Parser_parseStmt(self);
    return Parser_allocNode(self);
}
NodeId Parser_parseBlock(Parser* self) {
    Parser_expect(self, TokenKind_LBrace);
    while (((! Parser_check(self, TokenKind_RBrace)) && (! Parser_atEnd(self)))) {
        Parser_parseStmt(self);
    }
    Parser_expect(self, TokenKind_RBrace);
    return Parser_allocNode(self);
}
NodeId Parser_parseComptimeStmt(Parser* self) {
    Parser_advance(self);
    Parser_expect(self, TokenKind_LBrace);
    while (((! Parser_check(self, TokenKind_RBrace)) && (! Parser_atEnd(self)))) {
        Parser_parseStmt(self);
    }
    Parser_expect(self, TokenKind_RBrace);
    return Parser_allocNode(self);
}
NodeId Parser_parseAsmStmt(Parser* self) {
    Parser_match(self, TokenKind_Volatile);
    Parser_expect(self, TokenKind_Asm);
    Parser_expect(self, TokenKind_LBrace);
    while (((! Parser_check(self, TokenKind_RBrace)) && (! Parser_atEnd(self)))) {
        if ((Parser_check(self, TokenKind_String) || Parser_check(self, TokenKind_RawString))) {
            Parser_advance(self);
        } else {
            {
                Parser_parseExpr(self);
            }
        }
        Parser_match(self, TokenKind_Comma);
        Parser_match(self, TokenKind_Semicolon);
    }
    Parser_expect(self, TokenKind_RBrace);
    return Parser_allocNode(self);
}
NodeId Parser_parseExprOrDecl(Parser* self) {
    if ((Parser_check(self, TokenKind_Var) || Parser_check(self, TokenKind_Const))) {
        Parser_advance(self);
        Parser_expect(self, TokenKind_Ident);
        Parser_expect(self, TokenKind_Equal);
        Parser_parseExpr(self);
        Parser_expect(self, TokenKind_Semicolon);
        return Parser_allocNode(self);
    }
    NodeId expr = Parser_parseExpr(self);
    if (Parser_check(self, TokenKind_Ident)) {
        Parser_advance(self);
        if (Parser_match(self, TokenKind_Equal)) {
            Parser_parseExpr(self);
        }
        Parser_expect(self, TokenKind_Semicolon);
        return Parser_allocNode(self);
    }
    if (Parser_match(self, TokenKind_Semicolon)) {
        return expr;
    }
    Parser_expect(self, TokenKind_Semicolon);
    return expr;
}



typedef struct GenericParam GenericParam;
typedef struct ExprKind ExprKind;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct SourceMap SourceMap;
typedef struct InternEntry InternEntry;
typedef struct Parser Parser;
typedef struct StmtKind StmtKind;
typedef struct File File;
typedef struct TypeEntry TypeEntry;
typedef struct Param Param;
typedef struct SwitchCase SwitchCase;
typedef struct Token Token;
typedef struct Lexer Lexer;
typedef struct FlagBranch FlagBranch;
typedef struct EscapeResult EscapeResult;
typedef struct FileEntry FileEntry;
typedef struct ParserMark ParserMark;
typedef struct PatKind PatKind;
typedef struct TypeKind TypeKind;
typedef struct Stmt Stmt;
typedef struct TraitBound TraitBound;
typedef struct VariantVariant VariantVariant;
typedef struct Decl Decl;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Node Node;
typedef struct NodeKind NodeKind;
typedef struct DeclKind DeclKind;
typedef struct Field Field;
typedef struct AstContext AstContext;
typedef struct TestResult TestResult;
typedef struct Pat Pat;
typedef struct IdentifierTable IdentifierTable;
typedef struct Expr Expr;
typedef struct NodeId NodeId;
typedef struct Diagnostic Diagnostic;
typedef struct DiagInfo DiagInfo;
typedef struct Span Span;
typedef struct Label Label;
typedef struct Attribute Attribute;
typedef struct ImportSymbol ImportSymbol;
typedef struct SourceLoc SourceLoc;
typedef struct IdentEntry IdentEntry;
typedef struct Slice Slice;
typedef struct EnumVariant EnumVariant;
typedef struct Ast Ast;
typedef enum ErrorCode ErrorCode;
typedef enum Severity Severity;
typedef enum TokenKind TokenKind;


NodeId Parser_storeDecl(Parser* self, DeclKind kind);
NodeId Parser_parseDecl(Parser* self);
_Bool Parser_isTypeStart(Parser* self);
NodeId Parser_parseFuncOrVarDecl(Parser* self, _Bool isPub, _Bool isExtern, _Bool isStatic);
NodeId Parser_parseGenericParams(Parser* self);
NodeId Parser_parseFuncDecl(Parser* self);
NodeId Parser_parseParam(Parser* self);
NodeId Parser_parseStructDecl(Parser* self);
NodeId Parser_parseEnumDecl(Parser* self);
NodeId Parser_parseVariantDecl(Parser* self);
NodeId Parser_parseUnionDecl(Parser* self);
NodeId Parser_parseTraitDecl(Parser* self);
NodeId Parser_parseExtendDecl(Parser* self);
NodeId Parser_parseTypedefDecl(Parser* self);
NodeId Parser_parseDistinctDecl(Parser* self);
NodeId Parser_parseFlagDecl(Parser* self);
NodeId Parser_parseImportDecl(Parser* self);
NodeId Parser_parseModReexport(Parser* self);
NodeId Parser_parseComptimeDecl(Parser* self);

NodeId Parser_storeDecl(Parser* self, DeclKind kind) {
    NodeId id = AstContext_allocNodeSlot(self->ctx);
    if ((id.index == 0)) {
        return id;
    }
    Decl d;
    (d.kind = kind);
    Node n;
    (n.kind = (NodeKind){ .tag = NodeKind_Decl, .payload.Decl = {.value = d} });
    return id;
}
NodeId Parser_parseDecl(Parser* self) {
    while (Parser_match(self, TokenKind_AttrOpen)) {
        Parser_expect(self, TokenKind_Ident);
        if (Parser_check(self, TokenKind_LParen)) {
            Parser_advance(self);
            while (((! Parser_check(self, TokenKind_RParen)) && (! Parser_atEnd(self)))) {
                if (((Parser_check(self, TokenKind_Ident) || Parser_check(self, TokenKind_String)) || Parser_check(self, TokenKind_Dec))) {
                    Parser_advance(self);
                } else {
                    Parser_advance(self);
                }
                if ((! Parser_match(self, TokenKind_Comma))) {
                    break;
                }
            }
            Parser_expect(self, TokenKind_RParen);
        }
        while (Parser_match(self, TokenKind_Comma)) {
            Parser_expect(self, TokenKind_Ident);
            if (Parser_check(self, TokenKind_LParen)) {
                Parser_advance(self);
                while (((! Parser_check(self, TokenKind_RParen)) && (! Parser_atEnd(self)))) {
                    if (((Parser_check(self, TokenKind_Ident) || Parser_check(self, TokenKind_String)) || Parser_check(self, TokenKind_Dec))) {
                        Parser_advance(self);
                    } else {
                        Parser_advance(self);
                    }
                    if ((! Parser_match(self, TokenKind_Comma))) {
                        break;
                    }
                }
                Parser_expect(self, TokenKind_RParen);
            }
        }
        Parser_expect(self, TokenKind_AttrClose);
    }
    _Bool isPub = Parser_match(self, TokenKind_Pub);
    _Bool isExtern = Parser_match(self, TokenKind_Extern);
    if ((isExtern && Parser_check(self, TokenKind_LParen))) {
        Parser_advance(self);
        Parser_expect(self, TokenKind_String);
        Parser_expect(self, TokenKind_RParen);
    }
    _Bool isStatic = Parser_match(self, TokenKind_Static);
    if (Parser_check(self, TokenKind_Struct)) {
        return Parser_parseStructDecl(self);
    }
    if (Parser_check(self, TokenKind_Enum)) {
        return Parser_parseEnumDecl(self);
    }
    if (Parser_check(self, TokenKind_Variant)) {
        return Parser_parseVariantDecl(self);
    }
    if (Parser_check(self, TokenKind_Union)) {
        return Parser_parseUnionDecl(self);
    }
    if (Parser_check(self, TokenKind_Trait)) {
        return Parser_parseTraitDecl(self);
    }
    if (Parser_check(self, TokenKind_Extend)) {
        return Parser_parseExtendDecl(self);
    }
    if (Parser_check(self, TokenKind_Typedef)) {
        return Parser_parseTypedefDecl(self);
    }
    if (Parser_check(self, TokenKind_Distinct)) {
        return Parser_parseDistinctDecl(self);
    }
    if (Parser_check(self, TokenKind_Flag)) {
        return Parser_parseFlagDecl(self);
    }
    if (Parser_check(self, TokenKind_Import)) {
        return Parser_parseImportDecl(self);
    }
    if (Parser_check(self, TokenKind_Mod)) {
        return Parser_parseModReexport(self);
    }
    if (Parser_check(self, TokenKind_Comptime)) {
        return Parser_parseComptimeDecl(self);
    }
    if (((isExtern || isStatic) || Parser_isTypeStart(self))) {
        return Parser_parseFuncOrVarDecl(self, isPub, isExtern, isStatic);
    }
    (self->panicMode = 1);
    return Parser_noneNode(self);
}
_Bool Parser_isTypeStart(Parser* self) {
    TokenKind k = self->current.kind;
    switch (k) {
        case TokenKind_Void:
            return 1;
            break;
        case TokenKind_Bool:
            return 1;
            break;
        case TokenKind_Char:
            return 1;
            break;
        case TokenKind_U8:
            return 1;
            break;
        case TokenKind_I8:
            return 1;
            break;
        case TokenKind_U16:
            return 1;
            break;
        case TokenKind_I16:
            return 1;
            break;
        case TokenKind_U32:
            return 1;
            break;
        case TokenKind_I32:
            return 1;
            break;
        case TokenKind_U64:
            return 1;
            break;
        case TokenKind_I64:
            return 1;
            break;
        case TokenKind_U128:
            return 1;
            break;
        case TokenKind_I128:
            return 1;
            break;
        case TokenKind_F32:
            return 1;
            break;
        case TokenKind_F64:
            return 1;
            break;
        case TokenKind_Usize:
            return 1;
            break;
        case TokenKind_Isize:
            return 1;
            break;
        case TokenKind_Rawptr:
            return 1;
            break;
        case TokenKind_Str:
            return 1;
            break;
        case TokenKind_Ident:
            return 1;
            break;
        case TokenKind_LParen:
            return 1;
            break;
        case TokenKind_Struct:
            return 1;
            break;
        default:
            return 0;
            break;
    }
}
NodeId Parser_parseFuncOrVarDecl(Parser* self, _Bool isPub, _Bool isExtern, _Bool isStatic) {
    Ty retType = Parser_parseType(self);
    Token nameTok = Parser_expect(self, TokenKind_Ident);
    Str name = AstContext_intern(self->ctx, nameTok.data.ptr, nameTok.data.len);
    if (Parser_check(self, TokenKind_Less)) {
        Parser_parseGenericParams(self);
    }
    if (Parser_check(self, TokenKind_LParen)) {
        Parser_expect(self, TokenKind_LParen);
        if ((! Parser_check(self, TokenKind_RParen))) {
            Parser_parseParam(self);
            while (Parser_match(self, TokenKind_Comma)) {
                Parser_parseParam(self);
            }
        }
        Parser_expect(self, TokenKind_RParen);
        if (Parser_match(self, TokenKind_Semicolon)) {
            return Parser_allocNode(self);
        }
        Parser_expect(self, TokenKind_LBrace);
        while (((! Parser_check(self, TokenKind_RBrace)) && (! Parser_atEnd(self)))) {
            Parser_parseStmt(self);
        }
        Parser_expect(self, TokenKind_RBrace);
        return Parser_allocNode(self);
    }
    Parser_expect(self, TokenKind_Equal);
    Parser_parseExpr(self);
    Parser_expect(self, TokenKind_Semicolon);
    return Parser_allocNode(self);
}
NodeId Parser_parseGenericParams(Parser* self) {
    Parser_expect(self, TokenKind_Less);
    Parser_expect(self, TokenKind_Ident);
    if (Parser_match(self, TokenKind_Colon)) {
        Parser_expect(self, TokenKind_Ident);
        while (Parser_match(self, TokenKind_Comma)) {
            Parser_expect(self, TokenKind_Ident);
        }
    }
    while (Parser_match(self, TokenKind_Comma)) {
        Parser_expect(self, TokenKind_Ident);
        if (Parser_match(self, TokenKind_Colon)) {
            Parser_expect(self, TokenKind_Ident);
        }
    }
    if (Parser_check(self, TokenKind_Shr)) {
        Parser_advance(self);
        return Parser_allocNode(self);
    }
    Parser_expect(self, TokenKind_Greater);
    return Parser_allocNode(self);
}
NodeId Parser_parseFuncDecl(Parser* self) {
    Ty retType = Parser_parseType(self);
    Parser_expect(self, TokenKind_Ident);
    if (Parser_check(self, TokenKind_Less)) {
        Parser_parseGenericParams(self);
    }
    Parser_expect(self, TokenKind_LParen);
    if ((! Parser_check(self, TokenKind_RParen))) {
        Parser_parseParam(self);
        while (Parser_match(self, TokenKind_Comma)) {
            Parser_parseParam(self);
        }
    }
    Parser_expect(self, TokenKind_RParen);
    if (Parser_match(self, TokenKind_Semicolon)) {
        return Parser_allocNode(self);
    }
    Parser_expect(self, TokenKind_LBrace);
    while (((! Parser_check(self, TokenKind_RBrace)) && (! Parser_atEnd(self)))) {
        Parser_parseStmt(self);
    }
    Parser_expect(self, TokenKind_RBrace);
    return Parser_allocNode(self);
}
NodeId Parser_parseParam(Parser* self) {
    if (Parser_check(self, TokenKind_Self)) {
        Parser_advance(self);
        return Parser_allocNode(self);
    }
    Parser_parseType(self);
    Parser_expect(self, TokenKind_Ident);
    return Parser_allocNode(self);
}
NodeId Parser_parseStructDecl(Parser* self) {
    Parser_expect(self, TokenKind_Struct);
    Parser_expect(self, TokenKind_Ident);
    if (Parser_check(self, TokenKind_Less)) {
        Parser_parseGenericParams(self);
    }
    Parser_expect(self, TokenKind_LBrace);
    while (((! Parser_check(self, TokenKind_RBrace)) && (! Parser_atEnd(self)))) {
        Parser_match(self, TokenKind_Pub);
        if ((Parser_check(self, TokenKind_Extern) || Parser_check(self, TokenKind_Static))) {
            Parser_parseFuncDecl(self);
            continue;
        }
        ParserMark mark = Parser_save(self);
        Parser_parseType(self);
        Parser_expect(self, TokenKind_Ident);
        _Bool isMethod = Parser_check(self, TokenKind_LParen);
        Parser_restore(self, mark);
        if (isMethod) {
            Parser_parseFuncDecl(self);
            continue;
        }
        Parser_parseType(self);
        Parser_expect(self, TokenKind_Ident);
        if (Parser_match(self, TokenKind_Equal)) {
            Parser_parseExpr(self);
        }
        Parser_match(self, TokenKind_Comma);
        Parser_match(self, TokenKind_Semicolon);
    }
    Parser_expect(self, TokenKind_RBrace);
    return Parser_allocNode(self);
}
NodeId Parser_parseEnumDecl(Parser* self) {
    Parser_expect(self, TokenKind_Enum);
    Parser_expect(self, TokenKind_Ident);
    if (Parser_match(self, TokenKind_Colon)) {
        Parser_parseType(self);
    }
    Parser_expect(self, TokenKind_LBrace);
    if ((! Parser_check(self, TokenKind_RBrace))) {
        Parser_expect(self, TokenKind_Ident);
        if (Parser_match(self, TokenKind_Equal)) {
            Parser_parseExpr(self);
        }
        while (Parser_match(self, TokenKind_Comma)) {
            if (Parser_check(self, TokenKind_RBrace)) {
                break;
            }
            Parser_expect(self, TokenKind_Ident);
            if (Parser_match(self, TokenKind_Equal)) {
                Parser_parseExpr(self);
            }
        }
    }
    Parser_expect(self, TokenKind_RBrace);
    return Parser_allocNode(self);
}
NodeId Parser_parseVariantDecl(Parser* self) {
    Parser_expect(self, TokenKind_Variant);
    Parser_expect(self, TokenKind_Ident);
    if (Parser_check(self, TokenKind_Less)) {
        Parser_parseGenericParams(self);
    }
    Parser_expect(self, TokenKind_LBrace);
    while (((! Parser_check(self, TokenKind_RBrace)) && (! Parser_atEnd(self)))) {
        if (Parser_check(self, TokenKind_Pub)) {
            Parser_advance(self);
            Parser_parseFuncDecl(self);
            continue;
        }
        Parser_expect(self, TokenKind_Ident);
        if ((! Parser_check(self, TokenKind_LBrace))) {
            Parser_match(self, TokenKind_Comma);
            continue;
        }
        Parser_expect(self, TokenKind_LBrace);
        while (((! Parser_check(self, TokenKind_RBrace)) && (! Parser_atEnd(self)))) {
            Parser_parseType(self);
            Parser_expect(self, TokenKind_Ident);
            if ((! Parser_match(self, TokenKind_Comma))) {
                break;
            }
        }
        Parser_expect(self, TokenKind_RBrace);
        Parser_match(self, TokenKind_Comma);
    }
    Parser_expect(self, TokenKind_RBrace);
    return Parser_allocNode(self);
}
NodeId Parser_parseUnionDecl(Parser* self) {
    Parser_expect(self, TokenKind_Union);
    Parser_expect(self, TokenKind_Ident);
    if (Parser_check(self, TokenKind_Less)) {
        Parser_parseGenericParams(self);
    }
    Parser_expect(self, TokenKind_LBrace);
    while (((! Parser_check(self, TokenKind_RBrace)) && (! Parser_atEnd(self)))) {
        if (Parser_check(self, TokenKind_Pub)) {
            Parser_advance(self);
            Parser_parseFuncDecl(self);
            continue;
        }
        if (Parser_isTypeStart(self)) {
            Parser_parseFuncDecl(self);
            continue;
        }
        Parser_match(self, TokenKind_Pub);
        Parser_parseType(self);
        Parser_expect(self, TokenKind_Ident);
        Parser_match(self, TokenKind_Comma);
        Parser_match(self, TokenKind_Semicolon);
    }
    Parser_expect(self, TokenKind_RBrace);
    return Parser_allocNode(self);
}
NodeId Parser_parseTraitDecl(Parser* self) {
    Parser_expect(self, TokenKind_Trait);
    Parser_expect(self, TokenKind_Ident);
    if (Parser_check(self, TokenKind_Less)) {
        Parser_parseGenericParams(self);
    }
    Parser_expect(self, TokenKind_LBrace);
    while (((! Parser_check(self, TokenKind_RBrace)) && (! Parser_atEnd(self)))) {
        Parser_parseFuncDecl(self);
    }
    Parser_expect(self, TokenKind_RBrace);
    return Parser_allocNode(self);
}
NodeId Parser_parseExtendDecl(Parser* self) {
    Parser_expect(self, TokenKind_Extend);
    Parser_parseType(self);
    if (Parser_match(self, TokenKind_Colon)) {
        Parser_expect(self, TokenKind_Ident);
    }
    Parser_expect(self, TokenKind_LBrace);
    while (((! Parser_check(self, TokenKind_RBrace)) && (! Parser_atEnd(self)))) {
        Parser_parseFuncDecl(self);
    }
    Parser_expect(self, TokenKind_RBrace);
    return Parser_allocNode(self);
}
NodeId Parser_parseTypedefDecl(Parser* self) {
    Parser_expect(self, TokenKind_Typedef);
    Token nameTok = Parser_expect(self, TokenKind_Ident);
    Str name = AstContext_intern(self->ctx, nameTok.data.ptr, nameTok.data.len);
    Parser_expect(self, TokenKind_Equal);
    Ty target = Parser_parseType(self);
    Parser_expect(self, TokenKind_Semicolon);
    return Parser_storeDecl(self, (DeclKind){ .tag = DeclKind_TypeAlias, .payload.TypeAlias = {.name = name, .target = target, .flags = 0} });
}
NodeId Parser_parseDistinctDecl(Parser* self) {
    Parser_expect(self, TokenKind_Distinct);
    Token nameTok = Parser_expect(self, TokenKind_Ident);
    Str name = AstContext_intern(self->ctx, nameTok.data.ptr, nameTok.data.len);
    Parser_expect(self, TokenKind_Equal);
    Ty base = Parser_parseType(self);
    Parser_expect(self, TokenKind_Semicolon);
    return Parser_storeDecl(self, (DeclKind){ .tag = DeclKind_Distinct, .payload.Distinct = {.name = name, .baseType = base, .flags = 0} });
}
NodeId Parser_parseFlagDecl(Parser* self) {
    Parser_expect(self, TokenKind_Flag);
    Parser_expect(self, TokenKind_LParen);
    Parser_expect(self, TokenKind_Ident);
    Parser_expect(self, TokenKind_RParen);
    Parser_expect(self, TokenKind_LBrace);
    while (((! Parser_check(self, TokenKind_RBrace)) && (! Parser_atEnd(self)))) {
        if ((! Parser_match(self, TokenKind_Else))) {
            Parser_expect(self, TokenKind_Ident);
        }
        Parser_expect(self, TokenKind_FatArrow);
        Parser_expect(self, TokenKind_LBrace);
        while (((! Parser_check(self, TokenKind_RBrace)) && (! Parser_atEnd(self)))) {
            Parser_parseStmt(self);
        }
        Parser_expect(self, TokenKind_RBrace);
        Parser_match(self, TokenKind_Comma);
    }
    Parser_expect(self, TokenKind_RBrace);
    return Parser_allocNode(self);
}
NodeId Parser_parseImportDecl(Parser* self) {
    Parser_expect(self, TokenKind_Import);
    if (Parser_match(self, TokenKind_LParen)) {
        Parser_expect(self, TokenKind_Ident);
        Parser_expect(self, TokenKind_RParen);
    }
    if (Parser_check(self, TokenKind_String)) {
        Parser_advance(self);
    } else {
        {
            Parser_expect(self, TokenKind_Ident);
            while (Parser_match(self, TokenKind_ColonColon)) {
                Parser_expect(self, TokenKind_Ident);
            }
        }
    }
    if (Parser_match(self, TokenKind_LBrace)) {
        if ((! Parser_check(self, TokenKind_RBrace))) {
            Parser_expect(self, TokenKind_Ident);
            if (Parser_match(self, TokenKind_As)) {
                Parser_expect(self, TokenKind_Ident);
            }
            while (Parser_match(self, TokenKind_Comma)) {
                if (Parser_check(self, TokenKind_RBrace)) {
                    break;
                }
                if (Parser_match(self, TokenKind_Star)) {
                    break;
                }
                Parser_expect(self, TokenKind_Ident);
                if (Parser_match(self, TokenKind_As)) {
                    Parser_expect(self, TokenKind_Ident);
                }
            }
        }
        Parser_expect(self, TokenKind_RBrace);
    }
    Parser_match(self, TokenKind_Semicolon);
    return Parser_allocNode(self);
}
NodeId Parser_parseModReexport(Parser* self) {
    Parser_expect(self, TokenKind_Mod);
    Parser_expect(self, TokenKind_Ident);
    Parser_expect(self, TokenKind_Equal);
    Parser_expect(self, TokenKind_Import);
    if (Parser_match(self, TokenKind_LParen)) {
        Parser_expect(self, TokenKind_Ident);
        Parser_expect(self, TokenKind_RParen);
    }
    if (Parser_check(self, TokenKind_String)) {
        Parser_advance(self);
    } else {
        {
            Parser_expect(self, TokenKind_Ident);
            while (Parser_match(self, TokenKind_ColonColon)) {
                Parser_expect(self, TokenKind_Ident);
            }
        }
    }
    Parser_match(self, TokenKind_Semicolon);
    return Parser_allocNode(self);
}
NodeId Parser_parseComptimeDecl(Parser* self) {
    Parser_expect(self, TokenKind_Comptime);
    Parser_expect(self, TokenKind_LBrace);
    while (((! Parser_check(self, TokenKind_RBrace)) && (! Parser_atEnd(self)))) {
        Parser_parseDecl(self);
    }
    Parser_expect(self, TokenKind_RBrace);
    return Parser_allocNode(self);
}



typedef struct GenericParam GenericParam;
typedef struct ExprKind ExprKind;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct SourceMap SourceMap;
typedef struct InternEntry InternEntry;
typedef struct Parser Parser;
typedef struct StmtKind StmtKind;
typedef struct File File;
typedef struct TypeEntry TypeEntry;
typedef struct Param Param;
typedef struct SwitchCase SwitchCase;
typedef struct Token Token;
typedef struct Lexer Lexer;
typedef struct FlagBranch FlagBranch;
typedef struct EscapeResult EscapeResult;
typedef struct FileEntry FileEntry;
typedef struct ParserMark ParserMark;
typedef struct PatKind PatKind;
typedef struct TypeKind TypeKind;
typedef struct Stmt Stmt;
typedef struct TraitBound TraitBound;
typedef struct VariantVariant VariantVariant;
typedef struct Decl Decl;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Node Node;
typedef struct NodeKind NodeKind;
typedef struct DeclKind DeclKind;
typedef struct Field Field;
typedef struct AstContext AstContext;
typedef struct TestResult TestResult;
typedef struct Pat Pat;
typedef struct IdentifierTable IdentifierTable;
typedef struct Expr Expr;
typedef struct NodeId NodeId;
typedef struct Diagnostic Diagnostic;
typedef struct DiagInfo DiagInfo;
typedef struct Span Span;
typedef struct Label Label;
typedef struct Attribute Attribute;
typedef struct ImportSymbol ImportSymbol;
typedef struct SourceLoc SourceLoc;
typedef struct IdentEntry IdentEntry;
typedef struct Slice Slice;
typedef struct EnumVariant EnumVariant;
typedef struct Ast Ast;
typedef enum ErrorCode ErrorCode;
typedef enum Severity Severity;
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

Parser Parser_init(Parser* self, Lexer* lexer, AstContext* ctx) {
    Parser p;
    (p.lexer = lexer);
    (p.ctx = ctx);
    (p.panicMode = 0);
    (p.pendingGreater = 0);
    (p.current = Lexer_nextToken(lexer));
    (p.previous = p.current);
    return p;
}
Token Parser_advance(Parser* self) {
    (self->previous = self->current);
    (self->current = Lexer_nextToken(self->lexer));
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



typedef struct GenericParam GenericParam;
typedef struct ExprKind ExprKind;
typedef struct IdentifierInfo IdentifierInfo;
typedef struct SourceMap SourceMap;
typedef struct InternEntry InternEntry;
typedef struct Parser Parser;
typedef struct StmtKind StmtKind;
typedef struct File File;
typedef struct TypeEntry TypeEntry;
typedef struct Param Param;
typedef struct SwitchCase SwitchCase;
typedef struct Token Token;
typedef struct Lexer Lexer;
typedef struct FlagBranch FlagBranch;
typedef struct EscapeResult EscapeResult;
typedef struct FileEntry FileEntry;
typedef struct ParserMark ParserMark;
typedef struct PatKind PatKind;
typedef struct TypeKind TypeKind;
typedef struct Stmt Stmt;
typedef struct TraitBound TraitBound;
typedef struct VariantVariant VariantVariant;
typedef struct Decl Decl;
typedef struct DiagnosticEngine DiagnosticEngine;
typedef struct Node Node;
typedef struct NodeKind NodeKind;
typedef struct DeclKind DeclKind;
typedef struct Field Field;
typedef struct AstContext AstContext;
typedef struct TestResult TestResult;
typedef struct Pat Pat;
typedef struct IdentifierTable IdentifierTable;
typedef struct Expr Expr;
typedef struct NodeId NodeId;
typedef struct Diagnostic Diagnostic;
typedef struct DiagInfo DiagInfo;
typedef struct Span Span;
typedef struct Label Label;
typedef struct Attribute Attribute;
typedef struct ImportSymbol ImportSymbol;
typedef struct SourceLoc SourceLoc;
typedef struct IdentEntry IdentEntry;
typedef struct Slice Slice;
typedef struct EnumVariant EnumVariant;
typedef struct Ast Ast;
typedef enum ErrorCode ErrorCode;
typedef enum Severity Severity;
typedef enum TokenKind TokenKind;

extern int32_t printf(uint8_t* fmt, ...);
extern void* malloc(size_t size);
extern void free(void* ptr);

size_t sourceLen(uint8_t* src);
void TestResult_print(TestResult* self);
TestResult runParser(uint8_t* src, size_t len);
TestResult runExpr(uint8_t* src, size_t len);
void testExpr();
void testFunc();
void testVariant();
void testSwitch();
void testSwitchStmt();
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
extern void* malloc(size_t size);
extern void free(void* ptr);
size_t sourceLen(uint8_t* src) {
    size_t len = 0;
    while ((src[len] != 0)) {
        (len = (len + 1));
    }
    return len;
}
void TestResult_print(TestResult* self) {
    printf("tokens=%u nodes=%u errors=%u\n", self->tokens, self->nodes, self->errors);
}
TestResult runParser(uint8_t* src, size_t len) {
    AstContext ctx;
    AstContext_init(&ctx, 4096, 4096, 4096);
    IdentEntry* identEntries = malloc((256 * 64));
    IdentifierTable idents;
    IdentifierTable_init(&idents, identEntries, 256);
    IdentifierTable_addKeywords(&idents);
    Lexer lexer;
    (lexer.bufStart = src);
    (lexer.cur = src);
    (lexer.bufEnd = (src + len));
    (lexer.line = 1);
    (lexer.lineStart = src);
    (lexer.diag = NULL);
    (lexer.idents = (& idents));
    Parser p;
    (p.lexer = (& lexer));
    (p.ctx = (& ctx));
    (p.panicMode = 0);
    (p.pendingGreater = 0);
    (p.current = Lexer_nextToken(&lexer));
    (p.previous = p.current);
    uint32_t decls = 0;
    while ((! Parser_atEnd(&p))) {
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
    free(identEntries);
    return r;
}
TestResult runExpr(uint8_t* src, size_t len) {
    AstContext ctx;
    AstContext_init(&ctx, 4096, 4096, 4096);
    IdentEntry* identEntries = malloc((256 * 64));
    IdentifierTable idents;
    IdentifierTable_init(&idents, identEntries, 256);
    IdentifierTable_addKeywords(&idents);
    Lexer lexer;
    (lexer.bufStart = src);
    (lexer.cur = src);
    (lexer.bufEnd = (src + len));
    (lexer.line = 1);
    (lexer.lineStart = src);
    (lexer.diag = NULL);
    (lexer.idents = (& idents));
    Parser p;
    (p.lexer = (& lexer));
    (p.ctx = (& ctx));
    (p.panicMode = 0);
    (p.pendingGreater = 0);
    (p.current = Lexer_nextToken(&lexer));
    (p.previous = p.current);
    Parser_parseExpr(&p);
    TestResult r;
    (r.tokens = 1);
    (r.nodes = AstContext_nodeCount(&ctx));
    (r.errors = p.panicMode);
    AstContext_deinit(&ctx);
    free(identEntries);
    return r;
}
void testExpr() {
    uint8_t* src = "a + b * (c - d);";
    printf("expr test: ");
    TestResult r = runExpr(src, sourceLen(src));
    TestResult_print(&r);
}
void testFunc() {
    uint8_t* src = "pub i32 add(u32 a, u32 b) { return a + b; }";
    printf("func test: ");
    TestResult r = runParser(src, sourceLen(src));
    TestResult_print(&r);
}
void testVariant() {
    uint8_t* src = "pub variant Option { Some { u32 value }, None }";
    printf("variant test: ");
    TestResult r = runParser(src, sourceLen(src));
    TestResult_print(&r);
}
void testSwitch() {
    uint8_t* src = "switch (x) { A => { 1 }, else => { 0 } }";
    printf("switch test: ");
    TestResult r = runExpr(src, sourceLen(src));
    TestResult_print(&r);
}
void testSwitchStmt() {
    uint8_t* src = "void f() { switch (x) { A => { a; }, else => { b; } } }";
    printf("switch stmt test: ");
    TestResult r = runParser(src, sourceLen(src));
    TestResult_print(&r);
}
void testFlag() {
    uint8_t* src = "flag(PLATFORM) { linux => { a; }, else => { b; } }";
    printf("flag test: ");
    TestResult r = runParser(src, sourceLen(src));
    TestResult_print(&r);
}
void testImport() {
    uint8_t* src = "import \"path\" { foo, bar as baz };";
    printf("import path test: ");
    TestResult r = runParser(src, sourceLen(src));
    TestResult_print(&r);
}
void testImportRoot() {
    uint8_t* src = "import file::math::core { square };";
    printf("import root test: ");
    TestResult r = runParser(src, sourceLen(src));
    TestResult_print(&r);
}
void testImportLib() {
    uint8_t* src = "import(lib) std::math { pow };";
    printf("import lib test: ");
    TestResult r = runParser(src, sourceLen(src));
    TestResult_print(&r);
}
void testModReexport() {
    uint8_t* src = "pub mod m = import \"path\";";
    printf("mod reexport test: ");
    TestResult r = runParser(src, sourceLen(src));
    TestResult_print(&r);
}
void testAttr() {
    uint8_t* src = "[[packed]] pub struct Foo { u32 x; }";
    printf("attr test: ");
    TestResult r = runParser(src, sourceLen(src));
    TestResult_print(&r);
}
/* pub */ int32_t main() {
    printf("****coral parser self-test****\n");
    testExpr();
    testFunc();
    testVariant();
    testSwitch();
    testSwitchStmt();
    testFlag();
    testImport();
    testImportRoot();
    testImportLib();
    testModReexport();
    testAttr();
    printf("****done****\n");
    return 0;
}
