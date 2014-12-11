#include <iostream>
using namespace std;
class A 
{
public:
	void Set(int x,int y)
	{
		a=x;
		b=y;
	}
	void Show()
	{
		cout<<"a:"<<a<<"\t"<<"b:"<<b<<endl;
	}
private:
	int a;
	int b;
};
void(A::*p)(int,int);
int main()
{
	A a;
	p=&A::Set;
	int x=2,y=3;
	(a.*p)(x,y);
	a.Show();
	return 0;
}