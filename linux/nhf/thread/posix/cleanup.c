#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

static void clup_f1(void *p)
{
	printf("clup_f1: %s\n", p);
}

static void *func(void *arg)
{
	puts("Thread is working.");

	pthread_cleanup_push(clup_f1, "aaa");
	pthread_cleanup_push(clup_f1, "bbb");
	pthread_cleanup_push(clup_f1, "ccc");

	puts("Thread is over.");

//	return NULL;
	while (1) pause();
	pthread_exit(NULL);

	pthread_cleanup_pop(0);
	pthread_cleanup_pop(0);
	pthread_cleanup_pop(0);
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

	sleep(5);
	pthread_cancel(tid);

	pthread_join(tid, NULL);

	return 0;
}

