#include "../apue.h"
/*看一共复制了几次子进程*/
int main()
{
	pid_t pid;//short类型的进程编号
	int i;//定义个整型的变量

	for(i=0; i<3; i++)//2 + 4 + 8 =14  有点类似哈夫曼树
	{
		pid = fork();
		printf("pid=%d getpid=%d getppid=%d\n", 
		pid,getpid(), getppid());
	}
}

//为什么打印结果是这样？
//
//pid=10150 getpid=10149 getppid=9485
//pid=10151 getpid=10149 getppid=9485
//pid=10152 getpid=10149 getppid=9485
//james@ubuntu:~/Desktop/apue/2_day$ pid=0 getpid=10152 getppid=1
//pid=0 getpid=10151 getppid=1
//pid=10153 getpid=10151 getppid=1
//pid=0 getpid=10150 getppid=1
//pid=10154 getpid=10150 getppid=1
//pid=10155 getpid=10150 getppid=1
//pid=0 getpid=10153 getppid=1
//pid=0 getpid=10154 getppid=1
//pid=10156 getpid=10154 getppid=1
//pid=0 getpid=10155 getppid=1
//pid=0 getpid=10156 getppid=1
//
