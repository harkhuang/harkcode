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
	sigset_t set, oset, saveset;

	signal(SIGINT, handler);

	sigemptyset(&set);
	sigaddset(&set, SIGINT);

	sigprocmask(SIG_UNBLOCK, &set, &oset);

	sigprocmask(SIG_BLOCK, &set, &saveset);

	while (1) {
/*
		sigset_t tmpset;
		sigprocmask(SIG_SETMASK, &saveset, &tmpset);
		pause();
		sigprocmask(SIG_SETMASK, &tmpset, NULL);

		ATOMIC:
*/
		sigsuspend(&saveset);
		for (i=0;i<5;++i) {
			write(1, "x", 1);
			sleep(1);
		}
		write(1, "\n", 1);
		fflush(stdout);
	}

	sigprocmask(SIG_SETMASK, &oset, NULL);

	return 0;
}

