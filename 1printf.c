#include "main.h"
#include "printflm.h"
#include <stdio.h>
#include <stdarg.h>

/**
  * _printf - Prints according to a format
  * @...: The number of output
  * @format: A pointer
  * Return: Output according to a format
  */

int _printf(const char *format, ...)
{
	va_list mag;
	int count = 0;

	va_start(mag, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					count += _putchar(va_arg(mag, int));
					break;
				case 's':
					count += print_string(va_arg(mag, const char *));
					break;
				case '%':
					count += _putchar('%');
					break;
				default:
					_putchar('%');
					_putchar(*format);
					count += 2;
					break;
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	return (count);
	va_end(mag);
}

/**
  * print_string - Prints string
  * @str: string to be printed
  * Return: Number of strints printed
  */

int print_string(const char *str)
{
	int count = 0;

	while (*str)
	{
		_putchar(*str);
		count++;
		str++;
	}
	return (count);
}
