/*************************************************************************
	> File Name: myserver.c
	> Author: 
	> Mail: 
	> Created Time: Mon Nov 27 15:26:25 2017


	一个非io复用 的最简单的  单个链接socket
 ************************************************************************/



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "proto.h"
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>


#define	BUFSIZE	1024
static void server_job(int newsd)
{
	char buf[BUFSIZE];//定义字符串
	ssize_t len;//定义长度  ssize_t 移植性强  通常定义为int
	int pos, ret;


    
	len = snprintf(buf, BUFSIZE, FMT_STAMP, (long long)time(NULL));
	pos = 0;



    //为什么要用循环?
	while (len>0) {

        //每次发送
        //绑定了socket后就相当于不停的往文件描述符中写又回归了我们的通常状态
		ret = send(newsd, buf+pos, len, 0);
		if (ret<0) {
			if (errno==EINTR) {
				continue;
			} else {
				perror("send()");
				exit(1);
			}
		}

        //针对发送内容长的多次发送
		len -= ret;
		pos += ret;
	}
}

#define	IPSTRSIZE	40

int
main()
{
	int sd, newsd;
	struct sockaddr_in laddr, raddr;
	socklen_t raddr_len;
	char ipstr[IPSTRSIZE];
    //  申请了一个可用的socket描述符   要求是ipv4  流字节=tcp
	// 只是表示在本地申请了一个可用的socket描述符
    sd = socket(AF_INET, SOCK_STREAM, 0 /* IPPROTO_TCP, IPPROTO_SCTP */);
	if (sd<0) {
		perror("socket()");
		exit(1);
	}

    // 用于bind的描述符 
	laddr.sin_family = AF_INET;  //表示ipv4
	laddr.sin_port = htons(atoi(SERVERPORT));//表示端口号

    // 转译ip地址为通用网络字节序  0.0.0.0  表示可以接收任何的ip地址
    inet_pton(AF_INET, "0.0.0.0", &laddr.sin_addr);
	
    //绑定socket  到  对应的  地址和端口号
    //完整的解释一个ip地址的具体意义
    //表示这个ip地址监听的供给使用的具体IP和端口号
    if (bind(sd, (sockaddr*)&laddr, sizeof(laddr))<0) {
		perror("bind()");
		exit(1);
	}
    // sd
	if (listen(sd, 200)<0) {
		perror("listen()");
		exit(1);
	}

	raddr_len = sizeof(raddr);
	while (1) {

        
        //  获取请求链接的地址和端口号 建立链接
        //  回复握手  得到了这个链接
        newsd = accept(sd, (sockaddr *)&raddr, &raddr_len);
		if (newsd<0) {
			if (errno==EINTR) {
				continue;
			} else {
				perror("accept()");
				exit(1);
			}
		} else {
            // 网络到本地字节序的转换函数
			inet_ntop(AF_INET, &raddr.sin_addr, ipstr, IPSTRSIZE);
			printf("=== Client: %s:%d ===\n", ipstr, ntohs(raddr.sin_port));
			
            //拿到文件描述符 去完成job
            server_job(newsd);
            //完成工作关闭描述符
			close(newsd);
		}
	}

	close(sd);

	return 0;
}

