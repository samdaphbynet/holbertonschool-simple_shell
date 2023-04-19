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

#define MAX_CMD 20

void prompt(char **argv, char **env);
void exec_cmd(char **av, char **env, int *status);
void read_cmd(char **av);
#endif
