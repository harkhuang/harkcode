#include <iostream>
using namespace std;
class A
{
public:
	int get() const{return i;}
	void set(int x){i=x;cout<<"this����������ڴ�:\t"<<this<<endl;}

private:
	int i;
};
int main()
{
	A a;
	a.set(9);
	cout<<"����a���ڴ��ַ:\t"<<&a<<endl;
	cout<<a.get()<<endl;
	A b;
	b.set(999);
	cout<<"����b���ڴ��ַ:\t"<<&b<<endl;
	cout<<b.get()<<endl;
	return 0;
}