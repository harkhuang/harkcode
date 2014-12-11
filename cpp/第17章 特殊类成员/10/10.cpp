#include <iostream>
using namespace std;
class Paper 
{
public:
	void read(){cout<<"纸上面的字可以读\n";}
	void write(){cout<<"纸可以用来写字\n";}
	void burn(){cout<<"纸可以用来点火\n";}
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
		cout<<"(0)退出(1)读(2)写(3)点火:";
		cin>>choice[0];
		if (choice[0]>'3'||choice[0]<'0')
		{
			cout<<"请输入从0到3之间的数字\n";
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