/*
//#ifdef
#include <iostream>
#define  Two 
using namespace std;
int main()
{
   #ifdef Two
     cout<<"Two������.\n";
   #else
     cout<<"Twoû����.\n";
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
     cout<<"Two������.\n";
   #else
     cout<<"Twoû����.\n";
   #endif
   return 0;
}
