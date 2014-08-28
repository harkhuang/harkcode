/*
说明：
1.父进程创建两个消息队列，之后产生子进程，通过消息队列与子进程进行通信。
2.要求对应的linux信号捕获机制，主要是屏蔽SIGINT(ctrl+c)，防止程序退出，
但是并没有删除消息队列，linux系统对消息队列的个数是有限制的。我们要做的
是SIGINT信号捕获之后，先要删除消息队列，并通过kill命令告诉子进程要退出。
之后通过waitpid函数确认子进程全部退出，管理进程才退出。

目的：

*/

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#include <fcntl.h>
#include <dlfcn.h>
#include <stdarg.h>
#include <dirent.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/ipc.h>
#include <sys/shm.h> 
#include <sys/sem.h>
#include <sys/wait.h>
#include <termios.h>
#include <sys/select.h>
#include <iconv.h>
#include <locale.h>


#define FATHER_TYPE 1000

#define EXCEPTION -1		//异常
#define NORMAL 0		//正常
#define MAX_CHILD_NUM 1	//设置子进程数量
#define UNUSED 10		//未占用
#define USED	-10		//占用
#define IDLE	0		//空闲
#define BUSY 1		//正忙
#define DEFAULT -1

/*子进程信息结构体*/
typedef struct{
    int nChildPid;		//子进程pid号
    int nPos;			//数组位置
    int nFlag;		//数组位置是否空闲
    int nStatus;		//当前状态，是死是活！
}StruChildProcInfo;

/*进程管理结构体*/
typedef struct{
	int nCurrentProcNum;					//当前子进程数量
	StruChildProcInfo struChild[MAX_CHILD_NUM];	//子进程信息结构体数组
}StruChildProcCtrl;

/*消息结构体*/
typedef struct{
    int nPid;
    int nPos;
    char szContext[128];
}StruChildMsg;

/*外壳结构体*/
typedef struct{
    long MsgType;			//指定消息类型
    StruChildMsg struMyMsg;		//真正消息内容所在的地方
}StruMsg;

/*全局变量*/
static int gnF2CMsgQueue;	//父进程到子进程消息队列
static int gnC2FMsgQueue;	//子进程到父进程消息队列
static int gnMainPid;	//主进程的pid
static StruMsg struFMsg;		//父进程消息结构体
static StruMsg struCMsg;		//子进程消息结构体
static struct sigaction struAct;		//信号设置
static struct sigaction struOldAct;	//原信号设置

/*函数声明*/
void Init(StruChildProcCtrl *struChildCtrl);
int CreateMsgQueue(int *pnResult);
void DeleteMsgQueue();
void StartChildTask();
void CaptureQuitSignal(int nSignal);

