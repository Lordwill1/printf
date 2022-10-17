#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * print_unsigned_number - print unsigned number
 * @n: unsigned int to print
 * Return: number of printed chars
 */

int print_unsigned_number(unsigned int n)
{
	int count = 0;
	unsigned int nb = n;

	if (nb <= 9)
	{
		_putchar(nb + '0');
		return (1);
	}
	if (nb > 9)
	{
		count = print_unsigned_number(nb / 10) + 1;
		_putchar(nb % 10 + '0');
		return (count);
	}
	return (0);
}

/**
 * print_number - display the number contained in an int
 * @n: int to print
 * Return: number of char
 */
int print_number(int n)
{
	unsigned int nb;
	int count = 0;

	nb = n;
	if (n < 0)
	{
		_putchar('-');
		count++;
		nb = -nb;
	}
	if (nb <= 9)
	{
		count += _putchar(nb + '0');
		return (count);
	}
	if (nb > 9)
	{
		count += print_number(nb / 10) + 1;
		_putchar(nb % 10 + '0');
		return (count);
	}
	return (0);
}
/**
 * _nbr_len - length of a number
 * @prmNumber: number
 * Return: length of the number
 */

int _nbr_len(int prmNumber)
{
	int cLoop = 0, number;

	if (prmNumber == 0)
		return (1);

	number = prmNumber;

	if (number < 0)
	{
		number *= -1;
		cLoop++;	/* for the sign char */
	}

	while (number)
	{
		number /= 10;
		cLoop++;
	}

	return (cLoop);
}

/**
 * _itoa - Convert an int to a string
 * @prmNumber: int to convert
 * Return: converted string
 */

char *_itoa(int prmNumber)
{
	char *s;
	int cLoop;
	long number;

	number = prmNumber;
	cLoop = _nbr_len(number);
	s = malloc(sizeof(char) * cLoop + 1);

	if (s == NULL)
	{
		return (NULL);
	}

	s[cLoop] = '\0';

	if (number == 0)
	{
		s = "0";
	}
	else if (number < 0)
	{
		s[0] = '-';
		number *= -1;
	}

	while (number)
	{
		s[--cLoop] = number % 10 + 48;
		number /= 10;
	}

	return (s);
}
