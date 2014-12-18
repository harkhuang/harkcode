#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

#define	LEFT	30000000
#define	RIGHT	30000200

#define	THRNUM	3

static int	job=0;
static pthread_mutex_t	mut_job = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t	cond_job = PTHREAD_COND_INITIALIZER;

static void *thr_prime(void *ptr)
{
	int mark;
	int n=(int)ptr;
	int i, j;

	while (1) {
		pthread_mutex_lock(&mut_job);
		while (job==0) {
			pthread_cond_wait(&cond_job, &mut_job);
		}
		if (job<0) {
			pthread_mutex_unlock(&mut_job);
			break;
		}
		i=job;
		job=0;
		pthread_cond_broadcast(&cond_job);
		pthread_mutex_unlock(&mut_job);
		mark=1;
		for (j=2;j<i/2;++j) {
			if (i%j==0) {
				mark=0;
				break;
			}
		}
		if (mark==1) {
			printf("[%d]: %d is a prime\n", n, i);
		}
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
		err = pthread_create(tid+i, NULL, thr_prime, (void*)i);
		if (err) {
			fprintf(stderr, "pthread_create(): %s\n", strerror(err));
			exit(1);
		}
	}

	for (i=LEFT;i<=RIGHT;++i) {
		pthread_mutex_lock(&mut_job);
		while (job>0) {
			pthread_cond_wait(&cond_job, &mut_job);
		}
		job=i;
		pthread_cond_signal(&cond_job);
		pthread_mutex_unlock(&mut_job);
	}

	pthread_mutex_lock(&mut_job);
	while (job>0) {
		pthread_cond_wait(&cond_job, &mut_job);
	}
	job=-1;
	pthread_cond_broadcast(&cond_job);
	pthread_mutex_unlock(&mut_job);

	for (i=0;i<THRNUM;++i) {
		pthread_join(tid[i], NULL);
	}

	return 0;
}

