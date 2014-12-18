#include <iostream>
using namespace std;
class A 
{
public:
	A(){cout<<"构造函数执行完毕\n";}
	void set(int a,char b)
	{
		i=a;
		j=b;
	}
	void print(){cout<<i<<j<<endl;}
private:
	int i;
	char j;
};
int main()
{
	A *a;
	a=new A;
	a->set(3,'4');
	a->print();
	return 0;
}

