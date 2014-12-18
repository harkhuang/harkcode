/*
//例21.35.1  good()和eof()函数的使用
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ofstream fout( "a.txt");
	fout<<"输出到文件\n";
	fout.close();
	ifstream fin( "a.txt" );
	if (fin.good())  //可将fin.good()可替换为fin
	{
		cout<<"打开文件成功,以下是文件内容:\n";
		char ch;
		while( !fin.eof() )  //未到文件尾时循环
		{
			ch=fin.get();
			cout << ch;
		}
	}
	fin.close();
	fin.open("b.txt");
	if (fin.fail())
	{
		cout<<"文件打开失败\n";
	}
	fin.close();
	return 0;
} 
*/

//例21.35.2   is_open()方法打开文件
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ofstream fout( "a.txt");
	if(fout)
	{
		fout<<"输出到文件\n";
	}
	fout.close();
	ifstream fin( "a.txt" );
	if (fin)
	{
		cout<<"打开文件成功,以下是文件内容:\n";
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
		fout<<"再次输出到文件\n";
	}
	fout.close();
	fin.clear();
	fin.open( "a.txt" );
	if (fin.is_open())
	{
		cout<<"打开文件成功,以下是文件内容:\n";
		char ch;
		while( fin.get(ch) ) 
		{
			cout << ch;
		}
	}
	fin.close();
	return 0;
}
