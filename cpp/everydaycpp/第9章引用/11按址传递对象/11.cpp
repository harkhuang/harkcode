#include <iostream>
using namespace std;
class A 
{
public:
	A(){cout<<"ִ�й��캯������һ������\n";}
	A(A&){cout<<"ִ�и��ƹ��캯�������ö���ĸ���\n";}
	~A(){cout<<"ִ����������ɾ���ö���\n";}
};
A* func(A *one)
{
	return one;
}
int main()
{
	A a;
	func(&a);
	return 0;
}