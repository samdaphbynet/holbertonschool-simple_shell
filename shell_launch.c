#include "shell.h"

/**
 *
 *
 */

int shell_launch(char **args)
{
	pid_t child_pid;
	int status;

	child_pid = fork();


	if (child_pid == 0)
	{
		if (execvp(args[0], args) == -1)
			perror("./shell");
		exit(EXIT_FAILURE);
	}
	else if (child_pid < 0)
		perror("./shell");
	else
	{
		do
		{
			waitpid(child_pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
