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
* 文 件 名：autorefer.h 
* 模块名称：基础类
* 功能说明：智能引用模板类
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
#ifndef __KMDS_AUTOREFER_H__
#define __KMDS_AUTOREFER_H__

template <class T> 
class CAutoRefer
{
public: 
	CAutoRefer()
	{
		m_iface = new T;
	}

	CAutoRefer(T *p)
	{
		m_iface = p;
	}

	virtual ~CAutoRefer()
	{
		Release();
	}
	operator T*()
	{
		return m_iface;
	}
	T* operator*() {	return m_iface;  } 
	T** operator&() {	return &m_iface;  } 

	// Return the address being pointed to.  
	T* operator->() { return m_iface; }		


	int Attach(T *pinterface,bool baddref = true)
	{
		if (m_iface == pinterface)
		{
			return 0;
		}

		Release();
		m_iface = pinterface;
		if (baddref)
		{
			m_iface->AddRef();
		}
		return 0;
	}

	int Detech()
	{
		Release();
		return 0;
	}

	T* GetInterface()
	{
		return m_iface;
	}

	void Release()
	{
		if (m_iface)
		{
			m_iface->Release(); 
			m_iface = NULL; 
		}
	}

private:
	T* m_iface;
};

#endif//__KMDS_AUTOREFER_H__