#include "apue.h"
#define MAX_CHILD 9
void main(void)
{
	pid_t pid;
	int n;
	printf("hello\n");
	n = 0;
	do 
	{
	    pid = fork();
		n++;
	    switch (pid) 
	    {
			case -1:
				printf("failure!\n");
				exit(-1);
				break;

			case 0:
				printf("I am child %d!\n",n);
				break;

			default:
				printf("my child is %d\n",pid); 
				break;
		}
	} 	while (pid!=0&&n);
	if (pid>0) exit(0);//结束父进程

	pause(); //让进程处于挂载状态
}