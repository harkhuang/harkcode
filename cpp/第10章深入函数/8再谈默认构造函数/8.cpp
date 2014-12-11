#include <iostream>
using namespace std;
class A 
{
public:
	A(){}
	A(int i){x=i;}
private:
	int x;
};
int main()
{
  A a;
  A b(3);
}