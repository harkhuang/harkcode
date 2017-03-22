 /**********************************************************************
 # File Name:   1_create.c
 # Version:     1.0
 # Mail:        shiyanhk@gmail.com 
 # Created Time: 2017-03-20	
 ************************************************************************/
#include <stdio.h>
#include <pthread.h>


void *call_back(void *arg)
{
	printf("call back is called ...\n");
	printf("the create arg is %d", ((int *)arg));
	//pthread_exit(100);
}


int main(int argc,char **argv)
{
	pthread_t id;	
	int back;
	void *para =  malloc(4);
	para  = 100;
	pthread_create( &id, NULL,call_back, para);
	pthread_join(id, NULL);
	return 0;
}

