/********************************************************************
# File Name:    1-1.cpp
# Version:      1.0
# Mail:         shiyanhk@gmail.com
# Created Time: 2014-08-15
# 在c++中class data member :      有两种  static  和 nonstatic
#         class member functions : 有三种 static   和 nonstatic 和 virtual
#
*********************************************************************/

#include <iostream>
using namespace std;



class Point {

public:
  Point(float xval);
  virtual ~Point();

  float x() const;
  static int PointCount();
protected:
  virtual ostream& print(ostream &os)const;
  float _x;
  static int _point_count;
};

int main()
{
  cout << "this is 1-3" << endl;
   return 0;
}
