#include "../apue.h"
#include <setjmp.h>
/*longjump 实现  跨函数的跳转*/
/*longjmp   setjmp         执行了两次选择   每次的选项还不一样*/
jmp_buf jb;//这是个什么类型？？？里面存的是函数指针？？？？

void fun1(void)
{
	printf("fun1 start\n");
	longjmp(jb, 5);//跳哪去来？？？5是什么意思？？？跳后的返回值吗？？？
	printf("fun1 end\n");
}
void fun2(void)
{
	printf("fun2 start\n");
	printf("fun2 end\n");
}
void fun(void)
{
	int ret;
	printf("fun start\n");
	
	ret = setjmp(jb);//这里是一个跳跃点    
	if(ret == 0)//返回值是0的时候对f1操作
	{
		fun1();
	}
	else//否走对2操作  为什么
	{
		fun2();
	}
	printf("fun end ret=%d\n", ret);
}


int main()
{
	fun();
}
