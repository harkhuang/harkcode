#ifndef __L_LINUXWIN32API_H__
#define __L_LINUXWIN32API_H__
#ifdef _LINUX_

#include <unistd.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/times.h>
#include <sys/time.h>
#include <dlfcn.h>

#ifdef __cplusplus
extern "C"
{
#endif

void strupr(char *src);
void getdate2(char *datestr,char *format);
char* strrev(char* szT);
char* itoa(int value, char*  str, int radix);
int GetComputerName(char *lpBuffer, unsigned long* lpnSize);
int GetModuleFileName(void *hModule, char* sFileName, int nSize);
char * getAppPath(char *lpdir);

// dll liberary
#define LOAD_WITH_ALTERED_SEARCH_PATH RTLD_LAZY
void *LoadLibraryEx(const char *lpszFileName, void *hFile, int nFlags);
void *GetProcAddress(void *hInstance,const char *lpszProcName);
int FreeLibrary(void *hInstance);

#ifdef __cplusplus
}
#endif


#endif
#endif
