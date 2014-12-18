/*
//for_each()����
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
//find()����
#include <iostream>
#include <string> 
#include <list> 
#include <algorithm> 
using namespace std;
int main (void) 
{ 
  list<string> str; 
  list<string>::iterator it; 
  str.push_back("ѧ��"); 
  str.push_back("��ʦ"); 
  str.push_back("У��"); 
  it = find (str.begin(), str.end(), "У��"); 
  if (it == str.end()) 
  { 
   cout << "û���ҵ���У����\n"; 
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
//find_if()����
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
  one.insert(VT("�����������","1897"));
  one.insert(VT("���������","1858"));
  one.insert(VT("�����콢����","1869"));
  CIT cit=find_if(one.begin(),one.end(),func());
  if (cit==one.end()) 
  { 
   cout << "û���ҵ�...\n"; 
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
//adjacent_find()����
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
   cout<<"one�����е�Ԫ�����£�\n";
   for (CIT cit=one.begin();cit!=one.end();++cit)
   {
    cout<<*cit<<endl;
   }
   cout<<endl;
   cout<<"���ڲ��Ҳ������һ����ͬԪ�أ�\n";
   CIT cit=adjacent_find(one.begin(),one.end());
   cout<<*cit<<endl;
   cit++;
   cout<<*cit<<endl;
   cout<<"���ڲ��Ҳ�����ڶ�����ͬԪ�أ�\n";
   adjacent_find(cit,one.end());
   cit++;
   cout<<*cit<<endl;
   cit++;
   cout<<*cit<<endl;
}
*/


//count()����
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
  cout<<"one�����е�Ԫ�����£�\n";
  for (CIT cit=one.begin();cit!=one.end();++cit)
  {
   cout<<*cit<<endl;
  }
  cout<<endl;
  int n=count(one.begin(),one.end(),10);
  cout<<"�������й���"<<n<<"��10��\n";
}
