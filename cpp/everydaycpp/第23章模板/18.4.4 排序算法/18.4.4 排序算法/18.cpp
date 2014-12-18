/*
//sort()方法

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void show(char&t)
{
cout<<t<<" ";
}
int main()
{
vector<char>one;
one.push_back('h');
one.push_back('e');
one.push_back('l');
one.push_back('l');
one.push_back('o');
for_each(one.begin(),one.end(),show);
sort(one.begin(),one.end());
cout<<"\n进行排序后：\n";
for_each(one.begin(),one.end(),show);
return 0;
}
*/


/*
//partial_sort()方法

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void show(char&t)
{
  cout<<t<<" ";
}
int main()
{
  vector<char>one;

  one.push_back('z');
  one.push_back('c');
  one.push_back('b');
  one.push_back('o');
  one.push_back('p');
  one.push_back('t');
  one.push_back('i');
  one.push_back('w');
  one.push_back('x');
  one.push_back('b');
  for_each(one.begin(),one.end(),show);
  partial_sort(one.begin(),one.begin()+5,one.end());
  cout<<"\n进行排序后：\n";
  for_each(one.begin(),one.end(),show);
  return 0;
}
*/

/*
//partial_sort()方法的用途
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
using namespace std;
class student
{
  public:
  student(const string &a, int b):name(a), score(b){}
  string name;
  int score;
  bool operator < (const student &m)const 
  {
  return score< m.score;
  }
};
int main()
{
  vector< student> one;
  student str("王明", 74);
  one.push_back(str);
  str.name="张胜";
  str.score=100;
  one.push_back(str);
  str.name="徐容花";
  str.score=82;
  one.push_back(str);
  str.name="夏宛如";
  str.score=85;
  one.push_back(str);
  str.name="方胜山";
  str.score=48;
  one.push_back(str);
  str.name="常进";
  str.score=99;
  one.push_back(str);
  str.name="钱广大";
  str.score=77;
  one.push_back(str);
  str.name="杨乃军";
  str.score=24;
  one.push_back(str);
  str.name="许放名";
  str.score=76;
  one.push_back(str);
  str.name="路进";
  str.score=80;
  one.push_back(str);
  cout<<"------调用partial_sort函数前..."<<endl;
  for(int i = 0 ; i < one.size(); i ++) 
  cout<<one[i].name<<":\t"<<one[i].score<<endl;
  partial_sort(one.begin(), one.begin()+5, one.end());
  cout <<"-----调用partial_sort函数后...."<<endl;
  for(int i = 0 ; i < one.size(); i ++) 
  cout<<one[i].name<<":\t"<<one[i].score<<endl;
  return 0 ;
}
*/

/*
//nth_element()方法
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
using namespace std;
class student
{
  public:
  student(const string &a, int b):name(a), score(b){}
  string name;
  int score;
  bool operator < (const student &m)const
 {
  return score< m.score;
  }
};
int main()
{
  vector< student> one;
  student str("王明", 74);
  one.push_back(str);
  str.name="张胜";
  str.score=100;
  one.push_back(str);
  str.name="徐容花";
  str.score=82;
  one.push_back(str);
  str.name="夏宛如";
  str.score=85;
  one.push_back(str);
  str.name="方胜山";
  str.score=48;
  one.push_back(str);
  str.name="常进";
  str.score=99;
  one.push_back(str);
  str.name="钱广大";
  str.score=77;
  one.push_back(str);
  str.name="杨乃军";
  str.score=24;
  one.push_back(str);
  str.name="许放名";
  str.score=76;
  one.push_back(str);
  str.name="路进";
  str.score=80;
  one.push_back(str);
  cout<<"------调用nth_element函数前..."<<endl;
  for(int i = 0 ; i < one.size(); i ++) 
  cout<<one[i].name<<":\t"<<one[i].score<<endl;
  nth_element(one.begin(), one.begin()+5, one.end());
  cout <<"-----调用nth_element函数后...."<<endl;
  for(int i = 0 ; i < one.size(); i ++) 
  cout<<one[i].name<<":\t"<<one[i].score<<endl;
  return 0 ;
}
*/

