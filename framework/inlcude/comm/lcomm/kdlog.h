#ifndef __KDLOG_H__
#define __KDLOG_H__
#include <lcomm/publicdef.h>
#include <lcomm/baseerror.h>
#include <lcomm/lgrowbuf.h>
#include <lcomm/minipool.h>
#include <platform/queue.h>
#include <platform/lcommthread.h>
#include <platform/criticalsection.h>

class CLogDataItem : public CMiniMemPoolInstance< CLogDataItem, 1000 >
{
	DELARE_MINIMEMPOOL(CLogDataItem, 1000);
public:
	void GetLevel(int *penLenvel)
	{
		*penLenvel = m_nLevel;
		return;
	}

	void SetLevel(int nLevel)
	{
		m_nLevel = nLevel;
		return;
	}

	void GetData(unsigned char **ppdata,int *pndatalen)
	{
		*ppdata = (unsigned char*)m_objLGrowBuf.getPointer();
		*pndatalen = m_objLGrowBuf.getLength();
		return;
	}

	void SetData(unsigned char *pdata,int ndatalen)
	{
		m_objLGrowBuf.truncate(0);
		m_objLGrowBuf.append((char*)pdata,ndatalen);
		return;
	}
	CLogDataItem()
	{
		Init();
	}
	~CLogDataItem()
	{
		Uninit();
	}
	int Init()
	{
		m_objLGrowBuf.truncate(0);
		m_nLevel = KDLOG_DEBUG;
		return 0;
	}
	int Uninit()
	{
		return 0;
	}
private:
	CLGrowBuf m_objLGrowBuf;
	int m_nLevel;
};

class CLogThread: public CLCommThread
{
public:
	CLogThread() { }
	virtual ~CLogThread() { }
	int Run();
};

class CLogCallBack
{
public:
	virtual void OnLog(void *pdata,int ndatalen)
	{
	}
	virtual ~CLogCallBack(){}
};

class CKDLog:public CLBaseError
{
	friend class CLogThread;
public:
	CKDLog();
	virtual ~CKDLog();

	void SetCallBack(CLogCallBack *pcllogcallback);
	// ·����Ҫ��/ ���� ��֧��\����
	int SetLogFilePath(char *lpszFilePath);
	int SetLogFileName(char *lpszfilename);

	// ����ĳ�������ϲŴ�ӡ��־
	int	SetLogLevel(int nSetLevel);
	int GetLogLevel();

	// ���ô����򲻴���
	int	SetLogLevel_Special(int nSetLevel_Special);
	int GetLogLevel_Special();

public:
	int WriteLog(int nLevel,const char* pszLog, ...);
	int WriteLog(int nLevel,const unsigned char* pdata,int ndatalen);

	static int InitKmdsLog();
	/*************************************************
	Function:       WriteLog
	Description:    д��־
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
	static int WriteKmdsLog(int nLevel,const char* pszLog, ...);
	static int WriteKmdsLog_Len(int nLevel,const void* pData, int nDataLen);
	static int WriteDebugKmdsLog(int nline,const char* pszfile,const char* pszLog, ...);
	/*************************************************
	Function:       ReleaseLog
	Description:    �ͷ���־��Դ
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
	static int ReleaseKmdsLog();

	// �ڴ�����־
	static int WriteMemoryKmdsLog(void* pDataAddress,int nDatalen,int nLineByte);

	// ������
	static int WriteBinaryKmdsLog(unsigned char* pData,int nDatalen);

	// ��ȡ��־��ָ��
	static CKDLog* GetKmdsLog();
	static int SetKmdsLevel_Special(int nSetLevel_Special);
	static int SetKmdsLevel(int nSetLevel);
	// ����д��־(Ĭ���Ѿ�����)
	static int StartKmdsLog();
	// ֹͣд��־
	static int StopKmdsLog();
private:
	void GetNowDate(char *datestr,char *format);
	int StartLog();
	int StopLog();
	// �Ӷ��������ȡ����д����־
	int QueueDataToFile();
	// ���ݷ������
	int PutQueue(void* pdata,int ndatalen,int nLevel);
	// ������־����
	int ProcessLogLevel(int nLevel,void* pdata, int nheadlen,int ndatalen);

	int OpenLogFile();
	void CloseLogFile();
	// ֧�ֶ�����д  nmode:1 ����ǰ����д���ǰ��������ʱ��
	int WriteLogFile(const unsigned char* pszdata,int nsize,int nLevel,int nmode = 1);

	// �жϴ���10M�������½�һ���ļ�
	int CheckLogFileLen(struct tm* ptm);
private:
	CLogCallBack *m_pcllogcallback;
	// �Ƿ����������
	bool m_bQueueVaild;
	// �߳���־�Ƿ�����
	bool m_bLogRuning;
	CLogThread m_cl_thread;

	CQueue<void *> m_clqueue;

	char m_szFilePath[MAX_PATH];
	char m_szFileName[MAX_PATH];
	FILE *m_plog_file;
	int  m_nLevel_Special;                //��־����(�������)
	int  m_nLevel;						  //��־����

	int m_nfilesize;
	int  m_nlognum;
	bool m_bIsSetPath;
	bool m_bIsSetLogName;
	char m_szSetFilePath[MAX_PATH];
	char m_szSetFileName[MAX_PATH];

	int  m_ndata;
	CriticalSection m_cl_lock;
};
#endif // __KDLOG_H__
