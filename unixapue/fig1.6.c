#include "apue.h"
 

 int main()
 {
	int t;
	t = getppid();
	// 获取父进程id
	printf("getppid() = %d \n",getppid());
	// 获取当前进程id
	printf("getpid() = %d \n",getpid());
	exit(0);
 }