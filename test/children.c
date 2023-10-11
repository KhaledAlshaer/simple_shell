#include "main.h"

/**
 * child- child process for shell3.c
 * @buffer: the getline buffer
 * Return: Nothing
*/

void child(char *buffer)
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
