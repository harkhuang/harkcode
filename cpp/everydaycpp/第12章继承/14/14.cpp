#include <iostream>
using namespace std;
class a
{
public:
	void hello(){cout<<"基类a的hello函数"<<endl;}
};
class b
{
public:
	void hello(){cout<<"基类b的hello函数"<<endl;}
	void print(){cout<<"基类b的print函数"<<endl;}
};
class c:public a,public b
{
public:
	void print(){cout<<"子类c的print函数"<<endl;}
};
int main()
{
	c c;
	a a;
	b b;
	a.hello();
	b.print();
	c.a::hello();
	c.b::hello();
	c.b::print();
	c.print();
	return 0;
}




