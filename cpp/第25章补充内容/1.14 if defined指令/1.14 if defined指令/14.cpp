#include <iostream>
#define  command
using namespace std;
int main()
{
  #if defined command
    cout<<"command被定义"<<endl;
  #endif
    cout<<"程序结束"<<endl;
  return 0;
}
