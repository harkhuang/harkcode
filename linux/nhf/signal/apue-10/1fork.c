#include "apue.h"
 
void main(void)
{
	pid_t pid;
	pid = fork();
	if (pid>0) {
		printf("daemon on duty!\n");
		exit(0);
	} else
	if (pid<0) {
		printf("Can't fork!\n");
		exit(-1);
	}
	if(pid == 0 )
	{

		for (;;) {
		printf("父进程死了, 剩下我这个孤儿, 被1接管了 ..I am the daemon!\n");
		sleep(3);

	}

	}
}