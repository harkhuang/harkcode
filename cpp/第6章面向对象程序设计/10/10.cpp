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
	cout<<"������һ������\n";
	cin>>x;
	a.func(x);
	cout<<"\n";
	cout<<"���������Ϊ��"<<a.get()<<endl;
	return 0;
}