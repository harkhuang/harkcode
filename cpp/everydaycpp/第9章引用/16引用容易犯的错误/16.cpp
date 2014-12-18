#include <iostream>
using namespace std;
class A 
{
public:
	A(int i){cout<<"执行构造函数创建一个对象\n";x=i;}
	A(A&a){x=a.x;cout<<"执行复制构造函数创建一个对象\n";}
	~A(){cout<<"执行析构函数!\n";}
	int get(){return x;}
private:
	int x;
};
A func()
{
	cout<<"跳转到func函数中!\n";
	A a(23);
	cout<<"对象a的地址:"<<&a<<endl;
	return a;
}
int main()
{
	A*r=&func();
	cout<<"对象a的副本的地址:"<<r<<endl;
	cout<<r->get()<<endl;
	return 0;
}