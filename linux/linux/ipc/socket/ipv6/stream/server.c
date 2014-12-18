#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "proto.h"

#define	POOLSIZE	4

#define	BUFSIZE	1024
static void server_job(int newsd)
{
	char buf[BUFSIZE];
	ssize_t len;
	int pos, ret;

	len = snprintf(buf, BUFSIZE, FMT_STAMP, (long long)time(NULL));
	pos = 0;
	sleep(5);
	while (len>0) {
		ret = send(newsd, buf+pos, len, 0);
		if (ret<0) {
			if (errno==EINTR) {
				continue;
			} else {
				perror("send()");
				exit(1);
			}
		}
		len -= ret;
		pos += ret;
	}
}

#define	IPSTRSIZE	40

static void server_loop(int sd)
{
	int newsd;
	struct sockaddr_in6 raddr;
	socklen_t raddr_len;
	char ipstr[IPSTRSIZE];

	raddr_len = sizeof(raddr);
	while (1) {
		newsd = accept(sd, (void*)&raddr, &raddr_len);
		if (newsd<0) {
			if (errno==EINTR || errno==EAGAIN) {
				continue;
			} else {
				perror("accept()");
				exit(1);
			}
		} else {
			inet_ntop(AF_INET6, &raddr.sin6_addr, ipstr, IPSTRSIZE);
			printf("[%d]: === Client: %s:%d ===\n", getpid(), ipstr, ntohs(raddr.sin6_port));
			server_job(newsd);
			close(newsd);
		}
	}

}

int
main()
{
	int sd;
	struct sockaddr_in6 laddr;
	pid_t pid;
	int i, val;

	sd = socket(AF_INET6, SOCK_STREAM, 0 /* IPPROTO_TCP, IPPROTO_SCTP */);
	if (sd<0) {
		perror("socket()");
		exit(1);
	}

    val = 1;
    if (setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val))<0) {
        perror("setsockopt(..., SO_REUSEADDR, ...)");
    }


	laddr.sin6_family = AF_INET6;
	laddr.sin6_port = htons(atoi(SERVERPORT));
	inet_pton(AF_INET6, "::", &laddr.sin6_addr);
	if (bind(sd, (void*)&laddr, sizeof(laddr))<0) {
		perror("bind()");
		exit(1);
	}

	if (listen(sd, 200)<0) {
		perror("listen()");
		exit(1);
	}

	for (i=0;i<POOLSIZE;++i) {
		pid = fork();
		if (pid<0) {
			perror("fork");
			exit(1);
		}
		if (pid==0) {
			server_loop(sd);
			exit(0);
		}
	}

	for (i=0;i<POOLSIZE;++i) {
		wait(NULL);
	}

	close(sd);

	return 0;
}

