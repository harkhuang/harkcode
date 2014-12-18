#include <stdio.h>

int
main()
{
	int i;

	for (i=0;i<5;++i) {
		putchar('x');
		fflush(stdout);
		sleep(1);
	}
	putchar('\n');

	return 0;
}

