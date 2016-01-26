#include <iostream>
#ifndef __L_PUB_H__
#define __L_PUB_H__

#ifdef _LINUX_

#ifndef VOID
#define VOID void
typedef char CHAR;
typedef short SHORT;
typedef long LONG;
typedef int INT;
#endif

typedef long long __int64;
typedef unsigned long long uint64;
typedef signed long long int64;

typedef char OLECHAR;

typedef bool      boolean;
typedef unsigned int       DWORD;
#ifndef _OBJC_OBJC_H_
#ifndef _YUANPX_
typedef int                 BOOL;
#endif
#endif
typedef unsigned char       BYTE;
typedef unsigned short      WORD;
typedef float               FLOAT;


typedef void * HWND;
typedef void * HANDLE;
typedef void * HINSTANCE;
typedef BYTE * PBYTE;


#ifndef CONST
#define CONST               const
#endif

typedef CHAR *PCHAR, *LPCH, *PCH;
typedef CONST CHAR *LPCCH, *PCCH;

typedef CHAR *NPSTR, *LPSTR, *PSTR;
typedef PSTR *PZPSTR;
typedef CONST PSTR *PCZPSTR;
#ifndef _YUANPX_
typedef CONST CHAR *LPCSTR, *PCSTR;
typedef PCSTR *PZPCSTR;
#endif
typedef CHAR *PZZSTR;
typedef CONST CHAR *PCZZSTR;

typedef CHAR *PNZCH;
typedef CONST CHAR *PCNZCH;

typedef CHAR TCHAR;


typedef LPCH LPTCH, PTCH;
typedef LPCCH LPCTCH, PCTCH;
typedef LPSTR PTSTR, LPTSTR, PUTSTR, LPUTSTR;
#ifndef _YUANPX_
typedef LPCSTR PCTSTR, LPCTSTR, PCUTSTR, LPCUTSTR;
#endif
typedef PZZSTR PZZTSTR, PUZZTSTR;
typedef PCZZSTR PCZZTSTR, PCUZZTSTR;
typedef PNZCH PNZTCH, PUNZTCH;
typedef PCNZCH PCNZTCH, PCUNZTCH;

typedef CHAR *BSTR;

#define MAX_PATH 256
#define INFINITE -1

// linux socket define
typedef int SOCKET;
#define INVALID_SOCKET -1
#define SOCKET_ERROR   -1

#ifndef _APPLE_ 
#define TRUE true
#define FALSE false
#endif

// ipc
#define WAIT_TIMEOUT 258L
#define STATUS_WAIT_0  ((DWORD   )0x00000000L)    
#define WAIT_OBJECT_0       ((STATUS_WAIT_0 ) + 0 )
#define WAIT_FAILED    ((DWORD)0xFFFFFFFF)	

// max min data value

//#define MB_LEN_MAX    5             /* max. # bytes in multibyte char */
//#define SHRT_MIN    (-32768)        /* minimum (signed) short value */
//#define SHRT_MAX      32767         /* maximum (signed) short value */
//#define USHRT_MAX     0xffff        /* maximum unsigned short value */
//#define INT_MIN     (-2147483647 - 1) /* minimum (signed) int value */
//#define INT_MAX       2147483647    /* maximum (signed) int value */
//#define UINT_MAX      0xffffffff    /* maximum unsigned int value */
//#define LONG_MIN    (-2147483647L - 1) /* minimum (signed) long value */
//#define LONG_MAX      2147483647L   /* maximum (signed) long value */
//#define ULONG_MAX     0xffffffffUL  /* maximum unsigned long value */
//#define LLONG_MAX     9223372036854775807i64       /* maximum signed long long int value */
//#define LLONG_MIN   (-9223372036854775807i64 - 1)  /* minimum signed long long int value */
//#define ULLONG_MAX    0xffffffffffffffffui64       /* maximum unsigned long long int value */

// COLORREF
typedef DWORD COLORREF;

#define LOWORD(l)           ((WORD)(((DWORD)(l)) & 0xffff))
#define HIWORD(l)           ((WORD)((((DWORD)(l)) >> 16) & 0xffff))
#define LOBYTE(w)           ((BYTE)(((DWORD)(w)) & 0xff))
#define HIBYTE(w)           ((BYTE)((((DWORD)(w)) >> 8) & 0xff))

#define RGB(r,g,b)          ((COLORREF)(((BYTE)(r)|((WORD)((BYTE)(g))<<8))|(((DWORD)(BYTE)(b))<<16)))
#define GetRValue(rgb)      (LOBYTE(rgb))
#define GetGValue(rgb)      (LOBYTE(((WORD)(rgb)) >> 8))
#define GetBValue(rgb)      (LOBYTE((rgb)>>16))

#define __stdcall


#ifndef GUID_DEFINED
#define GUID_DEFINED
typedef struct _GUID
{
	unsigned long Data1;
	unsigned short Data2;
	unsigned short Data3;
	unsigned char Data4[8];
} GUID;
#endif

#endif


#endif // __L_PUB_H__
