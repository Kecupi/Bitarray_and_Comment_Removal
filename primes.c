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
    size_t rot_idx = 0;
    unsigned long last_primes[OUT_MAX];
    for (unsigned long field_idx = 0; field_idx < field_size; field_idx++){
        if (bitarray_getbit(field, field_idx)){
            last_primes[rot_idx % 10]  = field_idx;
            rot_idx += 1;
        }
    }
    for (size_t idx = 0; idx < OUT_MAX; idx++){
        printf("%lu\n", last_primes[(idx + rot_idx) % 10]);
    }
    fprintf(stderr, "Time=%.3g\n", (double)(clock()-start)/CLOCKS_PER_SEC);
    return 0;
}