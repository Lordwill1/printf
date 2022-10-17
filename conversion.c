#include <stdlib.h>
#include "main.h"
/**
 * convert_alpha_numeric - convert digits to char
 * @nb: digit or number
 * @upper: upper case check
 * Return: converted value
 */

int convert_alpha_numeric(int nb, int upper)
{
	if (nb >= 10)
		return (nb - 10 + ((upper) ? 'A' : 'a'));
	else
		return (nb + '0');
}

/**
 * convert_base - convert unsigned from base 10 to base
 * @nb: decimal number
 * @base: base to convert from
 * @upper: upper case check
 * Return: converted number to string
 */

char *convert_base(unsigned long nb, unsigned int base, int upper)
{
	int i = 0;
	char *str;
	unsigned long nbr = nb;

	while (nbr >= base)
	{
		nbr /= base;
		i++;
	}
	str = malloc(sizeof(char) * i + 2);
	if (!str)
		return (0);
	str[i + 1] = '\0';

	while (i >= 0)
	{
		nbr = nb % base;
		str[i] = convert_alpha_numeric(nbr, upper);
		nb /= base;
		i--;
	}
	return (str);
}

/**
 * convert_base_pointer - convert pointer void to ul
 * @p: pointer
 * Return: converted string
 */

char *convert_base_pointer(unsigned long p)
{
	unsigned long adress;
	char *str;

	adress = p;
	if (adress == 0)
		return ("0");
	str = convert_base(adress, 16, 0);
	return (str);
}
/**
 * convert_rot13 - encode using rot13
 * @str: string to encode
 * Return: encoded string
 */

char *convert_rot13(char *str)
{
	int i = 0;
	char *s;
	int size = _strlen_recursion(str);

	s = malloc(sizeof(char) * size + 1);
	if (!s)
		return (0);

	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'm') || (str[i] >= 'A' && str[i] <= 'M'))
			s[i] = str[i] + 13;
		else if ((str[i] >= 'n' && str[i] <= 'z')
				|| (str[i] >= 'N' && str[i] <= 'Z'))
			s[i] = str[i] - 13;
		else
			s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
