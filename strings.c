#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: number of printed char
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - write all char from string to stdout
 * @str: string to print
 * @ascii: enable ascii restriction
 * Return: number of printed char
 */

int _puts(char *str, int ascii)
{
	char *s;
	int i = 0, sum = 0;

	while (str[i])
	{
		if (((str[i] >= 0 && str[i] < 32) || str[i] >= 127) && ascii)
		{
			s = convert_base(str[i], 16, 1);
			sum += write(1, "\\x", 2);
			if (str[i] >= 0 && str[i] < 16)
				sum += _putchar('0');
			sum += _puts(s, 0);
			free(s);
			i++;
		}
		else
		{
			sum += _putchar(str[i]);
			i++;
		}
	}
	return (sum);
}

/**
 * _strlen_recursion - return the length of a string
 *
 * @s: char pointer
 *
 * Return: the length of a string
 */
int _strlen_recursion(char *s)
{
	if (*s != '\0')
	{
		return (_strlen_recursion(s + 1) + 1);
	}
	else
	{
		return (0);
	}
}

/**
 * _strdup - a pointer to a newly allocated space in memory,
 *           which contains a copy of the string given as a parameter.
 *
 * @str: char pointer to copy
 *
 * Return: a new char pointer
 */
char *_strdup(char *str)
{
	char *s;
	int cLoop;

	if (str == NULL)
	{
		return (NULL);
	}

	s = malloc(sizeof(char) * (_strlen_recursion(str) + 1));

	if (s == NULL)
	{
		return (NULL);
	}

	for (cLoop = 0; cLoop < _strlen_recursion(str) + 1; cLoop++)
	{
		s[cLoop] = str[cLoop];
	}

	return (s);
}
