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
* �� �� ����msgdata.h
* ģ�����ƣ�������
* ����˵����MsgData��TableData������
* ��    �ߣ�liulj
* �������ڣ�2013-07-20
* �� �� �ţ�1.0
* �޸���ʷ��
*
* �޸�����       ����            ����
* ---------------------------------------------------------------------------
* 2013-07-20     liulj         ��ʼ�汾
* 2013-09-16     malin         ����CDataSerialϵ�л�
******************************************************************************/
#ifndef __MSGDATA_H__
#define __MSGDATA_H__
#include <map>
#include <string>
#include <deque>
#include <string.h>
using namespace std;

/************************************************************************/
/*  windows dll��Ҫ������CMsgData ��CTableData,�����ʱ��Ҫ�� KMDSAPI_EXPORT_DEF KMDSAPI_BUILD_DLL�����������ȷ���ɡ�
            ʹ��dllʱ�����ִ�г������ʱ��Ҫ����KMDSAPI_EXPORT_DEF�궨�塣
	Ĭ�������ʹ�þ�̬��Lib���������ӵģ�������CMsgData��CTableData�ࡣ
            */
/************************************************************************/
#if defined (_WIN32)|| defined(_WIN64)

#  if defined (KMDSAPI_EXPORT_DEF)
#    if defined (KMDSAPI_BUILD_DLL)
#      define MSGDATA_Export __declspec(dllexport)
#    else /* KMDSAPI_BUILD_DLL */
#      define MSGDATA_Export __declspec(dllimport)
#    endif /* KMDSAPI_BUILD_DLL */
#  else 
#    define MSGDATA_Export
#  endif /* KMDSAPI_HAS_DLL == 1 */

#  else /* !_WIN32 || !_WIN64 */
#    define MSGDATA_Export
#  endif /* !_WIN32 || !_WIN64 */

#ifndef NET_TYPEDEFS
#define NET_TYPEDEFS
typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

#if defined(_WIN32) || defined(_WIN64) 
typedef unsigned __int64 uint64;
typedef signed __int64 int64;
#else
typedef long long __int64;
typedef unsigned long long uint64;
typedef signed long long int64;

#endif


typedef signed char int8;
typedef signed short int16;
typedef signed int int32;

#endif

#define DEF_MSGDATA_VER 1
class CPrivateData;
class CLBufData;
class CLGrowBuf;
class CMsgData;
class CTableData;
class CTableDataScan;

// key ��󳤶�
#define DEF_MSGDATAKEY_MAXLEN 64
// ��ά������
#define DEF_TABLEDATA_COLMAX 256

enum EM_DUMP_FORMAT
{	
	EM_DUMP_FORMAT_COLDETAIL	= 0,
	EM_DUMP_FORMAT_ROWMODE	= 0x1000,
	EM_DUMP_FORMAT_ROWMODE_NOTITLE	= 0x1100,
	EM_DUMP_FORMAT_CALLPROGRAM	= 0x2000
};

enum EM_MSGDATA_MODE
{	
	EM_MSGDATA_MODE_NORMAL	= 0x1000,
	EM_MSGDATA_MODE_WITHONLYDATA	= 0x10
};

class CMsgDataName
{
public:
	CMsgDataName()
	{
		m_szname[0] = 0;
	}

	CMsgDataName(CMsgDataName const &rhs);

	CMsgDataName(char *lpszname);

	void Copy(char *lpszname);

	~CMsgDataName()
	{ }


	char *c_str() const
	{
		return (char *)m_szname;
	}

	char m_szname[DEF_MSGDATAKEY_MAXLEN +1];
};

class KeyComp_MsgDataName
{
public:
	enum
	{	// parameters for hash table
		bucket_size = 4,	// 0 < bucket_size
		min_buckets = 8};	// min_buckets = 2 ^^ N, 0 < N

		bool operator()(const CMsgDataName& lhs, const CMsgDataName& rhs) const
		{
			return (strncmp(lhs.m_szname,rhs.m_szname,sizeof(lhs.m_szname) -1) <0)?true:false;
		}
		size_t operator()(const CMsgDataName& lhs) const
		{
			return sizeof(CMsgDataName);
		}
};

