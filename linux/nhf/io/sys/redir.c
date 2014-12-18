#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int
main()
{
	int fd;

	fd = open("/dev/sda", O_WRONLY|O_TRUNC|O_CREAT, 0666);
	if (fd<0) {
//		perror("open()");
		fprintf(stderr, "[%s:%s/%d]: %s: %s\n", __FILE__, __FUNCTION__, __LINE__, "open()", strerror(errno));
		exit(1);
	}

	dup2(fd, 1);
	if (fd!=1) close(fd);

/************************/
	puts("Hello");
	return 0;
}

