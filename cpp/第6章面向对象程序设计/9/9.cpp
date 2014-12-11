#include <iostream>
using namespace std;
void show();
void show()
{
	cout<<"hello world\n";
}
class Human
{
public:
	void set(int w);

	int show(){return weight;}
private:
	int weight;
};
void Human::set(int w)
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
int main()
{
	/*Human Tom;
	Tom.set(80);
	cout<<"汤姆的体重为："<<Tom.show()<<"\n";
	Human Mike;
	Mike.set(90);
	cout<<"迈克的体重为："<<Mike.show()<<"\n";
	*/
	show();
	return 0;
}
