#include <iostream>
using namespace std;
void swap(int ,int );
int x=3,y=4;
int main()
{
	
	int x=3000,y=4000;
	cout<<"在main函数中，调用swap函数之前，x的值为："<<x<<",y的值为："<<y<<endl;
	swap(x,y);
	cout<<"在main函数中，调用swap函数之后，x的值为："<<x<<",y的值为："<<y<<endl;
	return 0;
}
void swap(int x,int y)
{
	cout<<"在swap函数中，调用swap函数之前，x的值为："<<x<<",y的值为："<<y<<endl;
	int z;
	z=x;
	x=y;
	y=z;
	cout<<"在swap函数中，调用swap函数之后，x的值为："<<x<<",y的值为："<<y<<endl;
}