#include <iostream>
using namespace std;
class human
{
public:
	int func(){return 1;}
};
class father: virtual public human
{
public:
	int func1(){return 2;}
};
class mother: virtual public human
{
public:
	int func2(){return 3;}
};
class son:public father,public mother
{
public:
	int func4(){return 4;}
};
int  main()
{
	son a;
	cout<<a.func()<<endl;
	cout<<a.func1()<<endl;
	cout<<a.func2()<<endl;
	cout<<a.func4()<<endl;
	return 0;
}
