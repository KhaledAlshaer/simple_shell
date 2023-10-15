#include "main.h"

/**
 * _is_interactive- check to print prompt or not
 * Return: Nothing
*/

void _is_interactive(void)
{
	if (isatty(STDIN_FILENO))
		_puts("#cisfun$ ");
}
