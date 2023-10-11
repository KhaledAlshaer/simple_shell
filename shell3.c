#include "main.h"

/**
 * main- entry point
 * Return: Nothing
*/

int main(void)
{
	pid_t fork_pid;
	char *buffer = NULL;
	size_t n = 0;
	int len;

	while (1)
	{
		printf(":) ");

		len = getline(&buffer, &n, stdin);

		if (len == -1)
			_perror("Error getline!", buffer);

		if (buffer[len - 1] == '\n')
			buffer[len - 1] = '\0';

		if (_strcmp(buffer, "exit") == 0)
			break;
		else if (_strcmp(buffer, "env") == 0)
			_env();

		fork_pid = fork();
		if (fork_pid == -1)
			_perror("Error fork!", buffer);


		if (fork_pid == 0)
		{
			child3(buffer);
		}
		else
		{
			wait(NULL);
		}
	}
	free(buffer);
	return (0);
}
