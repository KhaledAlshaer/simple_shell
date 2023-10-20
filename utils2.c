#include "main.h"

/**
 * _strcmp- compare two strings
 * @str1: the first string
 * @str2: the second string
 * Return: 0 true, -1 false
*/

int _strcmp(char *str1, char *str2)
{
	while (*str1 || *str2)
	{
		if (*str1 != *str2)
			return (0);

		str1++;
		str2++;
	}

	return (1);
}

/**
 * _strdup- copy string
 * @str: string to copy
 * Return: string result
*/

char *_strdup(char *str)
{
	int len = _strlen(str), i;
	char *res = malloc(sizeof(char) * (len + 1));

	if (!str)
		return (NULL);

	if (res == NULL)
	{
		perror("strdup Error!");
		return (NULL);
	}

	for (i = 0; str[i]; i++)
		res[i] = str[i];

	res[len] = '\0';
	return (res);
}

/**
 * _strlen_2d- the length of array of strings
 * @str: the array of string
 * Return: the length
*/

int _strlen_2d(char **str)
{
	int i = 0;

	while (str[i] != NULL)
		i++;

	return (i);
}

/**
 * _split- SPlitting a string at a delim
 * @buffer: the string
 * @delim: the delimeter
 * Return: Splitted string
*/

char **_split(char *buffer, char *delim)
{
	char **args = NULL, *str;
	int i = 0, size = 10;

	args = (char **)malloc(sizeof(char *) * size);
	if (args == NULL)
	{
		perror("Malloc _split Error!");
		return (NULL);
	}

	str = strtok(buffer, delim);
	while (str)
	{
		if (i == size)
		{
			args = _realloc(args, size * sizeof(char *), (size + 16) * sizeof(char *));
			if (args == NULL)
				_perr_free2d_exit1("_split _realloc Error!", args);
		}

		args[i] = _strdup(str);
		if (args[i] == NULL)
			_perr_free2d_exit1("_split _strdup Error!", args);
		i++;
		str = strtok(NULL, delim);
	}

	args[i] = NULL;
	return (args);
}

/**
 * _realloc- realloc built-in
 * @ptr: the old buffer
 * @new_size: the new length
 * @old_size: the old length
 * Return: new malloc with new size
*/

void *_realloc(void *ptr, int old_size, int new_size)
{
	int i;
	char *new_ptr;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	if (ptr != NULL && old_size < new_size)
	{
		for (i = 0; i < old_size; i++)
			*((char *)new_ptr + i) = *((char *)ptr + i);
	}

	free(ptr);
	return (new_ptr);
}
