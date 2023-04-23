#include "shell.h"

/**
 *
 *
*/

#define MAX_ARG 128

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
		fprintf(stderr, "Error aloc\n");
		exit(EXIT_FAILURE);
	}

	input_copy = strdup(input);
	if (input_copy == NULL)
	{
		perror("strdup failed");
		exit(EXIT_FAILURE);
	}
	parsed = strtok(input_copy, separator);

	while (parsed != NULL && i < MAX_ARG - 1)
	{
		command[i] = strdup(parsed);
		if (command[i] == NULL)
		{
			perror("strdup failed");
			exit(EXIT_FAILURE);
		}
		parsed = strtok(NULL, separator);
		i++;
	}
	command[i] = NULL;
	free(input_copy);
	return (command);
}
