#include <iostream>
#include <stack>
using namespace std;
int main()
{
	stack<int> s;
	for( int i=0; i < 10; i++ )
	{
		s.push(i);
		cout << "��ǰ��ջ��Ԫ����ĿΪ��" << s.size() << endl;
	}
	cout<<"\n���ε���ջ��Ԫ��\n";
	while( !s.empty() ) 
	{
		cout << s.top() << " ";
		s.pop();
	}
	if (s.empty())
	{
		cout<<"\n\n��ջ�ѿ�\n";
	}
	system("pause");
}
