#include "../apue.h"
//环境变量相当于linux全局变量
//PWD SHELL->命令cd ，

/*putenv(pathname)设置当前环境变量*/
extern char **environ;//定义一个全局的环境变量

int main()
{
	int i, pfid;//定义两个整型
	char *p = NULL;//定义一个字符串指针....

	p = getenv("PWD");//获得当前环境变量  将名字存放在p中
	printf("p=%s\n", p);//打印  p
	
	//参数中ENV＝arg ENV存在时值被修改
	//ENV不存在时 创建该环境变量并赋值
	char pathname[100]="PWD=/root";//将这个文件名字存放再pathname中
	putenv(pathname);//设置当前的环境变量
	p = getenv("PWD");//再次获得当前的环境变量
	printf("p=%s\n", p);//打印环境变量

	
#if 0
	for(i=0; environ[i]!= NULL; i++)//打印出来的是什么??????
	{
		printf("%s\n", environ[i]);
	}
#endif

	exit(0);//退出进程>??
}







