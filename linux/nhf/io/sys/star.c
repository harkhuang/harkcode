#include <stdio.h>

int
main()
{
	int i;

	for (i=0;i<5;++i) {
		write(1, "x", 1);
		sleep(1);
	}
	write(1, "\n", 1);

	return 0;
}

