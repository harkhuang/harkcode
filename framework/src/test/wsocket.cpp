#include "wsocket.h"
#include <time.h>
#include <stdio.h>
#include "linuxfuncdef.h"
#include "linuxwin32api.h"
#include <string.h>
#include <debug.h>
#ifdef _LINUX_

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h> 
#include <sys/ioctl.h>
#include <netdb.h>

#define  _KDDEBUG_ 0

#define HOSTENT hostent	
#endif

#if defined(WIN32) || defined(WIN64)
#pragma comment(lib, "ws2_32.lib")
#include <ws2tcpip.h>
#endif

//add huangkui  
int WaitForSingleObject(void *hHandle, int dwMilliseconds)
{
    return 0;
}

void strupr(char *src)
{
    return (void )src;
}
#pragma pack(push, 1)
typedef struct
{
  CHAR	cVer;
  CHAR	cRepCmd;
  CHAR	cRsv;
  CHAR	cAtyp;
  DWORD	dwDstAddr;
  WORD	wDstPort;
}
WSOCK5_CONNECT;

typedef struct
{
  CHAR	cVer;
  CHAR	cRepCmd;
  WORD	wDstPort;
  DWORD	dwDstAddr;
  CHAR	cNULL;
}
WSOCK4_CONNECT;

#pragma pack(pop)
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
#ifndef __TCP_KEEPALIVE_STRUCT_
#define __TCP_KEEPALIVE_STRUCT_
struct This_tcp_keepalive {
	unsigned  long   onoff;
	unsigned  long   keepalivetime;
	unsigned  long   keepaliveinterval;
};
#define SIO_KEEPALIVE_VALS    _WSAIOW(IOC_VENDOR,4)
#endif

CWSocket::CWSocket()
{
    InitSystemSocket();

    SetInvalidSocket(m_hsocket);
    //udp socket init  other erro 
    SetInvalidSocket(m_hsocketm);
    m_szaddress[0] = 0;
    m_nport = 0;
    m_nerr = 0;  //error number

    m_nconnecttimeout = 10;
    m_szproxyaddress[0] = 0;
    m_nproxyport = 0;
    m_szproxyusername[0] = 0;
    m_szproxypwd[0] = 0;
    m_nproxytype = WSOCKET_PROXY_DIRECT;

    m_bstopsocket = false;
    m_hquit_event = NULL;

    m_nlivetime = 0;
    m_ninterval = 0;
    m_nsockstatus = WSOCKET_STATUS_INVALID;
}

CWSocket::~CWSocket()
{
  UnInitSystemSocket();
}

void CWSocket::Close()
{
  if (!IsInvalidSocket(m_hsocket))
  {
#ifdef _LINUX_  	
    shutdown(m_hsocket, SHUT_RDWR);
    close(m_hsocket);
#else  // _WIN32
    shutdown(m_hsocket, SD_BOTH);
    closesocket(m_hsocket);
#endif    
    
    SetInvalidSocket(m_hsocket);
  }

  if (!IsInvalidSocket(m_hsocketm))
  {
#ifdef _LINUX_  	
    shutdown(m_hsocketm, SHUT_RDWR);
    close(m_hsocketm);
#else  // _WIN32
    shutdown(m_hsocketm, SD_BOTH);
    closesocket(m_hsocketm);
#endif    
    
    SetInvalidSocket(m_hsocketm);
  }
  //m_nerr = 0;
  m_nsockstatus = WSOCKET_STATUS_INVALID;
}
//if null== pszAddress, it is set conn timeout
void CWSocket::SetAddressPort(char *lpszaddress , int nport, int nconnecttimeout)
{
	if(NULL == lpszaddress)
	{
		if(nconnecttimeout > MIN_CONN_TIMEOUT)
		{
			m_nconnecttimeout = nconnecttimeout;
		}
		return;
	}
	
  strncpy(m_szaddress, lpszaddress, sizeof(m_szaddress) - 1);
  m_szaddress[sizeof(m_szaddress) - 1] = 0;
  m_nport = nport;
  m_nconnecttimeout = nconnecttimeout;
}

bool CWSocket::ReConnect()//connect the server
{
  m_nerr = 0;    //Lanq 20110228 
  return Connect();
}


