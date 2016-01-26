// LINUX Æ½Ì¨Ä£Äâ WIN32 ATL ÊÊÅä
#ifndef __WIN32COM_LINUXATLADAPTER_H__
#define __WIN32COM_LINUXATLADAPTER_H__	
#ifdef _LINUX_

#include "limits.h"
#include <platform/criticalsection.h>

#define ATL_NO_VTABLE
#define LInterface(a) public IUnknown

#define ATLASSERT(a)


#define _ATL_IIDOF(x) __uuidof(x)

typedef HRESULT (_ATL_CREATORARGFUNC)(
	void* pv,
	REFIID riid,
  void ** ppv,
	unsigned long dw);

struct _ATL_INTMAP_ENTRY
{
	const IID* piid;       // the interface id (IID)
	unsigned long dw;
	_ATL_CREATORARGFUNC* pFunc; //NULL:end, 43:offset, n:ptr
};

#define _ATL_SIMPLEMAPENTRY ((_ATL_CREATORARGFUNC*)1)


inline HRESULT AtlInternalQueryInterface(
	void* pThis,
	const _ATL_INTMAP_ENTRY* pEntries,
	REFIID iid,
	void** ppvObject)
{
	// printf("AtlInternalQueryInterface %s\n",iid.Data4);
	
	_ATL_INTMAP_ENTRY* pFirstEntries  = (_ATL_INTMAP_ENTRY*)pEntries;
	if(pThis == NULL || pEntries == NULL)
		return E_INVALIDARG;

	if (ppvObject == NULL)
		return E_POINTER;
	*ppvObject = NULL;
	if (InlineIsEqualGUID(__uuidof(IUnknown), iid)) // use first interface
	{
			IUnknown* pUnk = (IUnknown*)((char *)pThis+pFirstEntries->dw);
			pUnk->AddRef();
			*ppvObject = pUnk;
			return S_OK;
	}
	while (pEntries->pFunc != NULL)
	{
		//printf("Atcmp riid=%s item=%s\n",iid.Data4,pEntries->piid->Data4);
		if (pEntries->piid != NULL && 
			  InlineIsEqualGUID(*(pEntries->piid), iid))
		{
			if (pEntries->pFunc == _ATL_SIMPLEMAPENTRY) //offset
			{
				void *pobj = ((char *)pThis+pEntries->dw);
				IUnknown* pUnk = (IUnknown*)((char *)pThis+pFirstEntries->dw);
				pUnk->AddRef();
				*ppvObject = pobj;

				// printf("AtlInternalQueryInterface %s found\n",iid.Data4);
				return S_OK;
			}
		}
		pEntries++;
	}
	//printf("ERROR: AtlQI %s no tif=%s\n",iid.Data4,pFirstEntries->piid->Data4);
	return E_NOINTERFACE;
}


class CComObjectRootBase
{
public:
	CComObjectRootBase()
	{
		m_dwRef = 0;
	}
	virtual ~CComObjectRootBase()	{	}
	
	virtual HRESULT FinalConstruct()
	{
		return S_OK;
	}
	
	virtual void FinalRelease() 	{	}


	static HRESULT InternalQueryInterface(
			void* pThis,
			const _ATL_INTMAP_ENTRY* pEntries, 		
			REFIID iid, 
			void** ppvObject)
		{
			HRESULT hRes = AtlInternalQueryInterface(pThis, pEntries, iid, ppvObject);
			return hRes;
		}

	int _ResetRef(int nref)
	{
		m_dwRef = nref;
		return 0;
	}
	
protected:
	int m_dwRef;
};

class CComSingleThreadModel
{
public:
	static int Increment(int *n)
	{
		return ++(*n);
	}
	static int Decrement(int *n)
	{
		return --(*n);
	}
};

template <class ThreadModel>
class CComObjectRootEx : 
	public CComObjectRootBase
{
public:
	typedef ThreadModel _ThreadModel;

	virtual ~CComObjectRootEx() 
	{
	}

	int InternalAddRef()
	{
		int nref  =0;
		CriticalFunction lock(__m_refcs);
		nref = _ThreadModel::Increment(&m_dwRef);
		return nref;
	}
	
	int InternalRelease()
	{
		int nref = 0;
		CriticalFunction lock(__m_refcs);
		nref = _ThreadModel::Decrement(&m_dwRef);
		if (nref ==-(INT_MAX/2))
		{
			// throw error
		}
		return nref;
	}

	void Lock() 
	{
	}
	
	void Unlock() 
	{
	}
	private:
		CriticalSection __m_refcs;
};

