//例18.9  string类erase成员函数的使用

#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s("give me");
	cout << "原始字符串为：" << s<< endl;
	s.erase( 2, 2 );
	cout << "现在字符串为：" << s << endl;
	s.erase( 2 );
	cout << "现在字符串为：" << s << endl;
	s.erase();
	cout << "现在字符串为：" << s << endl;
	return 0;
}
