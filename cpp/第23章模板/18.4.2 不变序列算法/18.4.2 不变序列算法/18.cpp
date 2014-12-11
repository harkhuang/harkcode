/*
//for_each()函数
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
template<class T>
class show
{
public:
  void operator()(const T&t)
  {
   std::cout<<t<<" ";
  }
};
int main()
{
  show<int>one;
  vector<int>vone(10);
  for (int i=0;i<10;++i)
  {
   vone[i]=i*2;
  }
  for_each(vone.begin(),vone.end(),one);
  system("pause");
  return 0;
}
*/

/*
//find()方法
#include <iostream>
#include <string> 
#include <list> 
#include <algorithm> 
using namespace std;
int main (void) 
{ 
  list<string> str; 
  list<string>::iterator it; 
  str.push_back("学生"); 
  str.push_back("老师"); 
  str.push_back("校长"); 
  it = find (str.begin(), str.end(), "校长"); 
  if (it == str.end()) 
  { 
   cout << "没有找到“校长”\n"; 
  } 
  else 
  { 
   cout << *it << endl; 
  } 
  system("pause");
  return 0;
}
*/

/*
//find_if()方法
#include <iostream>
#include <string> 
#include <map> 
#include <algorithm> 
using namespace std;
typedef map<string,string>::const_iterator CIT;
typedef map<string,string>::value_type VT;
class func 
{ 
  public: 
  bool operator () (VT&vt)
  { 
   return vt.second=="1858"; 
  } 
}; 
int main () 
{ 
  map<string,string>one;
  one.insert(VT("创办许汇银行","1897"));
  one.insert(VT("创办杨辰商行","1858"));
  one.insert(VT("创办旗舰船厂","1869"));
  CIT cit=find_if(one.begin(),one.end(),func());
  if (cit==one.end()) 
  { 
   cout << "没有找到...\n"; 
  } 
  else 
  { 
   cout<<cit->second<<"\t"<<cit->first<< endl; 
  }
  system("pause");
  return 0;
}
*/


/*
//adjacent_find()方法
#include <iostream>
#include <algorithm>
#include<set>
using namespace std;
typedef multiset<int>::iterator CIT;
int main()
{
   multiset<int>one;
   one.insert(3);
   one.insert(2);
   one.insert(9);
   one.insert(9);
   one.insert(10);
   one.insert(10);
   cout<<"one容器中的元素如下：\n";
   for (CIT cit=one.begin();cit!=one.end();++cit)
   {
    cout<<*cit<<endl;
   }
   cout<<endl;
   cout<<"现在查找并输出第一组相同元素：\n";
   CIT cit=adjacent_find(one.begin(),one.end());
   cout<<*cit<<endl;
   cit++;
   cout<<*cit<<endl;
   cout<<"现在查找并输出第二组相同元素：\n";
   adjacent_find(cit,one.end());
   cit++;
   cout<<*cit<<endl;
   cit++;
   cout<<*cit<<endl;
}
*/


//count()方法
#include <iostream>
#include <algorithm>
#include<set>
using namespace std;
typedef multiset<int>::iterator CIT;
int main()
{
  multiset<int>one;
  one.insert(3);
  one.insert(2);
  one.insert(9);
  one.insert(9);
  one.insert(10);
  one.insert(10);
  cout<<"one容器中的元素如下：\n";
  for (CIT cit=one.begin();cit!=one.end();++cit)
  {
   cout<<*cit<<endl;
  }
  cout<<endl;
  int n=count(one.begin(),one.end(),10);
  cout<<"该容器中共有"<<n<<"个10。\n";
}
