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
	A *p=new A(99);
	cout<<"堆中对象的地址:"<<p<<endl;
	return *p;
}
int main()
{
	A&r=func();
	cout<<"堆中对象的副本的地址:"<<&r<<endl;
	cout<<r.get()<<endl;
	A*p=&r;
	delete p;
	return 0;
}