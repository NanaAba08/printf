#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * struct flags - struct that has  flags to "turn on"
 * when a flag specifier is passed to _printf()
 * @plus - flag for '+' char
 * @space - flag for '' char
 * @hash - flag for '#' char
 */
typedef struct flags
{
	int plus;
	int space;
	int harsh;
} flags_tm;


/**
  * struct print_handle - Entry point
  * Description - struct to aid in selecting the right function according to the
  * format specifier passed to the _printf function
  * @c: format specifier
  * @f: pointer to the printing function
  */
typedef struct print_handle
{
	char c;
	int (*f)(va_list ap, flags_tm *f);
} ph;

/* print output according to format */
int _printf(const char *format, ...);
int (*get_func(const char id))(va_list);
int _putchar(int chr);

#endif
