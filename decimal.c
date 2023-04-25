#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */

int main(void)
{
	double num = 3.14159265358979323846;

/* printing with default precision */
	printf("%f\n", num);   /* prints  "3.141593" */

/* printing with two digits after the decimal point */
	printf("%.2f\n", num);   /* prints  "3.14" */

/* printing with five digits after the decimal point */
	printf("%.5f\n", num);   /* prints  "3.14159" */

/* printing with precision greater than the number */
/* of digits after the decimal point */
	printf("%.10f\n", num);   /* prints  "3.1415926536" */

	return (0);
}
