#include "main.h"


int _putchar(char c)
{
	return (write(1, &c, 1));
}


int _puts(char *str)
{
	int count = 0;

	while (*str)
	{
		_putchar(*str);
		str++;
		count++;
	}

	return (count);
}


int _strlen(char *str)
{
	int i = 0;

	while (*str != '\0')
	{
		i++;
		str++;
	}

	return (i);
}


char *_concat_with_char(char *str1, char mid_char, char *str2)
{
	int len = _strlen(str1) + _strlen(str2), i, j;
	char *res = malloc(sizeof(char) * (len + 2));

	for (i = 0; str1[i] != '\0'; i++)
		res[i] = str1[i];

	res[i++] = mid_char;

	for (j = 0; str2[j] != '\0'; j++, i++)
		res[i] = str2[j];

	res[i] = '\0';

	return (res);
}


int _atoi(char *num)
{
	int i = 0, res = 0, sign = 1;

	if (num[0] == '-')
	{
		sign = -1;
		i++;
	}

	for (; num[i] != '\0'; i++)
	{
		if (num[i] < '0' || num[i] > '9')
			return (0);

		res = res * 10 + (num[i] - '0');
	}

	return (res * sign);
}
