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
	cout<<"a��ƽ��Ϊ��"<<a*a<<endl;
}
void func(long b)
{
	cout<<"b��ƽ��Ϊ��"<<b*b<<endl;
}
void func(float c)
{
	cout<<"c��ƽ��Ϊ��"<<c*c<<endl;
}
void func(double d)
{
	cout<<"d��ƽ��Ϊ��"<<d*d<<endl;
}