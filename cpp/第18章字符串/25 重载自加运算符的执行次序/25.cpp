//例18.25  重载自加运算符的执行次序

#include <iostream>
using namespace std;
class A 
{
public:
	A(int x){rx=x;}
	int operator++(){cout<<"++i\n";rx++;return rx;}
	int operator++(int){cout<<"i++\n";int i=rx;rx++;return i;}
    friend ostream& operator<<(ostream &s,const A c)
	{
		s<<c.rx;
		return s;
	}
	
private:
	int rx;
};

int main()
{
	A a(4);
	cout<<++a<<a++<<endl;
	return 0;
}
