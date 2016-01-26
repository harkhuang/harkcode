#ifndef __MINIPOOL__INCLUDE__H__
#define __MINIPOOL__INCLUDE__H__

#ifndef NULL
#define NULL 0
#endif

#ifdef _WIN32
#include <windows.h>
#endif

#include <platform/linuxcplusplus.h>


// 系统内存分配
#define	USE_MINIMEMPOOL_NORMAL 0
// 使用直接的队列池列表快速分配
#define	USE_MINIMEMPOOL_QUEUENEWDEL 1
// 使用系统的Interlocked SList减少锁
#define	USE_MINIMEMPOOL_SLIST 2

#define USE_MINIMEMPOOL USE_MINIMEMPOOL_NORMAL

#if USE_MINIMEMPOOL == USE_MINIMEMPOOL_QUEUENEWDEL
#include <deque>
#endif

#define USE_MINIMEMPOOL_MAXQUEUE 10

#if USE_MINIMEMPOOL == USE_MINIMEMPOOL_SLIST

#ifndef _SLIST_HEADER_
#define _SLIST_HEADER_


#define SLIST_ENTRY SINGLE_LIST_ENTRY
#define _SLIST_ENTRY _SINGLE_LIST_ENTRY
#define PSLIST_ENTRY PSINGLE_LIST_ENTRY

typedef union _SLIST_HEADER {
    ULONGLONG Alignment;
    struct {
        SLIST_ENTRY Next;
        WORD   Depth;
        WORD   Sequence;
    };
} SLIST_HEADER, *PSLIST_HEADER;

#endif
	typedef struct MINIMEMPOOL_APP_ITEM {
    	SLIST_ENTRY ItemEntry;
	    void *pdata;
	} MINIMEMPOOL_APP_ITEM, *PMINIMEMPOOL_APP_ITEM;
#endif

class CBaseMiniMemPool
{
public:
	CBaseMiniMemPool() { }
	virtual ~CBaseMiniMemPool() {}
#if USE_MINIMEMPOOL == USE_MINIMEMPOOL_QUEUENEWDEL
	static int SetCpuCount(int ncount)
	{
		int& ncpucount = const_cast<int &>(m_ncpucount);
		if (ncount > USE_MINIMEMPOOL_MAXQUEUE)
		{
			ncpucount = USE_MINIMEMPOOL_MAXQUEUE;
		}
		else
		{
			ncpucount = ncount;
		}
		m_ncpucount = USE_MINIMEMPOOL_MAXQUEUE;
		return m_ncpucount;
		return 1;
	}
	static int m_ncpucount;
#endif
};