#ifndef __KMDS_AUTOREFER_H__
#define __KMDS_AUTOREFER_H__

template <class T> 
class CAutoRefer
{
public: 
	CAutoRefer()
	{
		m_iface = new T;
	}

	CAutoRefer(T *p)
	{
		m_iface = p;
	}

	virtual ~CAutoRefer()
	{
		Release();
	}
	operator T*()
	{
		return m_iface;
	}
	T* operator*() {	return m_iface;  } 
	T** operator&() {	return &m_iface;  } 

	// Return the address being pointed to.  
	T* operator->() { return m_iface; }		


	int Attach(T *pinterface,bool baddref = true)
	{
		if (m_iface == pinterface)
		{
			return 0;
		}

		Release();
		m_iface = pinterface;
		if (baddref)
		{
			m_iface->AddRef();
		}
		return 0;
	}

	int Detech()
	{
		Release();
		return 0;
	}

	T* GetInterface()
	{
		return m_iface;
	}

	void Release()
	{
		if (m_iface)
		{
			m_iface->Release(); 
			m_iface = NULL; 
		}
	}

private:
	T* m_iface;
};

#endif //__KMDS_AUTOREFER_H__

class CDataReference
{
public:
	CDataReference();
	virtual ~CDataReference();
	int AddRef(void);
	int Release(void);
private:
	int     m_nref;
	void*   m_refcs;
};


class MSGDATA_Export CTableData : public CDataReference
{
public:
	CTableData();
	~CTableData();
private:
	CTableData(CTableData &);
	CTableData& operator=(CTableData &);

public:
	// �������
	int Reset();

	// ���ñ�����
	// ������ ����������
	int AddRow(CMsgData **ppObjMsgData);
	int SaveRow();

	// ��ȡ������
	// ��ȡ����
	int GetCount(int *pnCount);
	int GetRow(int nRow, CMsgData **ppObjMsgData);

	int Get_TableDataScan(CTableDataScan **ppTableDataScan);
	// ��ȡ��ά����ֶ���
	int GetFieldCount(/* [out] */int *pnFieldCount);
	// �� 0 ��ʼȡ�ֶ�����
	int GetFieldName(/* [in] */int nFieldno,/* [in] */unsigned char *pFieldName,/* [in] */int nmaxlen);
	// �� 0 ��ʼȡ�ֶ�����
	int GetFieldType(/* [in] */int nFieldno,/* [out] */int *pnFieldType);

	int GetFieldNo(/* [in] */const char* pszFieldName,/* [out] */int *pnFieldno);
	// �����ֶ�
	int AddFieldNo(/* [in] */const char* pszFieldName,/* [out] */int *pnFieldno);

	// ɾ����
	int DeleteRow(int nRow);
	int CopyData_To_TableData(CTableData *pTableData);

	// ���� ���
	int Dump(enum EM_DUMP_FORMAT nformat,std::string& strDump);
private:
	typedef std::map < int, CMsgData * > map_rowdatas;
	map_rowdatas m_map_rowdatas;
	map_rowdatas::iterator m_it_map_rowdatas;

	CMsgData *m_pnewmsgdata;
	void Clear();

	CMsgDataName m_cl_fieldsinfo[DEF_TABLEDATA_COLMAX];
	int m_n_fieldcount;
	int m_nfieldlastrunno;
};

class MSGDATA_Export CMsgData : public CDataReference
{
public:
	CMsgData();
	~CMsgData();
private:
	CMsgData(CMsgData &);
	CMsgData& operator=(CMsgData &);
public:
	// ��������ģʽ
	int SetDataMode(/* [in] */enum EM_MSGDATA_MODE nmode);
	int GetDataMode(/* [out] */enum EM_MSGDATA_MODE *pnmode);
	int SetFieldInfo(/*[in] */CTableData *pICommTableData);

	// ��������
	int ClearAll();
	int DeleteItem(const char* pszKey);

