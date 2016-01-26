#ifndef __CKYW_H__
#define __CKYW_H__

#include <kcbpcli/KCBPConnectPool.h>
#include <lcomm/lmapstruct.h>
#include <platform/criticalsection.h>

typedef struct
{
	unsigned int    dwTick;
	char			strywlb[1024];
	void    *pUserObj;
}tagWaitForReply;
typedef CLMapStructByString<tagWaitForReply>  TY_MAP_WAITFORREPLY;


class CKYW
{
public:
	CKYW();
	~CKYW();
	int AddMap(tagWaitForReply * pstWaitRep, bool bCopy, char * pszMsgId);
	CKCBPConnectPool * GetSyncPool();
	CKCBPConnectPool * GetASyncPool();
	int SetSyncPool(CKCBPConnectPool *);
	int SetASyncPool(CKCBPConnectPool *);
	CriticalSection * GetCriticalSection();
	TY_MAP_WAITFORREPLY * GetMapWaitRep();
	int GetSize();
private:
	CriticalSection  m_pCs;
	TY_MAP_WAITFORREPLY  m_pmapWaitRep;
	CKCBPConnectPool * m_SyncPool;
	CKCBPConnectPool * m_ASyncPool;
};

#endif