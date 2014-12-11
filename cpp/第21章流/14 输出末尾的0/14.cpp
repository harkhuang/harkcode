#include <iostream>
using namespace std;
int main()
{
	float price=4.0f;
	cout.precision(6);
    cout.setf(ios_base::showpoint);
	cout<<price<<endl;
	return 0;
}
