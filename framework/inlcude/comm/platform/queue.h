#ifndef __CQueue_h_include__
#define __CQueue_h_include__

#include <deque>


#if defined(WIN32) || defined(WIN64)
#include <windows.h>
#elif defined(_APPLE_)
#include "iossemaphore.h"
#else
#include <semaphore.h>
#endif
#include "linuxcplusplus.h"

#define USE_BASEQUEUE

#ifdef _LINUX_
typedef pthread_mutex_t TY_L_Q_LOCK;
typedef sem_t TY_L_Q_HANDLE;
typedef sem_t* TY_L_Q_PHANDLE;
#else
typedef CRITICAL_SECTION TY_L_Q_LOCK;
typedef HANDLE TY_L_Q_HANDLE;
typedef HANDLE TY_L_Q_PHANDLE;
#endif

template < class T , int DefaultData = 0 >
class CQueue
{
public:
  CQueue(int nlimit = 100000)
  {
#ifdef _LINUX_
    sem_init(&handles[SemaphoreIndex], 0, 0);
    sem_init(&handles[StopperIndex], 0, 0);
#else
    handles[SemaphoreIndex] = ::CreateSemaphore(NULL, 0, nlimit, NULL);
    handles[StopperIndex] = ::CreateEvent(NULL, true, false, NULL);
#endif
    InitializeCriticalSection(&lock);

    m_userlen = 0;
    m_pgrouphandle = 0;
    m_nmaxsize = nlimit;
#ifdef USE_BASEQUEUE
    m_nqueuesize = 0;
#else
    m_nsize = 0L;
#endif
  }

  virtual ~CQueue()
  {
#ifdef _LINUX_
    sem_destroy(&handles[SemaphoreIndex]);
    sem_destroy(&handles[StopperIndex]);
#else
    ::CloseHandle(handles[SemaphoreIndex]);
    ::CloseHandle(handles[StopperIndex]);
#endif
    DeleteCriticalSection(&lock);
  }

  int AddTail(T p,bool bsignal = true)
  {
    int result = -1;
#ifdef USE_BASEQUEUE
    EnterCriticalSection(&lock);
    if (m_nqueuesize >= m_nmaxsize)
    {
      LeaveCriticalSection(&lock);
      return 0;
    }

    queue.push_back(p);
    m_nqueuesize ++;
    LeaveCriticalSection(&lock);

		if (bsignal)
		{
#ifdef _LINUX_
    result = sem_post(&handles[SemaphoreIndex]);
    result = !result;
#else
	result = ::ReleaseSemaphore(handles[SemaphoreIndex], 1, NULL);
#endif
		}
		else
		{
			result = 0;
		}

#else
    ::InterlockedIncrement(&m_nsize);
    EnterCriticalSection(&lock);
    queue.push_back(p);
		if (bsignal)
		{
	    result = ::ReleaseSemaphore(handles[SemaphoreIndex], 1, NULL);
	    if (!result)
	    {
	      queue.pop_back();
	      ::InterlockedDecrement(&m_nsize);
	    }
		}
		else
		{
			result = 0;
		}
    LeaveCriticalSection(&lock);
#endif

		if (bsignal)
		{
			AddGroupHandle();
		}
    return result;
  }


  T RemoveHead(int ntimeout = -1)
  {
    T result = DefaultData;
    int nret = 0;
#ifdef _LINUX_
    if (ntimeout == -1)
    {
      nret = sem_wait(&handles[SemaphoreIndex]);
    }
    else if (ntimeout == 0)
    {
      if (sem_trywait(&handles[SemaphoreIndex]) == 0)
      {
        EnterCriticalSection( &lock );
        result = *(queue.begin());
        queue.pop_front();
        m_nqueuesize --;
        LeaveCriticalSection( &lock );
      }
      return result;
    }
	  else
    {
#ifdef _APPLE_
			mach_timespec_t ts;
			ts.tv_sec = (ntimeout / 1000 );         //加上等待时间的秒数
			ts.tv_nsec = ( ntimeout % 1000 ) * 1000;  //加上等待时间纳秒数
#else
			timespec ts;
			ts.tv_sec = time(NULL) + (ntimeout / 1000 );         //加上等待时间的秒数
			ts.tv_nsec = ( ntimeout % 1000 ) * 1000;  //加上等待时间纳秒数
#endif
			nret = sem_timedwait( (sem_t *) & handles[SemaphoreIndex], &ts );
	  }
	if (nret == 0)
	{
		EnterCriticalSection( &lock );
                // 判断是否退出
                if (sem_trywait(&handles[StopperIndex]) == 0)
                {
                     LeaveCriticalSection( &lock );
                     return result;
                }
		result = *(queue.begin());
		queue.pop_front();
		m_nqueuesize --;
		LeaveCriticalSection( &lock );
	}
#else
switch (::WaitForMultipleObjects(2, handles, FALSE, ntimeout))
    {
    case SemaphoreIndex:
#ifdef USE_BASEQUEUE
      EnterCriticalSection(&lock);
      result = *(queue.begin());
      queue.pop_front();
      m_nqueuesize --;
      LeaveCriticalSection(&lock);
#else
		EnterCriticalSection(&lock);
    result = *(queue.begin());
    queue.pop_front();
    LeaveCriticalSection(&lock);

    InterlockedDecrement(&m_nsize);
#endif
      break;
    case StopperIndex:
      break;

    case WAIT_TIMEOUT:
    default:
      break;
    }
#endif
    return result;
  }

