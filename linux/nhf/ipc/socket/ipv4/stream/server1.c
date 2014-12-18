#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "proto.h"

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

int
main()
{
	int sd, newsd;
	struct sockaddr_in laddr, raddr;
	socklen_t raddr_len;
	char ipstr[IPSTRSIZE];
	pid_t pid;

	sd = socket(AF_INET, SOCK_STREAM, 0 /* IPPROTO_TCP, IPPROTO_SCTP */);
	if (sd<0) {
		perror("socket()");
		exit(1);
	}

	laddr.sin_family = AF_INET;
	laddr.sin_port = htons(atoi(SERVERPORT));
	inet_pton(AF_INET, "0.0.0.0", &laddr.sin_addr);
	if (bind(sd, (void*)&laddr, sizeof(laddr))<0) {
		perror("bind()");
		exit(1);
	}

	if (listen(sd, 200)<0) {
		perror("listen()");
		exit(1);
	}

	raddr_len = sizeof(raddr);
	while (1) {
		newsd = accept(sd, (void*)&raddr, &raddr_len);
		if (newsd<0) {
			if (errno==EINTR) {
				continue;
			} else {
				perror("accept()");
				exit(1);
			}
		} else {
			pid = fork();
			if (pid==0) {
				close(sd);
				inet_ntop(AF_INET, &raddr.sin_addr, ipstr, IPSTRSIZE);
				printf("=== Client: %s:%d ===\n", ipstr, ntohs(raddr.sin_port));
				server_job(newsd);
				close(newsd);
				exit(0);
			} else {
				close(newsd);
			}
		}
	}

	close(sd);

	return 0;
}

