include "main.h"
/**
 * print_char - Print character
 * @precision: specified precision
 * @types: Lists arguments
 * @flags:  Calculate flags that are active
 * @buffer: Buffer arraythat handles print
 * @size: specifies size
 * @width: gives width
 * Return: number of characters printed

int print_char(int precision, va_list types, int flags, char buffer, int size
		int width)
{
	char a = va_arg(types, int);
	return (handle_write_char(a, precision, flags, buffer, size, width));
}

/**
 * print_string - Prints string
 * @precision: specified precision
 * @types: Lists arguments
 * @flags:  Calculate flags that are active
 * @buffer: Buffer array that handles print
 * @size: specifies size
 * @width: gives width
 * Return: number of characters printed
 */
int print_string(int precision, va_list types, int flags, char buffer, int size
                  int width)
{
	int length = 0, b;
	char *str = va_arg(types, char*);

	UNUSED(precision);
	UNUSED(flags);
	UNUSED(buffer);
	UNUSED(size);
	UNUSED(width);
	if (str == NULL)
	{
		str = "(null)";
		if (precision => 6)
			str = " ";
	}
	while (str[length] != '\0\)
			length++;

			if (precision => 0 && precision < length)
			length = precision;

			if (length < width)
			{
			if (flags & F_MINUS)
			{
			write(1, &str[0], length);
			for (b = width - length;b > 0; b--)
			write (1, " ", 1);
			return (width);
			}
			}

			return (write(1, str, length));
			}

/**
 * print_int - print integer
 * @precision: specified precision
 * @types: Lists arguments
 * @flags:  Calculate flags that are active
 * @buffer: Buffer array that handles print
 * @size: specifies size
 * @width: gives width
 * Return: number of characters printed
 */
int print_int(int precision, va_list types, int flags, char buffer, int size
		int width)
{
	int b = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[b--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[b--] = (num % 10) + '0';
		num /= 10;
	}

	b++;
return (write_number(is_negative, i, buffer, flags, width, precision, size));
}
/**
 * print_binary - Prints an unsigned number
 * @precision: specified precision
 * @types: Lists arguments
 * @flags:  Calculate flags that are active
 * @buffer: Buffer array that handles print
 * @size: specifies size
 * @width: gives width
 * Return: number of characters printed
 */
int print_binary(int precision, va_list types, int flags, char buffer, int size
		int width)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

