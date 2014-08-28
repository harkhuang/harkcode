#include<stdio.h>
int main()
{
	int myarray[4]= {1,2,3,0};
	int *p = myarray;
	int out = 0;
	int i = 0;
	while (out = (*p)++) 
	{
		if (i++ >= 4) 
		{
			break;
		}
		printf("%d ", out);
		printf("%p\n", (void *)p);
	}
	return 0;
}
//putout  1234