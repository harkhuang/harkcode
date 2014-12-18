#include <iostream>
using namespace std;
class A 
{
public:
	A();
	~A();
};
A::A(){cout<<"构造函数执行完毕！\n";}
A::~A(){cout<<"析构函数执行完毕！\n";}
int main()
{
	A a[2];
	return 0;
}