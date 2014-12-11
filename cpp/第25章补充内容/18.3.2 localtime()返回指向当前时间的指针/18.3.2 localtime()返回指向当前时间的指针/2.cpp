#include <time.h>
#include <iostream>
using namespace std;
int main(void)
{
  struct tm *local;
  time_t t;
  t=time(NULL);
  local=localtime(&t);
  cout<<"本地时间日期:\n"<<asctime(local);
  return 0;
}
