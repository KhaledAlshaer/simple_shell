#include "main.h"

/**
 * _exec - This is the function
 * @str: this is a variable
 * Return: returns 0
*/

void _exec(char **str)
{
	pid_t pid;

	pid = fork();

	if (pid == -1)
		perror("Fork _exec Error!");
	else if (pid == 0)
	{
		if (execve(str[0], str, NULL) == -1)
			perror("Execute Error!");

		exit(0);
		
	}
	else
	{
		wait(NULL);
	}
}

/**
 * _path_then_exec- find path and exec
 * @args: array of strings
 * Return: Nothing
*/

void _path_then_exec(char **args)
{
	pid_t pid;
	char *path, *current_path, *temp;
	const char *env_key = "PATH";

	pid = fork();

	if (pid == -1)
	{
		perror("Fork _path_exec Error");
		exit(0);
	}
	else if (pid == 0)
	{
		path = getenv(env_key);
		current_path = strtok(path, ":");
		while (current_path)
		{
			temp = _concat_with_char(current_path, '/', args[0]);
			if (access(temp, F_OK) == 0 && access(temp, X_OK) == 0)
			{
				args[0] = temp;
				if (execve(args[0], args, NULL) == -1)
					perror("./shell");

				exit(0);
			}
			current_path = strtok(NULL, ":");
			free(temp);
		}
		perror("./shell");
	}
	else
		wait(NULL);
}

/**
 * _perror- perror implementation
 * @err_msg: error message
 * @free_me: buffer to free
*/

void _perror(char *err_msg, char *free_me)
{
	perror(err_msg);
	free(free_me);
	exit(1);
}

/**
 * _env- print environments
 * Return: Nothing
*/

void _env(void)
{
	char **envs = environ;

	for (; *envs != NULL; envs++)
	{
		_puts(*envs);
		_puts("\n");
	}
}
