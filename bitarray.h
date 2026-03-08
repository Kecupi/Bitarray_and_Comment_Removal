#ifndef BIT_ARRAY
#define BIT_ARRAY 1
#include <assert.h>

typedef unsigned long* bit_array;
typedef unsigned long bit_array_index_t;
#define UL_SIZE (sizeof(unsigned long) * CHAR_BIT)

#define bit_array_create(name, size) \
    _Static_assert( size <= ULONG_MAX && size > 0, "Error: Invalid size of bitarray during static creation"); \
    bit_array name[1 + ((size + UL_SIZE - 1)/ UL_SIZE)] = {(usigned long)(size), 0};

#endif