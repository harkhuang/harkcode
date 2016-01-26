// KCBPConnectPool.h : KCBP连接池
//                原理： 系统在一启动时，与KCBP建立N个长连接，并维护连接状态，
//                       应用在需要接收或发送时，此类实例返回一个空闲可用句柄，进行异步调用或接收
//
//
//
//write by luosj 20061204
//
//
#include "platform/queue.h"
#include "lcomm/baseerror.h"
//#include "KCBPCli.h"
#include "kcbpcli.h"
//#include <windows.h>
#include <vector>
//using namespace std;

#ifndef _KCBPCONNECTPOOL_H_
#define _KCBPCONNECTPOOL_H_

#ifndef _LINUX_
#define DLL_API _declspec(dllimport)
#else
#define DLL_API 
#endif
//add by luosj 20061204
typedef struct
{
    tagKCBPConnectOption KCBPConnectOption;

    char szKCBPUser[KCBP_SERVERNAME_MAX+1];              //KCBP用户
    char szKCBPPwd[KCBP_SERVERNAME_MAX+1];               //KCBP用户密码

    int  iTimeOutConnect;                                //连接超时
    int  iTimeOutRequest;                                //请求超时
    char szAppName[64];                                  //应用名称
}tagKCBPConnectOptionExMy; //tagKCBPConnectOptionEx;新的头文件竟然已经有了这个名称的结构，只好改名了


class  CKCBPConnectPool : public CLBaseError
{
private:
    
  //KCBP地址列表，用于随机选择用
  std::vector <tagKCBPConnectOptionExMy *> m_vctKCBPServer; 

	CQueue<void *> m_queue_kcbpconnect;

	int m_nkcxp_confirm;

public:
    CKCBPConnectPool(int nquickreplay =0, bool basync=false);
    virtual ~CKCBPConnectPool();
    
    //增加一个服务端
    bool AddServer(tagKCBPConnectOptionExMy *p_pKCBPConnectOptionEx);
    
    //初始化连接池，并连接KCBP，并维持之
    bool InitPool(int p_iTotalConnectNum);
    //释放连接池
    bool UninitPool();
    
    //释放所有连接，复位连接池
    bool ReleasePool();

    //增加一个连接
    bool AddConnect(KCBPCLIHANDLE *hHandle=NULL); 

    //分配一个空闲连接，并设置占用标志
    bool AllocConnect(KCBPCLIHANDLE *hHandle);

    //归还连接，并释放占用标志
    bool FreeConnect(KCBPCLIHANDLE p_hHandle);
    
    //复位连接，用于出错处理
    //bool ResetConnect(KCBPCLIHANDLE p_hHandle);

    //重新连接，保持KCBPCli句柄不变
    bool Reconnect(KCBPCLIHANDLE& p_hHandle);
		
  	int GetConnectCount();

private:
	//异步操作需要GROUPID， 每个机器独立，但要相对池也独立
	int GeneralGroupId();
	int GetComputerName(char *lpBuffer, unsigned long* lpnSize);
	int ftok(const char *szPath, int nKeyproj);
private:
	  bool	      m_bASync;				//是否为异步池, 默认否
	  char        m_szgroupid[24 + 1]; 		//每个池的ID = 21位m_szappgroupid + m_nGroupIndex
	  static char m_szappgroupid[24 +1];		//整个应用的ID
	  static char m_szpathid[8 +1];
	  static char m_sznode[32 + 1];
	  static  int  m_nGroupIndex;
};

#endif
