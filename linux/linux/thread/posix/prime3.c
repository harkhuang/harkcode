#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define	LEFT	30000000
#define	RIGHT	30000200

#define	THRNUM	(RIGHT-LEFT+1)

static void *thr_prime(void *ptr)
{
	int mark;

	int i, j;
	
	i=(int)ptr;
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

	for (i=LEFT;i<=RIGHT;++i) {
		err = pthread_create(tid+(i-LEFT), NULL, thr_prime, (void*)i);
		if (err) {
			fprintf(stderr, "pthread_create(): %s\n", strerror(err));
			exit(1);
		}
	}

	for (i=LEFT;i<=RIGHT;++i) {
		pthread_join(tid[i-LEFT], NULL);
	}

	return 0;
}

