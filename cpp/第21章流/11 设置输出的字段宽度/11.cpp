//例21.11	使用cout对象调用width()函数调节输出的宽度
#include <iostream>
using namespace std;
int main()
{
	cout.width(20);
	cout<<"help"<<endl;
	cout<<"help\n";
	cout.width(1);
	cout<<"help"<<endl;
	return 0;
}
