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
		els {
			format++;
			if (*format == 'a' || *format == "b")
			{
				intvalue = va_ard(arga, int);
				printf("%a", value);
			}
		}
	}
	va_end(args)
}
