#include <iostream>
namespace func
{
    void swap(int&rx,int&ry);
	void compare(int x,int y);
}
namespace people
{
	namespace Jack
	{
		void show(){std::cout<<"Jack is a good man\n";}
	}
}

int main()
{
	
	int x=5,y=6;
	func::compare(x,y);
	func::swap(x,y);
	people::Jack::show();
	return 0;
}
void func::swap(int&rx,int&ry)
	{
		using std::cout;
		int temp;
		cout<<"����ǰ��x��ֵΪ:"<<rx<<"y��ֵΪ��"
			<<ry<<"\n";
		temp=rx;
		rx=ry;
		ry=temp;
		cout<<"������x��ֵΪ:"<<rx<<"y��ֵΪ��"
			<<ry<<"\n";
	}
void func::compare(int x,int y)
	{
		using std::cout;
		if (x<y)
		{
			cout<<"x��yС\n";
		}
		else if (x=y)
		{
			cout<<"x����y\n";
		}
		else
		{
			cout<<"y��xС\n";
		}
} 
