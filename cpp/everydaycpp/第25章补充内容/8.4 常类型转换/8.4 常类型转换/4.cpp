#include <iostream>
using namespace std;
class A 
{
public:
	A(int i):x(i){}
	void show()const
	{
		const_cast<A*>(this)->x++;
		cout<<x<<endl;
	}
private:
	int x;
};

int main()
{
	const A a(1);
	a.show();
	a.show();
	a.show();
	return 0;
}
