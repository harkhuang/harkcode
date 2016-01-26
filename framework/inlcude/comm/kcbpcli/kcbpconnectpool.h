// KCBPConnectPool.h : KCBP���ӳ�
//                ԭ�� ϵͳ��һ����ʱ����KCBP����N�������ӣ���ά������״̬��
//                       Ӧ������Ҫ���ջ���ʱ������ʵ������һ�����п��þ���������첽���û����
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

    char szKCBPUser[KCBP_SERVERNAME_MAX+1];              //KCBP�û�
    char szKCBPPwd[KCBP_SERVERNAME_MAX+1];               //KCBP�û�����

    int  iTimeOutConnect;                                //���ӳ�ʱ
    int  iTimeOutRequest;                                //����ʱ
    char szAppName[64];                                  //Ӧ������
}tagKCBPConnectOptionExMy; //tagKCBPConnectOptionEx;�µ�ͷ�ļ���Ȼ�Ѿ�����������ƵĽṹ��ֻ�ø�����


class  CKCBPConnectPool : public CLBaseError
{
private:
    
  //KCBP��ַ�б��������ѡ����
  std::vector <tagKCBPConnectOptionExMy *> m_vctKCBPServer; 

	CQueue<void *> m_queue_kcbpconnect;

	int m_nkcxp_confirm;

public:
    CKCBPConnectPool(int nquickreplay =0, bool basync=false);
    virtual ~CKCBPConnectPool();
    
    //����һ�������
    bool AddServer(tagKCBPConnectOptionExMy *p_pKCBPConnectOptionEx);
    
    //��ʼ�����ӳأ�������KCBP����ά��֮
    bool InitPool(int p_iTotalConnectNum);
    //�ͷ����ӳ�
    bool UninitPool();
    
    //�ͷ��������ӣ���λ���ӳ�
    bool ReleasePool();

    //����һ������
    bool AddConnect(KCBPCLIHANDLE *hHandle=NULL); 

    //����һ���������ӣ�������ռ�ñ�־
    bool AllocConnect(KCBPCLIHANDLE *hHandle);

    //�黹���ӣ����ͷ�ռ�ñ�־
    bool FreeConnect(KCBPCLIHANDLE p_hHandle);
    
    //��λ���ӣ����ڳ�����
    //bool ResetConnect(KCBPCLIHANDLE p_hHandle);

    //�������ӣ�����KCBPCli�������
    bool Reconnect(KCBPCLIHANDLE& p_hHandle);
		
  	int GetConnectCount();

private:
	//�첽������ҪGROUPID�� ÿ��������������Ҫ��Գ�Ҳ����
	int GeneralGroupId();
	int GetComputerName(char *lpBuffer, unsigned long* lpnSize);
	int ftok(const char *szPath, int nKeyproj);
private:
	  bool	      m_bASync;				//�Ƿ�Ϊ�첽��, Ĭ�Ϸ�
	  char        m_szgroupid[24 + 1]; 		//ÿ���ص�ID = 21λm_szappgroupid + m_nGroupIndex
	  static char m_szappgroupid[24 +1];		//����Ӧ�õ�ID
	  static char m_szpathid[8 +1];
	  static char m_sznode[32 + 1];
	  static  int  m_nGroupIndex;
};

#endif
