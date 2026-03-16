// primes.c
// Řešení IJC-DU1, příklad a), 16.3.2026
// Autor: Štěpán Hořenek, FIT
// Přeloženo: gcc 14.2
// ...popis příkladu - poznámky, omezení, atd
#include <stdio.h>
#include <time.h>
#include "bitarray.h"
#include "eratosthenes.h"

# define OUT_MAX 10
# define FIELD_SIZE 444000000

int main(){
    clock_t start = clock();
    bitarray_create(field, FIELD_SIZE);
    Eratosthenes(field);
    unsigned long field_size = bitarray_size(field);
    int res_idx = OUT_MAX - 1; // last index of last_primes
    unsigned long last_primes[OUT_MAX];
    for (unsigned long field_idx = field_size - 1; field_idx > 0; field_idx--){ // start from highest number (bitarray_idx) and continue to 0
        if (bitarray_getbit(field, field_idx)){
            last_primes[res_idx]  = field_idx;
            res_idx -= 1;
            if (res_idx < 0){ // if list was filled, break
                break;
            }
        }
    }
    res_idx += 1; // idx ends always 1 position bellow lowest last_primes index
    for (; res_idx < OUT_MAX; res_idx++){ // print from newest to oldest found
        printf("%lu\n", last_primes[res_idx]);
    }
    fprintf(stderr, "Time=%.3g\n", (double)(clock()-start)/CLOCKS_PER_SEC);
    return 0;
}