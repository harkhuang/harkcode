#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#include "proto.h"

int
main(int argc, char **argv)
{
	int sd, ret;
	struct sockaddr_in6 raddr;
	long long stamp;
	FILE *fp;
    struct addrinfo hint, *res;

	if (argc<2) {
		fprintf(stderr, "Usage...\n");
		exit(1);
	}

    hint.ai_flags = 0;
    hint.ai_family = AF_INET6;
    hint.ai_socktype = SOCK_STREAM;
    hint.ai_protocol = 0;
    ret = getaddrinfo(argv[1], SERVERPORT, &hint, &res);
    if (ret) {
        fprintf(stderr, "getaddrinfo(): failed.\n");
        exit(1);
    }

	sd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
	if (sd<0) {
		perror("socket()");
		exit(1);
	}

	if (connect(sd, res->ai_addr, res->ai_addrlen)<0) {
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

