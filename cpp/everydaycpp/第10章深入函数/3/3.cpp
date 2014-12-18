#include <iostream>
using namespace std;
class rectangle 
{
public:
	rectangle()
	{
		cout<<"构造一个长方形a!\n";
	}
	rectangle(int l,int w)
	{
		length=l;width=w;
		cout<<"长方形b的面积为："<<length*width<<endl;
	}
	rectangle(int l,int w,int h)
	{
		length=l;
		width=w;
		height=h;
		cout<<"长方体c的体积为："<<length*width*height<<endl;
	}
private:
	int length;
	int width;
	int height;
};
int main()
{
	rectangle a;
	rectangle b(3,4);
	rectangle c(3,4,10);
	return 0;
}