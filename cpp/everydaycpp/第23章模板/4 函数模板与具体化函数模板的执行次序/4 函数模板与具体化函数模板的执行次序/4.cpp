#include <iostream>
using namespace std;
template<class T>
void show(T  a){cout<<"模板函数!"<<a<<endl;}
template<>void show<int>(int a){cout<<"具体化模板函数:"<<a<<endl;}
int main()
{
	show(5);
	return 0;
}