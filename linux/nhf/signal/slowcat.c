#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <sys/time.h>

#define	CPS		10
#define	BURST	60

#define	BUFSIZE	(CPS)

static volatile sig_atomic_t token=0;

static void alrm_handler(int s)
{
//	alarm(1);
	token++;
	if (token>BURST) {
		token = BURST;
	}
}

int
main(int argc, char **argv)
{
	int sfd, dfd, ret;
	char buf[BUFSIZE];
	ssize_t len, pos;
	struct itimerval tv, otv;

	if (argc<2) {
		fprintf(stderr, "Usage...\n");
		exit(1);
	}

	while ((sfd = open(argv[1], O_RDONLY))<0) {
		if (errno!=EINTR) {
			perror("open()");
			exit(1);
		}
	}

	dfd = 1;

	signal(SIGALRM, alrm_handler);
//	alarm(1);
	tv.it_interval.tv_sec = 1;
	tv.it_interval.tv_usec = 0;
	tv.it_value.tv_sec = 1;
	tv.it_value.tv_usec = 0;
	setitimer(ITIMER_REAL, &tv, &otv);

	while (1) {
		while (token<=0) pause();
		token--;

		while ((len = read(sfd, buf, BUFSIZE))<0) {
			if (errno==EINTR) {
				continue;
			}
			perror("read()");
			exit(1);
		}
		if (len==0) {
			break;
		}
		pos = 0;
		while (len>0) {
			ret = write(dfd, buf+pos, len);
			if (ret<0) {
				if (errno==EINTR) {
					continue;
				}
				perror("write()");
				exit(1);
			}
			pos += ret;
			len -= ret;
		}
	}

	close(sfd);

	return 0;
}

