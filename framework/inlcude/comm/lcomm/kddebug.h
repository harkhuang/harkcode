#ifndef __KD_DEBUG_HPP_
#define __KD_DEBUG_HPP_

#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <string>
//#include <platform/linuxcplusplus.h>

#if defined(_DEBUG) && defined(WIN32)  
	#include <windows.h>
	#include <crtdbg.h>

	#include <iostream>
	#include <sstream>
	#include <iomanip>
	
#	define KD_DEBUG(x)		{ std::ostringstream outs; outs << x << std::endl; std::cout << outs.str() << std::endl; OutputDebugString((char *)outs.str().c_str()); }
#	define KD_DEBUGLINE(x)	std::cout << __FILE__ << "(" << __LINE__ <<"): " ;	x
#	define KD_DEBUGRUN(x)	x
# define KD_ASSERT(x)    _ASSERT(x); 
	inline void ShowProgDebugLog(const char *lpszmsg, ...)
	{
		char szbuf[200];
		va_list arg_ptr;
		
		va_start(arg_ptr, lpszmsg);
		_vsnprintf(szbuf, sizeof(szbuf) -1,lpszmsg, arg_ptr);
		va_end(arg_ptr);
		szbuf[sizeof(szbuf) -1] =0;
		OutputDebugString(szbuf);
		OutputDebugString("\n");
	}
#else
#	define KD_DEBUG(x)
#	define KD_DEBUGLINE(x)
#	define KD_DEBUGRUN(x)	
# define KD_ASSERT(x)
	inline void ShowProgDebugLog(const char *lpszmsg, ...)
	{
		
	}
#endif

inline void ShowProgReleaseLog(const char *lpszmsg, ...)
{
	char szbuf[200];
	va_list arg_ptr;
	
	va_start(arg_ptr, lpszmsg);
	_vsnprintf(szbuf, sizeof(szbuf) -1,lpszmsg, arg_ptr);
	va_end(arg_ptr);
	szbuf[sizeof(szbuf) -1] =0;
	#ifdef _WIN32_
		OutputDebugString(szbuf);
		OutputDebugString("\n");
	#endif
}

inline void KD_DumpMemory(void *address, int size,int nlinebyte,std::string &strout)
{
#define MAX_LINEBYTECT        128 
#define BYTEFORMATBUFFERLENGTH 4
#define HEXDUMPLINELENGTH     (MAX_LINEBYTECT *2 + MAX_LINEBYTECT/4 +1)
    unsigned char   byte;
    int byteindex;
    int bytesdone;
    int dumplen;
    char  formatbuf [BYTEFORMATBUFFERLENGTH];
    char  hexdump [HEXDUMPLINELENGTH] = {0};
    char szline[4096];
    int hexindex;
    unsigned char  unidump [MAX_LINEBYTECT +1] = {0};
    int niindex = 0;

		if (nlinebyte > MAX_LINEBYTECT)
		{
			nlinebyte = MAX_LINEBYTECT;
		}
		
    strout = "";

    // Each line of output is MAX_LINEBYTECT bytes.
    if ((size % nlinebyte) == 0) 
		{
        dumplen = size;
    }
    else 
    {
        dumplen = size + (nlinebyte - (size % nlinebyte));
    }

    // For each word of data, get both the Unicode equivalent and the hex
    // representation.
    bytesdone = 0;
    for (byteindex = 0; byteindex < dumplen; byteindex++) 
	  {
        hexindex = (byteindex % nlinebyte)*2 + (byteindex % nlinebyte) /4;
        niindex = byteindex %nlinebyte;
        if (byteindex < size) 
				{
            byte = ((unsigned char *)address)[byteindex];
            _snprintf((char *)formatbuf, BYTEFORMATBUFFERLENGTH,"%.2X ", byte);
            formatbuf[BYTEFORMATBUFFERLENGTH - 1] = '\0';
            strncpy(hexdump + hexindex, formatbuf, 3);
            
            if (byte==0x00 || byte <0x20 || byte >=0x7f)
            {
            	unidump[niindex] = '.';
            }
            else
            {
            	unidump[niindex] = byte;
            }
        }
        else 
				{
            // Add padding to fill out the last line to 16 bytes.
            strncpy(hexdump + hexindex,  "   ", 3);
            unidump[niindex] = 0x20;
        }
        bytesdone++;
        if ((bytesdone % nlinebyte) == 0) 
				{
        		szline[0] = 0;
        		unidump[nlinebyte] = 0;
        		//hexdump[3*16] = 0;
        		hexdump[2*nlinebyte +nlinebyte /4] = 0;
        		_snprintf(szline,sizeof(szline) -1,"%s    %s\r\n", hexdump, unidump);
        		szline[sizeof(szline) -1] = 0;
            // Print one line of data for every 16 bytes. Include the
            // ASCII dump and the hex dump side-by-side.
            strout += szline;
        }
    }
}

#endif	// __KD_DEBUG_HPP_
