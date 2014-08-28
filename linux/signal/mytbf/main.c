#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

#include "mytbf.h"

#define	CPS		10
#define	BURST	60

#define	BUFSIZE	1024

int
main(int argc, char **argv)
{
	int sfd, dfd, ret;
	char buf[BUFSIZE];
	ssize_t len, pos, size;
	mytbf_t *tbf;
	int err;

	if (argc<2) {
		fprintf(stderr, "Usage...\n");
		exit(1);
	}

	if (err = mytbf_new(&tbf, CPS, BURST)) {
		fprintf(stderr, "mytbf_new(): %s\n", strerror(err));
		exit(1);
	}

	while ((sfd = open(argv[1], O_RDONLY))<0) {
		if (errno!=EINTR) {
			perror("open()");
			exit(1);
		}
	}

	dfd = 1;

	while (1) {
		size = mytbf_fetchtoken(tbf, BUFSIZE);
		while ((len = read(sfd, buf, size))<0) {
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

	mytbf_delete(tbf);

	return 0;
}

