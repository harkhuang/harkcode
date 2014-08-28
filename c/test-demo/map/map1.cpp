#include <iostream>
#include <map>

using namespace std;
typedef  struct  _A{
	int a;
	int b;
		
}A;

typedef map<int,A> MYMAP;

int main ()
{
   
MYMAP ma;
(ma[1]).a=100;
(ma[2]).a=200;
ma[1].b=1;
ma[2].b=2;

cout<<ma[1].a<<endl;
cout<<ma[2].a<<endl;
cout<<ma[1].b<<endl;
cout<<ma[2].b<<endl;


  return 0;
}

