#include <iostream>
using namespace std;
template<class T>
class num 
{
public:
  num():x(0){}
  T get(){return y;}
private:
  T x;
  static T y;
};
template<class T>
T num<T>::y=1;
int main()
{
  num<int>one;
  cout<<one.get();
}
