#include <iostream>
#include <stack>
using namespace std;
int main()
{
	stack<int> s;
	for( int i=0; i < 10; i++ )
	{
		s.push(i);
		cout << "当前堆栈中元素数目为：" << s.size() << endl;
	}
	cout<<"\n依次弹出栈顶元素\n";
	while( !s.empty() ) 
	{
		cout << s.top() << " ";
		s.pop();
	}
	if (s.empty())
	{
		cout<<"\n\n堆栈已空\n";
	}
	system("pause");
}
