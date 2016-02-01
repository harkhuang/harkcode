#include "../apue.h"
/*fork分叉出两个进程    一个子  一个父 通过返回值pid来操作    getpid()当前进程编号, getppid()当前进程父编号*/
int main()
{
	int pid;

	printf("main : pid=%d\n", getpid());

	//创建进程
	pid = fork();
	if(pid < 0)//容错  这个是一个不对的返回值呀
	{
		perror("fork");
		exit(1);
	}
	if(pid == 0)//当返回值是0的时候可以对子进程操作
	{
		//while(1)
		{
			printf("[pid=%d ppid=%d]:hello world\n", 
					getpid(), getppid());
			printf("[pid=%d ppid=%d]:hello world\n", 
					getpid(), getppid());
			exit(1);
		}
	}
	else
		if(pid > 0)//当进程号大于0是对父进程操作
		{
			printf("[pid=%d ppid=%d]:hello\n", getpid(), getppid());
/*			while(1)
			{
				;
			}
		}
*/
	printf("[pid=%d ppid=%d]:end\n", getpid(), getppid());

}





