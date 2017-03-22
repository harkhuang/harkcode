 /**********************************************************************
 # File Name:   signal.c
 # Version:     1.0
 # Mail:        shiyanhk@gmail.com 
 # Created Time: 2017-03-22	
 ************************************************************************/
#include <stdio.h>
#include <signal.h>
#include "apue.h"
static void sig_usr(int signo)
{
	if(signo == SIGUSR1)
	{
		printf("call back get sigusr1 .");
	}
	
	else if(signo == SIGUSR2)
	{
		printf("call back get sigusr2 .");
	}
	else
	{
		err_dump("received signal %d\n", signo);
	}
}

int main(int argc,char **argv)
{

	if(signal(SIGUSR1, sig_usr) == SIG_ERR)
	{
		printf("can't get SIGUSR1.\n ");
	}
	if(signal(SIGUSR2, sig_usr) == SIG_ERR)
	{
		printf("can't get SIGUSR2.\n ");
	}
 
	sleep(100);
	
	return 0;
}

