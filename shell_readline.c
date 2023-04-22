#include "shell.h"

/**
 *
 *
 */

char *shell_readline(void)
{
#ifdef USE_GET
	char *line = NULL;
	ssize_t bufsize = 0;

	getline(&line, &bufsize, stdin);
	return (line);
#else
#define SHELL_BUFSIZE 1024
	int bufsize = SHELL_BUFSIZE;
	int position = 0;
	char *buffer;
	int c;

	buffer = malloc(sizeof(char) * bufsize);
	if (buffer == NULL)
		exit(EXIT_FAILURE);
	while (1)
	{
		c = getchar();

		if (c == EOF)
		{
			exit(EXIT_FAILURE);
		}
		else if (c == '\n')
		{
			buffer[position] = '\0';
			return (buffer);
		}
		else
		{
			buffer[position] = c;
		}
		position++;

		if (position >= bufsize)
		{
			bufsize += SHELL_BUFSIZE;
			buffer = realloc(buffer, bufsize);

			if (buffer == NULL)
			{
				exit(EXIT_FAILURE);
			}
		}
	}
#endif
}
