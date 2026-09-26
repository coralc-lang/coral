#pragma once
// Simple bump/arena allocator. This is the only place we call malloc/free
// directly. Everything else (AST nodes, strings, dynamic arrays) is carved
// out of arena blocks and freed all at once with arena_free_all.
//
// "No std" here means: no STL containers, no std::string, no std::vector,
// no iostream, no smart pointers. Plain C allocation (malloc/free) is used
// as the underlying primitive, which is the usual convention for "no-std"
// C++ (freestanding-style) code.

#include <cstdlib>

struct ArenaBlock {
    char* data;
    long size;
    long used;
    ArenaBlock* next;
};

struct Arena {
    ArenaBlock* head;
    long blockSize;
};

inline ArenaBlock* arena_new_block(long size) {
    ArenaBlock* b = (ArenaBlock*)malloc(sizeof(ArenaBlock));
    b->data = (char*)malloc((unsigned long)size);
    b->size = size;
    b->used = 0;
    b->next = 0;
    return b;
}

inline void arena_init(Arena* a, long blockSize) {
    a->blockSize = blockSize;
    a->head = arena_new_block(blockSize);
}

inline void* arena_alloc(Arena* a, long size, long align) {
    if (size < 0) size = 0;
    if (align < 1) align = 1;
    ArenaBlock* b = a->head;
    long aligned = (b->used + (align - 1)) & ~(align - 1);
    if (aligned + size > b->size) {
        long newSize = a->blockSize;
        if (size + align > newSize) newSize = size + align;
        ArenaBlock* nb = arena_new_block(newSize);
        nb->next = b;
        a->head = nb;
        b = nb;
        aligned = 0;
    }
    void* ptr = b->data + aligned;
    b->used = aligned + size;
    return ptr;
}

inline void arena_free_all(Arena* a) {
    ArenaBlock* b = a->head;
    while (b) {
        ArenaBlock* next = b->next;
        free(b->data);
        free(b);
        b = next;
    }
    a->head = 0;
}
