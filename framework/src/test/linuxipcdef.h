#ifndef __L_LINUXIPCDEF_INCLUDE__
#define __L_LINUXIPCDEF_INCLUDE__

#ifdef _LINUX_

#include <sys/types.h>
#include <pthread.h>
#include <errno.h>
#include <sys/times.h>
#include <sys/time.h>
#include <unistd.h>
#include "linuxatomic.h"
#include "linuxsemphore.h"

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

inline int GETATOMIC(atomic_t *natomic)
{
  return natomic->counter;
}

inline int ATOMIC_IncData(atomic_t *natomic,int ndata)
{
	natomic->counter = natomic->counter + ndata;
  return GETATOMIC(natomic);
}

inline int ATOMIC_Init(atomic_t *natomic)
{
	natomic->counter = 0;
  return GETATOMIC(natomic);
}

inline int ATOMIC_Set(atomic_t *natomic,int ndata)
{
  natomic->counter = ndata;
	return GETATOMIC(natomic);
}



inline int InitializeCriticalSection(CRITICAL_SECTION *lock)
{
// 通常, 我们用一些静态变量来初始化mutex
// fast  PTHREAD_MUTEX_INITIALIZER
// recursive    PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP
// error check  PTHREAD_ERRORCHECK_MUTEX_INITIALIZER_NP
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
		// PTHREAD_MUTEX_RECURSIVE
		// PTHREAD_MUTEX_DEFAULT
    pthread_mutexattr_settype(&attr,PTHREAD_MUTEX_RECURSIVE);
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
	struct timeval current;

	gettimeofday(&current, NULL);
	return current.tv_sec*1000+current.tv_usec/1000;
  //return clock();
}

inline void Sleep(unsigned int useconds )
{
    // 1 毫秒（milisecond） = 1000 微秒 （microsecond）.
    // Windows 的 Sleep 使用毫秒（miliseconds）
    // Linux 的 usleep 使用微秒（microsecond）
    // 由于原来的代码是在 Windows 中使用的，所以参数要有一个毫秒到微秒的转换。
    usleep( useconds * 1000 );
}



#endif
#endif  // __L_LINUXIPCDEF_INCLUDE__

