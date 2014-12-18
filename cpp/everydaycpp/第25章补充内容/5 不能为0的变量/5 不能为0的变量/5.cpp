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
	cout<<"错误！ASSERT("<<#x<<")宏函数执行失败\n";\
	cout<<"错误代码出现在第"<<__LINE__<<"行\n";\
	cout<<"出错的文件在："<<__FILE__<<"\n";\
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
	cout<<"圆的面积为："<<one.Result()<<endl;
	one.set(0);
	cout<<"圆的面积为："<<one.Result()<<endl;
	return 0;
}
