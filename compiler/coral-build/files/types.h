#pragma once
// Sized types, spelled the way the codebase wants them (not uintN_t-ish).
typedef unsigned char       u8;
typedef unsigned short      u16;
typedef unsigned int        u32;
typedef unsigned long long  u64;

typedef signed char  i8;
typedef short         i16;
typedef int           i32;
typedef long long     i64;

typedef float  f32;
typedef double f64;

// Every method below refers to its own instance as `self` rather than the
// bare C++ `this`. It is exactly `this` -- just an alias for readability,
// so method bodies read `self->pos`, `self->arena`, etc.
#define self (this)
