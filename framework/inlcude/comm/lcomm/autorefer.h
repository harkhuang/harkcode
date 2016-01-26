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
* �� �� ����autorefer.h 
* ģ�����ƣ�������
* ����˵������������ģ����
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