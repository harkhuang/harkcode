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
	father(){cout<<"构造基类\n";}
	void print(){cout<<name<<"身高为："<<tall<<"\n";}
	~father(){cout<<"释放基类对象\n";}
};
father::father(string a,int i)
{
	cout<<"\n在基类的构造函数内\n";
	name=a;
	tall=i;
	print();
	cout<<"离开基类构造函数\n";
}
class son:public father
{
private:
	int weight;
public:
	son(string a,int i,int j);
	void print1();
	~son(){cout<<"\n释放子类对象\n";}
};
son::son(string a,int i,int j):father(a,i)
{
	
	weight=j;
	cout<<"\n在子类的构造函数内\n";
}
void son::print1()
{
	father::print();
	cout<<"体重："<<weight;
}
int main()
{
	son Mike("Mike",180,80);
	Mike.print1();
	cout<<"\n 程序结束\n";
	return 0;
}