#include <iostream>
using namespace std;
class A
{
public:
	A(int a):i(a){}
	void show()
	{
		cout<<i;
	}
private:
	int i;
};
class B :public A
{
public:
	B(int b):A(0),j(b){}
	void show()
	{
		cout<<j;
	}
private:
	int j;

};
int main()
{
	B one=123;
	one.show();
	cout<<'/';
	B two=B(456);
	two.show();
	cout<<'/';
	A three=static_cast<B>(one);
	three.show();
	cout<<endl;
	A*p=&three;
	B *four=static_cast<B*>(p);
	four->show();
	char ch=static_cast<int>(111);
	cout<<"\n"<<ch;
	return 0;
} 
