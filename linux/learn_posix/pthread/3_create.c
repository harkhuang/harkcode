#include <pthread.h>
#include <stdio.h>
#define NUM_THREADS     5

void *PrintHello(void *threadid)
{
   int* tid;
   tid = (int *)threadid;
   printf("Hello World! It's me, thread #%d!\n", *tid);
   pthread_exit(1);
}

int main (int argc, char *argv[])
{
   pthread_t threads[NUM_THREADS];
   int rc, t;
   int *taskids[NUM_THREADS];
	for(t=0; t<NUM_THREADS; t++)
	{
		taskids[t] = (int *) malloc(sizeof(int));
		*taskids[t] = t;
		printf("Creating thread %d\n", t);
		rc = pthread_create(&threads[t], NULL, PrintHello, (void *) taskids[t]);
	}
	int rett;
	int *p = &rett;
    void **ret = (void **)malloc (4); 
    pthread_join(threads[0], ret);
	//printf("thread  retruen value is #%d!\n", (void**)p);
	printf("thread  retruen value is #%d!\n", (int *)*ret);
	pthread_exit(NULL);
}




