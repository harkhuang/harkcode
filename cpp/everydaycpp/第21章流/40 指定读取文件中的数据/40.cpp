#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream fout("people.txt");
	if (!fout)
	{
		cout<<"创建文件失败";
	}
	fout<<"123456789abcdefghijklmnopqrstuvwxyz";
	fout.close();
    ifstream fin("people.txt");
	if (fin.fail())
	{
		cout<<"打开文件失败\n";
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
