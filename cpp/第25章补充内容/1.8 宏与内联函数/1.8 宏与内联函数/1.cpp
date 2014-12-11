#include <iostream>
using namespace std;
inline int func1(int x) {return (x)*2;}
inline int func2(int x) {return x*2;}
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
