#ifndef __COMMENT_H__
#define __COMMENT_H__
#include <datatype/datatype.h>
#pragma pack(push,1)
enum FAST_FLAG//fast通用头标志
{
	FAST_FLAG_TDF,// 发送是TDB行情
	FAST_FLAG_TDB,// 发送TDF行情
	FAST_FLAG_END
};
// fast通用头部
struct FAST_COMMON_HEADER
{
	int nFlag;		// 标志
	int nSeqID;		// 包序号
	int nBodyLength;// 消息体长度
	int64 ntime;	// 时间戳
	int nnum;		// 服务端一共发了多少个包  测试使用
	int nsum;		// 服务端原来数据长度 sizeof(结构)
	int64 nentime;	// Fast编码时间
	//char szdata[1024];
};
#pragma pack(pop)

#endif