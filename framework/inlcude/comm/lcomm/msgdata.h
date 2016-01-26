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
* 文 件 名：msgdata.h
* 模块名称：基础类
* 功能说明：MsgData和TableData基础类
* 作    者：liulj
* 创建日期：2013-07-20
* 版 本 号：1.0
* 修改历史：
*
* 修改日期       姓名            内容
* ---------------------------------------------------------------------------
* 2013-07-20     liulj         初始版本
* 2013-09-16     malin         增加CDataSerial系列化
******************************************************************************/
#ifndef __MSGDATA_H__
#define __MSGDATA_H__
#include <map>
#include <string>
#include <deque>
#include <string.h>
using namespace std;

/************************************************************************/
/*  windows dll中要导出类CMsgData 和CTableData,则编译时需要加 KMDSAPI_EXPORT_DEF KMDSAPI_BUILD_DLL两个宏才能正确生成。
            使用dll时，则可执行程序编译时需要增加KMDSAPI_EXPORT_DEF宏定义。
	默认情况是使用静态库Lib来进行链接的，不导出CMsgData和CTableData类。
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

// key 最大长度
#define DEF_MSGDATAKEY_MAXLEN 64
// 二维表列数
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
	// 清空数据
	int Reset();

	// 设置表数据
	// 增加行 返回行数据
	int AddRow(CMsgData **ppObjMsgData);
	int SaveRow();

	// 获取表数据
	// 获取行数
	int GetCount(int *pnCount);
	int GetRow(int nRow, CMsgData **ppObjMsgData);

	int Get_TableDataScan(CTableDataScan **ppTableDataScan);
	// 获取二维表的字段数
	int GetFieldCount(/* [out] */int *pnFieldCount);
	// 从 0 开始取字段名称
	int GetFieldName(/* [in] */int nFieldno,/* [in] */unsigned char *pFieldName,/* [in] */int nmaxlen);
	// 从 0 开始取字段类型
	int GetFieldType(/* [in] */int nFieldno,/* [out] */int *pnFieldType);

	int GetFieldNo(/* [in] */const char* pszFieldName,/* [out] */int *pnFieldno);
	// 增加字段
	int AddFieldNo(/* [in] */const char* pszFieldName,/* [out] */int *pnFieldno);

	// 删除行
	int DeleteRow(int nRow);
	int CopyData_To_TableData(CTableData *pTableData);

	// 调试 输出
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
	// 设置数据模式
	int SetDataMode(/* [in] */enum EM_MSGDATA_MODE nmode);
	int GetDataMode(/* [out] */enum EM_MSGDATA_MODE *pnmode);
	int SetFieldInfo(/*[in] */CTableData *pICommTableData);

	// 清理数据
	int ClearAll();
	int DeleteItem(const char* pszKey);

	// 设置数据
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

	// 获取数据
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

	// 数据是否存在
	int HaveData(const char* pszKey);
	// 获取数据类型
	int GetDataType(const char* pszKey, int *pnValue);

	// 循环数据访问
	int GoFirst();
	int GetCurrentType(int *pnType);
	int GetCurrentData(char *pstrKey, int nkeylen,unsigned char *pValue,int ndatalen);
	int GetCurrentDataWithType(unsigned char *pstrKey, int nkeylen,unsigned char *pValue, int ndatalen,int *pnType);

	// 获取普通数据字段数 Private Data
	int PD_GetCount(/* [out] */int *pnFieldCount);
	// 0 开始
	int PD_GetName_Str(/* [in] */int nFiledNo,/* [in] */unsigned char *pbFieldName,/* [in] */int nmaxlen);
	int PD_GetType(/* [in] */int nFiledNo,/* [out] */int *pnType);
	int PD_GetData_Str(/* [in] */int nFiledNo,/* [in] */unsigned char *pbFieldValue,/* [in] */int nmaxlen,/* [out] */int *pndatareallen);

	// 递归消息实体存储
	int PutData_MsgData(const char* pszKey, CMsgData *pobjMsgData);
	// 这类双指针函数需要在外面显式调用Release
	int GetData_MsgData(const char* pszKey, CMsgData **ppObjMsgData);

	int GoFirst_MsgData();
	int MoveNext_MsgData(unsigned char* pbKey, int nkeylen, CMsgData **ppObjMsgData);

	int MsgData_GetCount(/* [out] */int *pnCount);
	int MsgData_GetName_Str(/* [in] */int nNo,/* [in] */unsigned char *pbFieldName,/* [in] */int nmaxlen);
	int MsgData_GetMsgData(/* [in] */int nNo,/* [out] */CMsgData **ppObjMsgData);


	// 二维数据存储
	int PutData_TableData(const char* pszKey, CTableData *pobjTableData);
	int GetData_TableData(const char* pszKey, CTableData **ppobjTableData);

	int GoFirst_TableData();
	int MoveNext_TableData(unsigned char* pbKey, int nkeylen,CTableData **ppobjTableData);

	int TableData_GetCount(/* [out] */int *pnCount);
	int TableData_GetName_Str(/* [in] */int nNo,/* [in] */unsigned char *pbFieldName,/* [in] */int nmaxlen);
	int TableData_GetTableData(/* [in] */int nNo,/* [out] */CTableData **ppobjTableData);


	// 调试 输出
	int Dump(enum EM_DUMP_FORMAT nformat,std::string& strDump);

	// 清理并设置MsgData
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
	// 设置字符流输出为64BASE 编码
	int  SetBase64Code(bool bEnable);
	// 设置字符流加密方法
	int  SetEncrypt(bool bEnable,int nmethod);
	// 设置字符流压缩方法
	int SetCompress(bool bEnable,int nmethod);

	// 将 MsgData 生成 字符流
	int MsgData_To_BufData(CMsgData *pMsgData,unsigned char **ppbbuf,int *pnbufle);

	// 将 TableData 生成 字符流
	int TableData_To_BufData(CTableData *pTableData,unsigned char **ppbbuf,int *pnbuflen);

	// 释放输出的数据
	int FreeBufData(unsigned char **ppbbuf);

	// 将 字符流 生成 MsgData
	// 需要释放 MsgData Release
	int BufData_To_MsgData(unsigned char *pbbuf,int nbuflen,CMsgData **ppMsgData);

	// 将 字符流 生成 CTableData
	// 需要释放 CTableData Release
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

	// 设置二维表
	int SetICommTableData(CTableData *pTableDataScan);

	// 获取二维表记录个数
	int GetCount(int *pnCount);

	// 定位到第 nRow 行 从 0 开始 返回 S_OK 表示定位成功，否则失败
	int GoRow(int nRow);

	// 定位到第 0 行 返回 S_OK 表示定位成功，否则失败
	int GoFirst();

	// 定位到下一行 返回 S_OK 表示定位成功，否则失败
	int MoveNext();

	// 定位到行的结构数据中
	int GoMsgData(char* pszKey);

	// 取当前nRow的ICommMsgData
	int GetCurrenRow_MsgData(CMsgData **ppMsgData);

	// 取当前结构数据的ICommMsgData
	int GetCurrentStruct_MsgData(CMsgData **ppMsgData);

	// 取列数据
	int GetData_String(char* pszKey,unsigned char *pbValue,int nmaxlen);
	int GetData_Int32(char* pszKey, int *piValue);
	int GetData_Double(char* pszKey, double *pdValue);
	int GetData(char* pszKey, string& strValue);

	// 获取二维表的字段数
	int GetFieldCount(int *pnFieldCount);
	// 从 0 开始取字段名称
	int GetFieldName(int nFieldno,unsigned char *pbFieldName,int nmaxlen);
	// 从 0 开始取字段类型
	int GetFieldType(int nFieldno,int *pdwFieldType);

	// 定位到 Key = Value 的数据行
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

/// 外面需要形如这样子使用CAutoRefer<CTableData> pobjTableData(new CTableData);
// 或CAutoRefer<CTableData> pobjTableData;
/***************************************
// 使用实例
#include <comm/autorefer.h>
#include <prj/msgdata/msgdata.h>
int main()
{
	WriteLog(KDLOG_TIPS,"测试程序启动%s","测试");

	CAutoRefer<CMsgData> pobjdata(new CMsgData);
	// 然后对pobjdata进行操作
	...

	// 程序退出需要释放日志
	ReleaseLog();
}

***************************************/
