#include <iostream>
using namespace std;
void (*p[5])(int&,int&);
void square(float&x,float&y){x=x*x;y=y*y;}
void cube(float&x,float&y){x=x*x*x;y=y*y*y;}
void print(float&x,float&y){cout<<"����"<<x<<"\t"<<"��"<<y<<endl;}
void Swap(float&x,float&y){int z;z=x;x=y;y=z;}
int main()
{
	float a=2,b=3;
	char choice='0';
	int i;
	void (*p[5])(float&x,float&y);
	for (i=0;i<5;i++)
	{
		cout<<"(0)�˳�(1)ƽ��(2)����(3)����x��y��ֵ��";
		cin>>choice;
		bool quit=false;
		switch (choice)
		{
		case'0':quit=true;break;
		case'1':p[i]=square;break;
		case'2':p[i]=cube;break;
		case'3':p[i]=Swap;break;
		default:p[i]=0;
		}
		if(quit)break;
		if(p[i]==0)
		{
			cout<<"������һ����0��3֮�������\n";
			i=i-1;
			continue;
		}
		cout<<"��"<<i+1<<"��ִ��,����5�ν���\n";
		cout<<"��ʼֵ\n";
		print(a,b);
		cout<<"���ڵ��ú���ָ������p["<<i<<"]��ָ��ĺ���...\n";
		p[i](a,b);
		cout<<"�����\n";
		print(a,b);
	}
	return 0;
}