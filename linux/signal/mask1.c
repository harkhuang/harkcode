#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

static void handler(int s)
{
	write(1, ".", 1);
}

int
main()
{
	int i;
	sigset_t set, oset;

	signal(SIGINT, handler);

	sigemptyset(&set);
	sigaddset(&set, SIGINT);

	sigprocmask(SIG_UNBLOCK, &set, &oset);

	while (1) {
		/* BLOCK */
		sigprocmask(SIG_BLOCK, &set, NULL);
		for (i=0;i<5;++i) {
			write(1, "x", 1);
			sleep(1);
		}
		write(1, "\n", 1);
		fflush(stdout);
		/* UNBLOCK */
		sigprocmask(SIG_UNBLOCK, &set, NULL);
	}

	sigprocmask(SIG_SETMASK, &oset, NULL);

	return 0;
}

