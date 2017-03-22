 /**********************************************************************
 # File Name:   alarm.c
 # Version:     1.0
 # Mail:        shiyanhk@gmail.com 
 # Created Time: 2017-03-22	
 ************************************************************************/
#include <stdio.h>
#include <signal.h>
#include "apue.h"
int sig_int_flag = 0 ;

static void sig_int(int signo)
{
	signal(SIGINT, sig_int);	
	D("signo:%d", signo);
	sig_int_flag = 1;
}

int main(int argc,char **argv)
{

 	

 	D("alarm(2)此处设置2秒钟的闹钟");
	alarm(2);
 
	while(1)
	{
		D("pause()挂起进程,等待闹钟终止程序");
		pause();
	}
 
	
	return 0;
}

