#include "main.h"

/**
 *_exec - This is the function
 *@str: this is a variable
 *Return: returns 0
*/
void _exec(char **str)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
		perror("fork Error");
	else if (pid == 0)
	{
		if (execve(str[0], str, NULL) == -1)
			perror("./shell");
	}
	else
	{
		wait(NULL);
	}
}
