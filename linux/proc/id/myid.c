#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int
main()
{
	printf("real=%d, effective=%d\n", getuid(), geteuid());
	return 0;
}

