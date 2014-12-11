/*
//21.36.1  以文本形式输出到文件
#include <iostream>
#include<fstream>
using namespace std;
const int num=20;
struct people
{
	char name[num];
	double weight;
	int tall;
	int age;
	char sex;
};
int main()
{
    people pe={"李勇",78.5,181,25,'f'};
    ofstream fout("people.dat",ios::out|ios::app);
	fout<<pe.name<<" "<<pe.age<<" "<<pe.sex<<" "<<pe.tall<<" "<<pe.weight<<" "<<"\n";
    fout.close();
    ifstream fin("people.dat");
    char ch[255];
    fin.getline(ch,255-1,0);
	cout<<ch;
    fin.close();
    return 0;
}
*/


//21.36.2  以二进制形式输出到文件
#include <iostream>
#include<fstream>
using namespace std;
const int num=20;
struct people
{
	char name[num];
	double weight;
	int tall;
	int age;
	char sex;
};
int main()
{
	people pe={"李勇",78.5,181,25,'f'};
	ofstream fout("people.txt",ios::binary);
	fout.write((char*)&pe,sizeof pe);
	fout.close();
	people pe1={"张玲",65.4,165,62,'m'};
	ifstream fin("people.txt",ios::binary);
	fin.read((char*)&pe1,sizeof pe1);
	cout<<pe1.name<<" "<<pe1.age<<" "<<pe1.sex<<" "<<pe1.tall<<" "<<pe1.weight<<" "<<"\n";
	fin.close();
	return 0;
}
