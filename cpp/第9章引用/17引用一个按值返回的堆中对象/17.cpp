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
	A *p=new A(99);
	cout<<"���ж���ĵ�ַ:"<<p<<endl;
	return *p;
}
int main()
{
	A&r=func();
	cout<<"���ж���ĸ����ĵ�ַ:"<<&r<<endl;
	cout<<r.get()<<endl;
	A*p=&r;
	delete p;
	return 0;
}