#include <iostream>
using namespace std;
class A 
{
public:
	A(int i){cout<<"ִ�й��캯������һ������\n";x=i;}
	A(A&a){x=a.x;cout<<"ִ�и��ƹ��캯������һ������\n";}
	~A(){cout<<"ִ����������!\n";}
	int get(){return x;}
	void set(int i){x=i;}
private:
	int x;
};
A& func(A&a)
{
	cout<<"��ת��func������!\n";
	a.set(66);
	return a;
}
int main()
{
	A *p=new A(99);
	func(*p);
	cout<<p->get()<<endl;
	delete p;
	return 0;
}