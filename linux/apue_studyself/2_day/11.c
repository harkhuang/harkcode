#include "../apue.h"

int main()
{
	pid_t pid;//short类型的进程编号
	int i;

	for(i=0; i<3; i++)//2+4+8=14
	{
		pid = fork();
		printf("pid=%d getpid=%d getppid=%d\n", 
			pid,getpid(), getppid());
	}
}
