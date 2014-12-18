#include <iostream>
#include <locale>
using namespace std;
int main()
{
  locale german ("German");
  char ch[]="abc";
  char*first=ch;
  char*last=first+sizeof(ch);
  bool check=has_facet<ctype<char> >(german);
  if (!check)
  {
    cout<<"不能通过转换.";
    return 1;
  }
  cout<<"ch:";
  cout<<first<<endl;
  use_facet<ctype<char> >(german).toupper(first,last);
  cout<<"将小写改变为大写\n";
  cout<<"ch:";
  cout<<first<<endl;
  return 0;
}
