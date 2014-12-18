#include <iostream>
using namespace std;
class A	
{
public:
	void static show(){cout<<A::n;A a;a.get1();n++;}
	void get(){cout<<n;}
	void get1(){cout<<m;}
	A(){m=0;}
private:
	static int n;
	int m;
};
class B:public A 
{

};
int A::n=0;
int main()
{
	A::show();
	A a;
	a.get();
	B::show();
	return 0;
}