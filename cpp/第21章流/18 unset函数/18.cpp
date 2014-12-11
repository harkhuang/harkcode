//例21.18  unset()函数的使用
#include <iostream>
using namespace std;
int main()
{
	const float number=-185;
	cout.width(10);
	cout.setf(ios::left);
	cout<<number<<endl;
	cout.width(10);
	cout.unsetf(ios::adjustfield);
	cout.setf(ios::right);
	cout<<number<<endl;
	cout.width(10);
	cout.unsetf(ios::adjustfield);
	cout.setf(ios::internal);
	cout<<number<<endl;
	return 0;
}
