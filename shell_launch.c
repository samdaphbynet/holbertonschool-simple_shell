#include "shell.h"

/**
 *
 *
 */

int hsh_launch(char **args)
{
	pid_t child_pid;
	int status = 0;

	child_pid = fork();
	
	if (child_pid == -1)
	{
		perror("./shell: Error fork");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		do
		{
			waitpid(child_pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
