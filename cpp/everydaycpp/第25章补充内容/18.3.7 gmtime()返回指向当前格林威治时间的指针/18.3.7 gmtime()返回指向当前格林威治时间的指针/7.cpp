#include <time.h>
#include <iostream>
using namespace std;
int main(void)
{
  struct tm *local,*gl;
  time_t t;
  t=time(NULL);
  local = localtime(&t);
  cout<<"��������ʱ��:"<<asctime(local)<<endl;
  gl=gmtime(&t);
  cout<<"��������ʱ��:"<<asctime(gl)<<endl;
  return 0;
}
