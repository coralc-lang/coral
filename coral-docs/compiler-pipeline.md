# Compiler Pipeline Note

## Current boundary

Coral follows a Clang-like split between semantic analysis and code generation:

1. The lexer converts source text into tokens.
2. The parser builds the AST, including generic declarations, type arguments, and `comptime` type parameters.
3. Sema builds declaration and lexical scopes, resolves names, checks assignments and mutability, validates types and calls, and checks generic declarations.
4. `coral-mono` performs monomorphization. It collects concrete uses such as `Box<u32>`, substitutes concrete types, and instantiates generic functions and types.
5. Each instantiated body is fully type-checked before code generation.
6. The backend emits code for the checked concrete instances.

Generic syntax is therefore handled in two places:

- Sema understands the generic declaration, its type-parameter scope, constraints, and valid generic type references.
- Mono creates concrete instantiations. Sema does not turn every generic use into a monomorphized instance itself.

`comptime T` is a separate type-level/comptime mechanism. It is not a generic-bound syntax such as `T: Bound`, and its concrete evaluation/instantiation behavior must remain distinct from ordinary runtime generic arguments.

The generic parser accepts the Coral forms currently used by the language, including `Name<T, U>` declarations and `Name<T>` type arguments. Bounds and other constraint syntax must not be invented; they need an explicit language rule before being accepted.

## Clang-inspired frontend

The Clang-like design applies to the whole frontend, not only Sema:

- The lexer owns token boundaries, numeric prefixes, keyword recognition, source spans, and lexer diagnostics.
- The parser owns precedence, lookahead/pending-token handling, declaration/expression/statement recovery, AST node storage, and parser diagnostics.
- Sema consumes the parser's stable AST and owns scopes, name binding, type construction, constraints, and semantic diagnostics.
- Mono and the backend consume checked concrete instances.

This separation is intentional: the lexer must not perform semantic classification, the parser must not perform name/type lookup, and Sema must not redo tokenization or generic monomorphization.

## Semantic responsibilities

The self-host semantic layer is split by responsibility:

- `scope.crl`: nested scopes, symbols, duplicate declarations, and assignment mutability.
- `decl.crl`: declaration binding and declaration-kind dispatch.
- `typecheck.crl`: type identity, compatibility, generic arity, and type checking.
- `expr.crl`: expression checking, calls, lvalues, and resolved expression types.
- `stmt.crl`: statement and function-body checking.
- `member.crl`: field/method lookup and member type resolution.
- `sema.crl`: semantic context ownership and diagnostics state.

The frontend `analyze.crl` seam runs lexer → parser → Sema and returns parse errors, semantic errors, and AST node count. The frontend test harness exercises these modules through `compiler/coral-frontend/test.crl`; it is not enough to compile the semantic files without running their tests.
