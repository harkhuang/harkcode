#include<stdio.h>
/*自加运算符的意义*/
int main()
{
	int x = 0;
	int y = x++;/*先把x值带入表达式,再进行自加*/
	printf("x = %d, y = %d\n", x, y);
	printf("x++: %d\n", x++);
	printf("x++: %d\n", x++);
	printf("x++: %d\n", x++);
	printf("x: %d\n", x);
	y++,y++,y++,printf("y++ = %d\n",y);
}

/* 输出结果
x = 1, y = 0
*/