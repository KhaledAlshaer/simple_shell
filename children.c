#include "main.h"

/**
 * child0- child 0 for shell.c
 * @buffer: the buffer
 * Return: Nothing
*/

void child0(char *buffer)
{
	char *str, *str2[1024];
	int i = 0;

	str = strtok(buffer, " ");
	while (str)
	{
		str2[i++] = str;
		str = strtok(NULL, " ");
	}

	if (execve(str2[0], str2, NULL) == -1)
		_perror("./shell", buffer);
}

/**
 * child3- child process for shell3.c
 * @buffer: the getline buffer
 * Return: Nothing
*/

void child3(char *buffer)
{
	char *args[1024], *current_str, *path, *current_path, *first_arg;
	int i = 0;
	const char *env_key = "PATH";

	current_str = strtok(buffer, " \t");
	while (current_str)
	{
		args[i++] = current_str;
		current_str = strtok(NULL, " \t");
	}

	if (access(args[0], F_OK) == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		_perror("./shell", buffer);
	}
	else
	{
		path = getenv(env_key);
		current_path = strtok(path, ":");
		while (current_path)
		{
			first_arg = _concat_with_slash(current_path, args[0]);
			if (access(first_arg, F_OK) == 0)
			{
				args[0] = first_arg;
				if (execve(args[0], args, NULL) == -1)
					_perror("./shell", buffer);
			}
				current_path = strtok(NULL, ":");
				free(first_arg);
		}
		_perror("./shell", buffer);
	}
}
