#include "shell.h"

/**
 * process - function that launch new process
 * @args: the arguments passed in shell
 * Return: -1
*/

int process(char **args)
{
    int pid;
    int status;

    pid = fork();

    if (pid == 0)
    {
        if (execve(args[0], args, environ) == -1)
        {
            perror("Error: process child");
            free(args[0]);
        }
        free(args);
        exit(EXIT_FAILURE);
    }
    else if (pid < 0)
    {
        perror("Error: forking");
        return (-1);
    }
    else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));

        if (WIFEXITED(status))
        {
            return (WEXITSTATUS(status));
        }
        else
        {
            return (-1);
        }
	}
}