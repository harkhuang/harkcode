#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int
main()
{
	pid_t pid;

	puts("Begin");
	fflush(NULL);
	pid = fork();
	if (pid<0) {
		perror("fork()");
		exit(1);
	}
	if (pid==0) {
		puts("Child.");
	} else {
		puts("Parent.");
	}

	puts("End.");
	return 0;
}

