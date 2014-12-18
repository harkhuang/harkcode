#include <iostream>
using namespace std;
class A 
{
public:
	void set(int =30,int=5);
	void count(bool=false);
private:
	int w;
	int h;
};
void A::set(int width,int height)
{
	w=width;
	h=height;
}
void A::count(bool val)
{
	if (val==true)
	{
		cout<<"val的值为真时："<<w*h<<endl;
	}
	else
	{
		cout<<"val的值为假时："<<w*h/2<<endl;
	}
}
int main()
{
	A a;
	a.set();
	a.count();
	a.count(true);
	return 0;
}

1：重载函数使用方便，易于理解。
默认参数的函数如不加标注的话很容易被忽略，
而且容易被有参数的同名函数覆盖。
2：具有默认参数的函数重载的是参数的数值，
而重载函数重载的是参数的类型。