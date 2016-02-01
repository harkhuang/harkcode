#include "../apue.h"

int main()
{
	pid_t pid;//定义一个进程编号
	int pfid;//定义一个文件指针
	char buf[5];//长度是5的字符数组  能存4个

	pfid = open("file", O_RDONLY);//以只读的方式打开一个文件
	if(pfid < 0)//当pfid小于0的时候容错
	{
		perror("open");
		exit(1);
	}

	pid = fork();//分叉
	if(pid < 0)//容错
	{
		perror("fork");
		exit(1);
	}
	if(pid > 0)//父进程
	{
		read(pfid , buf, 5);//从文件pfid中读取5个字符
		printf("[%d]:buf=%s\n", getpid(),buf);
		wait(NULL);//没有这个就是一个错误的程序  会出现僵尸进程！
						//输出都不好控制  更别说别的了！对吗 对吗！！哈哈哈
		exit(1);
	}
	if(pid == 0)//对信的进程操作  这是一个副本 副本懂吗 
		   		//
				//子进程赋值文件指针 是父进程执行完的 文件 指针位置
				//而且该副本有父进程的一切信息   但是不执行 懂吗 懂吗？？
	{
		read(pfid , buf, 5);//在子进程中读
		printf("[%d]:buf=%s\n", getpid(),buf);
		exit(1);
	}
}






