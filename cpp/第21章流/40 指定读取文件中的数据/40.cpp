#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream fout("people.txt");
	if (!fout)
	{
		cout<<"�����ļ�ʧ��";
	}
	fout<<"123456789abcdefghijklmnopqrstuvwxyz";
	fout.close();
    ifstream fin("people.txt");
	if (fin.fail())
	{
		cout<<"���ļ�ʧ��\n";
	}
	fin.seekg(9,ios::beg);
	char ch;
	while (fin.get(ch))
	{
		cout<<ch;
	}
	fin.close();
	return 0;
} 
