//�������LBMҵ��. Ӧ������Ӧ��ֻ��1��ʵ��
#ifndef  __KDHQSERVER_LBM_H_1
#define  __KDHQSERVER_LBM_H_1
//#ifndef _LINUX_
//#include "stdafx.h"
//#endif

#include <datatype/linuxdatatype.h>
#include <platform/linuxcplusplus.h>
#include <platform/config_file.h>
#include  <kcbpcli/kcbpcli.h>
//#include <kcbpcli/Config.h>
#include <kcbpcli/kcbpconnectpool.h>
#include <lcomm/kdlog.h>
#include <lcomm/msgdata.h>
#include <lcomm/lmapstruct.h>
#include <platform/criticalsection.h>
#include <platform/queue.h>
#include <kcbpcli/clikcbpconnectconfig.h>
//#include <kcbpcli/kyw.h>

#ifndef _LINUX_
#define DLL_API _declspec(dllimport)
#else
#define DLL_API 
#endif

#define			RS_MAXSIZE		8193			//��������ֽ�
#define 		ASYNC_REPLAY_TIMEOUT		10000		//�ȴ�Ӧ��ʱ
#define 		SCAN_TIMEOUT_INTERVAL		1000		//ɨ�賬ʱ�̼߳��
#define        		SERVERNAME			"KCBPA"

typedef struct
{
	unsigned int    dwTick;
	char			strywlb[1024];
	void    *pUserObj;
}tagWaitForReply;
typedef CLMapStructByString<tagWaitForReply>  TY_MAP_WAITFORREPLY;

	
class   CLBMCB
{
	public:
		CLBMCB(){}
		virtual ~CLBMCB() {}
	public:
		//�첽�����ص�, CMsgData�Զ��ͷ�. msgid, ansmsg
		virtual int  DoLBMCB(int nerrcode, char *pszerrmsg, char *pszMsgId, CMsgData *pAnsCommMsgData, void *pUserObj) = 0;
};


class   CASyncRecvThread : public CLCommThread
{//�첽���������̣߳�ÿ����1��
	public:
		CASyncRecvThread(){}
		virtual ~CASyncRecvThread(){}
		int  Run();
	public:
		void  SetYwlb(char *pszywlb)
		{
			if(pszywlb)
			{
				m_strywlb = pszywlb;
			}
		}

	protected:
		std::string			m_strywlb;		//ҵ�����
};
//ɨ�賬ʱ
class   CScanTimeOutThread : public CASyncRecvThread
{
	public:
		CScanTimeOutThread(){}
		virtual ~CScanTimeOutThread(){}
		int  Run();
};




class  KPoolCallLbm
{
	friend class CASyncRecvThread;
	friend class CScanTimeOutThread;
	friend class KCentralCallLbm;
public:
	KPoolCallLbm();
	~KPoolCallLbm();
	//���ӳ�ʼ������ҪΪ�첽����
	/*************************************************
	Function:       Init
	Description:    ��ʼ��
	Calls:          
	Called By:      
	Table Accessed: 
	Table Updated:  
	Input:			
	Output:
	Return:         0��ʾ�ɹ��� ����ʧ��
	Others:         // ����˵��
	ex:             
	*************************************************/
	int     Init();
	/*************************************************
	Function:       Uninit
	Description:    ����ʼ��
	Calls:          
	Called By:      
	Table Accessed: 
	Table Updated:  
	Input:			
	Output:
	Return:         0��ʾ�ɹ��� ����ʧ��
	Others:         // ����˵��
	ex:             
	*************************************************/	
	int     Uninit();
	int     Process(CMsgData *pCMsgData_Input, CMsgData **ppIcommMsgData_Return, int & nerrcode, char *pszErrMsg, int nMaxErrMsgLen, bool bASync, void *pUserObj=NULL);
	int    SetCB(CLBMCB *pcb);
	int    SetKDLog(CKDLog *pLog);
	
	int AddMap(tagWaitForReply * pstWaitRep, bool bCopy, char * pszMsgId);
	CKCBPConnectPool * GetSyncPool();
	CKCBPConnectPool * GetASyncPool();
	int SetSyncPool(CKCBPConnectPool *);
	int SetASyncPool(CKCBPConnectPool *);
	CriticalSection * GetCriticalSection();
	TY_MAP_WAITFORREPLY * GetMapWaitRep();
	int GetSize();
private:	

	void* GetBPPool(bool bASync=false);
	int   KcbpErrMsg(KCBPCLIHANDLE &hKcbpHandle, int &nErrCode, char *szErrMsg, int nMaxMsgSize);
	int   KcbpGetData(KCBPCLIHANDLE 	&hKcbpHandle, CMsgData *pCMsgData);
	int __Process(CKCBPConnectPool *pKCBPConnectPool,
					  KCBPCLIHANDLE 	  hKcbpHandle,
	                  CMsgData *pCMsgData_Input, 
	                  CMsgData **ppCMsgData_Return, 
	                  int &nerrcode,
	                  char *pszerrmsg, 
	                  int nerrmsglen, 
	                  bool bASync, 
	                  void *pUserObj);


  
  int SetKCBPCLIValue(KCBPCLIHANDLE hKcbpHandle, CMsgData *pCMsgData_Input);
  int ASyncAct(tagCallCtrl * pstControl, void * pUserObject);
private:
	CKDLog			*m_pLog;
	CLBMCB			*m_pclsLBMCB;
	std::vector<CLCommThread *>  m_vcSendOrRecvTrd;
	CriticalSection  m_pCs;
	TY_MAP_WAITFORREPLY  m_pmapWaitRep;
	CKCBPConnectPool * m_SyncPool;
	CKCBPConnectPool * m_ASyncPool;
	
	
	typedef struct
	{
		CMsgData * pCMsgData;
		unsigned int dwTick;	
	}AnsCache;
	
	CLMapStructByString<AnsCache> m_mapCache;
	typedef struct
	{
		CMsgData *pCMsgDataReq;
		void    *pUserObj;
	}tagWaitForSend;
	//CQueue<void *>     m_quSend;
};
#endif
