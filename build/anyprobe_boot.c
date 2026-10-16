#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <assert.h>

typedef struct _coral_str { const uint8_t* ptr; size_t len; } _coral_str;

typedef uint32_t Str;
typedef uint32_t Ty;


int32_t f(uint8_t c);
int32_t main();

int32_t f(uint8_t c) {
    switch (c) {
        case 10:
        {
            return 1;
            break;
        }
        case any:
        {
            return 2;
            break;
        }
    }
    return 0;
}
int32_t main() {
    return (f(10) + f(99));
}
