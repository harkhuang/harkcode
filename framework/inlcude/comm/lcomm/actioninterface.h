#ifndef __ACTION_INTERFACE_INCLUDE_H__
#define __ACTION_INTERFACE_INCLUDE_H__

// ½Ó¿ÚÀà
class CActionInterface
{
	public:
		CActionInterface() { }
		virtual ~CActionInterface() { }

	public:
		virtual int OnDoAction(char *lpszActionName) = 0;
};

#endif // __ACTION_INTERFACE_INCLUDE_H__
