#ifndef __WIN32COM_WIN32COMADAPTER_H__
#define __WIN32COM_WIN32COMADAPTER_H__
	
#ifdef _WIN32
#include <wtypes.h>
	#define LInterface(a) public a
#endif

#ifdef _LINUX_
#include <platform/linuxcplusplus.h>
#include "linuxcomadapter.h"
#include "linuxatladapter.h"
#endif

inline bool KDCP_GUID_CMP(const IID &lhs, const IID &rhs)
{
	return ((memcmp(&lhs, &rhs, sizeof(IID)) == 0) ? true : false);
}
#endif // __WIN32COM_WIN32COMADAPTER_H__

