#include <iostream>
using namespace std;
class father
{
public:
	int a,b;
};
class son:public father
{

};
int main()
{
	son a;
	a.a=1;
	a.b=2;
	cout<<a.a<<"\t"<<a.b<<endl;
	return 0;
}
基类的公有成员在派生类中仍然是公有的.