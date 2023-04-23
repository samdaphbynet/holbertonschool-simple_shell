#include "shell.h"

/**
 *
 *
 */
char **hsh_split_line(char *line)
{
	int bufsize = HSH_TOK_BUFSIZE, position = 0;
	char **tokens;
	char *token;

	tokens = malloc(bufsize * sizeof(char *));

	if (!tokens)
	{
		fprintf(stderr, "./shell: Error\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, HSH_TOK_DELIM);

	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += HSH_TOK_BUFSIZE;
			tokens = realloc(tokens, bufsize * sizeof(char *));

			if (!tokens)
			{
				perror("reallocation de mémoire");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, HSH_TOK_DELIM);
	}
	tokens[position] = NULL;
	return (tokens);
}

