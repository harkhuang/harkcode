#include <iostream>
using namespace std;
class A 
{
public:
	A();
	~A();
};
A::A(){cout<<"���캯��ִ����ϣ�\n";}
A::~A(){cout<<"��������ִ����ϣ�\n";}
int main()
{
	A a[2];
	return 0;
}