/*
#include <iostream>
using namespace std;
#define ASSERT(x)\
	if (!(x))\
	{\
	cout<<"错误！ASSERT("<<#x<<")宏函数执行失败\n";\
	cout<<"错误代码出现在第"<<__LINE__<<"行\n";\
	cout<<"出错的文件在："<<__FILE__<<"\n";\
	}
int main()
{
	int x=999;
	cout<<"第一次执行assert():\n";
	ASSERT(x==999);
	cout<<"第二次执行assert():\n";
	ASSERT(x!=999);
	cout<<"程序结束.\n";
	return 0;
}
*/
//打开调试（DEBUG）
#define DEBUG
#include <iostream>
using namespace std;
#ifndef DEBUG
#define ASSERT(x)
#else 
#define ASSERT(x)\
	if (!(x))\
	{\
	cout<<"错误！ASSERT("<<#x<<")宏函数执行失败\n";\
	cout<<"错误代码出现在第"<<__LINE__<<"行\n";\
	cout<<"出错的文件在："<<__FILE__<<"\n";\
	}
#endif
int main()
{
	int x=999;
	cout<<"第一次执行assert():\n";
	ASSERT(x==999);
	cout<<"第二次执行assert():\n";
	ASSERT(x!=999);
	cout<<"程序结束.\n";
	return 0;
}
