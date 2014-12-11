#include <iostream>
using namespace std;
class A 
{
public:
	void func(int x,int y){i=x;j=y;}
	void print()const{cout<<"两数相乘为："<<i*j<<endl;}
private:
	int i;
	int j;
};
int main()
{
	A a;
	a.func(1,2);
	a.print();
	A b;
	b.func(3,4);
	b.print();
	return 0;
}