	// ��������
	int PutData_Int8(const char* pszKey, int8 cValue);
	int PutData_Int16(const char* pszKey, int16 shValue);
	int PutData_Int32(const char* pszKey, int32 iValue);
	int PutData_Int64(const char* pszKey, int64 n64Value);

	int PutData_UInt8(const char* pszKey, uint8 cValue);
	int PutData_UInt16(const char* pszKey, uint16 shValue);
	int PutData_UInt32(const char* pszKey, uint32 iValue);
	int PutData_UInt64(const char* pszKey, uint64 n64Value);

	int PutData_Float(const char* pszKey, float fValue);
	int PutData_Double(const char* pszKey, double dValue);
	int PutData_Buf(const char* pszKey, unsigned char *pbuf, int nlen);
	int PutData(const char* pszKey, char* pszValue);

	// ��ȡ����
	int GetData_Int8(const char* pszKey, int8 *pcValue);
	int GetData_Int16(const char* pszKey, int16 *pshValue);
	int GetData_Int32(const char* pszKey, int32 *piValue);
	int GetData_Int64(const char* pszKey, int64 *pn64Value);

	int GetData_UInt8(const char* pszKey, uint8 *pcValue);
	int GetData_UInt16(const char* pszKey, uint16 *pshValue);
	int GetData_UInt32(const char* pszKey, uint32 *piValue);
	int GetData_UInt64(const char* pszKey, uint64 *pn64Value);

	int GetData_Float(const char* pszKey, float *pfValue);
	int GetData_Double(const char* pszKey, double *pdValue);
	int GetData_Buf(const char* pszKey, unsigned char **pbuf, int *pnlen);
	int GetData_String(/* [in] */const char* pszKey,/* [in] */unsigned char *pValue,/* [in] */int nmaxlen);
	int GetData(const char* pszKey, unsigned char *pstrValue,int ndatalen);

	// �����Ƿ����
	int HaveData(const char* pszKey);
	// ��ȡ��������
	int GetDataType(const char* pszKey, int *pnValue);

	// ѭ�����ݷ���
	int GoFirst();
	int GetCurrentType(int *pnType);
	int GetCurrentData(char *pstrKey, int nkeylen,unsigned char *pValue,int ndatalen);
	int GetCurrentDataWithType(unsigned char *pstrKey, int nkeylen,unsigned char *pValue, int ndatalen,int *pnType);

	// ��ȡ��ͨ�����ֶ��� Private Data
	int PD_GetCount(/* [out] */int *pnFieldCount);
	// 0 ��ʼ
	int PD_GetName_Str(/* [in] */int nFiledNo,/* [in] */unsigned char *pbFieldName,/* [in] */int nmaxlen);
	int PD_GetType(/* [in] */int nFiledNo,/* [out] */int *pnType);
	int PD_GetData_Str(/* [in] */int nFiledNo,/* [in] */unsigned char *pbFieldValue,/* [in] */int nmaxlen,/* [out] */int *pndatareallen);

	// �ݹ���Ϣʵ��洢
	int PutData_MsgData(const char* pszKey, CMsgData *pobjMsgData);
	// ����˫ָ�뺯����Ҫ��������ʽ����Release
	int GetData_MsgData(const char* pszKey, CMsgData **ppObjMsgData);

	int GoFirst_MsgData();
	int MoveNext_MsgData(unsigned char* pbKey, int nkeylen, CMsgData **ppObjMsgData);

	int MsgData_GetCount(/* [out] */int *pnCount);
	int MsgData_GetName_Str(/* [in] */int nNo,/* [in] */unsigned char *pbFieldName,/* [in] */int nmaxlen);
	int MsgData_GetMsgData(/* [in] */int nNo,/* [out] */CMsgData **ppObjMsgData);


	// ��ά���ݴ洢
	int PutData_TableData(const char* pszKey, CTableData *pobjTableData);
	int GetData_TableData(const char* pszKey, CTableData **ppobjTableData);

	int GoFirst_TableData();
	int MoveNext_TableData(unsigned char* pbKey, int nkeylen,CTableData **ppobjTableData);

