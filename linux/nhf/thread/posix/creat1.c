#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

static void *func(void *arg)
{
	puts("Thread is working.");

	return NULL;
}

int
main()
{
	pthread_t tid;
	int errcode;

	puts("Begin.");
	errcode = pthread_create(&tid, NULL, func, NULL);
	if (errcode) {
		fprintf(stderr, "pthread_create(): %s\n", strerror(errcode));
		exit(1);
	}
	puts("OK.");

	pthread_join(tid, NULL);

	return 0;
}

