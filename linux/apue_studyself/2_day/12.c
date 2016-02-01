#include "../apue.h"

int glob = 10;

int main()
{
	int tmp = 5;//设置临时变量
	pid_t pid;//设置short类型的进程编号

	pid = fork();  //分叉
	switch(pid)
	{
		case -1://容错
		{
			perror("fork");//这个的错误+是什么
			exit(1);//退出进程了
		}
		case 0://新进程操作
		{
			glob+=10;
			tmp+=5;
			printf("[pid=%d]:glob=%d tmp=%d\n", 
					getpid(), glob, tmp);
			exit(1);
		}
		default://父进程操作   两次的tmp不是一个tmp  完全不同的  具体改变方式下节课学
		{
			sleep(3);
			printf("[pid=%d]:glob=%d tmp=%d\n", 
					getpid(), glob, tmp);
			exit(1);

		}
	}

}