	int TableData_GetCount(/* [out] */int *pnCount);
	int TableData_GetName_Str(/* [in] */int nNo,/* [in] */unsigned char *pbFieldName,/* [in] */int nmaxlen);
	int TableData_GetTableData(/* [in] */int nNo,/* [out] */CTableData **ppobjTableData);


	// ���� ���
	int Dump(enum EM_DUMP_FORMAT nformat,std::string& strDump);

	// ��������MsgData
	int CopyData_To_MsgData(CMsgData *pobjMsgData);
private:

	// typedef stdext::hash_map < CMsgDataName, CPrivateData * ,KeyComp_MsgDataName> map_kvdatas;
	//typedef std::map < std::string, CPrivateData *> map_kvdatas;
	typedef std::map < CMsgDataName, CPrivateData * ,KeyComp_MsgDataName> map_kvdatas;
	map_kvdatas m_map_kvdatas;
	map_kvdatas::iterator m_it_map_kvdatas;

	CPrivateData * Find(const char* pszKey);

	typedef std::map < std::string, CMsgData * > map_msgdatas;
	map_msgdatas m_map_msgdatas;
	map_msgdatas::iterator m_it_map_msgdata;

	int DumpCallProgram(std::string& strDump);
	CMsgData * FindMsgData(const char* pszKey);
	void ClearMsgDatas();

	typedef std::map < std::string, CTableData * > map_tabledatas;
	map_tabledatas m_map_tabledatas;
	map_tabledatas::iterator m_it_map_tabledata;

	CTableData * FindTableData(const char* pszKey);
	void ClearTablesDatas();

	void Clear();
	CPrivateData * Reset(const char* pszKey);
	int m_protocol_nver;
	int m_nver;

	CPrivateData *GetPD_ByFieldNo(int nFieldNo,char *lpszname,int nmaxlen);

	EM_MSGDATA_MODE m_nmode;

	CTableData * m_pTableData_FieldInfo;
	typedef std::map < int, CPrivateData *> map_fielddatas;
	map_fielddatas m_map_fielddatas;
};


class CDataSerial : public CDataReference
{
	enum EM_COMMDATA_TYPE
	{
		EM_COMMDATA_TYPE_PD = 1,
		EM_COMMDATA_TYPE_MSGDATA,
		EM_COMMDATA_TYPE_TABLEDATA
	};

	enum EM_COMMDATA_VER
	{
		EM_COMMDATA_VER_1 = 1
	};

	//#pragma pack(push,1)
	struct ST_HEAD
	{
		char szbz[2];
		int ntype;
		int nver;
		int ndate;
		int ntime;
		int nencryptmethod;
		int ncompressmethod;
		int nbase64code;
		int nlength;
	};
public:
	CDataSerial();
	~CDataSerial();
public:
	// �����ַ������Ϊ64BASE ����
	int  SetBase64Code(bool bEnable);
	// �����ַ������ܷ���
	int  SetEncrypt(bool bEnable,int nmethod);
	// �����ַ���ѹ������
	int SetCompress(bool bEnable,int nmethod);

	// �� MsgData ���� �ַ���
	int MsgData_To_BufData(CMsgData *pMsgData,unsigned char **ppbbuf,int *pnbufle);

	// �� TableData ���� �ַ���
	int TableData_To_BufData(CTableData *pTableData,unsigned char **ppbbuf,int *pnbuflen);

	// �ͷ����������
	int FreeBufData(unsigned char **ppbbuf);

	// �� �ַ��� ���� MsgData
	// ��Ҫ�ͷ� MsgData Release
	int BufData_To_MsgData(unsigned char *pbbuf,int nbuflen,CMsgData **ppMsgData);

