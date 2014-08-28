#include <iostream>

using namespace std;

int main()
{
	char a[] = “hello”;
	a[0] = ‘X’;
	cout << a << endl;
	char *p = “world”;     // 注意p指向常量字符串
	p[0] = ‘X’;             // 编译器不能发现该错误
	cout << p << endl;
	return 0;

}