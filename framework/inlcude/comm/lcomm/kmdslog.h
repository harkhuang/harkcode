#ifndef _KMDSLOG_H_
#define _KMDSLOG_H_

#include <lcomm/publicdef.h>
#include <lcomm/kdlog.h>

#define KMDS_LOG_INIT		CKDLog::InitKmdsLog();
#define KMDS_LOG_UNINIT		CKDLog::ReleaseKmdsLog();
#define KMDS_LOG_GET		CKDLog::GetKmdsLog();

// 启动写日志(默认已经启动)
#define KMDS_LOG_START		CKDLog::StartKmdsLog();
// 停止写日志
#define KMDS_LOG_STOP		CKDLog::StopKmdsLog();

//  设置日志级别
#define KMDS_LOG_SETLEVEL_SPECIAL(enLevel)	CKDLog::SetKmdsLevel_Special(enLevel);
#define KMDS_LOG_SETLEVEL(enLevel)	CKDLog::SetKmdsLevel(enLevel);

// 内存块打日志 nLineByte:一行打印多少个字节
#define KMDS_LOG_WRITE_MEMORY(pDataAddress,nDatalen,nLineByte) CKDLog::WriteMemoryKmdsLog(pDataAddress,nDatalen,nLineByte);
// 写二进制数据
#define KMDS_LOG_WRITE_BINARY(pData,nDataLen)		   CKDLog::WriteBinaryKmdsLog(pData,nDataLen);

#define KMDS_LOG_WRITE_LEN(enLevel,pData,nDataLen)		CKDLog::WriteKmdsLog_Len(enLevel,pData,nDataLen);

#if defined(_MSC_VER)
#define KMDS_LOG_WRITE(enLevel,szLogBuf,...)		CKDLog::WriteKmdsLog(enLevel,szLogBuf,__VA_ARGS__);
// release版不会打印日志
#define KMDS_LOG_WRITE_DEBUG(szLogBuf,...)		CKDLog::WriteDebugKmdsLog(__LINE__,__FILE__,szLogBuf,__VA_ARGS__);
#else
#define KMDS_LOG_WRITE(enLevel,szLogBuf,...)		CKDLog::WriteKmdsLog(enLevel,szLogBuf,##__VA_ARGS__);
#define KMDS_LOG_WRITE_DEBUG(szLogBuf,...)		CKDLog::WriteDebugKmdsLog(__LINE__,__FILE__,szLogBuf,##__VA_ARGS__);
#endif

#endif
// 注意:使用完之后需要显式调用KMDS_LOG_UNINIT
/***************************************
// 使用实例
#include <prj/kdlog/kmdslog.h>
int main()
{
	// 只需要在程序启动的时候初始化一次  不需要每次都初始化
	KMDS_LOG_INIT

	...
	KMDS_LOG_WRITE_DEBUG("测试程序启动%s","测试");
	KMDS_LOG_WRITE(KDLOG_DEBUG,"测试程序启动%s","测试");
	...

	// 程序退出需要释放日志
	KMDS_LOG_UNINIT
}
***************************************/