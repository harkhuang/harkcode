#include <iostream>
using namespace std;
class A 
{
public:
	A(int i){cout<<"执行构造函数创建一个对象\n";x=i;}
	A(A&a){x=a.x;cout<<"执行复制构造函数创建一个对象\n";}
	~A(){cout<<"执行析构函数!\n";}
	int get(){return x;}
	void set(int i){x=i;}
private:
	int x;
};
A& func(A&a)
{
	cout<<"跳转到func函数中!\n";
	a.set(66);
	return a;
}
int main()
{
	A *p=new A(99);
	func(*p);
	cout<<p->get()<<endl;
	delete p;
	return 0;
}