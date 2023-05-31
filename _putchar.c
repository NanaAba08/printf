#include <unistd.h>
#include "main.h"

/**
 * _putchar - prints a character (char)
 * @chr: character to be printed
 * Return: 1 (success) otherwise -1
 */

int _putchar(int chr)
{
	return (write(1, &chr, 1));
}
