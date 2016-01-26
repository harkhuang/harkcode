
#include <kcbpcli/kpoolcalllbm.h>
#include <lcomm/lmapstruct.h>
#include <kcbpcli/clikcbpconnectconfig.h>

#ifndef _LINUX_
#define DLL_API _declspec(dllimport)
#else
#define DLL_API 
#endif


class CKDLong;
class  KCentralCallLbm
{
public:
	KCentralCallLbm();
	virtual ~KCentralCallLbm();
		/*************************************************
	Function:       SetKDLog
	Description:    设置日志对象
	Calls:          
	Called By:      
	Table Accessed: 
	Table Updated:  
	Input:			
	CKDLog *pLog   Y  日志对象
	Output:
	Return:         0表示成功， 其他失败
	Others:         // 其它说明
	ex:             
	*************************************************/
	int 	SetKDLog(CKDLog *pLog);
	//Init֮ǰSetKDLog
	/*************************************************
	Function:       Init
	Description:    初始化
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
	int     Init();
  /*************************************************
	Function:       Uninit
	Description:    反初始化
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
	int     Uninit();
	/*************************************************
	Function:       SetCB
	Description:    设置回调
	Calls:          
	Called By:      
	Table Accessed: 
	Table Updated:  
	Input:		
	char * pszYWLB      Y   回调业务类别
	CLBMCB* pclCB       Y   回调对象	
	Output:
	Return:         0表示成功， 其他失败
	Others:         // 其它说明
	ex:             
	*************************************************/
	int SetCB(char * pszYWLB, CLBMCB* pclCB);
	/*************************************************
	Function:       Process
	Description:    请求lbm
	Calls:          
	Called By:      
	Table Accessed: 
	Table Updated:  
	Input:		
	CMsgData *pCMsgData_Input      Y   包含请求参数的msg对象
	CMsgData **ppIcommMsgData_Return       Y   包含返回的应答的msg对象
	char *pszErrMsg    Y        错误信息
	int nMaxErrMsgLen  Y   错误信息最大长度
	bool bASync      Y    指定是否为异步请求 true为异步， false为同步	
	Output:
	CMsgData **ppIcommMsgData_Return   N  返回的msg对象
	char *pszErrMsg       Y  返回的错误信息
	Return:         0表示成功， 其他失败
	Others:         // 其它说明
	ex:             
	*************************************************/
	int     Process(CMsgData *pCMsgData_Input, CMsgData **ppIcommMsgData_Return, char *pszErrMsg, int nMaxErrMsgLen, bool bASync, void *pUserObj=NULL);
	/*************************************************
	Function:       SetCliConfig
	Description:    设置配置
	Calls:          
	Called By:      
	Table Accessed: 
	Table Updated:  
	Input:		
	CMsgData *pCMsgData_Input      Y   包含请求参数的msg对象
	CMsgData **ppIcommMsgData_Return       Y   包含返回的应答的msg对象
	char *pszErrMsg    Y        错误信息
	int nMaxErrMsgLen  Y   错误信息最大长度
	bool bASync      Y    指定是否为异步请求 true为异步， false为同步	
	Output:
	CMsgData **ppIcommMsgData_Return   N  返回的msg对象
	char *pszErrMsg       Y  返回的错误信息
	Return:         0表示成功， 其他失败
	Others:         // 其它说明
	ex:             
	*************************************************/
	int			SetCliConfig(CCliConfig *);
//	int SetCB(char * pszYWLB, CLBMCB* pclCB);
private:
	CLMapStructByString<KPoolCallLbm>  m_mapPoolCallLbm;	
	CCliConfig			*m_pConfig;	
	CKDLog				*m_pLog;
};