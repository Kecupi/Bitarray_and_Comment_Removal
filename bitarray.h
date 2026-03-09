#ifndef BIT_ARRAY
#define BIT_ARRAY 1
#include <assert.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef unsigned long* bit_array;
typedef unsigned long bit_array_index_t;
#define UL_SIZE (sizeof(unsigned long) * CHAR_BIT)

#define bit_array_create(name, size) \
    static_assert(size <= ULONG_MAX && size > 0, "Error: Invalid size of bitarray during static creation"); \
    bit_array name[1 + ((size + UL_SIZE - 1)/ UL_SIZE)] = {(unsigned long)(size), 0}

#define bit_array_alloc(name, size) \
    assert(size <= ULONG_MAX && size > 0); \
    bit_array name = calloc(1 + ((size + UL_SIZE - 1)/ UL_SIZE), sizeof(unsigned long)); \
    if (name == NULL){ \
        fprintf(stderr, "bitarray_alloc: Chyba alokace paměti"); \
        exit(1); \
    } \
    name[0] = (unsigned long)(size)

#ifndef USE_INLINE

#define bit_array_free(name) (free(name))

#define bit_array_size(name) (name[0])

#define bit_array_fill(name, bool_in) \
    do { \
        unsigned long idx_count = 1 + ((bit_array_size(name)) + UL_SIZE - 1)/ UL_SIZE; \
        for (unsigned long idx = 1; idx < idx_count ; idx++){ \
            name[idx] = bool_in ? ULONG_MAX : 0; \
        } \
    } while (0)

#define bit_array_setbit(name, index, bool_in) \
    bool_in ? name[1 + (index / UL_SIZE)] |= (1UL << (index % UL_SIZE)): name[1 + (index / UL_SIZE)] &= ~(1UL << (index % UL_SIZE)); \

#define bit_array_getbit(name, index) \
    ((name[1 + (index / UL_SIZE)] >> (index % UL_SIZE)) & 1UL)

#else

inline void bit_array_free(bit_array name){
    free(name);
}

inline unsigned long bit_array_size(bit_array name){
    return name[0];
}

inline void bit_array_fill(bit_array name, bool bool_in){
    unsigned long idx_count = 1 + ((bit_array_size(name)) + UL_SIZE - 1)/ UL_SIZE;
    for (unsigned long idx = 1; idx < idx_count ; idx++){
        name[idx] = bool_in ? ULONG_MAX : 0;
    }
}

inline void bit_array_setbit(bit_array name, unsigned long index, bool bool_in){
    bool_in ? name[1 + (index / UL_SIZE)] |= (1UL << (index % UL_SIZE)): name[1 + (index / UL_SIZE)] &= ~(1UL << (index % UL_SIZE));
}

inline unsigned long bit_array_getbit(bit_array name, unsigned long index){
    return ((name[1 + (index / UL_SIZE)] >> (index % UL_SIZE)) & 1UL);
}

#endif
#endif