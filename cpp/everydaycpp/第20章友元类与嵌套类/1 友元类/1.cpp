#include <iostream>
using namespace std;
class TV 
{
public:
	friend class Tele;
	TV():on_off(off),volume(20),channel(3),mode(tv){}
private:	
	enum{on,off};
	enum{tv,av};
	enum{minve,maxve=100};
	enum{mincl,maxcl=60};
	bool on_off;
	int  volume;
	int channel;
	int mode;
};
class Tele
{
public:
	   void OnOFF(TV&t){t.on_off=(t.on_off==t.on)?t.off:t.on;}
	   void SetMode(TV&t){t.mode=(t.mode==t.tv)?t.av:t.tv;}
	   bool VolumeUp(TV&t);
	   bool VolumeDown(TV&t);
	   bool ChannelUp(TV&t);
	   bool ChannelDown(TV&t);
	   void show(TV&t)const;	
};
bool Tele::VolumeUp(TV&t)
{
	if (t.volume<t.maxve)
	{
		t.volume++;
		return true;
	} 
	else
	{
		return false;
	}
}
bool Tele::VolumeDown(TV&t)
{
	if (t.volume>t.minve)
	{
		t.volume--;
		return true;
	} 
	else
	{
		return false;
	}
}
bool Tele::ChannelUp(TV&t)
{
	if (t.channel<t.maxcl)
	{
		t.channel++;
		return true;
	} 
	else
	{
		return false;
	}
}
bool Tele::ChannelDown(TV&t)
{
	if (t.channel>t.mincl)
	{
		t.channel--;
		return true;
	} 
	else
	{
		return false;
	}
}
void Tele::show(TV&t)const
{
	if (t.on_off==t.on)
	{
		cout<<"��������"<<(t.on_off==t.on?"����":"�ر�")<<endl;
		cout<<"������СΪ��"<<t.volume<<endl;
		cout<<"�źŽ���ģʽΪ��"<<(t.mode==t.av?"AV":"TV")<<endl;
		cout<<"Ƶ��Ϊ��"<<t.channel<<endl;

	} 
	else
	{
		cout<<"��������"<<(t.on_off==t.on?"����":"�ر�")<<endl;
	}
	
}
int main()
{
	Tele t1;
	TV t2;
	t1.show(t2);
	t1.OnOFF(t2);
	t1.show(t2);
	cout<<"��������"<<endl;
	t1.VolumeUp(t2);
	cout<<"Ƶ��+1"<<endl;
	t1.ChannelUp(t2);
	cout<<"ת��ģʽ"<<endl;
	t1.SetMode(t2);
	t1.show(t2);
	return 0;
}
