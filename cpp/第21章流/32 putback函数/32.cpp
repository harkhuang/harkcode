#include<iostream>
using namespace std;
int main()
{
	char ch;
	while (cin.get(ch)) //���ļ�β����
	{
		if (ch=='#') //����ch����'#'
		{
			cin.putback('$');  //��'#'��������'��'�Ž�������
		}
		else
		{
			cout<<ch;
		}
	}
	return 0;
}
