#ifndef __ACTION_INTERFACE_INCLUDE_H__
#define __ACTION_INTERFACE_INCLUDE_H__

// �ӿ���
class CActionInterface
{
	public:
		CActionInterface() { }
		virtual ~CActionInterface() { }

	public:
		virtual int OnDoAction(char *lpszActionName) = 0;
};

#endif // __ACTION_INTERFACE_INCLUDE_H__
