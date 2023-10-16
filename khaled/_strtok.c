#include "main.h"

/**
 *is_delim - This is the function
 *@c: this is a variable
 *@delim: this is a variable
 *Return: returns 0
*/
int is_delim(char c, const char *delim)
{
	while (*delim)
	{
		if (c == *delim)
		{
			return (1);
		}
		delim++;
	}
	return (0);
}

/**
 *_strtok - This is the function
 *@str: this is a variable
 *@delim: this is a variable
 *Return: returns 0
*/
char *_strtok(char *str, char *delim)
{
	static char *current_position = NULL;
	char *val = NULL;

	if (str != NULL)
	{
		current_position = str;
	}

	while (current_position != NULL && *current_position != '\0')
	{
		while (is_delim(*current_position, delim))
		{
			current_position++;
		}

		if (val != NULL)
		{
			*current_position = '\0';
			return (val);
		}
	}
	return(NULL);
}
