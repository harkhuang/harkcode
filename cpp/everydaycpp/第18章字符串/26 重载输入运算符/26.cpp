//Àý18.26  ÖØÔØÊäÈëÔËËã·û
#include <iostream>
using namespace std;
class A
{
public:
	A(int i){x=i;}
	friend istream &operator>>(istream &s,  A &c)
	{
		s>>c.x;
		return s;
	}
	friend ostream &operator<<(ostream &o, const A &c)
	{
		o<<c.x;
		return o;
	}
private:
	int x;
};
int main()
{
	A a(3),b(4);
	cin>>a>>b;
	cout<<a<<b;
	return 0;
}

