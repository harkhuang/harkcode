#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>

#define	DATASIZE	1024

int
main()
{
	int ret;
	int pd[2];
	pid_t pid;
	char data[DATASIZE];

	puts("Begin.");
	if (pipe(pd)<0) {
		perror("pipe()");
		exit(1);
	}

	pid = fork();
	if (pid<0) {
		perror("fork()");
		exit(1);
	}
	if (pid==0) {
		close(pd[1]);
		while (1) {
			ret = read(pd[0], data, DATASIZE);
			if (ret<0) {
				if (errno==EINTR) {
					continue;
				} else {
					perror("read()");
					exit(1);
				}
			}
			if (ret==0) {
				break;
			}
			/* FIXME: loop! */
			write(1, data, ret);
		}
		close(pd[0]);
		exit(0);
	} else {
		close(pd[0]);
		/* FIXME: loop! */
		write(pd[1], "Hello!\n", 7);
		close(pd[1]);

		wait(NULL);

		exit(0);
	}
}

