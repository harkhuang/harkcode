 /**********************************************************************
 # File Name:   vss_v5_client.c
 # Version:     1.0
 # Mail:        shiyanhk@gmail.com 
 # Created Time: 2015-11-24	
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "proto.h"


int recv_v5_binary()
{


}



int main(int argc,char **argv)
{
	int sd;
	struct sockaddr_in raddr;
	long long stamp;
	FILE *fp;

	sd = socket(AF_INET, SOCK_STREAM, 0);
	if (sd<0) {
		perror("socket()");
		exit(1);
	}

	raddr.sin_family = AF_INET;
	raddr.sin_port = htons(atoi(SERVERPORT));
	inet_pton(AF_INET, SERVERIP, &raddr.sin_addr);
	if (connect(sd, (void*)&raddr, sizeof(raddr))<0) {
		perror("connect()");
		exit(1);
	}

	fp = fdopen(sd, "r+");
	if (fp==NULL) {
		perror("fdopen()");
		exit(1);
	}
	elses {
		printf("connect ok  IP:%s PORT:%s",SERVERIP, SERVERPORT);
	}
	

	return 0;
}

int SendData(char *pbuf, int nlen, int ntimeout)
{

  int nRet;
  int	nSended;
  fd_set	wrevents;
  fd_set	expevents;
  struct timeval	tv;
  struct timeval	*ptv;

  nSended = 0;
  ptv = NULL;
  if (ntimeout > 0)
  {
    tv.tv_sec = ntimeout;
    tv.tv_usec = 0;
    ptv = &tv;
  }

  if (m_bstopsocket)
  {
     return -10;
  }

  m_nsockstatus = WSOCKET_STATUS_SENDING;
  int  nRetCode = 0;
  while (nSended < nlen)
  {
    FD_ZERO( &wrevents );
    FD_SET(m_hsocket, &wrevents);
    FD_ZERO( &expevents );
    FD_SET(m_hsocket, &expevents);
    nRet = select(m_hsocket + 1, NULL, &wrevents, &expevents, ptv);
    //select·¢Éú´íÎó
    if (SocketFail(nRet))
    {
      m_nerr = WSAGetLastError();
      nRetCode = -2;
      goto _SOCK_SEND_ERR;
    }//³¬Ê±
    else if (nRet == 0)
    {
      m_nerr = WSAGetLastError();
      nRetCode = -3;
      goto _SOCK_SEND_ERR;
    }
    if (FD_ISSET(m_hsocket, &expevents))
    {
      m_nerr = WSAGetLastError();
      nRetCode = -4;
      goto _SOCK_SEND_ERR;
    }
    if (FD_ISSET(m_hsocket, &wrevents))
    {
      nRet = send(m_hsocket, pbuf + nSended, nlen - nSended, 0);
      if (nRet == SOCKET_ERROR)
      {
        m_nerr = WSAGetLastError();
        nRetCode = -5;
        goto _SOCK_SEND_ERR;
      }
      nSended += nRet;
    }
  }
  return nSended;

_SOCK_SEND_ERR:
  m_nsockstatus = WSOCKET_STATUS_SOCKERROR;
  return nRetCode;
}