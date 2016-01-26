#ifndef __PLATFORMOS_WSOCKET_INCLUDE_H__
#define __PLATFORMOS_WSOCKET_INCLUDE_H__


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#ifdef _WIN32
#include <winsock2.h>
#else
#include "linuxcplusplus.h"
#include "linuxdatatype.h"
#endif

#define  MIN_CONN_TIMEOUT    3

enum WSOCKET_PROXY
{
  WSOCKET_PROXY_DIRECT = 0,
  WSOCKET_PROXY_SOCK4,
  WSOCKET_PROXY_SOCK5,
  WSOCKET_PROXY_HTTP101,  //http 1.0
  WSOCKET_PROXY_HTTP102,  //HTTP 1.0
  WSOCKET_PROXY_HTTP111,  //HTTP 1.1
  WSOCKET_PROXY_HTTP112,  //HTTP 1.1
  WSCOKET_PROXY_MAX
};

#ifndef  __WSOCKET_STATUS_1_
#define  __WSOCKET_STATUS_1_
enum  WSOCKET_STATUS
{
  WSOCKET_STATUS_NORMAL = 0,
//  WSOCKET_STATUS_INITING,
//  WSOCKET_STATUS_CONNETTING,
  WSOCKET_STATUS_SENDING,
  WSOCKET_STATUS_RECVING,
  WSOCKET_STATUS_INVALID,
  WSOCKET_STATUS_SOCKERROR,
};
#endif

class CWSocket
{
public:
  CWSocket();
  virtual ~CWSocket();

public:
  //This ioctl command is available on Windows 2000 and later versions.
  int  SetKeepLive(int nlivetime, int ninterval);  //milliseond
  int SetProxy(int nproxytype, char *lpszproxyaddress, int nport, char *lpszuser, char *lpszpwd, int nconnecttimeout);

  bool Connect(char *lpszaddress , int nport, int nconnecttimeout = 15);
  bool Connect();
  //加入多播，udp协议，客户端<1>SetAddressPort<2>Join
  //dwFlag:JL_SENDER_ONLY, JL_RECEIVER_ONLY, JL_BOTH
  #ifdef WIN32
  bool Join(DWORD   dwflag = JL_BOTH);
  #endif
  //if null== pszAddress, it is set conn timeout
  void SetAddressPort(char *lpszaddress , int nport, int nconnecttimeout = 15);

  bool ReConnect();
  void Close();

  int SendData(char *pbuf, int nlen, int ntimeout = 20);
  //bDataArriRet, 有收到数据立刻返回
  int ReciveData(char *pbuf, int nlen, int ntimeout = 999999999, bool bdataarriret = false);

  int GetError();

  void  SetQuitEventHandle(HANDLE hQuitEvent)
  {
    m_hquit_event = hQuitEvent;
  }

  inline static bool SocketFail(int nret)
  {
    return (nret == SOCKET_ERROR);
  }

  inline static bool IsInvalidSocket(SOCKET nsocket)
  {
    return ((nsocket == INVALID_SOCKET) || (nsocket <= 0));
  }

  inline static void SetInvalidSocket(SOCKET &nsocket)
  {
    nsocket = INVALID_SOCKET;
  }

  static void InitSystemSocket();
  static void UnInitSystemSocket();
  static SOCKET CreateServerSocket(int nport, int nlistencount = 5);

  int Stop(bool bstop);
  bool IsMeInvalidSocket()
  {
    return IsInvalidSocket(m_hsocket);
  }
// malin 2012.03.21 移动终端与行情平台整合后，
bool CheckConnectTime(char *pszAddress , int nPort, int nconnecttimeout,int &nrealconect_tickcount);

  int  GetStatus()   {  return  m_nsockstatus;  }

  unsigned int GetInetAddr(char *lpszuri);

private:
  int  __SetKeepLive();  //milliseond
  bool __Connect(char *lpszserver , int nport, int nconnecttimeout = 15);
  //bool __Connect();
  bool DirectConnect(char *lpszserver, int nport, int nconnecttimeout);
  int ConnectBySock4(char *lpszserver, int nport, int nconnecttimeout);
  int ConnectBySock5(char *lpszserver, int nport, int nconnecttimeout);
  int ConnectByHttp(char *lpszserver, int nport, int nconnecttimeout);

private:
  static void to64frombits(unsigned char *out, const unsigned char *in, int ninlen);
  bool   IsIpAddr(char * lpszuri);
  static int SetBlock(SOCKET socket,int nblock);

private:
  SOCKET m_hsocket;
  SOCKET m_hsocketm;  //多播组
  char m_szaddress[256];
  int m_nport;
  bool m_bwsastartup;
  int m_nerr;  ///错误号
  int m_nconnecttimeout;

  // proxy info
  char m_szproxyaddress[256];
  int m_nproxyport;
  char m_szproxyusername[64];
  char m_szproxypwd[64];
  int m_nproxytype;

  bool m_bstopsocket;
  HANDLE m_hquit_event;

  int    m_nlivetime;
  int    m_ninterval;
  int    m_nsockstatus;
};

#endif //__PLATFORMOS_WSOCKET_INCLUDE_H__
