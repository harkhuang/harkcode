#include <stdio.h>

int main()
{
	int a=10;
	//int *p=&a;
    int *p;
	*p=&a;//这里的赋值方式是错误的 因为是对指针所指向内容赋值  你认为存在意义吗   应该是 指针就是个标签  复合类型而已  切忌 切忌
	printf("%p\n",*p);
    return 0;
}
