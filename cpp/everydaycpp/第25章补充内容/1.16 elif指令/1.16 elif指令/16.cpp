#include <iostream>
#define  Test
using namespace std;
int main()
{
#ifdef command
  cout<<"command������"<<endl;
#elif defined Test 
  cout<<"Test������"<<endl;
#elif defined Exe 
  cout<<"Exe������"<<endl;
#else
  cout<<"����ȫ��û�ж���"<<endl;
#endif
  cout<<"�������"<<endl;
  return 0;
}
