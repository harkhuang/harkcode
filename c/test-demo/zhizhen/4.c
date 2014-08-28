#include<stdio.h>

int main()
{
	int myarray[4]= {1,2,3,0};
	int *p = myarray;
	int *x = p;
	p = p + 1;
	printf("*p = %d, *x = %d\n", *p, *x);
}