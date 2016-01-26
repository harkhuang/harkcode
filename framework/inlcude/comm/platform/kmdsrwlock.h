#ifndef _KMDS_RWLOCK_HH_
#define _KMDS_RWLOCK_HH_

#include <platform/criticalsection.h>  

#if !defined(_WIN32) && !defined(_WIN64)	
class CKmdsRwLock
{  
public:  
	CKmdsRwLock()
	{
		pthread_rwlock_init(&m_rw_lock, NULL);
	}

	~CKmdsRwLock()
	{  
		pthread_rwlock_destroy(&m_rw_lock);  
	}  

	//获取读锁  
	//如果其它一个线程占有写锁，则当前线程必须等待写锁被释放，才能对保护资源进行访问  
	inline void readlock()
	{
		pthread_rwlock_rdlock(&m_rw_lock);
	}

	//尝试获取一个读锁  
	//如果获取成功，则立即返回true，否则当另一个线程占有写锁，则返回false  
	inline bool tryreadlock()  
	{
		if (0 == pthread_rwlock_tryrdlock(&m_rw_lock))
		{
			return true; 
		}     
		return false;
	}

	//获取写锁  
	//如果一个或更多线程占有读锁，则必须等待所有锁被释放  
	//如果相同的一个线程已经占有一个读锁或写锁，则返回结果不确定  
	inline void writelock() 
	{
		pthread_rwlock_wrlock(&m_rw_lock);
	}

	//尝试获取一个写锁  
	//如果获取成功，则立即返回true，否则当一个或更多其它线程占有读锁，返回false  
	//如果相同的一个线程已经占有一个读锁或写锁，则返回结果不确定
	inline bool trywritelock()  
	{
		int rc = pthread_rwlock_trywrlock(&m_rw_lock);  
		if (rc == 0) 
		{ 
			return true;  
		}		
		return false; 
	}

	//释放一个读锁或写锁 
	inline void unlock()
	{
		pthread_rwlock_unlock(&m_rw_lock);
	}

private:  
	pthread_rwlock_t m_rw_lock;  
};  

#endif

// 读锁
class CKmdsReadLockFunction
{
private:
#if defined(_WIN32) || defined(_WIN64)
	CriticalSection &m_cllock;
#else
	CKmdsRwLock  &m_cllock;
#endif
	int m_block;
public:
#if defined(_WIN32) || defined(_WIN64)	
	CKmdsReadLockFunction(CriticalSection &cllock):m_cllock(cllock),m_block(false)
#else
	CKmdsReadLockFunction(CKmdsRwLock &cllock):m_cllock(cllock),m_block(false)
#endif
	{
		lock();
	}

	~CKmdsReadLockFunction()
	{
		unlock();
	}

	inline void lock()
	{
		if (!m_block)
		{
#if defined(_WIN32) || defined(_WIN64)	
			m_cllock.lock();
#else
			m_cllock.readlock();
#endif
			m_block = true;
		}
	}

	inline void unlock()
	{
		if (m_block)
		{				
			m_cllock.unlock();
			m_block = false;
		}
	}
};

// 写锁
class CKmdsWriteLockFunction
{
private:
#if defined(_WIN32) || defined(_WIN64)
	CriticalSection &m_cllock;
#else
	CKmdsRwLock  &m_cllock;
#endif
	int m_block;
public:
#if defined(_WIN32) || defined(_WIN64)	
	CKmdsWriteLockFunction(CriticalSection &cllock):m_cllock(cllock),m_block(false)
#else
	CKmdsWriteLockFunction(CKmdsRwLock &cllock):m_cllock(cllock),m_block(false)
#endif
	{
		lock();
	}

	~CKmdsWriteLockFunction()
	{
		unlock();
	}

	inline void unlock()
	{
		if (m_block)
		{				
			m_cllock.unlock();
			m_block = false;
		}
	}

	inline void lock()
	{
		if (!m_block)
		{
#if defined(_WIN32) || defined(_WIN64)	
			m_cllock.lock();
#else
			m_cllock.writelock();
#endif
			m_block = true;
		}
	}

};


#endif
