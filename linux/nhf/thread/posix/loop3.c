#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

#define	THRNUM	4

static pthread_barrier_t barr;

static void *thr_func(void *ptr)
{
	int n = (int)ptr;
	char c='a'+n;


	while (1) {
		write(1, &c, 1);
		sleep(rand()%5);
		pthread_barrier_wait(&barr);
	}

	pthread_exit(NULL);
}

int
main()
{
	int i;
	int err;
	pthread_t tid[THRNUM];

	pthread_barrier_init(&barr, NULL, THRNUM);

	for (i=0;i<THRNUM;++i) {
		err = pthread_create(tid+i, NULL, thr_func, (void*)i);
		if (err) {
			fprintf(stderr, "pthread_create(): %s\n", strerror(err));
			exit(1);
		}
	}

	while (1) pause();

	pthread_barrier_destroy(&barr);

	exit(0);

}

