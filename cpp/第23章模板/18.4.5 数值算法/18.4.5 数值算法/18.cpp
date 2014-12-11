/*
//accumlate函数
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
cout<<"以上5个数与5相加的结果为："<<result;
}
*/

/*
//inner_product函数
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
cout<<"输出one中的元素:\n";
for_each(one.begin(),one.end(),show);
cout<<"输出two中的元素:\n";
for_each(two.begin(),two.end(),show);
int result=inner_product(one.begin(),one.end(),two.begin(),0);
cout<<"one的前个元素与two的前个元素做内积之和并与相加后的结果为："<<result;
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
cout<<"输出one中的元素:\n";
for_each(one.begin(),one.end(),show);
cout<<"输出two中的元素:\n";
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
cout<<"输出one中的元素:\n";
for_each(one.begin(),one.end(),show);
cout<<"输出two中的元素:\n";
for_each(two.begin(),two.end(),show);
}
