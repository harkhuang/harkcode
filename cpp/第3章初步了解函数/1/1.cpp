#include <iostream>
int show(int x,int y)
{
	return x+y;
}
int main()
{
	int a,b;
	std::cout<<"请输入两个整数：";
	std::cin>>a;
	std::cin>>b;
	std::cout<<"a+b="<<show(a,b);
	std::cout<<"main函数结束\n";
	return 0;
}
