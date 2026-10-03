#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <assert.h>

#undef INT8_MIN
#undef INT8_MAX
#undef INT16_MIN
#undef INT16_MAX
#undef INT32_MIN
#undef INT32_MAX
#undef INT64_MIN
#undef INT64_MAX

typedef struct _coral_str { const uint8_t* ptr; size_t len; } _coral_str;
