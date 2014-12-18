#include <iostream>
using namespace std;
void swap(int a,int b)
{
	int c;
	cout<<"swap函数中，交换前，a:"<<a<<"b:"<<b<<endl;
	c=a;
	a=b;
	b=c;
	cout<<"swap函数中，交换后，a:"<<a<<"b:"<<b<<endl;
}
int main()
{
	int a=3,b=4;
	cout<<"主程序中，交换前，a:"<<a<<"b:"<<b<<endl;
	swap(a,b);
    cout<<"主程序中，交换后，a:"<<a<<"b:"<<b<<endl;
	return 0;
}