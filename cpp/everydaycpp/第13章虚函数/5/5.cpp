#include<iostream>
using namespace std;
class A 
{
public:
	int get(){return 1;}
};
class B:public A 
{
public:
	int get(){return 2;}
};
int  main()
{
	A a;
	int one;
	one=a.get();
	cout<<"a.get "<<one<<endl;
	B b;
	one=b.get();
	cout<<"b.get "<<one<<endl;
	return 0;
}
