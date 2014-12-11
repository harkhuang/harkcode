#include<iostream>
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
  for (int i=0;i<10;++i)
  {
   one(i);
  }
  return 0;
}
