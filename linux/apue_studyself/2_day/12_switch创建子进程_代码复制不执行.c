#include "../apue.h"

int glob = 10;
/*整个程序都是再子进程中执行的*/
int main()
{
	int tmp = 5;//设置临时变量
	pid_t pid;//设置short类型的进程编号

	pid = fork();  //分叉
	switch(pid)//这样只执行了一次
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
			printf("~[pid=%d]:glob=%d tmp=%d ppid=%d\n", 
					getpid(), glob, tmp,getppid());
			exit(1);//这个进程不在别的进程代码中释放。。
		}
		default://父进程操作   两次的tmp不是一个tmp  完全不同的  具体改变方式下节课学
				//这部分代码是父进程的  尽管一次进入但是还是调用了？？
				//
				//？
				//？
				//？
		{
		//	sleep(3);
			printf("[pid=%d]:glob=%d tmp=%d  ppid=%d\n", 
					getpid(), glob, tmp,getppid());
			exit(1);

		}//default代码段被  子程序共享吗
		//这里父进程没有执行  只有子进程执行了。
		//父进程退出后赋值给了子进程  把子进程交给了init进程管理托管了。。
	}

}


//共享代码段但是并不执行。。。




