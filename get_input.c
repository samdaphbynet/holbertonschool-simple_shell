#include "shell.h"

/**
 *
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARG 1024

char **get_input(char *input)
{
    char **command = NULL;
    char *separator = " \t\n\a";
    char *parsed = NULL;
    char *input_copy = NULL;
    int i = 0;

    command = malloc(sizeof(char *) * MAX_ARG);
    if (command == NULL)
    {
        fprintf(stderr, "Error: Failed to allocate memory for command.\n");
        exit(EXIT_FAILURE);
    }

    input_copy = strdup(input);
    if (input_copy == NULL)
    {
        fprintf(stderr, "Error: Failed to copy input string.\n");
        exit(EXIT_FAILURE);
    }

    parsed = strtok(input_copy, separator);

    while (parsed != NULL && i < MAX_ARG - 1)
    {
        command[i] = strdup(parsed);
        if (command[i] == NULL)
        {
            fprintf(stderr, "Error: Failed to allocate memory for argument.\n");
            exit(EXIT_FAILURE);
        }
        parsed = strtok(NULL, separator);
        i++;
    }

    command[i] = NULL;

    free(input_copy);
    return command;
}
