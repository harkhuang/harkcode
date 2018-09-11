
#include "apue.h"
#define BUFFSIZE 4019


int main()
{
    int n;
    char buf[4019];
    // 最简单的文件内容读取，首先
    while ( (n = read(STDIN_FILENO,buf,BUFFSIZE )  ) > 0 )
        if(write(STDOUT_FILENO,buf,n) != n)
		err_sys("read or write failed..\n");
	if(n<0)
        err_sys("read error");
}