int main(int argc,char **argv)
{
    /*定义*/

    int i;
    int nPid;		//pid值
    int nRet;		//函数返回值
    int nStatus;    //状态
    int nInitFlag=0;
    StruChildProcCtrl struChildCtrl;	//父进程的管理结构体

    /*初始化*/
    i=0;
    nPid=0;
    nRet=0;
    nStatus=0;
    gnMainPid=getpid();

    /*管理结构体初始化*/
    Init(&struChildCtrl);

    /*设置信号处理*/
    struAct.sa_handler=CaptureQuitSignal;
    struAct.sa_flags=0;
    sigfillset(&struAct.sa_mask);
    if(sigaction(SIGINT,&struAct,&struOldAct)==-1)
    {
	printf("[ERRORS] sigaction is failed!\n");
	return EXCEPTION;
    }

    /*创建消息队列*/
    nRet=CreateMsgQueue(&nStatus);
    if(nRet!=NORMAL&&nStatus!=2)
    {
	printf("[ERRORS] CreateMsgQueue is failed!\n");
	return EXCEPTION;
    }
    else
    {
        printf("[INFO] 创建消息队列成功!\n");
    }

    /*产生子进程*/
    while(1)
    {
        if(nInitFlag)
        {
            usleep(50000);
	    /*接受子进程消息*/
	    memset(&struFMsg,0,sizeof(StruMsg));
	    if(msgrcv(gnC2FMsgQueue,(struct msgbuf*)&struFMsg,sizeof(StruChildMsg),FATHER_TYPE+1,IPC_NOWAIT)==-1)
	    {
	        if(errno!=ENOMSG)
	        {
		     printf("[ERRORS] msgrcv is failed!\n");
		     /*这里需要发信号，错误退出之前要处理一些东西*/
		     continue;
	        }
	    }

            usleep(50000);
            /*根据子进程消息做处理 --改变进程状态*/
	    for(i=0;i<MAX_CHILD_NUM;i++)
	    {
	        if(struFMsg.struMyMsg.nPid==struChildCtrl.struChild[i].nChildPid)
	        {
		     struChildCtrl.struChild[i].nStatus=IDLE;
		     break;
	        }
	    } 
         }
	
	/*子进程消息*/
	printf("[INFO] father recv:%s\n",struFMsg.struMyMsg.szContext);
        usleep(50000);

	while(struChildCtrl.nCurrentProcNum<MAX_CHILD_NUM)
	{
            printf("[INFO] 需要产生子进程!\n");
	    nPid=fork();

	    switch(nPid)
	    {
		/*fork 出错*/
		case -1:
			printf("[ERRORS] fork is failed!\n");
		break;

		/*进入子进程*/
		case 0:
                        usleep(50000);
                        printf("[INFO] 子进程进入工作函数!\n");
			StartChildTask();
		break;

		/*进入父进程*/
	 	default:
                        printf("[INFO] 父进程设置!\n");
                        if(!nInitFlag)
                        {
                            nInitFlag=1;
                            printf("[INFO] 初始化设置成功!\n");
                        }

			for(i=0;i<MAX_CHILD_NUM;i++)
			{
			    if(struChildCtrl.struChild[i].nFlag==UNUSED\
				&&struChildCtrl.struChild[i].nChildPid<0)
			    {
			        struChildCtrl.nCurrentProcNum++;
			        struChildCtrl.struChild[i].nFlag=USED;
				 struChildCtrl.struChild[i].nChildPid=nPid;
				 struChildCtrl.struChild[i].nPos=i;
				 struChildCtrl.struChild[i].nStatus=IDLE;
                                 printf("[INFO] %d[%d] 子进程设置成功!\n",struChildCtrl.struChild[i].nChildPid,nPid);
				 break;
			    }
			}
		 break;
	    }//end switch(nPid)
	 }//end while

	/*子进程状态检测*/
        usleep(5000);
        printf("[INFO] 父进程进入子进程状态检测阶段!\n");
	for(i=0;i<MAX_CHILD_NUM;i++)
	{
	    if(struChildCtrl.struChild[i].nChildPid>0)
	    {
		 if(kill(struChildCtrl.struChild[i].nChildPid,0)==-1&&errno==ESRCH)
		 {
			struChildCtrl.nCurrentProcNum--;
			struChildCtrl.struChild[i].nFlag=UNUSED;
			struChildCtrl.struChild[i].nChildPid=-1;
			struChildCtrl.struChild[i].nPos=-1;
			struChildCtrl.struChild[i].nStatus=DEFAULT;
		 }
                 else
                 {
                     printf("[INFO] %d 子进程正常!\n",struChildCtrl.struChild[i].nChildPid);
                 }
	    }
	}

	/*发消息给子进程*/
	for(i=0;i<MAX_CHILD_NUM;i++)
	{
	    if(struChildCtrl.struChild[i].nChildPid>0&&struChildCtrl.struChild[i].nStatus==IDLE)
	    {
                 printf("[INFO] 找到空闲子进程!\n");
		 struChildCtrl.struChild[i].nStatus=BUSY;
		 break;
	    }
	}

	struFMsg.MsgType=struChildCtrl.struChild[i].nChildPid;
	struFMsg.struMyMsg.nPid=struChildCtrl.struChild[i].nChildPid;
	struFMsg.struMyMsg.nPos=i;
	memset(struFMsg.struMyMsg.szContext,0,sizeof(struFMsg.struMyMsg.szContext));
	strcpy(struFMsg.struMyMsg.szContext,"一乡二里，共三夫子，不识四书五经，竟敢教七八九子，十分大胆！");

	if(msgsnd(gnF2CMsgQueue,(struct msgbuf*)&struFMsg,sizeof(StruChildMsg),IPC_NOWAIT)==-1)
	{
	    printf("[ERRORS] msgsnd is failed!\n");
            usleep(50000);
	}
        else
        {
            printf("[INFO] 向子进程发送消息成功!\n");
            usleep(50000);
        }
     }//end while(1)
    
    return 0;
}