// must have Init Uninit function
template <class T,int DefaultLimit = 1000 > class CMiniMemPool: public CBaseMiniMemPool
{
public:
	CMiniMemPool(int nlimit = DefaultLimit)
	{
#if USE_MINIMEMPOOL == USE_MINIMEMPOOL_QUEUENEWDEL
	int i;
	for (i=0;i< USE_MINIMEMPOOL_MAXQUEUE; ++i)
	{
		::InitializeCriticalSection(&lock[i]);
	    m_nqueuesize[i] = 0;
		m_nmaxqueuesize[i] = nlimit;
		m_clqueue[i].clear();
	}

	memset(&m_nputqueuedata, 0, sizeof(atomic_t));
	memset(&m_ngetqueuedata, 0, sizeof(atomic_t));
	//m_nputqueuedata = 0L;
	//m_ngetqueuedata = 0L;

#elif USE_MINIMEMPOOL == USE_MINIMEMPOOL_SLIST
    // Initialize the list header.
    m_plisthead = (PSLIST_HEADER)_aligned_malloc(sizeof(SLIST_HEADER),
       											 MEMORY_ALLOCATION_ALIGNMENT);
    InitializeSListHead(m_plisthead);	
#endif
	}
	
	virtual ~CMiniMemPool()
	{
#if USE_MINIMEMPOOL == USE_MINIMEMPOOL_QUEUENEWDEL		
		T * pobject = NULL;
		int i;
		for (i=0;i< USE_MINIMEMPOOL_MAXQUEUE; ++i)
		{
			// t_minipoolqueue::iterator itpos;
			//t_minipoolqueue_it itpos;
			typename std::deque<T *>::iterator itpos;
			::EnterCriticalSection(&lock[i]);
			for (itpos = m_clqueue[i].begin();itpos != m_clqueue[i].end(); ++itpos)
			{
				pobject = *itpos;
				delete pobject;
			}
			m_clqueue[i].clear();
			::LeaveCriticalSection(&lock[i]);
			::DeleteCriticalSection(&lock[i]);
		}
#elif USE_MINIMEMPOOL == USE_MINIMEMPOOL_SLIST
		_aligned_free(m_plisthead);
#endif
	}
	
	T *GeneralData()
	{
	  T * pobject = NULL;
#if USE_MINIMEMPOOL == USE_MINIMEMPOOL_QUEUENEWDEL

	  unsigned int nq =0;
	  if (m_ncpucount >1)
	  {
		int  ngetqdata = ATOMIC_Inc(&m_ngetqueuedata);
		nq = ngetqdata % m_ncpucount;
	  }

	  if (m_nqueuesize[nq] >0)
	  {
  	    ::EnterCriticalSection(&lock[nq]);
		if (m_nqueuesize[nq] >0)
		{
	    	m_nqueuesize[nq] --;
			pobject = m_clqueue[nq].back();
			m_clqueue[nq].pop_back();
			::LeaveCriticalSection(&lock[nq]);
			pobject->Init();
		}
		else
		{
			::LeaveCriticalSection(&lock[nq]);		
		}
	  }
#elif USE_MINIMEMPOOL == USE_MINIMEMPOOL_SLIST
	  PSLIST_ENTRY pListEntry;
	  PMINIMEMPOOL_APP_ITEM pProgramItem;
	  pListEntry = InterlockedPopEntrySList(m_plisthead);
	  if (pListEntry == NULL)
	  {
        pProgramItem = (PMINIMEMPOOL_APP_ITEM)_aligned_malloc(sizeof(MINIMEMPOOL_APP_ITEM),
            												  MEMORY_ALLOCATION_ALIGNMENT);	  	
		pobject = pProgramItem->pdata = new T;
	  }
	  else
	  {
	  	pProgramItem = (PMINIMEMPOOL_APP_ITEM)pListEntry;
		pobject = pProgramItem->pdata;
		pobject->Init();
	  }
	  return pobject;	  
#endif
		
	  if (pobject == NULL)
	  {
	  	pobject = new T;
	  }
	  return pobject;
	}
	
	void ReleaseData(T* pobject)
	{
#if USE_MINIMEMPOOL == USE_MINIMEMPOOL_QUEUENEWDEL		
		unsigned int nq =0;
   	    if (m_ncpucount >1)
		{
		  int  nputqdata = ATOMIC_Inc(&m_nputqueuedata);
		  nq = nputqdata % m_ncpucount;
		}

		pobject->Uninit();
 	    ::EnterCriticalSection(&lock[nq]);
		if (m_nqueuesize[nq] <m_nmaxqueuesize[nq])
		{		
		   m_clqueue[nq].push_back(pobject);
    	   m_nqueuesize[nq]++;
		   ::LeaveCriticalSection(&lock[nq]);	   
		}
		else
		{
			::LeaveCriticalSection(&lock[nq]);
			delete pobject;
		}
#elif USE_MINIMEMPOOL == USE_MINIMEMPOOL_SLIST
		pobject->Uninit();
		PSLIST_ENTRY pListEntry = (PSLIST_ENTRY)(pobject - offsetof(MINIMEMPOOL_APP_ITEM,pdata)); 

		InterlockedPushEntrySList(m_plisthead, pListEntry);
#else
		delete pobject;
#endif
	}

	//CRITICAL_SECTION tlock;
private:
#if USE_MINIMEMPOOL == USE_MINIMEMPOOL_QUEUENEWDEL
    // 程序 std::list 有问题 性能极低应避免使用
	// typedef std::list<T *> t_minipoolqueue;
	typedef std::deque<T *> t_minipoolqueue;
	//typename std::deque<T *>::iterator  t_minipoolqueue_it;
	t_minipoolqueue m_clqueue[USE_MINIMEMPOOL_MAXQUEUE];
	CRITICAL_SECTION lock[USE_MINIMEMPOOL_MAXQUEUE];
	int m_nqueuesize[USE_MINIMEMPOOL_MAXQUEUE];
	int m_nmaxqueuesize[USE_MINIMEMPOOL_MAXQUEUE];
	atomic_t m_nputqueuedata;
	atomic_t m_ngetqueuedata;
#elif USE_MINIMEMPOOL == USE_MINIMEMPOOL_SLIST
	PSLIST_HEADER m_plisthead;
#endif
};

template <class T,int DefaultLimit =1000> class CMiniMemPoolInstance
{
public:
	virtual ~CMiniMemPoolInstance(){}
	static T *CreateFromPool()
	{
		#if USE_MINIMEMPOOL == USE_MINIMEMPOOL_NORMAL
		return new T();
		#else
			return m_clmempool.GeneralData();
		#endif	
	}

	int ReleaseToPool(T *lpcldata)
	{
		#if USE_MINIMEMPOOL == USE_MINIMEMPOOL_NORMAL		
			delete lpcldata;
		#else	
			m_clmempool.ReleaseData(lpcldata);
		#endif	
		return 0;
	}	

	virtual int Init() = 0;
	virtual int Uninit() = 0;

private:
	static CMiniMemPool<T,DefaultLimit> m_clmempool;
};

template <class T,int DefaultLimit>
CMiniMemPool<T,DefaultLimit> CMiniMemPoolInstance<T,DefaultLimit>::m_clmempool;


#define DELARE_MINIMEMPOOL(T,DefaultLimit) friend class CMiniMemPool < T, DefaultLimit >; \
                                           friend class CMiniMemPoolInstance < T, DefaultLimit > ;


#endif //__MINIPOOL__INCLUDE__H__
