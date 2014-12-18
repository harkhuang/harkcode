#include <iostream>
#include <string>
using namespace std;
template<class T1,class T2>
class People
{
public:
	T1&getx();
	T2&gety();
	T1 getx()const{return x;}
	T2 gety()const{return y;}
	People(const T1&a,const T2&b):x(a),y(b){cout<<"构造函数\n";}
private:
	T1 x;
	T2 y;
};
template<class T1,class T2>
T1&People<T1,T2>::getx()
{
	return x;
}
template<class T1,class T2>
T2&People<T1,T2>::gety()
{
	return y;
}
int main()
{
	People<string,int>one[4]={
	People<string,int>("hello world",5),
	People<string,int>("good morning",6),
	People<string,int>("sit down please",8),
	People<string,int>("have a cup of tea",2)
	};
	int num=sizeof(one)/sizeof(People<string,int>);
	cout<<"输出对象数组one的所有元素:\n";
	for (int i=0;i<num;i++)
	{
		cout<<one[i].gety()<<":\t"
			<<one[i].getx()<<endl;
	}
		cout<<"修改one[3]的数据并输出:\n";
		one[3].getx()="gertie's fab eat";
		one[3].gety()=6;
		cout<<one[3].gety()<<":\t"
			<<one[3].getx()<<endl;
	return 0;
}
