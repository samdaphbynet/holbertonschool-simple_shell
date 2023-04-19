#include "shell.h"

/**
 *
 *
 */

void prompt(char **argv, char **env)
{
	char *str = NULL;
	char *av[MAX_CMD];
	int status = 0, i, j;
	size_t n = 0;
	ssize_t num_char;
	pid_t child_pid;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");
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
		while (j < MAX_CMD - 1 && av[j])
		{
			av[++j] = strtok(NULL, " ");
		}
		if (j == 0)
			continue;
		child_pid = fork();
		if (child_pid == -1)
		{
			free(str);
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			if (execve(av[0], av, env) == -1)
				printf("%s: No such file or directory\n", argv[0]);
		}
		else
		{
			if (waitpid(child_pid, &status, 0) == -1)
			{
				free(str);
				exit(EXIT_FAILURE);
			}
			if (WIFEXITED(status))
				status = WEXITSTATUS(status);
		}
	}
}
