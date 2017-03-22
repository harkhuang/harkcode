
#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include <string.h>

void fun1(void);
void fun2(void);
jmp_buf jmpbuffer;


int a = 0;
int  main(void)
{
    printf("%d\n", a);
   
    fun2();
    fun1();

    printf("%d\n", a);

    return 1;
} 

void fun1(void)
{ 
    printf("this is fun1.1\n");
    longjmp(jmpbuffer,1);
    printf("this is fun1.2\n");
} 

void fun2(void)
{

    a = setjmp(jmpbuffer);
    printf("this is fun2\n");
}