#include <stdio.h>
int fun(int n){
    static int i=1;//一次赋值  在内存中保存 谁都可以使用
    if(n>=5) return n;
    n=n+i;
    i++;
	// fflush(stdout);
	printf("n=%d  i=%d \n",n,i);
	// fflush(stdout);
    return fun(n);
}

int main(int argc, char *argv[])
{
    int x = fun(1);
    printf("%d\n",x);
    return 0;
}


