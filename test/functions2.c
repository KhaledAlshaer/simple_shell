#include "main.h"

/**
 * _is_interactive- check to print prompt or not
 * Return: Nothing
*/

void _is_interactive(void)
{
	if (isatty(STDIN_FILENO))
		_puts("#cisfun$ ");
}

/**
 * _getline- getline high level
 * @buffer: the buffer to fill
 * @n: the length of chars filled
 * Return: the len for success, 0 failure
*/

int _getline(char **buffer, size_t *n, FILE *stream)
{
	int len = getline(buffer, n, stream);

	if (len == -1)
	{
		perror("Error getline!");
		return (len);
	}

	if ((*buffer)[len - 1] == '\n')
		(*buffer)[len - 1] = '\0';

	return (len);
}
