#include <iostream>
using namespace std;
class rectangel
{
public:
	rectangel(int l,int w){length=l;width=w;}
	int area(){return length*width;}
		rectangel(){}
private:
	int length;
	int width;
};
int main()
{
	rectangel a(3,4);
	cout<<"������a�����Ϊ��"<<a.area()<<endl;
	return 0;
}