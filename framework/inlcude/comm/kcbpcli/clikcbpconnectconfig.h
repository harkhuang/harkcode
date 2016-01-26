#ifndef __CLICONFIG_H__
#define __CLICONFIG_H__


#include <kcbpcli/kcbpconnectpool.h>
#include <platform/config_file.h>
#include <lcomm/macro_ldef.h>
#include <lcomm/kdlog.h>
#define         SEC_KCBPBUSINESSINFO		 "KCBP_BUSINESS_INFO"
#define        		SERVERNAME			"KCBPA"

#ifndef _LINUX_
#define DLL_API _declspec(dllimport)
#else
#define DLL_API 
#endif

typedef struct 
{
	char szAddress[16];			//������
  int  nPort;		//Socket
	char szReqQ[64];            // �������
	char szAnsQ[64];            // Ӧ�����
	char szKcxpUser[64];         // xp�û�
	char szKcxpPass[64];           // xp�û�����
}tagNETWORKADD;

typedef struct 
{
	char 			szywlb[24];		//ҵ�����
	int 		        nSyncPoolSize;	//ͬ��BP�ش�С
	int 		        nASyncPoolSize;	//�첽
	//char szResname[256];
	int 			nkcxpcount;
	tagNETWORKADD 		*pkcxpnetaddr;
	CKCBPConnectPool 	*pSyncKCBPConnectPool;
	CKCBPConnectPool 	*pASyncKCBPConnectPool;
}tagKCBP_BUSINESS_NODE;





class  CCliConfig
{
public:
	CCliConfig();
	virtual ~CCliConfig();
	/*************************************************
	Function:       AttachNodes
	Description:    ���bp�Ľڵ�
	Calls:          
	Called By:      
	Table Accessed: 
	Table Updated:  
	Input:		
	tagKCBP_BUSINESS_NODE * pstNode Y bp�ڵ�Ķ���
	Output:
	Return:         0��ʾ�ɹ��� ����ʧ��
	Others:         // ����˵��
	ex:             
	*************************************************/
	int AttachNodes(tagKCBP_BUSINESS_NODE * pstNode);
	/*************************************************
	Function:       GetNodeCount
	Description:    ��ȡbp�ڵ�����
	Calls:          
	Called By:      
	Table Accessed: 
	Table Updated:  
	Input:		
	Output:
	Return:         �Ǹ�����ʾbp�ڵ������� ����ʧ��
	Others:         // ����˵��
	ex:             
	*************************************************/
	int GetNodeCount();
	/*************************************************
	Function:       SetNodeCount
	Description:    ��ȡbp�ڵ�����
	Calls:          
	Called By:      
	Table Accessed: 
	Table Updated:  
	Input:	
	int nCount           Y    ����bp�ڵ�����	
	Output:
	Return:         0��ʾ�ɹ��� ����ʧ��
	Others:         // ����˵��
	ex:             
	*************************************************/
	int SetNodeCount(int nCount);
	/*************************************************
	Function:       GetKCBPConnetTimeOut
	Description:    ��ȡ���ӳ�ʱʱ��
	Calls:          
	Called By:      
	Table Accessed: 
	Table Updated:  
	Input:		
	Output:
	Return:         �Ǹ�����ʾ���ӳ�ʱʱ�䣬 ����ʧ��
	Others:         // ����˵��
	ex:             
	*************************************************/
	int GetKCBPConnetTimeOut();
	/*************************************************
	Function:       GetKCBPRequestTimeOut
	Description:    ��ȡ����ʱʱ��
	Calls:          
	Called By:      
	Table Accessed: 
	Table Updated:  
	Input:		
	Output:
	Return:         �Ǹ�����ʾ����ʱʱ�䣬 ����ʧ��
	Others:         // ����˵��
	ex:             
	*************************************************/
	int GetKCBPRequestTimeOut();
	/*************************************************
	Function:       AddNode
	Description:    ���bp�ڵ����
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
	int AddNode(tagKCBP_BUSINESS_NODE * pstNode);
	/*************************************************
	Function:       SetConnectTimeOut
	Description:    �������ӳ�ʱʱ��
	Calls:          
	Called By:      
	Table Accessed: 
	Table Updated:  
	Input:		
	int nTimeOut   Y    ��ʱʱ��
	Output:
	Return:         0��ʾ�ɹ��� ����ʧ��
	Others:         // ����˵��
	ex:             
	*************************************************/
	int SetConnectTimeOut(int nTimeOut);
	/*************************************************
	Function:       SetReqTimeOut
	Description:    �������ӳ�ʱʱ��
	Calls:          
	Called By:      
	Table Accessed: 
	Table Updated:  
	Input:		
	int nTimeOut   Y    ��ʱʱ��
	Output:
	Return:         0��ʾ�ɹ��� ����ʧ��
	Others:         // ����˵��
	ex:             
	*************************************************/
	int SetReqTimeOut(int nTimeout);
	/*************************************************
	Function:       GetKCBPParams
	Description:    ����bp�ڵ��б�
	Calls:          
	Called By:      
	Table Accessed: 
	Table Updated:  
	Input:		
	Output:
	Return:         ��NULL��ʾ�ɹ��� ����ʧ��
	Others:         // ����˵��
	ex:             
	*************************************************/	
	tagKCBP_BUSINESS_NODE * GetKCBPParams();
	
	tagKCBP_BUSINESS_NODE * m_pKCBPBusinessNode;
	int m_nKCBPConnetTimeOut;
	int m_nKCBPRequestTimeOut;
	int m_nKCBPBusinessCount;
	CKDLog			*m_pLog;
	virtual int ReadKCBPParams() {return 0;}
	bool InitKCBPConnectPool();
};
class CFileConfig : public CCliConfig
{
public:
	CFileConfig()
	{
		m_pConfig = new CIniFile();
		m_bSelfRelease = true;
	}
	CFileConfig(CIniFile * p)
	{
		m_pConfig = p;
		m_bSelfRelease = false;
	}
    ~CFileConfig(){
		if(m_bSelfRelease && m_pConfig != NULL)
		{
			delete m_pConfig;
			m_pConfig = NULL;
		}
	};
	int Open(const char * pszPath);
	virtual int ReadKCBPParams();
private:
	CIniFile  *m_pConfig;
	bool      m_bSelfRelease;

};





#endif