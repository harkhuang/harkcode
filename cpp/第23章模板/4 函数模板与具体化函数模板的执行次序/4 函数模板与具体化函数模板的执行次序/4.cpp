#include <iostream>
using namespace std;
template<class T>
void show(T  a){cout<<"ģ�庯��!"<<a<<endl;}
template<>void show<int>(int a){cout<<"���廯ģ�庯��:"<<a<<endl;}
int main()
{
	show(5);
	return 0;
}