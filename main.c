#include "shell.h"

/**
 *
 *
 */

int main(int argc, char **argv, char **env)
{
	if (argc == 1)
		read_line(argv, env);
	return (0);
}
