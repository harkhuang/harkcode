/*
//支持重复元素
#include <iostream>
#include <set>
#include <string>
using namespace std;
int main()
{
  multiset<string>one;
  one.insert("陈群");
  one.insert("陈群");
  multiset<string>::const_iterator it;
  for (it=one.begin();it!=one.end();++it)
  {
    cout<<*it<<endl;
   }
  system("pause");
}
*/

//equal_range()函数
#include <iostream>
#include <set>
#include <string>
using namespace std;
typedef multiset<int>::const_iterator IT;
int main()
{
      multiset<int>one;
      one.insert(100);
  one.insert(100);
  one.insert(200);
  one.insert(300);
  IT it;
  for (it=one.begin();it!=one.end();++it)
  {
    cout<<*it<<endl;
  }
  cout<<"输出所有值为的元素：\n";
  typedef pair<IT,IT> PAIR;
  PAIR p=one.equal_range(100);
  int num=0;
  for (it=p.first;it!=p.second;++it)
  {
   cout<<*it<<endl;
   num++;
  }
  cout<<"数值为的元素共有"<<num<<"个。\n";
  system("pause");
}
