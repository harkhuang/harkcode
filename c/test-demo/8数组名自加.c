#include<stdio.h>


	void fun(int a[])
	{
		a++;//没问题，相当于int *a; a++;
	}
int main()
{
	int b[];
	*b++;

	return 0;

}