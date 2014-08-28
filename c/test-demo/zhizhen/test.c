#include<stdio.h>

int main()
{
	int myarray[4]= {1,2,3,0};
	*p = myarray;
	int i = 0;
	int out = 0;
	while (out = ++(*p)) 
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