#ifndef __L_NETDATATYPE_H__
#define __L_NETDATATYPE_H__

#ifdef _WIN32
#define __L_LITTLE_ENDIAN
#else
#define __L_BIG_ENDIAN
#endif

#ifdef __L_LITTLE_ENDIAN
#define hton16      htons
#define hton32      htonl
#define hton64(i)   ( ((uint64)(htonl((u_long)((i) & 0xffffffff))) << 32) | htonl((u_long)(((i) >> 32) & 0xffffffff)) )
#define ntoh16      ntohs
#define ntoh32      ntohl
#define ntoh64      hton64
#endif

#ifdef __L_BIG_ENDIAN
#define hton16      htons
#define hton32      htonl
#define ntoh16      ntohs
#define ntoh32      ntohl
//#define hton64(i)   ( i )
//#define ntoh64(i)   ( i )
#endif

#endif // __L_NETDATATYPE_H__
