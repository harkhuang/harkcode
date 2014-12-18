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
	struct score_st *scorep;
	struct sockaddr_in raddr;
	int len;

	if (argc<3) {
		fprintf(stderr, "Usage...\n");
		exit(1);
	}

	sd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sd<0) {
		perror("socket()");
		exit(1);
	}

	if (strlen(argv[2]) > SCORE_MAX-sizeof(struct score_st)) {
		fprintf(stderr, "Name is TOO long.\n");
		exit(1);
	}

	len = sizeof(struct score_st)+strlen(argv[2]);

	scorep = malloc(len);
	if (scorep==NULL) {
		perror("malloc()");
		exit(1);
	}

	strcpy(scorep->name, argv[2]);
	scorep->math = htonl(rand()%150);
	scorep->chinese = htonl(rand()%150);

	raddr.sin_family = AF_INET;
	raddr.sin_port = htons(atoi(RCVPORT));
	inet_pton(AF_INET, argv[1], &raddr.sin_addr);

	if (sendto(sd, scorep, len, 0, (void*)&raddr, sizeof(raddr))<0) {
		perror("msgsnd()");
		exit(1);
	}

	free(scorep);

	close(sd);

	return 0;
}

