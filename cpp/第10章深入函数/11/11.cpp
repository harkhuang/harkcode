#include <iostream>
using namespace std;
class A 
{
public:
     A(int x){i=x;cout<<"���캯��ִ�У�"<<i<<endl;}
	~A(){cout<<"��������ִ�У�"<<i<<endl;}
	void get(){cout<<i<<endl;}
private:
	int i;
};
int main()
{
	A a(99);
	a.get();
	a=1000;
	return 0;
}