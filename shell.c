#include "main.h"

/**
 * main- entry point
 * Return: 0 when exit
*/

int main(void)
{
	char *buffer = NULL, **args;
	size_t n = 0, len, status = 0;

	while (1)
	{
		_is_interactive();

		len = getline(&buffer, &n, stdin);

		_eof_handle(len, buffer);

		comments(buffer);

		if (len > 0 && buffer[len - 1] == '\n')
			buffer[len - 1] = '\0';

		args = _split(buffer, " \t");

		if (args && args[0])
		{
			if (_strcmp(args[0], "exit") == 1)
			{
				if (args[1] != NULL)
					status = _atoi(args[1]);

				free(buffer);
				_free_args(args);
				_exitt(status);
			}
			else if (_strcmp(args[0], "env") == 1)
				_env();
			else if (access(args[0], F_OK) == 0 && access(args[0], X_OK) == 0)
				_exec(args);
			else
				_path_then_exec(args);
		}

		_free_args(args);
	}

	free(buffer);
	return (0);
}
