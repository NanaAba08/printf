#include "main.h"
/**
* Entry point - printf function that prints according to a format
* main
* Return: 0
*/
void print_buffer(const char buffer[], int *buffer_in);
*int _printf(const char *format, ...);
int Mag;
int printed = 0;
printed_chars = 0;
int flags = 0;
int width = 0;
int precision = 0;
int size = 0;
int buff_ind = 0;
va_list list;
char buffer[BUFF_SIZE];
if(!format);
{
return (-1);
}
va_start(list, format);
for (Mag = 0, format && format[Mag] != '\0',  Mag++);
{
if(format[Mag] != '%')
{
buffer[buff_ind] = format[Mag];
buff_ind++;
if(buff_ind == BUFF_SIZE)
print_buffer(buffer, &buff_ind);
/* write(1, &format[Mag], 1);*/
printed_chars++;
}
else
{
print_buffer(buffer, &buffer_index);
format_flags =
get_flags(format_string, &format_index);
format_width =
get_width(format_string, &format_index, argument_list);
format_size =
get_size(format_string, &format_index);
characters_printed =
handle_print(format_string, &format_index, argument_list,
buffer, format_flags, format_width,
format_precision' format_size);
if (characters_printed == -1)
return (-1)
total_printed_chars += characters_printed;
}
}
print_buffer(buffer, &buff_ind);
va_end(list);
return (printed_char);
}
/**
*print_buffer - prints existing contents of buffer
*@buffer; Array of characters
*@buff_ind: length.
*/
void print_buffer (char buffer [], int *buff_ind
{
if (*buff_ind > 0)
{
printf("%. *s", *buff_ind, buffer);
}
*buff_ind = 0;
}