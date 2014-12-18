#include <iostream>
using namespace std;
class A 
{
public:
	A(){x=new int;*x=5;}
	~A(){delete x;x=NULL;}
	A(const A&a)
	{
		cout<<"复制构造函数执行。。。\n"<<endl;
		x=a.x;
	}
	void print()const{cout<<*x<<endl;}
	void set(int i){*x=i;}
private:
	int *x;
};
int main()
{
	A*a=new A();
	cout<<"a:";
	a->print();
	cout<<endl;
	A b=(*a);
	b.print();
	a->set(32);
	cout<<"b:";
	b.print();
	cout<<endl;
	delete a;
	return 0;
}