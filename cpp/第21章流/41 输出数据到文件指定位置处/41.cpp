#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream fout("D:people.txt");
	if (!fout)
	{
		cout<<"�����ļ�ʧ��";
	}
	fout<<"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	fout.close();
	fstream fout1;
	fout1.open("D:people.txt");
	char ch[]="123456789abcdefghijklmnopqrstuvwxyz";
	fout1.seekp(9,ios::beg);
	fout1<<ch;
	fout1.close();
    ifstream fin("D:people.txt");
	if (fin.fail())
	{
		cout<<"���ļ�ʧ��\n";
	}
	char ch1;
	while (fin.get(ch1))
	{
		cout<<ch1;
	}
	fin.close();
	return 0;
}
