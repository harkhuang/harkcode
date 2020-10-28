// tesdll.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "tesdll.h"
#include <iostream>

// 这是导出变量的一个示例
TESDLL_API int ntesdll=0;

// 这是导出函数的一个示例。
TESDLL_API int fntesdll(void)
{
	return 42;
}

// 这是已导出类的构造函数。
// 有关类定义的信息，请参阅 tesdll.h
Ctesdll::Ctesdll()
{
	std::cout<< "xxxxxx" <<std::endl;
	return;
}


void Ctesdll::foo()
{
	std::cout<< "xxxxxx" <<std::endl;
	 
}
