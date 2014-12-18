#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

static void handler(int s)
{
	int i;
	printf("[handler]: %lld\n", &i);
}

int
main()
{
	int i;

	signal(SIGINT, handler);

	printf("[main]: %lld\n", &i);

	while (1) {
		pause();
	}

}

