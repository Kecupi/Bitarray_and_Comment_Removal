# Information about project

This project consists of 2 parts: one is library implementing bitarray and its basic methods, the other is implementation of state automaton for removal of comments in C files in a manner that preprocessor does it.

## Bitarray Library

The bitarray library is implemented in 'bitarray.h'. The 'bitarray.c' is only present for proper functioning of inline functions in said header file.

The library is tested on Erathosthenes sieve that uses bitarray implementation to count highest number up to some number.

The connection between the library and Erathosthenes Sieve function is located in 'primes.c'. Note that for running the 'primes.c' with such high number with static memory you'll need to increase the size of stack.

## Preprocessor-like Comment Removal

The preprocessor-like comment removal is implemented in 'no-comment.c'. It should properly detect comments from input file and replace them with spaces.

## Makefile

Makefile contains methods for compilation of all parts of project alongside other functions.

### make - compiles all .c files

### make primes - compiles primes.c with macro functions from library

### make primes-i - compiles primes.c with inline functions from library

### make no-comment - compiles no-comment.c

### make run - compiles primes.c with both version of functions from library and runs them with same input to compare speed

### make zip - zips the important parts of project

### make clean - deletes all temporary files

# Technologies

## C Programming Language

## Makefile

## gcc - [Download](https://gcc.gnu.org/)
