#include "shell.h"

/**
 * execute - execute command path
 * @args: arguments passed
 * Return: exit status
 */

int execute(char **args)
{
    unsigned int i = 0;
	char *builtin_f_list[] =
    {
        "cd",
        "env",
        "exit"
    };
    int (*builtin_f[])(char **) =
    {
        &own_cd,
        &own_env,
        &own_exit
    };

    if (args[0] == NULL)
    {
        return (-1);
    }

    for (; i < sizeof(builtin_f_list) / sizeof(char *); i++)
    {
        if (strcmp(args[0], builtin_f_list[i]) == 0)
        {
            return ((*builtin_f[i])(args));
        }
    }
    return (process(args));
}