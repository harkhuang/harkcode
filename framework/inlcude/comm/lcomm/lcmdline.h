#ifndef _LCMDLINE_INCLUDE_H_
#define _LCMDLINE_INCLUDE_H_

#include <string>
#include "lmapstruct.h"

// Example: Program /Key1:Value1 /Key2:Value2 /Key3:Value3
class CLCommandLine
{
	public:
		CLCommandLine();
		virtual ~CLCommandLine();
		
		// Example: Program Key1=Value1,Key2=Value2,Key3=Value3...
		int ParserKVString(char *lpszcmdline);
		
		// Example: Program /Key1:Value1 /Key2:Value2 /Key3:Value3...
		int ParserCmdLine(int nargc, char **ppszargv);
		
		bool HaveParam(char *lpszkey);
		char *GetParamStr(char *lpszkey,char *lpszdefaultvalue = NULL);
		int GetParamInt(char *lpszkey,int ndefaultvalue=0);
		// 检查数据值是否能够 1 yes YES
		bool IsEnable(char *lpszkey);
		
	private:
		struct st_param
		{
			int nid;
			char szkey[64];
			char szvalue[1024];
		};
		typedef CLMapStruct < std::string, st_param > map_parms;
		map_parms m_map_parms;
		
		char m_szdefaultkey[24];
		char* GetDataValue(char *src,char *dest ,int nmaxlen,int num,char ch);
};


#endif // _LCMDLINE_INCLUDE_H_
