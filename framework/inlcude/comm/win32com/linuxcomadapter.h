// LINUX 平台模拟 WIN32 COM 适配
#ifndef __WIN32COM_LINUXCOMADAPTER_H__
#define __WIN32COM_LINUXCOMADAPTER_H__
#ifdef _LINUX_

#include <datatype/datatype.h>
#include <platform/criticalsection.h>



#define STDMETHODCALLTYPE


#define _T(a) a
typedef long HRESULT;
#define SUCCEEDED(hr) (((HRESULT)(hr)) == 0)
#define FAILED(hr) (((HRESULT)(hr)) != 0)

#define _HRESULT_TYPEDEF_(_sc) ((HRESULT)_sc)
#define E_UNEXPECTED                     _HRESULT_TYPEDEF_(0x8000FFFFL)
#define E_NOTIMPL                        _HRESULT_TYPEDEF_(0x80004001L)
#define E_OUTOFMEMORY                    _HRESULT_TYPEDEF_(0x8007000EL)
#define E_INVALIDARG                     _HRESULT_TYPEDEF_(0x80070057L)
#define E_NOINTERFACE                    _HRESULT_TYPEDEF_(0x80004002L)
#define E_POINTER                        _HRESULT_TYPEDEF_(0x80004003L)
#define E_HANDLE                         _HRESULT_TYPEDEF_(0x80070006L)
#define E_ABORT                          _HRESULT_TYPEDEF_(0x80004004L)
#define E_FAIL                           _HRESULT_TYPEDEF_(0x80004005L)
#define E_ACCESSDENIED                   _HRESULT_TYPEDEF_(0x80070005L)
#define E_CANNOTRELEASE                  _HRESULT_TYPEDEF_(0x80070100L)



#define STDMETHOD(method)       virtual HRESULT method
#define STDMETHODIMP            HRESULT

// Success codes
#define S_OK                                   ((HRESULT)0L)
#define S_FALSE                                ((HRESULT)1L)

// REFIID 定义
#ifndef GUID_DEFINED
#define GUID_DEFINED
typedef struct _GUID
{
  unsigned long Data1;
  unsigned short Data2;
  unsigned short Data3;
  unsigned char Data4[ 8 ];
}
GUID;
#endif

#ifndef __IID_DEFINED__
#define __IID_DEFINED__
typedef GUID IID;
#endif

#ifndef _REFIID_DEFINED
#define _REFIID_DEFINED
#define REFIID const IID &
#endif

/*
#ifndef DECLSPEC_UUID
#define DECLSPEC_UUID
#define EXTERN_GUID(itf,l1,s1,s2,c1,c2,c3,c4,c5,c6,c7,c8)  \
IID itf = {l1,s1,s2,{c1,c2,c3,c4,c5,c6,c7,c8}}
#endif

EXTERN_GUID(IID_LALLOBJECT, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
*/

//#define __uuidof(a) IID_##a

template < class TheClass >
struct _LGuidTraits
{};

#define L_RLS_DEFINE_GUID(                                          \
TheClass, sz, x, s1, s2, c1, c2, c3, c4, c5, c6, c7, c8)            \
                                                                    \
template <class nInst>                                              \
struct _GuidOf_##TheClass {                                         \
static const GUID guid;                                             \
};                                                                  \
                                                                    \
template <class nInst>                                              \
const GUID _GuidOf_##TheClass<nInst>::guid = {                      \
x, s1, s2, { c1, c2, c3, c4, c5, c6, c7, c8 }                    \
};                                                                  \
                                                                    \
template <>                                                         \
struct _LGuidTraits<TheClass> {                                     \
typedef _GuidOf_##TheClass<int> _Class;                             \
};

#define L_RLS_DEFINE_GUID_ALTER(TheClass, guidref)                  \
                                                                    \
template <class nInst>                                              \
struct _GuidOf_##TheClass {                                         \
static const GUID& guid;                                            \
};                                                                  \
                                                                    \
