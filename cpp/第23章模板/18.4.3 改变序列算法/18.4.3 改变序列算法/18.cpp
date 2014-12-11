/*
//fill()方法

#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
template<class T>
class show 
{
public:
void operator()(const T&t)
{
cout<<t<<" ";
}
};
int main()
{
show<int>one;
vector<int>vone(10);
fill(vone.begin(),vone.begin()+5,0);
fill(vone.begin()+5,vone.end(),1);
for_each(vone.begin(),vone.end(),one);
cout<<"\n";
return 0;
}
*/

/*
//random_shuffle()方法

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void show(int val)
{
cout<<val<<endl;
}
int main()
{
vector<int>vint;
for (int i=0;i<10;++i)
{
vint.push_back(i);
}
for_each(vint.begin(),vint.end(),show);
cout<<"乱序输出：\n";
random_shuffle(vint.begin(),vint.end());
for_each(vint.begin(),vint.end(),show);
return 0;
}
*/


/*
//partition()方法
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void show(int val)
{
  cout<<val<<endl;
}
bool equal(int val)
{
  return (val==5);
}
int main()
{
  vector<int>one;
  one.push_back(1);
  one.push_back(3);
  one.push_back(5);
  one.push_back(6);
  one.push_back(5);
  one.push_back(4);
  one.push_back(5);
  for_each(one.begin(),one.end(),show);
  cout<<"partition\n";
  partition(one.begin(),one.end(),equal);
  for_each(one.begin(),one.end(),show);
  return 0;
}
*/

//rotate()方法

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void show(char val)
{
  cout<<val;
}
int main()
{
  vector<char>one;
  one.push_back('h');
  one.push_back('e');
  one.push_back('l');
  one.push_back('l');
  one.push_back('o');
  one.push_back('w');
  one.push_back('o');
  one.push_back('r');
  one.push_back('l');
  one.push_back('d');
  for_each(one.begin(),one.end(),show);
  cout<<"\nrotate\n";
  rotate(one.begin(),one.begin()+5,one.end());
  for_each(one.begin(),one.end(),show);
  return 0;
}
