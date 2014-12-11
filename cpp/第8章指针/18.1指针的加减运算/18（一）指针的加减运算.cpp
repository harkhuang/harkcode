#include <iostream>
using namespace std;
int main()
{
	int *p=new int;
	cout<<"指针p保存的空间地址为：\t\t"<<p<<endl;
	p++;
	cout<<"自加后，指针p保存的空间地址为："<<p<<endl;
	p--;
	cout<<"自减后，指针p保存的空间地址为："<<p<<endl;
	p=p-2;
	cout<<"减2后，指针p保存的空间地址为： "<<p<<endl;
	return 0;
}
