#include <iostream>
using namespace std;
class A 
{
public:
	virtual int get(){return 1;}
};
class B:public A 
{
public :
	int get(){return 2;}
};
void main()
{
	while (1)
	{
		cout<<"(1)父类(2)子类(3)退出:";
		int choice;
		cin>>choice;
		A p;
		bool quit=false;
		switch (choice)
		{
		case 1:p=A();
			break;
		case 2:p=B();
			break;
		case 3:quit=true;
			break;
		default:cout<<"请输入1、2或者3。";
			break;
		}
		if (quit==true)
		{
			break;
		}
		cout<<p.get()<<endl;
	}
}