#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>

#include "proto.h"

int
main(int argc, char **argv)
{
	int sd;
	struct score_st score;
	struct sockaddr_in raddr;
	int val;

	sd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sd<0) {
		perror("socket()");
		exit(1);
	}

	val=1;
	if (setsockopt(sd, SOL_SOCKET, SO_BROADCAST, &val, sizeof val)<0) {
		perror("setsockopt()");
		exit(1);
	}
	if (setsockopt(sd, SOL_SOCKET, SO_BINDTODEVICE, "eth0", 5)<0) {
		perror("setsockopt()");
		exit(1);
	}

	memset(&score, 0, sizeof(score));
	strcpy(score.name, "Alan");
	score.math = htonl(rand()%150);
	score.chinese = htonl(rand()%150);

	raddr.sin_family = AF_INET;
	raddr.sin_port = htons(atoi(RCVPORT));
	inet_pton(AF_INET, "255.255.255.255", &raddr.sin_addr);

	if (sendto(sd, &score, sizeof(score), 0, (void*)&raddr, sizeof(raddr))<0) {
		perror("msgsnd()");
		exit(1);
	}

	close(sd);

	return 0;
}

