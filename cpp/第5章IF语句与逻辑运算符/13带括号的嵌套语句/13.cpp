#include <iostream>
using namespace std;
int main()
{
	cout<<"请输入一个整数：\n";
	int x;
	cin>>x;
	if(x>1)
	{
		if(x<100)cout<<"x大于1小于100\n";
		//else cout<<"x大于或者等于100\n";
	}
	else 
		if(x<1)cout<<"x小于1\n";
		else cout<<"x等于1\n";
	return 0;
}