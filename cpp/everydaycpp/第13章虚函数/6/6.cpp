#include <iostream>
using namespace std;
class A 
{
public:
	int get(){return 1;}
};
class B:public A 
{
public :
	int get(){return 2;}
};
int  main()
{
	while (1)
	{
		cout<<"1.base 2.son 3.exit";
		int choice;
		cin>>choice;
		A*p;
		bool quit=false;
		switch (choice)
		{
		case 1:p=new A;
			break;
		case 2:p=new B;
			break;
		case 3:quit=true;
			break;
		default:cout<<"please input 1 2 3";
			break;
		}
		if (quit==true)
		{
			break;
		}
		cout<<"p->get()"<<p->get()<<endl;
	}
	return 0;
}
