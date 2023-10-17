#include "main.h"

/**
 * main- entry point
 * @argc: the args count
 * @argv: the args vector
 * Return: 0 when exit
*/

int main(int argc, char *argv[])
{
	if (argc == 1)
		return (interactive());
	else if (argc > 1)
	{

		return (non_interactive(argv[1]));
	}

	return (0);
}
