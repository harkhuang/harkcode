
/********************************************************************
*                     ���ݷ�������ϵͳ(KMDS) V1.0
*
*           Copyright (C) 2012-2013, SHENZHEN KINGDOM Co., Ltd.
*
*                         All Rights Reserved.
* ===================================================================
* 
* �� �� ����kdfile.h
* ģ�����ƣ���ƽ̨�ļ�������
* ����˵�����򿪡�����������д�ļ��Ȼ����ļ���������
* ��    �ߣ�lind
* �������ڣ�2013-7-26
* �� �� �ţ�1.0
* �޸���ʷ��
*
* �޸�����                ����            ����
* --------------------------------------------------------------------
* 2013-7-26               lind            ��ʼ�汾
**********************************************************************/

#ifndef __KDFILE_INCLUDE_H__
#define __KDFILE_INCLUDE_H__

#ifdef _WIN32
#include <windows.h>
#else
#include <win32com/linuxcomadapter.h>
#endif
#include<stdio.h> // �¼�
#include "baseerror.h"

enum ENUM_FILE_MODE
{
	ENUM_FILE_MODE_READ = 0,  // �ļ�ֻ��
	ENUM_FILE_MODE_WRITE      // �ļ���д
};

class CKDFile : public CLBaseError
{
public:

	/*************************************************
	��  ��:    CreateFile
	��  ��:    ��д�򿪻򴴽�һ���������ļ�      
	��  ��:	   char * pszFileName       Y      �ļ���
	��  ��:	   char * pszBuf          N  ����ģʽ
	                                     Ĭ��NULL��ʾ�޻���ģʽ
										 ȫ���壺char szBuf[BUFSIZ] ����BUFSIZ��stdio.h�ж���
	��  ��:
	����ֵ:    S_OK��ʾ�ɹ��� E_FAILʧ��
	��  ��:               
	*************************************************/
	HRESULT		CreateFile(char * pszFileName,  char *pszBuf = NULL);


	/*************************************************
	��  ��:    OpenFileAlways
	��  ��:    �Զ����ƶ�ģʽ���ļ�     
	��  ��:	   char * pszFileName       Y      �ļ���
	��  ��:
	����ֵ:    S_OK��ʾ�ɹ��� E_FAILʧ��
	��  ��:               
	*************************************************/
	HRESULT		OpenFileAlways(char * pszFileName);


	/*************************************************
	��  ��:    Empty
	��  ��:    ��յ�ǰ���򿪵��ļ�     
	��  ��:	   void
	��  ��:
	����ֵ:    S_OK��ʾ�ɹ��� E_FAILʧ��
	��  ��:               
	*************************************************/
	HRESULT		Empty(void);


	/*************************************************
	��  ��:    SetFilePointer
	��  ��:    �����ļ�ָ���λ��      
	��  ��:	   INT iOffset    Y      ָ��ƫ����
	��  ��:	   DWORD dwPos    N      ��ʼλ��
	��  ��:
	����ֵ:    S_OK��ʾ�ɹ��� E_FAILʧ��
	��  ��:               
	*************************************************/
	HRESULT		SetFilePointer(INT iOffset, int dwPos = SEEK_END);


	/*************************************************
	��  ��:    GetFilePointer
	��  ��:    ��ȡ�ļ�ָ�뵱ǰλ��      
	��  ��:	   
	��  ��:    INT & iOffset   Y    ָ�뵱ǰλ��
	����ֵ:    S_OK��ʾ�ɹ��� E_FAILʧ��
	��  ��:               
	*************************************************/
	HRESULT		GetFilePointer(INT &iOffset);


	/*************************************************
	��  ��:    GetFileSize
	��  ��:    ��ȡ�ļ���С      
	��  ��:	   
	��  ��:    DWORD * pdwFileSize     Y       �ļ���С
	����ֵ:    S_OK��ʾ�ɹ��� E_FAILʧ��
	��  ��:               
	*************************************************/
	HRESULT		GetFileSize(INT *pdwFileSize);


	/*************************************************
	��  ��:    WriteFile
	��  ��:    д�ļ�      
	��  ��:	   char * pszBuf      Y      д�������
	��  ��:	   int uLen           Y      д�����ݵĳ���
	��  ��:
	����ֵ:    S_OK��ʾ�ɹ��� E_FAILʧ��
	��  ��:               
	*************************************************/
	HRESULT		WriteFile(char * pszBuf, int uLen);


	/*************************************************
	��  ��:    ReadFile
	��  ��:    ���ļ�     
	��  ��:	   LPTSTR pszBuf      Y      ���ڽ��ն�ȡ���ݵ��ڴ��ַ    
	��  ��:	   int uLen           Y      ��ȡ���ݵĳ��� 
	��  ��:
	����ֵ:    S_OK��ʾ�ɹ��� E_FAILʧ��
	��  ��:    ��ȡnLen��Ԫ�ص�pszBuf�� ����Ԫ�ش�СΪsizeof(char)        
	*************************************************/
	HRESULT		ReadFile(LPTSTR pszBuf, int uLen);


	/*************************************************
	��  ��:    CloseFile
	��  ��:    �ر��ļ�     
	��  ��:	   void
	��  ��:
	����ֵ:    S_OK��ʾ�ɹ��� E_FAILʧ��
	��  ��:               
	*************************************************/
	HRESULT		CloseFile(void);


	/*************************************************
	��  ��:    OpenFile
	��  ��:    �޻���ģʽ���ļ�      
	��  ��:	   char * pszFileName     Y  �ļ���
	��  ��:	   char * pszMode         Y  ����̬����"r","w","rb+"��
	��  ��:	   char * pszBuf          N  ����ģʽ
	                                     Ĭ��NULL��ʾ�޻���ģʽ
										 ȫ���壺char szBuf[BUFSIZ] ����BUFSIZ��stdio.h�ж���
	��  ��:
	����ֵ:    S_OK��ʾ�ɹ��� E_FAILʧ��
	��  ��:    linux�½���ʹ���޻��巽ʽ           
	*************************************************/
	HRESULT     OpenFile(char *pszFileName, char *pszMode, char *pszBuf = NULL);


	/*************************************************
	��  ��:    IsExists
	��  ��:    �ж��ļ��Ƿ����      
	��  ��:	   char * lpszfilename       Y   �ļ���
	��  ��:
	����ֵ:    true��ʾ�ɹ��� false��ʾʧ��
	��  ��:               
	*************************************************/
	bool        IsExists(char *lpszfilename);


	/*************************************************
	��  ��:    IsOpen
	��  ��:          
	��  ��:
	����ֵ:    true��ʾ�ɹ��� false��ʾʧ��
	��  ��:               
	*************************************************/
	bool 		IsOpen();

	CKDFile();
	virtual ~CKDFile();


	/*************************************************
	��  ��:    ReadFileRetLen
	��  ��:    ���ļ�     
	��  ��:	   char *pbuf         Y      ���ڽ��ն�ȡ���ݵ��ڴ��ַ    
	��  ��:	   int nlen           Y      ��ȡ���ݵĳ��� 
	��  ��:
	����ֵ:    ʵ�ʶ�ȡ������
	��  ��:    ��ȡnLen��Ԫ�ص�pszBuf�� ����Ԫ�ش�СΪsizeof(char)        
	*************************************************/
	int		ReadFileRetLen(char *pbuf, int nlen);

private:
	// �ļ�ָ��
	FILE        *m_pFile;
	// д�ļ���ʶ
	int          m_nWriteFlag;
};

#endif // __KDFILE_INCLUDE_H__
