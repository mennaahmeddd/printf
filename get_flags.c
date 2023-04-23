#include "main.h"

/**
 * get_flags - it finds the flag func
 * @format: the format string
 * @a: it takes a paramater
 *
 * Return: flag
 */
int get_flags(char *format, int *a)
{
	int i = 0;

	switch (*format)
	{
		case '+':
			i = a->plus_flag = 1;
			break;
		case ' ':
			i = a->space_flag = 1;
			break;
		case '#':
			i = a->hashtag_flag = 1;
			break;
		case '-':
			i = a->minus_flag = 1;
			break;
		case '0':
			i = a->zero_flag = 1;
			break;
	}
	return (i);
}
