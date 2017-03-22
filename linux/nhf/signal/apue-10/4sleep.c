#include "apue.h"
#include   <setjmp.h>
#include   <signal.h>
#include   <unistd.h>

unsigned int        sleep2(unsigned int);
static void         sig_int(int);

static jmp_buf  env_alrm; 
int
main(void)
{
    unsigned int        unslept;
    alarm(1);
//   if (signal(SIGINT, sig_int) == SIG_ERR)
//        err_sys("signal(SIGINT) error");
//   unslept = sleep2(5);
    
    unslept = sleep(10000);
    printf("sleep2 returned: %u\n", unslept);
    exit(0);
    return 0;
}

static void
sig_int(int signo)
{
    int            i, j;
    volatile int   k;

    /*
     * Tune these loops to run for more than 5 seconds
     * on whatever system this test program is run.
     */
    printf("\nsig_int starting\n");
    for (i = 0; i < 300000; i++)
        for (j = 0; j < 4000; j++)
            k += i * j;
    printf("sig_int finished\n");
}

static void
sig_alrm(int signo)
{
 
    longjmp(env_alrm, 1);
 
}

unsigned int
sleep2(unsigned int nsecs)
{
    if (signal(SIGALRM, sig_alrm) == SIG_ERR)
        return(nsecs);
    if (setjmp(env_alrm) == 0) {
        alarm(nsecs);       /* start the timer */
        pause();            /* next caught signal wakes us up */
    }
    return(alarm(0));       /* turn off timer, return unslept time */
}

