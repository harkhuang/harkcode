#include <iostream>
using namespace std;
void A();
void B();
void A()
{
	cout<<"����A\n";
	B();
}
void B()
{
	cout<<"����B\n";
	A();
}
int main()
{
	A();
	B();
	return 0;
}
