#include "shell.h"

/**
 *
 *
 */

void execute_cmd(char **argv)
{
	char *cmd = NULL, *act_cmd = NULL;
	int status = 0;
	pid_t child_pid;

	if (argv)
	{
		cmd = argv[0];
		act_cmd = get_location(cmd);

		child_pid = fork();

		if (child_pid == -1)
		{
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			if (execve(act_cmd, argv, NULL) == -1)
				printf("%s: No such file or directory\n", cmd);
		}
		else
		{
			if (waitpid(child_pid, &status, 0) == -1)
				exit(EXIT_FAILURE);
		
			if (WIFEXITED(status))
				status = WEXITSTATUS(status);
		}
	}
}