template <class Base>
class CComObject : public Base
{
public:
	typedef Base _BaseClass;
	CComObject(void* = NULL)
	{
	}
	// Set refcount to -(INT_MAX/2) to protect destruction and 
	// also catch mismatched Release in debug builds
	virtual ~CComObject()
	{	
		int nv = -(INT_MAX/2);
		_BaseClass::_ResetRef(nv);
		_BaseClass::FinalRelease();
	}
	//If InternalAddRef or InternalRelease is undefined then your class
	//doesn't derive from CComObjectRoot
	int AddRef(void) 
	{
		int l = _BaseClass::InternalAddRef();
		//if (l == 0)
		//	_pAtlModule->Lock();
		return l;
	}
	int Release(void)
	{
		int l = _BaseClass::InternalRelease();
		if (l == 0)
		{
			delete this;
		}
		//else if (l == 0)
		//	_pAtlModule->Unlock();
		return l;
	}

  HRESULT QueryInterface(REFIID iid, void **ppvObject)
  {
  	*ppvObject = NULL;
		_BaseClass::_InternalQueryInterface(iid, ppvObject);
		return S_OK;
	}
};


template <class T>
class CComCreator
{
public:
	static HRESULT CreateInstance(
		void *pv, 
		REFIID riid, 
		void **ppv)
	{
		//ATLASSERT(ppv != NULL);
		if (ppv == NULL)
		{
			return E_POINTER;
		}

		*ppv = NULL;

		HRESULT hRes = E_OUTOFMEMORY;
		CComObject<T>* p = NULL;

		p = new CComObject<T>(NULL);
		if (p != NULL)
		{
			hRes = p->FinalConstruct();
			if (hRes == S_OK)
			{
				hRes = p->QueryInterface(riid, ppv);
			}
			if (hRes != S_OK)
			{
				delete p;
			}
		}
		return hRes;
	}
};


template <class T> 
class CComCoClass
{
public:
	typedef CComCreator<T> _CreatorClass;
	virtual ~CComCoClass() { }
	
	template <class Q>
	static HRESULT CreateInstance(
		IUnknown* punkOuter, 
		Q** pp)
	{
		return _CreatorClass::CreateInstance(punkOuter, __uuidof(Q), (void**) pp);
	}
	template <class Q>
	static HRESULT CreateInstance(Q **pp)
	{
		return _CreatorClass::CreateInstance(NULL, __uuidof(Q), (void**)pp);
	}
	
};	
	
class CLUnknow
{
public:
	CLUnknow() { }
	virtual ~CLUnknow() { }
	
};



#define DECLARE_NO_REGISTRY()
#define DECLARE_NOT_AGGREGATABLE(a)
#define DECLARE_PROTECT_FINAL_CONSTRUCT()

//#define BEGIN_COM_MAP(a)
//#define COM_INTERFACE_ENTRY(a)
//#define END_COM_MAP()

#ifndef _ATL_PACKING
#define _ATL_PACKING 8
#endif

#define offsetofclass(base, derived) ((unsigned long)(static_cast<base*>((derived*)_ATL_PACKING))-_ATL_PACKING)

#define BASE_OFFSET(ClassName, BaseName) \
  (DWORD(static_cast<BaseName*>(reinterpret_cast<ClassName*>\
  (0x10000000))) - 0x10000000)


#define BEGIN_COM_MAP(x) public: \
	typedef x _ComMapClass; \
	HRESULT _InternalQueryInterface( \
		REFIID iid, \
		void** ppvObject) \
	{ \
		return InternalQueryInterface(this, _GetEntries(), iid, ppvObject); \
	} \
	const static _ATL_INTMAP_ENTRY* _GetEntries()  { \
	static const _ATL_INTMAP_ENTRY _entries[] = { 

	/*
	\
	{&_ATL_IIDOF(IUnknown), \
	offsetofclass(IUnknown, _ComMapClass), \
	_ATL_SIMPLEMAPENTRY},
	*/

#define COM_INTERFACE_ENTRY(x) \
	{&_ATL_IIDOF(x), \
	offsetofclass(x, _ComMapClass), \
	_ATL_SIMPLEMAPENTRY},

#define END_COM_MAP() \
	{NULL, 0, 0}};  return _entries;} \
	virtual int AddRef(void) = 0; \
	virtual int Release(void) = 0; \
	virtual HRESULT QueryInterface(REFIID riid, void **ppvObject) = 0;


#endif	
#endif // __WIN32COM_LINUXATLADAPTER_H__
