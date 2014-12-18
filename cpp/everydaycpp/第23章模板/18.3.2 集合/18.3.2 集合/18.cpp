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
  string s2[N]={"�ŷ�","��ƽ","����","½��","����"};
  set<string>name1;
  name1.insert(s1,s1+N);
  set<string>name2(s2,s2+N);
  CIT it;
  cout<<"���name1�и���Ԫ�أ�\n";
  show(it,name1);
  cout<<"���name2�и���Ԫ�أ�\n";
  show(it,name2);
  cout<<"����name1�д��ڻ��ߵ��ڹؼ��֡��������ĵ�һ��Ԫ�ء�\n";
  it=name2.lower_bound("����");
  cout<<*it<<endl;
  cout<<"����name1�д��ڹؼ��֡��������ĵ�һ��Ԫ�ء�\n";
  it=name2.upper_bound("����");
  cout<<*it<<endl;
  system("pause");
}
