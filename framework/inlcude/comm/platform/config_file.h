/*
  20130915 support CMsgData, using #define USE_MSGDATA  in your code.
*/
#ifndef _CONFIG_FILE_H_
#define _CONFIG_FILE_H_

#ifdef _MSC_VER
  // warning C4189: local variable is initialized but not referenced
  // warning C4290: C++ exception specification ignored except to indicate a function is not __declspec(nothrow)
  // warning C4702: unreachable code
  // warning C4710: function 'blah' not inlined
  // warning C4786: identifier was truncated to '255' characters in the debug information
# pragma warning( push )
# pragma warning( disable : 4189 4290 4702 4710 4786 4503)

#endif


#include <map>
#include <string>
#include <algorithm>
#define  MAX_BUF_LEN  1024

using std::map;
using std::string;
using std::less;


typedef map<string, string, less<string> > ty_map_ky;
typedef ty_map_ky::iterator ty_map_ky_it;

typedef map<string, ty_map_ky *,  less<string> > strMap;
typedef strMap::iterator strMapIt;

struct SAnalyzeIni
{
    string strsect;
    void operator()( const string & strini);
#ifdef  USE_MSGDATA
    CMsgData *m_pMsgData;
    SAnalyzeIni(CMsgData & stMsgData);
#else
    strMap *pmap;
    SAnalyzeIni(strMap & strmap);
#endif
 };



class CIniFile
{
public:
	CIniFile( );
	~CIniFile( );
	void Free();
	bool Open(const char* pIniPath);
	bool Read(const char*pSect, const char*pKey, char *pszVal,int nsize, const char *pszDef = "", int iIndex = -1);
	bool Read(const char*pSect, const char*pKey, string& strVal, const char *pszDef = "", int iIndex = -1);
	bool Read(const char* pSect, const char* pKey, int& nVal, int nDef = 0, int iIndex = -1);	

	bool MoveFirstSec();
	bool GetSec(char *lpszsec,int nsize);

	bool MoveFirstKeyValue(char *lpszsec);
	bool GetKeyValue(char *lpszkey,int nkeysize,char *lpszvalue,int nvaluesize);
	//取一个Section的Item个数
	bool GetKeyCount(char*pSect, int*piResult);
	bool RemoveSect(char*pSect);

	bool AddValue(const char*pSect, const char*pKey, char*pszVal);
	bool AddValue(const char*pSect, const char*pKey, int& nVal);
	bool ModifyValue(const char*pSect, const char*pKey, char*pszVal);
	bool ModifyValue(const char* pSect, const char* pKey, int& nVal);
	bool ModifyValue(const char*pSect, const char*pKey, string& strVal);

	bool AddSect(const char*pSect);

	bool SaveAs(const char* pIniPath);

#ifdef _DEBUG
	void ShowAll();
#endif

protected:
    bool DoOpen(const char* pIniPath);
	std::string Trim(const char *pszSrc);

#ifdef  USE_MSGDATA
	int 				m_inisecit;		//SEC 游标
	int					m_inikeyvalueit; //KEY 游标
	CMsgData			*m_pMsgData_Key;	//KEY缓存游标
	
    CMsgData  		    m_stMsgData;
#else
    strMap m_inimap;

	strMapIt m_inisecit;
	
	ty_map_ky *m_map_ky;
	ty_map_ky_it m_inikeyvlaueit;
#endif	
};

/*
	其中do_open是用来真正实现初始化ini内容的函数。先用ifstream fin打开一个文件，然后用is_open判断文件是否正常打开。顺序读取文件的时候用eof()判断是否到文件尾。getline是一个字符处理函数：直接从fin中读取一行。然后用while循环过滤一行末尾的空格等字符。
	后保存到一个vector中，完成读入文本工作?
	用for_each函数来完成字符串的内容提取工作。声明一个结构，实现对操作符()的重载。代码如下： 
*/



#ifdef _MSC_VER
#pragma warning( pop )
#endif

#endif

