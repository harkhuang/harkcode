#include <iostream>
#define  command
using namespace std;
int main()
{
  #if defined command
    cout<<"command������"<<endl;
  #endif
    cout<<"�������"<<endl;
  return 0;
}
