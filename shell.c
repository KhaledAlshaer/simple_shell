#include "main.h"

/**
 * main- entry point
 * Return: Nothing
*/

int main(void)
{
	pid_t fork_pid;
	char *buffer = NULL, **str;
	size_t n = 0;
	int len;

	while (1)
	{
		write(1, "#cisfun$ ", 9);

		len = getline(&buffer, &n, stdin);

		if (len == -1)
			_perror("Error getline!", buffer);

		if (buffer[len - 1] == '\n')
			buffer[len - 1] = '\0';

		if (_strcmp(buffer, "exit") == 0)
			break;
		else if (_strcmp(buffer, "env") == 0)
			_env();

		str = _split(buffer);

		if (access(*str[0], F_OK) == 0)
			if (access(*str[0], X_OK) == 0)
				_exec(str);
		else if (path(str[0]) == 0)
		{
			_exec(str);
		}
	}
	free(buffer);
	return (0);
}
