/********************************************************************
*                     ���ݷ�������ϵͳ(KMDS) V1.0
*
*           Copyright (C) 2012-2013, SHENZHEN KINGDOM Co., Ltd.
*
*                         All Rights Reserved.
* ===================================================================
* 
* �� �� ����KDDbf.h
* ģ�����ƣ���ƽ̨dbf�ļ�������
* ����˵������ȡdbf����
* ��    �ߣ�lind
* �������ڣ�2013-7-26
* �� �� �ţ�1.0
* �޸���ʷ��
*
* �޸�����                ����            ����
* --------------------------------------------------------------------
* 2013-7-26               lind            ��ʼ�汾
**********************************************************************/

/*#if !defined(AFX_KDDBF_H__51C1184F_DA2B_4E00_8300_5324B0CF0D77__INCLUDED_)
#define AFX_KDDBF_H__51C1184F_DA2B_4E00_8300_5324B0CF0D77__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000*/

#ifndef __KDDBF_H__
#define __KDDBF_H__

#include <datatype/datatype.h>
#include <lcomm/publicdef.h>
#include "kddbfstruct.h"

/////////////////////////////////////////////////////////////////////////////
// CKDDbf

enum EM_DBF_STATUS
{
	EM_DBF_STATUS_NONE = 0,
	EM_DBF_STATUS_OPEN,
	EM_DBF_STATUS_HEAD,
	EM_DBF_STATUS_BODY
};

class CKDFile;
class CKDDbf 
{
public:
	CKDDbf();
	virtual ~CKDDbf();

private:
	// dbf�ļ�ͷ��Ϣ
	DBFHEADER			    m_DbfHeader;
	// dbf�����ֶ���Ϣ
	DBFFIELDINFO		    m_DbfFieldInfo[MAX_DBFFIELDNUM];
	// �ֶ�����������
	unsigned int		    m_dwFieldNum;
	// dbf�ļ���¼��������
	char					*m_szDbfRecord;     //Lanq �޸�Ϊ��̬����
	// dbf�ļ���
	char				    m_szDbfFileName[1024];
	// dbf�ļ�ָ��
	CKDFile*		        m_pcl_DbfFile;
public:
	
	/*************************************************
	��  ��:    SetFileName
	��  ��:    ��dbf�ļ�����ȡdbf�ļ�ͷ����������˵�����ֶ�˵�������ļ���¼
	��  ��:	   char * pszDbfFileName         Y    dbf�ļ���
	��  ��:
	����ֵ:    0��ɹ�
			   -1��ʾ���ļ�ʧ�ܣ�-2��ʾ��ȡ�ļ�ͷʧ�ܣ�-3��ʾ��ȡ�ļ���¼ʧ��
	��  ��:               
	*************************************************/
	int SetFileName(char * pszDbfFileName);
	
	/*************************************************
	��  ��:    ReReadRecorderOne
	��  ��:    �ض�һ����¼      
	��  ��:	   unsigned int dwRecordNo      Y    ��¼��ţ���0��ʼ����ʾ��ȡ��һ����¼
	��  ��:    
	����ֵ:    0��ʾ�ɹ�������ʧ��
	��  ��:               
	*************************************************/
	int ReReadRecorderOne(unsigned int dwRecordNo);

	/*************************************************
	��  ��:    ReadHead
	��  ��:    ��ȡdbf�ļ�ͷ     
	��  ��:
	����ֵ:    0��ʾ�ɹ�������ʧ��
	��  ��:               
	*************************************************/
	int ReadHead();

	/*************************************************
	��  ��:    ReadBody
	��  ��:    ��ȡdbf�ļ���¼     
	��  ��:
	����ֵ:    0��ʾ�ɹ�������ʧ��
	��  ��:               
	*************************************************/
	int ReadBody();

	/*************************************************
	��  ��:    GetRecordPtr
	��  ��:    ����ָ��ָ��ǰ�ļ���¼��ǰ������    
	��  ��:	   
	��  ��:    char *  * ppRecordPtr          Y      ����ָ��
	����ֵ:    0��ʾ�ɹ�������ʧ��
	��  ��:               
	*************************************************/
	int GetRecordPtr(char * *ppRecordPtr);

