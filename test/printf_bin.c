#include "main.h"
#include <stdio.h>

/***************** FUNCTION THAT PRINTS A CHARACTER ******************/

/**
 * print_char - Print a character as output of a format
 * @types: List a of arguments
 * @buffer: prints a buffer array
 * @flags:  Finds the active flags
 * @width: Determine width
 * @precision: Specifies precision
 * @size: Specifies the size
 * Return: Number of characters
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char g = va_arg(types, int);

	return (handle_write_char(g, buffer, flags, width, precision, size));
}
/**************** FUNCTION THAT PRINTS A STRING ********************/
/**
 * print_string - Printing a string
 * @types: List a of arguments args
 * @buffer: Prints a Buffer array to handle print
 * @flags:  Finds the active flags
 * @width: Determine width.
 * @precision: Specifies the precision
 * @size: Specifies the size
 * Return: Number of characters
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int len = 0, g;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "     ";
	}
	while (str[len] != '\0')
		len++;
	if (precision >= 0 && precision < len)
		len = precision;

	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(len, &str[0], 1);

			for (g = width - len; g > 0; g--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (g = width - len; g > 0; g--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (width);
		}
	}
	return (write(1, str, len));
}
/****************** FUNCTION TO PRINT PERCENT SIGN ******************/
/**
 * print_percent - Prints a percentage sign
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Finds active flags
 * @width: Determines width.
 * @precision: Specifies Precision
 * @size: Specifies size
 * Return: Number of characters
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/************************* FUNCTION TO PRINT INTEGER *************************/
/**
 * print_integers - Prints integers of an output to a format
 * @types: List arguments
 * @buffer: Buffer array to handle print
 * @flags: Finds active flags
 * @width: Determines width
 * @precision: Specifies Precision
 * @size: Size specified
 * Return: Number of chars printed
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int g = BUFF_SIZE - 2;
	int is_neg = 0;
	long int h = va_arg(types, long int);
	unsigned long int nh;

	h = convert_size_number(h, size);

	if (h == 0)
		buffer[g--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	nh = (unsigned long int)h;

	if (h < 0)
	{
		nh = (unsigned long int)((-1) * h);
		is_neg = 1;
	}
	while (nh > 0)
	{
		buffer[g--] = (nh % 10) + '0';
		nh /= 10;
	}
	g++;

	return (write_number(is_neg, y, buffer, flags, width, precision, size));
}

/************************* FUNCTION TO PRINT BINARY *************************/
/**
 * print_binary - Prints an unsigned number
 * @types: List arguments to a function
 * @buffer: Buffer array to handle print
 * @flags:  Finds active flags
 * @width: Determine width.
 * @precision: Specifies Precision
 * @size: Size specified
 * Return: Numbers of characters printed.
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int x, y, e, sum;
	unsigned int str[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	x = va_arg(types, unsigned int);
	y = 2147483648; /* (2 ^ 31) */
	str[0] = x / y;
	for (e = 1; e < 32; e++)
	{
		y /= 2;
		str[e] = (x / y) % 2;
	}
	for (e = 0, sum = 0, count = 0; e < 32; e++)
	{
		sum += str[e];
		if (sum || e == 31)
		{
			char v = '0' + str[e];

			write(1, &v, 1);
			count++;
		}
	}
	return (count);
}