int CWSocket::SendData(char *pbuf, int nlen, int ntimeout)
{
  if (IsInvalidSocket(m_hsocket))
  {
    m_nerr = -1;
    return -1;
  }

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
    //select error
    if (SocketFail(nRet))
    {
      m_nerr = WSAGetLastError();
      nRetCode = -2;
      goto _SOCK_SEND_ERR;
    }//timeout
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

int CWSocket::ReciveData(char *pbuf, int nlen, int ntimeout, bool bdataarriret)
{
  if (IsInvalidSocket(m_hsocket))
  {
    m_nerr = -1;
    return -1;
  }

  int	nRet;
  int	nReaded;
  fd_set	rdevents;
  fd_set	expevents;
  struct timeval	tv;
  struct timeval	*ptv;

  nReaded = 0;
  ptv = NULL;
  
  if (m_bstopsocket)
  {
     return -10;
  }

  int nct = 0;
  m_nsockstatus = WSOCKET_STATUS_RECVING;
  int  nRetCode = 0;
  while (nReaded < nlen)
  {
    if (ntimeout > 0)
    {
      tv.tv_sec = 1;
      tv.tv_usec = 0;
      ptv = &tv;
    }

    FD_ZERO( &rdevents );
    FD_SET(m_hsocket, &rdevents);
    FD_ZERO( &expevents );
    FD_SET(m_hsocket, &expevents);
    nRet = select(m_hsocket + 1, &rdevents, NULL, &expevents, ptv);
    // dbg_log_write1("select one %d %d",m_hsocket,nRet);
    nct ++;

    if (nRet == 0)
    {
      if ((ntimeout >0 && nct >= ntimeout) ||
          (ntimeout <= 0))
      {
        // dbg_log_write1("select error timeout %d %d",ntimeout,nct);
        m_nerr = WSAGetLastError();
        nRetCode = -3;
        goto _SOCK_RECV_ERR;
      }

      if (m_bstopsocket 
		  || (m_hquit_event !=NULL && WaitForSingleObject(m_hquit_event, 0) == WAIT_OBJECT_0) )     //Lanq add m_hQuitEvent 
      {//set statues ??
        m_nerr = -10;
				m_nsockstatus = WSOCKET_STATUS_NORMAL;
        return m_nerr;
      }
      continue;
    }

    //select  error
    if (SocketFail(nRet))
    {
      m_nerr = WSAGetLastError();
      nRetCode = -2;
      goto _SOCK_RECV_ERR;
    }//timeout
    if (FD_ISSET(m_hsocket, &expevents))
    {
      m_nerr = WSAGetLastError();
      nRetCode = -4;
      goto _SOCK_RECV_ERR;
    }
    if (FD_ISSET(m_hsocket, &rdevents))
    {
      nRet = recv(m_hsocket, pbuf + nReaded, nlen - nReaded, 0);
      // dbg_log_write1("select recv left=%d nret=%d\n",nlen - nReaded,nRet);
      if (nRet == SOCKET_ERROR)
      {
        m_nerr = WSAGetLastError();
        nRetCode = -5;
        goto _SOCK_RECV_ERR;
      }
      else if (nRet == 0)
      {
	m_nerr = -6;
	nRetCode = -6;
      	goto _SOCK_RECV_ERR;
      }
      nReaded += nRet;
      nct = 0;
	  if(bdataarriret)
	  {//return  if recv data
	  	break;
	  }
    }
  }
  return nReaded;
 _SOCK_RECV_ERR:
  if(m_nerr != 0)
  {
  	m_nsockstatus = WSOCKET_STATUS_SOCKERROR;
  }
  else
  {//time out
  	m_nsockstatus = WSOCKET_STATUS_NORMAL;
  }
  return nRetCode;	
}

int CWSocket::GetError()
{
  return m_nerr;
}

SOCKET CWSocket::CreateServerSocket(int nport, int nlistencount)
{
      InitSystemSocket();
      SOCKET	Socket;
      struct sockaddr_in	addrsrv;
      INT	iRet;
      unsigned long iReUse;

      Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
      if (IsInvalidSocket(Socket))
      {
        return SOCKET_ERROR;
      }

      memset(&addrsrv, 0, sizeof(sockaddr_in));
      addrsrv.sin_family = AF_INET;
      addrsrv.sin_addr.s_addr = htonl(0);
      addrsrv.sin_port = htons(nport);

      iReUse = 0;
      iRet = SetBlock(Socket,(int)iReUse);
      if (SocketFail(iRet))
      {
        goto __LableError_CreateServerSocket;
      }

    	iReUse = 1;
      iRet = setsockopt(Socket, SOL_SOCKET, SO_REUSEADDR, (const char *) & iReUse, sizeof(int));
      if (SocketFail(iRet))
      {
        goto __LableError_CreateServerSocket;
      }

      iRet = bind(Socket, (struct sockaddr*) & addrsrv, sizeof(sockaddr));
      if (SocketFail(iRet))
      {
        goto __LableError_CreateServerSocket;
      }

      iRet = listen(Socket, nlistencount);
      if (SocketFail(iRet))
      {
        goto __LableError_CreateServerSocket;
      }
      return Socket;

    __LableError_CreateServerSocket:
#ifdef _LINUX_  	
        shutdown(Socket, SHUT_RDWR);
        close(Socket);
#else  // _WIN32
        shutdown(Socket, SD_BOTH);
        closesocket(Socket);
#endif    
      return SOCKET_ERROR;

}

void CWSocket::InitSystemSocket()
{
#if defined(WIN32) || defined(WIN64)	
  WSADATA wsd;
  if (WSAStartup(MAKEWORD(2, 2), &wsd))
  {
    return ;
  }
#endif  
}

void CWSocket::UnInitSystemSocket()
{
#if defined(WIN32) || defined(WIN64)		
  WSACleanup();
#endif
}

int  CWSocket::SetKeepLive(int nlivetime, int ninterval)//milliseond
{
	m_nlivetime = nlivetime;
	m_ninterval = ninterval;
	return 0;
}

int  CWSocket::__SetKeepLive()//milliseond 
{	
#if defined(WIN32) || defined(WIN64)
    int nOption = 1;
    if (m_nlivetime > 0 && m_ninterval > 0)
    {
        if ( setsockopt(m_hsocket, SOL_SOCKET, SO_KEEPALIVE, (const char *)&nOption, sizeof(int)) == SOCKET_ERROR )
        {
#ifdef _KDDEBUG_
	OutputDebugString("CWSocket::__SetKeepLive err -1");
#endif  		
             return -1;
        }
				{
            struct This_tcp_keepalive stKeepaliveIn, stKeepaliveOut;
            DWORD dwBytesReturned;
            stKeepaliveIn.onoff = 1;
            stKeepaliveIn.keepalivetime = m_nlivetime;
            stKeepaliveIn.keepaliveinterval = m_ninterval;
            //This ioctl command is available on Windows 2000 and later versions.
            if (WSAIoctl(
                        m_hsocket,
                        SIO_KEEPALIVE_VALS,
                        &stKeepaliveIn,
                        sizeof(stKeepaliveIn),
                        &stKeepaliveOut,
                        sizeof(stKeepaliveOut),
                        &dwBytesReturned,
                        NULL,
                        NULL
                    ) == SOCKET_ERROR)
            {
#ifdef _KDDEBUG_
	OutputDebugString("CWSocket::__SetKeepLive err");
#endif  	
                return -2;
            }
        }
    }
#ifdef _KDDEBUG_
	char szBuf[256];
	_snprintf(szBuf, sizeof(szBuf)-1, "CWSocket::__SetKeepLive succ, m_nlivetime:%d, m_ninterval:%d", m_nlivetime, m_ninterval);
	OutputDebugString(szBuf);
#endif     
#endif
	return 0;
}

int CWSocket::SetProxy(int nproxytype, char *lpszproxyaddress, int nport, char *lpszuser, char *lpszpwd, int nconnecttimeout)
{
  if (nproxytype < WSOCKET_PROXY_DIRECT || nproxytype >= WSCOKET_PROXY_MAX)
  {
    return -1;
  }

    char szHostIPUse[64] = {0};  memset(szHostIPUse, 0, sizeof(szHostIPUse));
	if (lpszproxyaddress && strlen(lpszproxyaddress) > 0 && !IsIpAddr(lpszproxyaddress))
	{
		HOSTENT *pHostent =	gethostbyname(lpszproxyaddress);
		if( pHostent != NULL)
		{
			_snprintf(szHostIPUse,
				      sizeof(szHostIPUse) - 1, 
					  "%d.%d.%d.%d",
					  (pHostent->h_addr_list[0][0]&0x00ff), 
					  (pHostent->h_addr_list[0][1]&0x00ff),
					  (pHostent->h_addr_list[0][2]&0x00ff), 
					  (pHostent->h_addr_list[0][3]&0x00ff));	

			strncpy(m_szproxyaddress, szHostIPUse, sizeof(m_szproxyaddress) - 1);
		}
		else
		{
			//LoginTrace("Resolve domain name failed  error numeber:%d",szHostIP,WSAGetLastError());
			return -2;
		}
	}
	else if(lpszproxyaddress)
	{
		strncpy(m_szproxyaddress, lpszproxyaddress, sizeof(m_szproxyaddress) - 1);
	}
	
  m_szproxyaddress[sizeof(m_szproxyaddress) - 1] = 0;
	m_szproxyusername[0] =0;
  if (lpszuser)   
  {
	  strncpy(m_szproxyusername, lpszuser, sizeof(m_szproxyusername) - 1);
	  m_szproxyusername[sizeof(m_szproxyusername) - 1] = 0;
  }
	
	m_szproxypwd[0] =0;
	if (lpszpwd)
  {
		strncpy(m_szproxypwd, lpszpwd, sizeof(m_szproxypwd) - 1);
		m_szproxypwd[sizeof(m_szproxypwd) - 1] = 0;
  }

  m_nproxyport = nport;
  m_nproxytype = nproxytype;
  m_nconnecttimeout = nconnecttimeout;
  return 0;
}

int CWSocket::ConnectBySock4(char *lpszserver, int nport, int nconnecttimeout)
{
  WSOCK4_CONNECT	ConnectCmd4;

  if (!DirectConnect(m_szproxyaddress, m_nproxyport, nconnecttimeout))
  {
    return -1;
  }

  memset(&ConnectCmd4, 0, sizeof(ConnectCmd4));
  ConnectCmd4.cVer	= 4;
  ConnectCmd4.cRepCmd	= 1;
  ConnectCmd4.dwDstAddr	= GetInetAddr(lpszserver);
  ConnectCmd4.wDstPort	= htons(nport);

  if (SendData((char *)&ConnectCmd4, sizeof(ConnectCmd4)) <= 0)
  {
    Close();
    return -2;
  }
  if (ReciveData((char *)&ConnectCmd4, sizeof(ConnectCmd4), nconnecttimeout) <= 0)
  {
    Close();
    return -3;
  }

  if (ConnectCmd4.cRepCmd != 90)
  {
    Close();
    return -4;
  }
  return 0;
}

int CWSocket::ConnectBySock5(char *lpszserver, int nport, int nconnecttimeout)
{
  unsigned char	bCommand[32];
  WSOCK5_CONNECT ConnectCmd5;

  if (!DirectConnect(m_szproxyaddress, m_nproxyport, nconnecttimeout))
  {
    return -1;
  }

  bCommand[0] = 5;
  bCommand[1] = 2;
  bCommand[2] = 0;
  bCommand[3] = 2;
  if (SendData((char *)bCommand, 4) <= 0)
  {
    Close();
    return -2;
  }
  if (ReciveData((char *)bCommand, 2, nconnecttimeout) <= 0)
  {
    Close();
    return -3;
  }
  if (bCommand[1] == 0xFF)
  {
    Close();
    return -4;
  }
  if (bCommand[1])
  {
    char	szbuff[1024];
    char *pbuf = szbuff;
    int	nsize = 0;

    if (bCommand[1] != 2)
    {
      Close();
      return -5;
    }
    memset(szbuff, 0, sizeof(szbuff));
    *pbuf = 5;
    ++pbuf;
    *pbuf = (char)strlen(m_szproxyusername);
    ++pbuf;
    strcpy(pbuf, m_szproxyusername);
    pbuf += strlen(m_szproxyusername);
    *pbuf = (char)strlen(m_szproxypwd);
    ++pbuf;
    strcpy(pbuf, m_szproxypwd);
    pbuf += strlen(m_szproxypwd);
    nsize = pbuf - szbuff;
    if (SendData(szbuff, nsize) <= 0)
    {
      Close();
      return -6;
    }
    if (ReciveData((char *)bCommand, 2, nconnecttimeout) <= 0)
    {
      Close();
      return -7;
    }
    if (bCommand[1] != 0x00)
    {
      Close();
      return -8;
    }
  }
  ConnectCmd5.cVer = 5;
  ConnectCmd5.cRepCmd = 1;
  ConnectCmd5.cRsv = 0;
  ConnectCmd5.cAtyp = 1;
  ConnectCmd5.dwDstAddr = GetInetAddr(lpszserver);
  ConnectCmd5.wDstPort = htons(nport);
  if (SendData((char *)&ConnectCmd5, sizeof(ConnectCmd5)) <= 0)
  {
    Close();
    return -9;
  }
  memset(&ConnectCmd5, 0, sizeof(ConnectCmd5));
  if (ReciveData((char *)&ConnectCmd5, sizeof(ConnectCmd5), nconnecttimeout) <= 0)
  {
    Close();
    return -10;
  }
  if (ConnectCmd5.cRepCmd != 0x00)
  {
    Close();
    return -11;
  }
  return 0;
}

int CWSocket::ConnectByHttp(char *lpszserver, int nport, int nconnecttimeout)
{
	if (!DirectConnect(m_szproxyaddress, m_nproxyport, nconnecttimeout))
	 {
	   return -1;
	 }

	char szHttpBuff[1024*5], szTmp[1024*2];  
	memset(szHttpBuff, 0, sizeof(szHttpBuff));
	if (m_nproxytype == WSOCKET_PROXY_HTTP101 || m_nproxytype == WSOCKET_PROXY_HTTP102)
	{
		_snprintf(szTmp, sizeof(szTmp) - 1, " HTTP/1.0\r\n");
	}
	else
	{
		_snprintf(szTmp, sizeof(szTmp) - 1, " HTTP/1.1\r\n");			
	}
	_snprintf(szHttpBuff, 
		      sizeof(szHttpBuff) - 1,
		      "%s%s:%d%s", 
		      "CONNECT ",
		      lpszserver, 
		      nport,
		      szTmp); 
		// add agent pasword and id
	if (m_szproxyusername[0] != 0)
	{
		char szAuth[1024] = {""};
		char szAuthT[1024] = {""}; memset(szAuthT, 0, sizeof(szAuthT));
		_snprintf(szAuthT, sizeof(szAuthT) - 1, "%s:%s", m_szproxyusername, m_szproxypwd);
		to64frombits((unsigned char *)szAuth, (const unsigned char *)szAuthT, strlen(szAuthT));
		_snprintf(szTmp, sizeof(szTmp) - 1, "Proxy-Authorization: Basic %s\r\n", szAuth);
		strcat(szHttpBuff, szTmp);			
	}

	if (WSOCKET_PROXY_HTTP101 == m_nproxytype)
	{// 
		strcat(szHttpBuff,"User-Agent: MyApp/0.1\r\n\r\n");	 
	}
	else if (WSOCKET_PROXY_HTTP102 == m_nproxytype)
	{// 
		strcat(szHttpBuff,"User-Agent:Mozilla/4.0 (compatible; MSIE 5.00; Windows 98)\r\n");
		strcat(szHttpBuff,"Proxy-Connection:Keep-Alive\r\n\r\n");	
	}		
	else if (WSOCKET_PROXY_HTTP112 == m_nproxytype)
	{// 
		strcat(szHttpBuff,"User-Agent:Mozilla/4.0 (compatible; MSIE 5.00; Windows 98)\r\n");
		strcat(szHttpBuff,"Proxy-Connection:Keep-Alive\r\n\r\n");	
	}
	else// if (WSOCKET_PROXY_HTTP111 == m_nproxytype)
	{// 
		strcat(szHttpBuff,"Accept: */*\r\n");
		strcat(szHttpBuff,"Content-Type: text/html\r\n");
		strcat(szHttpBuff,"Proxy-Connection: Keep-Alive\r\n");
		strcat(szHttpBuff,"Content-length: 0\r\n\r\n");
	}
	

	if(SendData(szHttpBuff, strlen(szHttpBuff)) <= 0)
	{
	   Close();
	   return -2;
	}

	memset(szHttpBuff, 0, sizeof(szHttpBuff));
	int nRet = ReciveData(szHttpBuff, sizeof(szHttpBuff) - 1, 5);
	if (nRet != -3 && nRet <= 0)
	{//too much data back
	  Close();
	  return -3;
	}


	strupr(szHttpBuff);
	if(strstr(szHttpBuff, "HTTP") != NULL && strstr(szHttpBuff, "200") != NULL)
	{
		return 0;
	}

	 return -4;

}


bool CWSocket::DirectConnect(char *lpszserver, int nport, int nconnecttimeout)
{
  return __Connect(lpszserver, nport, nconnecttimeout);
}

//connect the server
bool CWSocket::__Connect(char *lpszserver , int nport, int nconnecttimeout)
{
  if (lpszserver[0] == 0 || nport == 0)
  {
    return false;
  }

  Close();      ///if connected colse it and connect again

  sockaddr_in TCP_ServerAddr;

  m_hsocket = socket(AF_INET, SOCK_STREAM, 0);
  if (IsInvalidSocket(m_hsocket))
  {
    m_nerr = WSAGetLastError();      ////create socket error
    return false;
  }
   
  if(m_nlivetime> 0 && m_ninterval > 0)
  {
  	__SetKeepLive();
  }
  
  int i=0;
  int rval;
#if defined(WIN32) || defined(WIN64) 
	i = 0;
	rval = setsockopt(m_hsocket, SOL_SOCKET, SO_DONTLINGER, (char*)&i, sizeof(i));
#endif	
	//i = 1;
	//rval = setsockopt(m_hsocket, SOL_SOCKET, SO_REUSEADDR, (char*)&i, sizeof(i));
	{
		i = 32 *1024;
		rval = setsockopt(m_hsocket, SOL_SOCKET, SO_RCVBUF, (char*)&i, sizeof(i));
	}

	{
		i = 32 *1024;
		rval = setsockopt(m_hsocket, SOL_SOCKET, SO_SNDBUF, (char*)&i, sizeof(i));
	}

    unsigned long ul =1;
    int nret = 0;
    fd_set	wdevents;
    fd_set	rdevents;
    struct timeval	tv;
    int nct = 0;
    int nret_err = -1;
    int nret_err_len = sizeof(nret_err);
    nret = SetBlock(m_hsocket,(int)ul);
  if (SocketFail(nret))
  {
    m_nerr = WSAGetLastError();
    Close();
    return false;
  }


  TCP_ServerAddr.sin_family = AF_INET; 
  TCP_ServerAddr.sin_addr.s_addr = GetInetAddr(lpszserver);
  TCP_ServerAddr.sin_port = htons(nport);
  if (connect(m_hsocket, (sockaddr *)&TCP_ServerAddr, sizeof(TCP_ServerAddr)) == SOCKET_ERROR)
  {	
    m_nerr = WSAGetLastError();      ////connect error
 #ifdef  _KDDEBUG_
	char  szBuf[256] = {0};
 	_snprintf(szBuf, sizeof(szBuf) - 1, "connect fail err:%d", m_nerr);
    //OutputDebugString(szBuf);
 #endif
    if ((m_nerr == WSAEINPROGRESS) || (m_nerr == WSAEWOULDBLOCK) || (m_nerr == WSAEISCONN))
    {}
    else
    {
      Close();
      return false;
    }
  }

  tv.tv_sec = 1;
  tv.tv_usec = 0;
  
  if (m_nconnecttimeout <=5)
  {
    m_nconnecttimeout =5;
  }

#if defined(WIN32) || defined(WIN64)
  while (nct < m_nconnecttimeout)
  {
    nct ++;
    FD_ZERO( &wdevents );
    FD_SET(m_hsocket, &wdevents);
    FD_ZERO( &rdevents );
    FD_SET(m_hsocket, &rdevents);
    tv.tv_sec = 1;
    tv.tv_usec = 0;
    nret = select(m_hsocket + 1, 0, &wdevents, NULL, &tv);

    //time out
    if (nret == 0)
    {
      if ((m_nconnecttimeout >0 && nct >= m_nconnecttimeout) ||
          (m_nconnecttimeout <= 0))
      {
      	m_nerr = -9999;
       // m_nerr = WSAGetLastError();
        Close();
        return false;
      }
      if (m_bstopsocket 
     		  || (m_hquit_event !=NULL && WaitForSingleObject(m_hquit_event, 0) == WAIT_OBJECT_0) )        
      {
        m_nerr = -10;
        Close();
        return false;
      }
      continue;
    }

    //select error
    if (nret<0)
    {
      m_nerr = WSAGetLastError();
      Close();
      return false;
    }
		// purview  decline
    if (!FD_ISSET(m_hsocket, &wdevents))
    {
			m_nerr = WSAGetLastError();
      Close();
      return false;
    }

		
    break;
  }
#else
	while (nct < m_nconnecttimeout)
	{
		nct ++;
		FD_ZERO( &wdevents );
		FD_SET(m_hsocket, &wdevents);
		FD_ZERO( &rdevents );
		FD_SET(m_hsocket, &rdevents);
		tv.tv_sec = 1;
		tv.tv_usec = 0;
		nret = select(m_hsocket + 1, &rdevents, &wdevents, NULL, &tv);

		//time out
		if (nret == 0)
		{
			if ((m_nconnecttimeout >0 && nct >= m_nconnecttimeout) ||
					(m_nconnecttimeout <= 0))
			{
				m_nerr = WSAGetLastError();
				Close();
				return false;
			}

			// 2011 lanq add wsocket recevie quit single
			if (m_bstopsocket 
					|| (m_hquit_event !=NULL && WaitForSingleObject(m_hquit_event, 0) == WAIT_OBJECT_0) ) 			 
			{
				m_nerr = -10;
				Close();
				return false;
			}
			continue;
		}

		//select error
		if (nret<0)
		{
			m_nerr = WSAGetLastError();
			Close();
			return false;
		}

		/**/
		if (FD_ISSET(m_hsocket, &wdevents) || FD_ISSET(m_hsocket, &rdevents))
		{
			nret_err = -1;
			if (getsockopt(m_hsocket,SOL_SOCKET,SO_ERROR,&nret_err,(socklen_t *)&nret_err_len) <0)
			{
				m_nerr = -101;
				Close();
				return false;
			}
			if (nret_err == 0)
			{
				break;
			}
			else
			{
				m_nerr = nret_err;
				Close();
				return false;
			}
		}
		m_nerr = -102;
		Close();
		return false;
	}
#endif
	
  ul = 0;
  nret = SetBlock(m_hsocket, (int)ul);
  
  if (SocketFail(nret))
  {
    m_nerr = WSAGetLastError();
    Close();
    return false;
  }

  return true; 
}


bool CWSocket::Connect(char *lpszaddress , int nport, int nconnecttimeout)
{
	if (lpszaddress[0] ==0 || nport <=0)
	{
		return false;
	}
	m_nerr = 0;

  SetAddressPort(lpszaddress, nport, nconnecttimeout);
  return Connect();
}

bool CWSocket::Connect()
{
	if (m_szaddress[0] ==0 || m_nport <=0)
	{
		return false;
	}

  if (m_nproxytype == WSOCKET_PROXY_DIRECT)
  {
    return DirectConnect(m_szaddress , m_nport, m_nconnecttimeout);
  }
  
  if (m_nproxytype == WSOCKET_PROXY_SOCK4)
  {
    return (ConnectBySock4(m_szaddress , m_nport, m_nconnecttimeout) == 0 ? true : false);
  }

  if (m_nproxytype == WSOCKET_PROXY_SOCK5)
  {
    return (ConnectBySock5(m_szaddress , m_nport, m_nconnecttimeout) == 0 ? true : false);
  }

  // (m_nproxytype == WSOCKET_PROXY_HTTP)
 
  return (ConnectByHttp(m_szaddress , m_nport, m_nconnecttimeout) == 0 ? true : false);
 
}
//#if 1
#if defined(WIN32) || defined(WIN64)
//dwFlag:JL_SENDER_ONLY, JL_RECEIVER_ONLY, JL_BOTH
bool CWSocket::Join(DWORD dwflag)
{
#ifdef _KDDEBUG_
	char  szdebugbuf[256]; szdebugbuf[0] = 0;
#endif
	int nRet = 0;
	int nOptVal = 0;

	Close();
	
	if ((m_hsocket = WSASocket(AF_INET, SOCK_DGRAM, 0, NULL, 0, 
			WSA_FLAG_MULTIPOINT_C_LEAF
			| WSA_FLAG_MULTIPOINT_D_LEAF
			| WSA_FLAG_OVERLAPPED)) == INVALID_SOCKET)
		{
#ifdef _KDDEBUG_
	_snprintf(szdebugbuf, sizeof(szdebugbuf) - 1, "CWSocket::Create SOCK_DGRAM err %d", WSAGetLastError());
	szdebugbuf[sizeof(szdebugbuf) - 1] = 0;
	OutputDebugString(szdebugbuf);
#endif  			
			nRet = SOCKET_ERROR;
			goto __CWSocket_JOIN_Lab;
		}
	
		//socket(AF_INET,	SOCK_RAW,	IPPROTO_ICMP); 
		//if  timeout  is needed  ,set "IPPROTO_ICMP=WSA_FLAG_OVERLAPPED"
		 
			
		nOptVal = 1;
		nRet = setsockopt(m_hsocket, SOL_SOCKET, SO_REUSEADDR, (char *)&nOptVal,sizeof(nOptVal));
		if(SocketFail(nRet))
		{
#ifdef _KDDEBUG_
	_snprintf(szdebugbuf, sizeof(szdebugbuf) - 1, "CWSocket::setsockopt SO_REUSEADDR err %d", WSAGetLastError());
	szdebugbuf[sizeof(szdebugbuf) - 1] = 0;
	OutputDebugString(szdebugbuf);
#endif  
			goto __CWSocket_JOIN_Lab;
		}

		nOptVal = 1;
		nRet = setsockopt(m_hsocket, IPPROTO_IP, IP_MULTICAST_LOOP, (char *)&nOptVal, sizeof(nOptVal));
		if(SocketFail(nRet))
		{
#ifdef _KDDEBUG_
	_snprintf(szdebugbuf, sizeof(szdebugbuf) - 1, "CWSocket::setsockopt IPPROTO_IP err %d", WSAGetLastError());
	szdebugbuf[sizeof(szdebugbuf) - 1] = 0;
	OutputDebugString(szdebugbuf);
#endif  
			goto __CWSocket_JOIN_Lab;
		}

		sockaddr_in ServerAddr; 
		memset((void *)&ServerAddr,0, sizeof(sockaddr_in));
		ServerAddr.sin_family = AF_INET;
		ServerAddr.sin_port = ::ntohs(m_nport);
		//ServerAddr.sin_addr.S_un.S_addr = INADDR_ANY;
		ServerAddr.sin_addr.s_addr	= GetInetAddr(m_szaddress);
		
		if ((m_hsocketm = WSAJoinLeaf(m_hsocket, (SOCKADDR *)&ServerAddr, 
			sizeof(ServerAddr), NULL, NULL, NULL, NULL, 
			dwflag)) == INVALID_SOCKET)
		{
#ifdef _KDDEBUG_
	_snprintf(szdebugbuf, sizeof(szdebugbuf) - 1, "CWSocket::WSAJoinLeaf err %d", WSAGetLastError());
	szdebugbuf[sizeof(szdebugbuf) - 1] = 0;
	OutputDebugString(szdebugbuf);
#endif 
			nRet = SOCKET_ERROR;
			goto __CWSocket_JOIN_Lab;
		}
__CWSocket_JOIN_Lab:
		if(SocketFail(nRet))
		{
			m_nerr = WSAGetLastError();
			return false;
		}
	    return true;
}
#endif

int CWSocket::Stop(bool bstop)
{
  m_bstopsocket = bstop;
  return 0;
}


//=============================================================

void CWSocket::to64frombits(unsigned char *out, const unsigned char *in, int ninlen)
{
	const char base64digits[] =
		"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	for (; ninlen >= 3; ninlen -= 3)
	{
		*out++ = base64digits[in[0] >> 2];
		*out++ = base64digits[((in[0] << 4) & 0x30) | (in[1] >> 4)];
		*out++ = base64digits[((in[1] << 2) & 0x3c) | (in[2] >> 6)];
		*out++ = base64digits[in[2] & 0x3f];
		in += 3;
	}
	if (ninlen > 0)
	{
		unsigned char fragment;

		*out++ = base64digits[in[0] >> 2];
		fragment = (in[0] << 4) & 0x30;
		if (ninlen > 1)
			fragment |= in[1] >> 4;
		*out++ = base64digits[fragment];
		*out++ = (ninlen < 2) ? '=' : base64digits[(in[1] << 2) & 0x3c];
		*out++ = '=';
	}
	*out = '\0';
};


bool CWSocket::IsIpAddr(char *lpszuri)
{
	int  ii = 0;
	int  nLen = strlen(lpszuri);
	for (ii = 0; ii < nLen; ii ++)
	{
		char ch1 = lpszuri[ii];
		if ('.' != ch1)
		{
			if ('9' < ch1 || '0' > ch1)
			{
				return false;
			}
		}
	}
	return true;
}

int CWSocket::SetBlock(SOCKET socket,int nblock)
{
	int nret = -1;
#ifdef _LINUX_	
	nret = ioctl(socket, FIONBIO, &nblock);
#else // _WIN32
	nret = ioctlsocket(socket, FIONBIO, (unsigned long *) &nblock);
#endif	
  return nret;
}

unsigned int CWSocket::GetInetAddr(char *lpszuri)
{
	if (lpszuri == NULL || lpszuri[0] == 0)
	{
		return 0;
	}

	char szipaddress[256];
	szipaddress[0] =0;
	strncpy(szipaddress,lpszuri,sizeof(szipaddress) - 1);
	if (!IsIpAddr(lpszuri))
	{
#ifdef _LINUX_
		hostent *phostent =	NULL;
#else // _WIN32
		HOSTENT *phostent =	NULL;
#endif		
		phostent = gethostbyname(lpszuri);
		if( phostent != NULL)
		{
			_snprintf(szipaddress,
			      sizeof(szipaddress) - 1, 
					  "%d.%d.%d.%d",
					  (phostent->h_addr_list[0][0]&0x00ff), 
					  (phostent->h_addr_list[0][1]&0x00ff),
					  (phostent->h_addr_list[0][2]&0x00ff), 
					  (phostent->h_addr_list[0][3]&0x00ff));	
		}
		else
		{
			//LoginTrace(failed to analyze domain  name number is :%d",szHostIP,WSAGetLastError());
			return 0;
		}
	}
	szipaddress[sizeof(szipaddress) - 1] = 0;
	return inet_addr(szipaddress);
}
bool CWSocket::CheckConnectTime(char *pszAddress , int nPort, int nconnecttimeout,int &nrealconect_tickcount)
{
	bool bret = false;
	nrealconect_tickcount = -1;
	DWORD dwbegin = 0;    //server GetTickCount() time 
	DWORD dwend   = 0;    //server GetTickCount() time 

	dwbegin = GetTickCount();
	bret = Connect(pszAddress , nPort, nconnecttimeout);

	if (!bret)
	{
		return false;
	}

	Close();
	dwend = GetTickCount();
	nrealconect_tickcount = dwend - dwbegin;
	return true;
}

