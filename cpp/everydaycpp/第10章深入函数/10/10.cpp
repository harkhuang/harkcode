#include <iostream>
using namespace std;
class A
{
public:
	A(){cout<<"���캯��ִ�У�\n";}
	~A(){}
};
int main()
{
	A*p=new A;
	delete p;
	return 0;
}