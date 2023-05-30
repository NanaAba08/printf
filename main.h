#ifndef MAIN_H_
#define MAIN_H_

#include "printflm.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* For Flags */
#define F_MINUS 1 /* flag representing '-' flag */
#define F_PLUS 2 /* flag representing '+' flag */
#define F_ZERO 4 /* flag representing '0' flag */
#define F_HARSH 8 /* flag representing '#' flag */
#define F_SPACE 16 /*flag representing ' ' flag */

/* For sizes */
#define S_LONG 1
#define S_SHORT 2

int _printf(const char *format, ...);
int _putchar(int chr);
int print_string(const char *str);
int printBinary(unsigned int num);
int con_binary(va_list liz);

#endif
