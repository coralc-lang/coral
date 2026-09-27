#pragma once
#include "types.h"

// A string slice: pointer + length, nothing owned. Deliberately has NO
// user-declared constructors, so it stays a trivial/POD type and can live
// inside Value's union (ast.h) without any special-member-function
// complications. Construct one with Str::make / Str::fromCstr instead.
struct Str {
    const char* ptr;
    i64 len;

    static Str make(const char* p, i64 l);
    static Str fromCstr(const char* c);

    bool equals(Str other) const;
    bool equalsCstr(const char* c) const;
    void print() const;
};
