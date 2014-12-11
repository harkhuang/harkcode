#include <iostream>
using namespace std;
void a(int x[])
{
  x[2]=3;
}
int main()
{
	int x[20];
	a(x);
	cout<<x[2]<<endl;
	return 0;
}