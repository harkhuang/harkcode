#include <iostream>
using namespace std;
class A 
{
public:
	virtual int get(){return 0;}
};
class B:public A 
{
public:
	int get(){return 1;}
};
int main()
{
	B b;
	A*p=&b;
	cout<<p->get();
	cout<<p->A::get();
	return 0;
}