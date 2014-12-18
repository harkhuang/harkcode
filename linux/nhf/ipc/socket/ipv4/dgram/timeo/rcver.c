#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>
#include <sys/time.h>

#include "proto.h"

#define	IPSTRSIZE	40

int
main()
{
	int sd;
	struct score_st score;
	struct sockaddr_in laddr, raddr;
	socklen_t raddr_len;
	char ipstr[IPSTRSIZE];
	struct timeval to;

	to.tv_sec = 3;
	to.tv_usec = 0;

	sd = socket(AF_INET, SOCK_DGRAM, 0 /* IPPROTO_UDP */);
	if (sd<0) {
		perror("socket()");
		exit(1);
	}

	if (setsockopt(sd, SOL_SOCKET, SO_RCVTIMEO, &to, sizeof(to))<0) {
		perror("setsockopt(,SO_RCVTIMEO,)");
	}

	laddr.sin_family = AF_INET;
	laddr.sin_port = htons(atoi(RCVPORT));
	inet_pton(AF_INET, RCVADDR, &laddr.sin_addr);
	if (bind(sd, (void*)&laddr, sizeof(laddr))<0) {
		perror("bind()");
		exit(1);
	}

	raddr_len = sizeof(raddr);
	while (1) {
		while (recvfrom(sd, &score, sizeof(score), 0, (void*)&raddr, &raddr_len)<0) {
			if (errno==EAGAIN || errno==EWOULDBLOCK) {
				fprintf(stderr, "3 seconds.\n");
				continue;
			}
			if (errno!=EINTR) {
				perror("rcvfrom()");
				exit(1);
			}
		}
		inet_ntop(AF_INET, &raddr.sin_addr, ipstr, IPSTRSIZE);
		printf("======= From: %s:%d =======\n", ipstr, ntohs(raddr.sin_port));
		printf("Name: %s\n", score.name);
		printf("Math: %d\n", ntohl(score.math));
		printf("Chinese: %d\n", ntohl(score.chinese));
	}

	close(sd);

	return 0;
}

