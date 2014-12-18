#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

#define	THRNUM	4

static int id;
static pthread_mutex_t mut_id = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond_id = PTHREAD_COND_INITIALIZER;

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
		pthread_mutex_lock(&mut_id);
		while (id!=n) {
			pthread_cond_wait(&cond_id, &mut_id);
		}
		write(1, &c, 1);
		id = next(n);
		pthread_cond_broadcast(&cond_id);
		pthread_mutex_unlock(&mut_id);
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

