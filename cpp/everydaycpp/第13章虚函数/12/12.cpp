#include <iostream>
using namespace std;
class A 
{
public:
	A(){cout<<"����A"<<endl;}
	virtual void func(){cout<<"��A"<<endl;}
	virtual ~A(){cout<<"����A"<<endl;}
};
class B:public A 
{
public:
	B(){cout<<"����B"<<endl;}
	 void func(){cout<<"��B"<<endl;}
	 ~B(){cout<<"����B"<<endl;}
};
int main()
{
	A*p=new B;
	p->func();
	delete p;
	return 0;
}