#ifndef _KMDSLOG_H_
#define _KMDSLOG_H_

#include <lcomm/publicdef.h>
#include <lcomm/kdlog.h>

#define KMDS_LOG_INIT		CKDLog::InitKmdsLog();
#define KMDS_LOG_UNINIT		CKDLog::ReleaseKmdsLog();
#define KMDS_LOG_GET		CKDLog::GetKmdsLog();

// ����д��־(Ĭ���Ѿ�����)
#define KMDS_LOG_START		CKDLog::StartKmdsLog();
// ֹͣд��־
#define KMDS_LOG_STOP		CKDLog::StopKmdsLog();

//  ������־����
#define KMDS_LOG_SETLEVEL_SPECIAL(enLevel)	CKDLog::SetKmdsLevel_Special(enLevel);
#define KMDS_LOG_SETLEVEL(enLevel)	CKDLog::SetKmdsLevel(enLevel);

// �ڴ�����־ nLineByte:һ�д�ӡ���ٸ��ֽ�
#define KMDS_LOG_WRITE_MEMORY(pDataAddress,nDatalen,nLineByte) CKDLog::WriteMemoryKmdsLog(pDataAddress,nDatalen,nLineByte);
// д����������
#define KMDS_LOG_WRITE_BINARY(pData,nDataLen)		   CKDLog::WriteBinaryKmdsLog(pData,nDataLen);

#define KMDS_LOG_WRITE_LEN(enLevel,pData,nDataLen)		CKDLog::WriteKmdsLog_Len(enLevel,pData,nDataLen);

#if defined(_MSC_VER)
#define KMDS_LOG_WRITE(enLevel,szLogBuf,...)		CKDLog::WriteKmdsLog(enLevel,szLogBuf,__VA_ARGS__);
// release�治���ӡ��־
#define KMDS_LOG_WRITE_DEBUG(szLogBuf,...)		CKDLog::WriteDebugKmdsLog(__LINE__,__FILE__,szLogBuf,__VA_ARGS__);
#else
#define KMDS_LOG_WRITE(enLevel,szLogBuf,...)		CKDLog::WriteKmdsLog(enLevel,szLogBuf,##__VA_ARGS__);
#define KMDS_LOG_WRITE_DEBUG(szLogBuf,...)		CKDLog::WriteDebugKmdsLog(__LINE__,__FILE__,szLogBuf,##__VA_ARGS__);
#endif

#endif
// ע��:ʹ����֮����Ҫ��ʽ����KMDS_LOG_UNINIT
/***************************************
// ʹ��ʵ��
#include <prj/kdlog/kmdslog.h>
int main()
{
	// ֻ��Ҫ�ڳ���������ʱ���ʼ��һ��  ����Ҫÿ�ζ���ʼ��
	KMDS_LOG_INIT

	...
	KMDS_LOG_WRITE_DEBUG("���Գ�������%s","����");
	KMDS_LOG_WRITE(KDLOG_DEBUG,"���Գ�������%s","����");
	...

	// �����˳���Ҫ�ͷ���־
	KMDS_LOG_UNINIT
}
***************************************/