// error.c
// Řešení IJC-DU1, příklad a), 16.3.2026
// Autor: Štěpán Hořenek, FIT
// Přeloženo: gcc 14.2
// ...popis příkladu - poznámky, omezení, atd
#include <stdarg.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "error.h"

void warning(const char* fmt, ...){
    va_list arguments;
    va_start(arguments, fmt);
    fprintf(stderr, "Warning: ");
    vfprintf(stderr, fmt, arguments);
    va_end(arguments);
}
void error_exit(const char* fmt, ...){
    va_list arguments;
    va_start(arguments, fmt);
    fprintf(stderr, "Error: ");
    vfprintf(stderr, fmt, arguments);
    va_end(arguments);
    exit(1);
}