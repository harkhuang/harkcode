#include <iostream>
using namespace std;
class father
{
public:
	void set(int x,int y)
	{
		a=x;
		b=y;
	}
	void show()
	{
		cout<<a<<"\t"<<b<<endl;
	}
private:
	int a,b;
};
class son:public father
{
public:
	void set(int x,int y)
	{
		father::set(x,y);
	}
	void show()
	{
		father::show();
	}
};
class grandson:public son
{

};
int main()
{
	son a;
	a.set(1,2);
	a.show();
	return 0;
}