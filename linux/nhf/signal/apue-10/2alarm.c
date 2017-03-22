 /**********************************************************************
 # File Name:   2alarm.c
 # Version:     1.0
 # Mail:        shiyanhk@gmail.com 
 # Created Time: 2017-03-22	
 ************************************************************************/
#include <stdio.h>
#include <setjmp.h>
#include <unistd.h>
#include "apue.h"

static jmp_buf env_alrm;

static void sig_alrm(int signo)
{
	longjmp(env_alrm, 1);

	D("sig_alrm");
}


unsigned int sleep2(unsigned int nsecs )
{
	D("设置信号默认处理函数");

	if(signal(SIGALRM, sig_alrm) == SIG_ERR)
	{
		return (nsecs );
	}

	D("设置信号默认处理函数");
	if(setjmp (env_alrm) == 0)
	{
		alarm(nsecs);
		pause();
	}
	return(alarm(0));

}

int main(int argc,char **argv)
{

	sleep(5);
	sleep2(2);
	return 0;
}

