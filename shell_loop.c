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
		if (!line)
			break;

		args = shell_split(line);

		if (!args)
		{
			free(line);
			break;
		}
		status = shell_execute(args);

		free(line);
		free(args);
	} while (status);
}
