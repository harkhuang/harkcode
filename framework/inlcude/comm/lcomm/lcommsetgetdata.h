#ifndef _LCOMM_SETDATA_INCLUDE_
#define _LCOMM_SETDATA_INCLUDE_

#include<comm/lcomm/macro_ldef.h>
#include<comm/platform/linuxcplusplus.h>

#define LCOMM_SETDATA_BYNAME(T,pcl,key,value) ((CLCommSetData<T, const char * > *)pcl)->SetData(key,value); 
#define LCOMM_SETDATA_BYNO(T,pcl,key,value) ((CLCommSetData<T, int > *)pcl)->SetData(key,value); 

/*
LCOMM_SETDATA_BYNAME(CCsvWrite,&clcsvwrite,"a",fdata);
LCOMM_SETDATA_BYNO(CCsvWrite,&clcsvwrite,2,fdata2);
LCOMM_SETDATA_BYNAME(CCsvWrite,&clcsvwrite,"b","2.3");
*/

template<typename TClass, typename TKeyClass>
class CLCommSetData_Func
{
	public:
		static int SetData(TClass *pclass,TKeyClass pfieldname, char *lpdata)
		{
			int nret = -101;
			if (pclass==NULL)
			{
				return nret;
			}
			nret = -104;
			TClass *pcl = pclass;
			//pcl = dynamic_cast<TClass>(pclass);
			if (pcl == NULL)
			{
				return nret;
			}
			nret = pcl->SetData(pfieldname,(const char *)lpdata);
			return nret;			
		}
		
};

// child must have function
// int SetData(TKeyClass pfieldname,char *lpdata);
// ex: public CLCommSetData<CCsvWrite, const char * >
//     int SetData(const char * pfieldname,char *lpdata);
//     public CLCommSetData<CCsvWrite, int >
//     int SetData(int pfieldname,char *lpdata);
template<typename TClass, typename TKeyClass, typename TSetDataFunc = CLCommSetData_Func<TClass,TKeyClass> >
class CLCommSetData
{
	public:
		//CLCommSetData() { };
		//virtual ~CLCommSetData() { };
	
		// ToFunction Child Class SetData
		int SetData(TKeyClass pfieldname,char *lpdata)
		{
			TClass *pclass = static_cast<TClass *>(this);
			return TSetDataFunc::SetData(pclass,pfieldname, lpdata);
		}
		
		int SetData(TKeyClass pfieldname,const char *lpdata)
		{
			return CLCommSetData<TClass,TKeyClass,TSetDataFunc>::SetData(pfieldname,(char *)lpdata);
		}
		
		int SetDataA(TKeyClass pfieldname,char *lpdata)
		{
			return CLCommSetData<TClass,TKeyClass,TSetDataFunc>::SetData(pfieldname,(char *)lpdata);
		}
		
		int SetData(TKeyClass pfieldname,int8 cdata)
		{
			int nret = -1;
			char szvalue[2];
			szvalue[0] = cdata;
			szvalue[1] = 0;
			nret = CLCommSetData<TClass,TKeyClass,TSetDataFunc>::SetData(pfieldname,(char *)szvalue);
			return nret;
		}
		
		int SetData(TKeyClass pfieldname,uint8 cdata)
		{
			int nret = -1;
			uchar szvalue[2];
			szvalue[0] = cdata;
			szvalue[1] = 0;
			nret = CLCommSetData<TClass,TKeyClass,TSetDataFunc>::SetData(pfieldname,(char *)szvalue);
			return nret;
		}
		
		int SetData(TKeyClass pfieldname,int16 ndata)
		{
			return CLCommSetData<TClass,TKeyClass,TSetDataFunc>::SetData(pfieldname,(uint64)ndata);
		}	
	
		int SetData(TKeyClass pfieldname,uint16 ndata)
		{
			return CLCommSetData<TClass,TKeyClass,TSetDataFunc>::SetData(pfieldname,(uint64)ndata);
		}	
	
		int SetData(TKeyClass pfieldname,int32& ndata)
		{
			return CLCommSetData<TClass,TKeyClass,TSetDataFunc>::SetData(pfieldname,(uint64)ndata);
		}	
	
		int SetData(TKeyClass pfieldname,uint32& ndata)
		{
			return CLCommSetData<TClass,TKeyClass,TSetDataFunc>::SetData(pfieldname,(uint64)ndata);
		}	

