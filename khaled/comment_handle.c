#include "main.h"

/**
 *comments - This is the function
 *@str: this is a variable
 *Return: returns 0
*/
char *comments(char *str)
{
	char *res = _strdup(str);
	char *comment_start = _strchr(str, '#');

	if (comment_start != NULL)
	{
		comment_start = '\0';
	}

	return (res);
}
