#include "main.h"

/**
 * _getline- getline implement
 * @buf: the buffer
 * @n: the lenght
 * @stream: the stream to read from
 * Return: len for success, -1 for failure
*/

ssize_t _getline(char **buf, int *n, FILE *stream)
{
	char c, *line, *new_line __attribute__((unused));
	int len, i = 0;
	ssize_t bytes_read;

	if (!buf || !n)
		return (-1);

	if (*buf == NULL || *n == 0)
	{
		len = DEF_BUF_SIZE;
		line = malloc(sizeof(char) * DEF_BUF_SIZE);
		if (line == NULL)
			return (-1);
	}
	else
	{
		line = *buf;
		len = *n;
	}

	while (1)
	{
		bytes_read = read(fileno(stream), &c, 1);

		if (c == '\n' || bytes_read == 0)
		{
			line[0] = '\0';
			*buf = line;
			*n = len;
			return (i);
		}

		if (bytes_read == -1)
		{
			free(line);
			return (-1);
		}

		line[i++] = c;

		if (i == len)
		{
			new_line = realloc(line, sizeof(char) * (len * 2));
			if (new_line == NULL)
			{
				free(line);
				return (-1);
			}
		}
	}
}

/**
 *_strtok - This is the function
 *@str: this is a variable
 *@delim: this is a variable
 *Return: returns 0
*/

char *_strtok(char *str, char *delim)
{
	static char *current_position = NULL;
	char *val = NULL;

	if (str != NULL)
	{
		current_position = str;
		val = NULL;
	}
	else if (current_position == NULL || *current_position == '\0')
	{
		return (NULL);
	}

	while (*current_position)
	{
		if (strchr(delim, *current_position) != NULL)
		{
			*current_position = '\0';
			current_position++;
			return (val);
		}
		else
		{
			if (val == NULL)
			{
				val = current_position;
			}
		}

		current_position++;
	}

	 return (val);
}
