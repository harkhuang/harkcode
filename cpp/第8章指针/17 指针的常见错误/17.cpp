#include <iostream>
using namespace std;
int main()
{
	int *p=new int;
	*p=3;
	cout<<"将3赋给p的地址后，指针p读取的值：\t"<<*p<<endl;
	delete p;
	p=0;
	//cout<<"删除空间后，指针p读取的值：\t\t"<<*p<<endl;
	long *p1=new long;
	cout<<"创建新空间后，指针p中保存的地址：\t"<<p<<endl;
	*p1=999999;
	cout<<"指向新空间的指针p1保存的地址：\t\t"<<p1<<endl;
	p=new int;
	*p=23;
	cout<<"将23赋给p的地址后，指针p读取的值：\t"<<*p<<endl;
	cout<<"将23赋给p的地址后，指针p1读取的值：\t"<<*p1<<endl;
	delete p1;
	return 0;
}