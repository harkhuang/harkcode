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
		cout<<"父亲身高="<<fatherheight<<"\t"<<"父亲体重="<<fatherweight<<endl;
	}
};
class Son: public father
{
private:
	int Sonwidth,Sonlength;
public:
	void setSonwidth(int Sonswidth){Sonwidth=Sonswidth;}
	void setSonlength(int Sonslength){Sonlength=Sonslength;}
	void ShowSonData(){cout<<"儿子肩宽="<<Sonwidth<<"\t"<<"儿子臂长="<<Sonlength<<endl;}
	void show()
	{
	cout<<"父亲身高="<<fatherheight<<"\t"<<"父亲体重="<<fatherweight<<endl;
	cout<<"儿子肩宽="<<Sonwidth<<"\t"<<"儿子臂长="<<Sonlength<<endl;
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