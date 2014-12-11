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
	cout<<"阿司匹林的库存总价格为：";
	cout<<aspl::get()<<endl;
	int i=0;
	cout<<"请输入第"<<i<<"次购进的阿司匹林的单箱价格：";
	cin>>f;
	aspl*p[5];
	p[i]=new aspl(f);
	cout<<"阿司匹林的库存总价格为：";
	cout<<aspl::get()<<endl;
	i++;
	cout<<"请输入第"<<i<<"次购进的阿司匹林的单箱价格：";
	cin>>f;
	p[i]=new aspl(f);
	cout<<"阿司匹林的库存总价格为：";
	cout<<aspl::get()<<endl;
	cout<<"请输入卖出的阿司匹林的编号，编号即第几次购进：";
	cin>>i;
	delete p[i];
	cout<<"阿司匹林的库存总价格为：";
	cout<<aspl::get()<<endl;
	return 0;
}