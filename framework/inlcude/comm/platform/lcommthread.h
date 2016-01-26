
#ifndef THREAD_H
#define THREAD_H

#include <errno.h>

#ifdef _WIN32
#include <windows.h>
#include <process.h>
#else
#include <pthread.h>
#ifdef _APPLE_
#include <platform/iossemaphore.h>
//using namespace iossem;
#else
#include <semaphore.h>
#endif
#endif

#include <iostream>

// 2009/09
// 增加 GetThreadQuitEvent 获取线程已经退出的 EVENT HANDLE
//      GetQuitEvent       是否手动事件退出 HANDLE

class CLCommThread
{
#ifdef _WIN32
  static unsigned int WINAPI ThreadRun(void* lpVoid)
  {
    CLCommThread* pstThread = (CLCommThread*)lpVoid;
    pstThread->Run();
    pstThread->OnEnd();

    HANDLE hthreadquitevent = pstThread->GetThreadQuitEvent();
    SetEvent(hthreadquitevent);
    return 0;
  }
#else
static void* ThreadRun(void* lpVoid)
  {
    CLCommThread* pstThread = (CLCommThread*)lpVoid;
    pstThread->Run();
    pstThread->m_bStart = false;
    pstThread->OnEnd();
    pthread_exit((void *)0);
    return NULL;
  }
#endif

protected:

#ifdef _WIN32
  // 外部控制退出标志
  HANDLE	m_hQuitEvent;
  // 线程退出标志
  HANDLE	m_hThreadQuitEvent;

  HANDLE	m_hThread;
  unsigned int	m_tThread;
#else
bool m_bStart;
  pthread_attr_t m_tThreadAttr;
  pthread_t	m_tThread;
#endif

  bool m_bDetach;
  int	m_StackSize;
  void *m_puserdata;

public:
  CLCommThread(bool bDetach = false)
  {
    m_bDetach = bDetach;

    m_StackSize = 2 * 1024 * 1024;    // 默认2M堆栈

    m_puserdata = NULL;

#ifdef _WIN32
    m_hQuitEvent = ::CreateEvent(NULL, true, false, NULL);
    m_hThreadQuitEvent = ::CreateEvent(NULL, true, false, NULL);
    ResetEvent(m_hQuitEvent);
    ResetEvent(m_hThreadQuitEvent);


    m_hThread = INVALID_HANDLE_VALUE;
    m_tThread = -1;
#else
		m_tThread = 0;

		m_bStart = false;
    pthread_attr_init(&m_tThreadAttr);
    if (m_bDetach)
      pthread_attr_setdetachstate(&m_tThreadAttr, PTHREAD_CREATE_DETACHED);
    else
      pthread_attr_setdetachstate(&m_tThreadAttr, PTHREAD_CREATE_JOINABLE);
#endif
  }

  virtual ~CLCommThread()
  {
#ifdef _WIN32
    ::CloseHandle(m_hQuitEvent);
    ::CloseHandle(m_hThreadQuitEvent);
#else
    pthread_attr_destroy(&m_tThreadAttr);
#endif
    OnDelete();
  }

  bool Start()
  {
#ifdef _WIN32
    if (m_hThread != INVALID_HANDLE_VALUE)
    {
      return false;
    }
#else
if (m_bStart)
    {
      return false;
    }
#endif

    if (false == OnStart())
    {
      return false;
    }

#ifdef _WIN32
    ResetEvent(m_hQuitEvent);
    ResetEvent(m_hThreadQuitEvent);
    m_hThread = (HANDLE)_beginthreadex(NULL, 0, CLCommThread::ThreadRun, (void*)this, 0, &m_tThread);
    if (m_hThread == INVALID_HANDLE_VALUE)
    {
      return false;
    }
#else
    // 设置堆栈大小
    pthread_attr_setstacksize(&m_tThreadAttr, (size_t)m_StackSize);
    m_bStart = true;
    int iResult = pthread_create(&m_tThread, &m_tThreadAttr, CLCommThread::ThreadRun, (void*)this);
    if (iResult)
    {
			m_bStart = false;      //cout<<"Create thread failed!\n";
      return false;
    }
#endif 
    return true;
  }

