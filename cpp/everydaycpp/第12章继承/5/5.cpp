#include <iostream>
using namespace std;
class father
{
protected:
	int fatherheight,fatherweight;
public:
	void setfatherheight(int fathersheight){fatherheight=fathersheight;}
	void setfatherweight(int fathersweight){fatherweight=fathersweight;}
	void Showfatherheightweight()
	{
		cout<<"�������="<<fatherheight<<"\t"<<"��������="<<fatherweight<<endl;
	}
};
class Son: public father
{
private:
	int Sonwidth,Sonlength;
public:
	void setSonwidth(int Sonswidth){Sonwidth=Sonswidth;}
	void setSonlength(int Sonslength){Sonlength=Sonslength;}
	void ShowSonData(){cout<<"���Ӽ��="<<Sonwidth<<"\t"<<"���ӱ۳�="<<Sonlength<<endl;}
	void show()
	{
	cout<<"�������="<<fatherheight<<"\t"<<"��������="<<fatherweight<<endl;
	cout<<"���Ӽ��="<<Sonwidth<<"\t"<<"���ӱ۳�="<<Sonlength<<endl;
	}
};
int main()
{
	Son a;
	a.setfatherheight(160);
	a.setfatherweight(60);
	a.setSonwidth(60);
	a.setSonlength(80);
	a.show();
	return 0;
}