#include "shell.h"

/**
 *
 *
 */

int main(int ac, char **argv)
{
	char *str = NULL, *str_cpy = NULL, *token;
	const char *delim = " \n";
	size_t n = 0;
	ssize_t num_char;
	int num_tokens = 0, i;
	(void)ac;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");
		num_char = getline(&str, &n, stdin);

		if (num_char == -1)
		{
			free(str);
			exit(EXIT_FAILURE);
		}
		str_cpy = malloc(sizeof(char *) * num_char);

		if (str_cpy == NULL)
		{
			free(str);
			exit(EXIT_FAILURE);
		}
		strcpy(str_cpy, str);
		token = strtok(str, delim);

		while (token != NULL)
		{
			num_tokens++;
			token = strtok(NULL, delim);
		}
		num_tokens++;

		argv = malloc(sizeof(char * ) * num_tokens);

		token = strtok(str_cpy, delim);

		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);

			token = strtok(NULL, delim);
		}
		argv[i] = NULL;
		execute_cmd(argv);
	}
	free(str);
	free(str_cpy);
	return (0);
}
