#include <iostream>
using namespace std;
class A
{
public:
	inline void func(int);
	int get(){return x;}
private:
	int x;
};

void A::func(int a){x=a;}
int main()
{
	A a;
	int x;
	cout<<"请输入一个数字\n";
	cin>>x;
	a.func(x);
	cout<<"\n";
	cout<<"输入的数字为："<<a.get()<<endl;
	return 0;
}