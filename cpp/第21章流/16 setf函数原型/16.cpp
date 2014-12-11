#include <iostream>
using namespace std;
int main()
{
	const float number=-185;
	cout.width(10);
	cout.setf(ios::left);
	cout<<number<<endl;
	cout.width(10);
	cout.setf(ios::right,ios::adjustfield);
	cout<<number<<endl;
	cout.width(10);
	cout.setf(ios::internal,ios::adjustfield);
	cout<<number<<endl;
	return 0;
} 
