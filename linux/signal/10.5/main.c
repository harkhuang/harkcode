#include <stdio.h>

#include "anytimer.h"

static at_jobfunc_t f1, f2, f3;

int
main()
{
	puts("Begin.");
	at_addjob(5, f1, "aaa");
	at_addjob(2, f2, "bbb");
	at_addjob(7, f1, "ccc");
	puts("OK.");

	while (1) {
		write(1, ".", 1);
		sleep(1);
	}

	return 0;
}

static void f1(void *p)
{
	printf("f1(): %s\n", p);
}

static void f2(void *p)
{
	printf("f2(): %s\n", p);
}