template <class nInst>                                              \
const GUID& _GuidOf_##TheClass<nInst>::guid = guidref;              \
                                                                    \
template <>                                                         \
struct _LGuidTraits<TheClass> {                                     \
typedef _GuidOf_##TheClass<int> _Class;                             \
};

#define L_RLS_GUIDOF(TheClass)       _LGuidTraits<TheClass>::_Class::guid

#ifndef __uuid
#define __uuid(TheClass)         L_RLS_GUIDOF(TheClass)
#endif

#ifndef DEFINE_IID
#define DEFINE_IID(Interface, sz, x, s1, s2, c1, c2, c3, c4, c5, c6, c7, c8) \
class Interface;                                                                                                     \
L_RLS_DEFINE_GUID(Interface, sz, x, s1, s2, c1, c2, c3, c4, c5, c6, c7, c8)
#endif

#ifndef DEFINE_CLSID
#define DEFINE_CLSID(TheClass, sz, x, s1, s2, c1, c2, c3, c4, c5, c6, c7, c8) \
class TheClass;                                                                                                                   \
L_RLS_DEFINE_GUID(TheClass, sz, x, s1, s2, c1, c2, c3, c4, c5, c6, c7, c8)
#endif

#ifndef DEFINE_GUID_ALTER
#define DEFINE_GUID_ALTER(TheClass, guid)                                                                       \
L_RLS_DEFINE_GUID_ALTER(TheClass, guid)
#endif


#define __uuidof(TheClass)              __uuid(TheClass)

DEFINE_IID(IUnknown,"IUnknown", 
               8, 8, 8, 'I', 'U', 'n', 'k', 'n', 'o', 'w', 0);
DEFINE_IID(IKDCP,"IKDCP", 
	             8, 8, 8, 'K', 'D', 'C', 'P', 0, 0, 0, 0);
DEFINE_IID(IKDCPBase,"IKDCPBase", 
	             8, 8, 8, 'K', 'D', 'C', 'P', 'B', 'a', 's', 0);

DEFINE_IID(IKDCPQuery,"IKDCPQuery", 
	             8, 8, 8, 'K', 'D', 'C', 'P', 'Q', 'u', 'y', 0);

struct IUnknown
{
public:
  virtual ~IUnknown(){}
  virtual int AddRef(void) = 0;
  virtual int Release(void) = 0;
  virtual HRESULT QueryInterface(REFIID riid, void **ppvObject) = 0;
};

class CLinuxIUnknown: public IUnknown
{
public:
	CLinuxIUnknown()
	{
		m_nref = 1;
	}
	
  int AddRef(void)
  {
  	CriticalFunction lock(__m_refcs);
    return ++m_nref;
  }
  int Release(void)
  {
	  CriticalFunction lock(__m_refcs);
    return --m_nref;
  }

  HRESULT QueryInterface(REFIID riid, void **ppvObject)
  {
    return S_FALSE;
  }
private:
  	long m_nref;
	CriticalSection __m_refcs;
};


//#ifdef __cplusplus
//extern "C"
//{
//#endif

BSTR SysAllocString( char const* sz);
VOID SysFreeString( BSTR bstr);
namespace _com_util
{
// Convert char * to BSTR
//
BSTR ConvertStringToBSTR(char const* pSrc);

// Convert BSTR to char *
//
char* ConvertBSTRToString(BSTR pSrc);
};


//#ifdef __cplusplus
//}
//#endif
inline int InlineIsEqualGUID(REFIID rguid1, REFIID rguid2)
{
   return (
      ((unsigned long *) &rguid1)[0] == ((unsigned long *) &rguid2)[0] &&
      ((unsigned long *) &rguid1)[1] == ((unsigned long *) &rguid2)[1] &&
      ((unsigned long *) &rguid1)[2] == ((unsigned long *) &rguid2)[2] &&
      ((unsigned long *) &rguid1)[3] == ((unsigned long *) &rguid2)[3]);
}





#endif

#endif // __WIN32COM_LINUXCOMADAPTER_H__