	// �� �ַ��� ���� CTableData
	// ��Ҫ�ͷ� CTableData Release
	int BufData_To_TableData(unsigned char *pbbuf,int nbuflen,CTableData **ppTableData);

private:
	// CMsgData To BufData
	int __MsgData_To_GrowBuf(CMsgData *pMsgData,CLGrowBuf *plgrowbuf);
	int __PDData_To_GrowBuf(CMsgData *pMsgData,CLGrowBuf *plgrowbuf);
	int __SubMsgData_To_GrowBuf(CMsgData *pMsgData,CLGrowBuf *plgrowbuf);
	int __SubTableData_To_GrowBuf(CMsgData *pMsgData,CLGrowBuf *plgrowbuf);
	int __TableData_To_GrowBuf(CTableData *pTableData,CLGrowBuf *plgrowbuf);

	// BufData To CMsgData
	int __BufData_To_MsgData(CLBufData *plbufdata,CMsgData *pMsgData);
	int __BufData_To_PDData(CLBufData *plbufdata,CMsgData *pMsgData);
	int __BufData_To_SubMsgData(CLBufData *plbufdata,CMsgData *pMsgData);
	int __BufData_To_SubTableData(CLBufData *plbufdata,CMsgData *pMsgData);
	int __BufData_To_TableData(CLBufData *plbufdata,CTableData *pTableData);

	int MakeSerialHead(ST_HEAD &st_head,int ntype);

	int FormatNowDateTime(char* pszFormat,unsigned char *pbDateTime,int nlen);

};


class  CTableDataScan : public CDataReference
{
public:
	CTableDataScan();
    ~CTableDataScan();

public:

	// ���ö�ά��
	int SetICommTableData(CTableData *pTableDataScan);

	// ��ȡ��ά���¼����
	int GetCount(int *pnCount);

	// ��λ���� nRow �� �� 0 ��ʼ ���� S_OK ��ʾ��λ�ɹ�������ʧ��
	int GoRow(int nRow);

	// ��λ���� 0 �� ���� S_OK ��ʾ��λ�ɹ�������ʧ��
	int GoFirst();

	// ��λ����һ�� ���� S_OK ��ʾ��λ�ɹ�������ʧ��
	int MoveNext();

	// ��λ���еĽṹ������
	int GoMsgData(char* pszKey);

	// ȡ��ǰnRow��ICommMsgData
	int GetCurrenRow_MsgData(CMsgData **ppMsgData);

	// ȡ��ǰ�ṹ���ݵ�ICommMsgData
	int GetCurrentStruct_MsgData(CMsgData **ppMsgData);

	// ȡ������
	int GetData_String(char* pszKey,unsigned char *pbValue,int nmaxlen);
	int GetData_Int32(char* pszKey, int *piValue);
	int GetData_Double(char* pszKey, double *pdValue);
	int GetData(char* pszKey, string& strValue);

	// ��ȡ��ά����ֶ���
	int GetFieldCount(int *pnFieldCount);
	// �� 0 ��ʼȡ�ֶ�����
	int GetFieldName(int nFieldno,unsigned char *pbFieldName,int nmaxlen);
	// �� 0 ��ʼȡ�ֶ�����
	int GetFieldType(int nFieldno,int *pdwFieldType);

	// ��λ�� Key = Value ��������
	int GoLocal(char* pszKey,char* pszValue);

private:
	void Release_CommMsgData();

	typedef std::deque <CMsgData*> list_release_msgdatas;
	list_release_msgdatas          m_list_release_msgdatas;

	CMsgData *m_prow_commmsgdata;
	CMsgData *m_prow_struct_commmsgdata;

	CTableData *m_p_commtabledata;
	int m_nrownow;

};








#endif // __MSGDATA_H__

/// ������Ҫ����������ʹ��CAutoRefer<CTableData> pobjTableData(new CTableData);
// ��CAutoRefer<CTableData> pobjTableData;
/***************************************
// ʹ��ʵ��
#include <comm/autorefer.h>
#include <prj/msgdata/msgdata.h>
int main()
{
	WriteLog(KDLOG_TIPS,"���Գ�������%s","����");

	CAutoRefer<CMsgData> pobjdata(new CMsgData);
	// Ȼ���pobjdata���в���
	...

	// �����˳���Ҫ�ͷ���־
	ReleaseLog();
}

***************************************/
