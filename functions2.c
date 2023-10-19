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
 * _perr_free2d_exit1-print err, free arrya of str and exit(1)
 * @err_msg: the error message
 * @free_me: the array of str
 * Return: Nothing
*/
char **_perr_free2d_exit1(char *err_msg, char **free_me)
{
	perror(err_msg);
	_free_args(free_me);
	return (NULL);
}

/**
 * _eof_handle- handling ctrl+d and eof
 * @len: the res of getline
 * @buf: the buffer of getline
*/

void _eof_handle(char *buf, int len)
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

/**
 * _exitt- advanced exit implement
 * @status: the exit status
 * Return: Nothing
*/

void _exitt(int status)
{
	if (status)
		exit(status);

	exit(0);
}
