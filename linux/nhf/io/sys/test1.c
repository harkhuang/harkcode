#include <stdio.h>

int
main()
{
	putchar('a');
	write(1, "b", 1);
	putchar('a');
	write(1, "b", 1);
	putchar('a');
	write(1, "b", 1);

	return 0;
}

