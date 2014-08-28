#ifndef APUE_H
#define APUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <pthread.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <semaphore.h>
#include <sys/mman.h>
#include <sys/socket.h>
#include <netinet/in.h>
#define PORT 6111
struct msgtype
{
	int msg_type;
	char msg_data[50];
};

void sig_fun(int signo)
{
	printf("signo=%d pid=%d tid=%lu\n", signo, getpid(), pthread_self());

	return ;
}


typedef void (*sig_t)(int);
#endif








