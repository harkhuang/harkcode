#include <iostream>
using namespace std;
class Human
{
public:
	Human(){cout<<"构造函数执行中...\n";}
};
int main()
{
	Human *p=new Human;
	return 0;
}

