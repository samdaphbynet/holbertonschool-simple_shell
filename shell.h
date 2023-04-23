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

int hsh_exit(char **args);

int hsh_num_builtins(void);
int hsh_launch(char **args);
int hsh_execute(char **args);
char *hsh_read_line(int argc, char **argv);
char **hsh_split_line(char *line);
void hsh_loop(void);

#endif
