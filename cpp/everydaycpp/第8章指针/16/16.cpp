#include <iostream>
using namespace std;
class A
{
public:
	int get() const{return i;}
	void set(int x){i=x;cout<<"this变量保存的内存:\t"<<this<<endl;}

private:
	int i;
};
int main()
{
	A a;
	a.set(9);
	cout<<"对象a的内存地址:\t"<<&a<<endl;
	cout<<a.get()<<endl;
	A b;
	b.set(999);
	cout<<"对象b的内存地址:\t"<<&b<<endl;
	cout<<b.get()<<endl;
	return 0;
}