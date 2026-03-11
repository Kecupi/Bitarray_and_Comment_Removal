#ifndef BITARRAY_H
#define BITARRAY_H 1

#include <assert.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

typedef unsigned long* bitarray_t;
typedef unsigned long bitarray_index_t;
#define UL_SIZE (sizeof(unsigned long) * CHAR_BIT)

#define bitarray_create(name, size) \
    static_assert(size <= ULONG_MAX && size > 0, "Error: Invalid size of bitarray during static creation"); \
    bitarray_index_t name[1 + ((size + UL_SIZE - 1)/ UL_SIZE)] = {size, 0}

#define bitarray_alloc(name, size) \
    assert(size <= ULONG_MAX && size > 0); \
    bitarray_t name = calloc(1 + ((size + UL_SIZE - 1)/ UL_SIZE), sizeof(bitarray_index_t)); \
    if (name == NULL){ \
        fprintf(stderr, "bitarray_alloc: Chyba alokace paměti"); \
        exit(1); \
    } \
    name[0] = size

#ifndef USE_INLINE

#define bitarray_free(name) \
    (free(name))

#define bitarray_size(name) \
    (name[0])

#define bitarray_fill(name, bool_in) \
    do { \
        bitarray_index_t idx_count = 1 + ((bitarray_size(name)) + UL_SIZE - 1)/ UL_SIZE; \
        for (bitarray_index_t idx = 1; idx < idx_count ; idx++){ \
            name[idx] = bool_in ? ULONG_MAX : 0; \
        } \
    } while (0)

#define bitarray_setbit(name, index, bool_in) \
    bool_in ? (name[1 + (index / UL_SIZE)] |= (1UL << (index % UL_SIZE))) : (name[1 + (index / UL_SIZE)] &= ~(1UL << (index % UL_SIZE)))

#define bitarray_getbit(name, index) \
    ((name[1 + (index / UL_SIZE)] >> (index % UL_SIZE)) & 1UL)

#else

inline void bitarray_free(bitarray_t name){
    free(name);
}

inline bitarray_index_t bitarray_size(bitarray_t name){
    return name[0];
}

inline void bitarray_fill(bitarray_t name, bool bool_in){
    bitarray_index_t idx_count = 1 + ((bitarray_size(name)) + UL_SIZE - 1)/ UL_SIZE;
    for (bitarray_index_t idx = 1; idx < idx_count ; idx++){
        name[idx] = bool_in ? ULONG_MAX : 0;
    }
}

inline void bitarray_setbit(bitarray_t name, bitarray_index_t index, bool bool_in){
    bool_in ? (name[1 + (index / UL_SIZE)] |= (1UL << (index % UL_SIZE))) : (name[1 + (index / UL_SIZE)] &= ~(1UL << (index % UL_SIZE)));
}

inline bool bitarray_getbit(bitarray_t name, bitarray_index_t index){
    return ((name[1 + (index / UL_SIZE)] >> (index % UL_SIZE)) & 1UL);
}

#endif // end of USE_INLINE condition
#endif