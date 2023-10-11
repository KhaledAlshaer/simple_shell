#include "main.h"

/**
 *_split - This is the function
 *@buffer: this is a variable
 *Return: returns 0
*/
char **_split(char *buffer)
{
	char *str, *str2[1024];
	int i = 0;

	str = strtok(buffer, " ");
	while (str)
	{
		str2[i++] = str;
		str = strtok(NULL, " ");
	}

	str2[i] = NULL;

	return (str2);
}
