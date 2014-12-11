#include <iostream>
using namespace std;
void show()
{
	cout<<"该语句所在函数名为："<<__FUNCDNAME__<<endl;
	cout<<"当前文件为："<<__FILE__<<endl;
	cout<<"当前代码所在行为："<<__LINE__<<endl;
}
int main()
{
	cout<<"当前文件为："<< __FILE__ <<endl;
	cout<<"编译日期为："<<__DATE__<<endl;
	cout<<"编译时间为："<<__TIME__<<endl;
	cout<<"当前代码所在行为："<<__LINE__<<endl;
	cout<<"该语句所在函数名为："<<__FUNCTION__<<endl;
	show();
	return 0;
}
