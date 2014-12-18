#include<iostream>
using namespace std;
class area
{
public:
	area(){length=0;width=0;}
	~area(){cout<<"执行析构函数释放内存"<<endl;}
	int get(){return length*width;}
	void set(int l,int w){length=l;width=w;}
private:
	int length;
	int width;
};
void main()
{
	area *one=new area[10000];
	int i;
	for (i=0;i<10000;i++)
	{
		one[i].set(4,5*i);
	}
	cout<<one->get()<<endl;
	cout<<(one+1)->get()<<endl;
	
	
	//delete []one;
}