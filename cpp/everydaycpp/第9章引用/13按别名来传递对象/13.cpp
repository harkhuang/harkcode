#include <iostream>
using namespace std;
class A 
{
public:
	A(){cout<<"执行构造函数创建一个对象\n";}
	A(A&){cout<<"执行复制构造函数创建该对象的副本\n";}
	~A(){cout<<"执行析构函数删除该对象\n";}
	void set(int i){x=i;}
	int get()const{return x;}
private:
	int x;
};
const A& func(const A & one)
{
	//one.set(33);
	return one;
}
int main()
{
	A a;
	a.set(11);
	A const &b=func(a);
	cout<<b.get()<<endl;
	//b.set(33);
    cout<<b.get()<<endl;
	return 0;
}
