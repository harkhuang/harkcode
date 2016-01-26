
#ifndef __L_INT64_INCLUDE_H__
#define __L_INT64_INCLUDE_H__

#ifdef _WIN32
#define I64Const(x) x##I64
#endif

#ifdef _LINUX_
#define I64Const(x) x
#endif

inline int64 INT32ToINT64 (int32 low) {  int64 retval = static_cast<int64>(low); return retval; };
inline int32 INT64ToINT32 (int64 value) { int low = static_cast<int32>(value & 0x00000000FFFFFFFF); return low; };
inline int32 UINT64ToINT32 (uint64 value) { int low = static_cast<int32>(value & 0x00000000FFFFFFFF); return low; };

#ifdef _WIN32
#define ATOI64(x) _atoi64(x)  
#endif

#ifdef _LINUX_
#define ATOI64(x) atoll(x)  
#endif


#if defined(_APPLE_) || defined(_LINUX_)
#define DEF_I64D "%lld"
#define DEF_UI64D "%llu"
#else
#define DEF_I64D "%I64d"
#define DEF_UI64D "%I64u"
#endif


#endif
