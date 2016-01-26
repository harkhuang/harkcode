#ifndef __L_LINUXFUNCDEF_H__
#define __L_LINUXFUNCDEF_H__


#ifdef _LINUX_
#define ASSERT(expr) 
#define _snprintf snprintf
#define _vsnprintf vsnprintf
#define stricmp strcasecmp
#define strnicmp strncasecmp
#define _access access
#define _itoa     itoa
#define _strnicmp  strnicmp
#define _atoi64   atoll
#define __strrev strrev
#define _isnan  isnan
#define _finite isfinite
#define _stricmp stricmp
#define WSAGetLastError() errno
#define WSAECONNRESET ENOTCONN
#define WSAEINVAL EINVAL
#define WSAECONNABORTED EINTR
#define WSAENETRESET ECONNRESET
#define WSAEINPROGRESS EINPROGRESS
#define WSAEWOULDBLOCK     EWOULDBLOCK
#define WSAEISCONN EISCONN
#define _close close
#define _sopen(file, as, shflg, perm) open(file, as, perm)
#define _write write
#define _read  read
#define _chsize ftruncate
#define _lseek lseek
#define O_BINARY    0x00
#define LK_NBLCK    F_RDLCK
#define LK_UNLCK    F_UNLCK
#define _memicmp(s1, s2, n) strncasecmp((char *)s1, (char *)s2, (size_t)n)
#endif

#endif  // __L_LINUXFUNCDEF_H__
