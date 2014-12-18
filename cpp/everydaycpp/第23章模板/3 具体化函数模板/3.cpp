/*
//例23.3.1   交换结构体数据对象Jack和Mick
#include <iostream>
using namespace std;
template<class T>
void Swap(T &a,T &b);
struct people
{
	char name[10];
	int age;
};
void show(people&p);
int main()
{
	int i=10,j=20;
	cout<<"初始值i="<<i<<",j="<<j<<".\n";
	cout<<"执行Swap函数进行交换....\n";
	Swap(i,j);
	cout<<"现在,i="<<i<<",j="<<j<<".\n";
	people Jack={"Jack",44};
	people Mick={"Mick",24};
	cout<<"交换之前:\n";
	show(Jack);
	show(Mick);
	Swap(Jack,Mick);
	cout<<"交换后:\n";
	show(Jack);
	show(Mick);
	return 0;
}
template<class T>
void Swap(T &a,T &b)
{
	T temp;
	temp=a;
	a=b;
	b=temp;
}
void show(people&p)
{
	cout<<p.name<<"的年龄:"<<p.age<<endl;
}
*/

/*23.3.2   具体化函数模板解决重载问题
#include <iostream>
using namespace std;
template<class T>
void Swap(T &a,T &b);
struct people
{
	char name[10];
	int age;
};
template<>void Swap<people>(people&p1,people&p2);
//void Swap(people&a,people&b);
void show(people&p);
int main()
{
	int i=10,j=20;
	cout<<"初始值i="<<i<<",j="<<j<<".\n";
	cout<<"执行Swap函数进行交换....\n";
	Swap(i,j);
	cout<<"现在,i="<<i<<",j="<<j<<".\n";
	people Jack={"Jack",44};
	people Mick={"Mick",24};
	cout<<"交换之前:\n";
	show(Jack);
	show(Mick);
	Swap(Jack,Mick);
	cout<<"交换后:\n";
	show(Jack);
	show(Mick);
	return 0;
}
template<class T>
void Swap(T &a,T &b)
{
	T temp;
	temp=a;
	a=b;
	b=temp;
}
template<>void Swap<people>(people &a,people &b)
//void Swap(people&a,people&b)
{
	int Age;
	Age=a.age;
	a.age=b.age;
	b.age=Age;
}
void show(people&p)
{
	cout<<p.name<<"的年龄:"<<p.age<<endl;
}
*/

//23.3.3   具体化函数模板与实例化模板函数
#include <iostream>
using namespace std;
template<class T>
void show(T a){cout<<a<<endl;}
template void show<char>(char&);
int main()
{
	show(5);
	return 0;
}
