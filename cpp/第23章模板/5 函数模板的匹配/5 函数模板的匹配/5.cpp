#include <iostream>
using namespace std;
struct people
{
  char name[50];
  int age;
};
template <class T>
void show(T t[],int n)
{
  cout<<"执行函数模板void show(T t[],int n)\n";
  for(int i=0;i<n;i++)
    cout<<t[i]<<' ';
  cout<<endl;
}
template <class T>
void show(T * t[],int n)
{
  cout<<"执行函数模板void show(T * t[],int n)\n";
   for (int i=0;i<n;i++)
     cout<<*t[i]<<' ';
  cout<<endl;
}
int main()
{
  int num[2]={13,31};
  people list[3]={{"Jack",21},{"Mick",24},{"Tom",18}};
  int * pd[3];
  for(int i=0;i<3;i++)
    pd[i]=&list[i].age;
  show(num,2);
  show(pd,3);
  return 0;
}
