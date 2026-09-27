#include "str.h"
#include <cstring>
#include <cstdio>

Str Str::make(const char* p, i64 l) {
    Str s; s.ptr = p; s.len = l; return s;
}

Str Str::fromCstr(const char* c) {
    return Str::make(c, (i64)strlen(c));
}

bool Str::equals(Str other) const {
    if (self->len != other.len) return false;
    if (self->len == 0) return true;
    return memcmp(self->ptr, other.ptr, (u64)self->len) == 0;
}

bool Str::equalsCstr(const char* c) const {
    i64 l = (i64)strlen(c);
    if (self->len != l) return false;
    if (l == 0) return true;
    return memcmp(self->ptr, c, (u64)l) == 0;
}

void Str::print() const {
    fwrite(self->ptr, 1, (u64)self->len, stdout);
}
