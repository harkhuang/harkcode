#include <iostream>
#include <string>
using namespace std;
class father
{
protected:
	string name;
	int tall;
public:
	father(string a,int i);
	father(){cout<<"�������\n";}
	void print(){cout<<name<<"���Ϊ��"<<tall<<"\n";}
	~father(){cout<<"�ͷŻ������\n";}
};
father::father(string a,int i)
{
	cout<<"\n�ڻ���Ĺ��캯����\n";
	name=a;
	tall=i;
	print();
	cout<<"�뿪���๹�캯��\n";
}
class son:public father
{
private:
	int weight;
public:
	son(string a,int i,int j);
	void print1();
	~son(){cout<<"\n�ͷ��������\n";}
};
son::son(string a,int i,int j):father(a,i)
{
	
	weight=j;
	cout<<"\n������Ĺ��캯����\n";
}
void son::print1()
{
	father::print();
	cout<<"���أ�"<<weight;
}
int main()
{
	son Mike("Mike",180,80);
	Mike.print1();
	cout<<"\n �������\n";
	return 0;
}