/*函数定义*/

void Init(StruChildProcCtrl *struChildCtrl)
{
    int i=0;

    struChildCtrl->nCurrentProcNum=0;
    for(i=0;i<MAX_CHILD_NUM;i++)
    {
	struChildCtrl->struChild[i].nPos=-1;
	struChildCtrl->struChild[i].nChildPid=-1;
	struChildCtrl->struChild[i].nFlag=UNUSED;
	struChildCtrl->struChild[i].nStatus=DEFAULT;
    }
}

int CreateMsgQueue(int *pnResult)
{
	/*父进程到子进程消息队列*/
	gnF2CMsgQueue = msgget(IPC_PRIVATE, IPC_CREAT|0777);
	if(gnF2CMsgQueue == -1)
	{
		printf("[ERRORS][MsgFunc.c]调用msgget函数发生错误![%s]\n",strerror(errno));
		return EXCEPTION;
	}
	
	*pnResult++;

	/*子进程到父进程消息队列*/
	gnC2FMsgQueue = msgget(IPC_PRIVATE,IPC_CREAT|0777);
	if(gnC2FMsgQueue == -1)
	{
		printf("[ERRORS][MsgFunc.c]调用msgget函数发生错误![%s]\n",strerror(errno));
		return EXCEPTION;
	}

	*pnResult++;

	return NORMAL;
}

void StartChildTask()
{
    int nSelfPid;

    nSelfPid=getpid();

    while(1)
    {
	/*阻塞等待父进程消息*/
        printf("[INFO] 等待父进程消息!\n");
        struCMsg.MsgType=nSelfPid;
	if(msgrcv(gnF2CMsgQueue,(struct msgbuf*)&struCMsg,sizeof(StruChildMsg),nSelfPid,0)==-1)
	{
	    printf("[ERRORS]接收父进程消息  msgrcv is failed!\n");
            usleep(5000);
	    continue;
	}

	/*父进程消息*/
	printf("[INFO] 子进程收到recv:%s\n",struCMsg.struMyMsg.szContext);

	/*回射消息给父进程*/
	struCMsg.MsgType=FATHER_TYPE+1;
	memset(struCMsg.struMyMsg.szContext,0,sizeof(StruChildMsg));
	strcpy(struCMsg.struMyMsg.szContext,"十室九贫，凑得八两七毛六分五豪四厘，尚且三心二意，一等下流！");
	if(msgsnd(gnC2FMsgQueue,(struct msgbuf*)&struCMsg,sizeof(StruChildMsg),IPC_NOWAIT)==-1)
	{
	    printf("[ERRORS] 向父进程 msgsnd is failed!\n");
            usleep(5000);
	    continue;
	}
    }

}

void DeleteMsgQueue()
{
    msgctl(gnF2CMsgQueue,IPC_RMID,NULL);	
    msgctl(gnC2FMsgQueue,IPC_RMID,NULL);
}

void CaptureQuitSignal(int nSignal)
{
    kill(0,SIGTERM);

    /*删除消息队列*/
    DeleteMsgQueue();    

    /*恢复信号设置*/
    if(sigaction(SIGINT,&struOldAct,NULL)==-1)
    {
	 printf("[ERRORS] sigaction is failed!\n");
    }

    exit(0);
}
