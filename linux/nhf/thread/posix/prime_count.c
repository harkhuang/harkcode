#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

#define	LEFT	30000000
#define	RIGHT	30000200

#define	THRNUM	(RIGHT-LEFT+1)

static int count=0;
static pthread_mutex_t mut_count = PTHREAD_MUTEX_INITIALIZER;

static void *thr_prime(void *ptr)
{
	int mark;

	int i, j;
	
	i=*(int*)ptr;
	mark=1;
	for (j=2;j<i/2;++j) {
		if (i%j==0) {
			mark=0;
			break;
		}
	}
	if (mark==1) {
		pthread_mutex_lock(&mut_count);
		usleep(1);
		count++;
		pthread_mutex_unlock(&mut_count);
	}
	pthread_exit(NULL);
}

int
main()
{
	int i;
	int err;
	pthread_t tid[THRNUM];
	int arg[THRNUM];

	for (i=LEFT;i<=RIGHT;++i) {
		arg[i-LEFT] = i;
		err = pthread_create(tid+(i-LEFT), NULL, thr_prime, arg+(i-LEFT));
		if (err) {
			fprintf(stderr, "pthread_create(): %s\n", strerror(err));
			exit(1);
		}
	}

	for (i=LEFT;i<=RIGHT;++i) {
		pthread_join(tid[i-LEFT], NULL);
	}

	pthread_mutex_destroy(&mut_count);

	printf("%d primes between %d ans %d\n", count, LEFT, RIGHT);

	return 0;
}

