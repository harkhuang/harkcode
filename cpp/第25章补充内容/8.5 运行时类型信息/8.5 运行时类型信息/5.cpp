#include <iostream>
#include <typeinfo>
using namespace std;
class A{};
int main()
{
	A a;
	cout<<"a��"<<typeid(a).name()<<endl;
	int b=3;
	if (typeid(b)!=typeid(A))
	{
		cout<<"b����"<<typeid(A).name()<<endl;
	}
	if (typeid(b)==typeid(1.23))
	{
		cout<<"b�Ǹ�double���ͱ���"<<endl;
	}
	if (typeid(b)==typeid(int))
	{
		cout<<"b�Ǹ�int���ͱ���"<<endl;
	}
	return 0;
} 
