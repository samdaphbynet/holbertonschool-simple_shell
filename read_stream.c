#include "shell.h"

/**
 * -read_stream - function that read line from stream
 * Return: pointer line
*/

char *read_stream(void)
{
    int bufsize = 1024;
    int i = 0;
    char *line;
    int character;

    line = malloc(sizeof(char) * bufsize);

    if (line == NULL)
    {
        fprintf(stderr, "Aloccation Error");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        character = getchar();

        if (character == EOF)
        {
            free(line);
            exit(EXIT_FAILURE);
        }
        else if (character == '\n')
        {
            line[i] = '\0';
            return (line);
        }
        else
        {
            line[i] = character;
        }
        i++;

        if (i >= bufsize)
        {
            bufsize += bufsize;
            line = realloc(line, bufsize);

            if (line == NULL)
            {
                fprintf(stderr, "Error: realloc");
                exit(EXIT_FAILURE);
            }
        }
    }
}