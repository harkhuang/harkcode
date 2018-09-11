#include "apue.h"
#include <sys/wait.h>

int
main(void)
{
	char buf[MAXLINE];
	int status;
	pid_t pid;

	printf("%% ");
	while(fgets(buf,MAXLINE,stdin ) != NULL ){
		// set buffer end
		if(buf[strlen(buf) - 1] == '\n')
			buf[strlen(buf) -1] = 0;
		
		// make process
		if((pid = fork() < 0)){
			err_sys("fork erro");
		} else if (pid == 0 ){ //chilid
			execlp(buf,buf,(char *) 0);
			err_ret("could't execute:%s",buf);
			exit(127);
		}

		//   pa pa process
		if((pid = waitpid(pid, &status, 0)) < 0)
			err_sys("waitpid error");
		printf("%%");
	}
	exit(0);
}