#include <iostream>
using namespace std;
class A 
{
public:
	A(){cout<<"执行构造函数创建一个对象\n";}
	A(A&){cout<<"执行复制构造函数创建该对象的副本\n";}
	~A(){cout<<"执行析构函数删除该对象\n";}
};
A* func(A *one)
{
	return one;
}
int main()
{
	A a;
	func(&a);
	return 0;
}