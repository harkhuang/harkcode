#include<stdio.h>
int main()
{
	int myarray[4]= {1,2,3,0};
	int *p = myarray;
	int out = 0;
	while (out = *p++) 
	{
		 printf("%d\n ", out);
	}
}
