#include "main.h"

/**
 * main- this is a function
 * Return: return 0
*/
int main(void)
{
	pid_t pid;
	size_t n = 0;
	char *buffer = NULL;
	int count = 0;

	while (1)
	{
		printf("#cisfun$ ");
		count = getline(&buffer, &n, stdin);
		if (count == -1)
			_perror("getline Error", buffer);

		if ((buffer[count - 1]) == '\n')
			(buffer[count - 1]) = '\0';

		pid = fork();
		if (pid == -1)
			_perror("fork Error", buffer);

		else if (pid == 0)
		{
			child0(buffer);
		}
		else
			wait(NULL);
	}

	free(buffer);
	return (0);
}
