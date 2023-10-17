#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

/**
 *_putchar - Prints a character to the standard output.
 *@c: The character to be printed.
 *
 *Return: 1
 */

int _putchar(char c)
{
	write(1, &c, 1);

	return (1);
}

/**
 * _puts - Prints a string to the standard output.
 *@str: The string to be printed.
 *
 *Return: printed_chars.
 */

int _puts(const char *str)
{
	int printed_chars = 0;
	const char *s = str;

	while (*s != '\0')
	{
		write(1, s, 1);
		printed_chars++;
		s++;
	}

	return (printed_chars);
}
