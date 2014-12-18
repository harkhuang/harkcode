/*带参数的宏函数
#include <iostream>
#define func(x) ((x)*2)
using namespace std;
int main()
{
  int x=func(9);
  cout<<x<<endl;
  return 0;
}
*/

//宏函数中括号的作用
#include <iostream>
#define func1(x) ((x)*2)
#define func2(x)  x*2
using namespace std;
int main()
{
int x=func1(9);
cout<<"x:"<<x<<endl;
int y=func2(9);
cout<<"y:"<<y<<endl;
x=func1(9+1);
cout<<"x:"<<x<<endl;
y=func2(9+1);
cout<<"y:"<<y<<endl;
return 0;
}
