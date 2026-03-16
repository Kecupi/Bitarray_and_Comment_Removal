// eratosthenes.c
// Řešení IJC-DU1, příklad a), 16.3.2026
// Autor: Štěpán Hořenek, FIT
// Přeloženo: gcc 14.2
// ...popis příkladu - poznámky, omezení, atd
#include "bitarray.h"
#include "eratosthenes.h"
#include <math.h>

void Eratosthenes(bitarray_t field){
    bitarray_fill(field, true); // set whole bitarray to 1s
    bitarray_setbit(field, 0, false); // set bitarray[0] to 0
    bitarray_setbit(field, 1, false); // set bitarray[1] to 0
    unsigned long bitarr_size = bitarray_size(field);
    unsigned long bitarr_sqrt = sqrt(bitarr_size);
    for (unsigned long num = 2; num <= bitarr_sqrt; num++){
        if (bitarray_getbit(field, num) == true){ // if number was already deemed not prime, skip it
            for (unsigned long mult = num * num; mult < bitarr_size; mult += num){
                bitarray_setbit(field, mult, false);
            }
        }
    }
}