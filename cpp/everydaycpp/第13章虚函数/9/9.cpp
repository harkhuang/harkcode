#include <iostream>
using namespace std;
class father
{
public:
	virtual void run()const{cout<<"���׿���������\n";}
};
class son:public father
{
public:
	void run()const{cout<<"���ӿ�����ʮ����\n";}
};
class daughter:public father
{
public:
	void run()const{cout<<"Ů��������������\n";}
};
void one(father);
void two(father*);
void three(father&);
int main()
{
	father*p=0;
	int choice;
	while (1)
	{
		bool quit=false;
		cout<<"(0)quit (1)son (2)daughter (3)father:";
		cin>>choice;
		switch (choice)
		{
		case 0:quit=true;
			break;
		case 1:p=new son;
			one(*p);
			break;
		case 2:p=new daughter;
			two(p);
			break;
		case 3:p=new father;
			three(*p);
			break;
		default:cout<<"������0��3֮�������\n";
			break;
		}
		if (quit)
		{
			break;
		}
	}
	return 0;
}
void one(father one)
{
	one.run();
}
void two(father*two)
{
	two->run();
}
void three(father&three)
{
	three.run();
}