		int SetData(TKeyClass pfieldname,int64 ndata)
		{
			return CLCommSetData<TClass,TKeyClass,TSetDataFunc>::SetData(pfieldname,(uint64)ndata);
		}	
		
		int SetData(TKeyClass pfieldname,uint64 ndata)
		{
			int nret = -1;
			uchar szvalue[128];
			SAFESPRINTF(szvalue,DEF_UI64D,ndata);
			nret = CLCommSetData<TClass,TKeyClass,TSetDataFunc>::SetData(pfieldname,(char *)szvalue);
			return nret;
		}

		int SetData(TKeyClass pfieldname,float fdata)
		{
			int nret = -1;
			char szvalue[128];
			SAFESPRINTF(szvalue,"%.3f",fdata);
			nret = CLCommSetData<TClass,TKeyClass,TSetDataFunc>::SetData(pfieldname,(char *)szvalue);
			return nret;
		}
				
		int SetData(TKeyClass pfieldname,double ddata)
		{
			int nret = -1;
			char szvalue[128];
			SAFESPRINTF(szvalue,"%.3f",ddata);
			nret = CLCommSetData<TClass,TKeyClass,TSetDataFunc>::SetData(pfieldname,(char *)szvalue);
			return nret;			
		}
		
};

#define LCOMM_DEFMODTH_SETDATA(funcname,TKeyClass)  \
		int funcname(TKeyClass pfieldname,int8 cdata) \
		{ \
			int nret = -1; \
			char szvalue[2]; \
			szvalue[0] = cdata; \
			szvalue[1] = 0; \
			nret = funcname(pfieldname,(char *)szvalue); \
			return nret; \
		} \
		int funcname(TKeyClass pfieldname,uint8 cdata) \
		{ \
			int nret = -1; \
			uchar szvalue[2]; \
			szvalue[0] = cdata;\
			szvalue[1] = 0;\
			nret = funcname(pfieldname,(char *)szvalue);\
			return nret;\
		}\
		\
		int funcname(TKeyClass pfieldname,int16 ndata)\
		{\
			return funcname(pfieldname,(uint64)ndata);\
		}	\
	  \
		int funcname(TKeyClass pfieldname,uint16 ndata)\
		{\
			return funcname(pfieldname,(uint64)ndata);\
		}	\
	  \
		int funcname(TKeyClass pfieldname,int32 ndata)\
		{\
			return funcname(pfieldname,(uint64)ndata);\
		}	\
	  \
		int funcname(TKeyClass pfieldname,uint32 ndata)\
		{\
			return funcname(pfieldname,(uint64)ndata);\
		}	\
    \
		int funcname(TKeyClass pfieldname,int64 ndata)\
		{\
			return funcname(pfieldname,(uint64)ndata);\
		}	\
		\
		int funcname(TKeyClass pfieldname,uint64 ndata)\
		{\
			int nret = -1;\
			uchar szvalue[128];\
			_snprintf((char *)szvalue,sizeof(szvalue) -1,DEF_UI64D,ndata);\
		  nret = funcname(pfieldname,(char *)szvalue);\
			return nret;\
		}\
    \
		int funcname(TKeyClass pfieldname,float fdata)\
		{\
			int nret = -1;\
			char szvalue[128];\
			SAFESPRINTF(szvalue,"%.3f",fdata);\
			nret = funcname(pfieldname,(char *)szvalue);\
			return nret;\
		}\
		\
		int funcname(TKeyClass pfieldname,double ddata)\
		{\
			int nret = -1;\
			char szvalue[128];\
			SAFESPRINTF(szvalue,"%.3f",ddata);\
			nret = funcname(pfieldname,(char *)szvalue);\
			return nret;			\
		}

