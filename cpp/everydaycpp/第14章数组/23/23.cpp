#include <iostream>
using namespace std;
class area 
{
public:
	area(int l,int w){length=l;width=w;cout<<"调用构造函数设置长和宽的值,"<<"长："<<length<<"宽："<<width<<endl;}
	~area(){cout<<"调用析构函数释放内存,"<<"长："<<length<<"宽："<<width<<endl;}
	int get(){return length*width;}
	void set(int l,int w){length=l;width=w;}
private:
	int length;
	int width;
};
int main()
{
	area one[4]={area(10,10),area(13,34),area(20,30),area(40,40)};
	cout<<one[0].get()<<endl;
	one[0].set(30,40);
	cout<<one[0].get()<<endl;
	cout<<one[1].get()<<endl;
	cout<<one[2].get()<<endl;
	cout<<one[3].get()<<endl;
	return 0;
}