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
	cout<<"�������֣�";
	cin.get(pp.name,num);
	cin.ignore();
	cout<<"�������䣺";
	cin>>pp.age;
	cout<<"����нˮ��";
	cin>>pp.pay;
	fout.write((char*)&pp,sizeof pp);
	cout<<"�Ƿ�������룬�ǰ�y����n��";
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
		cout<<"��ǰ����Ϊ��"<<file<<"\n";
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
			cerr<<"��ȡ����"<<file<<".\n";
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		cerr<<file<<"���ܴ�\n";
		exit(EXIT_FAILURE);
	}
	cout<<"������ϣ���ı�ı�ţ�";
	long line;
	cin>>line;
	cin.ignore();
	if (line<0||line>=count)
	{
		cerr<<"��Ч���\n";
		exit(EXIT_FAILURE);
	}
	streampos place=line*sizeof pp;
	InOut.seekg(place);
	if (InOut.fail())
	{
		cerr<<"���Բ�ѯʧ��\n";
		exit(EXIT_FAILURE);
	}
	InOut.read((char*)&pp,sizeof pp);
	cout<<"���ѡ��Ϊ��\n";
	cout<<line<<":"<<setw(num)<<pp.name<<":"<<setprecision(0)<<setw(12)<<pp.age
		<<setprecision(2)<<setw(16)<<pp.pay<<endl;
	if (InOut.eof())
	{
		InOut.clear();
	}
	cout<<"�������֣�";
	cin.get(pp.name,num);
	cin.ignore();
	cout<<"�������䣺";
	cin>>pp.age;
	cout<<"����нˮ��";
	cin>>pp.pay;
    InOut.seekp(place);
	InOut.write((char*)&pp,sizeof pp)<<flush;
	if (InOut.fail())
	{
		cerr<<"����д��ʧ��\n";
		exit(EXIT_FAILURE);
	}
	count=0;
	InOut.seekg(0);
	cout<<"��ǰ����Ϊ��"<<file<<"\n";
	while (InOut.read((char*)&pp,sizeof pp))
	{
		cout<<count++<<":"<<setw(num)<<pp.name<<":"
			<<setprecision(0)<<setw(12)<<pp.age
			<<setprecision(2)<<setw(16)<<pp.pay<<endl;
	}
	InOut.close();
	cout<<"���\n";
	return 0;
}
