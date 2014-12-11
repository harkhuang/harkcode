#include <iostream>
using namespace std;
int main()
{
	int *p=new int;
	*p=4;
	cout<<*p<<endl;
	delete p;
	cout<<*p<<endl;
	p=0;
	p=new int;
	*p=8;
	cout<<*p<<endl;
	delete p;

	return 0;
}

