#include <stdio.h>
#include <iostream>

using namespace std;
int main(int argc, char *argv[])
{
	//数组运算符高于指针和引用
	int (*a)[5];
	int  a1[5] = {1,2,3,4,5};
	 
	printf("(*a)= %d    \na1 = %d\n", *a + 2,a1);
	
	char array[10] = "123456789";
	memcpy(&array[1],&array[2],3);
	printf("= %s\n",array);

	char array1[10] = "123456789";
	memmove(&array1[1],&array1[2],3);
	printf("= %s\n",array1);



	char s[11] = "1234567890";
	//char* p1 = s;
	//char* p2 = s+2;
	memcpy(&s[0] + 1, &s[0], 5);
	printf("= %s\n",s);
	
	char s1[11] = "1234567890";
	memmove(&s1[0] + 1, &s1[0], 5);
	printf("= %s\n",s1);

	return 0;
}
