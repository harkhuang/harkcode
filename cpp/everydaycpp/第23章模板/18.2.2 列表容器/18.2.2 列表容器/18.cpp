/*
#include <iostream>
#include <list>
using namespace std;
typedef list<int> List;
int main()
{
  List ll;
  List::iterator p;
  for (int i=1;i<10;++i)
   {
    ll.push_back(i*2);
   }
  for (p=ll.begin();p!=ll.end();++p)
   {
    cout<<*p<<" ";
   }
  system("pause");
  return 0;
}
*/

#include <iostream>
#include <list>
using namespace std;
typedef list<int> List;
void show(List&one,List::iterator pos)
{
	for (pos=one.begin();pos!=one.end();++pos)
	{
		cout<<*pos<<" ";
	}
}
int main()
{
	List one;
	int num[6]={0,1,2,3,4,5};
	one.insert(one.begin(),num,num+6);
	List::iterator p;
	show(one,p);
	cout<<"\n倒转所有元素\n";
	one.reverse();
	show(one,p);
	one.sort();
	cout<<"\n按升序排列所有元素\n";
	ostream_iterator<int,char>pp(cout," ");
	copy(one.begin(),one.end(),pp);
	cout<<endl;
	List two(2);
	cout<<"\n将list two的所有元素添加到one的后面\n";
	one.splice(one.end(),two);
	copy(one.begin(),one.end(),pp);
	cout<<endl;
	cout<<"\n删除重复元素\n";
	one.unique();
	show(one,p);
	cout<<endl;
	cout<<"\n删除为0的元素\n";
	one.remove(0);
	show(one,p);
	cout<<endl;
	cout<<"\n清空所有元素\n";
	one.clear();
	show(one,p);
	system("pause");
}
