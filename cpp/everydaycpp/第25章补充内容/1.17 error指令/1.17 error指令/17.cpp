#include <iostream>
#define Test
using namespace std;
int main()
{
#ifndef Test
#error  Test未定义导致编译失败
#endif
	cout<<"程序结束"<<endl;
}
