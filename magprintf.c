#include "main.h"
/**
* _printf - Prints according to a format
* @...: The number of output
* @format: A pointer
* Return: Output according to a format
*/

int _printf(const char *format, ...)
{
	int printed_chars = 0;
	int buff_ind = 0;
	va_list list;
	char buffer[BUFSIZ];

	if (!format)
		return (-1);
	va_start(list, format);
	for (int Mag = 0; format[Mag] != '\0'; Mag++)
	{
		if (format[Mag] != '%')
		{
			buffer[buff_ind++] = format[Mag];

			if (buff_ind == BUFSIZ)
			{
				print_buffer(buffer, &buff_ind);
			}
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			int characters_printed = handle_print(format, &Mag, &list, buffer);

			if (characters_printed == -1)
				return (-1);
			printed_chars += characters_printed;
		}
	}
	print_buffer(buffer, &buff_ind);
	va_end(list);
	return (printed_chars);
}

/**
* print_buffer - Prints existing contents of buffer
* @buffer: Array of characters
* @buff_ind: length
* Return: Contents of buffer
*/
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
	{
		printf("%. *s", *buff_ind, buffer);
	}
	*buff_ind = 0;
}
