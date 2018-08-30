 /**********************************************************************
 # File Name:   signal.c
 # Version:     1.0
 # Mail:        shiyanhk@gmail.com 
 # Created Time: 2015-08-27	
 ************************************************************************/
#include <stdio.h>
#include <signal.h>
static void prnt()
{
	printf("aaaaa\n");
}
int main(int argc,char **argv)
{
	signal(SIGHUP, prnt);
	
	printf(" singnal() is not blocking");
	
	kill(getpid(),SIGHUP);

	printf(" kill(getpid(),SIGSTP)  is not blocking\n ");

	pause();

	printf("pasue out ");
	return 0;
}

