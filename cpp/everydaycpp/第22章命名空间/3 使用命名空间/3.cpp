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
func::num::~num(){std::cout<<"析构函数执行...\n";}
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
	cout<<"交换前，x的值为:"<<rx<<" y的值为："
		<<ry<<"\n";
	temp=rx;
	rx=ry;
	ry=temp;
	cout<<"交换后，x的值为:"<<rx<<" y的值为："
		<<ry<<"\n";
}
void func::num::compare(int ax,int ay)
{
	using std::cout;
	if (ax<ay)
	{
		cout<<"x比y小\n";
	}
	else if (ax=ay)
	{
		cout<<"x等于y\n";
	}
	else
	{
		cout<<"y比x小\n";
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
	std::cout<<"静态变量z的值为:"<<func::num::z<<"\n";
	return 0;
}
