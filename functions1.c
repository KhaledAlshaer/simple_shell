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
	{
		perror("Fork _exec Error!");
	}
	else if (pid == 0)
	{
		if (execve(str[0], str, NULL) == -1)
			perror("Execute Error!");

		exit(1);
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
	pid_t pid = fork();
	char *path, *current_path, *temp;
	const char *env_key = "PATH";
	int found = 0;

	if (pid == -1)
	{
		perror("Fork _path_exec Error");
		exit(1);
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
				{
					perror("./shell");
					exit(1);
				}
				found = 1;
				break;
			}
			current_path = strtok(NULL, ":");
			free(temp);
		}
		if (!found)
		{
			_perror(args[0], NULL);
			exit(1);
		}
	}
	else
		wait(NULL);
}

/**
 * _perror- perror implementation
 * @err_msg: error message
 * @free_me: buffer to free
*/

void _perror(char *command, char *free_me)
{
	if (isatty(STDIN_FILENO))
	{
		_puts("./hsh: ");
		_puts(command);
		_puts(": not found\n");
	}
	else
	{
		write(STDERR_FILENO, "./hsh: 1: ", 11);
		write(STDERR_FILENO, command, _strlen(command));
		write(STDERR_FILENO, ": not found\n", 12);
	}

	if (free_me)
		free(free_me);
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
