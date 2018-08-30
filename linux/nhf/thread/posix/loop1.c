#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

#define	THRNUM	4

static void *thr_func(void *ptr)
{
	char c='a'+(int)ptr;

	while (1) {
		write(1, &c, 1);
	}

	pthread_exit(NULL);
}

int
main()
{
	int i;
	int err;
	pthread_t tid[THRNUM];

	for (i=0;i<THRNUM;++i) {
		err = pthread_create(tid+i, NULL, thr_func, (void*)i);
		if (err) {
			fprintf(stderr, "pthread_create(): %s\n", strerror(err));
			exit(1);
		}
	}

	sleep(5);
	exit(0);

}

