#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* ls -l /etc/ppp */

static int mysystem(const char *cmd)
{
	pid_t pid;
	int status;

	fflush(NULL);
	pid = fork();
	if (pid<0) {
		perror("fork()");
		exit(1);
	}
	if (pid==0) {
		fflush(NULL);
		execl("/bin/sh", "sh", "-c", cmd, NULL);
		perror("execl()");
		exit(1);
	}

	waitpid(pid, status, 0);
	if (WIFEXITED(status)) {
		return WEXITSTATUS(status);
	}
	return -1;
}

int
main()
{
	puts("Begin.");

	mysystem("ls -l /etc/ppp");

	puts("End.");

	return 0;
}

