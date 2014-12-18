#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* ls -l /etc/ppp */

int
main()
{
	puts("Begin.");
	fflush(NULL);
	execl("/bin/ls", "ls", "-l", "/etc/ppp", NULL);
	puts("End.");

	return 0;
}

