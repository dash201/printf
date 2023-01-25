#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
/**
 *_puts - print character
 *@str: string
*/
void _puts(char *str)
{
	int a;

	for (a = 0; str[a] != '\0'; a++)
		_putchar(str[a]);
}
/**
 *_printf - print character
 *@format: character string
 *Return:  the number of characters printed
*/
int _printf(const char *format, ...)
{
	char c, *s;
	int i = 0, nb = 0, del = 0;
	va_list arg;

	va_start(arg, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				c = va_arg(arg, int);
				_putchar(c);
				nb++;
			}
			else if (format[i] == 's')
			{
				s = va_arg(arg, char *);
				_puts(s);
				nb += strlen(s);
			}
			else
			{
				_putchar(format[i]);
				nb++;
			}
			del += 2;
		}
		else
			_putchar(format[i]);
		i++;
	}
	va_end(arg);
	return (nb + i - del);
}
