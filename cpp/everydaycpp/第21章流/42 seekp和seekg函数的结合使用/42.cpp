#include <iostream>
#include <fstream>
#include <iomanip>
const int num=20;
using namespace std;
struct people 
{
	char name[num];
	int age;
	float pay;
	
};
const char*file="d:people.txt";
inline void deleteline(){while(cin.get()!='\n')continue;}
int main()
{
	people pp={0};
	ofstream fout(file,ios::out|ios::binary);
	bool quit=true;
	while (quit)
	{	
	cout<<"输入名字：";
	cin.get(pp.name,num);
	cin.ignore();
	cout<<"输入年龄：";
	cin>>pp.age;
	cout<<"输入薪水：";
	cin>>pp.pay;
	fout.write((char*)&pp,sizeof pp);
	cout<<"是否继续输入，是按y，否按n：";
	char choice;
	cin>>choice;
	if (choice=='y')
	{
		deleteline();
		continue;}
	else
		quit=false;
	}
    fout.close();
	cout<<fixed;
    fstream InOut; 
	InOut.open(file,ios::in|ios::out|ios::binary);
	int count=0;
	if (InOut.is_open())
	{
		InOut.seekp(0);
		cout<<"当前内容为："<<file<<"\n";
		while (InOut.read((char*)&pp,sizeof pp))
		{
cout<<count++<<":"<<setw(num)<<pp.name<<":"<<setprecision(0)<<setw(12)<<pp.age
				<<setprecision(2)<<setw(16)<<pp.pay<<endl;
		}
		if (InOut.eof())
		{
			InOut.clear();
		}
		else
		{
			cerr<<"读取错误"<<file<<".\n";
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		cerr<<file<<"不能打开\n";
		exit(EXIT_FAILURE);
	}
	cout<<"输入你希望改变的编号：";
	long line;
	cin>>line;
	cin.ignore();
	if (line<0||line>=count)
	{
		cerr<<"无效编号\n";
		exit(EXIT_FAILURE);
	}
	streampos place=line*sizeof pp;
	InOut.seekg(place);
	if (InOut.fail())
	{
		cerr<<"尝试查询失败\n";
		exit(EXIT_FAILURE);
	}
	InOut.read((char*)&pp,sizeof pp);
	cout<<"你的选择为：\n";
	cout<<line<<":"<<setw(num)<<pp.name<<":"<<setprecision(0)<<setw(12)<<pp.age
		<<setprecision(2)<<setw(16)<<pp.pay<<endl;
	if (InOut.eof())
	{
		InOut.clear();
	}
	cout<<"输入名字：";
	cin.get(pp.name,num);
	cin.ignore();
	cout<<"输入年龄：";
	cin>>pp.age;
	cout<<"输入薪水：";
	cin>>pp.pay;
    InOut.seekp(place);
	InOut.write((char*)&pp,sizeof pp)<<flush;
	if (InOut.fail())
	{
		cerr<<"尝试写入失败\n";
		exit(EXIT_FAILURE);
	}
	count=0;
	InOut.seekg(0);
	cout<<"当前内容为："<<file<<"\n";
	while (InOut.read((char*)&pp,sizeof pp))
	{
		cout<<count++<<":"<<setw(num)<<pp.name<<":"
			<<setprecision(0)<<setw(12)<<pp.age
			<<setprecision(2)<<setw(16)<<pp.pay<<endl;
	}
	InOut.close();
	cout<<"完成\n";
	return 0;
}
