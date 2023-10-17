#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
/**
 * _printf - Prints formatted output to the standard output.
 * @format: The format string specifying the output format.
 *
 * Return: 0
 */
int _putchar(char c);
int _puts(const char *str);

int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++; /*Move past the '%'*/

			/*Handle the conversion specifier*/
			switch (*format)
			{
			case 'c':
			{
				/*Print a character*/

				char c = (char)va_arg(args, int);
				/*commit*/
				printed_chars += _putchar(c);
				break;
			}
			case 's':
			{
				/*Print a string*/
				char *str = va_arg(args, char *);
				/*commit*/
				printed_chars += _puts(str);
				break;
			}
			case 'd':
			case 'i':
			{
				/*Print a signed decimal integer*/
				int num = va_arg(args, int);
				char buffer[20];
				int t = 0, s;

				if (num < 0)
				{
					printed_chars += _putchar('-');
					num = -num;
				}

				if (num == 0)
				{
					printed_chars += _putchar('0');
				}
				else
				{
					while (num != 0)
					{
						buffer[t++] = num % 10 + '0';
						num /= 10;
					}

					for (s = t - 1; s >= 0; s--)
					{
						printed_chars += _putchar(buffer[s]);
					}
				}

				break;
			}
			case '%':
			{
				/*Print a percent sign*/
				printed_chars += _putchar('%');
				break;
			}
			default:
				/*Invalid conversion specifier, ignore and continue*/
				printed_chars += _putchar('%');
				printed_chars += _putchar(*format);
				break;
			}
		}
		else
		{
			/*Regular character, print as-is*/
			printed_chars += _putchar(*format);
		}

		format++;
	}

	va_end(args);

	return (printed_chars);
}
/**
 * _putchar - Prints a character to the standard output.
 * @c: The character to be printed.
 *
 * Retuen: 1.
 */
int _putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
/**
 * _puts - Prints a string to the standard output.
 * @str: The string to be printed.
 *
 * Return: print char
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
