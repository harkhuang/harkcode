#include <iostream>
using namespace std;
void swap(int ,int );
int x=3,y=4;
int main()
{
	
	int x=3000,y=4000;
	cout<<"��main�����У�����swap����֮ǰ��x��ֵΪ��"<<x<<",y��ֵΪ��"<<y<<endl;
	swap(x,y);
	cout<<"��main�����У�����swap����֮��x��ֵΪ��"<<x<<",y��ֵΪ��"<<y<<endl;
	return 0;
}
void swap(int x,int y)
{
	cout<<"��swap�����У�����swap����֮ǰ��x��ֵΪ��"<<x<<",y��ֵΪ��"<<y<<endl;
	int z;
	z=x;
	x=y;
	y=z;
	cout<<"��swap�����У�����swap����֮��x��ֵΪ��"<<x<<",y��ֵΪ��"<<y<<endl;
}