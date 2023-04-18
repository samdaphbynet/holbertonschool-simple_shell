#include "shell.h"

/**
 *
 *
 */

void read_line(char **argv, char **env)
{
	char *str = NULL;
	int i, status;
	size_t n = 0;
	ssize_t num_char;
	char *av[] = {NULL, NULL};
	pid_t child_pid;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("cisfun$ ");
		num_char = getline(&str, &n, stdin);

		if (num_char == -1)
		{
			free(str);
			exit(EXIT_FAILURE);
		}
		i = 0;

		while (str[i])
		{
			if (str[i] == '\n')
				str[i] = 0;
			i++;
		}
		av[0] = str;
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
