#include <iostream>
using namespace std;
class rectangle 
{
public:
	rectangle()
	{
		cout<<"����һ��������a!\n";
	}
	rectangle(int l,int w)
	{
		length=l;width=w;
		cout<<"������b�����Ϊ��"<<length*width<<endl;
	}
	rectangle(int l,int w,int h)
	{
		length=l;
		width=w;
		height=h;
		cout<<"������c�����Ϊ��"<<length*width*height<<endl;
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