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