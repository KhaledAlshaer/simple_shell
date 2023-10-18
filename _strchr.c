#include "main.h"

/**
 **_strchr - This is the function
 *@str: this is a variable
 *@character: this is a variable
 *Return: returns 0
*/
char *_strchr(const char *str, int character)
{
	while (*str != '\0')
	{
		if (*str == character)
		{
			return ((char *)str);
		}
		else
		{
			str++;
		}
	}

	return (NULL);
}
