// bitarray.c
// Řešení IJC-DU1, příklad a), 16.3.2026
// Autor: Štěpán Hořenek, FIT
// Přeloženo: gcc 14.2
// ...popis příkladu - poznámky, omezení, atd
#include "bitarray.h"

#ifdef USE_INLINE

extern inline void bitarray_free(bitarray_t name);
extern inline bitarray_index_t bitarray_size(bitarray_t name);
extern inline void bitarray_fill(bitarray_t name, bool bool_in);
extern inline void bitarray_setbit(bitarray_t name, bitarray_index_t index, bool bool_in);
extern inline bool bitarray_getbit(bitarray_t name, bitarray_index_t index);

#endif