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
	int bufsize = 64;
	int i = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "error in _split\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(str, TOK_DELIM);
	while (token != NULL)
	{
		if (token[0] == '#')
		{
			break;
		}
		tokens[i] = token;
		i++;
		if (i >= bufsize)
		{
			bufsize += bufsize;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "reallocation error in split");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, TOK_DELIM);
	}
	tokens[i] = NULL;
	return (tokens);
}
