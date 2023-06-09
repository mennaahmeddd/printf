#include "main.h"

/**
 * print_from_to - Prints a range of char addresses
 *@start: The starting address
 *@stop: The stopping address
 *@except: The except address
 *Return: A number bytes printed
 */

int print_from_to(char *start, char *stop, char *except)
{
	int sum = 0;

	while (start <= stop)
	{
		if (start != except)
			sum += _putchar(*start);
		start++;
	}
	return (sum);
}

/**
 * print_rev - Prints string in reverse
 *@list: String
 *@params: The parameters struct
 *Return: The number bytes printed
 */

int print_rev(va_list list, params_t *params)
{
	int len, sum = 0;
	char *str = va_arg(list, char *);
	(void)params;

	if (str)
	{
		for (len = 0; *str; str++)
			len++;
		str--;
		for (; len > 0; len--, str--)
			sum += _putchar(*str);
	}
	return (sum);
}

/**
 * print_rot13 - Prints string in rot13
 *@list: String
 *@params: The parameters struct
 *Return: A number bytes printed
 */

int print_rot13(va_list list, params_t *params)
{
	int i, index;
	int count = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(list, char *);
	(void)params;

	i = 0;
	index = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')
		    || (a[i] >= 'a' && a[i] <= 'z'))
		{
			index = a[i] - 65;
			count += _putchar(arr[index]);
		}
		else
			count += _putchar(a[i]);
		i++;
	}
	return (count);
}
