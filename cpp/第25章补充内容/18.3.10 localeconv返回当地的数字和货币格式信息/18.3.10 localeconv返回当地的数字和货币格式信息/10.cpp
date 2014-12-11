//例子：显示当前地理区域所使用的十进制小数点字符。

#include <iostream> 
#include <locale.h> 
using namespace std;
int main() 
{ 
	struct lconv lc; 
	lc= *localeconv(); 
	cout<<"Decimal symbol:"<<lc.decimal_point<<"\n"; 
	return 0; 
} 
