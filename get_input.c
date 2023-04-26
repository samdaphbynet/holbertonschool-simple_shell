#include "shell.h"

/**
 * execute - execute command path
 * @args: arguments passed
 * Return: exit status
 */

int execute(char **args)
{
	int status;
	pid_t pid;
	char *path = search_path(args[0]);
	if (path == NULL)
	{
		perror(args[0]);
		return 1;
	}
	status = 0;
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return 1;
	}
	if (pid == 0)
	{
		char **argv = _split(args[1], " ");
		char *envp[] = { NULL };
		char *command = malloc(strlen(path) + strlen(args[1]) + 2);
		sprintf(command, "%s %s", path, args[1]);
		execve(command, argv, envp);
		perror(command);
		free(command);
		free(argv);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
	}
	free(path);
	return status;
}

/**
 *
 *
 */

void _env(void)
{
	int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}

/**
 *
 *
 */

int empty_line(char *buff)
{
	int i;

	for (i = 0; buff[i] != '\0'; i++)
	{
		if (buff[i] != ' ')
			return (0);
	}
	return (1);
}

/**
 *
 *
 */

char **_split(char *str, char *sep)
{
	char *aux, **split_str;
	int i = 0;

	aux = strtok(str, sep);
	split_str = (char **)calloc(100, sizeof(char *));

	if (!split_str)
	{
		free(split_str);
		return (NULL);
	}

	while (aux)
	{
		split_str[i] = aux;
		aux = strtok(NULL, sep);
		i++;
	}
	return (split_str);
}
