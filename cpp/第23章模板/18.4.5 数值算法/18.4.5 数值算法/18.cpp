/*
//accumlate����
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;
void show(int val)
{
cout<<val<<endl;
}
int main()
{
vector<int>one;
for (int i=0;i<5;++i)
{
one.push_back(i);
}
for_each(one.begin(),one.end(),show);
int result=accumulate(one.begin(),one.end(),5);
cout<<"����5������5��ӵĽ��Ϊ��"<<result;
}
*/

/*
//inner_product����
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;
void show(int val)
{
cout<<val<<endl;
}
int main()
{
vector<int>one;
for (int i=0;i<5;++i)
{
one.push_back(i);
}
vector<int>two;
for (int i=0;i<10;++i)
{
two.push_back(i);
}
cout<<"���one�е�Ԫ��:\n";
for_each(one.begin(),one.end(),show);
cout<<"���two�е�Ԫ��:\n";
for_each(two.begin(),two.end(),show);
int result=inner_product(one.begin(),one.end(),two.begin(),0);
cout<<"one��ǰ��Ԫ����two��ǰ��Ԫ�����ڻ�֮�Ͳ�����Ӻ�Ľ��Ϊ��"<<result;
}

*/


/*
//partial_sum(first,last,result)
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;
void show(int val)
{
cout<<val<<endl;
}
int main()
{
vector<int>one;
for (int i=0;i<5;++i)
{
one.push_back(i);
}
vector<int>two(5);
partial_sum(one.begin(),one.end(),two.begin());
cout<<"���one�е�Ԫ��:\n";
for_each(one.begin(),one.end(),show);
cout<<"���two�е�Ԫ��:\n";
for_each(two.begin(),two.end(),show);
}
*/

//adjacent_difference (first,last,result)

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;
void show(int val)
{
cout<<val<<endl;
}
int main()
{
vector<int>one;
for (int i=0;i<5;++i)
{
one.push_back(i);
}
vector<int>two(5);
adjacent_difference(one.begin(),one.end(),two.begin());
cout<<"���one�е�Ԫ��:\n";
for_each(one.begin(),one.end(),show);
cout<<"���two�е�Ԫ��:\n";
for_each(two.begin(),two.end(),show);
}
