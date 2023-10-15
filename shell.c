#include "main.h"

/**
 * main- entry point
 * Return: Nothing
*/

int main(void)
{
	char *buffer = NULL, **args;
	size_t n = 0;
	int len;

	while (1)
	{
		_is_interactive();

		len = getline(&buffer, &n, stdin);
		
		eof_handle(len, buffer);
		
		if (len > 0 && buffer[len - 1] == '\n')
			buffer[len - 1] = '\0';

		args = _split(buffer, " \t");

		if (args && args[0])
		{
			if (_strcmp(args[0], "exit") == 1)
				break;
			else if (_strcmp(args[0], "env") == 1)
				_env();

			if (access(args[0], F_OK) == 0 && access(args[0], X_OK) == 0)
				_exec(args);
			else
				_path_then_exec(args);
		}

		free_args(args);
	}

	free(buffer);
	return (0);
}
