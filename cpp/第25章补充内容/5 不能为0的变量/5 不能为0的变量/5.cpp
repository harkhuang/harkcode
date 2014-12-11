#define DEBUG
#include <iostream>
#include <string>
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
class Circle
{
public:
	double check()const
	{
		return radius;
	}
	void set(double x)
	{
		ASSERT(check());
		radius=x;
		ASSERT(check());
	}
	double Result()
	{
		return 3.14*radius*radius;
	}
private:
	double radius;
};
int main()
{
	Circle one;
	one.set(14);
	cout<<"Բ�����Ϊ��"<<one.Result()<<endl;
	one.set(0);
	cout<<"Բ�����Ϊ��"<<one.Result()<<endl;
	return 0;
}
