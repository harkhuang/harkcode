#include <iostream>
using namespace std;
class A 
{
public:
	void Func(){cout<<A::x;}
private:
	static int x;
};
int A::x=1000;
//void Func1(){cout<<A::x;}
int main()
{
	A a;
	a.Func();
	return 0;
}