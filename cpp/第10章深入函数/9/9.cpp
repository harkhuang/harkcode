#include <iostream>
using namespace std;
class A
{
public:
	A(){cout<<"构造函数执行！\n";}
	~A(){cout<<"析构函数执行！\n";}
};
int main()
{
	A*p=new A;
	delete p;
	return 0;
}