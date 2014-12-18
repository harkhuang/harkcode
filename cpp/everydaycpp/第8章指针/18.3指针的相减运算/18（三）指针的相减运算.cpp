#include <iostream.h>
//using namespace std;
int main()
{
	int *p=new int;
	cout<<"p:"<<p<<endl;
	int *p1=new int;
	cout<<"p1"<<p1<<endl;
	*p=p-p1;
	cout<<"两块内存的地址差：";
	cout<<*p<<endl;
	return 0;
}