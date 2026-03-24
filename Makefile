# Makefile
# Řešení IJC-DU1, příklad a), 16.3.2026
# Autor: Štěpán Hořenek, FIT
# Přeloženo: gcc 14.2
# ...popis příkladu - poznámky, omezení, atd
CC=gcc
CFLAGS=-g -std=c11 -pedantic -Wall -Wextra -O2
LDLIBS=-lm

.PHONY: all run zip clean

all: primes primes-i no-comment

primes.o: primes.c error.h eratosthenes.h bitarray.h
eratosthenes.o: eratosthenes.c eratosthenes.h bitarray.h
bitarray.o: bitarray.c bitarray.h error.h
error.o: error.c error.h
no-comment.o: no-comment.c error.h

primes-i.o: primes.c error.h bitarray.h eratosthenes.h
	$(CC) $(CFLAGS) -DUSE_INLINE -c $< -o $@ $(LDLIBS)

bitarray-i.o: bitarray.c bitarray.h error.h
	$(CC) $(CFLAGS) -DUSE_INLINE -c $< -o $@ $(LDLIBS)

eratosthenes-i.o: eratosthenes.c bitarray.h eratosthenes.h
	$(CC) $(CFLAGS) -DUSE_INLINE -c $< -o $@ $(LDLIBS)

primes: primes.o eratosthenes.o bitarray.o error.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS)

primes-i: primes-i.o eratosthenes-i.o bitarray-i.o error.o
	$(CC) $(CFLAGS) -DUSE_INLINE $^ -o $@ $(LDLIBS)

no-comment: no-comment.o error.o
	$(CC) $(CFLAGS) $^ -o $@

run: primes primes-i
	ulimit -s 60000 && ./primes
	ulimit -s 60000 && ./primes-i

zip:
	zip xhorens00.zip *.c *.h Makefile

clean:
	rm -f *.o *.zip primes primes-i no-comment
