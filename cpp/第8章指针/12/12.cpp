#include <iostream>
using namespace std;
class Human
{
public:
	Human(){cout<<"构造函数执行中...\n";}
	~Human(){cout<<"析构函数执行中...\n";}
};
int main()
{
	Human *p=new Human;
	delete p;
	return 0;
}
