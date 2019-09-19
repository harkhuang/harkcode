 /********************************************************************
 # File Name:    test.cpp
 # Version:      1.0
 # Mail:         shiyanhk@gmail.com 
 # Created Time: 2018-07-30
 *********************************************************************/

#include <iostream>
using namespace std;



// 直接从文件中引入 
// 方式和头文件不同 


// 头文件引入是因为 源文件在统一的环境下编译生成的 但是extern引用可以是库里的内容(精确的说是二进制文件中的内容被引入)
extern "C"{
	int hello();
}

int main()
{
	hello();
	return 0;
}
