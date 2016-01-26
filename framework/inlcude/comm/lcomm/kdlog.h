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
	// 路径需要用/ 区分 不支持\区分
	int SetLogFilePath(char *lpszFilePath);
	int SetLogFileName(char *lpszfilename);

	// 设置某个级别上才打印日志
	int	SetLogLevel(int nSetLevel);
	int GetLogLevel();

	// 设置打屏或不打屏
	int	SetLogLevel_Special(int nSetLevel_Special);
	int GetLogLevel_Special();

public:
	int WriteLog(int nLevel,const char* pszLog, ...);
	int WriteLog(int nLevel,const unsigned char* pdata,int ndatalen);

	static int InitKmdsLog();
	/*************************************************
	Function:       WriteLog
	Description:    写日志
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
	static int WriteKmdsLog(int nLevel,const char* pszLog, ...);
	static int WriteKmdsLog_Len(int nLevel,const void* pData, int nDataLen);
	static int WriteDebugKmdsLog(int nline,const char* pszfile,const char* pszLog, ...);
	/*************************************************
	Function:       ReleaseLog
	Description:    释放日志资源
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
	static int ReleaseKmdsLog();

	// 内存块打日志
	static int WriteMemoryKmdsLog(void* pDataAddress,int nDatalen,int nLineByte);

	// 二进制
	static int WriteBinaryKmdsLog(unsigned char* pData,int nDatalen);

	// 获取日志类指针
	static CKDLog* GetKmdsLog();
	static int SetKmdsLevel_Special(int nSetLevel_Special);
	static int SetKmdsLevel(int nSetLevel);
	// 启动写日志(默认已经启动)
	static int StartKmdsLog();
	// 停止写日志
	static int StopKmdsLog();
private:
	void GetNowDate(char *datestr,char *format);
	int StartLog();
	int StopLog();
	// 从队列里面读取数据写入日志
	int QueueDataToFile();
	// 数据放入队列
	int PutQueue(void* pdata,int ndatalen,int nLevel);
	// 处理日志级别
	int ProcessLogLevel(int nLevel,void* pdata, int nheadlen,int ndatalen);

	int OpenLogFile();
	void CloseLogFile();
	// 支持二进制写  nmode:1 数据前面进行处理前面如增加时间
	int WriteLogFile(const unsigned char* pszdata,int nsize,int nLevel,int nmode = 1);

	// 判断大于10M则重新新建一个文件
	int CheckLogFileLen(struct tm* ptm);
private:
	CLogCallBack *m_pcllogcallback;
	// 是否允许插数据
	bool m_bQueueVaild;
	// 线程日志是否运行
	bool m_bLogRuning;
	CLogThread m_cl_thread;

	CQueue<void *> m_clqueue;

	char m_szFilePath[MAX_PATH];
	char m_szFileName[MAX_PATH];
	FILE *m_plog_file;
	int  m_nLevel_Special;                //日志开关(特殊控制)
	int  m_nLevel;						  //日志开关

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