  bool Stop()
  {
#ifdef _WIN32
    SetEvent(m_hQuitEvent);
    if (m_hThread == INVALID_HANDLE_VALUE)
    {
      return false;
    }
#else
    if (!m_bStart)
    {
      return false;
    }
#endif

    if (!OnStop())
    {
      return false;
    }

#ifndef _WIN32
    m_bStart = false;
#endif 
    return true;
  }
/*
  int Cancel()
  {
#ifdef _WIN32
    if (m_hThread != INVALID_HANDLE_VALUE)
    {
      ::TerminateThread(m_hThread, 0);
      CloseHandle(m_hThread);
      m_hThread = INVALID_HANDLE_VALUE;
      return 0;
    }
#else
	    #ifndef _ANDROID_
				if (m_bStart)
    		{
      		m_bStart = false;
      		return pthread_cancel(m_tThread);
    		}
    	#endif
#endif 
    return 0;
  }
*/
#ifdef _WIN32
  HANDLE GetThreadQuitEvent()
  {
    return m_hThreadQuitEvent;
  }

  HANDLE GetQuitEvent()
  {
    return m_hQuitEvent;
  }

  bool IsThreadRunning(int ntimeout = 0)
  {
    if (m_hThread == INVALID_HANDLE_VALUE)
    {
      return false;
    }

    if (WaitForSingleObject(m_hQuitEvent, ntimeout) == WAIT_OBJECT_0)
    {
      return false;
    }

    return true;
  }
#else
  bool IsThreadRunning()
  {
    if (m_bStart)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
#endif

  bool CanRun();

  // 设置线程的堆栈大小
  // 必须在线程创建前设置
  void SetThreadStackSize(int StackSize)
  {
    if (StackSize < 512 * 1024)
    {
      // 最小 512 KB 堆栈内存
      m_StackSize = 512 * 1024;
    }
    else
    {
      m_StackSize = StackSize;
    }
  }
  int WaitEnd(int ntimeout = -1)
  {
#ifdef _WIN32
    WaitForSingleObject(m_hThreadQuitEvent, ntimeout);
    WaitForSingleObject(m_hThread, ntimeout);
    m_hThread = INVALID_HANDLE_VALUE;
#else
	  void   *pret;
    pthread_join(m_tThread, &pret);
#endif 
    return 0;
  }

  void SetUserData(void *puserdata)
  {
    m_puserdata = puserdata;
  }
  void *GetUserData()
  {
    return m_puserdata;
  }

  static int EndSomeOneThread(CLCommThread **ppthread, int ntimeout = -1)
  {
    CLCommThread * pthread = (*ppthread);

    if (pthread != NULL)
    {
      pthread->Stop();
			pthread->WaitEnd(ntimeout);
      delete pthread;
      *ppthread = NULL;
      return 0;
    }

    return -1;
  }

protected:
  virtual int Run() = 0;
  virtual bool OnStart()
  {
    return true;
  }
  virtual bool OnStop()
  {
    return true;
  }
  virtual void OnEnd()
{}	//perhaps you will delete THIS here.



  virtual void OnDelete()
  {
#ifdef _WIN32
    if (m_hThread != INVALID_HANDLE_VALUE)
    {
      if (GetCurrentThreadId() != m_tThread)	//end by another thread
      {
        ::TerminateThread(m_hThread, 0);
      }
      CloseHandle(m_hThread);
      m_hThread = INVALID_HANDLE_VALUE;
    }
#else
    int iResult;

    if (m_bStart && pthread_self() != m_tThread)	//end by another thread
    {
    	#ifndef _ANDROID_
      iResult = pthread_cancel(m_tThread);
      if (iResult)
      {
        return ;
      }
      #endif

      if (!m_bDetach)
      {
        pthread_join(m_tThread, NULL);
      }
    }
#endif
  }

};

#endif

