#if !defined(AFX_LIUUTIL_H__INCLUDED_)
#define AFX_LIUUTIL_H__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if defined WIN32 || defined WIN64
#define DIRPATHCHAR '\\'
#else
#define DIRPATHCHAR '/'
#endif
enum CALC_TIMEMODE
{
	MODE_HOUR,
	MODE_MIN,
	MODE_SEC,
	MODE_ALL
};

class Util  
{
public:

	static int GetRealPath(char *lpszabspath,char *lpszoutpath,int nmaxlen);
	static void getdate(char *datestr,char *format);

	static char *stringtoupper(char *s);
	static char * getAppPath(char *lpdir);
	static int    GetAppName(char *lpname, int nsize);

	static char * ltrim(char *str);
	static char * rtrim(char *str);
	static char * alltrim(char *str);
	static void Trim(char *strbuf);

	static int Convert(char *sBase,int Day,char *sDATE,int nFrm =0);
	static int DiffDate(char *lpszbegindate,char *lpszenddate);
	static bool NowBetweenDate(char *lpszbegindate,char *lpszenddate);

	static char *GetValue(char *src,char *dest ,int num,char ch);
	static char * GetDataValue(char *src, char *dest , int nmaxlen, int num, char ch);
	static void strcomma(int ndata,char *lpszdst,int noutlen);
	static void strcomma(char *lpszsrc,char *lpszdst,int noutlen);

	static char *LRemoveValue(char *src, char *dest, int num, char ch, char cp);

	static int ftok(const char *szPath, int nKeyproj);
	static int GetFtoK(char *lpszbuf,char *lpoutkey,int nmaxlen);
	static int GetModuleFtoK(char *lpoutkey,int nmaxlen);
	static int GetModuleBaseFilename(char *lpbasefilename,int nmaxlen);

	static int GetDouble_To_JE(double ddata,char *lpszbuf,int nmaxlen);
	static int General_RandNum(char *lpszbuf,int nmaxlen);

	static int GetFileMode (const char* pszFileName);
	static int MkDir(const char* pszFilePath);

	static int GetSpliteData(char* pszSrc,char *pszDst,int nDstlen,int nnum,char ch);
	static int GetchrCount(char* szStr,char ch);
	static void ProcessPercentSymbol(char * szDest, char * szSource,int nMaxSize);
	static int CheckTime(int nTime);
	// ʱ�����㺯�������ؼ���õ�ʱ�� ʱ������:0-235959
	// ndifftime֧�ְ���ʱ���֣������ 
	// ����磺nsrctime:103000��ndifftime:123��ǰ��1����23�룩ndifftime:-123(����һ����23��) nmode:MODE_ALL
	static int time_calc(int nsrctime,int ndifftime,int nmode = MODE_ALL);
	// ʱ�����㺯��
	static int time_diff(int nsrctime,int ndesttime,int nmode = MODE_ALL);
	/*
	{
	int nsrctime = 90000;
	cout << time_calc(nsrctime,3,MODE_HOUR) << endl; // 120000
	cout << time_calc(nsrctime,123,MODE_MIN) << endl; // 110300
	cout << time_calc(nsrctime,123,MODE_SEC) << endl; // 90203
	cout << time_calc(nsrctime,12359,MODE_ALL) << endl << endl;//102359

	cout << time_calc(nsrctime,-3,MODE_HOUR) << endl; // 60000
	cout << time_calc(nsrctime,-123,MODE_MIN) << endl; // 65700
	cout << time_calc(nsrctime,-123,MODE_SEC) << endl; // 85757
	cout << time_calc(nsrctime,-12359,MODE_ALL) << endl << endl;//73601

	int ndesttime1 = 85822,ndesttime2 = 103456;
	cout << time_diff(nsrctime,ndesttime1,MODE_ALL) << endl;//138
	cout << time_diff(nsrctime,ndesttime1,MODE_HOUR) << endl;//1
	cout << time_diff(nsrctime,ndesttime1,MODE_MIN) << endl;//2
	cout << time_diff(nsrctime,ndesttime1,MODE_SEC) << endl << endl;//98

	cout << time_diff(nsrctime,ndesttime2,MODE_ALL) << endl;//13456
	cout << time_diff(nsrctime,ndesttime2,MODE_HOUR) << endl;//1
	cout << time_diff(nsrctime,ndesttime2,MODE_MIN) << endl;//94
	cout << time_diff(nsrctime,ndesttime2,MODE_SEC) << endl;//5696
	system("pause");
	return 0;
	}
	*/

};

#endif // !defined(AFX_LIUUTIL_H__INCLUDED_)
