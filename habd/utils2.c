#include "main.h"


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
	int i = 0, size = 16;

	args = (char **)malloc(sizeof(char *) * size);
	if (args == NULL)
		perror("Malloc _split Error!"), exit(1);

	str = strtok(buffer, delim);
	while (str)
	{
		if (i == size)
		{
			size += 16;
			args = _realloc(args, (size * sizeof(char *)), (i * sizeof(char *)));
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
 * @buf: the old buffer
 * @new_size: the new length
 * @old_size: the old length
 * Return: new malloc with new size
*/

char **_realloc(char **buf, int new_size, int old_size)
{
	char **new, **old;
	int i;

	if (buf == NULL)
		return ((char **)malloc(new_size * sizeof(char *)));

	if (new_size == old_size)
		return (buf);

	if (buf != NULL && new_size == 0)
	{
		free(buf);
		return (NULL);
	}

	new = (char **)malloc(new_size * sizeof(char));
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
			new[i] = NULL;
	}

	return (new);
}
