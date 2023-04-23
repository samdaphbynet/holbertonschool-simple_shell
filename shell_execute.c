#include "shell.h"

/**
 *
 *
 */
int shell_exit(char **args);

char *builtin_str[] = 
{
	"exit"
};

int (*builtin_func[])(char **) = 
{
	&shell_exit
};

int shell_builtins(void)
{
        return (sizeof(builtin_str) / sizeof(char *));
}

int shell_execute(char **args)
{
	int i;

	if (args[0] == NULL)
		return (1);
	for (i = 0; i < shell_builtins(); i++)
	{
		if (strcmp(args[0], builtin_str[i]) == 0)
			return ((builtin_func[i])(args));
	}
	if (shell_launch(args) == 0)
		return (0);
	else
		return (1);
}


int shell_exit(char **args)
{
        if (args[0] == NULL)
                return (0);
        else
                return (0);
}
