#include <iostream>
using namespace std;
class A 
{
public:
	A(){cout<<"创建A"<<endl;}
	virtual void func(){cout<<"类A"<<endl;}
	virtual ~A(){cout<<"析构A"<<endl;}
};
class B:public A 
{
public:
	B(){cout<<"创建B"<<endl;}
	 void func(){cout<<"类B"<<endl;}
	 ~B(){cout<<"析构B"<<endl;}
};
int main()
{
	A*p=new B;
	p->func();
	delete p;
	return 0;
}