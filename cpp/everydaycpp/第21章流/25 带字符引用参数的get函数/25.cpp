/*
//��21.25.1  get()�����ļ���
#include <iostream>
using namespace std;
int main()
{
	char a,b,c;
	cin.get(a).get(b).get(c);
	cout<<"a:"<<a<<"\nb:"<<b<<"\nc:"<<c<<endl;
	return 0;
}
*/

//��21.25.2	  ѭ�����ļ�β����
#include <iostream>
using namespace std;
int main()
{
	char ch;
	while (cin.get(ch))
	{
		cout<<ch;
	}
	cout<<"�������\n";
	return 0;
}
