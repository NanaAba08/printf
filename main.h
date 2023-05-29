#ifndef MAIN_H_
#define MAIN_H_

#include "printflm.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

<<<<<<< HEAD
int _printf(const char *format, ...);
int _putchar(int chr);
int print_string(const char *str);
=======
/* prints output according to format */
int_printf(const char *format, ...);
void print_buffer(char *buffer, int *buff_ind);
int _putchar (char c);
int handle_print(const char *format, int *j, va_list list, char *buffer
int flags, int width, int precision, int size);
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
	int hash;
} flags_tm;


/**
  * struct print_handle - Entry point
  * Description - aid in selecting the right function according to the
  * format specifier passed to the _printf function
  * @c: format specifier
  * @f: pointer to the printing function
  */
typedef struct print_handle
{
	char c;
	int (*f)(va_list ap, flags_tm *f);
} ph;



int _printf(const char *format, ...);
int (*get_func(const char id))(va_list);
int _putchar(char j)
>>>>>>> 9bf5e6d66e69d5d72850ac74d324478a4bc1df73

#endif
