#include <iostream>
using namespace std;
class A
{
public:
	 void print(){cout<<"a"<<endl;}
};
class B:public A
{
public:
	void print(){cout<<"b"<<endl;}
};
class C:public A 
{
public:
	void print(){cout<<"c"<<endl;}
};

int main()
{
	A a;
	B b;
	C c;
	A*p=&a;
	A*p1=&b;
	A*p2=&c;
	p->print();
	p1->print();
	p2->print();
	return 0;
}