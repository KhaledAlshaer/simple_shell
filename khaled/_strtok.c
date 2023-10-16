#include "main.h"

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
		val = NULL;
	}
	else if (current_position == NULL || *current_position == '\0')
	{
		return (NULL);
	}

	 while (*current_position)
	{
		if (strchr(delim, *current_position) != NULL)
		{
		*current_position = '\0';
		current_position++;
		return (val);
		}
		else
		{
			if (val == NULL)
			{
				val = current_position;
			}
		}

		current_position++;
	}

	 return (val);
}
