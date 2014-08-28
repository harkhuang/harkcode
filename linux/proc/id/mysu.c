#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

/* mysu uid cmd ... */

int
main(int argc, char **argv)
{
	setuid(atoi(argv[1]));

	execvp(argv[2], &argv[2]);
	
	return 0;
}

