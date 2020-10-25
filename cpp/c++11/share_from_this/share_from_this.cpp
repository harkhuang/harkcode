
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

#include <memory>
#include <iostream>

// 异步调用省事了
struct Good : std::enable_shared_from_this<Good> // 注意：继承
{
public:


	// 使用shared_from_this() 返回该类
	// 通过this 指针和这个类建立关联关系
	std::shared_ptr<Good> getptr() {
		return shared_from_this();
	}
	~Good() { std::cout << "Good::~Good() called" << std::endl; }
};
 

int main()
{
	// 错误的示例，每个shared_ptr都认为自己是对象仅有的所有者
	std::shared_ptr<Bad> bp1(new Bad());
	std::shared_ptr<Bad> bp2 = bp1->getptr();
	// 打印bp1和bp2的引用计数
	std::cout << "bp1.use_count() = " << bp1.use_count() << std::endl;
	std::cout << "bp2.use_count() = " << bp2.use_count() << std::endl;




		// 大括号用于限制作用域，这样智能指针就能在system("pause")之前析构
	{
		std::shared_ptr<Good> gp1(new Good());
		std::shared_ptr<Good> gp2 = gp1->getptr();
		// 打印gp1和gp2的引用计数
		std::cout << "gp1.use_count() = " << gp1.use_count() << std::endl;
		std::cout << "gp2.use_count() = " << gp2.use_count() << std::endl;
	}
	//system("pause");
} 