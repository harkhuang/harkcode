#include <iostream>
using namespace std;
class aspl 
{
public:
	aspl(float p){price=p;TotalPrice=p+TotalPrice;}
	~aspl(){TotalPrice=TotalPrice-price;}
	static float get(){return TotalPrice;}
private:
	float price;
	static float TotalPrice;
};
float aspl::TotalPrice=0;
int main()
{
	float f;
	cout<<"��˾ƥ�ֵĿ���ܼ۸�Ϊ��";
	cout<<aspl::get()<<endl;
	int i=0;
	cout<<"�������"<<i<<"�ι����İ�˾ƥ�ֵĵ���۸�";
	cin>>f;
	aspl*p[5];
	p[i]=new aspl(f);
	cout<<"��˾ƥ�ֵĿ���ܼ۸�Ϊ��";
	cout<<aspl::get()<<endl;
	i++;
	cout<<"�������"<<i<<"�ι����İ�˾ƥ�ֵĵ���۸�";
	cin>>f;
	p[i]=new aspl(f);
	cout<<"��˾ƥ�ֵĿ���ܼ۸�Ϊ��";
	cout<<aspl::get()<<endl;
	cout<<"�����������İ�˾ƥ�ֵı�ţ���ż��ڼ��ι�����";
	cin>>i;
	delete p[i];
	cout<<"��˾ƥ�ֵĿ���ܼ۸�Ϊ��";
	cout<<aspl::get()<<endl;
	return 0;
}