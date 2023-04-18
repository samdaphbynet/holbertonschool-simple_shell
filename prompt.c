#include "shell.h"

#define MAX_CMD 20

/**
 *
 *
 */

void prompt(char **argv, char **env)
{
	char *str = NULL;
	int i, j;
	int status = 0;
	size_t n = 0;
	ssize_t num_char;
	char *av[MAX_CMD];
	pid_t child_pid;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("cisfun$ ");
		num_char = getline(&str, &n, stdin);

		if (num_char == -1)
		{
			free(str);
			exit(status);
		}
		i = 0;

		while (str[i])
		{
			if (str[i] == '\n')
				str[i] = 0;
			i++;
		}

		j = 0;
		av[0] = strtok(str, " ");

		while (av[j])
			av[++j] = strtok(NULL, " ");
		child_pid = fork();

		if (child_pid == -1)
		{
			free(str);
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			if (execve(av[0],av, env) == -1)
				printf("%s: No such file or directory\n", argv[0]);
		}
		else
		{
			wait(&status);
		}
	}
}
