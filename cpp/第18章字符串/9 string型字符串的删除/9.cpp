//��18.9  string��erase��Ա������ʹ��

#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s("give me");
	cout << "ԭʼ�ַ���Ϊ��" << s<< endl;
	s.erase( 2, 2 );
	cout << "�����ַ���Ϊ��" << s << endl;
	s.erase( 2 );
	cout << "�����ַ���Ϊ��" << s << endl;
	s.erase();
	cout << "�����ַ���Ϊ��" << s << endl;
	return 0;
}
