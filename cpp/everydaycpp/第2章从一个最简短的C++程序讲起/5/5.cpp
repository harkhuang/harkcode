#include <iostream>
namespace a 
{
	int b=5;
}
namespace c 
{
	int b=8;
}
int main()
{
	using namespace a;
	using namespace c;
	//int b=9;
	std::cout<<b;
	return 0;
}