#include "main.h"

/**
 * _perror - this is a function
 * @erro_msg: this is a variable
 * @free_me: this is a variable
 */
void _perror(char *erro_msg, char *free_me)
{
	perror(err_msg);
	free(free_me);
	exit(1);
}
