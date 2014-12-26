/********************************************************************
# File Name:    1-1.cpp
# Version:      1.0
# Mail:         shiyanhk@gmail.com
# Created Time: 2014-08-15
*********************************************************************/

#include <iostream>
using namespace std;



class Point3d
{
public:
   Point3d( float x = 0.0,
            float y = 0.0, float z = 0.0 )
      : _x( x ), _y( y ), _z( z ) {}

   float x() { return _x; }
   float y() { return _y; }
   float z() { return _z; }

   void x( float xval ) { _x = xval; }

   // ... etc ...
private:
   float _x;
   float _y;
   float _z;
};

inline  ostream& operator<<( ostream &os, const Point3d &pt )
{
  os << "("<<pt.x()<<","<<pt.y()<<","<<pt.z()<<")";
}



int main()
{
   return 0;
}
