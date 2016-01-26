#if !defined(__LIU_CRITICALSECTION_H__)
#define __LIU_CRITICALSECTION_H__


#include "linuxcplusplus.h"
class CriticalSection  {
public:
	CriticalSection() : isLocked_(false) 
	{
		InitializeCriticalSection( &cs_ );
 }

	~CriticalSection() 
	{
		DeleteCriticalSection( &cs_ );
	}

	inline void lock() {
		EnterCriticalSection( &cs_ );
		isLocked_ = true;
	}

	inline void unlock() {
		LeaveCriticalSection( &cs_ );
		isLocked_ = false;
	}

	inline bool isLocked() const {
		return isLocked_;
	}

  /*
	inline const CRITICAL_SECTION* getHandle() const {
		return &cs_;
	}
	*/
protected:

	CRITICAL_SECTION cs_;

	bool isLocked_;

};

class CriticalFunction
{
private:
	CriticalSection &m_cllock;
	int m_block;
public:
	CriticalFunction(CriticalSection &cllock):m_cllock(cllock),m_block(false)
	{
		Lock();
	}
	
	~CriticalFunction()
	{
		Unlock();
	}

	inline void Unlock()
	{
		if (m_block)
		{
			m_cllock.unlock();
			m_block = false;
		}
	}

	inline void Lock()
	{
		if (!m_block)
		{
			m_cllock.lock();
			m_block = true;
		}
	}
	
};

#endif
