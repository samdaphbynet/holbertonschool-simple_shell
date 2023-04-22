#include "shell.h"

/**
 *
 *
 */

int main(int argc, char *argv[])
{
	if (argc > 0 && argv[0] != NULL)
		shell_loop();
	else
		shell_loop();
	return (EXIT_SUCCESS);
}
