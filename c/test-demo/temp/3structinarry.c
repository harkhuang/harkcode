/*结构体中的数组*/
#include<stdio.h>
typedef struct _A
	{
		int i;
		char c[3];
	}A;
int main()
{
	int a=10;
	A  st_a;
	char b[2]={"aa"};
	memcpy(st_a.c,b,2);
	*(st_a.c+2)='\0';
	printf("%s\n",st_a.c);
}