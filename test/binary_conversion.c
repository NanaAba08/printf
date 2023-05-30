#include "main.h"
#include <stdio.h>

/**
  * printBinary - Function that converts integers to binary
  * @num: integer to convert
  * Return: Number of binary characters
  */

int printBinary(unsigned int num)
{
	if (num > 1)
	{
		printBinary(num / 2);
	}
	printf("%d", num % 2);
}

/**
  * con_binary - prints a binary number
  * @...: binary numbers to print
  * @liz: arguments passed to the function
  * Return: The number of binary characters to be printed
  */
int con_binary(va_list liz)
{
	va_list liz;

	va_start(liz, format);

	int charsPrinted = 0;
	const char *p = format;

	while (*p != '\0')
	{
		if (*p == '%')
		{
			p++;
			if (*p == 'b')
			{
				unsigned int num = va_arg(liz, unsigned int);

				printBinary(num);
				charsPrinted += sizeof(unsigned int) * 8;
			}
			else
			{
				_putchar('%');
				_putchar(*p);
				charsPrinted += 2;
			}
		}
		else
		{
			putchar(*p);
			charsPrinted++;
		}
		p++;
	}
	va_end(liz);
	return (charsPrinted);
}
