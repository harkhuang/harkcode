#include <stdio.h>
int fun(int n){
	static int i=1;
	if(n>=5) return n;
	n=n+i;
	i++;
	printf("n %d  i%d \n",n,i);
	
	return fun(n);
}



int main(int argc, char *argv[])
{

	
	printf("%d\n",fun(5));
	
	return 0;
}
