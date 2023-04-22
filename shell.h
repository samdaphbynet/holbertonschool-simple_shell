#ifndef MAIN_H
#define MAIN_H
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#define SHELL_TOKEN 64
#define SHELL_DELIM " \t\r\n\a"

int shell_launch(char **args);
char *shell_readline(void);
char **shell_split(char *line);
void shell_loop(void);
int shell_exit(char **args);
int shell_builtins(void);
int shell_execute(char **args);
#endif
