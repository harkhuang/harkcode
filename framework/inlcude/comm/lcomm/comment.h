#ifndef __COMMENT_H__
#define __COMMENT_H__
#include <datatype/datatype.h>
#pragma pack(push,1)
enum FAST_FLAG//fastͨ��ͷ��־
{
	FAST_FLAG_TDF,// ������TDB����
	FAST_FLAG_TDB,// ����TDF����
	FAST_FLAG_END
};
// fastͨ��ͷ��
struct FAST_COMMON_HEADER
{
	int nFlag;		// ��־
	int nSeqID;		// �����
	int nBodyLength;// ��Ϣ�峤��
	int64 ntime;	// ʱ���
	int nnum;		// �����һ�����˶��ٸ���  ����ʹ��
	int nsum;		// �����ԭ�����ݳ��� sizeof(�ṹ)
	int64 nentime;	// Fast����ʱ��
	//char szdata[1024];
};
#pragma pack(pop)

#endif