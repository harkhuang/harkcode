#include <iostream>
using namespace std;
class Human
{
public:
	Human(){cout<<"���캯��ִ����...\n";}
	~Human(){cout<<"��������ִ����...\n";}
};
int main()
{
	Human *p=new Human;
	delete p;
	return 0;
}
