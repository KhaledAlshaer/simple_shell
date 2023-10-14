#include "main.h"

/**
 * _getline_syscall- getline implement
 * @buf: the buffer
 * @n: the lenght
 * @stream: the stream to read from
 * Return: len for success, -1 for failure
*/

ssize_t _getline_syscall(char **buf, int *n, FILE *stream)
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
		bytes_read = read(stream, &c, 1);

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
			if (_realloc(&line, sizeof(char) * (len * 2)) == -1)
				free(line), return (-1);
		}
	}
}
