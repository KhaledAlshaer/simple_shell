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
 * free_args- fre array of strings
 * @args: arr of strings
*/

void free_args(char **args)
{
	int i;

	for (i = 0; args[i]; i++)
		free(args[i]);

	free(args);
}

/**
 * eof_handle- handling ctrl+d and eof
 * @len: the res of getline
 * @buf: the buffer of getline
*/

void eof_handle(int len, char *buf)
{
	(void)buf;
	if (len == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			_puts("\n");
			free(buf);
		}
		exit(0);
	}
}
