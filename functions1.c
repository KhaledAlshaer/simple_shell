#include "main.h"

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

/***/

extern char **environ;

void _env(void)
{
	char **envs = environ;
	for (;*envs != NULL; envs++)
	{
		printf("%s\n", *envs);
	}
}
