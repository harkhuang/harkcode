#include <iostream>
using namespace std;
class A 
{
public:
	A(int i){cout<<"ִ�й��캯������һ������\n";x=i;}
	A(A&a){x=a.x;cout<<"ִ�и��ƹ��캯������һ������\n";}
	~A(){cout<<"ִ����������!\n";}
	int get(){return x;}
private:
	int x;
};
A func()
{
	cout<<"��ת��func������!\n";
	A a(23);
	cout<<"����a�ĵ�ַ:"<<&a<<endl;
	return a;
}
int main()
{
	A*r=&func();
	cout<<"����a�ĸ����ĵ�ַ:"<<r<<endl;
	cout<<r->get()<<endl;
	return 0;
}