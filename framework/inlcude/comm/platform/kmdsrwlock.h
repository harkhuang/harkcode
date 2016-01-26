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

	//��ȡ����  
	//�������һ���߳�ռ��д������ǰ�̱߳���ȴ�д�����ͷţ����ܶԱ�����Դ���з���  
	inline void readlock()
	{
		pthread_rwlock_rdlock(&m_rw_lock);
	}

	//���Ի�ȡһ������  
	//�����ȡ�ɹ�������������true��������һ���߳�ռ��д�����򷵻�false  
	inline bool tryreadlock()  
	{
		if (0 == pthread_rwlock_tryrdlock(&m_rw_lock))
		{
			return true; 
		}     
		return false;
	}

	//��ȡд��  
	//���һ��������߳�ռ�ж����������ȴ����������ͷ�  
	//�����ͬ��һ���߳��Ѿ�ռ��һ��������д�����򷵻ؽ����ȷ��  
	inline void writelock() 
	{
		pthread_rwlock_wrlock(&m_rw_lock);
	}

	//���Ի�ȡһ��д��  
	//�����ȡ�ɹ�������������true������һ������������߳�ռ�ж���������false  
	//�����ͬ��һ���߳��Ѿ�ռ��һ��������д�����򷵻ؽ����ȷ��
	inline bool trywritelock()  
	{
		int rc = pthread_rwlock_trywrlock(&m_rw_lock);  
		if (rc == 0) 
		{ 
			return true;  
		}		
		return false; 
	}

	//�ͷ�һ��������д�� 
	inline void unlock()
	{
		pthread_rwlock_unlock(&m_rw_lock);
	}

private:  
	pthread_rwlock_t m_rw_lock;  
};  

#endif

// ����
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

// д��
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
