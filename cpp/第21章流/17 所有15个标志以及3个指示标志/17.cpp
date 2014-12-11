#include <iostream>
using namespace std;
int main()
{
	int x=185;
	cout.setf(ios::showpos);
	cout<<x<<endl;
	float y=193.34f;
	cout.setf(ios::scientific);
	cout<<y<<endl;
	cout.unsetf(ios::showpos);
	cout<<x<<endl;
	cout.unsetf(ios::scientific);
	cout<<y<<endl;
	return 0;
}
