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
        if (execvp(args[0], args) == -1)
        {
            perror("Error: process child");
            
            
        }
    }
    else if (pid < 0)
    {
        perror("Error: forking");
    }
    else
	{
		wait(&status);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
	}
	return (status);
}