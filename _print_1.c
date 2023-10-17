#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

/**
 *_printf - Prints formatted output to the standard output.
 *@format: The format string specifying the output format.
 *
 *Return: print value
 */

int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					{
						char c = (char)va_arg(args, int);

						printed_chars += _putchar(c);
						break;
					}
				case 's':
					{
						char *str = va_arg(args, char *);

						printed_chars += _puts(str);
						break;
					}
				case '%':
					{
						printed_chars += _putchar('%');
						break;
					}
				default:
					printed_chars += _putchar('%');
					printed_chars += _putchar(*format);
					break;
			}
		}
		else
			printed_chars += _putchar(*format);
		format++;
	}
	va_end(args);
	return (printed_chars);
}
