#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

static void *func(void *arg)
{
	while (1) pause();

	return NULL;
}

int
main()
{
	pthread_t tid;
	int errcode;
	int i;
	pthread_attr_t attr_small_stack;

	pthread_attr_init(&attr_small_stack);
	pthread_attr_setstacksize(&attr_small_stack, 10240);

	puts("Begin.");
	for (i=0;;++i) {
		errcode = pthread_create(&tid, &attr_small_stack, func, NULL);
		if (errcode) {
			fprintf(stderr, "pthread_create(): %s\n", strerror(errcode));
			break;
		}
		printf("%d\n", i);
	}

	printf("%d\n", i);

	return 0;
}

