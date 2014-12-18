#include <iostream>
using namespace std;
template<class T>
class people
{
 public:
    people(T x,T y):X(x),Y(y){}
    T getX(){return X;}
    T getY(){return Y;}
 private:
    T X,Y;
};
int main()
{
  people<int> Jack(3,4);
  cout<<Jack.getX()<<'\n'<<Jack.getY()<<endl;
  return 0;
}
