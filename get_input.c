#include "shell.h"

/**
 * own_cd - function that change directory
 * @args: target directory
 * Return: 1 on success , 0 otherwise
*/

int own_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "Error cd\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("Errorin function cd\n");
		}
	}
	return (-1);
}

/**
 * _env - Displays the current environment.
 */

int own_env(char **args)
{
	int i = 0;
	(void)(**args);

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (-1);
}


/**
 * own_exit - function that exit own shell
 * @args: empty argument
 * Return: 0 for exit own shell
*/

int own_exit(char **args)
{
	if (args[1])
	{
		return (atoi(args[1]));
	}
	else
	{
		return (0);
	}
}

/**
 * _split - splits a string into an array of substrings
 * @str: string to split
 * Return: array of substrings
 */

char **_split(char *str)
{
	char *aux, **split_str;
	int i = 0;

	aux = strtok(str, TOK_DELIM);
	split_str = (char **)calloc(100, sizeof(char *));

	if (!split_str)
	{
		free(split_str);
		return (NULL);
	}

	while (aux)
	{
		split_str[i] = aux;
		aux = strtok(NULL, TOK_DELIM);
		i++;
	}
	return (split_str);
}
