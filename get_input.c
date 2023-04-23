#include "shell.h"

/**
 *
 *
 */

char **get_input(char *input)
{
	char **command = NULL;
	char *separator = " ";
	char *parsed = NULL;
	int i = 0;

	command = malloc(8 * sizeof(char *));

	if (command == NULL)
	{
		fprintf(stderr, "Error aloc\n");
		exit(EXIT_FAILURE);
	}
	parsed = strtok(input, separator);

	while (parsed != NULL)
	{
		command[i] = parsed;
		i++;
		parsed = strtok(NULL, separator);
	}
	command[i] = NULL;
	return (command);
}
