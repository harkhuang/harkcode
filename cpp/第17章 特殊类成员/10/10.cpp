#include <iostream>
using namespace std;
class Paper 
{
public:
	void read(){cout<<"ֽ������ֿ��Զ�\n";}
	void write(){cout<<"ֽ��������д��\n";}
	void burn(){cout<<"ֽ�����������\n";}
};
typedef void (Paper::*p)();
int main()
{
	p func[3]={&Paper::read,&Paper::write,&Paper::burn};
	Paper*pp=0;
	char choice[1];
	bool quit=false;
	while(quit==false)
	{
		cout<<"(0)�˳�(1)��(2)д(3)���:";
		cin>>choice[0];
		if (choice[0]>'3'||choice[0]<'0')
		{
			cout<<"�������0��3֮�������\n";
		}
		else if (choice[0]=='0')
		{
			quit=true;
		}
		else
		{
			int n;
			pp=new Paper;
			n=atoi(choice);
			(pp->*func[n-1])();
			delete pp;
		}
	}
	return 0;
}