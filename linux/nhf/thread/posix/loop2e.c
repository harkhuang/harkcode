#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

#define	THRNUM	4

static pthread_mutex_t mut[THRNUM];

static int next(int n)
{
	if (n+1==THRNUM) {
		return 0;
	}
	return n+1;
}

static void *thr_func(void *ptr)
{
	int n = (int)ptr;
	char c='a'+n;


	while (1) {
		pthread_mutex_lock(mut+n);
		write(1, &c, 1);
		pthread_mutex_unlock(mut+next(n));
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
		pthread_mutex_init(mut+i, NULL);
		pthread_mutex_lock(mut+i);
		err = pthread_create(tid+i, NULL, thr_func, (void*)i);
		if (err) {
			fprintf(stderr, "pthread_create(): %s\n", strerror(err));
			exit(1);
		}
	}

	pthread_mutex_unlock(mut+0);

	sleep(5);
	exit(0);

}

