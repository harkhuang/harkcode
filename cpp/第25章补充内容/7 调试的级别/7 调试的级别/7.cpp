#include <iostream>
#include <string>
using namespace std;
#define DEBUG 2
#if DEBUG<2
#define ASSERT(x)
#else
#define ASSERT(x)\
	if (!(x))\
{\
	cout<<"����ASSERT("<<#x<<")�꺯��ִ�м��\n";\
	cout<<"�����������ڵ�"<<__LINE__<<"��\n";\
	cout<<"������ļ��ڣ�"<<__FILE__<<"\n";\
}
#endif
#if DEBUG<3
	#define SHOW(x)
#else
	#define SHOW(x)\
	cout<<x<<endl;
#endif
#if DEBUG<4
	#define PRINT(x)
#else
	#define PRINT(x)\
	cout<<#x<<endl;
#endif
class Circle
{
public:
	double check()const
	{
		SHOW("����3�����");
		PRINT("����4�����");
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
