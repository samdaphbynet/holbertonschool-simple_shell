#include "shell.h"

/**
 *
 *
 */

char *hsh_read_line(int argc, char **argv)
{
#ifdef HSH_USE_STD_GETLINE
    char *line = NULL;
    ssize_t bufsize = 0;

    getline(&line, &bufsize, stdin);
    return (line);
#else
#define HSH_RL_BUFSIZE 1024
    int bufsize = HSH_RL_BUFSIZE;
    int position = 0;
    char *buffer = malloc(sizeof(char) * bufsize);
    int c, i;
    char *cmdline_args = malloc(sizeof(char) * bufsize);

    if (!buffer || !cmdline_args)
    {
        fprintf(stderr, "hsh: allocation error\n");
        exit(EXIT_FAILURE);
    }

    cmdline_args[0] = '\0';

    for (i = 1; i < argc; i++)
    {
        cmdline_args = strcat(cmdline_args, argv[i]);
        cmdline_args = strcat(cmdline_args, " ");
    }

    strcat(buffer, cmdline_args);
    free(cmdline_args); 

    while (1)
    {
        c = getchar();

        if (c == EOF)
        {
            exit(EXIT_SUCCESS);
        }
        else if (c == '\n')
        {
            buffer[position] = '\0';
            return (buffer);
        }
        else
        {
            buffer[position] = c;
        }
        position++;

        if (position >= bufsize)
        {
            bufsize += HSH_RL_BUFSIZE;
            buffer = realloc(buffer, bufsize);
            if (!buffer)
            {
                fprintf(stderr, "hsh: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
    }
#endif
}

