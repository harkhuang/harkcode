#include <stdio.h>
#include <signal.h>
#include <stdint.h>

static volatile sig_atomic_t loop=1;

static void alrm_handler(int s)
{
	loop=0;
}

int
main()
{
	int64_t	count;

	count = 0;

	signal(SIGALRM, alrm_handler);
	alarm(5);

	while (loop) {
		count++;
	}

	printf("%lld\n", count);

	return 0;
}

