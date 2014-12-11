#include <iostream>
using std::cout;
class Human
{
public:
	void set(int w)
	{
		if (w>0&&w<100)
		{
			weight=w;
		}
		else
		{
			cout<<"请将set函数的参数设置为一个大于0而小于100的数字，否则默认返回0\n";
			weight=0;
		}
	
	}
	int print(){return weight;}
private:
	int weight;
};
int main()
{
	Human Tom;
	Tom.set(-1);
	cout<<"汤姆的体重为："<<Tom.print()<<"\n";
	Human Mike;
	Mike.set(101);
	cout<<"迈克的体重为："<<Mike.print()<<"\n";
	return 0;
}