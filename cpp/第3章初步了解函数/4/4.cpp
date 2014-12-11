#include <iostream>
using namespace std;
void A();
void B();
void A()
{
	cout<<"º¯ÊýA\n";
	B();
}
void B()
{
	cout<<"º¯ÊýB\n";
	A();
}
int main()
{
	A();
	B();
	return 0;
}
