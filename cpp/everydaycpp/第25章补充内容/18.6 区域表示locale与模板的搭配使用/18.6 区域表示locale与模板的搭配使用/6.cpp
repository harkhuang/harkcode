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
    cout<<"����ͨ��ת��.";
    return 1;
  }
  cout<<"ch:";
  cout<<first<<endl;
  use_facet<ctype<char> >(german).toupper(first,last);
  cout<<"��Сд�ı�Ϊ��д\n";
  cout<<"ch:";
  cout<<first<<endl;
  return 0;
}
