#include <iostream>
using namespace std;
void func(int);
void func(long);
void func(float);
void func(double);
int main()
{
	int a=1;
	long b=100000;
	float c=1.5;
	double d=6.4579;
	cout<<"a:"<<a<<endl;
	cout<<"b:"<<b<<endl;
	cout<<"c:"<<c<<endl;
	cout<<"d:"<<d<<endl;
	func(b);
	func(c);
	func(d);
	return 0;
}
void func(int a)
{
	cout<<"a的平方为："<<a*a<<endl;
}
void func(long b)
{
	cout<<"b的平方为："<<b*b<<endl;
}
void func(float c)
{
	cout<<"c的平方为："<<c*c<<endl;
}
void func(double d)
{
	cout<<"d的平方为："<<d*d<<endl;
}