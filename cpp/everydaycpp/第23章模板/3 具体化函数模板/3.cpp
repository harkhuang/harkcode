/*
//��23.3.1   �����ṹ�����ݶ���Jack��Mick
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
	cout<<"��ʼֵi="<<i<<",j="<<j<<".\n";
	cout<<"ִ��Swap�������н���....\n";
	Swap(i,j);
	cout<<"����,i="<<i<<",j="<<j<<".\n";
	people Jack={"Jack",44};
	people Mick={"Mick",24};
	cout<<"����֮ǰ:\n";
	show(Jack);
	show(Mick);
	Swap(Jack,Mick);
	cout<<"������:\n";
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
	cout<<p.name<<"������:"<<p.age<<endl;
}
*/

/*23.3.2   ���廯����ģ������������
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
	cout<<"��ʼֵi="<<i<<",j="<<j<<".\n";
	cout<<"ִ��Swap�������н���....\n";
	Swap(i,j);
	cout<<"����,i="<<i<<",j="<<j<<".\n";
	people Jack={"Jack",44};
	people Mick={"Mick",24};
	cout<<"����֮ǰ:\n";
	show(Jack);
	show(Mick);
	Swap(Jack,Mick);
	cout<<"������:\n";
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
	cout<<p.name<<"������:"<<p.age<<endl;
}
*/

//23.3.3   ���廯����ģ����ʵ����ģ�庯��
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
