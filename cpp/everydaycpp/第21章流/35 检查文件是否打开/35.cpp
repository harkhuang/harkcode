/*
//��21.35.1  good()��eof()������ʹ��
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ofstream fout( "a.txt");
	fout<<"������ļ�\n";
	fout.close();
	ifstream fin( "a.txt" );
	if (fin.good())  //�ɽ�fin.good()���滻Ϊfin
	{
		cout<<"���ļ��ɹ�,�������ļ�����:\n";
		char ch;
		while( !fin.eof() )  //δ���ļ�βʱѭ��
		{
			ch=fin.get();
			cout << ch;
		}
	}
	fin.close();
	fin.open("b.txt");
	if (fin.fail())
	{
		cout<<"�ļ���ʧ��\n";
	}
	fin.close();
	return 0;
} 
*/

//��21.35.2   is_open()�������ļ�
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ofstream fout( "a.txt");
	if(fout)
	{
		fout<<"������ļ�\n";
	}
	fout.close();
	ifstream fin( "a.txt" );
	if (fin)
	{
		cout<<"���ļ��ɹ�,�������ļ�����:\n";
		char ch;
		while( fin.get(ch) ) 
		{
			cout << ch;
		}
	}
	fin.close();
	fout.open( "a.txt",ios::app);
	if(fout.is_open())
	{
		fout<<"�ٴ�������ļ�\n";
	}
	fout.close();
	fin.clear();
	fin.open( "a.txt" );
	if (fin.is_open())
	{
		cout<<"���ļ��ɹ�,�������ļ�����:\n";
		char ch;
		while( fin.get(ch) ) 
		{
			cout << ch;
		}
	}
	fin.close();
	return 0;
}
