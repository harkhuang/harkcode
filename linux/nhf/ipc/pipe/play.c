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

	if (argc<2) {
		fprintf(stderr, "Usage...\n");
		exit(1);
	}

	if (pipe(pd)<0) {
		perror("pipe()");
		exit(1);
	}

	pid = fork();
	if (pid<0) {
		perror("fork()");
		exit(1);
	}
	if (pid==0) {
		close(pd[1]);

		fd = open("/dev/null", O_RDWR);
		if (fd<0) {
			perror("open()");
		} else {
			dup2(fd, 1);
			dup2(fd, 2);
			close(fd);
		}

		dup2(pd[0], 0);
		close(pd[0]);

		execl("/usr/local/bin/mpg123", "[player]", "-", NULL);
		perror("execl()");
		exit(1);
	} else {
		close(pd[0]);

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
				ret = write(pd[1], data+pos, len);
				if (ret<0) {
					if (errno==EINTR) {
						continue;
					} else {
						perror("read()");
						exit(1);
					}
				}
				len -= ret;
				pos += ret;
			}
		}

		close(fd);

		close(pd[1]);

		wait(NULL);

		exit(0);
	}
}

