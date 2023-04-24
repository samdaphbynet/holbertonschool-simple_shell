#include "shell.h"

/**
 *
 *
 */


int main()
{
	char **command = NULL;
	char input[2024];
	pid_t child_pid;
	int status = 0;
	int i;	

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");
		if (fgets(input, sizeof(input), stdin) == NULL)
			break;

		input[strcspn(input, "\n")] = '\0';

		if (strcmp(input, "exit") == 0)
		{
			break;
		}
		command = get_input(input);

		child_pid = fork();

		if (child_pid == -1)
		{
			perror("Fork failed");
			exit(1);
		}
		if (child_pid == 0)
		{
			if (execvp(command[0], command) == -1)
			{
				fprintf(stderr, "./hsh: %d: %s: not found\n", getpid(), command[0]);
				free(command[0]);
				free(command);
				exit(127);
			}
		}
		else
		{
			waitpid(child_pid, &status, WUNTRACED);
		}
		for (i = 0; command[i] != NULL; i++)
			free(command[i]);
		free(command);
	}
	return (0);
}