#define LCOMM_DEFMODTH_GETDATA(funcname,TKeyClass)  \
		int funcname(TKeyClass pfieldname,int8 &cdata) \
		{ \
			int nret = -1; \
			char szvalue[32]; \
			szvalue[0] = 0; \
			nret = funcname(pfieldname,(char *)szvalue,sizeof(szvalue)); \
			szvalue[sizeof(szvalue)] = 0; \
			if (nret == 0) { cdata = szvalue[0]; }\
			return nret; \
		} \
		int funcname(TKeyClass pfieldname,uint8 &cdata) \
		{ \
			int nret = -1; \
			uchar szvalue[32]; \
			szvalue[0] = 0; \
			nret = funcname(pfieldname,(char *)szvalue,sizeof(szvalue)); \
			szvalue[sizeof(szvalue)] = 0; \
			if (nret == 0) { cdata = szvalue[0]; }\
			return nret; \
		}\
		\
		int funcname(TKeyClass pfieldname,int16 &ndata)\
		{\
			int nret = -1; \
			char szvalue[32]; \
			szvalue[0] = 0; \
			nret = funcname(pfieldname,(char *)szvalue,sizeof(szvalue)); \
			szvalue[sizeof(szvalue)] = 0; \
			if (nret == 0) { ndata = atoi(szvalue); }\
			return nret; \
		}	\
	  \
		int funcname(TKeyClass pfieldname,uint16 &ndata)\
		{\
			int nret = -1; \
			char szvalue[32]; \
			szvalue[0] = 0; \
			nret = funcname(pfieldname,(char *)szvalue,sizeof(szvalue)); \
			szvalue[sizeof(szvalue)] = 0; \
			if (nret == 0) { ndata = atoi(szvalue); }\
			return nret; \
		}	\
	  \
		int funcname(TKeyClass pfieldname,int32 &ndata)\
		{\
			int nret = -1; \
			char szvalue[32]; \
			szvalue[0] = 0; \
			nret = funcname(pfieldname,(char *)szvalue,sizeof(szvalue)); \
			szvalue[sizeof(szvalue)] = 0; \
			if (nret == 0) { ndata = atoi(szvalue); }\
			return nret; \
		}	\
	  \
		int funcname(TKeyClass pfieldname,uint32 &ndata)\
		{\
			int nret = -1; \
			char szvalue[32]; \
			szvalue[0] = 0; \
			nret = funcname(pfieldname,(char *)szvalue,sizeof(szvalue)); \
			szvalue[sizeof(szvalue)] = 0; \
			if (nret == 0) { ndata = atoi(szvalue); }\
			return nret; \
		}	\
    \
		int funcname(TKeyClass pfieldname,int64 &ndata)\
		{\
			int nret = -1; \
			char szvalue[128]; \
			szvalue[0] = 0; \
			nret = funcname(pfieldname,(char *)szvalue,sizeof(szvalue)); \
			szvalue[sizeof(szvalue)] = 0; \
			if (nret == 0) { ndata = ATOI64(szvalue); }\
			return nret; \
		}	\
		\
		int funcname(TKeyClass pfieldname,uint64 &ndata)\
		{\
			int nret = -1; \
			char szvalue[128]; \
			szvalue[0] = 0; \
			nret = funcname(pfieldname,(char *)szvalue,sizeof(szvalue)); \
			szvalue[sizeof(szvalue)] = 0; \
			if (nret == 0) { ndata = ATOI64(szvalue); }\
			return nret; \
		}\
    \
		int funcname(TKeyClass pfieldname,float &fdata)\
		{\
			int nret = -1; \
			char szvalue[128]; \
			szvalue[0] = 0; \
			nret = funcname(pfieldname,(char *)szvalue,sizeof(szvalue)); \
			szvalue[sizeof(szvalue)] = 0; \
			if (nret == 0) { fdata = (float)atof(szvalue); }\
			return nret; \
		}\
		\
		int funcname(TKeyClass pfieldname,double &ddata)\
		{\
			int nret = -1; \
			char szvalue[128]; \
			szvalue[0] = 0; \
			nret = funcname(pfieldname,(char *)szvalue,sizeof(szvalue)); \
			szvalue[sizeof(szvalue)] = 0; \
			if (nret == 0) { ddata = atof(szvalue); }\
			return nret; \
		}

/*
		ex:
		int SetData(const char *lpszfieldname,const char *lpszvalue);
		int SetData(const char *lpszfieldname,char *lpszvalue);
		int SetData(int nno,const char *lpszvalue);
		int SetData(int nno,char *lpszvalue);
		
		LCOMM_DEFMODTH_SETDATA(SetData,const char *);
		LCOMM_DEFMODTH_SETDATA(SetData,int);

		int GetData(const char *lpszfieldname,const char *lpszvalue,int nmaxlen) { return 0; };
		int GetData(const char *lpszfieldname,char *lpszvalue,int nmaxlen) { return 0; };
		int GetData(int nno,const char *lpszvalue,int nmaxlen) { return 0; };
		int GetData(int nno,char *lpszvalue,int nmaxlen) { return 0; };
		
		LCOMM_DEFMODTH_GETDATA(GetData,const char *);
		LCOMM_DEFMODTH_GETDATA(GetData,int);

*/

#endif
