#include "shell.h"

/**
 * shell_active - function that execute cmd in shell active
*/

void shell_active(void)
{
    char *line = NULL;
    char **args = NULL;
    int status = -1;

    do
    {
        printf("#cisfun$ ");
        line = read_line();
        args = _split(line);
        status = execute(args);

        free(line);
        free(args);

        if (status >= 0)
            exit(status);
    }while (status == -1);
    
}