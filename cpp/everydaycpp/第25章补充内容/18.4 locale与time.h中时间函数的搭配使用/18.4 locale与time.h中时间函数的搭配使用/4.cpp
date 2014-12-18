
#include <iostream>
#include <time.h>
#include <locale.h>
using namespace std;
int main()
{
  setlocale(LC_TIME,"french");
  time_t TIME;
  struct tm*TM;
  char ch[81];
  time(&TIME);
  TM=gmtime(&TIME);
  strftime(ch,80,"%#x",TM);
  cout<<ch<<endl;
  return 0;
}