/*
//partition 和stable_partition方法
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
using namespace std;
class student
{
  public:
  student(const string &a, int b):name(a), score(b){}
  string name;
  int score;
  bool operator < (const student &m)const 
  {
  return score< m.score;
  }
};
int main()
{
  vector< student> one;
  student str("王明", 74);
  one.push_back(str);
  str.name="张胜";
  str.score=100;
  one.push_back(str);
  str.name="徐容花";
  str.score=52;
  one.push_back(str);
  str.name="夏宛如";
  str.score=85;
  one.push_back(str);
  str.name="方胜山";
  str.score=48;
  one.push_back(str);
  str.name="常进";
  str.score=99;
  one.push_back(str);
  str.name="钱广大";
  str.score=77;
  one.push_back(str);
  str.name="杨乃军";
  str.score=24;
  one.push_back(str);
  str.name="许放名";
  str.score=76;
  one.push_back(str);
  str.name="路进";
  str.score=80;
  one.push_back(str);
  cout<<"------调用nth_element函数前..."<<endl;
  for(int i = 0 ; i < one.size(); i ++) 
  cout<<one[i].name<<":\t"<<one[i].score<<endl;
  student two("pass", 60);
  partition(one.begin(),one.end(), bind2nd(less<student>(),two));
  cout <<"-----调用nth_element函数后...."<<endl;
  for(int i = 0 ; i < one.size(); i ++) 
  cout<<one[i].name<<":\t"<<one[i].score<<endl;
  return 0 ;
}
*/


/*
//merge()方法
#include <iostream>
#include<algorithm>
#include <vector>
#include <string>
using namespace std;
void show(string val)
{
  cout<<val<<endl;
}
int main()
{
  vector<string>one;
  vector<string>two;
  vector<string>three(5);
  one.push_back("one");
  one.push_back("two");
  one.push_back("three");
  two.push_back("four");
  two.push_back("five");
  cout<<"输出one容器中的所有元素。\n";
  for_each(one.begin(),one.end(),show);
  cout<<"输出two容器中的所有元素。\n";
  for_each(two.begin(),two.end(),show);
  sort(one.begin(),one.end());
  sort(two.begin(),two.end());
  merge(one.begin(),one.end(),two.begin(),two.end(),three.begin());
  cout<<"输出three容器中的所有元素。\n";
  for_each(three.begin(),three.end(),show);
  return 0;
}
*/

/*
//对set容器执行merge()方法
#include <iostream>
#include<algorithm>
#include <set>
#include <string>
using namespace std;
void show(string val)
{
  cout<<val<<endl;
}
int main()
{
set<string>one;
set<string>two;
set<string>three;
one.insert("one");
one.insert("two");
one.insert("three");
two.insert("four");
two.insert("five");
cout<<"输出one容器中的所有元素。\n";
for_each(one.begin(),one.end(),show);
cout<<"输出two容器中的所有元素。\n";
for_each(two.begin(),two.end(),show);
merge(one.begin(),one.end(),two.begin(),two.end(),inserter(three,three.begin()));
cout<<"输出three容器中的所有元素。\n";
for_each(three.begin(),three.end(),show);
return 0;
}
*/


//includes()方法
#include <iostream>
#include<algorithm>
#include <set>
#include <string>
using namespace std;
void show(string val)
{
  cout<<val<<endl;
}
int main()
{
  set<string>one;
  set<string>two;
  one.insert("one");
  one.insert("two");
  one.insert("three");
  two.insert("one");
  two.insert("two");
  two.insert("three");
  cout<<"输出one容器中的所有元素。\n";
  for_each(one.begin(),one.end(),show);
  cout<<"输出two容器中的所有元素。\n";
  for_each(two.begin(),two.end(),show);
  bool check=includes(one.begin(),one.end(),two.begin(),two.end());
  if (check)
  {
   cout<<"两个容器中的元素相等\n";
  }
  else
    cout<<"两个容器中的元素不等\n";
  return 0;
}
