#include "apue.h"
#include <pwd.h>



/* 
不可重入信号 
运行结果: 
hk@hk-desktop:/mnt/github/trunk/linux/nhf/signal/apue-10$ ./a.out 
in signal handler
*/
static void my_alarm(int signo)
{
	struct  passwd *rootptr;
	printf("in signal handler \n");
	if((rootptr = getpwnam("root")) == NULL)
	{
		err_sys("getpwnam(root) error");
	}
	alarm(1);
}

int main(void)
{
	struct passwd *ptr;
	signal(SIGALRM, my_alarm);
	alarm(1);
	for(;;)
	{
		if((ptr = getpwnam("root")) == NULL)
			err_sys("getpwnam error");
		if(strcmp(ptr->pw_name, "root") != 0)
			printf("return value corrupted, pw_name = %s\n", ptr->pw_name);
	}

}