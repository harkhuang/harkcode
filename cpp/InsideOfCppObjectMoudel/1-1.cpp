 /********************************************************************
 # File Name:    1-1.cpp
 # Version:      1.0
 # Mail:         shiyanhk@gmail.com 
 # Created Time: 2014-08-15
 *********************************************************************/

#include <iostream>
using namespace std;



class X
{
   friend istream&
      operator>>( istream&, X& );
public:
   X( int sz = 1024 ) { ptr = new char[ sz ]; }

private:
   char *ptr;
};

int main()
{
  return 0;
}

