#ifndef MAIN_H_
#define MAIN_H_

#include "printflm.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _putchar(int chr);
int print_string(const char *str);
int printBinary(unsigned int num);
int con_binary(va_list liz);

#endif
