//���ӣ���ʾ��ǰ����������ʹ�õ�ʮ����С�����ַ���

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
