#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "proto.h"

int
main(int argc, char **argv)
{
	int sd;
	struct sockaddr_in raddr;
	long long stamp;
	FILE *fp;

	if (argc<2) {
		fprintf(stderr, "Usage...\n");
		exit(1);
	}

	sd = socket(AF_INET, SOCK_STREAM, 0);
	if (sd<0) {
		perror("socket()");
		exit(1);
	}

	raddr.sin_family = AF_INET;
	raddr.sin_port = htons(atoi(SERVERPORT));
	inet_pton(AF_INET, argv[1], &raddr.sin_addr);
	if (connect(sd, (void*)&raddr, sizeof(raddr))<0) {
		perror("connect()");
		exit(1);
	}

	fp = fdopen(sd, "r+");
	if (fp==NULL) {
		perror("fdopen()");
		exit(1);
	}

	fscanf(fp, FMT_STAMP, &stamp);

	fclose(fp);

	printf("stamp is %lld\n", stamp);

	return 0;
}

