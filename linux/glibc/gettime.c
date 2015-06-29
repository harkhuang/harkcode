#include <time.h>
#include <stdio.h>
int main(void)
{
	time_t t;
	 t = time(NULL);
	 printf("The number of seconds since January 1, 1970 is %ld",t);
	 return 0;
 }