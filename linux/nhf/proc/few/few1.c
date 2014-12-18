#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* ls -l /etc/ppp */

int
main()
{
	pid_t pid;

	puts("Begin.");

	fflush(NULL);
	pid = fork();
	if (pid<0) {
		perror("fork()");
		exit(1);
	}
	if (pid==0) {
		fflush(NULL);
		execl("/bin/ls", "ls", "-l", "/etc/ppp", NULL);
		perror("execl()");
		exit(1);
	}

	wait(NULL);

	puts("End.");

	return 0;
}

