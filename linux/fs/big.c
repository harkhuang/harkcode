#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

int
main(int argc, char **argv)
{
	int fd;

	if (argc<2) {
		fprintf(stderr, "Usage...\n");
		exit(1);
	}

	fd = open(argv[1], O_WRONLY|O_CREAT|O_EXCL, 0600);
	if (fd<0) {
		perror("open()");
		exit(1);
	}
/*
	lseek(fd, 5LL*1024LL*1024LL*1024LL-1LL, SEEK_SET);
	write(fd, "", 1);	*/

	ftruncate(fd, 5LL*1024LL*1024LL*1024LL);

	close(fd);

	return 0;
}

