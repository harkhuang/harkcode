#include <iostream>
using namespace std;
int main()
{
	int a;
	int &ra=a;
	a=999;
	cout<<"&a:"<<&a<<endl;
	cout<<"&ra:"<<&ra<<endl;
	return 0;
}