#include <iostream>
using namespace std;
class a
{
public:
	a(){cout<<"����a"<<endl;}
	~a(){cout<<"����a"<<endl;}
};
class b
{
public:
	b(){cout<<"����b"<<endl;}
	~b(){cout<<"����b"<<endl;}
};
class c
{
public:
	c(){cout<<"����c"<<endl;}
	~c(){cout<<"����c"<<endl;}
};
class d
{
public:
	d(){cout<<"����d"<<endl;}
	~d(){cout<<"����d"<<endl;}
};
class e:public d,public c,public b,public a
{

};
int main()
{
	e com;

	return 0;
}
