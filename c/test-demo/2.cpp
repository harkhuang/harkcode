#include "apue.h"
#include <sys/stat.h> 
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <signal.h>
static int count = 0;
static struct itimerval oldtv;  //设置时间结构

void sig_alrm(int signo)
{
	printf("signo=%u pid=%lu tid=%lu\n",signo, getpid(), pthread_self());
	return ;
}

void signal_handler(int m)
 {
     count ++;
     printf("%d\n", count);
 }

unsigned long  get_file_size(const char *path)  
{  
    unsigned long filesize = -1;      
    struct stat statbuff;  
    if(stat(path, &statbuff) < 0)
    {  
        return filesize;  
    }
    else
    {  
        filesize = statbuff.st_size;  
    }  
    return filesize;  
} 

int file_cp(const char *src,const char *dest)
{

        char * buf[1024];
    int len;
    int fr,fd;
    int ret;

    fr =open(src,O_RDONLY);

        perror("1");
    fd = open(dest,O_WRONLY) ;

        perror("2");

    while( fr>0 && fd>0 )
        {
                memset(buf, 0, sizeof(buf));
                len = read(fr, buf, sizeof(buf));
                if( len  <  0 )
                    {

      //  perror("3");
                        break;
                    }
                else if(len == 0)
                    {
      //  perror("4");
                        break;
                    }
                ret = write(fd, buf, len);
                if(ret < 0)
                    {

       // perror("5");
                        break;
                    }
        }
        close(fd);
        close(fr);
}
      

char *  get_local_time()
{
	time_t   now;//实例化time_t结构
	struct   tm     *timenow;//实例化tm结构指针
	time(&now);//time函数读取现在的时间(国际标准时间非北京时间)，然后传值给now
	timenow=localtime(&now);//localtime函数把从time取得的时间now换算成你电脑中的时间(就是你设置的地区)
	printf("Local time is %s/n",asctime(timenow));
	return asctime(timenow);
}


void *thread_fun(void *arg)
{
	struct sigaction act,oact;//设置信号
	act.sa_handler = sig_alrm;//
	act.sa_flags = 0;
	sigemptyset(&act.sa_mask);
//	sigaction(SIGALRM, &act, &oact);
	while(1)
	{
		printf("pid=%lu tid=%lu\n", getpid(), pthread_self());
		unsigned long  ret;
		ret=get_file_size("2.cpp");
		
		//sleep(3);
     	struct itimerval itv;
    	itv.it_interval.tv_sec = 5;
        itv.it_interval.tv_usec = 0;
    	itv.it_value.tv_sec = 5;
    	itv.it_value.tv_usec = 0;
    	setitimer(ITIMER_REAL, &itv, &oldtv);

		if(ret>0)
		{
			printf("file  is  too big.....\n");
			get_local_time();
			file_cp("1","2");
		//	sleep(3);
		}
	//	sleep(3);
	}
}

int main()
{
	pthread_t thread;
	pthread_create(&thread, NULL, thread_fun, NULL);
	unsigned long  ret    =	get_file_size("1.cpp");
	printf("file size is  %d\n",ret);
	get_local_time();
	signal(SIGALRM, signal_handler);
	//sleep(3);
	//raise(SIGALRM);//向某一进程发送信号，由进程处理
     //	pthread_kill(thread, SIGALRM);//向某一线程发送信号，由接受线程处理
	pthread_join(thread, NULL);
	//进程接受信号和线程接受信号不同
}
