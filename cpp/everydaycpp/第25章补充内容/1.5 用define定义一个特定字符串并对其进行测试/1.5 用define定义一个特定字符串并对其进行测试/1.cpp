/*
//#ifdef
#include <iostream>
#define  Two 
using namespace std;
int main()
{
   #ifdef Two
     cout<<"Two定义了.\n";
   #else
     cout<<"Two没定义.\n";
   #endif
   return 0;
}
*/


//#ifndef
#include <iostream>
#define  Two 
using namespace std;
int main()
{
   #ifndef Two
     cout<<"Two定义了.\n";
   #else
     cout<<"Two没定义.\n";
   #endif
   return 0;
}
