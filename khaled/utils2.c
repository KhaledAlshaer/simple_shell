#include "main.h"

/**
 * _strcmp- compare two strings
 * @str1: the first string
 * @str2: the second string
 * Return: 0 true, -1 false
*/

int _strcmp(const char *str1, const char *str2)
{
	int i;

	if (str1 == NULL && str2 == NULL)
	{
		return (0);
	}
    
	if (str1 == NULL || str2 == NULL) {
		return (-1);
	}

	for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
	{
		if (str1[i] != str2[i])
		{
			return (-1);
		}
	}

	if (str1[i] == '\0' && str2[i] == '\0')
	{
		return (0);
	}

	return (-1);
}


/**
 * _strdup- copy string
 * @str: string to copy
 * Return: string result
*/

char *_strdup(char *str)
{
	int len = _strlen(str), i = 0;
	char *res = malloc(sizeof(char) * len);

	if (res == NULL)
		perror("strdup Error!"), exit(1);

	while (str[i])
	{
		res[i] = str[i];
		i++;
	}

	res[i] = '\0';
	return (res);
}

/**
 * _split- SPlitting a string at a delim
 * @buffer: the string
 * @delim: the delimeter
 * Return: Splitted string
*/

char **_split(char *buffer, char *delim)
{
	char **res = NULL, *str;
	int i = 0;

	res = (char **)malloc(sizeof(char *) * 16);
	if (res == NULL)
		perror("Malloc _split Error!"), exit(1);

	str = _strtok(buffer, delim);
	while (str)
	{
		if (i % 16 == 0)
		{
			res = (char **)realloc(res, (i + 16) * sizeof(char *));
			if (res == NULL)
				perror("Realloc _split Error!"), exit(1);
		}

		res[i] = _strdup(str);
		if (res[i] == NULL)
			perror("_split malloc Error!"), exit(1);

		i++;
		str = _strtok(NULL, delim);
	}

	res[i] = NULL;
	return (res);
}
