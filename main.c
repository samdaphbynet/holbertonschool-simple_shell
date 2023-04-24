#include "shell.h"

/**
 *
 *
 */

int main()
{
    char **command = NULL;
    char input[1024];
    pid_t child_pid;
    int status;
    int i;

    while (1)
    {
        if (isatty(STDIN_FILENO))
            printf("#cisfun$ ");
        if (fgets(input, sizeof(input), stdin) == NULL)
            exit(EXIT_FAILURE);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "exit") == 0)
	{
		for (i = 0; command[i] != NULL; i++)
		{
			free(command[i]);
		}
		free(command);
		break;
	}
        command = get_input(input);
        child_pid = fork();

        if (child_pid == -1)
        {
            perror("Fork failed");
            exit(EXIT_FAILURE);
        }
        if (child_pid == 0)
        {
            if (execvp(command[0], command) == -1)
            {
		    fprintf(stderr, "./hsh: %d: %s: not found\n", getpid(), command[0]);
                    exit(status);
            }
        }
        else
        {
            waitpid(child_pid, &status, WUNTRACED);
        }

        for (i = 0; command[i] != NULL; i++)
        {
            free(command[i]);
        }
        free(command);
    }
    return (0);
}
