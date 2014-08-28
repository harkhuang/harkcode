#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>

#include "proto.h"

#define	IPSTRSIZE	40

int
main()
{
	int sd;
	struct score_st *scorep;
	struct sockaddr_in laddr, raddr;
	socklen_t raddr_len;
	char ipstr[IPSTRSIZE];
	ssize_t len;

	sd = socket(AF_INET, SOCK_DGRAM, 0 /* IPPROTO_UDP */);
	if (sd<0) {
		perror("socket()");
		exit(1);
	}

	laddr.sin_family = AF_INET;
	laddr.sin_port = htons(atoi(RCVPORT));
	inet_pton(AF_INET, RCVADDR, &laddr.sin_addr);
	if (bind(sd, (void*)&laddr, sizeof(laddr))<0) {
		perror("bind()");
		exit(1);
	}

	scorep = malloc(SCORE_MAX);
	if (scorep==NULL) {
		perror("malloc()");
		exit(1);
	}

	raddr_len = sizeof(raddr);
	while (1) {
		while ((len = recvfrom(sd, scorep, SCORE_MAX, 0, (void*)&raddr, &raddr_len))<0) {
			if (errno!=EINTR) {
				perror("rcvfrom()");
				exit(1);
			}
		}
		inet_ntop(AF_INET, &raddr.sin_addr, ipstr, IPSTRSIZE);
		printf("======= From: %s:%d (%d)=======\n", ipstr, ntohs(raddr.sin_port), len);
		if (len>SCORE_MAX) {
			continue;
		}
		len -= sizeof(struct score_st);
		len -= 1;
		if (len<=0) {
			continue;
		}
		printf("Name: ");
		fwrite(scorep->name, 1, len, stdout);
		printf("\n");
		printf("Math: %d\n", ntohl(scorep->math));
		printf("Chinese: %d\n", ntohl(scorep->chinese));
	}

	free(scorep);

	close(sd);

	return 0;
}

