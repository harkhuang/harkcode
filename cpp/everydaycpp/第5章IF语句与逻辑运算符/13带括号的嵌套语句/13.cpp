#include <iostream>
using namespace std;
int main()
{
	cout<<"������һ��������\n";
	int x;
	cin>>x;
	if(x>1)
	{
		if(x<100)cout<<"x����1С��100\n";
		//else cout<<"x���ڻ��ߵ���100\n";
	}
	else 
		if(x<1)cout<<"xС��1\n";
		else cout<<"x����1\n";
	return 0;
}