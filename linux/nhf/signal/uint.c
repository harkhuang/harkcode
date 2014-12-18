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
	struct sigaction sa, osa;

//	signal(SIGINT, handler);

	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;

	sigaction(SIGINT, &sa, &osa);

	while (1) {
		for (i=0;i<5;++i) {
			write(1, "x", 1);
			sleep(1);
		}
		write(1, "\n", 1);
		fflush(stdout);
	}

}

