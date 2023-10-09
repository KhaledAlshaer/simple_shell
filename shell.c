#include "main.h"

/**
 *main: this is a function
 *Return: return 0
 */
int main(void)
{
	pid_t pid;
	size_t n = 0, i = 0;
	char *buffer = NULL, *str, *str2[1024];
	int count = 0;

	while (1)
	{
		printf("#cisfun$ ");
		count = getline(&buffer, &n, stdin);
		if (count == -1)
		{
			_perror("getline Error", buffer);
		}

		if ((buffer[count - 1]) == '\n')
		{
			(buffer[count - 1]) = '\0';
		}
		pid = fork();
		if (pid == -1)
		{
			_perror("fork Error", buffer);
		}
		else if (pid == 0)
		{
			str = strtok(buffer, " ");
			while (str)
			{
				str2[i++] = str;
				str = strtok(NULL, " ");
			}

			if (execve(str2[0], str2, NULL) == -1)
			{
				_perror("./shell", buffer);
			}
		}
		else
		{
			wait(NULL);
		}
	}

	free(buffer);
	return (0);
}
