/*
//��21.33.1  ������ݵ��ļ�
#include <fstream>
using namespace std;
int main()
{
	ofstream ocout;
	ocout.open("123.txt");
	ocout<<"hello world";
	ocout.close();
	return 0;
}
*/

/*
//��21.33.2  ��ȡ�ļ��е�����
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	char temp[25]={0};
	ifstream fin( "123.txt" );
    ofstream fout( "124.txt");
	fin>>temp;
    fout<<temp<< endl;
	cout<<temp<<endl;
    fin.close();
    fout.close();
	return 0;
}
*/

//��21.33.3   ��ȡ�ո񼰿ո������ַ�

#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	const num=255;
	char temp1[num]={0};
	char temp2[num]={0};
	ofstream fout( "1.txt");
	cout<<"�����룺";
	cin.getline(temp1,num-1,0);
	int n=strlen(temp1);
	temp1[n-1]='\0';
	fout<<temp1;
	fout.close();
	ifstream fin( "1.txt" );
    fin.getline(temp2,num-1,0);
    fout.open( "2.txt");
    fout<<temp2;
	cout<<temp2;
    fin.close();
    fout.close();
	return 0;
}
