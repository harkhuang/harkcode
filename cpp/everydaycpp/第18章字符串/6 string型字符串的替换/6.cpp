/*
//��18.6.1   char���ַ������滻

#include <iostream>
using namespace std;
int main()
{
	char ch1[10] = "gh";
	char ch2[]= "abcdef";
	strncpy(ch1,ch2,3);
	cout<<ch1<<endl;
	return 0;
}
*/

/*
//��18.6.2  string���Ա���� replace�ĵ�3�����ط�ʽ


#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str1 = "gh";
	string str2 = "abcdef";
	str1.replace(0,1,str2,4,2);
	cout<<str1<<endl;
	return 0;
}
*/


/*
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str1 = "gh";
	char str2[] = "abcdef";
	str1.replace(0,1,str2,4,2);
	cout<<str1<<endl;
	return 0;
}
*/


#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str1 = "gh";
	char ch1='l';
	str1.replace(0,2,2,ch1);
	cout<<str1<<endl;
	return 0;
}
