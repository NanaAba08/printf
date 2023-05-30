#include "main.h"
/**
 * get_flags - gives total of active flags
 * @format: the string in which arguments will be printed
 * @i: parameter
 * Return: flags
 */

int get_flags(const char *format, int *i)

{
	/* - + # 0 ' ' */
	/* 1 2 4 8 16 */
	int b, curr_i;
	int flags = 0;
const char FLAGS_CH[] = {'-', '+', '#', '0', '', '\0'};
const int FLAGS_ARR[] = {F _MINUS, F _PLUS, F _HASH, F _ZERO, F _SPACE, 0};

for (curr_i = *i + 1; format[curr_i] != '\0'; curr + i++)
{
	for (j = 0; FLAGS_CH[j] != '\0'; j++)
		if (format[curr_i] == FLAGS_CH[j])
		{
			flags |= FLAGS_ARR[j];
			break;
		}
	if (FLAGS_CH[j] == 0)
		break;
}
*i = curr_i - 1;
return (flags);
}
