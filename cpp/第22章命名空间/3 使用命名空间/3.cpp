#include <iostream>
namespace func
{
	const int cx=20;
	const int cy=50;
	class num 
	{
	public:
		num();
		~num();
		void size(int a,int b);
		void swap(int rx,int ry);
		void compare(int ax,int ay);
		int returnX();
		int returnY();
	private:
		static int z;
		int x;
		int y;
	};
}
int func::num::z=0;
func::num::num():x(0),y(0){}
func::num::~num(){std::cout<<"��������ִ��...\n";}
void func::num::size(int a,int b)
{
	if (a<func::cx&&a>0)
	{
		num::x=a;
	}
	if (b<func::cy&&b>0)
	{
		num::y=b;
	}
}
void func::num::swap(int rx,int ry)
{
	using std::cout;
	int temp;
	cout<<"����ǰ��x��ֵΪ:"<<rx<<" y��ֵΪ��"
		<<ry<<"\n";
	temp=rx;
	rx=ry;
	ry=temp;
	cout<<"������x��ֵΪ:"<<rx<<" y��ֵΪ��"
		<<ry<<"\n";
}
void func::num::compare(int ax,int ay)
{
	using std::cout;
	if (ax<ay)
	{
		cout<<"x��yС\n";
	}
	else if (ax=ay)
	{
		cout<<"x����y\n";
	}
	else
	{
		cout<<"y��xС\n";
	}
} 
int func::num::returnX()
{
	using std::cout;
	return x;
}
int func::num::returnY()
{
	using std::cout;
	return y;
}
int main()
{
	func::num num;
	num.size(14,15);
	num.compare(num.returnX(),num.returnY());
	num.swap(num.returnX(),num.returnY());
	std::cout<<"��̬����z��ֵΪ:"<<func::num::z<<"\n";
	return 0;
}
