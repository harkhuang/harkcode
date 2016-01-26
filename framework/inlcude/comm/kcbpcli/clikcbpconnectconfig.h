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
	char szAddress[16];			//网卡号
  int  nPort;		//Socket
	char szReqQ[64];            // 请求队列
	char szAnsQ[64];            // 应答队列
	char szKcxpUser[64];         // xp用户
	char szKcxpPass[64];           // xp用户密码
}tagNETWORKADD;

typedef struct 
{
	char 			szywlb[24];		//业务类别
	int 		        nSyncPoolSize;	//同步BP池大小
	int 		        nASyncPoolSize;	//异步
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
	Description:    添加bp的节点
	Calls:          
	Called By:      
	Table Accessed: 
	Table Updated:  
	Input:		
	tagKCBP_BUSINESS_NODE * pstNode Y bp节点的对象
	Output:
	Return:         0表示成功， 其他失败
	Others:         // 其它说明
	ex:             
	*************************************************/
	int AttachNodes(tagKCBP_BUSINESS_NODE * pstNode);
	/*************************************************
	Function:       GetNodeCount
	Description:    获取bp节点数量
	Calls:          
	Called By:      
	Table Accessed: 
	Table Updated:  
	Input:		
	Output:
	Return:         非负数表示bp节点数量， 其他失败
	Others:         // 其它说明
	ex:             
	*************************************************/
	int GetNodeCount();
	/*************************************************
	Function:       SetNodeCount
	Description:    获取bp节点数量
	Calls:          
	Called By:      
	Table Accessed: 
	Table Updated:  
	Input:	
	int nCount           Y    设置bp节点数量	
	Output:
	Return:         0表示成功， 其他失败
	Others:         // 其它说明
	ex:             
	*************************************************/
	int SetNodeCount(int nCount);
	/*************************************************
	Function:       GetKCBPConnetTimeOut
	Description:    获取连接超时时间
	Calls:          
	Called By:      
	Table Accessed: 
	Table Updated:  
	Input:		
	Output:
	Return:         非负数表示连接超时时间， 其他失败
	Others:         // 其它说明
	ex:             
	*************************************************/
	int GetKCBPConnetTimeOut();
	/*************************************************
	Function:       GetKCBPRequestTimeOut
	Description:    获取请求超时时间
	Calls:          
	Called By:      
	Table Accessed: 
	Table Updated:  
	Input:		
	Output:
	Return:         非负数表示请求超时时间， 其他失败
	Others:         // 其它说明
	ex:             
	*************************************************/
	int GetKCBPRequestTimeOut();
	/*************************************************
	Function:       AddNode
	Description:    添加bp节点对象
	Calls:          
	Called By:      
	Table Accessed: 
	Table Updated:  
	Input:		
	Output:
	Return:         0表示成功， 其他失败
	Others:         // 其它说明
	ex:             
	*************************************************/
	int AddNode(tagKCBP_BUSINESS_NODE * pstNode);
	/*************************************************
	Function:       SetConnectTimeOut
	Description:    设置连接超时时间
	Calls:          
	Called By:      
	Table Accessed: 
	Table Updated:  
	Input:		
	int nTimeOut   Y    超时时间
	Output:
	Return:         0表示成功， 其他失败
	Others:         // 其它说明
	ex:             
	*************************************************/
	int SetConnectTimeOut(int nTimeOut);
	/*************************************************
	Function:       SetReqTimeOut
	Description:    设置连接超时时间
	Calls:          
	Called By:      
	Table Accessed: 
	Table Updated:  
	Input:		
	int nTimeOut   Y    超时时间
	Output:
	Return:         0表示成功， 其他失败
	Others:         // 其它说明
	ex:             
	*************************************************/
	int SetReqTimeOut(int nTimeout);
	/*************************************************
	Function:       GetKCBPParams
	Description:    返回bp节点列表
	Calls:          
	Called By:      
	Table Accessed: 
	Table Updated:  
	Input:		
	Output:
	Return:         非NULL表示成功， 其他失败
	Others:         // 其它说明
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