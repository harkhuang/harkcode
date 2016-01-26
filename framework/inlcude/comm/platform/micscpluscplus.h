#ifndef __MISC_CPLUSCPLUS_INCLUDE__
#define  __MISC_CPLUSCPLUS_INCLUDE__

#define GETSETSTRINGMETHOD(name,size)  public:  \
                                         inline char* Get##name() { return m_sz##name; } \
                                         inline void Set##name(char *lpname) \
				                                 { \
                                           strncpy(m_sz##name,lpname,sizeof(m_sz##name) -1); \
                                           m_sz##name[sizeof(m_sz##name) -1] = 0; \
				                                 } \
				                               private: \
                                         char m_sz##name[size +1];

#define GETSETSTRIN_INIT(name) m_sz##name[0] = 0;


#define GETSETINTEGERMETHOD(name)  public:  \
                                     inline int Get##name() { return m_n##name; } \
                                     inline void Set##name(int ndata) \
				                             { \
                                       m_n##name = ndata; \
				                             } \
				                           private: \
                                     int m_n##name;

#define GETSETINTIN_INIT(name)    m_n##name = 0;


// 字符串安全拷贝 
// 注意：src 必须是字符数组
#ifndef DEF_L_SAFESTRCPY
#define DEF_L_SAFESTRCPY
#define SAFESTRCPY(src,dst)         { \
									                    strncpy(src,dst,sizeof(src) -1); \
	                                    src[sizeof(src) -1] =0; \
									                  }

#define SAFESTRCAT(src,dst)            { \
											int n_strcat_dstoffset = strlen(src); \
                      int n_strcat_dstleft = sizeof(src) -1 -n_strcat_dstoffset; \
                      if (n_strcat_dstleft <0) n_strcat_dstleft =0; \
									   strncpy(src + n_strcat_dstoffset,dst,n_strcat_dstleft); \
	                                   src[sizeof(src) -1] =0; \
									   }
#define SAFEFZERO(src) src[0] = 0;

#define SAFELZERO(src) src[sizeof(src) -1] =0;

#endif

#define DBGLOGOPEN

#if defined(DBGLOGOPEN) && (defined(_DEBUG) || defined(DBGOPEN))
	void ShowProgDebugLog(const char *lpszmsg, ...);
	void dumpmemory(void *address, int size);
#else
	void ShowProgDebugLog(const char *lpszmsg, ...);
	#define dumpmemory(address,size)
#endif

void ShowProgReleaseLog(const char *lpszmsg, ...);

char* ConvertCompileDateTime(char *lpszdate,int nmaxlen);

void int2str(unsigned char *szDest, int iSrc, int iDestSize);

int atoi_n(const char *szSrc, int len);
int atox_n(const char *szSrc, int len);

// 移至strs.h
// char * GetDataValue(char *src,char *dest ,int nmaxlen,int num,char ch);

#endif
