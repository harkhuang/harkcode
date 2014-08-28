#include<stdio.h>

int main()
{
	int myarray[4]= {1,2,3,0};
	int *p = myarray;
	int out = 0;
	while (out = *++p)      // 结果  2  3
	//while (out = *p++)     //  结果  1  2  3
	{
		printf("%d ", out);
		printf("%p\n", p);
	}
	return 0;
}