#include <time.h>
#include <iostream>
using namespace std;
int main(void)
{
  struct tm *local,*gl;
  time_t t;
  t=time(NULL);
  local = localtime(&t);
  cout<<"本地日期时间:"<<asctime(local)<<endl;
  gl=gmtime(&t);
  cout<<"格林威治时间:"<<asctime(gl)<<endl;
  return 0;
}
