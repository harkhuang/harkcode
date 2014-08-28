/*将float  写到字符串里面去  */
#include<stdio.h>
int main()
{
	float   a;
	char c[4];
	a=0.111;
	memcpy(c,(char *)(&a),4);
	//printf("%f\n",(float)c);
	printf("%f\n", *(float*)c);
}