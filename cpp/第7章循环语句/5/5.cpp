#include <iostream>
using namespace std;
int main()
{
	int s=0;
	while (1)
	{
		
		int n;
		cout<<"������һ�����֣�";
		cin>>n;
		cout<<"������������ǣ�"<<n<<endl;
		s++;
		if (s>3) 
		break;
	}
	cout<<"�ó���ִ����"<<s<<endl;
	return 0;
}