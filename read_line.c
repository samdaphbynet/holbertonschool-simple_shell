#include "shell.h"

/**
 * read_line - function that read line
 * Return: pointer that pointe to string with content
*/

char *read_line(void)
{
    char *line = NULL;
    size_t size = 0;

    if (getline(&line, &size, stdin) == -1)
    {
        if (feof(stdin))
        {
            free(line);
            exit(EXIT_FAILURE);
        }
    }
    return (line);
}