#include "main.h"

/**
 *comments - This is the function
 *@str: this is a variable
 *Return: returns 0
*/
void comments(char *str)
{

	char *comment_start = _strchr(str, '#');

	if (comment_start != NULL)
	{
		*comment_start = '\0';
	}
}
