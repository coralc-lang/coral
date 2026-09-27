#pragma once
#include "types.h"
#include <cstdlib>

// This is the only place that touches malloc/free directly. AST nodes and
// the dynamic arrays in dynarray.h are all carved out of an Arena and
// freed in one shot with freeAll(). The lexer does NOT use this -- see
// lexer.h for why.
struct ArenaBlock {
    u8* data;
    i64 size;
    i64 used;
    ArenaBlock* next;
};

struct Arena {
    ArenaBlock* head;
    i64 blockSize;

    void init(i64 blockSize);
    void* alloc(i64 size, i64 align);
    void freeAll();
};
