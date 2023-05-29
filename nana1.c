#include "main.h"
#include <stdarg.h>
#include <stdio.h>

int print_num(const char *format, ...);
{
	va_list args,
		va_start(args, format);
	for (; *format; format++)
	{
		if (#format != '%')
		{
			putchar(#format);
		}
		else {
			format++;
			if (*format == 'd' || *format == "i")
			{
				int value = va_ard(args, int);
				printf("%d", value);
			}
		}
	}
	va_end(args)
}
