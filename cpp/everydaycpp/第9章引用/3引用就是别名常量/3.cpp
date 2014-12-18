#include <iostream>
using namespace std;
int main()
{
	int a;
	int &ra=a;
	a=999;
	cout<<"&a:"<<&a<<endl;
	cout<<"&ra:"<<&ra<<endl;
	int b=888;
	ra=b;
	cout<<"&a:"<<&a<<endl;
	cout<<"&ra:"<<&ra<<endl;
	cout<<"&b:"<<&b<<endl;
	cout<<"a:"<<a<<endl;
	cout<<"ra:"<<ra<<endl;
	cout<<"b:"<<b<<endl;
	ra=1;
	cout<<"a:"<<a<<endl;
	cout<<"ra:"<<ra<<endl;
	cout<<"b:"<<b<<endl;
	return 0;
}