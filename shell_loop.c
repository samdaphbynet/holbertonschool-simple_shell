#include "shell.h"

/**
 *
 */

void shell_loop(void)
{
	char *line;
	char **args;
	int status;

	do
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");
		line = shell_readline();
		args = shell_split(line);
		status = shell_execute(args);

		free(line);
		free(args);
	} while (status);
}
