#include <iostream>
using namespace std;
int main()
{
	int s=0;
	while (1)
	{
		
		int n;
		cout<<"请输入一个数字：";
		cin>>n;
		cout<<"您输入的数字是："<<n<<endl;
		s++;
		if (s>3) 
		break;
	}
	cout<<"该程序执行了"<<s<<endl;
	return 0;
}