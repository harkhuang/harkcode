#include <iostream>
using namespace std;
void show()
{
	std::cout<<"��������ֵ��show()����\n";
}
int add(int x,int y)
{
	return x+y;
}

int main()
{
	show();
	int x=2,y=3;
	cout<<"x��y��ӵĺ�Ϊ��"<<add(x,y);
	return 0;
}
