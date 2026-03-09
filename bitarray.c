#include "bitarray.h"

#ifdef USE_INLINE

extern inline void bitarray_free(bitarray_t name);
extern inline bitarray_index_t bitarray_size(bitarray_t name);
extern inline void bitarray_fill(bitarray_t name, bool bool_in);
extern inline void bitarray_setbit(bitarray_t name, bitarray_index_t index, bool bool_in);
extern inline bool bitarray_getbit(bitarray_t name, bitarray_index_t index);

#endif