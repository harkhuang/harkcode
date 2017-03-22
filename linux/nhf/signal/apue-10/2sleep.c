#include   <setjmp.h>
#include   <signal.h>
#include   <unistd.h>
#include "apue.h"
static jmp_buf  env_alrm;

static void
sig_alrm(int signo)
{
	D("call back set longjmp");
    longjmp(env_alrm, 1);
}

unsigned int
sleep2(unsigned int nsecs)
{
		D("setjmp1.0");
		signal(SIGALRM, sig_alrm);
		D("setjmp1.1");
		setjmp(env_alrm);
		D("setjmp1.2");
        alarm(nsecs);       /* start the timer */
        D("setjmp1.3");
        pause();            /* next caught signal wakes us up */
        D("setjmp1.4");
    
    return(alarm(0));       /* turn off timer, return unslept time */
}


int main(int argc, char const *argv[])
{
	alarm(100);
	D("after sleep(3)");
	sleep2(1);
	pause();
	return 0;
}
