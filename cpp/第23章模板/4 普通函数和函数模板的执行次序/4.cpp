#include <iostream>
using namespace std;
template<class T>
void show(T a){cout<<"模板函数!"<<a<<endl;}
void show(int a){cout<<"非模板函数!"<<a<<endl;}
int main()
{
	show(5);
	return 0;
}
