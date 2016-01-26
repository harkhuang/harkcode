 /********************************************************************
 # File Name:    CActionInterface.h
 # Version:      1.0
 # Mail:         shiyanhk@gmail.com 
 # Created Time: 2016-01-25
 # Description:  临界抉择
 *********************************************************************/



#ifndef __ACTION_INTERFACE_INCLUDE_H__
#define __ACTION_INTERFACE_INCLUDE_H__

// 接口类
class CActionInterface
{
	public:
		CActionInterface() { }
		virtual ~CActionInterface() { }

	public:
		virtual int OnDoAction(char *lpszActionName) = 0;
};

#endif // __ACTION_INTERFACE_INCLUDE_H__
