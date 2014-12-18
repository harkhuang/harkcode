#include <iostream>
using namespace std;
class A 
{
public:
	A(){x=new int;*x=5;}
	~A(){delete x;x=0;}
	A(const A&a)
	{
		cout<<"复制构造函数执行...\n"<<endl;
		x=new int;
		*x=*(a.x);
	}
	int print()const{return *x;}
	void set(int i){*x=i;}
private:
	int *x;
};
int main()
{
	A*a=new A();
	cout<<"a:"<<a->print()<<endl;
	A b=(*a);
	cout<<"a:"<<a->print()<<endl;
	cout<<"b:"<<b.print()<<endl;
	b.set(32);
    cout<<"a:"<<a->print()<<endl;
	delete a;
	cout<<"b:"<<b.print()<<endl;
	return 0;
}