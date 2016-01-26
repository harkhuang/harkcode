#ifndef __L_EVENT_INCLUDE_H__
#define __L_EVENT_INCLUDE_H__

#ifdef _WIN32
#include <windows.h>
#endif

#ifdef _LINUX_
#include <pthread.h>
	#ifdef _APPLE_
		#include <platform/iossemaphore.h>
		//using namespace iossem;
	#else
		#include <linuxsemaphore.h>
	#endif
#endif

class CLEvent
{
	public:
		CLEvent()
		{
			m_hevent = CreateEvent(NULL, true, false, NULL);
		}
		virtual ~CLEvent()
		{
#ifdef _LINUX_
			CloseEvent(m_hevent);
#elif _WIN32
			CloseHandle(m_hevent);
#endif
		}

		bool Wait(ntimeout =0)
		{
			if (WaitForSingleObject(m_hevent, ntimeout) == WAIT_OBJECT_0)
			{
				return true;
			}
			return false;
		}

		bool Check()
		{
			return Wait(0);
		}

		int Set()
		{
			SetEvent(m_hevent);
			return 0;
		}

		int Reset()
		{
			ResetEvent(m_hevent);
			return 0;
		}

	private:
	  HANDLE m_hevent;
};

#endif


