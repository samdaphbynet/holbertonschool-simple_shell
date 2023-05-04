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

#define TOK_DELIM " \t\r\n\a"

extern char **environ;

/*ProtoType of all function*/

void shell_active(void);
void shell_no_active(void);

char *read_stream(void);
char *read_line(void);
int execute(char **args);
int process(char **args);

char **_split(char *str);
int own_env(char **args);
int own_exit(char **args);
int own_cd(char **args);








#endif
