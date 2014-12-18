#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>    //ERRNO mac head file
#include <unistd.h>   // io operationg head file

#define	BUFSIZE	1024

int
main(int argc, char **argv)
{
	int sfd, dfd, ret;
	char buf[BUFSIZE];
	ssize_t len, pos;

	if (argc<3) {
		fprintf(stderr, "Usage...\n");
		exit(1);
	}

	while ((sfd = open(argv[1], O_RDONLY))<0) {
		if (errno!=EINTR) {
			perror("open()");
			exit(1);
		}
	}

	while ((dfd = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC, 0666))<0) {
		if (errno!=EINTR) {
			perror("open()");
			exit(1);
		}
	}

	while (1) {
		len = read(sfd, buf, BUFSIZE);
		if (len<0) {
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
	close(dfd);
	return 0;
}

