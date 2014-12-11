#include <iostream>
#include <typeinfo>
using namespace std;
class A{};
int main()
{
	A a;
	cout<<"a是"<<typeid(a).name()<<endl;
	int b=3;
	if (typeid(b)!=typeid(A))
	{
		cout<<"b不是"<<typeid(A).name()<<endl;
	}
	if (typeid(b)==typeid(1.23))
	{
		cout<<"b是个double类型变量"<<endl;
	}
	if (typeid(b)==typeid(int))
	{
		cout<<"b是个int类型变量"<<endl;
	}
	return 0;
} 
