/*
//例21.10.1	用cout对象调用put()
#include <iostream>
using namespace std;
int main()
{
	cout.put('h').put('e').put('l').put('p').put('\n');
	return 0;
}
*/


//例21.10.2	用cout对象调用write()
#include <iostream>
using namespace std;
int main()
{
	char ch[]="hello world";
	int length=strlen(ch);
	cout.write(ch,length).put('\n').write(ch,length-6)<<endl;
	return 0;
}
