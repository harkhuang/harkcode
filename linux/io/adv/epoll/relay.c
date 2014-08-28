#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/epoll.h>

#define	TTY1	"/dev/tty11"
#define	TTY2	"/dev/tty12"

enum {
	STATE_R=1,
	STATE_W,
	STATE_Ex,
	STATE_T
};

#define	BUFSIZE	1024
struct fsa_relay_st {
	int state;
	int sfd, dfd;
	char buf[BUFSIZE];
	int len, pos;
	char *errstr;
};

static void fsa_driver(struct fsa_relay_st *fsa)
{
	int ret;

	switch (fsa->state) {
		case STATE_R:
			fsa->len = read(fsa->sfd, fsa->buf, BUFSIZE);
			if (fsa->len==0) {
				fsa->state = STATE_T;
			} else if (fsa->len<0) {
				if (errno==EAGAIN) {
					/* Do nothing */
				} else {
					fsa->errstr = "read(sfd)";
					fsa->state = STATE_Ex;
				}
			} else {
				fsa->pos = 0;
				fsa->state = STATE_W;
			}
			break;
		case STATE_W:
			ret = write(fsa->dfd, fsa->buf+fsa->pos, fsa->len);
			if (ret<0) {
				if (errno==EAGAIN) {
					/* Do nothing */
				} else {
					fsa->errstr = "write(dfd)";
					fsa->state = STATE_Ex;
				}
			} else {
				fsa->pos += ret;
				fsa->len -= ret;
				if (fsa->len>0) {
					/* Do nothing */
				} else {
					fsa->state = STATE_R;
				}
			}
			break;
		case STATE_Ex:
			perror(fsa->errstr);
			fsa->state = STATE_T;
			break;
		case STATE_T:
			/* Do nothing */
			break;
		default:
			raise(SIGABRT);
			break;
	}
}

static int max(int a, int b)
{
	if (a<b) {
		return b;
	}
	return a;
}

static void relay(int fd1, int fd2)
{
	struct fsa_relay_st fsa1, fsa2;
	int fd1_saveflag, fd2_saveflag;
	int epfd;
	struct epoll_event ev;

	epfd = epoll_create(1);
	if (epfd<0) {
		perror("epoll_create()");
		exit(1);
	}

	fd1_saveflag = fcntl(fd1, F_GETFL);
	fcntl(fd1, F_SETFL, fd1_saveflag|O_NONBLOCK);
	fd2_saveflag = fcntl(fd2, F_GETFL);
	fcntl(fd2, F_SETFL, fd2_saveflag|O_NONBLOCK);

	fsa1.sfd = fd1;
	fsa1.dfd = fd2;
	fsa1.state = STATE_R;

	fsa2.sfd = fd2;
	fsa2.dfd = fd1;
	fsa2.state = STATE_R;

	ev.events = 0;
	epoll_ctl(epfd, EPOLL_CTL_ADD, fd1, &ev);
	epoll_ctl(epfd, EPOLL_CTL_ADD, fd2, &ev);

	while (fsa1.state!=STATE_T || fsa2.state!=STATE_T) {
		ev.data.fd = fd1;
		ev.events =0;
		if (fsa1.state==STATE_R) {
			ev.events |= EPOLLIN;;
		}
		if (fsa2.state==STATE_W) {
			ev.events |= EPOLLOUT;;
		}
		epoll_ctl(epfd, EPOLL_CTL_MOD, fd1, &ev);

		ev.data.fd = fd2;
		ev.events =0;
		if (fsa1.state==STATE_W) {
			ev.events |= EPOLLOUT;
		}
		if (fsa2.state==STATE_R) {
			ev.events |= EPOLLIN;
		}
		epoll_ctl(epfd, EPOLL_CTL_MOD, fd2, &ev);

		while (epoll_wait(epfd, &ev, 1, -1)<0) {
			if (errno!=EINTR) {
				perror("poll()");
				exit(1);
			} else {
				continue;
			}
		}
		if (pfd[0].revents&POLLIN || pfd[1].revents&POLLOUT) {
			fsa_driver(&fsa1);
		}
		if (pfd[1].revents&POLLIN || pfd[0].revents&POLLOUT) {
			fsa_driver(&fsa2);
		}
	}

	fcntl(fd1, F_SETFL, fd1_saveflag);
	fcntl(fd2, F_SETFL, fd2_saveflag);
}

int
main()
{
	int fd1, fd2;

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

	relay(fd1, fd2);

	close(fd2);
	close(fd1);

	return 0;
}

