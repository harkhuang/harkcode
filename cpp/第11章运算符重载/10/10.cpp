#include <iostream>
using namespace std;
class A 
{
public:
	A(int x){i=x;cout<<"构造函数执行！"<<i<<endl;}
	~A(){cout<<"析构函数执行!"<<i<<endl;}
	void get(){cout<<i<<endl;}
	operator int(){return i;}
private:
	int i;
};
int main()
{
	A a(33);
	a.get();
	int x=999;
	x=a;
	a.get();
	cout<<endl;
	cout<<x<<endl;
	return 0;
}