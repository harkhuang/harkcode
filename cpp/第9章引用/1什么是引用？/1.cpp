#include <iostream>
using namespace std;
int main()
{
	int num;
	int &mum=num;
	num=999;
	cout<<"mum:"<<mum<<endl;
	mum=0;
	cout<<"num:"<<num<<endl;
	return 0;
}