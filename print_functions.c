#include "main.h"

/**
 * print_char - Prints character
 *@list: The argument pointer
 *@params: The parameters struct
 *Return: A number chars printed
 */

int print_char(va_list list, params_t *params)
{
	char pad_char = ' ';
	unsigned int pad = 1, sum = 0, ch = va_arg(list, int);

	if (params->minus_flag)
		sum += _putchar(ch);
	while (pad++ < params->width)
		sum += _putchar(pad_char);
	if (!params->minus_flag)
		sum += _putchar(ch);
	return (sum);
}

/**
 * print_int - Prints integer
 *@list: The argument pointer
 *@params: The parameters struct
 *Return: A number chars printed
 */

int print_int(va_list list, params_t *params)
{
	long l;

	if (params->l_modifier)
		l = va_arg(list, long);
	else if (params->h_modifier)
		l = (short int)va_arg(list, int);
	else
		l = (int)va_arg(list, int);
	return (print_number(convert(l, 10, 0, params), params));
}

/**
 * print_string - Prints string
 *@list: The argument pointer
 *@params: The parameters struct
 *Return: A number chars printed
 */

int print_string(va_list list, params_t *params)
{
	char *str = va_arg(list, char *), pad_char = ' ';
	unsigned int pad = 0, sum = 0, i = 0, y;

	(void)params;
	switch ((int)(!str))
		case 1:
			str = NULL_STRING;

	y = pad = _strlen(str);
	if (params->precision < pad)
		y = pad = params->precision;

	if (params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	while (y++ < params->width)
		sum += _putchar(pad_char);
	if (!params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	return (sum);
}

/**
 * print_percent - Prints string
 *@list: The argument pointer
 *@params: The parameters struct
 *Return: A number chars printed
 */

int print_percent(va_list list, params_t *params)
{
	(void)list;
	(void)params;
	return (_putchar('%'));
}

/**
 * print_S - Custom format specifier
 *@list: The argument pointer
 *@params: The parameters struct
 *Return: A number chars printed
 */

int print_S(va_list list, params_t *params)
{
	char *str = va_arg(list, char *);
	char *hex;
	int sum = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = convert(*str, 16, 0, params);
			if (!hex[1])
				sum += _putchar('0');
			sum += _puts(hex);
		}
		else
		{
			sum += _putchar(*str);
		}
	}
	return (sum);
}
