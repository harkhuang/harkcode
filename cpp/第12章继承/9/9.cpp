#include <iostream>
using namespace std;
class father
{
protected:
	int a,b;
};
class son:public father
{
public:
	void set(int i,int j)
	{
		a=i;
		b=j;
	}
	void show()
	{
		cout<<a<<"\t"<<b<<endl;
	}
};
class grandson:public son
{
public:
	void set(int i,int j)
	{
		a=i;
		b=j;
	}
	void show()
	{
		cout<<a<<"\t"<<b<<endl;
	}
};
int main()
{
	grandson g;
	g.set(2,3);
	g.show();
    son &a=g;
	a.set(99,99);
	a.show();
	return 0;
}