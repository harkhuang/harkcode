#include <stdio.h>
#include <iostream>

using namespace std;
int main()
{
char test1[111] = "123456789";


memcpy(test1+1,test1+2,10);

printf("%s\n",test1);

char test2[100] = "123456789";
memmove(test2+1, test2+2,10);
 
printf("%s\n",test2);
}