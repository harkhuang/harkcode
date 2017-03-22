#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#define	LEFT	30000000
#define	RIGHT	30000200

static void chld_handler(int s)
{
	while (waitpid(-1, NULL, WNOHANG)>0);
//	waitpid(-1, NULL, WNOHANG);
}

int
main()
{
	int i, j;
	int mark;
	pid_t pid;
	int status;
	struct sigaction sa, osa;

	sa.sa_handler = chld_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;

	singaction(SIGCHLD, &sa, NULL);

	for (i=LEFT;i<=RIGHT;++i) {
		pid = fork();
		if (pid<0) {
			perror("fork()");
			exit(1);
		}
		if (pid==0) {
			mark=1;
			for (j=2;j<i/2;++j) {
				if (i%j==0) {
					mark=0;
					break;
				}
			}
			if (mark==1) {
				printf("[%d]: %d is a prime\n", getpid(), i);
			}
			exit(0);	/* !!!!!!!!!!! */
		}
	}

/*
	for (i=LEFT;i<=RIGHT;) {
		wait(&status);
		if (!WIFSTOPPED(status) && !WIFCONTINUED(status)) {
			++i;
		}
	}
*/

	while (1) {
		write(2, ".", 1);
		sleep(1);
	}

	return 0;
}

