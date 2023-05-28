#include <unistd.h>
#include "main.h"

/**
 * _putchar - prints a character (char)
 * @c: character to be printed
 * Return: number of characters to be printed
 */

int _putchar(int c)
{
	return(write(1, &c, 1));
}
