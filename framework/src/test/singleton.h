  /********************************************************************
 # File Name:    singleton.h
 # Version:      1.0
 # Mail:         shiyanhk@gmail.com 
 # Created Time: 2016-01-25
 *********************************************************************/

#include <iostream>
using namespace std;



#if !defined(__SINGLETON_INCLUDE_H)
#define __SINGLETON_INCLUDE_H

#include <platform/criticalsection.h>

template <class Object>
class Singleton 
{
protected:
	Singleton();
	virtual ~Singleton();
public:
	static Object &         instance();
	static void release();
protected:
	static void             init();
private:
	static  Object      *   myInstance;
	static  unsigned int    myCount;
	static CriticalSection cs;
};

template <class Object>
Object  *   Singleton<Object>::myInstance = 0;

template <class Object>
unsigned int    Singleton<Object>::myCount = 0;

template <class Object>
CriticalSection   Singleton<Object>::cs;

template <class Object>
Singleton<Object>::Singleton()
{
}

template <class Object>
Singleton<Object>::~Singleton()
{
}

template <class Object>
Object &
	Singleton<Object>::instance()
{
	init();
	return ( *myInstance );
}

template <class Object>
void Singleton<Object>::release()
{
	if (myInstance !=0)
	{
		CriticalFunction lock(cs);
		if (myInstance !=0)
		{
			delete myInstance;
			myInstance = 0;
		}
	}
}

template <class Object>
void
	Singleton<Object>::init()
{
	if (myInstance == 0)
	{
		CriticalFunction lock(cs);
		if ( myInstance == 0 )
		{
			myInstance = new Object;
		}
	}
}

#endif // !defined(__SINGLETON_INCLUDE_H)
