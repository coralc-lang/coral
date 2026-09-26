#pragma once
#include "arena.h"
#include <cstring>

// Minimal growable array. Backed by the arena (old buffers just become
// garbage inside the arena until the whole arena is freed -- fine for a
// build-once-then-walk AST). This is a struct with free functions acting
// on it (composition), not a class with constructors/destructors.
template <typename T>
struct DynArray {
    T* data;
    long count;
    long capacity;
};

template <typename T>
inline void da_init(DynArray<T>* a) {
    a->data = 0;
    a->count = 0;
    a->capacity = 0;
}

template <typename T>
inline void da_push(Arena* arena, DynArray<T>* a, T value) {
    if (a->count >= a->capacity) {
        long newCap = a->capacity == 0 ? 4 : a->capacity * 2;
        T* newData = (T*)arena_alloc(arena, newCap * (long)sizeof(T), (long)alignof(T));
        if (a->data != 0 && a->count > 0) {
            memcpy(newData, a->data, (unsigned long)(a->count * (long)sizeof(T)));
        }
        a->data = newData;
        a->capacity = newCap;
    }
    a->data[a->count] = value;
    a->count = a->count + 1;
}
