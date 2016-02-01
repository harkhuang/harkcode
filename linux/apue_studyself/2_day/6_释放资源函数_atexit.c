#include "../apue.h"
int *pglob = NULL;//定义一个整型费的指针

void fun(void)
{
	pglob = malloc(10*sizeof(int));//给指针分配空间
	printf("fun is runing\n");//这个函数运行了
	return ;
}
void fun1(void)
{
	free(pglob);//释放堆中内存空间
	printf("fun1\n");//打印函数名
}
void fun2(void)//函数2  打印名字
{
	printf("fun2\n");
}
void fun3(void)//函数3 打印名字
{
	printf("fun3\n");
}
int main()
{
	printf("main start\n");
	//注册退出函数
	//int atexit(void (*pfun)(void));
/*

typedef void (*FUN)(void)
struct node
{
	FUN date;//date
	struct node *next;
}
*/
	//释放资源
	atexit(fun1);//进栈  说明这些函数要在函数结束后调用  相当于析构函数  释放资源
	atexit(fun2);//进栈   这些函数再exit执行后再执行
	atexit(fun3);//进栈    在exit后面调用 但是再_exit后面不调用


	fun();//运行空间分配函数
	printf("main end\n");
	exit(0);
}













