#include <stdarg.h>
#include "main.h"

/**
 * printc - print character (Entry point)
 * @list: variable va_list
 * Return: 1 (number of bytes)
 */
int printc(va_list list)
{
	_putchar(va_arg(list, int));
	return (1);
}


/**
 * print_string - print string
 * @s: variable va_list
 * Return: m and 8
 */
int print_string(va_list s)
{
	char *str;
	int m;

	str = va_arg(s, char*);
	if (str == NULL)
	{
		write(1, "(null)", 8);
		return (8);
	}
	else
	{
		for (m = 0; str[m] != '\0'; m++)
		{
			_putchar(str[m]);
		}
	}
	return (m);
}


/**
 * print_n - print number
 * @n: Variable va_list
 * Return: count (number of bytes)
 */
int print_n(va_list n)
{
	long int number;
	int counter, aux_variable, base;

	counter = 0;
	number = va_arg(n, int);

	if (number < 0)
	{
		number *= -1;
		_putchar(45);
		counter++;
	}
	if (number >= 0 && number <= 9)
	{
		_putchar(number + 48);
		counter++;
	}
	if (number > 9)
	{
		base = 10;

		while (number / base > 9)
		{
			base *= 10;
		}

		while (base > 0)
		{
			aux_variable = number / base;
			number = number % base;
			_putchar(aux_variable + 48);
			base = base / 10;
			counter++;
		}
	}
	return (counter);
}

