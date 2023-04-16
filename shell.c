#include "shell.c"

int main(void) {
	char *args[MAX_LINE / 2 + 1];
	int should_run = 1;
	char cmd[MAX_LINE];
	char *token;

	while (should_run) {
		printf("my_shell> ");
		fflush(stdout);

		fgets(cmd, MAX_LINE, stdin);

		cmd[strcspn(cmd, "\n")] = '\0';

		token = strtok(cmd, " ");
		int i = 0;
		while (token != NULL) {
			args[i++] = token;
			token = strtok(NULL, " ");
		}
		args[i] = NULL;

		pid_t pid = fork();
		if (pid == -1) {
			perror("fork");
			exit(EXIT_FAILURE);
		} else if (pid == 0) {

			execvp(args[0], args);
			perror("execvp");
			exit(EXIT_FAILURE);
		} else {

			wait(NULL);
		}
	}
