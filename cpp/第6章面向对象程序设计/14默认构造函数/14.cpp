#include <iostream>
using namespace std;
class rectangel
{
public:
	rectangel(int l,int w){length=l;width=w;}
	rectangel(){cout<<"���캯��������...\n";}
	int area(){return length*width;}
private:
	int length;
	int width;
};
int main()
{
	rectangel a(3,4);
	cout<<"������a�����Ϊ��"<<a.area()<<endl;
	rectangel b;
	cout<<"������b�����Ϊ��"<<b.area()<<endl;
	return 0;
}