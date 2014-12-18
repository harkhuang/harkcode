/*
//Àı18.23.1  ´íÎó´úÂë1

#include <iostream>
using namespace std;
class A 
{
public:
	A(int x,int y){rx=x;ry=y;}
private:
	int rx;
	int ry;
};

int main()
{
	A a(3,4),b(5,6);
	cout<<a<<b;
	return 0;
}
*/


#include <iostream>
using namespace std;
class A 
{
public:
	A(int x,int y){rx=x;ry=y;}
public:
	int rx;
	int ry;
};

ostream & operator << (ostream & s,const A & c)
{
	s<<c.rx;
	s<<c.ry;
	return s;
}

int main()
{
	A a(3,4),b(5,6);
	cout<<a<<b;
	return 0;
}
