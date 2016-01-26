#ifndef __BASEERROR__INCLUDE__H__
#define __BASEERROR__INCLUDE__H__
#include <stdarg.h>
#include <stdio.h>
#include <platform/linuxfuncdef.h>

#define L_ERR_BUFSIZE 4096
class CLBaseError
{
private:
	char m_szerrmsg[L_ERR_BUFSIZE];
	int m_nerrcode;
		
public:
	CLBaseError(void)
	{
		m_nerrcode = 0;
		m_szerrmsg[0] =0;
	}
	
	virtual ~CLBaseError(void) { }

	// 取错误码
	const int GetErrCode() const	{		return m_nerrcode;	}

	// 取错误消息
	const char* GetErrMsg()	const {		return (char *)m_szerrmsg;	}
	void SetErr(int nerrcode,const char *lpszerrfmt, ...)
	{
		va_list arg_ptr;
		m_nerrcode = nerrcode;
		m_szerrmsg[0] =0;
	
		if (!lpszerrfmt || lpszerrfmt[0]==0)
		{
			return;
		}
	
		va_start(arg_ptr, lpszerrfmt);
		_vsnprintf((char *)m_szerrmsg, sizeof(m_szerrmsg)-1, (char *)lpszerrfmt, arg_ptr);
		m_szerrmsg[sizeof(m_szerrmsg)-1] = 0x00;
		va_end(arg_ptr);
	}
};

#endif //__BASEERROR__INCLUDE__H__
