#include <iostream>
using namespace std;
void show()
{
	std::cout<<"不带返回值的show()函数\n";
}
int add(int x,int y)
{
	return x+y;
}

int main()
{
	show();
	int x=2,y=3;
	cout<<"x与y相加的和为："<<add(x,y);
	return 0;
}