	/*************************************************
	��  ��:    GetFieldNum
	��  ��:    ��ȡdbf�ļ��ֶ�����dbf�ļ�����     
	��  ��:	   
	��  ��:    unsigned int * pdwFieldNum   Y           dbf�ļ�����
	����ֵ:    0��ʾ�ɹ�������ʧ��
	��  ��:               
	*************************************************/
	int GetFieldNum(unsigned int *pdwFieldNum);

	/*************************************************
	��  ��:    GetRecordLength
	��  ��:    ��ȡ�����ļ���¼����      
	��  ��:	   
	��  ��:    unsigned int * pdwRecordLength    Y      �����ļ���¼���� 
	����ֵ:    0��ʾ�ɹ�������ʧ��
	��  ��:               
	*************************************************/
	int GetRecordLength(unsigned int *pdwRecordLength);

	/*************************************************
	��  ��:    GetRecordNum
	��  ��:    ��ȡ�ļ���¼������      
	��  ��:	   
	��  ��:    unsigned int * pdwRecordNum    Y    �ļ���¼������
	����ֵ:    0��ʾ�ɹ�������ʧ��
	��  ��:               
	*************************************************/
	int GetRecordNum(unsigned int *pdwRecordNum);

	/*************************************************
	��  ��:    Goto
	��  ��:    ��ת��dbf��dwRecordNo��     
	��  ��:	   unsigned int dwRecordNo    Y   ��¼��ţ���0��ʼ
	��  ��:
	����ֵ:    0��ʾ�ɹ�������ʧ��
	��  ��:               
	*************************************************/
	int Goto(unsigned int dwRecordNo);

	/*************************************************
	��  ��:    GetDbfXXX
	��  ��:    ��ȡ��ǰ�е�dwFiled������     
	��  ��:	   unsigned int dwFiled    Y   �ֶ���ţ���0��ʼ
	��  ��:
	����ֵ:    0��ʾ�ɹ�������ʧ��
	��  ��:    ����7����������ʾ��ȡdbf���嵥Ԫ������            
	*************************************************/
	int GetDbfDword(unsigned int dwFiled, unsigned int *pdwValue);
	int GetDbfFloat(unsigned int dwFieldNo, float *pfValue);
	int GetDbfDouble(unsigned int dwFieldNo, double *pdbValue);
	int GetDbfInt(unsigned int dwFieldNo, int *pIntValue);
	int GetDbfInt64(unsigned int dwFieldNo, int64 *pIntValue);
	int GetDbfUInt64(unsigned int dwFieldNo, uint64 *pIntValue);
	int GetDbfString(unsigned int dwFieldNo, char * pszBuf, int nmaxlen);

	int GetRateDbfString(unsigned int dwFieldNo, char * pszBuf, int nMaxLen, int nRate = PRICE_RATE_DIGIT);
	int GetRateDbfInt32(unsigned int dwFieldNo, int *pnValue, int nRate = PRICE_RATE_DIGIT);
	int GetRateDbfInt64(unsigned int dwFieldNo, int64 *pnValue, int nRate = PRICE_RATE_DIGIT);

private:
	/*************************************************
	��  ��:    Init
	��  ��:    ��ʼ��dbf�ļ�     
	��  ��:
	����ֵ:    0��ʾ�ɹ�������ʧ��
	��  ��:               
	*************************************************/
	int Init();

	/*************************************************
	��  ��:    Clear
	��  ��:    �ر�dbf�ļ����ͷ��ļ�ָ��     
	��  ��:
	����ֵ:    0��ʾ�ɹ�������ʧ��
	��  ��:               
	*************************************************/
	int Clear();

	/*************************************************
	��  ��:    Reopen
	��  ��:    ���´�dbf�ļ�      
	��  ��:
	����ֵ:    0��ʾ�ɹ�������ʧ��
	��  ��:               
	*************************************************/
	int Reopen();
private:
	// ��ǰ��¼����
	char *m_pcurrent_record;
	// dbf�ļ�״̬
	EM_DBF_STATUS m_ndbf_status;
};

#endif // _KDDBF_H__

//#endif // !defined(AFX_KDDBF_H__51C1184F_DA2B_4E00_8300_5324B0CF0D77__INCLUDED_)
