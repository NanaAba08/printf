#include <unistd.h>
#include "main.h"

/**
 * _putchar - prints a character (char)
 * @chr: character to be printed
 * Return: number of characters to be printed
 */

int _putchar(int chr)
{
	return(write(1, &chr, 1));
}
