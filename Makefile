# eratosthenes.h
# Řešení IJC-DU1, příklad a), 16.3.2026
# Autor: Štěpán Hořenek, FIT
# Přeloženo: gcc 14.2
# ...popis příkladu - poznámky, omezení, atd
CC=gcc
CFLAGS=-g -std=c11 -pedantic -Wall -Wextra -O2
LDLIBS=-lm

.PHONY: all run zip clean

all: primes primes-i no-comment

primes: primes.c eratosthenes.c bitarray.c error.c
	$(CC) $(CFLAGS) primes.c eratosthenes.c bitarray.c error.c -o $@ $(LDLIBS)

primes-i: primes.c eratosthenes.c bitarray.c error.c
	$(CC) $(CFLAGS) -DUSE_INLINE primes.c eratosthenes.c bitarray.c error.c -o $@ $(LDLIBS)

no-comment: no-comment.c error.c
	$(CC) $(CFLAGS) no-comment.c error.c -o no-comment

run: primes primes-i
	ulimit -s 60000 && ./primes
	ulimit -s 60000 && ./primes-i

zip:
	zip xhorens00.zip *.c *.h Makefile

clean:
	rm *.o *.zip primes primes-i no-comment

