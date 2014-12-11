#include <iostream>
using namespace std;
class A 
{
public:
	A(){}
	A(A&one){n=one.n;m=one.m;}
	A(int i,int j){n=i;m=j;}
	void print()
	{
		cout<<n<<m;
	}
private:
	int n;
	int m;
};
int main()
{
	A a(2,4);
	a.print();
	cout<<"\n";
	A b(a);
	b.print();
	return 0;
}