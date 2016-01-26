#ifndef __L_WIN32FUNCDEF_INCLUDE__
#define __L_WIN32FUNCDEF_INCLUDE__

#ifdef _WIN32
#include <windows.h>

typedef long atomic_t;


inline int ATOMIC_Inc(atomic_t *natomic)
{
  return ::InterlockedIncrement(natomic);
}

inline int ATOMIC_Dec(atomic_t *natomic)
{
  return ::InterlockedDecrement(natomic);
}

inline int GETATOMIC(atomic_t *natomic)
{
  return *natomic;
}

inline int ATOMIC_IncData(atomic_t *natomic,int ndata)
{
	*natomic = *natomic + ndata;
  return GETATOMIC(natomic);
}

inline int ATOMIC_Init(atomic_t *natomic)
{
  *natomic =0;
	return GETATOMIC(natomic);
}

inline int ATOMIC_Set(atomic_t *natomic,int ndata)
{
  *natomic =ndata;
	return GETATOMIC(natomic);
}


#endif 

#endif  // __L_WIN32FUNCDEF_INCLUDE__
