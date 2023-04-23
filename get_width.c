#include "main.h"

/**
 * get_width - it gets the width from the format string
 * @format: the format string
 * @a: it takes a parameter
 * @list: the argument pointer
 *
 * Return: width
 */
int get_width(char *a, int *format, va_list list)
{
	int i = 0;

	if (*a == '*')
	{
		i = va_arg(list, int);
		a++;
	}
	else
	{
		while (_isdigit(*a))
			i = i * 10 + (*a++ - '0');
	}
	format->width = i;
	return (a);
}
