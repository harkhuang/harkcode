/******************************************************************************
*
*									KMDS V1.0
*
*           Copyright (C) 2012-2013, SHENZHEN KINGDOM Co., Ltd.
*
*                             All Rights Reserved.
*
* ===========================================================================
*
* �� �� ����publicdef.h
* ģ�����ƣ�������
* ����˵�������������궨��
* ��    �ߣ�liulj
* �������ڣ�2013-07-20
* �� �� �ţ�1.0
* �޸���ʷ��
*
* �޸�����       ����            ����
* ---------------------------------------------------------------------------
* 2013-07-20     liulj         ��ʼ�汾
*
******************************************************************************/
#ifndef  __PUBLICDEF_H__
#define  __PUBLICDEF_H__

#include <assert.h>

// ����ת���궨��
// �۸���
#define   PRICE_RATE       10000
#define   PRICE_RATE_DIGIT 4

#ifndef MAX_BUF_LEN
#define MAX_BUF_LEN       1024   // ������ݻ��泤��
#endif
#ifndef MAX_FILE_PATH
#define MAX_FILE_PATH     256    // ���·������
#endif
#define MAX_SRC_LEN       64     // ���֤ȯ��ʶ����
#define MAX_TXN_TP_LEN    10     // ����������ͳ���
#define MAX_ENTRT_NBR     50     // ί����ϸ����
#define MAX_ORDR_NBR_LEN  1024   // ������ϸ��󳤶�
#define MAX_SRC_NAME_LEN  256    // ������Ƴ���
#define MAX_USER_LEN      128    // ����û�������
#define MAX_PWD_LEN       64     // ������볤��
#define MAX_HQ_TYPE_LEN   16     // ��������(��������)
#define MAX_PUBLISH_ID_LEN 4     // �����ڵ�(��������)
#define MAX_NUMBER_LEN    48     // ������ֳ���
#define MAX_BASEBUF_LEN   256    // ���������泤��
#define MAX_NAME_LEN      256    // ������Ƴ���
#define MAX_SERVERID_LEN  128    // ����������ַ����
#define MAX_FUTURES_LEVLE_LEN 5  // ����ڻ��۸�λ
#define MAX_HQ_POOL       100000  // �ڴ��������ָ�����
#define MAX_HQ_SIZE       10     // �ڴ��������ָ��malloc��С
#define MAX_CMD_ID        64     // �������������ID����

// kmds���Ժ�
#ifdef _DEBUG
#define KMDSASSERT(exp) assert(exp)
#else
#define KMDSASSERT(exp)
#endif

// ��־����������
#ifndef DEF_LOGBUF_LEN
#define DEF_LOGBUF_LEN (1024*4)
#endif
// �ļ�������СΪ10M  ����10M���½�һ��
#ifndef __MAX_FILEZIE__
#define __MAX_FILEZIE__ (1024*1024*10)
#endif
#ifndef __FILENAMEBUF__
#define __FILENAMEBUF__ "user_data"
#endif
//========================================================================================
//��־
#ifndef _DEF_KDLOG_TYPE_
#define _DEF_KDLOG_TYPE_
// ��־�����Ϊ�������  �ֱ�Ϊ д��־����Ļ  д��־������Ļ  ��д��־����Ļ  ��д��־������Ļ
enum EN_SET_KDLOGLEVEL
{
	// ���漶����Ҫ����SetLogLevel��Ч
	SET_KDLOG_DEF = 0,				// Ĭ�ϼ���	������û����ü����ӡ��־
	SET_KDLOG_PRINTANDWRITE,		// д��־����Ļ
	SET_KDLOG_ONLYWRITE,			// д��־������Ļ
	SET_KDLOG_ONLYPRINT,			// ��д��־����Ļ
	SET_KDLOG_END					// ��д��־������Ļ
};
enum EN_KDLOGLEVEL
{
	KDLOG_DEBUG = 100,	// ��־������Ϣ�����ڵ���ʱ��ʾ����Ļ�ϡ�ͬʱ����¼���ļ��� release�治���ӡ��־
	KDLOG_TIPS,			// ��ʾ��Ϣ ��������־(������)
	KDLOG_FILE,			// ��¼����־����¼���ļ��С� Ĭ�ϲ�����
	KDLOG_BIZ,			// ��ӡ�����ƴ� Ĭ�ϲ�����
	KDLOG_WARNING,		// ������־��ͻ����ʾ Ĭ�ϴ���
	KDLOG_ERROR,		// ������־��ͻ����ʾ ����(��������д��־)
	KDLOG_SYSTEM		// ����ϵͳ��־ ����(��������д��־)
};
#endif

//========================================================================================
//UI
#ifndef  __KDSERVER_UI__TYPE_
#define  __KDSERVER_UI__TYPE_
enum
{
	TT_TREEVIEW_ADD = 0,
	TT_TREEVIEW_DEL,
	TT_TREEVIEW_DELALL,
	TT_TREEVIEW_GETVIEWCOUNT,
	TT_TREEVIEW_END = TT_TREEVIEW_DELALL,

	TT_LOG = TT_TREEVIEW_DELALL + 1,
	TT_END
};
#endif
#endif

