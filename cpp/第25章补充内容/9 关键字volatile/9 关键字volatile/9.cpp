#include <iostream>
using namespace std;
int square(volatile int *p) 
{ 
return *p * *p; 
}
void main()
{
int a=546;
int *pa=&a;
int i=square(pa);
cout<<i;
}
