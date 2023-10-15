#include "main.h"

/**
 * _strcmp- compare two strings
 * @str1: the first string
 * @str2: the second string
 * Return: 0 true, -1 false
*/

int _strcmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (0);

		str1++;
		str2++;
	}

	return (*str1 == *str2);
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

	if (!str)
		return (NULL);

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

	str = strtok(buffer, delim);
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
		str = strtok(NULL, delim);
	}

	res[i] = NULL;
	return (res);
}

/**
 * _realloc- realloc built-in
 * @buf: the old buffer
 * @new_len: the new length
 * Return: new_buf for success, NULL failure
*/

void *_realloc(char *buf, int new_size, int old_size)
{
	char *new, *old;
	int i;

	if (buf == NULL)
		return (malloc(new_size));

	if (new_size == old_size)
		return (buf);

	if (buf != NULL && new_size == 0)
	{
		free(buf);
		return (NULL);
	}

	new = malloc(new_size);
	old = buf;

	if (new == NULL)
		return (NULL);

	if (new_size < old_size)
	{
		for (i = 0; i < new_size; i++)
			new[i] = old[i];
		free(buf);
	}
	else if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
			new[i] = old[i];
		
		free(buf);

		for (i = old_size; i < new_size; i++)
			new[i] = '\0';
	}

	return (new);
}
