/*
//��21.10.1	��cout�������put()
#include <iostream>
using namespace std;
int main()
{
	cout.put('h').put('e').put('l').put('p').put('\n');
	return 0;
}
*/


//��21.10.2	��cout�������write()
#include <iostream>
using namespace std;
int main()
{
	char ch[]="hello world";
	int length=strlen(ch);
	cout.write(ch,length).put('\n').write(ch,length-6)<<endl;
	return 0;
}
