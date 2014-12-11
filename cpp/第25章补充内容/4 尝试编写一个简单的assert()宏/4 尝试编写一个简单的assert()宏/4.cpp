/*
#include <iostream>
using namespace std;
#define ASSERT(x)\
	if (!(x))\
	{\
	cout<<"����ASSERT("<<#x<<")�꺯��ִ��ʧ��\n";\
	cout<<"�����������ڵ�"<<__LINE__<<"��\n";\
	cout<<"������ļ��ڣ�"<<__FILE__<<"\n";\
	}
int main()
{
	int x=999;
	cout<<"��һ��ִ��assert():\n";
	ASSERT(x==999);
	cout<<"�ڶ���ִ��assert():\n";
	ASSERT(x!=999);
	cout<<"�������.\n";
	return 0;
}
*/
//�򿪵��ԣ�DEBUG��
#define DEBUG
#include <iostream>
using namespace std;
#ifndef DEBUG
#define ASSERT(x)
#else 
#define ASSERT(x)\
	if (!(x))\
	{\
	cout<<"����ASSERT("<<#x<<")�꺯��ִ��ʧ��\n";\
	cout<<"�����������ڵ�"<<__LINE__<<"��\n";\
	cout<<"������ļ��ڣ�"<<__FILE__<<"\n";\
	}
#endif
int main()
{
	int x=999;
	cout<<"��һ��ִ��assert():\n";
	ASSERT(x==999);
	cout<<"�ڶ���ִ��assert():\n";
	ASSERT(x!=999);
	cout<<"�������.\n";
	return 0;
}
