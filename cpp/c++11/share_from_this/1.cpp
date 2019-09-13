
#include <memory>
#include <iostream>
 
class Bad
{
public:
	std::shared_ptr<Bad> getptr() 
	{
		// 获取自己的智能指针
		return std::shared_ptr<Bad>(this);
	}
	~Bad() 
	{ 
		std::cout << "Bad::~Bad() called" << std::endl; 
	}
};
 
/*
➜  share_from_this git:(master) ✗ g++ -std=c++11  1.cpp     
➜  share_from_this git:(master) ✗ ./a.out  
bp1.use_count() = 1
bp2.use_count() = 1
Bad::~Bad() called
Bad::~Bad() called
a.out(89130,0x7fffaa68f380) malloc: *** error for object 0x7fcc4ec00340: pointer being freed was not allocated
*** set a breakpoint in malloc_error_break to debug
[1]    89130 abort      ./a.out*** set a breakpoint in malloc_error_break to debug
*/

int main()
{
	// 错误的示例，每个shared_ptr都认为自己是对象仅有的所有者
	std::shared_ptr<Bad> bp1(new Bad());
	std::shared_ptr<Bad> bp2 = bp1->getptr();
	// 打印bp1和bp2的引用计数
	std::cout << "bp1.use_count() = " << bp1.use_count() << std::endl;
	std::cout << "bp2.use_count() = " << bp2.use_count() << std::endl;
} 