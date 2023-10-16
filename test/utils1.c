#include "main.h"

/**
 * _putchar- putchar implementation
 * @c: the char
 * Return: 1 for success
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts- put string
 * @str: the string
 * Return: number of printed chars
*/

int _puts(char *str)
{
	int count = 0;

	while (*str)
	{
		_putchar(*str);
		str++;
		count++;
	}

	return (count);
}

/**
 * _strlen- length of str
 * @str: the string
 * Return: Nothing
*/

int _strlen(char *str)
{
	int i = 0;

	while (*str)
	{
		i++;
		str++;
	}

	return (i);
}

/**
 * _concat_with_char- concat two strings
 * @str1: the first string
 * @mid_char: the middle char
 * @str2: the second string
 * Return:the concatenated string
*/

char *_concat_with_char(char *str1, char mid_char, char *str2)
{
	int len = _strlen(str1) + _strlen(str2), i, j;
	char *res = malloc(sizeof(char) * (len + 2));

	for (i = 0; str1[i] != '\0'; i++)
		res[i] = str1[i];

	res[i++] = mid_char;

	for (j = 0; str2[j] != '\0'; j++, i++)
		res[i] = str2[j];

	res[i] = '\0';

	return (res);
}
