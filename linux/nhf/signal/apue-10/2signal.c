 /**********************************************************************
 # File Name:   signal.c
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

 

	D("sig_int_flag:%d", sig_int_flag);
	sig_int(sig_int_flag);

	//信号没来得及处理  第二次又发送了信号
	signal(SIGINT, sig_int);
	


	//等待结果0的信号处理
	while(sig_int_flag == 0)
	{
		pause();
	}
	D("sig_int_flag:%d", sig_int_flag);
	
	return 0;
}

