/*
//例18.17.1  结构体

#include <iostream>
using namespace std;
struct A
{
public:
	int get(){return x;}
	void set(int i){x=i;}
private:
	int x;
};
int main()
{
	A a;
	a.set(9);
	cout<<a.get();
	return 0;
}
*/

/*
//例18.17.2  结构体与类的区别

#include <iostream>
using namespace std;
struct A
{
	int get(){return x;}
	void set(int i){x=i;}
private:
	int x;
};
int main()
{
	A a;
	a.set(9);
	cout<<a.get();
	return 0;
}
*/


/*
//例18.17.3  结构体的作用

#include <iostream>
using namespace std;
struct people
{
	double weight;
	double tall;
	int age;
	char *name;
	char *native;
	bool sex;
};
void check(bool s){if(s==1)cout<<"男"<<endl;else cout<<"女"<<endl;}
int main()
{
	people Jack=
	{
		180.5,
			179.3,
			34,
            "Jack",
			"济南",
			1
	};
	cout<<Jack.name<<endl;
	cout<<Jack.native<<endl;
	cout<<Jack.tall<<endl;
	cout<<Jack.weight<<endl;
	cout<<Jack.age<<endl;
	check(Jack.sex);
	return 0;
}
*/

//例18.17.4	结构体与构造函数

#include <iostream>
#include <string>
using namespace std;
struct people
{
	people(double t_weight,double t_tall,int t_age,string t_name, char *t_native,bool t_sex);
	double weight;
	double tall;
	int age;
	string name;
	char *native;
	bool sex;
};
people::people(double t_weight,double t_tall,int t_age,string t_name, char *t_native,bool t_sex)
{
	weight = t_weight;
	tall = t_tall;
	age = t_age;
	name = t_name;
	native = t_native;
	sex = t_sex;
};
void check(bool s){if(s==1)cout<<"男"<<endl;else cout<<"女"<<endl;}

int main()
{
	people Jack
		(
		180.5,
		179.3,
		34,
		"Jack",
		"济南",
		1
		);
	cout<<Jack.name<<endl;
	cout<<Jack.native<<endl;
	cout<<Jack.tall<<endl;
	cout<<Jack.weight<<endl;
	cout<<Jack.age<<endl;
	check(Jack.sex);
	return 0;
}
