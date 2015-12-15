#include<stdio.h>

int main()
{
	int arr[4];
	int i;
	
	int fool = 4;
	//这里非常有趣的是  如果  越界 四个 int  可以容错  越界第五个就进入死循环
	//当  fool<4  正常访问  4<fool<8编译器优化越界   fool>8访问编译器未优化的内存
	for(i=0; i<=fool; i++)
	{
		arr[i] = 0;
		printf("%d\n",arr[i]);
	}
	return 0;
}
