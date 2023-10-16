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
 * _free_args- fre array of strings
 * @args: arr of strings
*/

void _free_args(char **args)
{
	int i;

	for (i = 0; args[i]; i++)
		free(args[i]);

	free(args);
}

/**
 * _eof_handle- handling ctrl+d and eof
 * @len: the res of getline
 * @buf: the buffer of getline
*/

void _eof_handle(int len, char *buf)
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
