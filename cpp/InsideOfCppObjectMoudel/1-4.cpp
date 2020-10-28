#include <stdio.h>

typedef union{
 char c;
 int a;
 int b;
}Demo;

int main(int argc, char **argv)
{
    Demo d;
    //d.c = 'A';
    d.a = 65;
    //d.b = 12;

    printf("size: %d\n", sizeof(d));
    printf("%c %d %d\n", d.c, d.a, d.b);

    return 0;
}
