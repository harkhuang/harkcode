/******************************************************************************
*
*									KMDS V1.0 
*
*           Copyright (C) 2012-2013, SHENZHEN KINGDOM Co., Ltd.
* 
*                             All Rights Reserved.
*
* ===========================================================================
*
* �� �� ����referencecount.h 
* ģ�����ƣ�������
* ����˵�������ü�����
* ��    �ߣ�liulj
* �������ڣ�2013-07-20
* �� �� �ţ�1.0
* �޸���ʷ��
*
* �޸�����       ����            ����
* ---------------------------------------------------------------------------
* 2013-07-20     liulj         ��ʼ�汾
*
******************************************************************************/
#ifndef __KMDS_REFERENCECOUNT_H__
#define __KMDS_REFERENCECOUNT_H__

#include <platform/criticalsection.h>
class CReferenceCount
{
public:
	CReferenceCount()
	{
		m_nref = 1;
	}
	virtual ~CReferenceCount()
	{
	}

	int AddRef(void)
	{
		CriticalFunction lock(__m_refcs);
		return ++m_nref;
	}
	int Release(void)
	{
		int  nret = -1;
		{
			CriticalFunction lock(__m_refcs);
			nret = --m_nref;
		}

		if (nret == 0)
		{
			delete this;
		}
		return nret;
	}

private:
	int m_nref;
	CriticalSection __m_refcs;
};

#endif //__KMDS_REFERENCECOUNT_H__
