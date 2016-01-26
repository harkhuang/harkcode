#ifndef _MUTILINSTANCE_INCLUDE_H_
#define _MUTILINSTANCE_INCLUDE_H_
#include <lcomm/singleton.h>
#include <platform/criticalsection.h>
#include <lcomm/lmapstruct.h>

template <class T>
class CMutilInstance: public Singleton< CMutilInstance<T> >
{
	public:
		CMutilInstance()	{ m_nseq = 100;	}
		virtual ~CMutilInstance() { }
		
		int Create()
		{
			int nseq = 0;
			T *pclobj = new T;
			CriticalFunction lock(m_cs);
			nseq = m_nseq ++;
			m_lmap_datas.AddData(nseq,pclobj,false);
			return nseq;
		}
		T *GetInterface(int nhandle)
		{
			T *pclobj = NULL;
			CriticalFunction lock(m_cs);
			pclobj = m_lmap_datas.FindItem(nhandle);
			return pclobj;		
		}
		int Free(int nhandle)
		{
			int nret = -1;
			T * pclobj = GetInterface(nhandle);
			if (pclobj)
			{
				CriticalFunction lock(m_cs);
				nret = m_lmap_datas.DeleteWithKey(nhandle)?0:1;
			}
			return nret;
		}
	private:
		CriticalSection m_cs;
		int m_nseq;
		typedef CLMapStruct<int,T > ty_lmap_datas;
		ty_lmap_datas m_lmap_datas;

};
#endif

/*
使用：多句柄实例管理类
#include "mutilinstance.h"

需要使用时：
CMutilInstance<CKMDSApi> *pclmutinst = & Singleton<CMutilInstance<CKMDSApi> >::instance();

int nhandle = pclmutinst->Create();
CKMDSApi *pcl = pclmutinst->GetInterface(nhandle);
pcl->Free(nhandle);


//程序退出 只调用一次
Singleton<CMutilInstance<CKMDSApi> >::release();
*/