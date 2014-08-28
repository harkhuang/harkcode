#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>

#include "librelay.h"

#define	TTY1	"/dev/tty11"
#define	TTY2	"/dev/tty12"
#define	TTY3	"/dev/tty9"
#define	TTY4	"/dev/tty10"

int
main()
{
	int job1, job2;
	int fd1, fd2;
	struct relay_jobstat_st jobstat;

	fd1 = open(TTY1, O_RDWR);
	if (fd1<0) {
		perror("open()");
		exit(1);
	}
	write(fd1, "TTY1\n", 5);

	fd2 = open(TTY2, O_RDWR|O_NONBLOCK);
	if (fd2<0) {
		perror("open()");
		exit(1);
	}
	write(fd2, "TTY2\n", 5);

	job1 = relay_addjob(fd1, fd2);
	if (job1<0) {
		perror("relay_addjob()");
		exit(1);
	}

fprintf(stderr, "main(): job1=%d\n", job1);

	fd1 = open(TTY3, O_RDWR);
	if (fd1<0) {
		perror("open()");
		exit(1);
	}
	write(fd1, "TTY3\n", 5);

	fd2 = open(TTY4, O_RDWR|O_NONBLOCK);
	if (fd2<0) {
		perror("open()");
		exit(1);
	}
	write(fd2, "TTY4\n", 5);

	job2 = relay_addjob(fd1, fd2);
	if (job2<0) {
		perror("relay_addjob()");
		exit(1);
	}

	while (1) {
		relay_statjob(job1, &jobstat);
		printf("job1: 1->2=%lld, 2->1=%lld\n", jobstat.count12, jobstat.count21);
		relay_statjob(job2, &jobstat);
		printf("job2: 1->2=%lld, 2->1=%lld\n", jobstat.count12, jobstat.count21);
		printf("----------------------------\n");
		sleep(1);
	}

	close(fd2);
	close(fd1);

	return 0;
}

