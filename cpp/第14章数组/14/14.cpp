#include <iostream>
using namespace std;
int func(int *x)
{
	x[0]=100;
	return x[0];
}
int main()
{
	int x[30];
	cout<<"修改后的成绩为："<<func(x)<<endl;
	return 0;
}