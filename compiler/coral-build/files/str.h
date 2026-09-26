#pragma once
#include "arena.h"
#include <cstring>
#include <cstdio>

// A non-owning (or arena-owned) string slice. No std::string anywhere.
struct Str {
    const char* ptr;
    long len;
};

inline Str str_make(const char* p, long l) {
    Str s; s.ptr = p; s.len = l; return s;
}

inline Str str_from_cstr(const char* p) {
    return str_make(p, (long)strlen(p));
}

inline bool str_eq(Str a, Str b) {
    if (a.len != b.len) return false;
    if (a.len == 0) return true;
    return memcmp(a.ptr, b.ptr, (unsigned long)a.len) == 0;
}

inline bool str_eq_cstr(Str a, const char* c) {
    long l = (long)strlen(c);
    if (a.len != l) return false;
    if (l == 0) return true;
    return memcmp(a.ptr, c, (unsigned long)l) == 0;
}

// Copies [p, p+len) into arena-owned, NUL-terminated storage.
inline Str str_copy_arena(Arena* arena, const char* p, long len) {
    char* buf = (char*)arena_alloc(arena, len + 1, 1);
    if (len > 0) memcpy(buf, p, (unsigned long)len);
    buf[len] = 0;
    return str_make(buf, len);
}

inline void str_print(Str s) {
    fwrite(s.ptr, 1, (unsigned long)s.len, stdout);
}
