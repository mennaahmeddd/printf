#include "main.h"

/**
 * get_precision - It gets the precision from the format string
 *@p: The format string
 *@params: The parameters struct
 *@list: The argument pointer
 *Return: New pointer
 */

char *get_precision(char *p, params_t *params, va_list list)
{
	int m = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		m = va_arg(list, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			m = m * 10 + (*p++ - '0');
	}
	params->precision = m;
	return (p);
}
