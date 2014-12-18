#include <iostream>
int main()
{
	int i;
    std::cout<<"请输入一个数：";
	std::cin>>i;
	while (i<100&&i>0)
	{
		std::cout<<"i:"<<i<<std::endl;
		i++;
	}
	
	
	return 0;
}