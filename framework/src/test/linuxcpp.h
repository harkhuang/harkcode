 /********************************************************************
 # File Name:    linuxcpp.h
 # Version:      1.0
 # Mail:         shiyanhk@gmail.com 
 # Created Time: 2016-01-25
 # Description:  nothing to say 
 *********************************************************************/


#ifndef __LINUX_CPLUSCPLUS_INCLUDE__
#define  __LINUX_CPLUSCPLUS_INCLUDE__

#ifdef WIN32

//#include <winsock2.h>
typedef int socklen_t;

typedef long atomic_t;
//typedef sockaddr sockaddr_un;

inline int ATOMIC_Inc(atomic_t *natomic)
{
  return ::InterlockedIncrement(natomic);
}

inline int ATOMIC_Dec(atomic_t *natomic)
{
  return ::InterlockedDecrement(natomic);
}

#define sleep Sleep

inline void usleep(int ncount)
{
	Sleep(ncount /1000);
}

#endif 

#ifdef _LINUX_
#define ASSERT(expr) 
#define _snprintf snprintf
#define _vsnprintf vsnprintf
#define stricmp strcasecmp
#define strnicmp strncasecmp
#define _access access

#include "linuxatomic.h"
 
#include <sys/types.h>
#include <pthread.h>
#include <errno.h>
#include <sys/times.h>
#include <sys/time.h>
#include "linuxsemphore.h"

typedef long LONG;
typedef void * HANDLE;
typedef int  DWORD;
#define MAX_PATH 256
//#define min(a,b) (((a) > (b))?(b):(a))
#define INFINITE -1
#define INVALID_SOCKET -1

#define SD_BOTH SHUT_RDWR
#define closesocket close
#define ioctlsocket ioctl

#define __stdcall

typedef pthread_mutex_t CRITICAL_SECTION;

inline int min(int a, int b)
{
  if ((a)>(b))
  {
    return (b);
  }
  return (a);
}

inline int ATOMIC_Inc(atomic_t *natomic)
{
  return atomic_inc(natomic);
}

inline int ATOMIC_Dec(atomic_t *natomic)
{
  return atomic_dec(natomic);
}


inline int InitializeCriticalSection(CRITICAL_SECTION *lock)
{
// 通常, 我们用一些静态变量来初始化mutex
// fast  PTHREAD_MUTEX_INITIALIZER
// recursive    PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP
// error check  PTHREAD_ERRORCHECK_MUTEX_INITIALIZER_NP
  
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_settype(&attr,PTHREAD_MUTEX_DEFAULT);
    pthread_mutex_init(lock,&attr);
    return 0;  
}

inline int DeleteCriticalSection(CRITICAL_SECTION *lock)
{
	  pthread_mutex_destroy( lock );
    return 0;  
}

inline void EnterCriticalSection(CRITICAL_SECTION *lock)
{
	  pthread_mutex_lock( lock );
}

inline void LeaveCriticalSection(CRITICAL_SECTION *lock)
{
	  pthread_mutex_unlock( lock );
}


inline long GetTickCount()
{
  return clock();
  //  tms tm;
  //  return times(&tm);
}

void Sleep(unsigned int useconds );

#if defined(__linux__)

#define _itoa   itoa
#define __strrev strrev
char* strrev(char* szT);

char* itoa(int value, char*  str, int radix);
#endif


#define WSAGetLastError() errno
#define WSAECONNRESET ENOTCONN
#define WSAEINVAL EINVAL
#define WSAECONNABORTED EINTR
#define WSAENETRESET ECONNRESET
#define WSAEINPROGRESS EINPROGRESS
#define WSAEISCONN EISCONN


int GetComputerName(char *lpBuffer, unsigned long* lpnSize);
int GetModuleFileName( char* sModuleName, char* sFileName, int nSize);
char * getAppPath(char *lpdir);
void getdate(char *datestr,char *format);

#define TRUE true
#define FALSE false

#define WAIT_TIMEOUT -1
#define WAIT_OBJECT_0 1
#define WAIT_FAILED    -2

#endif


#endif  // __LINUX_CPLUSCPLUS_INCLUDE__
