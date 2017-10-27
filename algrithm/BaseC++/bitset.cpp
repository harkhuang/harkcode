#include <stdlib.h>
#include <stdio.h>
struct mybitfields
{
    unsigned short a : 4;
    unsigned short b : 5;
    unsigned short c : 7;
}  test;
 
int  main(void)
{
    int i;
    test.a = 2;
    test.b = 3;
    test.c = 0;
 
    i = *((short *)&test);
    printf("%d\n", i);
	return 0;
}