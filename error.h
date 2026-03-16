// error.h
// Řešení IJC-DU1, příklad a), 16.3.2026
// Autor: Štěpán Hořenek, FIT
// Přeloženo: gcc 14.2
// ...popis příkladu - poznámky, omezení, atd
#ifndef ERR_LIB_H
#define ERR_LIB_H
#include <stdarg.h>

void warning(const char *fmt, ...);
void error_exit(const char *fmt, ...);

#endif