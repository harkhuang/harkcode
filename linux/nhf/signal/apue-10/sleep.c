 /**********************************************************************
 # File Name:   sleep.c
 # Version:     1.0
 # Mail:        shiyanhk@gmail.com 
 # Created Time: 2017-03-22	
 ************************************************************************/
#include <stdio.h>
#include "apue.h"

#include     <signal.h>
#include     <unistd.h>

static void
sig_alrm(int signo)
{
    /* nothing to do, just return to wake up the pause */
    printf("call back in sig_alrm\n");
}

unsigned int
sleep1(unsigned int nsecs)
{
	printf("设置信号触发函数\n");
    if (signal(SIGALRM, sig_alrm) == SIG_ERR)
        return(nsecs);
	printf("发送信号\n");
    alarm(nsecs);       /* start the timer */

    printf("挂载等待信号\n");
    pause();            /* next caught signal wakes us up */

	printf("关闭定时\n");
    return(alarm(0));   /* turn off timer, return unslept time */
}

int main()
{


	/*程序弊端  
	1.程序sleep1 覆盖了之前的定时
	2.程序卡死在预先定义的pause()


	*/
	alarm(2);
	D("1");
	sleep(100);
	D("2");
	int a = alarm(2);
	D("3");
 
	sleep1(1);


	//程序最后停在这里 由于第一个46行被sleep1中抹掉的原因  
	//导致 前面闹钟被覆盖 后面pause卡死
	pause();
	return 0;
}