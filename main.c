#include "shell.h"

/**
 *
 *
 */

int main(int argc, char *argv[])
{

	if (argc > 0 && argv[0] != NULL)
		hsh_loop();
	else
		hsh_loop();

	return (EXIT_SUCCESS);
}
