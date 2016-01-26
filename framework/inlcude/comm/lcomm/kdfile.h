
/********************************************************************
*                     数据服务总线系统(KMDS) V1.0
*
*           Copyright (C) 2012-2013, SHENZHEN KINGDOM Co., Ltd.
*
*                         All Rights Reserved.
* ===================================================================
* 
* 文 件 名：kdfile.h
* 模块名称：跨平台文件操作类
* 功能说明：打开、创建、读、写文件等基本文件操作函数
* 作    者：lind
* 创建日期：2013-7-26
* 版 本 号：1.0
* 修改历史：
*
* 修改日期                姓名            内容
* --------------------------------------------------------------------
* 2013-7-26               lind            初始版本
**********************************************************************/

#ifndef __KDFILE_INCLUDE_H__
#define __KDFILE_INCLUDE_H__

#ifdef _WIN32
#include <windows.h>
#else
#include <win32com/linuxcomadapter.h>
#endif
#include<stdio.h> // 新加
#include "baseerror.h"

enum ENUM_FILE_MODE
{
	ENUM_FILE_MODE_READ = 0,  // 文件只读
	ENUM_FILE_MODE_WRITE      // 文件可写
};

class CKDFile : public CLBaseError
{
public:

	/*************************************************
	函  数:    CreateFile
	功  能:    读写打开或创建一个二进制文件      
	入  参:	   char * pszFileName       Y      文件名
	入  参:	   char * pszBuf          N  缓冲模式
	                                     默认NULL表示无缓冲模式
										 全缓冲：char szBuf[BUFSIZ] 其中BUFSIZ在stdio.h中定义
	出  参:
	返回值:    S_OK表示成功， E_FAIL失败
	其  他:               
	*************************************************/
	HRESULT		CreateFile(char * pszFileName,  char *pszBuf = NULL);


	/*************************************************
	函  数:    OpenFileAlways
	功  能:    以二进制读模式打开文件     
	入  参:	   char * pszFileName       Y      文件名
	出  参:
	返回值:    S_OK表示成功， E_FAIL失败
	其  他:               
	*************************************************/
	HRESULT		OpenFileAlways(char * pszFileName);


	/*************************************************
	函  数:    Empty
	功  能:    清空当前被打开的文件     
	入  参:	   void
	出  参:
	返回值:    S_OK表示成功， E_FAIL失败
	其  他:               
	*************************************************/
	HRESULT		Empty(void);


	/*************************************************
	函  数:    SetFilePointer
	功  能:    设置文件指针的位置      
	入  参:	   INT iOffset    Y      指针偏移量
	入  参:	   DWORD dwPos    N      起始位置
	出  参:
	返回值:    S_OK表示成功， E_FAIL失败
	其  他:               
	*************************************************/
	HRESULT		SetFilePointer(INT iOffset, int dwPos = SEEK_END);


	/*************************************************
	函  数:    GetFilePointer
	功  能:    获取文件指针当前位置      
	入  参:	   
	出  参:    INT & iOffset   Y    指针当前位置
	返回值:    S_OK表示成功， E_FAIL失败
	其  他:               
	*************************************************/
	HRESULT		GetFilePointer(INT &iOffset);


	/*************************************************
	函  数:    GetFileSize
	功  能:    获取文件大小      
	入  参:	   
	出  参:    DWORD * pdwFileSize     Y       文件大小
	返回值:    S_OK表示成功， E_FAIL失败
	其  他:               
	*************************************************/
	HRESULT		GetFileSize(INT *pdwFileSize);


	/*************************************************
	函  数:    WriteFile
	功  能:    写文件      
	入  参:	   char * pszBuf      Y      写入的数据
	入  参:	   int uLen           Y      写入数据的长度
	出  参:
	返回值:    S_OK表示成功， E_FAIL失败
	其  他:               
	*************************************************/
	HRESULT		WriteFile(char * pszBuf, int uLen);


	/*************************************************
	函  数:    ReadFile
	功  能:    读文件     
	入  参:	   LPTSTR pszBuf      Y      用于接收读取数据的内存地址    
	入  参:	   int uLen           Y      读取数据的长度 
	出  参:
	返回值:    S_OK表示成功， E_FAIL失败
	其  他:    读取nLen个元素到pszBuf， 单个元素大小为sizeof(char)        
	*************************************************/
	HRESULT		ReadFile(LPTSTR pszBuf, int uLen);


	/*************************************************
	函  数:    CloseFile
	功  能:    关闭文件     
	入  参:	   void
	出  参:
	返回值:    S_OK表示成功， E_FAIL失败
	其  他:               
	*************************************************/
	HRESULT		CloseFile(void);


	/*************************************************
	函  数:    OpenFile
	功  能:    无缓冲模式打开文件      
	入  参:	   char * pszFileName     Y  文件名
	入  参:	   char * pszMode         Y  流形态，如"r","w","rb+"等
	入  参:	   char * pszBuf          N  缓冲模式
	                                     默认NULL表示无缓冲模式
										 全缓冲：char szBuf[BUFSIZ] 其中BUFSIZ在stdio.h中定义
	出  参:
	返回值:    S_OK表示成功， E_FAIL失败
	其  他:    linux下建议使用无缓冲方式           
	*************************************************/
	HRESULT     OpenFile(char *pszFileName, char *pszMode, char *pszBuf = NULL);


	/*************************************************
	函  数:    IsExists
	功  能:    判断文件是否存在      
	入  参:	   char * lpszfilename       Y   文件名
	出  参:
	返回值:    true表示成功， false表示失败
	其  他:               
	*************************************************/
	bool        IsExists(char *lpszfilename);


	/*************************************************
	函  数:    IsOpen
	功  能:          
	出  参:
	返回值:    true表示成功， false表示失败
	其  他:               
	*************************************************/
	bool 		IsOpen();

	CKDFile();
	virtual ~CKDFile();


	/*************************************************
	函  数:    ReadFileRetLen
	功  能:    读文件     
	入  参:	   char *pbuf         Y      用于接收读取数据的内存地址    
	入  参:	   int nlen           Y      读取数据的长度 
	出  参:
	返回值:    实际读取到长度
	其  他:    读取nLen个元素到pszBuf， 单个元素大小为sizeof(char)        
	*************************************************/
	int		ReadFileRetLen(char *pbuf, int nlen);

private:
	// 文件指针
	FILE        *m_pFile;
	// 写文件标识
	int          m_nWriteFlag;
};

#endif // __KDFILE_INCLUDE_H__
