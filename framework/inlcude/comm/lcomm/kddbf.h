/********************************************************************
*                     数据服务总线系统(KMDS) V1.0
*
*           Copyright (C) 2012-2013, SHENZHEN KINGDOM Co., Ltd.
*
*                         All Rights Reserved.
* ===================================================================
* 
* 文 件 名：KDDbf.h
* 模块名称：跨平台dbf文件操作类
* 功能说明：获取dbf数据
* 作    者：lind
* 创建日期：2013-7-26
* 版 本 号：1.0
* 修改历史：
*
* 修改日期                姓名            内容
* --------------------------------------------------------------------
* 2013-7-26               lind            初始版本
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
	// dbf文件头信息
	DBFHEADER			    m_DbfHeader;
	// dbf所有字段信息
	DBFFIELDINFO		    m_DbfFieldInfo[MAX_DBFFIELDNUM];
	// 字段总数即列数
	unsigned int		    m_dwFieldNum;
	// dbf文件记录所有数据
	char					*m_szDbfRecord;     //Lanq 修改为动态创建
	// dbf文件名
	char				    m_szDbfFileName[1024];
	// dbf文件指针
	CKDFile*		        m_pcl_DbfFile;
public:
	
	/*************************************************
	函  数:    SetFileName
	功  能:    打开dbf文件，读取dbf文件头（包括数据说明和字段说明）和文件记录
	入  参:	   char * pszDbfFileName         Y    dbf文件名
	出  参:
	返回值:    0表成功
			   -1表示打开文件失败，-2表示读取文件头失败，-3表示读取文件记录失败
	其  他:               
	*************************************************/
	int SetFileName(char * pszDbfFileName);
	
	/*************************************************
	函  数:    ReReadRecorderOne
	功  能:    重读一条记录      
	入  参:	   unsigned int dwRecordNo      Y    记录序号，从0开始，表示读取第一条记录
	出  参:    
	返回值:    0表示成功，其他失败
	其  他:               
	*************************************************/
	int ReReadRecorderOne(unsigned int dwRecordNo);

	/*************************************************
	函  数:    ReadHead
	功  能:    读取dbf文件头     
	出  参:
	返回值:    0表示成功，其他失败
	其  他:               
	*************************************************/
	int ReadHead();

	/*************************************************
	函  数:    ReadBody
	功  能:    读取dbf文件记录     
	出  参:
	返回值:    0表示成功，其他失败
	其  他:               
	*************************************************/
	int ReadBody();

	/*************************************************
	函  数:    GetRecordPtr
	功  能:    传入指针指向当前文件记录当前行数据    
	入  参:	   
	出  参:    char *  * ppRecordPtr          Y      数据指针
	返回值:    0表示成功，其他失败
	其  他:               
	*************************************************/
	int GetRecordPtr(char * *ppRecordPtr);

	/*************************************************
	函  数:    GetFieldNum
	功  能:    获取dbf文件字段数及dbf文件列数     
	入  参:	   
	出  参:    unsigned int * pdwFieldNum   Y           dbf文件列数
	返回值:    0表示成功，其他失败
	其  他:               
	*************************************************/
	int GetFieldNum(unsigned int *pdwFieldNum);

	/*************************************************
	函  数:    GetRecordLength
	功  能:    获取单条文件记录长度      
	入  参:	   
	出  参:    unsigned int * pdwRecordLength    Y      单条文件记录长度 
	返回值:    0表示成功，其他失败
	其  他:               
	*************************************************/
	int GetRecordLength(unsigned int *pdwRecordLength);

	/*************************************************
	函  数:    GetRecordNum
	功  能:    获取文件记录总条数      
	入  参:	   
	出  参:    unsigned int * pdwRecordNum    Y    文件记录总条数
	返回值:    0表示成功，其他失败
	其  他:               
	*************************************************/
	int GetRecordNum(unsigned int *pdwRecordNum);

	/*************************************************
	函  数:    Goto
	功  能:    跳转到dbf第dwRecordNo行     
	入  参:	   unsigned int dwRecordNo    Y   记录序号，从0开始
	出  参:
	返回值:    0表示成功，其他失败
	其  他:               
	*************************************************/
	int Goto(unsigned int dwRecordNo);

	/*************************************************
	函  数:    GetDbfXXX
	功  能:    获取当前行第dwFiled列数据     
	入  参:	   unsigned int dwFiled    Y   字段序号，从0开始
	出  参:
	返回值:    0表示成功，其他失败
	其  他:    以下7个函数均表示获取dbf具体单元格数据            
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
	函  数:    Init
	功  能:    初始化dbf文件     
	出  参:
	返回值:    0表示成功，其他失败
	其  他:               
	*************************************************/
	int Init();

	/*************************************************
	函  数:    Clear
	功  能:    关闭dbf文件，释放文件指针     
	出  参:
	返回值:    0表示成功，其他失败
	其  他:               
	*************************************************/
	int Clear();

	/*************************************************
	函  数:    Reopen
	功  能:    重新打开dbf文件      
	出  参:
	返回值:    0表示成功，其他失败
	其  他:               
	*************************************************/
	int Reopen();
private:
	// 当前记录数据
	char *m_pcurrent_record;
	// dbf文件状态
	EM_DBF_STATUS m_ndbf_status;
};

#endif // _KDDBF_H__

//#endif // !defined(AFX_KDDBF_H__51C1184F_DA2B_4E00_8300_5324B0CF0D77__INCLUDED_)
