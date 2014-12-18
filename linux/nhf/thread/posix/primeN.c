#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define	LEFT	30000000
#define	RIGHT	30000200

#define	THRNUM	2

static void *thr_prime(void *ptr)
{
	int mark;
	int n=(int)ptr;
	int i, j;

	for (i=LEFT+n;i<=RIGHT;i+=THRNUM) {
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

	for (i=0;i<THRNUM;++i) {
		pthread_join(tid[i], NULL);
	}

	return 0;
}

