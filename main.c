#include "shell.h"

/**
 * main - entry point.
 * Return: status.
 */

int main(void)
{
	char *buff = NULL, **args;
	size_t read_size = 0;
	ssize_t buff_size = 0;
	int status = 0;

	while (1)
	{
		if (isatty(0))
			printf("#cisfun$ ");

		buff_size = getline(&buff, &read_size, stdin);
		if (buff_size == -1 || strcmp("exit\n", buff) == 0)
		{
			free(buff);
			exit(status);
		}
		buff[buff_size - 1] = '\0';

		if (strcmp("env", buff) == 0)
		{
			_env();
			continue;
		}

		if (empty_line(buff) == 1)
		{
			status = 0;
			continue;
		}

		args = _split(buff, " ");
		args[0] = search_path(args[0]);

		if (args[0] != NULL)
			status = execute(args);
		else
			perror("Error");
		free(args);
	}
	return (status);
}
