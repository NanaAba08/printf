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

/**
  * struct fmtl - Entry point
  * Description - 'indicates a format specifier'
  * @fmtl: the format specifier
  * @fcn: the function that helps to print
  */

struct fmtl
{
	char fmtl;
	int (*fcn)(va_list, char[], int, int, int, int);
};

/**
  * typedef struct fmtl fmtl_m - struct op
  * @fmtl: The format to print output
  * @fmtl_m: function associated
  */
typedef struct fmtl fmtl_m;

int printf(const char *format, ...);
int handles_print(const char *format, int *ind, va_list list, char buffer[],
int flags, int width, int precision, int size);

/**************PROTOTYPES FOR FUNCTIONS***********************/

/* Functions to use to print characters and strings */
int print_char(va_list types, char buffer[], int flags, int width,
		int precision, int size);
int print_string(va_list types, char buffer[], int flags, int width,
		int precision, int size);
int print_percent(va_list types, char buffer[], int flags, int width,
		int precision, int size);

/* Functions to use to print numbers */
int print_integer(va_list types, char buffer[], int flags, int width,
		int precision, int size);
int print_binary(va_list types, char buffer[], int flags, int width,
		int precision, int size);
int print_unsigned_integer(va_list types, char buffer[], int flags, int width,
		int precision, int size);
int print_octal(va_list types, char buffer[], int flags, int width,
		int precision, int size);
int print_hexadecimal(va_list types, char buffer[], int flags, int width,
		int precision, int size);
int print_hexa_upper(va_list types, char buffer[], int flags, int width,
		int precision, int size);
int print_hexa(va_list types, char map_to[], char buffer[],
		int flags, char flag_ch, int width, int precision, int size);

/* Function to use to print non printable characters */
int print_non_printable(va_list types, char buffer[], int flags, int width,
		int precision, int size);

/* Function to use to print memory address */
int print_pointer(va_list types, char buffer[], int flags, int width,
		int precision, int size);

/* Functions to use to handle other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/* Function to use to print string in reverse */
int print_reverse(va_list types, char buffer[], int flags, int width,
int precision, int size);

/* Function to use to print string in ROT13 */
int print_rot13string(va_list types, char buffer[], int flags, int width,
int precision, int size);

/* Functions to use to handle width */
int handle_write_char(char c, char buffer[], int flags, int width,
int precision, int size);
int write_number(int is_positive, int ind, char buffer[], int flags,
int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width,
int precision, int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length, int width, int flags,
char padd, char extra_c, int padd_start);
int write_unsignd(int is_negative, int ind, char buffer[], int flags,
int width, int precision, int size);

/***************** FUNCTION FOR  UTILITY *********************/

int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);


long int convert_size_number(long int num, int size);
/* converts a number with specified size */
long int convert_size_unsignd(unsigned long int num, int size);
/* converts unsigned number with specified size*/

int _putchar(int chr);
int print_string(const char *str);
int printBinary(unsigned int num);
int con_binary(va_list liz);

#endif
