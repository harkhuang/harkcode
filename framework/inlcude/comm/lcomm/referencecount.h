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
* 文 件 名：referencecount.h 
* 模块名称：基础类
* 功能说明：引用计数类
* 作    者：liulj
* 创建日期：2013-07-20
* 版 本 号：1.0
* 修改历史：
*
* 修改日期       姓名            内容
* ---------------------------------------------------------------------------
* 2013-07-20     liulj         初始版本
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
