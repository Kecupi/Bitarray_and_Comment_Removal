#ifndef ERR_LIB_H
#define ERR_LIB_H
#include <stdarg.h>

void warning(const char *fmt, ...);
void error_exit(const char *fmt, ...);

#endif