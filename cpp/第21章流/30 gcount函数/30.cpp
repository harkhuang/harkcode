/*
#include <iostream>
using namespace std;
int main()
{
	char ch[30];
	cin>>ch;
	int i=cin.gcount();
	cout<<"���뻺�����й���"<<i<<"���ַ�\n";
	return 0;
}
*/

#include <iostream>
using namespace std;
int main()
{
	char ch[30];
	cin.getline(ch,30);
	int i=cin.gcount();
	cout<<"���뻺�����й���"<<i<<"���ַ�\n";
	return 0;
}
