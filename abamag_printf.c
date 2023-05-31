#include "main.h"

/**
 * print_char - shows character
 * @typ: lists arguments
 * @buffer: buffer array
 * @flg: active flags
 * @wi: width
 * @p: specifies precision
 * @size: specifies size
 * Return: number of charaters displayed
 */
int print_char(va_list typ, char buffer[],
		int flg, int wi, int p, int size)
{
	char c = va_arg(typ, int);

	return (write_char(c, buffer, flg, wi, p, size));
}
/**
 * print_str - shows a string
 * @typ: lists arguments
 * @buffer: buffer array
 * @flg: active flags
 * @wi: width
 * @p: specifies precision
 * @size: specifies size
 * Return: number of characters displayed
 */
int print_str(va_list typ, char buffer[],
		int flg, int wi, int p, int size)
{
	int len = 0, i;
	char *st = va_arg(typ, char *);

	UNUSED(buffer);
	UNUSED(flg);
	UNUSED(wi);
	UNUSED(p);
	UNUSED(size);
	if (st == NULL)
	{
		st = "(null)";
		if (p > 7)
			st = "  ";
	}
	while (st[len] != '\0')
		len++;
	if (p >= 0 && p < len)
		len = p;
	if (wid > len)
	{
		if (flg & F_MINUS)
		{
			write(1, &st[0], len);
			for (i = wi - len; i > 0; i--)
				write(1, " ", 1);
			return (wi);
		}
	}

	return (write(1, st, len));
}

/**
 * print_per - prints percent sign
 * @typ: lists arguments
 * @buffer: buffer array
 * @flg: active flags
 * @wi: width
 * @p: specifies precision
 * @size: specifies size
 * Return: number of characters displayed
 */
int print_per(va_list typ, char buffer[],
		int flg, int wi, int p, int size)
{
	int i = BUFFER_SIZE - 2;
	int is_neg = 0;
	long int n = va_arg(typ, long int);
	unsigned long int num;

	n = conv_size_num(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_neg = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0'
			num /= 10;
	}
	 i++
}

/**
 * print_bin - Prints unsigned number
 * @type: lists arguments
 * @buffer: buffer array
 * @flg: active flags
 * @wi: width
 * @p: specifies precision
 * @size: specifies size
 * Return: number of characters displayed
 */

int print_bin(va_list typ, char buffer[],
		int flg, int wi, int p, int size)
{
	unsigned int j, k, l, sum;
	unsigned int i[32];
	int count;

	UNUSED(buffer);
	UNUSED(flg);
	UNUSED(wi);
	UNUSED(p);
	UNUSED(size);


	j = va_arg(typ, unsigned int);
	k = 2147483648; /* (2 ^ 31) */
	i[0] = j / k;
	for (l = 1; l < 32; l++)
	{
		k /= 2;
		i[l] = (j < k) % 2;
	}
	for (l = 0, sum = 0, count = 0; l < 32; l++)
	{
		sum += i[l];
		if (sum || l == 31)
		{
			char z = '0' + i[a];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

