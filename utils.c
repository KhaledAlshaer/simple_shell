#include "main.h"

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
 * _concat_with_slash- concat two strings
 * @str1: the first string
 * @str2: the second string
 * Return:the concatenated string
*/

char *_concat_with_slash(char *str1, char *str2)
{
	int len = _strlen(str1) + _strlen(str2), i, j;
	char *res = malloc(sizeof(char) * (len + 2));

	for (i = 0; str1[i] != '\0'; i++)
		res[i] = str1[i];

	res[i++] = '/';

	for (j = 0; str2[j] != '\0'; j++, i++)
		res[i] = str2[j];

	res[i] = '\0';

	return (res);
}

/**
 * _strcmp- compare two strings
 * @str1: the first string
 * @str2: the second string
 * Return: 0 true, -1 false
*/

int _strcmp(char *str1, char *str2)
{
	int i, res = 0;

	for (i = 0; str1[i] != '\0'; i++)
	{
		if (str1[i] != str2[i])
			res = -1;
	}

	return (res);
}
