#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <fcntl.h>

#define	DATASIZE	1024

int
main(int argc, char **argv)
{
	int ret;
	int pd[2], fd;
	pid_t pid;
	char data[DATASIZE];
	int pos, len;
	FILE *play_fp;

	if (argc<2) {
		fprintf(stderr, "Usage...\n");
		exit(1);
	}

	play_fp = popen("/usr/local/bin/mpg123 - > /dev/null 2>&1", "w");
	if (play_fp==NULL) {
		perror("popen()");
		exit(1);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd<0) {
		perror("open()");
		exit(1);
	}

	while (1) {
		len = read(fd, data, DATASIZE);
		if (len<0) {
			if (errno==EINTR) {
				continue;
			} else {
				perror("read()");
				exit(1);
			}
		}
		if (len==0) {
			break;
		}
		pos = 0;
		while (len>0) {
			ret = fwrite(data+pos, 1, len, play_fp);
			if (ret<0) {
				perror("fwrite()");
				exit(1);
			}
		}
		len -= ret;
		pos += ret;
	}

	close(fd);

	pclose(play_fp);

	exit(0);
}

