#include <iostream>
#include <iterator>
#include <set>
#include <string>
using namespace std;
typedef set<string>::const_iterator CIT;
template<class T>
void show(CIT&it,set<T>&s)
{
  for (it=s.begin();it!=s.end();++it)
  {
   cout<<*it<<"\t";
  }
  cout<<endl;
}
int main()
{
  const int N=5;
  string s1[N]={"Mick","Bill","Gate","Rose","Jane"};
  string s2[N]={"张锋","秦平","李力","陆放","胡涛"};
  set<string>name1;
  name1.insert(s1,s1+N);
  set<string>name2(s2,s2+N);
  CIT it;
  cout<<"输出name1中各个元素：\n";
  show(it,name1);
  cout<<"输出name2中各个元素：\n";
  show(it,name2);
  cout<<"查找name1中大于或者等于关键字“李力”的第一个元素。\n";
  it=name2.lower_bound("李力");
  cout<<*it<<endl;
  cout<<"查找name1中大于关键字“李力”的第一个元素。\n";
  it=name2.upper_bound("李力");
  cout<<*it<<endl;
  system("pause");
}
