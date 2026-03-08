#ifndef BIT_ARRAY
#define BIT_ARRAY 1
#include <assert.h>
#include <stdlib.h>

typedef unsigned long* bit_array;
typedef unsigned long bit_array_index_t;
#define UL_SIZE (sizeof(unsigned long) * CHAR_BIT)

#define bit_array_create(name, size) \
    _Static_assert( size <= ULONG_MAX && size > 0, "Error: Invalid size of bitarray during static creation"); \
    bit_array name[1 + ((size + UL_SIZE - 1)/ UL_SIZE)] = {(usigned long)(size), 0};

#define bit_array_alloc(name, size) \
    assert( size <= ULONG_MAX && size > 0); \
    bit_array name = calloc(1 + ((size + UL_SIZE - 1)/ UL_SIZE), sizeof(unsigned long)); \
    if (name == NULL){ \
        fprintf(stderr, "bitarray_alloc: Chyba alokace paměti"); \
        exit(1); \
    } \
    name[0] = (unsigned long)(size); \

#define bit_array_free(name) (free(name))
#endif