#include <iostream>
using namespace std;
class a
{
public:
	a(){cout<<"构造a"<<endl;}
	~a(){cout<<"析构a"<<endl;}
};
class b
{
public:
	b(){cout<<"构造b"<<endl;}
	~b(){cout<<"析构b"<<endl;}
};
class c
{
public:
	c(){cout<<"构造c"<<endl;}
	~c(){cout<<"析构c"<<endl;}
};
class d
{
public:
	d(){cout<<"构造d"<<endl;}
	~d(){cout<<"析构d"<<endl;}
};
class e:public d,public c,public b,public a
{

};
int main()
{
	e com;

	return 0;
}
