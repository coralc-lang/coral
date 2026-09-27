#include "arena.h"

static ArenaBlock* newBlock(i64 size) {
    ArenaBlock* b = (ArenaBlock*)malloc(sizeof(ArenaBlock));
    b->data = (u8*)malloc((u64)size);
    b->size = size;
    b->used = 0;
    b->next = 0;
    return b;
}

void Arena::init(i64 blockSize) {
    self->blockSize = blockSize;
    self->head = newBlock(blockSize);
}

void* Arena::alloc(i64 size, i64 align) {
    if (size < 0) size = 0;
    if (align < 1) align = 1;

    ArenaBlock* b = self->head;
    i64 aligned = (b->used + (align - 1)) & ~(align - 1);
    if (aligned + size > b->size) {
        i64 newSize = self->blockSize;
        if (size + align > newSize) newSize = size + align;
        ArenaBlock* nb = newBlock(newSize);
        nb->next = b;
        self->head = nb;
        b = nb;
        aligned = 0;
    }
    void* ptr = b->data + aligned;
    b->used = aligned + size;
    return ptr;
}

void Arena::freeAll() {
    ArenaBlock* b = self->head;
    while (b) {
        ArenaBlock* next = b->next;
        free(b->data);
        free(b);
        b = next;
    }
    self->head = 0;
}
