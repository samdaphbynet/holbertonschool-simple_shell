#include "shell.h"

/**
 *
 */

void hsh_loop(void)
{
        char *line;
        char **args;
        int status = 0;

        do {
		if (isatty(STDIN_FILENO))
                	printf("#CisFun$ ");
                line = hsh_read_line(0, NULL);
                args = hsh_split_line(line);
                status = hsh_execute(args);

                free(line);
                free(args);
        } while (status);
}
