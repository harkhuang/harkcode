#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	const int num=255;
	char temp[num]={0};
	ofstream fout( "a.txt");
	fout<<"������ļ�\n";
	fout.close();
	fout.open("a.txt",ios::app);
	fout<<"��ӵ��ļ�";
	fout.close();
	ifstream fin( "a.txt" );
	fin.getline(temp,num-1,0);
	cout<<temp<<endl;
    fin.close();
	return 0;
}
