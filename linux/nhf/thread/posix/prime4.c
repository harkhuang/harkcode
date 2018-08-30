#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

#define	LEFT	30000000
#define	RIGHT	30000200

#define	THRNUM	(RIGHT-LEFT+1)

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
		printf("[%d]: %d is a prime\n", getpid(), i);
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
	pthread_attr_t tattr;

	pthread_attr_init(&tattr);
	pthread_attr_setdetachstate(&tattr, PTHREAD_CREATE_DETACHED);

	for (i=LEFT;i<=RIGHT;++i) {
		arg[i-LEFT] = i;
		err = pthread_create(tid+(i-LEFT), &tattr, thr_prime, arg+(i-LEFT));
		if (err) {
			fprintf(stderr, "pthread_create(): %s\n", strerror(err));
			exit(1);
		}
//		pthread_detach(tid[i-LEFT]);
	}

	pthread_attr_destroy(&tattr);

	pthread_exit(NULL);
}

