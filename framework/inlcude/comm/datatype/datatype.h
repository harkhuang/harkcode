
#ifndef __L__DATATYPE__INCLUDED__H__
#define __L__DATATYPE__INCLUDED__H__

#include <string.h>
#include <stdio.h>
#include <stdarg.h>

#include "linuxdatatype.h"
#ifndef NET_TYPEDEFS
#define NET_TYPEDEFS
typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

#if defined(_WIN32) || defined(_WIN64) 
typedef unsigned __int64 uint64;
typedef signed __int64 int64;
#endif

typedef unsigned __int64 uint64;
typedef signed char int8;
typedef signed short int16;
typedef signed int int32;

#endif
typedef uint64 UID;

#define MEMSTZERO(x,y) memset(x,0x00,sizeof(y))
#define MEMBUFZERO(x)  memset(x,0x00,sizeof(x))

// 安全的字符拷贝
#ifndef  SAFESTRNCPY
#define SAFESTRNCPY(x,y)  strncpy(x,y,sizeof(x)); x[sizeof(x) -1] =0x00;
#endif

#ifdef _WIN32
	#ifdef _EXPORTS
		#define DECLSPECIFIER __declspec(dllexport)
		#define EXPIMP_TEMPLATE
		#define EXT_CLASS  __declspec(dllexport)
		#define EXT_ENTRY __declspec(dllexport)
	#else
		#define DECLSPECIFIER __declspec(dllimport)
		#define EXPIMP_TEMPLATE extern
		#define EXT_CLASS  __declspec(dllimport)
		#define EXT_ENTRY __declspec(dllimport)
	#endif
#else
		#define DECLSPECIFIER
		#define EXPIMP_TEMPLATE
		#define EXT_CLASS
		#define EXT_ENTRY
#endif

#include "lint64.h"
#include "netdatatype.h"

enum FIELDP_TYPE
{
    FIELDP_INVAILD = 0,
    FIELDP_INT8,
    FIELDP_INT16,
    FIELDP_INT32,
    FIELDP_INT64,
    FIELDP_UINT8,
    FIELDP_UINT16,
    FIELDP_UINT32,
    FIELDP_UINT64,
    FIELDP_FLOAT,
    FIELDP_DOUBLE,
    FIELDP_CHAR,
    FIELDP_NVARCHAR,
    FIELDP_STRING,
    FIELDP_BINARY,
    FIELDP_ICOMMSGDATA,
    FIELDP_ICOMTABLEDATA
};

#define GETSET_STRING_METHOD(name,size)  public:  \
                                  inline char* Get##name() { return m_sz##name; } \
                                  inline void Set##name(const char *lpname) \
				                          { \
                                     strncpy(m_sz##name,lpname,sizeof(m_sz##name) -1); \
                                     m_sz##name[sizeof(m_sz##name) -1] = 0; \
				                          } \
				                        private: \
                                  char m_sz##name[size +1];

#define GETSET_STRING_INIT(name) m_sz##name[0] = 0;


#define GETSET_INT_METHOD(name)  public:  \
                                  inline int Get##name() { return m_n##name; } \
                                  inline void Set##name(int ndata) \
				                          { \
                                     m_n##name = ndata; \
				                          } \
				                        private: \
                                  int m_n##name;

#define GETSET_INT_INIT(name)    m_n##name = 0;
#define GETSET_INT_INIT_WITHDATA(name,data)    m_n##name = data;



#define GETSET_VOID_METHOD(type,name)  public:  \
                                  inline type Get##name() { return m_##name; } \
                                  inline void Set##name(type pdata) \
				                          { \
                                     m_##name = pdata; \
				                          } \
				                        private: \
                                  type m_##name;

#define GETSET_VOID_INIT(name,data)    m_##name = data;

#define GetDP_FNameByFType_FUN(__ntype) \
   if (ntype == __ntype) \
   { \
     strncpy(lpsztype,#__ntype,nmaxlen); \
		 lpsztype[nmaxlen -1] = 0; \
		 return; \
   } \

inline void GetDP_FNameByFType(FIELDP_TYPE ntype,char *lpsztype,int nmaxlen)
{
	GetDP_FNameByFType_FUN(FIELDP_INVAILD);
	GetDP_FNameByFType_FUN(FIELDP_INT8);
	GetDP_FNameByFType_FUN(FIELDP_INT16);
	GetDP_FNameByFType_FUN(FIELDP_INT32);
	GetDP_FNameByFType_FUN(FIELDP_INT64);
	GetDP_FNameByFType_FUN(FIELDP_UINT8);
	GetDP_FNameByFType_FUN(FIELDP_UINT16);
	GetDP_FNameByFType_FUN(FIELDP_UINT32);
	GetDP_FNameByFType_FUN(FIELDP_UINT64);
	GetDP_FNameByFType_FUN(FIELDP_FLOAT);
	GetDP_FNameByFType_FUN(FIELDP_DOUBLE);
	GetDP_FNameByFType_FUN(FIELDP_CHAR);
	GetDP_FNameByFType_FUN(FIELDP_NVARCHAR);
	GetDP_FNameByFType_FUN(FIELDP_STRING);
	GetDP_FNameByFType_FUN(FIELDP_BINARY);
	GetDP_FNameByFType_FUN(FIELDP_ICOMMSGDATA);
	GetDP_FNameByFType_FUN(FIELDP_ICOMTABLEDATA);
	GetDP_FNameByFType_FUN(FIELDP_INVAILD);
	return;
}



#endif // __L__DATATYPE__INCLUDED__H__
