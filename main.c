#include "shell.h"

/**
 * main - entry point.
 * Return: status.
 */

int main(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		shell_active();
	}
	else
	{
		shell_no_active();
	}
	return (0);
}
