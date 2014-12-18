#include <iostream>
using namespace std;
class rectangel
{
public:
	rectangel(int l,int w){length=l;width=w;}
	rectangel(){cout<<"构造函数在运行...\n";}
	int area(){return length*width;}
private:
	int length;
	int width;
};
int main()
{
	rectangel a(3,4);
	cout<<"长方形a的面积为："<<a.area()<<endl;
	rectangel b;
	cout<<"长方形b的面积为："<<b.area()<<endl;
	return 0;
}