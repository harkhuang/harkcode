#include <iostream>
using namespace std;
int main()
{
	int *p=new int;
	cout<<"p:"<<p<<endl;
	int*p1=new int;
	cout<<"p1:"<<p1<<endl;
	p=p1;
	cout<<"¸³Öµºó...\n";
	cout<<"p:"<<p<<endl;
	return 0;
}