  void shutdown()
  {
#ifdef _LINUX_
    int i = 0;
    for (i = 0; i < 100; i++)
    {
      sem_post(&handles[StopperIndex]);
    }
    for (i = 0; i < 100; i++)
    {
      sem_post(&handles[SemaphoreIndex]);
    }
#else
    ::SetEvent(handles[StopperIndex]);
#endif
  }

  // add by lium 2009/03/20 重新初始化数据
  void ReUse()
  {
#ifdef _LINUX_
		sem_trywait(&handles[StopperIndex]);
                sem_destroy(&handles[SemaphoreIndex]);
		sem_destroy(&handles[StopperIndex]);
                sem_init(&handles[SemaphoreIndex], 0, 0);
		sem_init(&handles[StopperIndex], 0, 0);
#else
    ::ResetEvent(handles[StopperIndex]);
    ::CloseHandle(handles[SemaphoreIndex]);
    ::CloseHandle(handles[StopperIndex]);
    #ifdef USE_BASEQUEUE
		handles[SemaphoreIndex] = ::CreateSemaphore(NULL, 0, m_nmaxsize, NULL);
    #else
		handles[SemaphoreIndex] = ::CreateSemaphore(NULL, 0, 100000, NULL);
    #endif
		handles[StopperIndex] = ::CreateEvent(NULL, true, false, NULL);
#endif
  }
  T RemoveRealHead(bool bsignal =true)
  {
    T result = DefaultData;

#ifdef _LINUX_
	#ifdef USE_BASEQUEUE
		EnterCriticalSection(&lock);
		if (m_nqueuesize>0)
		{
			if (bsignal)
			{
			  sem_trywait(&handles[SemaphoreIndex]);
			}
			result = *(queue.begin());
			queue.pop_front();
			m_nqueuesize --;
		}
		LeaveCriticalSection(&lock);
	#else
		EnterCriticalSection(&lock);
		if (queue.size()>0)
		{
			if (bsignal)
			{
		  	sem_trywait(&handles[SemaphoreIndex]);
			}
			result = *(queue.begin());
			queue.pop_front();
		}
		LeaveCriticalSection(&lock);

		InterlockedDecrement(&m_nsize);
	#endif
#else
	#ifdef USE_BASEQUEUE
		EnterCriticalSection(&lock);
		if (m_nqueuesize>0)
		{
			result = *(queue.begin());
			queue.pop_front();
			m_nqueuesize --;
		}
		LeaveCriticalSection(&lock);
	#else
		EnterCriticalSection(&lock);
		if (queue.size()>0)
		{
	  	//WaitForSingleObject(handles[SemaphoreIndex],0);

			result = *(queue.begin());
			queue.pop_front();
			InterlockedDecrement(&m_nsize);
		}
		LeaveCriticalSection(&lock);

		
	#endif
#endif
    return result;
  }

	int GetMaxLength()
	{
		return m_nmaxsize;
	}

  int GetLength()
  {
#ifdef USE_BASEQUEUE
    return m_nqueuesize;
#else
    return m_nsize;
#endif
  }
  int GetUserLength()
  {
    return m_userlen;
  }
  void SetUserLength(int nlen)
  {
    m_userlen = nlen;
  }
	#ifdef _WIN32
	HANDLE GetStopHandles()
  {
  	return handles[StopperIndex];
  }

  HANDLE GetEventHandles()
  {
	  return handles[SemaphoreIndex];
  }
	#else
	HANDLE GetStopHandles()
  {
  	return (HANDLE)&handles[StopperIndex];
  }

  HANDLE GetEventHandles()
  {
	  return (HANDLE)&handles[SemaphoreIndex];
  }
	#endif

  int SetGroupHandle(HANDLE hgrouphandle)
  {
  	m_pgrouphandle = (TY_L_Q_PHANDLE)hgrouphandle;
  	return 0;
  }

  // 如果有互斥量,直接设置互斥量
  int AddGroupHandle()
  {
 		if (m_pgrouphandle)
		{
#ifdef _LINUX_
      sem_post(m_pgrouphandle);
#else
	    ::ReleaseSemaphore(m_pgrouphandle, 1, NULL);
#endif
			return 0;
		}
		return -1;

  }

protected:
  enum {StopperIndex = 0, SemaphoreIndex};

  TY_L_Q_HANDLE handles[2];
  TY_L_Q_LOCK lock;
  TY_L_Q_PHANDLE m_pgrouphandle;
  typename std::deque < T > queue;
  int m_userlen;
  int m_nmaxsize;

#ifdef USE_BASEQUEUE
  int m_nqueuesize;
#else
  LONG m_nsize;
#endif
};

#endif
