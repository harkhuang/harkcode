#include <iostream>
#define  Test
using namespace std;
int main()
{
#ifdef command
  cout<<"command被定义"<<endl;
#elif defined Test 
  cout<<"Test被定义"<<endl;
#elif defined Exe 
  cout<<"Exe被定义"<<endl;
#else
  cout<<"以上全部没有定义"<<endl;
#endif
  cout<<"程序结束"<<endl;
  return 0;
}
