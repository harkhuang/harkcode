#include <iostream>
using namespace std;
int main()
{
    int many;
	cout<<"你想看几次？";
	cin>>many;
	do
	{
		cout<<"\n 问君能有几多愁，恰似一江春水向东流！\n";
		many--;
	}while (many>0);
	cout<<"程序执行完毕，再见。";
	return 0;
}