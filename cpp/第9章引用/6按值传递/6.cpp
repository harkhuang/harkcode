#include <iostream>
using namespace std;
void swap(int a,int b)
{
	int c;
	cout<<"swap�����У�����ǰ��a:"<<a<<"b:"<<b<<endl;
	c=a;
	a=b;
	b=c;
	cout<<"swap�����У�������a:"<<a<<"b:"<<b<<endl;
}
int main()
{
	int a=3,b=4;
	cout<<"�������У�����ǰ��a:"<<a<<"b:"<<b<<endl;
	swap(a,b);
    cout<<"�������У�������a:"<<a<<"b:"<<b<<endl;
	return 0;
}