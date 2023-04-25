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

extern char **environ;

char *search_path(char *command);
char **_split(char *str, char *sep);
void _env(void);
int execute(char **args);
int empty_line(char *buff);

#endif
