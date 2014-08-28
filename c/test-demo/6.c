#include<stdio.h>
int main()
{
	char chrr1[6] = "1234";
	int num;	
	memcpy((char*)&num,chrr1,4);
	printf("%d/n",&num);
	return 0;
}
